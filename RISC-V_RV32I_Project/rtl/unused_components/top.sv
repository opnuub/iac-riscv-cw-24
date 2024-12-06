module top (
    input  logic        clk_i,
    input  logic        rst_ni,
    input  logic        trigger_i,
    output logic [31:0] a0_o
);

logic [31:0] pc, next_pc, instr;
logic [31:0] rs1_data, rs2_data, alu_result, mem_rdata;
logic branch_taken, branch_eq, branch_lt, branch_ltu;

// Control signals
logic [6:0] opcode;
logic [2:0] funct3;
logic [6:0] funct7;
logic [4:0] rs1_addr, rs2_addr, rd_addr;
logic [31:0] imm;
logic rf_wen;
logic [1:0] rf_wdata_sel;
logic [3:0] alu_op;
logic [1:0] alu_src1_sel, alu_src2_sel;
logic mem_wen;
logic [2:0] mem_size;
logic mem_signed;
logic [2:0] next_pc_sel;
logic [2:0] imm_type;

imem imem (
    .clk_i   ( clk_i   ),
    .addr_i  ( pc      ),
    .rdata_o ( instr   )
);

decoder decoder (
    .instr_i    ( instr     ),
    .opcode_o   ( opcode    ),
    .funct3_o   ( funct3    ),
    .funct7_o   ( funct7    ),
    .rd_addr_o  ( rd_addr   ),
    .rs1_addr_o ( rs1_addr  ),
    .rs2_addr_o ( rs2_addr  ),
    .imm_o      ( imm       )
);

controller controller (
    .clk_i          ( clk_i         ),
    .rst_ni         ( rst_ni        ),
    .opcode_i       ( opcode        ),
    .funct3_i       ( funct3        ),
    .funct7_i       ( funct7        ),
    .branch_eq_i    ( branch_eq     ),
    .branch_lt_i    ( branch_lt     ),
    .branch_ltu_i   ( branch_ltu    ),
    .rf_wen_o       ( rf_wen        ),
    .rf_wdata_sel_o ( rf_wdata_sel  ),
    .alu_op_o       ( alu_op        ),
    .alu_src1_sel_o ( alu_src1_sel  ),
    .alu_src2_sel_o ( alu_src2_sel  ),
    .mem_wen_o      ( mem_wen       ),
    .mem_size_o     ( mem_size      ),
    .mem_signed_o   ( mem_signed    ),
    .imm_type_o     ( imm_type      ),
    .next_pc_sel_o  ( next_pc_sel   )
);

// Instantiate register file
regfile regfile (
    .clk_i     ( clk_i     ),
    .rst_ni    ( rst_ni    ),
    .wen_i     ( rf_wen    ),
    .waddr_i   ( rd_addr   ),
    .wdata_i   ( rf_wdata  ),
    .raddr1_i  ( rs1_addr  ),
    .rdata1_o  ( rs1_data  ),
    .raddr2_i  ( rs2_addr  ),
    .rdata2_o  ( rs2_data  ),
    .a0_o      ( a0_o      ) // output
);

// Instantiate ALU
alu alu (
    .operand_a_i ( alu_src1 ),
    .operand_b_i ( alu_src2 ),
    .operator_i  ( alu_op   ),
    .result_o    ( alu_result )
);

// Instantiate data memory
dmem dmem (
    .clk_i     ( clk_i      ),
    .rst_ni    ( rst_ni     ),
    .wen_i     ( mem_wen    ),
    .size_i    ( mem_size   ),
    .signed_i  ( mem_signed ),
    .addr_i    ( alu_result ),
    .wdata_i   ( rs2_data   ),
    .rdata_o   ( mem_rdata  )
);

branch branch (
    .rs1_data_i     ( rs1_data     ),
    .rs2_data_i     ( rs2_data     ),
    .funct3_i       ( funct3       ),
    .branch_taken_o ( branch_taken ),
    .branch_eq_o    ( branch_eq    ),
    .branch_lt_o    ( branch_lt    ),
    .branch_ltu_o   ( branch_ltu   )
);

// Instantiate PC unit
pcunit pcunit (
    .clk_i         ( clk_i      ),
    .rst_ni        ( rst_ni     ),
    .next_pc_sel_i ( next_pc_sel),
    .alu_result_i  ( alu_result ),
    .imm_i         ( imm        ),
    .pc_o          ( pc         ),
    .next_pc_o     ( next_pc    )
);

// ALU input multiplexing
logic [31:0] alu_src1, alu_src2;

always_comb begin
    // ALU source 1 select
    case (alu_src1_sel)
        2'b00: alu_src1 = rs1_data;
        2'b01: alu_src1 = pc;
        default: alu_src1 = rs1_data;
    endcase

    // ALU source 2 select
    case (alu_src2_sel)
        2'b00: alu_src2 = rs2_data;
        2'b01: alu_src2 = imm;
        2'b10: alu_src2 = imm;
        default: alu_src2 = rs2_data;
    endcase
end

// Register write data multiplexing
logic [31:0] rf_wdata;

always_comb begin
    case (rf_wdata_sel)
        2'b00: rf_wdata = alu_result;
        2'b01: rf_wdata = mem_rdata;
        2'b10: rf_wdata = pc + 4;
        default: rf_wdata = alu_result;
    endcase
end

endmodule
