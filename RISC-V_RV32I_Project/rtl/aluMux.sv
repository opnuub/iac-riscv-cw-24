module aluMux #(
    parameter DATA_WIDTH = 32
) (
    input   logic [DATA_WIDTH-1:0]  immOp,
    input   logic [DATA_WIDTH-1:0]  regOp2,
    input   logic                   aluSrc,
    output  logic [DATA_WIDTH-1:0]  srcB
);

    assign srcB = aluSrc ? immOp : regOp2;

endmodule
