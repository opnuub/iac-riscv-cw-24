module instrMemory #(
    parameter ADDR_WIDTH = 32,
    parameter INSTR_WIDTH = 32
)(
    input  logic [ADDR_WIDTH-1:0] pc,
    output logic [INSTR_WIDTH-1:0] instr
);

    logic [7:0] rom [2**12-1:0]; // 0xBFC00000 - 0xBFC00FFF

    always_comb begin
        instr = {rom[pc[11:0] + 3], rom[pc[11:0] + 2], rom[pc[11:0] + 1], rom[pc[11:0]]};
    end

    initial begin
        $readmemh("../rtl/program.hex", rom); // 17'h10000
    end

endmodule
