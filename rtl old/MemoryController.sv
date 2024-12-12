module MemoryController #(
    parameter DATA_WIDTH = 32,
    parameter ADDR_WIDTH = 17
) (
    input  logic                   clk,
    input  logic                   rst_n,
    input  logic                   MemWrite,
    input  logic [2:0]            SizeCtr,
    input  logic [ADDR_WIDTH-1:0] addr,
    input  logic [DATA_WIDTH-1:0] WriteData,
    output logic [DATA_WIDTH-1:0] ReadData,
    output logic                  MemReady,
    output logic [DATA_WIDTH-1:0] regs0,
    output logic s0
);

    // Internal signals for L1 Cache
    logic l1_hit, l1_miss, l1_mem_write, l1_mem_read, l1_busy;
    logic [DATA_WIDTH-1:0] l1_data_out, l1_mem_write_data;
    
    // Internal signals for L2 Cache
    logic l2_hit, l2_miss, l2_mem_write, l2_mem_read, l2_busy;
    logic [DATA_WIDTH-1:0] l2_data_out, l2_mem_write_data;
    
    // Internal signals for L3 Cache
    logic l3_hit, l3_busy;
    logic [DATA_WIDTH-1:0] l3_data_out;
    
    // Main Memory Data
    logic [DATA_WIDTH-1:0] main_mem_data;
    logic main_mem_ready_reg;

    // Memory read/write control
    logic mem_access;
    assign mem_access = MemWrite || (SizeCtr != 3'b111 && !MemWrite);


    
    L1Cache #(
        .DATA_WIDTH(DATA_WIDTH),
        .SET_WIDTH(5)
    ) l1_cache (
        .clk(clk),
        .rst_n(rst_n),
        .load(!MemWrite && mem_access),
        .store(MemWrite && mem_access),
        .address({15'b0, addr}),  // Word-aligned address
        .data_in(WriteData),
        .mem_data(l2_data_out),
        .mem_ready(!l2_busy),
        .hit(l1_hit),
        .miss(l1_miss),
        .mem_write(l1_mem_write),
        .mem_read(l1_mem_read),
        .busy(l1_busy),
        .data_out(l1_data_out),
        .mem_write_data(l1_mem_write_data)
    );

    
    L2Cache #(
        .DATA_WIDTH(DATA_WIDTH),
        .SET_WIDTH(6)
    ) l2_cache (
        .clk(clk),
        .rst_n(rst_n),
        .load(l1_mem_read),
        .store(l1_mem_write),
        .address({15'b0, addr}),  
        .data_in(l1_mem_write_data),
        .mem_data(l3_data_out),
        .mem_ready(!l3_busy),
        .hit(l2_hit),
        .miss(l2_miss),
        .mem_write(l2_mem_write),
        .mem_read(l2_mem_read),
        .busy(l2_busy),
        .data_out(l2_data_out),
        .mem_write_data(l2_mem_write_data)
    );


    L3Cache l3_cache (
        .clk(clk),
        .reset(!rst_n),
        .address({15'b0, addr}),  
        .writeData(l2_mem_write_data),
        .writeEnable(l2_mem_write),
        .readData(l3_data_out),
        .hit(l3_hit)
    );


    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            l3_busy <= 0;
        else
            l3_busy <= l2_mem_write || l2_mem_read;
    end


    logic [7:0] main_memory [2**ADDR_WIDTH-1:0];

    assign regs0 = main_memory[s0];
    
    initial begin
        $readmemh("data.hex", main_memory, 17'h10000);
    end


    always_ff @(posedge clk) begin
        if (!rst_n) begin
            main_mem_ready_reg <= 0;
        end else if (MemWrite && !l1_hit && !l2_hit && !l3_hit) begin
            case (SizeCtr)
                3'b010: begin // Word
                    main_memory[addr]     <= WriteData[7:0];
                    main_memory[addr+1]   <= WriteData[15:8];
                    main_memory[addr+2]   <= WriteData[23:16];
                    main_memory[addr+3]   <= WriteData[31:24];
                end
                3'b001: begin // Halfword
                    main_memory[addr]     <= WriteData[7:0];
                    main_memory[addr+1]   <= WriteData[15:8];
                end
                3'b000: begin // Byte
                    main_memory[addr]     <= WriteData[7:0];
                end
                default: ; 
            endcase
            main_mem_ready_reg <= 1;
        end else begin
            main_mem_ready_reg <= 0;
        end
    end


    always_comb begin
        case (SizeCtr)
            3'b010: // Word
                main_mem_data = {main_memory[addr+3], main_memory[addr+2], 
                               main_memory[addr+1], main_memory[addr]};
            3'b001: // Halfword (signed)
                main_mem_data = {{16{main_memory[addr+1][7]}}, 
                               main_memory[addr+1], main_memory[addr]};
            3'b000: // Byte (signed)
                main_mem_data = {{24{main_memory[addr][7]}}, main_memory[addr]};
            3'b100: // Byte (unsigned)
                main_mem_data = {24'b0, main_memory[addr]};
            3'b101: // Halfword (unsigned)
                main_mem_data = {16'b0, main_memory[addr+1], main_memory[addr]};
            default:
                main_mem_data = 32'b0;
        endcase
    end


    always_comb begin
        if (l1_hit) begin
            ReadData = l1_data_out;
            MemReady = 1;
        end else if (l2_hit) begin
            ReadData = l2_data_out;
            MemReady = 1;
        end else if (l3_hit) begin
            ReadData = l3_data_out;
            MemReady = 1;
        end else begin
            ReadData = main_mem_data;
            MemReady = main_mem_ready_reg && !l1_busy && !l2_busy && !l3_busy;
        end
    end

endmodule
