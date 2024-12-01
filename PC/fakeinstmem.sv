module fakeinstmem #(
    parameter DATA_WIDTH = 32
) (
    input   logic [DATA_WIDTH-1:0]  PCf,
    output  logic [DATA_WIDTH-1:0]  Rd
);

    assign Rd = PCf + 10;

endmodule
