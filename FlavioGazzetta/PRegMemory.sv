module PRegDecode #(
    parameter DATA_WIDTH = 32,
    parameter REG_DATA_WIDTH = 3
) (
    input   logic [DATA_WIDTH-1:0]  ALUResultM,
    input   logic [DATA_WIDTH-1:0]  DMRd,
    input   logic [4:0]             RdM,
    input   logic [DATA_WIDTH-1:0]  PCPlus4M,
    input   logic                   clk,
    output  logic [4:0]             RdW,
    output  logic [DATA_WIDTH-1:0]  ALUResultW,
    output  logic [DATA_WIDTH-1:0]  WriteDataW,
    output  logic [DATA_WIDTH-1:0]  PCPlus4W,
    input   logic                   RegWriteM,
    input   logic [1:0]             ResultSrcM,
    output  logic                   RegWriteW,
    output  logic [1:0]             ResultSrcW
);

    logic [DATA_WIDTH-1:0] rom_array [2**REG_DATA_WIDTH-1:0];
    
    initial begin
        $display("Loading rom.5");
        $readmemh("PRegMemory.mem", rom_array);
    end

    always_comb begin
        rom_array[3'b000] = ALUResultM;
        rom_array[3'b001] = DMRd;
        rom_array[3'b010] = {{(DATA_WIDTH-5){1'b0}}, RdM};
        rom_array[3'b011] = PCPlus4M;
        rom_array[3'b100] = {{(DATA_WIDTH-1){1'b0}}, RegWriteM};
        rom_array[3'b101] = {{(DATA_WIDTH-2){1'b0}}, ResultSrcM};
    end

   
    always_ff @(posedge clk) begin
        ALUResultW <= rom_array[3'b000];
        WriteDataW <= rom_array[3'b001];
        RdW        <= rom_array[3'b010][4:0];    
        PCPlus4W   <= rom_array[3'b011];
        RegWriteW  <= rom_array[3'b100][0];      
        ResultSrcW <= rom_array[3'b101][1:0];    
    end

endmodule
