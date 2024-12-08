module pcMux #(
    parameter ADDR_WIDTH = 32
) (
    input   logic JumpE,
    input   logic BranchD,
    input   logic zero,
    output  logic [ADDR_WIDTH-1:0]  nextPC
);
    assign nextPC = PCsrc ? branchPC : incPC;
    
endmodule
