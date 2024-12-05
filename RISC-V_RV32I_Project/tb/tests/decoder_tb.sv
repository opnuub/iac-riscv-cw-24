module decoder_tb;

    logic [31:0] instr_i;
    logic [6:0]  opcode_o;
    logic [2:0]  funct3_o;
    logic [6:0]  funct7_o;
    logic [4:0]  rd_addr_o, rs1_addr_o, rs2_addr_o;
    logic [31:0] imm_o;

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

    // Test procedure
    initial begin
        $dumpfile("decoder_tb.vcd");
        $dumpvars(0, decoder_tb);

        // Test I-Type
        instr_i = 32'h00408093; // ADDI x1, x1, 4
        #10;
        assert(opcode_o == 7'b0010011);
        assert(rd_addr_o == 5'b00001);
        assert(rs1_addr_o == 5'b00001);
        assert(imm_o == 32'h00000004);

        // Test S-Type
        instr_i = 32'h00212023; // SW x2, 4(x0)
        #10;
        assert(opcode_o == 7'b0100011);
        assert(rs1_addr_o == 5'b00000);
        assert(rs2_addr_o == 5'b00010);
        assert(imm_o == 32'h00000004);

        // Test B-Type
        instr_i = 32'h0000E063; // BEQ x0, x0, 8
        #10;
        assert(opcode_o == 7'b1100011);
        assert(rs1_addr_o == 5'b00000);
        assert(rs2_addr_o == 5'b00000);
        assert(imm_o == 32'h00000008);

        // Test U-Type
        instr_i = 32'h00001037; // LUI x2, 0x1
        #10;
        assert(opcode_o == 7'b0110111);
        assert(rd_addr_o == 5'b00010);
        assert(imm_o == 32'h00001000);

        // Test J-Type
        instr_i = 32'h0000006F; // JAL x0, 0
        #10;
        assert(opcode_o == 7'b1101111);
        assert(rd_addr_o == 5'b00000);
        assert(imm_o == 32'h00000000);

        $finish;
    end
endmodule