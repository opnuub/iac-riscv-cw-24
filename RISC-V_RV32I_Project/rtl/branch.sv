module branch (
    input  logic [31:0] rs1_data_i,
    input  logic [31:0] rs2_data_i,
    input  logic [2:0]  funct3_i,
    
    output logic branch_taken_o,
    output logic branch_eq_o,
    output logic branch_lt_o,
    output logic branch_ltu_o
);

// Compare the results of registers
logic equal, less_than, less_than_u;

assign equal = (rs1_data_i == rs2_data_i);
assign less_than = ($signed(rs1_data_i) < $signed(rs2_data_i));
assign less_than_u = (rs1_data_i < rs2_data_i);

// Output
assign branch_eq_o = equal;
assign branch_lt_o = less_than;
assign branch_ltu_o = less_than_u;

// Branch decide
always_comb begin
    branch_taken_o = 1'b0;
    
    case (funct3_i)
        3'b000: branch_taken_o = equal;          // BEQ
        3'b001: branch_taken_o = !equal;         // BNE
        3'b100: branch_taken_o = less_than;      // BLT
        3'b101: branch_taken_o = !less_than;     // BGE
        3'b110: branch_taken_o = less_than_u;    // BLTU
        3'b111: branch_taken_o = !less_than_u;   // BGEU
        default: branch_taken_o = 1'b0;
    endcase
end

endmodule
