module PRegExecute_tb;

    parameter DATA_WIDTH = 32;
    parameter REG_DATA_WIDTH = 3;

    logic [DATA_WIDTH-1:0] ALUout;
    logic [DATA_WIDTH-1:0] WriteData;
    logic [DATA_WIDTH-1:0] PCPlus4E;
    logic clk;
    logic [4:0] RdE;
    logic [DATA_WIDTH-1:0] ALUResultM;
    logic [DATA_WIDTH-1:0] WriteDataM;
    logic [DATA_WIDTH-1:0] PCPlus4M;
    logic [4:0] RdM;
    logic RegWriteE, MemWriteE;
    logic [1:0] ResultSrcE;
    logic RegWriteM, MemWriteM;
    logic [1:0] ResultSrcM;

    // Instantiate PRegExecute
    PRegExecute #(
        .DATA_WIDTH(DATA_WIDTH),
        .REG_DATA_WIDTH(REG_DATA_WIDTH)
    ) uut (
        .ALUout(ALUout),
        .WriteData(WriteData),
        .PCPlus4E(PCPlus4E),
        .clk(clk),
        .RdE(RdE),
        .ALUResultM(ALUResultM),
        .WriteDataM(WriteDataM),
        .PCPlus4M(PCPlus4M),
        .RdM(RdM),
        .RegWriteE(RegWriteE),
        .ResultSrcE(ResultSrcE),
        .MemWriteE(MemWriteE),
        .RegWriteM(RegWriteM),
        .ResultSrcM(ResultSrcM),
        .MemWriteM(MemWriteM)
    );

    // Clock generation
    initial clk = 0;
    always #5 clk = ~clk; // Toggle clock every 5 time units

    // Test logic
    initial begin
        $display("Starting PRegExecute test...");

        // Test case 1: Load initial values
        ALUout = 32'hDEADBEEF; WriteData = 32'hCAFEBABE;
        PCPlus4E = 32'hABCDEF01; RdE = 5'h1F;
        RegWriteE = 1; ResultSrcE = 2'b10; MemWriteE = 0;
        @(posedge clk); // Wait for one clock cycle

        if (ALUResultM !== 32'hDEADBEEF || WriteDataM !== 32'hCAFEBABE ||
            PCPlus4M !== 32'hABCDEF01 || RdM !== 5'h1F ||
            RegWriteM !== 1 || ResultSrcM !== 2'b10 || MemWriteM !== 0) begin
            $fatal("Test case 1 failed: Incorrect outputs after 1st clock cycle.");
        end

        // Test case 2: Overwrite values
        ALUout = 32'hA5A5A5A5; WriteData = 32'h5A5A5A5A;
        PCPlus4E = 32'h12345678; RdE = 5'h0A;
        RegWriteE = 0; ResultSrcE = 2'b01; MemWriteE = 1;
        @(posedge clk); // Wait for one clock cycle

        if (ALUResultM !== 32'hA5A5A5A5 || WriteDataM !== 32'h5A5A5A5A ||
            PCPlus4M !== 32'h12345678 || RdM !== 5'h0A ||
            RegWriteM !== 0 || ResultSrcM !== 2'b01 || MemWriteM !== 1) begin
            $fatal("Test case 2 failed: Incorrect outputs after 2nd clock cycle.");
        end

        $display("All test cases passed.");
        $finish;
    end

endmodule
