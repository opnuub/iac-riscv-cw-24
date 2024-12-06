module pcunit (
    input  logic        clk_i,
    input  logic        rst_ni,
    
    input  logic [2:0]  next_pc_sel_i,
    input  logic [31:0] alu_result_i,  // For JALR
    input  logic [31:0] imm_i,         // For Branch/JAL
    
    output logic [31:0] pc_o,
    output logic [31:0] next_pc_o
);

logic [31:0] pc_q;

// PC update logic
always_comb begin
    next_pc_o = pc_q + 32'd4;

    case (next_pc_sel_i)
        3'b000:  next_pc_o = pc_q + 32'd4;                  // Sequential
        3'b001:  next_pc_o = pc_q + imm_i;                  // Branch
        3'b010:  next_pc_o = pc_q + imm_i;                  // JAL
        3'b011:  next_pc_o = (alu_result_i & ~32'b1);      // JALR
        default: next_pc_o = pc_q + 32'd4;
    endcase
end

// PC register
always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
        pc_q <= 32'h00000000;
    end else begin
        pc_q <= next_pc_o;
    end
end

assign pc_o = pc_q;

endmodule
