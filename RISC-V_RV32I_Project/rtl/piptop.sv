module piptop #( //!!!!!!!!!!!!!this file is still filled with errors, I am not finished yet
    parameter DATA_WIDTH = 32,
    parameter INSTR_WIDTH = 32,
    parameter ADDR_WIDTH = 32,
    parameter MEM_ADDR_WIDTH = 17,
    parameter REG_DATA_WIDTH = 5,
    parameter OFFSET = 4
) (
    input   logic                   clk,
    input   logic                   rst,
    input   logic                   trigger,
    output  logic [DATA_WIDTH-1:0]  a0
);

    // Declare all internal signals
    // Fetch Stage
    logic [ADDR_WIDTH-1:0] pc, incPC, branchPC, nextPC;
    logic [INSTR_WIDTH-1:0] instr;
    logic [DATA_WIDTH-1:0] PCPlus4F;

    // Decode Stage
    logic [DATA_WIDTH-1:0] PCd, PCPlus4D, rd1, rd2, immExt;
    logic [4:0] RdD;
    logic RegWriteD, MemWriteD, JumpD, BranchD, ALUSrcD;
    logic [2:0] ALUControlD;
    logic [1:0] ResultSrcD;

    // Execute Stage
    logic [DATA_WIDTH-1:0] PCe, PCPlus4E, ImmExtE, rd1E, rd2E, srcA, srcB, aluResult;
    logic [4:0] RdE;
    logic RegWriteE, MemWriteE, JumpE, BranchE, ALUSrcE;
    logic [2:0] ALUControlE;
    logic [1:0] ResultSrcE;

    // Memory Stage
    logic [DATA_WIDTH-1:0] ALUResultM, WriteDataM, ReadData, PCPlus4M;
    logic [4:0] RdM;
    logic RegWriteM, MemWriteM;
    logic [1:0] ResultSrcM;

    // Write-Back Stage
    logic [DATA_WIDTH-1:0] ALUResultW, WriteDataW, PCPlus4W;
    logic [4:0] RdW;
    logic RegWriteW;
    logic [1:0] ResultSrcW;

    // Additional Signals
    logic jalrSrc, jumpSrc, pcSrc, zero;
    logic [1:0] immSrc;

    // Trigger FSM
    logic triggerRst;
    triggerFSM triggerFSM (
        .clk(clk),
        .rst(rst),
        .trigger(trigger),
        .triggerRst(triggerRst)
    );

    // Fetch Stage
    pcReg #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .OFFSET(OFFSET)
    ) pcReg (
        .clk(clk),
        .triggerRst(triggerRst),
        .nextPC(nextPC),
        .pc(pc),
        .incPC(incPC)
    );

    instrMemory #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .INSTR_WIDTH(INSTR_WIDTH)
    ) instrMemory (
        .pc(pc),
        .instr(instr)
    );

    PRegFetch #(
        .DATA_WIDTH(DATA_WIDTH),
        .REG_DATA_WIDTH(3)
    ) PRegFetch (
        .instr(instr),
        .PCf(pc),
        .PCPlus4F(incPC),
        .clk(clk),
        .PCPlus4D(PCPlus4D),
        .PCd(PCd),
        .InstrD(instr)
    );

    // Decode Stage
    controlUnit controlUnit (
        .op(instr[6:0]),
        .funct3(instr[14:12]),
        .funct7(instr[30]),
        .zero(zero),
        .RegWriteD(RegWriteD),
        .resultSrc(ResultSrcD),
        .jumpSrc(jumpSrc),
        .jalrSrc(jalrSrc),
        .memWrite(MemWriteD),
        .aluControl(ALUControlD),
        .aluSrc(ALUSrcD),
        .immSrc(immSrc),
        .regWrite(RegWriteD)
    );

    extend #(
        .INSTR_WIDTH(INSTR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) extend (
        .instruction(instr),
        .immSrc(immSrc),
        .jumpSrc(jumpSrc),
        .immExt(immExt)
    );

    regfile #(
        .DATA_WIDTH(DATA_WIDTH),
        .REG_DATA_WIDTH(REG_DATA_WIDTH)
    ) regfile (
        .clk(clk),
        .rs1(instr[19:15]),
        .rs2(instr[24:20]),
        .rd(RdW),
        .RegWrite(RegWriteW),
        .ALUout(WriteDataW),
        .ALUop1(rd1),
        .regOp2(rd2),
        .a0(a0)
    );

    PRegDecode #(
        .DATA_WIDTH(DATA_WIDTH),
        .REG_DATA_WIDTH(4)
    ) PRegDecode (
        .rd1(rd1),
        .rd2(rd2),
        .PCd(PCd),
        .ImmExtD(immExt),
        .clk(clk),
        .RdD(instr[11:7]),
        .PCPlus4D(PCPlus4D),
        .rd1E(rd1E),
        .rd2E(rd2E),
        .PCe(PCe),
        .RdE(RdE),
        .ImmExtE(ImmExtE),
        .PcPlus4E(PCPlus4E),
        .RegWriteD(RegWriteD),
        .ResultSrcD(ResultSrcD),
        .MemWriteD(MemWriteD),
        .JumpD(JumpD),
        .BranchD(BranchD),
        .ALUControl(ALUControlD),
        .ALUSrcD(ALUSrcD),
        .RegWriteE(RegWriteE),
        .ResultSrcE(ResultSrcE),
        .MemWriteE(MemWriteE),
        .JumpE(JumpE),
        .BranchE(BranchE),
        .ALUControlE(ALUControlE),
        .ALUSrcE(ALUSrcE)
    );

    aluMux #(
        .DATA_WIDTH(DATA_WIDTH)
    ) aluMux (
        .immOp(ImmExtE),
        .regOp2(rd2E),
        .aluSrc(ALUSrcE),
        .srcB(srcB)
    );

    alu #(
        .DATA_WIDTH(DATA_WIDTH)
    ) alu (
        .srcA(rd1E),
        .srcB(srcB),
        .aluControl(ALUControlE),
        .aluResult(aluResult)
    );

    PRegExecute #(
        .DATA_WIDTH(DATA_WIDTH),
        .REG_DATA_WIDTH(3)
    ) PRegExecute (
        .ALUout(aluResult),
        .WriteData(rd2E),
        .PCPlus4E(PCPlus4E),
        .clk(clk),
        .RdE(RdE),
        .ALUResultM(ALUResultM),
        .WriteDataM(WriteDataM),
        .RdM(RdM),
        .PCPlus4M(PCPlus4M),
        .RegWriteE(RegWriteE),
        .ResultSrcE(ResultSrcE),
        .MemWriteE(MemWriteE),
        .RegWriteM(RegWriteM),
        .ResultSrcM(ResultSrcM),
        .MemWriteM(MemWriteM)
    );

    DataMemory #(
        .DATA_WIDTH(DATA_WIDTH),
        .ADDR_WIDTH(MEM_ADDR_WIDTH)
    ) DataMemory (
        .clk(clk),
        .SizeCtr(instr[14:12]),
        .ALUResult(ALUResultM[MEM_ADDR_WIDTH-1:0]),
        .WriteData(WriteDataM),
        .MemWrite(MemWriteM),
        .ReadData(ReadData)
    );

    resultMux #(
        .DATA_WIDTH(DATA_WIDTH)
    ) resultMux (
        .ReadData(ReadData),
        .ALUResult(ALUResultW),
        .PCPlus4(PCPlus4W),
        .ResultSrc(ResultSrcW),
        .Result(WriteDataW)
    );

endmodule
