module aluDecoder (
    input   logic [6:0] op,
    input   logic [1:0] aluOp,
    input   logic [2:0] funct3,
    input   logic       funct7, // supposedly 7 bits but only bit 30 is significant
    output  logic [2:0] aluControl
);
    logic [1:0] opfunct7;
    assign opfunct7 = {op[5], funct7[5]}

    always_comb begin
        case (aluOp)
            2'b00: aluControl = 3'b000;
            2'b01: aluControl = funct3;
            2'b10: begin
                case (funct3)
                    3'b000: begin
                        if (opfunct7 == 2'b11)
                            aluControl = 3'b001; // sub
                        else
                            aluControl = 3'b000; // add
                    end
                    3'b001: aluControl = 3'b110; // sll
                    3'b010: aluControl = 3'b101; // slt
                    3'b011: aluControl = 3'b100; // sltu
                    3'b100: aluControl = 3'b000; // xor (doesn't exist)
                    3'b101: aluControl = 3'b111; // srl
                    3'b110: aluControl = 3'b011; // or
                    3'b111: aluControl = 3'b010; // and
                endcase
            end
            default: aluControl = 3'b000; // shouldn't happen, reserved for jump
        endcase
    end
    
endmodule