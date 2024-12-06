module controller_tb;

  logic clk_i, rst_ni;
  logic [6:0] opcode_i, funct7_i;
  logic [2:0] funct3_i;
  logic branch_eq_i, branch_lt_i, branch_ltu_i;

  logic rf_wen_o;
  logic [1:0] rf_wdata_sel_o, alu_src1_sel_o, alu_src2_sel_o;
  logic [3:0] alu_op_o;
  logic mem_wen_o;
  logic [2:0] mem_size_o, imm_type_o, next_pc_sel_o;
  logic mem_signed_o;
  logic illegal_instr_o;

  controller uut (
    .clk_i          (clk_i),
    .rst_ni         (rst_ni),
    .opcode_i       (opcode_i),
    .funct3_i       (funct3_i),
    .funct7_i       (funct7_i),
    .branch_eq_i    (branch_eq_i),
    .branch_lt_i    (branch_lt_i),
    .branch_ltu_i   (branch_ltu_i),
    .rf_wen_o       (rf_wen_o),
    .rf_wdata_sel_o (rf_wdata_sel_o),
    .alu_op_o       (alu_op_o),
    .alu_src1_sel_o (alu_src1_sel_o),
    .alu_src2_sel_o (alu_src2_sel_o),
    .mem_wen_o      (mem_wen_o),
    .mem_size_o     (mem_size_o),
    .mem_signed_o   (mem_signed_o),
    .imm_type_o     (imm_type_o),
    .next_pc_sel_o  (next_pc_sel_o),
    .illegal_instr_o(illegal_instr_o)
  );

  initial clk_i = 0;
  always #5 clk_i = ~clk_i; // 10ns clock period

//tb logic
  initial begin
    $display("Starting controller_tb...");


    rst_ni = 0;
    #10;
    rst_ni = 1;

    // Test R-type instruction, opcode: 0110011
    opcode_i = 7'b0110011;
    funct3_i = 3'b000; // ADD/SUB
    funct7_i = 7'b0000000; // ADD
    #10;
    assert(rf_wen_o == 1) else $fatal("R-type rf_wen_o failed!");
    assert(alu_op_o == 4'b0000) else $fatal("R-type ALU ADD failed!");

    funct7_i = 7'b0100000; // SUB
    #10;
    assert(alu_op_o == 4'b0001) else $fatal("R-type ALU SUB failed!");

    // Test I-type instruction, opcode: 0010011
    opcode_i = 7'b0010011;
    funct3_i = 3'b100; // XORI
    #10;
    assert(rf_wen_o == 1) else $fatal("I-type rf_wen_o failed!");
    assert(alu_op_o == 4'b0101) else $fatal("I-type ALU XOR failed!");

    // Test Load instruction, opcode: 0000011
    opcode_i = 7'b0000011;
    funct3_i = 3'b010; // LW
    #10;
    assert(rf_wen_o == 1) else $fatal("Load rf_wen_o failed!");
    assert(mem_wen_o == 0) else $fatal("Load mem_wen_o failed!");
    assert(mem_size_o == 3'b010) else $fatal("Load mem_size_o failed!");

    // Test Store instruction, opcode: 0100011
    opcode_i = 7'b0100011;
    funct3_i = 3'b010; // SW
    #10;
    assert(mem_wen_o == 1) else $fatal("Store mem_wen_o failed!");
    assert(mem_size_o == 3'b010) else $fatal("Store mem_size_o failed!");

    // Test Branch instruction, opcode: 1100011
    opcode_i = 7'b1100011;
    funct3_i = 3'b000; // BEQ
    branch_eq_i = 1;
    #10;
    assert(next_pc_sel_o == 3'b001) else $fatal("Branch BEQ next_pc_sel_o failed!");

    branch_eq_i = 0;
    #10;
    assert(next_pc_sel_o == 3'b000) else $fatal("Branch BEQ next_pc_sel_o failed!");

    // Test Jump instruction, opcode: 1101111
    opcode_i = 7'b1101111;
    #10;
    assert(next_pc_sel_o == 3'b010) else $fatal("JAL next_pc_sel_o failed!");
    assert(rf_wen_o == 1) else $fatal("JAL rf_wen_o failed!");

    // Test Illegal instruction
    opcode_i = 7'b1111111;
    #10;
    assert(illegal_instr_o == 1) else $fatal("Illegal instruction detection failed!");

    $display("controller_tb passed!");
    $finish;
  end

endmodule
