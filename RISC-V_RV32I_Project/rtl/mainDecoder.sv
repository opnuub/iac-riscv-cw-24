module mainDecoder ( 
    input   logic [6:0] op,
    input   logic       zero,
    output  logic       pcSrc,
    output  logic       jalrSrc,
    output  logic       jumpSrc,
    output  logic [1:0] resultSrc, // Expanded to 2 bits
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
                immSrc = 2'b11; // for jal instruction
                aluSrc = 1;
                memWrite = 0;
                resultSrc = 2'b10; // Result from PC+4
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
                resultSrc = 2'b10; // Result from PC+4
                pcSrc = 1;
                aluOp = 2'b00;
                jalrSrc = 1;
                jumpSrc = 1;
            end
            7'b0000011: begin // load
                regWrite = 1;
                immSrc = 2'b00;
                aluSrc = 1;
                memWrite = 0;
                resultSrc = 2'b01; // Result from memory
                pcSrc = 0;
                aluOp = 2'b00;
                jalrSrc = 0;
                jumpSrc = 0;
            end
            7'b0100011: begin // store
                regWrite = 0;
                immSrc = 2'b01;
                aluSrc = 1;
                memWrite = 1;
                resultSrc = 2'b00; // x (don't care)
                pcSrc = 0;
                aluOp = 2'b00;
                jalrSrc = 0;
                jumpSrc = 0;
            end
            7'b0110111: begin // lui
                regWrite = 1;
                immSrc = 2'b11;
                aluSrc = 1;
                memWrite = 0;
                resultSrc = 2'b00; // Result from immediate
                pcSrc = 0;
                aluOp = 2'b11;
                jalrSrc = 0;
                jumpSrc = 0;
            end
            7'b0010011: begin // addi
                regWrite = 1;
                immSrc = 2'b00;
                aluSrc = 1;
                memWrite = 0;
                resultSrc = 2'b00; // Result from ALU
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
                resultSrc = 2'b00; // Result from ALU
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
                resultSrc = 2'b00; // x (don't care)
                aluOp = 2'b01;
                jalrSrc = 0;
                jumpSrc = 0;
                pcSrc = zero ? 1 : 0; // Branch decision based on zero flag
            end
            default: begin // Default case
                regWrite = 0;
                immSrc = 2'b00; // x
                aluSrc = 0;
                memWrite = 0;
                resultSrc = 2'b00; // Default ALU result
                pcSrc = 0;
                aluOp = 2'b00;
                jalrSrc = 0;
                jumpSrc = 0;
            end
        endcase 
    end
    
endmodule
