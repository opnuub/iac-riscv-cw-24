module MemoryController #(
    parameter DATA_WIDTH = 32,
    parameter ADDR_WIDTH = 17
) (
    input  logic                   clk,
    input  logic                   rst_n,
    input  logic                   MemWrite,
    input  logic [2:0]             SizeCtr,
    input  logic [ADDR_WIDTH-1:0]  addr,
    input  logic [DATA_WIDTH-1:0]  WriteData,
    output logic [DATA_WIDTH-1:0]  ReadData,
    output logic                   MemReady,

    output logic                   l1_miss_o,    // Changed from l1_miss to l1_miss_o
    output logic                   l2_miss_o,    // Changed from l2_miss to l2_miss_o
    output logic                   cache_busy_o  // Changed from cache_busy to cache_busy_o
);

    // Internal signals for L1Cache
    logic l1_hit, l1_miss, l1_busy;
    logic [DATA_WIDTH-1:0] l1_data_out;
    logic l1_mem_write, l1_mem_read;
    logic [DATA_WIDTH-1:0] l1_mem_write_data;

    // Assign output signals
    assign l1_miss_o = l1_miss;
    assign l2_miss_o = l2_miss;
    assign cache_busy_o = l1_busy || l2_busy;
    // Signals for L3Cache
    logic l3_hit, l3_stall;
    logic [DATA_WIDTH-1:0] l3_data_out;
    logic l3_mem_write, l3_mem_read;
    logic [DATA_WIDTH-1:0] l3_mem_write_data;
    logic [DATA_WIDTH-1:0] l3_mem_address;
    logic l3_mem_ready;

    // Memory access control
    logic mem_access;
    assign mem_access = MemWrite || (SizeCtr != 3'b111 && !MemWrite);

    // L1 Cache
    L1Cache #(
        .DATA_WIDTH(DATA_WIDTH),
        .SET_WIDTH(9)
    ) l1_cache (
        .clk(clk),
        .rst_n(rst_n),
        .load(!MemWrite && mem_access),
        .store(MemWrite && mem_access),
        .address({15'b0, addr}),  
        .data_in(WriteData),
        .mem_data(l2_data_out),   
        .mem_ready(!l2_busy),     
        .hit(l1_hit),
        .miss(l1_miss),
        .busy(l1_busy),
        .mem_write(l1_mem_write),
        .mem_read(l1_mem_read),
        .data_out(l1_data_out),
        .mem_write_data(l1_mem_write_data)
    );

    // L2 Cache
    L2Cache #(
        .DATA_WIDTH(DATA_WIDTH),
        .SET_WIDTH(10)  
    ) l2_cache (
        .clk(clk),
        .rst_n(rst_n),
        .load(l1_mem_read),
        .store(l1_mem_write),
        .address({15'b0, addr}),
        .data_in(l1_mem_write_data),
        .mem_data(l3_data_out),   
        .mem_ready(!l3_stall),   
        .hit(l2_hit),
        .miss(l2_miss),
        .busy(l2_busy),
        .mem_write(l2_mem_write),
        .mem_read(l2_mem_read),
        .data_out(l2_data_out),
        .mem_write_data(l2_mem_write_data)
    );

    // L3 Cache
    L3Cache l3_cache (
        .clk(clk),
        .reset(!rst_n),
        .address({15'b0, addr}),
        .writeData(l2_mem_write_data),
        .writeEnable(l2_mem_write),
        .readData(l3_data_out),
        .hit(l3_hit),
        .stall(l3_stall),
        .mem_read(l3_mem_read),
        .mem_write(l3_mem_write),
        .mem_address(l3_mem_address),
        .mem_write_data(l3_mem_write_data),
        .mem_read_data(main_mem_read_data),    
        .mem_ready(main_mem_ready)         
    );

    // Output assignments
    assign ReadData = l1_hit ? l1_data_out :
                     l2_hit ? l2_data_out :
                     l3_hit ? l3_data_out : 32'b0;
                     
    assign MemReady = (l1_hit || (!l1_busy && l2_hit) || (!l1_busy && !l2_busy && l3_hit)) && !l3_stall;

    // Main Memory signals
    logic main_mem_ready;
    logic [DATA_WIDTH-1:0] main_mem_read_data;

    // Instantiate Main Memory
    MainMemory #(
        .DATA_WIDTH(DATA_WIDTH),
        .ADDR_WIDTH(ADDR_WIDTH)
    ) main_memory (
        .SizeCtr(SizeCtr),
        .clk(clk),
        .rst_n(rst_n),
        .mem_read(l3_mem_read),
        .mem_write(l3_mem_write),
        .address(l3_mem_address),
        .write_data(l3_mem_write_data),
        .read_data(main_mem_read_data),
        .mem_ready(main_mem_ready)
    );

endmodule