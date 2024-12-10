module mainDecoder (
    input   logic [6:0] op,
    input   logic       zero,
    output  logic       pcSrc,
    output  logic       jalrSrc,
    output  logic       jumpSrc,
    output  logic       resultSrc,
    output  logic       memWrite,
    output  logic       aluSrc,
    output  logic [1:0] immSrc,
    output  logic       regWrite,
    output  logic [1:0] aluOp
);

    always_comb begin
        case (op)
            7'b1101111: begin // jal
                regWrite = 1; // write rd = PC+4
                immSrc = 2'b11; // like lui
                aluSrc = 1;
                memWrite = 0;
                resultSrc = 0;
                pcSrc = 1;
                aluOp = 2'b00;
                jalrSrc = 0;
                jumpSrc = 1;
            end
            7'b1100111: begin // jalr
                regWrite = 1;
                immSrc = 2'b00; // like addi
                aluSrc = 1;
                memWrite = 0;
                resultSrc = 0;
                pcSrc = 1;
                aluOp = 2'b00;
                jalrSrc = 1;
                jumpSrc = 1;
            end
            7'b0000011: begin // load 6:22
                regWrite = 1;
                immSrc = 2'b00;
                aluSrc = 1;
                memWrite = 0;
                resultSrc = 1;
                pcSrc = 0;
                aluOp = 2'b00;
                jalrSrc = 0;
                jumpSrc = 0;
            end
            7'b0100011: begin // store 6:22
                regWrite = 0;
                immSrc = 2'b01;
                aluSrc = 1;
                memWrite = 1;
                resultSrc = 1; // x (don't care)
                pcSrc = 0;
                aluOp = 2'b00;
                jalrSrc = 0;
                jumpSrc = 0;
            end
            7'b0110111: begin // upper immediate 6:24 lui
                regWrite = 1;
                immSrc = 2'b11;
                aluSrc = 1;
                memWrite = 0;
                resultSrc = 0;
                pcSrc = 0;
                aluOp = 2'b11;
                jalrSrc = 0;
                jumpSrc = 0;
            end
            7'b0010011: begin // lower immediate 6:22 addi
                regWrite = 1;
                immSrc = 2'b00;
                aluSrc = 1;
                memWrite = 0;
                resultSrc = 0;
                pcSrc = 0;
                aluOp = 2'b10;
                jalrSrc = 0;
                jumpSrc = 0;
            end
            7'b0110011: begin // R-type
                regWrite = 1;
                immSrc = 2'b00; // x
                aluSrc = 0;
                memWrite = 0;
                resultSrc = 0;
                pcSrc = 0;
                aluOp = 2'b10;
                jalrSrc = 0;
                jumpSrc = 0;
            end
            7'b1100011: begin // B-type
                regWrite = 0;
                immSrc = 2'b10;
                aluSrc = 0;
                memWrite = 0;
                resultSrc = 0; // x
                aluOp = 2'b01;
                jalrSrc = 0;
                jumpSrc = 0;
                if (zero)
                    pcSrc = 1;
                else
                    pcSrc = 0;
            end
            default: begin // shouldn't happen
                regWrite = 1;
                immSrc = 2'b00; // x
                aluSrc = 0;
                memWrite = 0;
                resultSrc = 0;
                pcSrc = 0;
                aluOp = 2'b10;
                jalrSrc = 0;
                jumpSrc = 0;
            end
        endcase 
    end
    
endmodule
