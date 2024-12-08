module PRegExecute #(
    parameter DATA_WIDTH = 32
) (
    input   logic [DATA_WIDTH-1:0]  ALUout,
    input   logic [DATA_WIDTH-1:0]  WriteData,
    input   logic [DATA_WIDTH-1:0]  PCPlus4E,
    input   logic                   clk,
    input   logic                   rst,          // Reset signal
    input   logic [4:0]             RdE,
    output  logic [DATA_WIDTH-1:0]  ALUResultM,
    output  logic [DATA_WIDTH-1:0]  WriteDataM,
    output  logic [4:0]             RdM,
    output  logic [DATA_WIDTH-1:0]  PCPlus4M,
    input   logic                   RegWriteE,
    input   logic [1:0]             ResultSrcE,
    input   logic                   MemWriteE,
    output  logic                   RegWriteM,
    output  logic [1:0]             ResultSrcM,
    output  logic                   MemWriteM
);

    // Sequential logic for both writing and output generation
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            // Reset or flush: Set outputs to default values
            ALUResultM <= 0;
            WriteDataM <= 0;
            PCPlus4M   <= 0;
            RdM        <= 0;
            RegWriteM  <= 0;
            ResultSrcM <= 0;
            MemWriteM  <= 0;
        end else begin
            // Normal operation: Assign inputs to outputs
            ALUResultM <= ALUout;
            WriteDataM <= WriteData;
            PCPlus4M   <= PCPlus4E;
            RdM        <= RdE;
            RegWriteM  <= RegWriteE;
            ResultSrcM <= ResultSrcE;
            MemWriteM  <= MemWriteE;
        end
    end

endmodule
