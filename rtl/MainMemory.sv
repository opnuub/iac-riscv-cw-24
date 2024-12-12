module MainMemory #(
    parameter DATA_WIDTH = 32,
    parameter ADDR_WIDTH = 32,
    parameter MEM_SIZE = 16384  // 16KB memory
) (
    input  logic                    clk,
    input  logic                    rst_n,
    input  logic                    mem_read,
    input  logic                    mem_write,
    input  logic [ADDR_WIDTH-1:0]   address,
    input  logic [DATA_WIDTH-1:0]   write_data,
    output logic [DATA_WIDTH-1:0]   read_data,
    output logic                    mem_ready
);

    // Memory array
    logic [7:0] memory [MEM_SIZE-1:0];
    
    // Access delay counter
    logic [3:0] delay_counter;
    localparam MEMORY_LATENCY = 10;  // 10 cycle latency for main memory access
    
    // Memory ready logic
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            delay_counter <= '0;
            mem_ready <= 1'b0;
        end else if (mem_read || mem_write) begin
            if (delay_counter == MEMORY_LATENCY) begin
                delay_counter <= '0;
                mem_ready <= 1'b1;
            end else begin
                delay_counter <= delay_counter + 1;
                mem_ready <= 1'b0;
            end
        end else begin
            delay_counter <= '0;
            mem_ready <= 1'b0;
        end
    end

    // Memory read operation
    always_comb begin
        if (mem_read && (delay_counter == MEMORY_LATENCY)) begin
            read_data = {
                memory[address+3],
                memory[address+2],
                memory[address+1],
                memory[address]
            };
        end else begin
            read_data = 'x;
        end
    end

    // Memory write operation
    always_ff @(posedge clk) begin
        if (mem_write && (delay_counter == MEMORY_LATENCY)) begin
            memory[address]   <= write_data[7:0];
            memory[address+1] <= write_data[15:8];
            memory[address+2] <= write_data[23:16];
            memory[address+3] <= write_data[31:24];
        end
    end


endmodule