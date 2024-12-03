module controller (
    input  logic        clk_i,
    input  logic        rst_ni,
    
    // Decoder
    input  logic [6:0]  opcode_i,
    input  logic [2:0]  funct3_i,
    input  logic [6:0]  funct7_i,
    
    // Branch
    input  logic        branch_eq_i,
    input  logic        branch_lt_i,
    input  logic        branch_ltu_i,
    
    // Register Control, register write enable and select
    output logic        rf_wen_o,        
    output logic [1:0]  rf_wdata_sel_o,
    
    // ALU Control
    output logic [3:0]  alu_op_o,       
    output logic [1:0]  alu_src1_sel_o,  // ALU source 1 select
    output logic [1:0]  alu_src2_sel_o,  // ALU source 2 select
    
    // Memory Control  
    output logic        mem_wen_o,       // Memory write enable
    output logic [2:0]  mem_size_o,      // Memory access size (B/H/W)
    output logic        mem_signed_o,     // Memory load sign extend
    
    // Immediate Control
    output logic [2:0]  imm_type_o,      // Immediate type
    
    // PC Control
    output logic [2:0]  next_pc_sel_o,   // Next PC select
    
    // Exception Control
    output logic        illegal_instr_o
);

// Instruction type para
typedef enum logic [6:0] {
    OPCODE_LUI    = 7'b0110111,
    OPCODE_AUIPC  = 7'b0010111,
    OPCODE_JAL    = 7'b1101111,
    OPCODE_JALR   = 7'b1100111,
    OPCODE_BRANCH = 7'b1100011,
    OPCODE_LOAD   = 7'b0000011,
    OPCODE_STORE  = 7'b0100011,
    OPCODE_OP_IMM = 7'b0010011,
    OPCODE_OP     = 7'b0110011
} opcode_e;

// ALU operation para
typedef enum logic [3:0] {
    ALU_ADD  = 4'b0000,
    ALU_SUB  = 4'b0001,
    ALU_SLL  = 4'b0010,
    ALU_SLT  = 4'b0011,
    ALU_SLTU = 4'b0100,
    ALU_XOR  = 4'b0101,
    ALU_SRL  = 4'b0110,
    ALU_SRA  = 4'b0111,
    ALU_OR   = 4'b1000,
    ALU_AND  = 4'b1001,
    ALU_LUI  = 4'b1010
} alu_op_e;

// Immediate type para
typedef enum logic [2:0] {
    IMM_I = 3'b000,
    IMM_S = 3'b001,
    IMM_B = 3'b010,
    IMM_U = 3'b011,
    IMM_J = 3'b100
} imm_type_e;


always_comb begin
    // Default values
    rf_wen_o        = 1'b0;
    rf_wdata_sel_o  = 2'b00;
    alu_op_o        = ALU_ADD;
    alu_src1_sel_o  = 2'b00;
    alu_src2_sel_o  = 2'b00;
    mem_wen_o       = 1'b0;
    mem_size_o      = funct3_i;
    mem_signed_o    = 1'b1;
    imm_type_o      = IMM_I;
    next_pc_sel_o   = 3'b000;
    illegal_instr_o = 1'b0;

    unique case (opcode_i)
        OPCODE_OP: begin // R-type
            rf_wen_o = 1'b1;
            unique case (funct3_i)
                3'b000: alu_op_o = (funct7_i[5]) ? ALU_SUB : ALU_ADD;
                3'b001: alu_op_o = ALU_SLL;
                3'b010: alu_op_o = ALU_SLT;
                3'b011: alu_op_o = ALU_SLTU;
                3'b100: alu_op_o = ALU_XOR;
                3'b101: alu_op_o = (funct7_i[5]) ? ALU_SRA : ALU_SRL;
                3'b110: alu_op_o = ALU_OR;
                3'b111: alu_op_o = ALU_AND;
                default: illegal_instr_o = 1'b1;
            endcase
        end

        OPCODE_OP_IMM: begin // I-type
            rf_wen_o = 1'b1;
            alu_src2_sel_o = 2'b01;
            imm_type_o = IMM_I;
            unique case (funct3_i)
                3'b000: alu_op_o = ALU_ADD;  // ADDI
                3'b010: alu_op_o = ALU_SLT;  // SLTI
                3'b011: alu_op_o = ALU_SLTU; // SLTIU
                3'b100: alu_op_o = ALU_XOR;  // XORI
                3'b110: alu_op_o = ALU_OR;   // ORI
                3'b111: alu_op_o = ALU_AND;  // ANDI
                3'b001: alu_op_o = ALU_SLL;  // SLLI
                3'b101: alu_op_o = (funct7_i[5]) ? ALU_SRA : ALU_SRL;
                default: illegal_instr_o = 1'b1;
            endcase
        end

        OPCODE_LOAD: begin
            rf_wen_o = 1'b1;
            rf_wdata_sel_o = 2'b01;
            alu_src2_sel_o = 2'b01;
            imm_type_o = IMM_I;
            mem_signed_o = ~funct3_i[2];
            unique case (funct3_i)
                3'b000,  // LB
                3'b001,  // LH
                3'b010,  // LW
                3'b100,  // LBU
                3'b101: begin  // LHU
                    mem_size_o = funct3_i;
                end
                default: illegal_instr_o = 1'b1;
            endcase
        end

        OPCODE_STORE: begin
            mem_wen_o = 1'b1;
            alu_src2_sel_o = 2'b01;
            imm_type_o = IMM_S;
            unique case (funct3_i)
                3'b000,  // SB
                3'b001,  // SH
                3'b010: begin  // SW
                    mem_size_o = funct3_i;
                end
                default: illegal_instr_o = 1'b1;
            endcase
        end

        OPCODE_BRANCH: begin
            imm_type_o = IMM_B;
            unique case (funct3_i)
                3'b000: next_pc_sel_o = branch_eq_i  ? 3'b001 : 3'b000;  // BEQ
                3'b001: next_pc_sel_o = !branch_eq_i ? 3'b001 : 3'b000;  // BNE
                3'b100: next_pc_sel_o = branch_lt_i  ? 3'b001 : 3'b000;  // BLT
                3'b101: next_pc_sel_o = !branch_lt_i ? 3'b001 : 3'b000;  // BGE
                3'b110: next_pc_sel_o = branch_ltu_i ? 3'b001 : 3'b000;  // BLTU
                3'b111: next_pc_sel_o = !branch_ltu_i? 3'b001 : 3'b000;  // BGEU
                default: illegal_instr_o = 1'b1;
            endcase
        end

        OPCODE_JAL: begin
            rf_wen_o = 1'b1;
            rf_wdata_sel_o = 2'b10;  // PC + 4
            next_pc_sel_o = 3'b010;  // JAL target
            imm_type_o = IMM_J;
        end

        OPCODE_JALR: begin
            rf_wen_o = 1'b1;
            rf_wdata_sel_o = 2'b10;  // PC + 4
            alu_src2_sel_o = 2'b01;  // I-imm
            next_pc_sel_o = 3'b011;  // JALR target
            imm_type_o = IMM_I;
        end

        OPCODE_LUI: begin
            rf_wen_o = 1'b1;
            alu_op_o = ALU_LUI;
            alu_src2_sel_o = 2'b10; // U-imm
            imm_type_o = IMM_U;
        end

        OPCODE_AUIPC: begin
            rf_wen_o = 1'b1;
            alu_src1_sel_o = 2'b01; // PC
            alu_src2_sel_o = 2'b10; // U-imm
            imm_type_o = IMM_U;
        end

        default: begin
            illegal_instr_o = 1'b1;
        end
    endcase
end

endmodule
