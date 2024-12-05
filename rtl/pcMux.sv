module pcMux #(
    parameter ADDR_WIDTH = 16
) (
    input   logic [ADDR_WIDTH-1:0]  branchPC,
    input   logic [ADDR_WIDTH-1:0]  incPC,
    input   logic                   PCsrc,
    output  logic [ADDR_WIDTH-1:0]  nextPC
);
    assign nextPC = PCsrc ? branchPC : incPC;
    
endmodule
