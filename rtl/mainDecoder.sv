module mainDecoder (
    input   logic [6:0] op,         // Opcode
    input   logic [2:0] funct3,     // Function code for load/store/branch
    output  logic       Branch,     // Indicates branch instruction
    output  logic       jumpSrc,    // For JAL/JALR instructions
    output  logic       jalrSrc,    // Distinguishes JALR (jump to register)
    output  logic [1:0] resultSrc,  // Source of result (ALU, memory, or PC)
    output  logic       memWrite,   // Memory write enable
    output  logic       aluSrc,     // ALU source select (register or immediate)
    output  logic [1:0] immSrc,     // Immediate source select
    output  logic       regWrite,   // Register write enable
    output  logic [1:0] aluOp,      // ALU operation select
    output  logic [2:0] sizeSrc     // Size control for load/store instructions
);

    always_comb begin
        // Default values
        regWrite  = 0;
        memWrite  = 0;
        aluSrc    = 0;
        immSrc    = 2'b00;
        resultSrc = 2'b00;
        Branch    = 0;
        jumpSrc   = 0;
        jalrSrc   = 0;
        aluOp     = 2'b00;
        sizeSrc   = 3'b000;

        case (op)
            // JAL
            7'b1101111: begin
                regWrite  = 1;
                immSrc    = 2'b11;
                aluSrc    = 1;
                resultSrc = 2'b10;
                aluOp     = 2'b00;
                jumpSrc   = 1;
            end

            // JALR
            7'b1100111: begin
                regWrite  = 1;
                immSrc    = 2'b00;
                aluSrc    = 1;
                resultSrc = 2'b10;
                aluOp     = 2'b00;
                jumpSrc   = 1;
                jalrSrc   = 1;
            end

            // Branch
            7'b1100011: begin
                Branch    = 1;
                immSrc    = 2'b10;
                aluOp     = 2'b01;
            end

            // Load
            7'b0000011: begin
                regWrite  = 1;
                immSrc    = 2'b00;
                aluSrc    = 1;
                resultSrc = 2'b01;
                case (funct3)
                    3'b000: sizeSrc = 3'b000; // lb
                    3'b001: sizeSrc = 3'b001; // lh
                    3'b010: sizeSrc = 3'b010; // lw
                    3'b100: sizeSrc = 3'b100; // lbu
                    3'b101: sizeSrc = 3'b101; // lhu
                    default: sizeSrc = 3'b000;
                endcase
            end

            // Store
            7'b0100011: begin
                memWrite  = 1;
                immSrc    = 2'b01;
                aluSrc    = 1;
                case (funct3)
                    3'b000: sizeSrc = 3'b000; // sb
                    3'b001: sizeSrc = 3'b001; // sh
                    3'b010: sizeSrc = 3'b010; // sw
                    default: sizeSrc = 3'b000;
                endcase
            end

            // Immediate ALU
            7'b0010011: begin
                regWrite  = 1;
                immSrc    = 2'b00;
                aluSrc    = 1;
                aluOp     = 2'b10;
            end

            // Register ALU
            7'b0110011: begin
                regWrite  = 1;
                aluOp     = 2'b10;
            end

            // LUI
            7'b0110111: begin
                regWrite  = 1;
                immSrc    = 2'b11;
                aluSrc    = 1;
                aluOp     = 2'b11;
            end

            // AUIPC
            7'b0010111: begin
                regWrite  = 1;
                immSrc    = 2'b11;
                aluSrc    = 1;
                aluOp     = 2'b11;
            end

            default: begin
                regWrite  = 0;
                memWrite  = 0;
                aluSrc    = 0;
                immSrc    = 2'b00;
                resultSrc = 2'b00;
                Branch    = 0;
                jumpSrc   = 0;
                jalrSrc   = 0;
                aluOp     = 2'b00;
                sizeSrc   = 3'b000;
            end
        endcase
    end
endmodule