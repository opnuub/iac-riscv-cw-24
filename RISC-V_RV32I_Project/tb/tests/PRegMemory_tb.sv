module PRegMemory_tb;

    parameter DATA_WIDTH = 32;
    parameter REG_DATA_WIDTH = 3;

    logic [DATA_WIDTH-1:0] ALUResultM;
    logic [DATA_WIDTH-1:0] DMRd;
    logic [4:0] RdM;
    logic [DATA_WIDTH-1:0] PCPlus4M;
    logic clk;
    logic [4:0] RdW;
    logic [DATA_WIDTH-1:0] ALUResultW;
    logic [DATA_WIDTH-1:0] WriteDataW;
    logic [DATA_WIDTH-1:0] PCPlus4W;
    logic RegWriteM;
    logic [1:0] ResultSrcM;
    logic RegWriteW;
    logic [1:0] ResultSrcW;

    // Instantiate PRegMemory
    PRegMemory #(
        .DATA_WIDTH(DATA_WIDTH),
        .REG_DATA_WIDTH(REG_DATA_WIDTH)
    ) uut (
        .ALUResultM(ALUResultM),
        .DMRd(DMRd),
        .RdM(RdM),
        .PCPlus4M(PCPlus4M),
        .clk(clk),
        .RdW(RdW),
        .ALUResultW(ALUResultW),
        .WriteDataW(WriteDataW),
        .PCPlus4W(PCPlus4W),
        .RegWriteM(RegWriteM),
        .ResultSrcM(ResultSrcM),
        .RegWriteW(RegWriteW),
        .ResultSrcW(ResultSrcW)
    );

    // Clock generation
    initial clk = 0;
    always #5 clk = ~clk; // Toggle clock every 5 time units

    // Test logic
    initial begin
        $display("Starting PRegMemory test...");

        // Test case 1: Load initial values
        ALUResultM = 32'hDEADBEEF; DMRd = 32'hCAFEBABE;
        RdM = 5'h1F; PCPlus4M = 32'hABCDEF01;
        RegWriteM = 1; ResultSrcM = 2'b10;
        @(posedge clk); // Wait for one clock cycle

        if (ALUResultW !== 32'hDEADBEEF || WriteDataW !== 32'hCAFEBABE ||
            RdW !== 5'h1F || PCPlus4W !== 32'hABCDEF01 ||
            RegWriteW !== 1 || ResultSrcW !== 2'b10) begin
            $fatal("Test case 1 failed: Incorrect outputs after 1st clock cycle.");
        end

        // Test case 2: Overwrite values
        ALUResultM = 32'hA5A5A5A5; DMRd = 32'h5A5A5A5A;
        RdM = 5'h0A; PCPlus4M = 32'h12345678;
        RegWriteM = 0; ResultSrcM = 2'b01;
        @(posedge clk); // Wait for one clock cycle

        if (ALUResultW !== 32'hA5A5A5A5 || WriteDataW !== 32'h5A5A5A5A ||
            RdW !== 5'h0A || PCPlus4W !== 32'h12345678 ||
            RegWriteW !== 0 || ResultSrcW !== 2'b01) begin
            $fatal("Test case 2 failed: Incorrect outputs after 2nd clock cycle.");
        end

        $display("All test cases passed.");
        $finish;
    end

endmodule
