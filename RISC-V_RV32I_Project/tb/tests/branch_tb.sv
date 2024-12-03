module branch_tb;

  // Inputs
  logic [31:0] rs1_data_i, rs2_data_i;
  logic [2:0]  funct3_i;

  // Outputs
  logic branch_taken_o, branch_eq_o, branch_lt_o, branch_ltu_o;

  // Instantiate DUT (Device Under Test)
  branch uut (
    .rs1_data_i     (rs1_data_i),
    .rs2_data_i     (rs2_data_i),
    .funct3_i       (funct3_i),
    .branch_taken_o (branch_taken_o),
    .branch_eq_o    (branch_eq_o),
    .branch_lt_o    (branch_lt_o),
    .branch_ltu_o   (branch_ltu_o)
  );

  // Testbench logic
  initial begin
    $display("Starting branch_tb...");

    // Test case 1: BEQ (Branch if Equal)
    rs1_data_i = 32'd10;
    rs2_data_i = 32'd10;
    funct3_i = 3'b000; // BEQ
    #10;
    assert(branch_eq_o == 1'b1) else $fatal("BEQ failed (equal case)");
    assert(branch_taken_o == 1'b1) else $fatal("BEQ failed (branch_taken case)");

    rs1_data_i = 32'd10;
    rs2_data_i = 32'd5;
    #10;
    assert(branch_eq_o == 1'b0) else $fatal("BEQ failed (not equal case)");
    assert(branch_taken_o == 1'b0) else $fatal("BEQ failed (branch_taken case)");

    // Test case 2: BNE (Branch if Not Equal)
    funct3_i = 3'b001; // BNE
    rs1_data_i = 32'd10;
    rs2_data_i = 32'd5;
    #10;
    assert(branch_taken_o == 1'b1) else $fatal("BNE failed (not equal case)");

    rs1_data_i = 32'd10;
    rs2_data_i = 32'd10;
    #10;
    assert(branch_taken_o == 1'b0) else $fatal("BNE failed (equal case)");

    // Test case 3: BLT (Branch if Less Than, signed)
    funct3_i = 3'b100; // BLT
    rs1_data_i = -32'd5;
    rs2_data_i = 32'd10;
    #10;
    assert(branch_lt_o == 1'b1) else $fatal("BLT failed (less than case)");
    assert(branch_taken_o == 1'b1) else $fatal("BLT failed (branch_taken case)");

    rs1_data_i = 32'd10;
    rs2_data_i = -32'd5;
    #10;
    assert(branch_lt_o == 1'b0) else $fatal("BLT failed (greater than case)");
    assert(branch_taken_o == 1'b0) else $fatal("BLT failed (branch_taken case)");

    // Test case 4: BGE (Branch if Greater or Equal, signed)
    funct3_i = 3'b101; // BGE
    rs1_data_i = 32'd10;
    rs2_data_i = -32'd5;
    #10;
    assert(branch_taken_o == 1'b1) else $fatal("BGE failed (greater than case)");

    rs1_data_i = -32'd5;
    rs2_data_i = -32'd5;
    #10;
    assert(branch_taken_o == 1'b1) else $fatal("BGE failed (equal case)");

    rs1_data_i = -32'd10;
    rs2_data_i = 32'd5;
    #10;
    assert(branch_taken_o == 1'b0) else $fatal("BGE failed (less than case)");

    // Test case 5: BLTU (Branch if Less Than, unsigned)
    funct3_i = 3'b110; // BLTU
    rs1_data_i = 32'h0000000F;
    rs2_data_i = 32'h00000010;
    #10;
    assert(branch_ltu_o == 1'b1) else $fatal("BLTU failed (less than case)");
    assert(branch_taken_o == 1'b1) else $fatal("BLTU failed (branch_taken case)");

    rs1_data_i = 32'h00000010;
    rs2_data_i = 32'h0000000F;
    #10;
    assert(branch_ltu_o == 1'b0) else $fatal("BLTU failed (greater than case)");
    assert(branch_taken_o == 1'b0) else $fatal("BLTU failed (branch_taken case)");

    // Test case 6: BGEU (Branch if Greater or Equal, unsigned)
    funct3_i = 3'b111; // BGEU
    rs1_data_i = 32'h00000010;
    rs2_data_i = 32'h0000000F;
    #10;
    assert(branch_taken_o == 1'b1) else $fatal("BGEU failed (greater than case)");

    rs1_data_i = 32'h0000000F;
    rs2_data_i = 32'h0000000F;
    #10;
    assert(branch_taken_o == 1'b1) else $fatal("BGEU failed (equal case)");

    rs1_data_i = 32'h0000000F;
    rs2_data_i = 32'h00000010;
    #10;
    assert(branch_taken_o == 1'b0) else $fatal("BGEU failed (less than case)");

    $display("branch_tb passed all tests!");
    $finish;
  end

endmodule
