module mux #(
    parameter DATA_WIDTH = 32
) (
    input   logic [DATA_WIDTH-1:0]  PCPlus4F,
    input   logic [DATA_WIDTH-1:0]  PCTargetE,
    input   logic                   PCsrcE,
    output  logic [DATA_WIDTH-1:0]  PCFp
);

    assign PCFp = PCsrcE ? PCTargetE : PCPlus4F;

endmodule
