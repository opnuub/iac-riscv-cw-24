module top_tb;

    logic clk_i;
    logic rst_ni;
    logic trigger_i;
    logic [31:0] a0_o;

   
    top dut (
        .clk_i(clk_i),
        .rst_ni(rst_ni),
        .trigger_i(trigger_i),
        .a0_o(a0_o)
    );


    always #5 clk_i = ~clk_i;

    // Test process
    initial begin

        $display("Starting Top Module Testbench...");
        clk_i = 0;
        rst_ni = 0;
        trigger_i = 0;
        #10;

        // Reset release
        rst_ni = 1;
        #10;

        trigger_i = 1;
        #100;
        trigger_i = 0;


        #50;
        $display("a0_o = %h", a0_o);
        assert(a0_o == 32'hEXPECTED_VALUE) else $fatal("Test failed: Unexpected value for a0_o!");


        $display("Top Module Test Passed!");
        $finish;
    end
endmodule
