module PRegDecode #(
    parameter DATA_WIDTH = 32,
    parameter REG_DATA_WIDTH = 4
) (
    input   logic [DATA_WIDTH-1:0]  rd1,
    input   logic [DATA_WIDTH-1:0]  rd2,
    input   logic [DATA_WIDTH-1:0]  PCd,
    input   logic [DATA_WIDTH-1:0]  ImmExtD,
    input   logic                   clk,
    input   logic                   rst,          // Reset signal
    input   logic                   FlushE,       // Flush signal
    input   logic [4:0]             RdD,
    input   logic [DATA_WIDTH-1:0]  PCPlus4D,
    output  logic [DATA_WIDTH-1:0]  rd1E,
    output  logic [DATA_WIDTH-1:0]  rd2E,
    output  logic [DATA_WIDTH-1:0]  PCe,
    output  logic [4:0]             RdE,
    output  logic [DATA_WIDTH-1:0]  ImmExtE,
    output  logic [DATA_WIDTH-1:0]  PcPlus4E,
    input   logic                   RegWriteD,
    input   logic [1:0]             ResultSrcD,
    input   logic                   MemWriteD,
    input   logic                   JumpD,
    input   logic                   BranchD,
    input   logic [2:0]             ALUControl,
    input   logic                   ALUSrcD,
    output  logic                   RegWriteE,
    output  logic [1:0]             ResultSrcE,
    output  logic                   MemWriteE,
    output  logic                   JumpE,
    output  logic                   BranchE,
    output  logic [2:0]             ALUControlE,
    output  logic                   ALUSrcE
);

    // Sequential logic with reset and flush
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            // Reset all outputs to default values
            rd1E        <= {DATA_WIDTH{1'b0}};
            rd2E        <= {DATA_WIDTH{1'b0}};
            PCe         <= {DATA_WIDTH{1'b0}};
            RdE         <= 5'b0;
            ImmExtE     <= {DATA_WIDTH{1'b0}};
            PcPlus4E    <= {DATA_WIDTH{1'b0}};
            RegWriteE   <= 1'b0;
            ResultSrcE  <= 2'b0;
            MemWriteE   <= 1'b0;
            JumpE       <= 1'b0;
            BranchE     <= 1'b0;
            ALUControlE <= 3'b0;
            ALUSrcE     <= 1'b0;
        end else if (FlushE) begin
            // Flush all outputs to default values
            rd1E        <= {DATA_WIDTH{1'b0}};
            rd2E        <= {DATA_WIDTH{1'b0}};
            PCe         <= {DATA_WIDTH{1'b0}};
            RdE         <= 5'b0;
            ImmExtE     <= {DATA_WIDTH{1'b0}};
            PcPlus4E    <= {DATA_WIDTH{1'b0}};
            RegWriteE   <= 1'b0;
            ResultSrcE  <= 2'b0;
            MemWriteE   <= 1'b0;
            JumpE       <= 1'b0;
            BranchE     <= 1'b0;
            ALUControlE <= 3'b0;
            ALUSrcE     <= 1'b0;
        end else begin
            // Normal operation: Pass inputs to outputs
            rd1E        <= rd1;
            rd2E        <= rd2;
            PCe         <= PCd;
            RdE         <= RdD;
            ImmExtE     <= ImmExtD;
            PcPlus4E    <= PCPlus4D;
            RegWriteE   <= RegWriteD;
            ResultSrcE  <= ResultSrcD;
            MemWriteE   <= MemWriteD;
            JumpE       <= JumpD;
            BranchE     <= BranchD;
            ALUControlE <= ALUControl;
            ALUSrcE     <= ALUSrcD;
        end
    end

endmodule
