module PRegDecode #(
    parameter DATA_WIDTH = 32,
    parameter REG_DATA_WIDTH = 3
) (
    input   logic [DATA_WIDTH-1:0]  ALUResultM,
    input   logic [DATA_WIDTH-1:0]  DMRd,
    input   logic [4:0]             RdM,
    input   logic [DATA_WIDTH-1:0]  PCPlus4M,
    input   logic                   clk,
    input   logic [4:0]             RdW,
    output  logic [DATA_WIDTH-1:0]  ALUResultW,
    output  logic [DATA_WIDTH-1:0]  WriteDataW,
    output  logic [DATA_WIDTH-1:0]  RdW,
    output  logic [DATA_WIDTH-1:0]  PCPlus4W
);

    logic [DATA_WIDTH-1:0] rom_array [2**REG_DATA_WIDTH-1:0];
    
    initial begin
        $display("Loading rom.2");
        $readmemh("PRegMemory.mem", rom_array);
    end

    always_comb begin

        rom_array[3'b00] = ALUResultM;
        rom_array[3'b01] = DMRd; 
        rom_array[3'b10] = RdM;
        rom_array[3'b11] = PCPlus4M;
        
    end

   
    always_ff @(posedge clk) begin

        ALUResultM <= rom_array[3'b00];
        WriteDataM <= rom_array[3'b01];
        RdM <= rom_array[3'b10];
        PCPlus4M <= rom_array[3'b11];
        
    end

endmodule
