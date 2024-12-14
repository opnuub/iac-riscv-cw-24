module tb_L2Cache;

    // Parameters
    parameter DATA_WIDTH = 32;
    parameter SET_WIDTH = 6;

    // DUT Inputs
    logic clk;
    logic rst_n;
    logic load;
    logic store;
    logic [DATA_WIDTH-1:0] address;
    logic [DATA_WIDTH-1:0] data_in;
    logic [DATA_WIDTH-1:0] mem_data;
    logic mem_ready;

    // DUT Outputs
    logic hit;
    logic miss;
    logic mem_write;
    logic mem_read;
    logic busy;
    logic [DATA_WIDTH-1:0] data_out;
    logic [DATA_WIDTH-1:0] mem_write_data;

    // Instantiate L2Cache
    L2Cache #(
        .DATA_WIDTH(DATA_WIDTH),
        .SET_WIDTH(SET_WIDTH)
    ) dut (
        .clk(clk),
        .rst_n(rst_n),
        .load(load),
        .store(store),
        .address(address),
        .data_in(data_in),
        .mem_data(mem_data),
        .mem_ready(mem_ready),
        .hit(hit),
        .miss(miss),
        .mem_write(mem_write),
        .mem_read(mem_read),
        .busy(busy),
        .data_out(data_out),
        .mem_write_data(mem_write_data)
    );

    // Clock generation
    always #5 clk = ~clk;

    // Test stimulus
    initial begin
        $dumpfile("L2Cache.vcd");
        $dumpvars(0, tb_L2Cache);

        // Initialize inputs
        clk = 0;
        rst_n = 0;
        load = 0;
        store = 0;
        address = 0;
        data_in = 0;
        mem_data = 0;
        mem_ready = 0;

        // Reset
        #10 rst_n = 1;

        // Test 1: Load - Cache Miss
        address = 32'h0000_0000; // Address in first set
        load = 1;
        #10 load = 0;

        // Test 2: Store - Cache Miss
        address = 32'h0000_0004; // Address in the same set
        data_in = 32'hDEADBEEF;
        store = 1;
        #10 store = 0;

        // Test 3: Load - Cache Hit
        address = 32'h0000_0004;
        load = 1;
        #10 load = 0;

        // Test 4: Replacement
        address = 32'h0000_0040; // Address in another way
        load = 1;
        #10 load = 0;

        // Finish simulation
        #50 $finish;
    end
endmodule