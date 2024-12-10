module adder #(
    parameter DATA_WIDTH = 32
) (
    input   logic [DATA_WIDTH-1:0]  PCf,
    output  logic [DATA_WIDTH-1:0]  PCPlus4F
);

    assign PCPlus4F = PCf + 4;

endmodule
