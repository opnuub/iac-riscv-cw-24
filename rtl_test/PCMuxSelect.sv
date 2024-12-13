module PCMuxSelect #(
    
) (
    input   logic JumpE,
    input   logic BranchE,
    input   logic zero,
    output  logic pcSrcE
);

assign pcSrcE = JumpE | (BranchE & zero);

endmodule
