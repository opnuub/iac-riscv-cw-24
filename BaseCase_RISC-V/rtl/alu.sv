module alu (
    input  logic [31:0] operand_a_i,
    input  logic [31:0] operand_b_i,
    input  logic [3:0]  operator_i,
    
    output logic [31:0] result_o
);

// ALU Operations
localparam ALU_ADD  = 4'b0000;
localparam ALU_SUB  = 4'b0001;
localparam ALU_SLL  = 4'b0010;
localparam ALU_SLT  = 4'b0011;
localparam ALU_SLTU = 4'b0100;
localparam ALU_XOR  = 4'b0101;
localparam ALU_SRL  = 4'b0110;
localparam ALU_SRA  = 4'b0111;
localparam ALU_OR   = 4'b1000;
localparam ALU_AND  = 4'b1001;
localparam ALU_LUI  = 4'b1010;

// Intermediate results
logic [31:0] add_sub_result;
logic [31:0] slt_result;
logic [31:0] sltu_result;
logic [31:0] shift_left_result;
logic [31:0] shift_right_result;
logic [31:0] shift_right_arith_result;

// Add or subtract operation
assign add_sub_result = (operator_i == ALU_SUB) ? 
                       operand_a_i - operand_b_i : 
                       operand_a_i + operand_b_i;

// Set less than operation
assign slt_result  = {31'b0, $signed(operand_a_i) < $signed(operand_b_i)};
assign sltu_result = {31'b0, operand_a_i < operand_b_i};

// Shift operation
assign shift_left_result = operand_a_i << operand_b_i[4:0];
assign shift_right_result = operand_a_i >> operand_b_i[4:0];
assign shift_right_arith_result = $signed(operand_a_i) >>> operand_b_i[4:0];

//  ALU mux
always_comb begin
    unique case (operator_i)
        ALU_ADD:  result_o = add_sub_result;
        ALU_SUB:  result_o = add_sub_result;
        ALU_SLT:  result_o = slt_result;
        ALU_SLTU: result_o = sltu_result;
        ALU_XOR:  result_o = operand_a_i ^ operand_b_i;
        ALU_OR:   result_o = operand_a_i | operand_b_i;
        ALU_AND:  result_o = operand_a_i & operand_b_i;
        ALU_SLL:  result_o = shift_left_result;
        ALU_SRL:  result_o = shift_right_result;
        ALU_SRA:  result_o = shift_right_arith_result;
        ALU_LUI:  result_o = operand_b_i;
        default:  result_o = '0;
    endcase
end

endmodule
