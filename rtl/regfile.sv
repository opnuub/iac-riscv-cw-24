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
    output  logic [DATA_WIDTH-1:0]      a0,


    //for testing
    output  logic [DATA_WIDTH-1:0]      a1,
    output  logic [DATA_WIDTH-1:0]      a2,
    output  logic [DATA_WIDTH-1:0]      a3,
    output  logic [DATA_WIDTH-1:0]      a4,
    output  logic [DATA_WIDTH-1:0]      a5,
    output  logic [DATA_WIDTH-1:0]      a6,
    output  logic [DATA_WIDTH-1:0]      s1,
    output  logic [DATA_WIDTH-1:0]      t1,
    output  logic [DATA_WIDTH-1:0]      t0,
    output  logic [DATA_WIDTH-1:0]      rega5,
    output  logic [DATA_WIDTH-1:0]      rega6
);

//     always_ff @ (posedge clk)
//  begin 

//     $display("a0: %d", rom_array[10]);
//     $display("a1: %d", rom_array[11]);
//     $display("a2: %d", rom_array[12]);
//     $display("a3: %d", rom_array[13]);
//     $display("a4: %d", rom_array[14]);    
//     $display("a5: %d", rom_array[15]);
//     $display("a6: %d", rom_array[16]);
//     $display("s1: %d", rom_array[9]);
//     $display("t1: %d", rom_array[6]);
//  end
    logic [DATA_WIDTH-1:0] rom_array [2**REG_DATA_WIDTH-1:0];

    assign a0 = rom_array[10];

    //for testing:
    assign a1 = rom_array[11];
    assign a2 = rom_array[12];
    assign a3 = rom_array[13];
    assign a4 = rom_array[14];
    assign a5 = rom_array[15];
    assign a6 = rom_array[16];
    assign t1 = rom_array[6];
    assign t0 = rom_array[5];

    
    assign s1 =    rom_array[9];
    assign rega5 = rom_array[a5];
    assign rega6 = rom_array[a6];

    always_comb begin
        ALUop1 = rom_array[rs1]; // Read first operand
        regOp2 = rom_array[rs2]; // Read second operand
    end

    always_ff @(negedge clk) begin //negedge
        if (RegWrite && rd!=5'd0)
            rom_array[rd] <= ResultW;  // Write to register
    end

endmodule
