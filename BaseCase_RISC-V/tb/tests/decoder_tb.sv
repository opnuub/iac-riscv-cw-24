module decoder_tb;

    // Signals
    logic [31:0] instr_i;
    logic [6:0] opcode_o;
    logic [2:0] funct3_o;
    logic [6:0] funct7_o;
    logic [4:0] rd_addr_o, rs1_addr_o, rs2_addr_o;
    logic [31:0] imm_o;

    // Instantiate the DUT
    decoder dut (
        .instr_i(instr_i),
        .opcode_o(opcode_o),
        .funct3_o(funct3_o),
        .funct7_o(funct7_o),
        .rd_addr_o(rd_addr_o),
        .rs1_addr_o(rs1_addr_o),
        .rs2_addr_o(rs2_addr_o),
        .imm_o(imm_o)
    );

    // Task for sign-extension
    function [31:0] sign_extend(input [31:0] value, input integer bits);
        return { { (32-bits) {value[bits-1]} }, value[bits-1:0] };
    endfunction

    // Testbench procedure
    initial begin
        $display("Running decoder_tb tests...");

        // Test R-type instruction
        instr_i = 32'h00C585B3; // Example R-type
        #1;
        assert(opcode_o == 7'b0110011) else $error("R-type opcode failed");
        assert(funct3_o == 3'b100) else $error("R-type funct3 failed");
        assert(funct7_o == 7'b0000000) else $error("R-type funct7 failed");
        assert(rd_addr_o == 11) else $error("R-type rd failed");
        assert(rs1_addr_o == 11) else $error("R-type rs1 failed");
        assert(rs2_addr_o == 12) else $error("R-type rs2 failed");

        // Test I-type instruction
        instr_i = 32'hFFF00793; // Example I-type
        #1;
        assert(opcode_o == 7'b0010011) else $error("I-type opcode failed");
        assert(imm_o == sign_extend(12'hFFF, 12)) else $error("I-type immediate failed");

        // Test S-type instruction
        instr_i = 32'h00F707A3; // Example S-type
        #1;
        assert(opcode_o == 7'b0100011) else $error("S-type opcode failed");
        assert(imm_o == sign_extend(12'hF0F, 12)) else $error("S-type immediate failed");

        // Test B-type instruction
        instr_i = 32'h00006063; // Example B-type
        #1;
        assert(opcode_o == 7'b1100011) else $error("B-type opcode failed");
        assert(imm_o == sign_extend(13'h006, 13)) else $error("B-type immediate failed");

        // Test J-type instruction
        instr_i = 32'h00C0006F; // Example JAL
        #1;
        assert(opcode_o == 7'b1101111) else $error("J-type opcode failed");
        assert(imm_o == sign_extend(21'hC0, 21)) else $error("J-type immediate failed");

        $display("All tests passed!");
        $finish;
    end
endmodule