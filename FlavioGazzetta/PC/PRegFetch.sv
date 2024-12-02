module PRegFetch #(
    parameter DATA_WIDTH = 32,
    parameter REG_DATA_WIDTH = 3
) (
    input   logic [DATA_WIDTH-1:0]  Rd,
    input   logic [DATA_WIDTH-1:0]  PCf,
    input   logic [DATA_WIDTH-1:0]  PCPlus4F,
    input   logic                   clk,
    output  logic [DATA_WIDTH-1:0]  PCPlus4D,
    output  logic [DATA_WIDTH-1:0]  PCd,
    output  logic [DATA_WIDTH-1:0]  InstrD
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
