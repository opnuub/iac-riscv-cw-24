module branchUnit #(
    parameter DATA_WIDTH = 32
) (
    input   logic [DATA_WIDTH-1:0]  srcA,
    input   logic [DATA_WIDTH-1:0]  srcB,
    input   logic [2:0]             aluControl,
    output  logic                   zero
);

    always_comb begin
        case (aluControl)
            3'b000: zero = ((srcA - srcB) == 32'b0);
            3'b001: zero = ((srcA - srcB) != 32'b0);
            3'b100: zero = srcA < srcB;
            3'b101: zero = srcA >= srcB;
            3'b110: zero = $unsigned(srcA) < $unsigned(srcB);
            3'b111: zero = $unsigned(srcA) >= $unsigned(srcB);
            default: zero = 0;
        endcase
    end
    
endmodule
