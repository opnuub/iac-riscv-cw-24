module decoder (
    input  logic [31:0] instr_i,
    output logic [6:0]  opcode_o,
    output logic [2:0]  funct3_o,
    output logic [6:0]  funct7_o,
    output logic [4:0]  rd_addr_o,
    output logic [4:0]  rs1_addr_o,
    output logic [4:0]  rs2_addr_o,
    output logic [31:0] imm_o
);

assign opcode_o = instr_i[6:0];
assign rd_addr_o = instr_i[11:7];
assign funct3_o = instr_i[14:12];
assign rs1_addr_o = instr_i[19:15];
assign rs2_addr_o = instr_i[24:20];
assign funct7_o = instr_i[31:25];

// Intermediate debug signals
logic [31:0] imm_debug;
logic signed [31:0] imm_sign_extended;

// Sign extend immediate value
always_comb begin
    unique case (opcode_o)
        // I-Type
        7'b0010011: imm_o = {{20{instr_i[31]}}, instr_i[31:20]}; 
        7'b0000011: imm_o = {{20{instr_i[31]}}, instr_i[31:20]}; 
        7'b1100111: imm_o = {{20{instr_i[31]}}, instr_i[31:20]}; 

        // S-Type
        7'b0100011: imm_o = {{20{instr_i[31]}}, instr_i[31:25], instr_i[11:7]}; // STORE

        // B-Type
        7'b1100011: imm_o = {{19{instr_i[31]}}, instr_i[31], instr_i[7], instr_i[30:25], instr_i[11:8], 1'b0}; // BRANCH

        // U-Type
        7'b0110111: imm_o = {instr_i[31:12], 12'b0}; // LUI
        7'b0010111: imm_o = {instr_i[31:12], 12'b0}; // AUIPC

        // J-Type
        7'b1101111: imm_o = {{11{instr_i[31]}}, instr_i[31], instr_i[19:12], instr_i[20], instr_i[30:21], 1'b0}; // JAL

        default: imm_o = 0;
    endcase
end

// Debug  code
assign imm_debug = imm_o;
assign imm_sign_extended = imm_o;

always_comb begin
    $display("instr_i: %b", instr_i);
    $display("opcode_o: %b", opcode_o);
    $display("rd_addr_o: %b, rs1_addr_o: %b, rs2_addr_o: %b", rd_addr_o, rs1_addr_o, rs2_addr_o);
    $display("funct3_o: %b, funct7_o: %b", funct3_o, funct7_o);
    $display("imm_debug: %b, imm_sign_extended: %d", imm_debug, imm_sign_extended);
end

endmodule