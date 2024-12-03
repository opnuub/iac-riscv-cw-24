module PRegDecode #(
    parameter DATA_WIDTH = 32,
    parameter REG_DATA_WIDTH = 3
) (
    input   logic [DATA_WIDTH-1:0]  rd1,
    input   logic [DATA_WIDTH-1:0]  rd2,
    input   logic [DATA_WIDTH-1:0]  PCd,
    input   logic [DATA_WIDTH-1:0]  ImmExtD,
    input   logic                   clk,
    input   logic [4:0]             RdD,
    output  logic [DATA_WIDTH-1:0]  rd1E,
    output  logic [DATA_WIDTH-1:0]  rd2E,
    output  logic [DATA_WIDTH-1:0]  PCe,
    output  logic [4:0]             RdE,
    output  logic [DATA_WIDTH-1:0]  ImmExtE,
    output  logic [DATA_WIDTH-1:0]  PcPlus4E
);

    logic [DATA_WIDTH-1:0] rom_array [2**REG_DATA_WIDTH-1:0];
    
    initial begin
        $display("Loading rom.3");
        $readmemh("PRegDecode.mem", rom_array);
    end

    always_comb begin

        rom_array[3'b00] = rd1;
        rom_array[3'b01] = rd2; 
        rom_array[3'b10] = PCd;
        rom_array[3'b11] = RdD;
        rom_array[3'b100] = ImmExtD;
        rom_array[3'b101] = PcPlus4D;
        
    end

   
    always_ff @(posedge clk) begin

        rd1E <= rom_array[3'b00];
        rd2E <= rom_array[3'b01];
        PCe <= rom_array[3'b10];
        Rde <= rom_array[3'b11];
        ImmExtE <= rom_array[3'b100];
        PCPlus4E <= rom_array[3'b101];
        
    end

endmodule
