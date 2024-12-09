module PRegDecode_tb;

    parameter DATA_WIDTH = 32;
    parameter REG_DATA_WIDTH = 4;

    logic [DATA_WIDTH-1:0] rd1;
    logic [DATA_WIDTH-1:0] rd2;
    logic [DATA_WIDTH-1:0] PCd;
    logic [DATA_WIDTH-1:0] ImmExtD;
    logic clk;
    logic [4:0] RdD;
    logic [DATA_WIDTH-1:0] PCPlus4D;
    logic [DATA_WIDTH-1:0] rd1E;
    logic [DATA_WIDTH-1:0] rd2E;
    logic [DATA_WIDTH-1:0] PCe;
    logic [4:0] RdE;
    logic [DATA_WIDTH-1:0] ImmExtE;
    logic [DATA_WIDTH-1:0] PcPlus4E;
    logic RegWriteD, MemWriteD, JumpD, BranchD, ALUSrcD;
    logic [1:0] ResultSrcD;
    logic [2:0] ALUControl;
    logic RegWriteE, MemWriteE, JumpE, BranchE, ALUSrcE;
    logic [1:0] ResultSrcE;
    logic [2:0] ALUControlE;

    // Instantiate the PRegDecode module
    PRegDecode #(
        .DATA_WIDTH(DATA_WIDTH),
        .REG_DATA_WIDTH(REG_DATA_WIDTH)
    ) uut (
        .rd1(rd1), .rd2(rd2), .PCd(PCd), .ImmExtD(ImmExtD),
        .clk(clk), .RdD(RdD), .PCPlus4D(PCPlus4D),
        .rd1E(rd1E), .rd2E(rd2E), .PCe(PCe), .RdE(RdE),
        .ImmExtE(ImmExtE), .PcPlus4E(PcPlus4E),
        .RegWriteD(RegWriteD), .ResultSrcD(ResultSrcD),
        .MemWriteD(MemWriteD), .JumpD(JumpD), .BranchD(BranchD),
        .ALUControl(ALUControl), .ALUSrcD(ALUSrcD),
        .RegWriteE(RegWriteE), .ResultSrcE(ResultSrcE),
        .MemWriteE(MemWriteE), .JumpE(JumpE), .BranchE(BranchE),
        .ALUControlE(ALUControlE), .ALUSrcE(ALUSrcE)
    );

    // Clock generation
    initial clk = 0;
    always #5 clk = ~clk; // Toggle clock every 5 time units

    // Test logic
    initial begin
        $display("Starting PRegDecode test...");

        // Test case 1: Load initial values
        rd1 = 32'hA5A5A5A5; rd2 = 32'h5A5A5A5A;
        PCd = 32'h12345678; ImmExtD = 32'h87654321;
        RdD = 5'h1F; PCPlus4D = 32'h11111111;
        RegWriteD = 1; ResultSrcD = 2'b10; MemWriteD = 1;
        JumpD = 0; BranchD = 1; ALUControl = 3'b101; ALUSrcD = 1;
        @(posedge clk); // Wait for one clock cycle

        if (rd1E !== 32'hA5A5A5A5 || rd2E !== 32'h5A5A5A5A ||
            PCe !== 32'h12345678 || ImmExtE !== 32'h87654321 ||
            RdE !== 5'h1F || PcPlus4E !== 32'h11111111 ||
            RegWriteE !== 1 || ResultSrcE !== 2'b10 ||
            MemWriteE !== 1 || BranchE !== 1 || ALUControlE !== 3'b101 || ALUSrcE !== 1) begin
            $fatal("Test case 1 failed: Incorrect outputs.");
        end

        // Test case 2: Overwrite with new values
        rd1 = 32'hDEADBEEF; rd2 = 32'hCAFEBABE;
        PCd = 32'hABCDEF01; ImmExtD = 32'h13572468;
        RdD = 5'h0A; PCPlus4D = 32'h22222222;
        RegWriteD = 0; ResultSrcD = 2'b01; MemWriteD = 0;
        JumpD = 1; BranchD = 0; ALUControl = 3'b010; ALUSrcD = 0;
        @(posedge clk); // Wait for one clock cycle

        if (rd1E !== 32'hDEADBEEF || rd2E !== 32'hCAFEBABE ||
            PCe !== 32'hABCDEF01 || ImmExtE !== 32'h13572468 ||
            RdE !== 5'h0A || PcPlus4E !== 32'h22222222 ||
            RegWriteE !== 0 || ResultSrcE !== 2'b01 ||
            MemWriteE !== 0 || JumpE !== 1 || BranchE !== 0 ||
            ALUControlE !== 3'b010 || ALUSrcE !== 0) begin
            $fatal("Test case 2 failed: Incorrect outputs.");
        end

        $display("All test cases passed.");
        $finish;
    end

endmodule
