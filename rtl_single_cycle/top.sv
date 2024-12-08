module top #(
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

    logic [ADDR_WIDTH-1:0]  pc;
    logic [INSTR_WIDTH-1:0] instr;
    logic [INSTR_WIDTH-1:0] immOp;
    logic                   regWrite;
    logic [2:0]             aluControl;
    logic                   aluSrc;
    logic [1:0]             immSrc;
    logic                   jalrSrc;
    logic                   jumpSrc;
    logic                   pcSrc;
    logic [DATA_WIDTH-1:0]  srcA;
    logic [DATA_WIDTH-1:0]  srcB;
    logic [DATA_WIDTH-1:0]  wd3;
    logic [DATA_WIDTH-1:0]  regOp2;
    logic [DATA_WIDTH-1:0]  aluResult;
    logic                   resultSrc;
    logic                   memWrite;
    logic [DATA_WIDTH-1:0]  readData;
    logic [DATA_WIDTH-1:0]  result;
    logic                   zero;
    logic [ADDR_WIDTH-1:0]  nextPC;
    logic [ADDR_WIDTH-1:0]  branchPC;
    logic [ADDR_WIDTH-1:0]  incPC;
    logic                   triggerRst;

    jumpMux #(
        .DATA_WIDTH(DATA_WIDTH)
    ) jumpMux (
        .result (result),
        .incPC (incPC),
        .jumpSrc (jumpSrc),
        .ALUout (wd3)
    );

    extendPC #(
        .DATA_WIDTH(DATA_WIDTH),
        .ADDR_WIDTH(ADDR_WIDTH)
    ) extendPC (
        .pc (pc),
        .immOp (immOp),
        .result (result),
        .jalrSrc (jalrSrc),
        .branchPC (branchPC)
    );

    triggerFSM triggerFSM (
        .clk (clk),
        .rst (rst),
        .trigger (trigger),
        .triggerRst (triggerRst)
    );

    resultMux #(
        .DATA_WIDTH(DATA_WIDTH)
    ) resultMux (
        .ReadData (readData),
        .ALUResult (aluResult),
        .ResultSrc (resultSrc),
        .Result (result)
    );

    DataMemory #(
        .DATA_WIDTH(DATA_WIDTH),
        .ADDR_WIDTH(MEM_ADDR_WIDTH)
    ) DataMemory (
        .clk (clk),
        .SizeCtr (instr[14:12]), // not set
        .ALUResult (aluResult[MEM_ADDR_WIDTH-1:0]),rr44444453545555555555547777777777777777777777777777
        .WriteData (regOp2),
        .MemWrite (memWrite),
        .ReadData (readData)
    );

    alu #(
        .DATA_WIDTH(DATA_WIDTH)
    ) alu (
        .srcA (srcA),
        .srcB (srcB),
        .aluControl (aluControl),
        .aluResult (aluResult)
    );

    aluMux #(
        .DATA_WIDTH(DATA_WIDTH)
    ) aluMux (
        .immOp (immOp),
        .regOp2 (regOp2),
        .aluSrc (aluSrc),
        .srcB (srcB)
    );

    regFile #(
        .DATA_WIDTH(DATA_WIDTH),
        .REG_DATA_WIDTH(REG_DATA_WIDTH)
    ) regFile (
        .clk (clk),
        .rs1 (instr[19:15]),
        .rs2 (instr[24:20]),
        .rd (instr[11:7]),
        .RegWrite (regWrite),
        .ALUout (wd3),
        .ALUop1 (srcA),
        .regOp2 (regOp2),
        .a0 (a0)
    );

    instrMemory #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .INSTR_WIDTH(INSTR_WIDTH)
    ) instrMemory (
        .pc (pc),
        .instr (instr)
    );

    extend #(
        .INSTR_WIDTH(INSTR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) extend (
        .instruction (instr),
        .immSrc (immSrc),
        .jumpSrc (jumpSrc),
        .immExt (immOp)
    );

    pcReg #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .OFFSET(OFFSET)
    ) pcReg (
        .clk (clk),
        .triggerRst (triggerRst),
        .pc (pc),
        .nextPC (nextPC),
        .incPC (incPC)
    );

    pcMux #(
        .ADDR_WIDTH(ADDR_WIDTH)
    ) pcMux (
        .incPC (incPC),
        .branchPC (branchPC),
        .PCsrc (pcSrc),
        .nextPC (nextPC)
    );
    
    controlUnit controlUnit (
        .op (instr[6:0]),
        .funct3 (instr[14:12]),
        .funct7 (instr[30]),
        .zero (zero),
        .pcSrc (pcSrc),
        .jumpSrc (jumpSrc),
        .jalrSrc (jalrSrc),
        .resultSrc (resultSrc),
        .memWrite (memWrite),
        .aluControl (aluControl),
        .aluSrc (aluSrc),
        .immSrc (immSrc),
        .regWrite (regWrite)
    );

    branchUnit #(
        .DATA_WIDTH(DATA_WIDTH)
    ) branchUnit (
        .srcA (srcA),
        .srcB (regOp2),
        .aluControl (aluControl),
        .zero (zero)
    );

endmodule
