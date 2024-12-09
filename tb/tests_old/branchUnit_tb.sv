module branchUnit_tb;

    // Parameters
    localparam DATA_WIDTH = 32;

    // DUT Inputs
    logic [DATA_WIDTH-1:0] srcA;
    logic [DATA_WIDTH-1:0] srcB;
    logic [3:0]            aluControl;

    // DUT Outputs
    logic zero;

    // Clock Signal
    logic clk;

    // Instantiate the DUT
    branchUnit #(
        .DATA_WIDTH(DATA_WIDTH)
    ) dut (
        .srcA(srcA),
        .srcB(srcB),
        .aluControl(aluControl),
        .zero(zero)
    );

    // Clock generation
    initial begin
        clk = 0;
        forever #5 clk = ~clk; // 10ns clock period
    end

    // Test Procedure
    initial begin
        $display("Starting Testbench for branchUnit...");

        // Test Case 1: BEQ
        srcA = 32'd10;
        srcB = 32'd10;
        aluControl = 4'b1000; // BEQ
        @(posedge clk); // Wait for a clock edge
        $display("BEQ: srcA=%d, srcB=%d, aluControl=%b -> zero=%b", srcA, srcB, aluControl, zero);
        assert(zero == 1) else $fatal("Test Case 1 Failed!");

        // Test Case 2: BNE
        srcA = 32'd10;
        srcB = 32'd5;
        aluControl = 4'b1001; // BNE
        @(posedge clk);
        $display("BNE: srcA=%d, srcB=%d, aluControl=%b -> zero=%b", srcA, srcB, aluControl, zero);
        assert(zero == 1) else $fatal("Test Case 2 Failed!");

        // Other test cases...

        $display("All Test Cases Passed!");
        $finish;
    end

endmodule