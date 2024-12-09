module L1Cache_tb;

    parameter DATA_WIDTH = 32;
    parameter SET_WIDTH = 5;

    logic clk, rst_n;
    logic load, store;
    logic [DATA_WIDTH-1:0] address, data_in, mem_data;
    logic hit, miss, eviction, mem_write, mem_read, busy;
    logic [DATA_WIDTH-1:0] eviction_addr, data_out, mem_write_data;
    logic mem_ready;

    always #5 clk = ~clk;

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
        .eviction(eviction),
        .mem_write(mem_write),
        .mem_read(mem_read),
        .busy(busy),
        .eviction_addr(eviction_addr),
        .data_out(data_out),
        .mem_write_data(mem_write_data)
    );

    always @(posedge clk) begin
        if (mem_read || mem_write) begin
            mem_ready <= #20 1;
        end else begin
            mem_ready <= 0;
        end
    end

    initial begin
        clk = 0;
        rst_n = 0;
        load = 0;
        store = 0;
        address = 0;
        data_in = 0;
        mem_data = 0;
        mem_ready = 0;
        
        #20 rst_n = 1;
        #20;

        test_basic_write_read();
        test_cache_miss();
        test_cache_replacement();
        test_write_back();
        test_cache_coherency();
        test_stress();
        
        $display("All tests completed successfully");
        $finish;
    end

    task test_basic_write_read();
        store = 1;
        address = 32'h00000100;
        data_in = 32'hDEADBEEF;
        @(posedge clk);
        wait(!busy);
        store = 0;
        
        #20;
        load = 1;
        @(posedge clk);
        assert(hit) else $error("Expected cache hit");
        assert(data_out === 32'hDEADBEEF) else $error("Data mismatch");
        wait(!busy);
        load = 0;
        
        #20;
    endtask

    task test_cache_miss();
        load = 1;
        address = 32'h00001000;
        mem_data = 32'h12345678;
        @(posedge clk);
        assert(!hit) else $error("Unexpected cache hit");
        assert(miss) else $error("Expected cache miss");
        wait(!busy);
        load = 0;
        
        #20;
    endtask

    task test_cache_replacement();
        for (int i = 0; i < 3; i++) begin
            store = 1;
            address = 32'h00001000 + (i * 32'h1000);
            data_in = 32'hA0000000 + i;
            @(posedge clk);
            wait(!busy);
            store = 0;
            #20;
        end
        
        assert(eviction) else $error("Expected eviction");
        
        #20;
    endtask

    task test_write_back();
        store = 1;
        address = 32'h00002000;
        data_in = 32'hCAFEBABE;
        @(posedge clk);
        wait(!busy);
        store = 0;
        
        store = 1;
        address = 32'h00012000;
        data_in = 32'hFEEDBEEF;
        @(posedge clk);
        assert(eviction) else $error("Expected write-back");
        wait(!busy);
        store = 0;
        
        #20;
    endtask

    task test_cache_coherency();
        store = 1;
        address = 32'h00003000;
        data_in = 32'h11223344;
        @(posedge clk);
        wait(!busy);
        store = 0;
        
        load = 1;
        @(posedge clk);
        assert(hit) else $error("Expected cache hit");
        assert(data_out === 32'h11223344) else $error("Data coherency error");
        wait(!busy);
        load = 0;
        
        #20;
    endtask

    task test_stress();
        for (int i = 0; i < 10; i++) begin
            store = 1;
            address = 32'h00004000 + (i * 32'h1000);
            data_in = 32'h55555555 + i;
            @(posedge clk);
            wait(!busy);
            store = 0;
            
            #10;
            load = 1;
            @(posedge clk);
            wait(!busy);
            load = 0;
            
            #10;
        end
    endtask

    initial begin
        $dumpfile("L1Cache_tb.vcd");
        $dumpvars(0, L1Cache_tb);
    end

endmodule