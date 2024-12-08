module regfile #(
    parameter DATA_WIDTH = 32,
    parameter REG_DATA_WIDTH = 5
) (
    input   logic                       clk,
    input   logic [REG_DATA_WIDTH-1:0]  rs1, // A1
    input   logic [REG_DATA_WIDTH-1:0]  rs2, // A2
    input   logic [REG_DATA_WIDTH-1:0]  rd,  // A3
    input   logic                       RegWrite, // WE3
    input   logic [DATA_WIDTH-1:0]      ResultW,  // WD3
    output  logic [DATA_WIDTH-1:0]      ALUop1,  // RD1
    output  logic [DATA_WIDTH-1:0]      regOp2,  // RD2
    output  logic [DATA_WIDTH-1:0]      a0
);

    logic [DATA_WIDTH-1:0] rom_array [2**REG_DATA_WIDTH-1:0];

    always_comb begin
        ALUop1 = rom_array[rs1]; // Read first operand
        regOp2 = rom_array[rs2]; // Read second operand
    end

    always_ff @(posedge clk) begin
        if (RegWrite && rd!=5'd0)
            rom_array[rd] <= ResultW;  // Write to register
        a0 <= ResultW;
    end

endmodule
