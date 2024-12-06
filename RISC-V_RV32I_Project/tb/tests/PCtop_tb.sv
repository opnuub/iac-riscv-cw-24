module PCtop_tb;

    parameter DATA_WIDTH = 32;

    logic clk, rst, PCsrcE;
    logic [DATA_WIDTH-1:0] PCTargetE;
    logic [DATA_WIDTH-1:0] InstrD, PCd, PCPlus4D;

    // Clock generation
    always #5 clk = ~clk;  // 10ns clock period (100MHz)

    // DUT instantiation
    PCtop #(DATA_WIDTH) DUT (
        .clk(clk),
        .rst(rst),
        .PCsrcE(PCsrcE),
        .PCTargetE(PCTargetE),
        .InstrD(InstrD),
        .PCd(PCd),
        .PCPlus4D(PCPlus4D)
    );

    initial begin
        // Initialize signals
        clk = 0;
        rst = 1;
        PCsrcE = 0;
        PCTargetE = 32'h00000000;

        // Apply reset
        #20 rst = 0;

        // Test Case 1: Default PC increment (PCPlus4F)
        PCsrcE = 0;  // Default sequential execution
        #10;
        $display("Test 1: PCd=%h, InstrD=%h, PCPlus4D=%h", PCd, InstrD, PCPlus4D);
        assert(PCd == 4) else $fatal("PC did not increment correctly!");

        // Test Case 2: Branch to PCTargetE
        PCsrcE = 1;  // Take branch
        PCTargetE = 32'h00000010;
        #10;
        $display("Test 2: PCd=%h, InstrD=%h, PCPlus4D=%h", PCd, InstrD, PCPlus4D);
        assert(PCd == 16) else $fatal("PC did not branch correctly!");

        // Test Case 3: Multiple sequential increments
        PCsrcE = 0;
        #30;
        $display("Test 3: PCd=%h, InstrD=%h, PCPlus4D=%h", PCd, InstrD, PCPlus4D);
        assert(PCd == 20) else $fatal("PC did not increment multiple times!");

        $finish;
    end

endmodule
