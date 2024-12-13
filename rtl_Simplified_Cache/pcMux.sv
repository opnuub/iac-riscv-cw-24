module pcMux #(
    parameter ADDR_WIDTH = 32
) (
    input   logic [ADDR_WIDTH-1:0]  branchPC,
    input   logic [ADDR_WIDTH-1:0]  PCPlus4F,
    input   logic                   PCsrc,
    output  logic [ADDR_WIDTH-1:0]  nextPC
);
    assign nextPC = PCsrc ? branchPC : PCPlus4F;
    
endmodule
