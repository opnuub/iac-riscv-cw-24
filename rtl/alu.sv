module alu #(
    parameter DATA_WIDTH = 32
) (
    input   logic [DATA_WIDTH-1:0]  srcA,  // SrcA
    input   logic [DATA_WIDTH-1:0]  srcB,  // SrcB
    input   logic [3:0]             aluControl, // ALUControl
    output  logic [DATA_WIDTH-1:0]  aluResult   // ALUResult
);
    
always_comb begin
    case (aluControl)
        4'b0000: aluResult = srcA + srcB;
        4'b0001: aluResult = srcA - srcB;
        4'b0010: aluResult = srcA & srcB;
        4'b0011: aluResult = srcA | srcB;
        4'b0100: aluResult = srcB; // lui
        4'b0101: aluResult = ($signed(srcA) < $signed(srcB)) ? 32'b1 : 32'b0;
        4'b0110: aluResult = srcA << srcB[4:0];
        4'b0111: aluResult = srcA >> srcB[4:0];
    endcase
end

endmodule
