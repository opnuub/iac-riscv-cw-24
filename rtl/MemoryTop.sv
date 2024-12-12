module MemoryTop #(
    parameter ADDR_WIDTH = 32,
    parameter DATA_WIDTH = 32,
    parameter MEM_ADDR_WIDTH = 17
) (
    input  logic                        clk,
    input  logic                        rst,
    input  logic                        mem_write_i,
    input  logic [2:0]                  size_src_i,
    input  logic [ADDR_WIDTH-1:0]       addr_i,
    input  logic [DATA_WIDTH-1:0]       write_data_i,
    output logic [DATA_WIDTH-1:0]       read_data_o,
    output logic                        data_valid_o
);
    // Cache hit and data signals
    logic l1_cache_hit, l2_cache_hit, l3_cache_hit;
    logic [DATA_WIDTH-1:0] l1_rd_data, l2_rd_data, l3_rd_data;
    logic [DATA_WIDTH-1:0] mem_rd_data;
    logic mem_valid;

    // Byte enable decoding
    logic [3:0] byte_en;
    always_comb begin
        case (size_src_i)
            3'b000:  byte_en = 4'b0001; // Byte
            3'b001:  byte_en = 4'b0011; // Half word
            3'b010:  byte_en = 4'b1111; // Word
            3'b100:  byte_en = 4'b0001; // Byte unsigned
            3'b101:  byte_en = 4'b0011; // Half word unsigned
            default: byte_en = 4'b0000;
        endcase
    end

    // L1 Cache
    l1_cache #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) l1_cache_inst (
        .clk               (clk),
        .rst               (rst),
        .wr_en_i          (mem_write_i),
        .addr_i           (addr_i),
        .wr_data_i        (write_data_i),
        .byte_en_i        (byte_en),
        .l2_cache_valid_i (l2_cache_hit),
        .l2_cache_data_i  (l2_rd_data),
        .l1_rd_data_o     (l1_rd_data),
        .l1_cache_hit_o   (l1_cache_hit)
    );

    // L2 Cache
    l2_cache #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) l2_cache_inst (
        .clk               (clk),
        .rst               (rst),
        .wr_en_i          (mem_write_i & ~l1_cache_hit),  // Write if L1 miss
        .addr_i           (addr_i),
        .wr_data_i        (write_data_i),
        .byte_en_i        (byte_en),
        .l3_cache_valid_i (l3_cache_hit),
        .l3_cache_data_i  (l3_rd_data),
        .l2_rd_data_o     (l2_rd_data),
        .l2_cache_hit_o   (l2_cache_hit)
    );

    // L3 Cache
    l3_cache #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) l3_cache_inst (
        .clk               (clk),
        .rst               (rst),
        .wr_en_i          (mem_write_i & ~l1_cache_hit & ~l2_cache_hit),  // Write if L1&L2 miss
        .addr_i           (addr_i),
        .wr_data_i        (write_data_i),
        .byte_en_i        (byte_en),
        .mem_valid_i      (mem_valid),
        .mem_data_i       (mem_rd_data),
        .l3_rd_data_o     (l3_rd_data),
        .l3_cache_hit_o   (l3_cache_hit)
    );

    // Main Memory
    DataMemory #(
        .DATA_WIDTH(DATA_WIDTH),
        .ADDR_WIDTH(MEM_ADDR_WIDTH)
    ) data_memory (
        .clk        (clk),
        .SizeCtr    (size_src_i),
        .ALUResult  (addr_i[MEM_ADDR_WIDTH-1:0]),
        .WriteData  (write_data_i),  // Direct write to memory
        .MemWrite   (mem_write_i & ~l1_cache_hit & ~l2_cache_hit & ~l3_cache_hit),  // Write if all cache miss
        .ReadData   (mem_rd_data)
    );

    

    // Memory valid logic
    // Set valid when data is available from memory after all cache misses
    assign mem_valid = 1'b1;//~l1_cache_hit & ~l2_cache_hit & ~l3_cache_hit;
    // Read data multiplexing
    logic data_valid;
    assign data_valid = |read_data_o;  // 如果read_data_o的任何位为1，则data_valid为1

    // Select data from the first cache level that hits
    always_comb begin
        read_data_o = 1'b0;
        if (l1_cache_hit)
            read_data_o = l1_rd_data;
        else if (l2_cache_hit)
            read_data_o = l2_rd_data;
        else if (l3_cache_hit)
            read_data_o = l3_rd_data;
        else
            read_data_o = mem_rd_data;
    end
    //tag bit 的问题， 用 lower bit 加两个bit


    // assign read_data_o = l1_cache_hit ? l1_rd_data :
    // l2_cache_hit ? l2_rd_data :
    // l3_cache_hit ? l3_rd_data :
    // mem_rd_data;
    // Data valid when any cache hits or memory responds
    assign data_valid_o = 1'b1; //l1_cache_hit | l2_cache_hit | l3_cache_hit | mem_valid;

endmodule