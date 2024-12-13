module branchUnit #(
    parameter DATA_WIDTH = 32
) (
    input   logic [DATA_WIDTH-1:0]  srcA,
    input   logic [DATA_WIDTH-1:0]  srcB,
    input   logic [3:0]             aluControl,
    output  logic                   zero
);

    always_comb begin

        
        case (aluControl)
            4'b1000: zero = ((srcA - srcB) === 32'b0); // beq
            4'b1001: zero = ((srcA - srcB) !== 32'b0); // bne
            4'b1100: zero = $signed(srcA) < $signed(srcB);
            4'b1101: zero = $signed(srcA) >= $signed(srcB);
            4'b1110: zero = $unsigned(srcA) < $unsigned(srcB);
            4'b1111: zero = $unsigned(srcA) >= $unsigned(srcB);
            default: zero = 0;
        endcase
    end
    
endmodule
