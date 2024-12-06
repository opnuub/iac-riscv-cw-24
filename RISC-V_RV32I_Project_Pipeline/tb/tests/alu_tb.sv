module alu_tb;
  import "DPI-C" function void gtest_check(input logic success);

  // Parameters
  logic [31:0] operand_a_i, operand_b_i, result_o;
  logic [3:0] operator_i;

  alu uut (
    .operand_a_i(operand_a_i),
    .operand_b_i(operand_b_i),
    .operator_i(operator_i),
    .result_o(result_o)
  );

  initial begin
    operand_a_i = 32'd10; operand_b_i = 32'd5; operator_i = 4'b0000; // ADD
    #10 assert(result_o == 32'd15) else $error("ADD failed");
    operator_i = 4'b0001; // SUB
    #10 assert(result_o == 32'd5) else $error("SUB failed");
    operator_i = 4'b1000; // OR
    #10 assert(result_o == (32'd10 | 32'd5)) else $error("OR failed");
    $finish;
  end
endmodule