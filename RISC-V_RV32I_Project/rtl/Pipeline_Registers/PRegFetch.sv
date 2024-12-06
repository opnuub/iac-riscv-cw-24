module PRegFetch #(
    parameter DATA_WIDTH = 32,
    parameter REG_DATA_WIDTH = 3
) (
    input   logic [DATA_WIDTH-1:0]  instr,
    input   logic [DATA_WIDTH-1:0]  PCf,
    input   logic [DATA_WIDTH-1:0]  PCPlus4F,
    input   logic                   clk,
    output  logic [DATA_WIDTH-1:0]  PCPlus4D,
    output  logic [DATA_WIDTH-1:0]  PCd,
    output  logic [DATA_WIDTH-1:0]  InstrD
);

    logic [DATA_WIDTH-1:0] rom_array [2**REG_DATA_WIDTH-1:0];

    always_comb begin

        InstrD = rom_array[3'b00];
        PCd = rom_array[3'b01];
        PCPlus4D = rom_array[3'b10]; 
        
    end

   
    always_ff @(posedge clk) begin

        rom_array[3'b00] <= instr; 
        rom_array[3'b01] <= PCf;
        rom_array[3'b10] <= PCPlus4F;
        
    end

    

endmodule


