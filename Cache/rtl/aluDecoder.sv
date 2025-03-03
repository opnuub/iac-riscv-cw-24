module aluDecoder (
    input   logic       op,          // Indicates operation type
    input   logic [1:0] aluOp,       // ALU operation from main decoder
    input   logic [2:0] funct3,      // Function code
    input   logic       funct7,      // MSB of funct7
    output  logic [3:0] aluControl   // 4-bit ALU control signal
);

    logic [1:0] opfunct7; // Combines operation and funct7 for R-type differentiation
    assign opfunct7 = {op, funct7};

    always_comb begin
        case (aluOp)
            // Default operations for Load/Store and Branch
            2'b00: aluControl = 4'b0000; // add
            2'b01: begin
                case (funct3)
                    3'b000: aluControl = 4'b1000; // beq
                    3'b001: aluControl = 4'b1001; // bne
                    3'b100: aluControl = 4'b1100; // blt
                    3'b101: aluControl = 4'b1101; // bge
                    3'b110: aluControl = 4'b1110; // bltu
                    3'b111: aluControl = 4'b1111; // bgeu
                    default: aluControl = 4'b0000; // Default to add
                endcase
            end
            // R-type and Immediate ALU instructions
            2'b10: begin
                case (funct3)
                    3'b000: begin
                        if (opfunct7 == 2'b11)
                            aluControl = 4'b0001; // sub
                        else
                            aluControl = 4'b0000; // add
                    end
                    3'b001: aluControl = 4'b0110; // sll
                    3'b010: aluControl = 4'b0101; // slt
                    3'b011: aluControl = 4'b0100; // li
                    3'b100: aluControl = 4'b0010; // xor
                    3'b101: aluControl = 4'b0111; // srl
                    3'b110: aluControl = 4'b0011; // or
                    3'b111: aluControl = 4'b0010; // and
                    default: aluControl = 4'b0000; // Default to add
                endcase
            end
            2'b11: aluControl = 4'b0100; // lui
            default: aluControl = 4'b0000; // Default to add
        endcase
    end

endmodule
