module pcunit_tb;

    logic clk_i;
    logic rst_ni;
    logic [2:0] next_pc_sel_i;
    logic [31:0] alu_result_i;
    logic [31:0] imm_i;

    logic [31:0] pc_o;
    logic [31:0] next_pc_o;

    pcunit uut (
        .clk_i(clk_i),
        .rst_ni(rst_ni),
        .next_pc_sel_i(next_pc_sel_i),
        .alu_result_i(alu_result_i),
        .imm_i(imm_i),
        .pc_o(pc_o),
        .next_pc_o(next_pc_o)
    );

    initial clk_i = 0;
    always #5 clk_i = ~clk_i;

    // Testbench stimulus
    initial begin
        rst_ni = 0;
        next_pc_sel_i = 3'b000;
        alu_result_i = 32'h00000000;
        imm_i = 32'h00000000;

        #10;
        rst_ni = 1;
        next_pc_sel_i = 3'b000;
        alu_result_i = 32'h00000010;
        imm_i = 32'h00000008;

        #10;
        next_pc_sel_i = 3'b001;

        #10;
        next_pc_sel_i = 3'b010;

        #10;
        next_pc_sel_i = 3'b011;

        #10;
        $finish;
    end
endmodule