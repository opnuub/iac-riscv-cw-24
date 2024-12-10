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
    output  logic [DATA_WIDTH-1:0]  PCPlus4M,
    input   logic                   RegWriteE,
    input   logic [1:0]             ResultSrcE,
    input   logic                   MemWriteE,
    output  logic                   RegWriteM,
    output  logic [1:0]             ResultSrcM,
    output  logic                   MemWriteM
);

    logic [DATA_WIDTH-1:0] rom_array [2**REG_DATA_WIDTH-1:0];
    
    initial begin
        $display("Loading rom.4");
        $readmemh("PRegExecute.mem", rom_array);
    end

    always_comb begin
        rom_array[3'b000] = ALUout;
        rom_array[3'b001] = WriteData;
        rom_array[3'b010] = PCPlus4E;
        rom_array[3'b011] = {{(DATA_WIDTH-5){1'b0}}, RdE}; 
        rom_array[3'b100] = {{(DATA_WIDTH-1){1'b0}}, RegWriteE}; 
        rom_array[3'b101] = {{(DATA_WIDTH-2){1'b0}}, ResultSrcE};
        rom_array[3'b110] = {{(DATA_WIDTH-1){1'b0}}, MemWriteE}; 
    end

   
    always_ff @(posedge clk) begin
        ALUResultM <= rom_array[3'b000];
        WriteDataM <= rom_array[3'b001];
        PCPlus4M   <= rom_array[3'b010];
        RdM        <= rom_array[3'b011][4:0];  
        RegWriteM  <= rom_array[3'b100][0];    
        ResultSrcM <= rom_array[3'b101][1:0];  
        MemWriteM  <= rom_array[3'b110][0];   
    end

endmodule
