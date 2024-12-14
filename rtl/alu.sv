module alu #(
    parameter DATA_WIDTH = 32
) (
    input   logic [DATA_WIDTH-1:0]  srcA,
    input   logic [DATA_WIDTH-1:0]  srcB,
    input   logic [3:0]             aluControl,
    output  logic [DATA_WIDTH-1:0]  aluResult
);
    
    logic signed [DATA_WIDTH-1:0] signedA;
    logic [4:0] shiftAmt;
    
    always_comb begin
        signedA = srcA;  // Convert to signed for arithmetic operations
        shiftAmt = srcB[4:0];  // Only use lower 5 bits for shift amount
        
        case (aluControl)
            4'b0000: aluResult = srcA + srcB;           // ADD
            4'b0001: aluResult = srcA - srcB;           // SUB
            4'b0010: aluResult = srcA & srcB;           // AND
            4'b0011: aluResult = srcA | srcB;           // OR
            4'b0100: aluResult = srcB;                  // LUI
            4'b0101: aluResult = ($signed(srcA) < $signed(srcB)) ? 32'b1 : 32'b0;  // SLT
            4'b0110: aluResult = srcA << shiftAmt;      // SLL
            4'b0111: aluResult = srcA >> shiftAmt;      // SRL
            4'b1000: aluResult = signedA >>> shiftAmt;  // SRA - Arithmetic right shift
            4'b1001: aluResult = srcA ^ srcB;           // XOR
            4'b1010: aluResult = (srcA < srcB) ? 32'b1 : 32'b0;  // SLTU
            4'b1011: aluResult = srcA + srcB;           // AUIPC
            default: aluResult = srcA + srcB;
        endcase
    end
endmodule