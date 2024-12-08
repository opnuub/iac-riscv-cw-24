module mainDecoder (
    input   logic [6:0] op,
    output  logic       Branch,     // Indicates branch instruction
    output  logic       jumpSrc,    // For JAL/JALR instructions
    output  logic       jalrSrc,    // Distinguishes JALR (jump to register)
    output  logic [1:0] resultSrc,  // Expanded to 2 bits
    output  logic       memWrite,   // Memory write enable
    output  logic       aluSrc,     // ALU source select
    output  logic [1:0] immSrc,     // Immediate source select
    output  logic       regWrite,   // Register write enable
    output  logic [1:0] aluOp       // ALU operation select
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
        jalrSrc   = 0; // Default to inactive
        aluOp     = 2'b00;

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
            end
            7'b0000011: begin // Load
                regWrite  = 1;
                immSrc    = 2'b00; // Load immediate
                aluSrc    = 1;     // Immediate as ALU source
                resultSrc = 2'b01; // Result from memory
            end
            7'b0100011: begin // Store
                memWrite  = 1;     // Enable memory write
                immSrc    = 2'b01; // Store immediate
                aluSrc    = 1;     // Immediate as ALU source
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
            end
        endcase
    end

endmodule
