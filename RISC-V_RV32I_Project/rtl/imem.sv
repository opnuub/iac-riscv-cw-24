module imem #(
    parameter ADDR_WIDTH = 32,
    parameter DATA_WIDTH = 8,
    parameter INSTR_WIDTH = 32,
    parameter MEM_SIZE = 4096  // 4KB
) (
    input  logic                    clk_i,
    input  logic [ADDR_WIDTH-1:0]   addr_i,
    output logic [INSTR_WIDTH-1:0]  rdata_o
);

// Memory array - byte addressable
logic [DATA_WIDTH-1:0] mem [MEM_SIZE-1:0];


initial begin
    $display("Loading program into instruction memory...");
    $readmemh("/Users/michaelli/Documents/GitHub/iac-riscv-cw-24/RISC-V_RV32I_Project/rtl/program.hex", mem);
end

// Combine 4 bytes to form instruction

// at the end, the lowest addressed byte is  the least significant
always_ff @(posedge clk_i) begin
    rdata_o <= {mem[{addr_i[11:2], 2'b11}],  // MSB (addr + 3)
                mem[{addr_i[11:2], 2'b10}],  
                mem[{addr_i[11:2], 2'b01}],
                mem[{addr_i[11:2], 2'b00}]}; // LSB  (addr)
end

endmodule