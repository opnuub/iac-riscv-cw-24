module extendPC #(
    parameter DATA_WIDTH = 32,
    parameter ADDR_WIDTH = 32
) (
    input   logic [ADDR_WIDTH-1:0]  pc,
    input   logic [DATA_WIDTH-1:0]  immOp,
    input   logic [DATA_WIDTH-1:0]  result,
    input   logic                   jalrSrc,
    output  logic [ADDR_WIDTH-1:0]  branchPC
);

    always_comb
        if (jalrSrc)
            branchPC = result;
        else
            branchPC = pc + immOp;
    
endmodule
