module controlUnit(
    input   logic [6:0] op,
    input   logic [2:0] funct3,
    input   logic       funct7,
    input   logic       zero,
    output  logic       pcSrc,
    output  logic       jumpSrc,
    output  logic       jalrSrc,
    output  logic [1:0] resultSrc,
    output  logic       memWrite,
    output  logic [2:0] aluControl,
    output  logic       aluSrc,
    output  logic [1:0] immSrc,
    output  logic       regWrite
);

    logic [1:0] aluOp;

    mainDecoder mainDecoder (
        .op(op),
        .zero(zero),
        .pcSrc(pcSrc),
        .jumpSrc(jumpSrc),
        .jalrSrc(jalrSrc),
        .resultSrc(resultSrc),
        .memWrite(memWrite),
        .aluSrc(aluSrc),
        .immSrc(immSrc),
        .regWrite(regWrite),
        .aluOp(aluOp)
    );

    aluDecoder aluDecoder (
        .op(op[5]),
        .aluOp(aluOp),
        .funct3(funct3),
        .funct7(funct7),
        .aluControl(aluControl)
    );
    
endmodule
