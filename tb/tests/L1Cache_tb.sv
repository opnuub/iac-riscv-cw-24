module L1Cache_tb;

    // Parameters
    parameter DATA_WIDTH = 32;
    parameter SET_WIDTH = 9;
    parameter TAG_WIDTH = DATA_WIDTH - SET_WIDTH - 2;

    // Signals
    logic clk;
    logic rst_n;
    logic load;
    logic store;
    logic [DATA_WIDTH-1:0] address;
    logic [DATA_WIDTH-1:0] data_in;
    logic [DATA_WIDTH-1:0] mem_data;
    logic mem_ready;
    logic hit;
    logic miss;
    logic mem_write;
    logic mem_read;
    logic busy;
    logic [DATA_WIDTH-1:0] data_out;
    logic [DATA_WIDTH-1:0] mem_write_data;

    // Clock generation
    initial clk = 0;
    always #5 clk = ~clk;

    // DUT instantiation
    L1Cache #(
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

    // Testbench tasks
    task initialize();
        rst_n = 0;
        load = 0;
        store = 0;
        address = 0;
        data_in = 0;
        mem_data = 0;
        mem_ready = 0;
        #20 rst_n = 1;
    endtask

    task load_data(input [DATA_WIDTH-1:0] addr);
        @(posedge clk);
        load = 1;
        address = addr;
        @(posedge clk);
        load = 0;
    endtask

    task store_data(input [DATA_WIDTH-1:0] addr, input [DATA_WIDTH-1:0] data);
        @(posedge clk);
        store = 1;
        address = addr;
        data_in = data;
        @(posedge clk);
        store = 0;
    endtask

    initial begin
        // Initialize
        initialize();

        // Test: Store data
        store_data(32'h12345678, 32'hAAAA_BBBB);
        #20;

        // Test: Load data
        load_data(32'h12345678);
        #20;

        // End simulation
        $finish;
    end
endmodule