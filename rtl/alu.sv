module alu #(
    parameter DATA_WIDTH = 32
) (
    input   logic [DATA_WIDTH-1:0]  srcA,  // SrcA
    input   logic [DATA_WIDTH-1:0]  srcB,  // SrcB
    input   logic [2:0]             aluControl, // ALUControl
    output  logic [DATA_WIDTH-1:0]  aluResult   // ALUResult
);
    
always_comb begin
    case (aluControl)
        3'b000: aluResult = srcA + srcB;
        3'b001: aluResult = srcA - srcB;
        3'b010: aluResult = srcA & srcB;
        3'b011: aluResult = srcA | srcB;
        3'b100: aluResult = ($unsigned(srcA) < $unsigned(srcB)) ? 32'b1 : 32'b0;
        3'b101: aluResult = (srcA < srcB) ? 32'b1 : 32'b0;
        3'b110: aluResult = srcA << srcB[4:0];
        3'b111: aluResult = srcA >> srcB[4:0];
    endcase
end

endmodule
