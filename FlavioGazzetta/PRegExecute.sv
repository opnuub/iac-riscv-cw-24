module PRegDecode #(
    parameter DATA_WIDTH = 32,
    parameter REG_DATA_WIDTH = 3
) (
    input   logic [DATA_WIDTH-1:0]  ALUout,
    input   logic [DATA_WIDTH-1:0]  WriteData,
    input   logic [DATA_WIDTH-1:0]  PCPlus4E,
    input   logic                   clk,
    input   logic [4:0]             RdE,
    output  logic [DATA_WIDTH-1:0]  ALUResultM,
    output  logic [DATA_WIDTH-1:0]  WriteDataM,
    output  logic [4:0]             RdM,
    output  logic [DATA_WIDTH-1:0]  PCPlus4M
);

    logic [DATA_WIDTH-1:0] rom_array [2**REG_DATA_WIDTH-1:0];
    
    initial begin
        $display("Loading rom.4");
        $readmemh("PRegExecute.mem", rom_array);
    end

    always_comb begin

        rom_array[3'b00] = ALUout;
        rom_array[3'b01] = WriteData; 
        rom_array[3'b10] = PCPlus4E;
        rom_array[3'b11] = RdE;
        
    end

   
    always_ff @(posedge clk) begin

        ALUResultM <= rom_array[3'b00];
        WriteDataM <= rom_array[3'b01];
        RdM <= rom_array[3'b10];
        PCPlus4M <= rom_array[3'b11];
        
    end

endmodule
