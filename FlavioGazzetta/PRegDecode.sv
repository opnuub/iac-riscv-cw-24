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
    output  logic [DATA_WIDTH-1:0]  RdE,
    output  logic [DATA_WIDTH-1:0]  ImmExtE,
    output  logic [DATA_WIDTH-1:0]  PcPlus4E
);

    logic [DATA_WIDTH-1:0] rom_array [2**REG_DATA_WIDTH-1:0];
    
    initial begin
        $display("Loading rom.2");
        $readmemh("PRegFetch.mem", rom_array);
    end

    always_comb begin

        rom_array[3'b00] = Rd; 
        rom_array[3'b01] = PCf;
        rom_array[3'b10] = PCPlus4F;
        
    end

   
    always_ff @(posedge clk) begin

        InstrD <= rom_array[3'b00];
        PCd <= rom_array[3'b01];
        PCPlus4D <= rom_array[3'b10]; 
        
    end

endmodule
