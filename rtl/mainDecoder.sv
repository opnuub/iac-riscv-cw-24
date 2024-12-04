module mainDecoder (
    input   logic [6:0] op,
    input   logic       zero,
    output  logic       pcSrc,
    output  logic       resultSrc,
    output  logic       memWrite,
    output  logic       aluSrc,
    output  logic [1:0] immSrc,
    output  logic       regWrite,
    output  logic [1:0] aluOp
);

    always_comb begin
        case (op)
            7'b0000011: begin // load 6:22
                regWrite = 1;
                immSrc = 2'b00;
                aluSrc = 1;
                memWrite = 0;
                resultSrc = 1;
                pcSrc = 0;
                aluOp = 2'b00;
            end
            7'b0100011: begin // store 6:22
                regWrite = 0;
                immSrc = 2'b01;
                aluSrc = 1;
                memWrite = 1;
                resultSrc = 1; // x (don't care)
                pcSrc = 0;
                aluOp = 2'b00;
            end
            7'b0010011: begin // immediate 6:22
                aluSrc = 1
                // more
            end
            7'b0110011: begin // R-type
                regWrite = 1;
                immSrc = 2'b00; // x
                aluSrc = 0;
                memWrite = 0;
                resultSrc = 0;
                pcSrc = 0;
                aluOp = 2'b10;
            end
            7'b1100011: begin // B-type beq only
                regWrite = 0;
                immSrc = 2'b10;
                aluSrc = 0;
                memWrite = 0;
                resultSrc = 1; // x
                aluOp = 2'b01;
                if (zero)
                    pcSrc = 1
                else
                    pcSrc = 0
            end
            default: begin // shouldn't happen
                regWrite = 1;
                immSrc = 2'b00; // x
                aluSrc = 0;
                memWrite = 0;
                resultSrc = 0;
                pcSrc = 0;
                aluOp = 2'b10;
            end
        endcase 
    end
    
endmodule