module HazardUnit_tb;

    // Parameters and test signals
    logic [4:0] Rs1E, Rs2E, Rs1D, Rs2D, RdE, destReg_m, destReg_w;
    logic memoryRead_e, RegWriteM, RegWriteW, zero_hazard, jump_hazard;
    logic [1:0] ForwardAE, ForwardBE;
    logic stall, Flush;

    // Instantiate the DUT (Device Under Test)
    HazardUnit dut (
        .Rs1E(Rs1E),
        .Rs2E(Rs2E),
        .Rs1D(Rs1D),
        .Rs2D(Rs2D),
        .RdE(RdE),
        .destReg_m(destReg_m),
        .destReg_w(destReg_w),
        .memoryRead_e(memoryRead_e),
        .RegWriteM(RegWriteM),
        .RegWriteW(RegWriteW),
        .zero_hazard(zero_hazard),
        .jump_hazard(jump_hazard),
        .ForwardAE(ForwardAE),
        .ForwardBE(ForwardBE),
        .stall(stall),
        .Flush(Flush)
    );

    // Test procedure
    initial begin
        $display("Starting HazardUnit Testbench...");

        // Default values
        Rs1E = 0; Rs2E = 0; Rs1D = 0; Rs2D = 0;
        RdE = 0; destReg_m = 0; destReg_w = 0;
        memoryRead_e = 0; RegWriteM = 0; RegWriteW = 0;
        zero_hazard = 0; jump_hazard = 0;

        // Test 1: ForwardAE
        RegWriteM = 1;
        destReg_m = 5; Rs1E = 5;
        #10;
        $display("Test 1 ForwardAE: ForwardAE=%b, Expected=2'b10", ForwardAE);
        assert(ForwardAE == 2'b10);

        // Test 2: ForwardBE
        destReg_m = 5; Rs2E = 5;
        #10;
        $display("Test 2 ForwardBE: ForwardBE=%b, Expected=2'b10", ForwardBE);
        assert(ForwardBE == 2'b10);

        // Test 3: Stall
        memoryRead_e = 1; RdE = 5; Rs1D = 5;
        #10;
        $display("Test 3 Stall: stall=%b, Expected=1'b1", stall);
        assert(stall == 1'b1);

        // Test 4: Flush due to zero_hazard
        zero_hazard = 1;
        #10;
        $display("Test 4 Flush: Flush=%b, Expected=1'b1", Flush);
        assert(Flush == 1'b1);

        // Test 5: Flush due to jump_hazard
        zero_hazard = 0; jump_hazard = 1;
        #10;
        $display("Test 5 Flush: Flush=%b, Expected=1'b1", Flush);
        assert(Flush == 1'b1);

        // Test 6: No Forwarding
        RegWriteM = 0; RegWriteW = 0;
        Rs1E = 1; Rs2E = 2; destReg_m = 3; destReg_w = 4;
        #10;
        $display("Test 6 No Forwarding: ForwardAE=%b, ForwardBE=%b, Expected=2'b00", ForwardAE, ForwardBE);
        assert(ForwardAE == 2'b00 && ForwardBE == 2'b00);

        $display("All Tests Completed Successfully!");
        $finish;
    end

endmodule