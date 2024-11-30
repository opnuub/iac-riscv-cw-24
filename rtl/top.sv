module top #(
    parameter DATA_WIDTH = 32,
    parameter INSTR_WIDTH = 32,
    parameter ADDR_WIDTH = 16,
    parameter REG_DATA_WIDTH = 5
) (
    input   logic                   clk,
    input   logic                   rst,
    output  logic [DATA_WIDTH-1:0]  a0
);

    logic [ADDR_WIDTH-1:0]  pc;
    logic [INSTR_WIDTH-1:0] instr;
    logic [INSTR_WIDTH-1:0] immOp;
    // logic                   regWrite;
    // logic [2:0]             aluCtrl;
    // logic                   aluSrc;
    logic [1:0]             immSrc;
    logic                   pcSrc;
    // logic [DATA_WIDTH-1:0]  aluOp1;
    // logic [DATA_WIDTH-1:0]  aluOp2;
    // logic [DATA_WIDTH-1:0]  regOp2;
    // logic [DATA_WIDTH-1:0]  aluOut;
    // logic                   zero;
    logic [ADDR_WIDTH-1:0]  nextPC;
    logic [ADDR_WIDTH-1:0]  branchPC;
    logic [ADDR_WIDTH-1:0]  incPC;
    
    instrMemory #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .INSTR_WIDTH(INSTR_WIDTH)
    ) instrMemory (
        .pc (pc),
        .instr (instr)
    );

    extend #(
        .INSTR_WIDTH(INSTR_WIDTH)
    ) extend (
        .instruction(instr),
        .immSrc(immSrc),
        .immExt(immOp)
    );

    pcReg #(
        .ADDR_WIDTH(ADDR_WIDTH)
    ) pcReg (
        .clk (clk),
        .rst (rst),
        .pc (pc),
        .nextPC (nextPC)
    );

    pcMux #(
        .ADDR_WIDTH(ADDR_WIDTH)
    ) pcMux (
        .incPC (incPC),
        .branchPC (branchPC),
        .PCsrc (pcSrc),
        .nextPC (nextPC)
    );

    always_comb begin
        incPC = pc + 4;
        branchPC = pc + immOp[15:0];
    end

endmodule
