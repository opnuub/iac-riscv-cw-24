module extendPC #(
    parameter DATA_WIDTH = 32,
    parameter ADDR_WIDTH = 32
) (
    input   logic [ADDR_WIDTH-1:0]  PCEn,
    input   logic [DATA_WIDTH-1:0]  immOp,
    output  logic [ADDR_WIDTH-1:0]  PCTargetE
);

    always_comb
            PCTargetE = PCEn + immOp;
    
endmodule
