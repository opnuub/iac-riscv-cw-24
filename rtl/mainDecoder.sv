module mainDecoder (
    input   logic [6:0] op,
    input   logic [2:0] funct3,     // Added funct3 input for memory operation decoding
    output  logic       Branch,     // Indicates branch instruction
    output  logic       jumpSrc,    // For JAL/JALR instructions
    output  logic       jalrSrc,    // Distinguishes JALR (jump to register)
    output  logic [1:0] resultSrc,  // Expanded to 2 bits
    output  logic       memWrite,   // Memory write enable
    output  logic       aluSrc,     // ALU source select
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
        sizeSrc   = 3'b000;  // Default to byte-sized operations

        case (op)
            7'b1101111: begin // JAL
                regWrite  = 1;
                immSrc    = 2'b11;
                aluSrc    = 1;
                resultSrc = 2'b10; // Result is PC + 4
                aluOp     = 2'b00;
                jumpSrc   = 1;     // Indicate jump
            end
            7'b1100111: begin // JALR
                regWrite  = 1;
                immSrc    = 2'b00;
                aluSrc    = 1;
                resultSrc = 2'b10; // Result is PC + 4
                aluOp     = 2'b00;
                jumpSrc   = 1;     // Indicate jump
                jalrSrc   = 1;     // Distinguish JALR
            end
            7'b1100011: begin // B-type (branch instructions)
                Branch    = 1;     // Indicates branch instruction
                immSrc    = 2'b10; // Branch immediate
                aluOp     = 2'b01; // ALU for branch comparison
                aluSrc    = 0;
            end
            7'b0000011: begin // Load instructions
                regWrite  = 1;
                immSrc    = 2'b00; // Load immediate
                aluSrc    = 1;     // Immediate as ALU source
                resultSrc = 2'b01; // Result from memory
                case (funct3)
                    3'b000: sizeSrc = 3'b000; // lb (Load Byte)
                    3'b001: sizeSrc = 3'b001; // lh (Load Halfword)
                    3'b010: sizeSrc = 3'b010; // lw (Load Word)
                    3'b100: sizeSrc = 3'b100; // lbu (Load Byte Unsigned)
                    3'b101: sizeSrc = 3'b101; // lhu (Load Halfword Unsigned)
                    default: sizeSrc = 3'b000; // Default to byte-sized load
                endcase
            end
            7'b0100011: begin // Store instructions
                memWrite  = 1;     // Enable memory write
                immSrc    = 2'b01; // Store immediate
                aluSrc    = 1;     // Immediate as ALU source
                case (funct3)
                    3'b000: sizeSrc = 3'b000; // sb (Store Byte)
                    3'b001: sizeSrc = 3'b001; // sh (Store Halfword)
                    3'b010: sizeSrc = 3'b010; // sw (Store Word)
                    default: sizeSrc = 3'b000; // Default to byte-sized store
                endcase
            end
            7'b0010011: begin // Immediate (e.g., ADDI)
                regWrite  = 1;
                immSrc    = 2'b00; // Arithmetic immediate
                aluSrc    = 1;     // Immediate as ALU source
                aluOp     = 2'b10; // ALU performs operation
            end
            7'b0110011: begin // R-type
                regWrite  = 1;
                aluOp     = 2'b10; // ALU performs operation
            end 
            
            7'b0110111: begin // upper immediate 6:24 lui
                regWrite = 1;
                immSrc = 2'b11;
                aluSrc = 1;
                memWrite = 0;
                resultSrc = 0;
                aluOp = 2'b11;
                jalrSrc = 0;
                jumpSrc = 0;
            end
            
            default: begin
                // Default case: all control signals inactive
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
