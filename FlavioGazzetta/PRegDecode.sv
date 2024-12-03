module PRegDecode #(
    parameter DATA_WIDTH = 32,
    parameter REG_DATA_WIDTH = 4
) (
    input   logic [DATA_WIDTH-1:0]  rd1,
    input   logic [DATA_WIDTH-1:0]  rd2,
    input   logic [DATA_WIDTH-1:0]  PCd,
    input   logic [DATA_WIDTH-1:0]  ImmExtD,
    input   logic                   clk,
    input   logic [4:0]             RdD,
    input   logic [DATA_WIDTH-1:0]  PCPlus4D,
    output  logic [DATA_WIDTH-1:0]  rd1E,
    output  logic [DATA_WIDTH-1:0]  rd2E,
    output  logic [DATA_WIDTH-1:0]  PCe,
    output  logic [4:0]             RdE,
    output  logic [DATA_WIDTH-1:0]  ImmExtE,
    output  logic [DATA_WIDTH-1:0]  PcPlus4E,
    input   logic                   RegWriteD,
    input   logic [1:0]             ResultSrcD,
    input   logic                   MemWriteD,
    input   logic                   JumpD,
    input   logic                   BranchD,
    input   logic [2:0]             ALUControl,
    input   logic                   ALUSrcD,
    output  logic                   RegWriteE,
    output  logic [1:0]             ResultSrcE,
    output  logic                   MemWriteE,
    output  logic                   JumpE,
    output  logic                   BranchE,
    output  logic [2:0]             ALUControlE,
    output  logic                   ALUSrcE
    

);

    logic [DATA_WIDTH-1:0] rom_array [2**REG_DATA_WIDTH-1:0];
    
    initial begin
        $display("Loading rom.3");
        $readmemh("PRegDecode.mem", rom_array);
    end

    always_comb begin
        rom_array[4'b0000] = rd1;
        rom_array[4'b0001] = rd2; 
        rom_array[4'b0010] = PCd;
        rom_array[4'b0011] = {27'b0, RdD};      
        rom_array[4'b0100] = ImmExtD;
        rom_array[4'b0101] = PcPlus4D;
        rom_array[4'b0110] = {31'b0, RegWriteD}; 
        rom_array[4'b0111] = {30'b0, ResultSrcD};
        rom_array[4'b1000] = {31'b0, MemWriteD};
        rom_array[4'b1001] = {31'b0, JumpD};
        rom_array[4'b1010] = {31'b0, BranchD};
        rom_array[4'b1011] = {29'b0, ALUControl};
        rom_array[4'b1100] = {31'b0, ALUSrcD};
    end

   
    always_ff @(posedge clk) begin

        rd1E        <= rom_array[4'b0000];
        rd2E        <= rom_array[4'b0001];
        PCe         <= rom_array[4'b0010];
        RdE         <= rom_array[4'b0011][4:0];  
        ImmExtE     <= rom_array[4'b0100];       
        PcPlus4E    <= rom_array[4'b0101];
        RegWriteE   <= rom_array[4'b0110][0];    
        ResultSrcE  <= rom_array[4'b0111][1:0];  
        MemWriteE   <= rom_array[4'b1000][0];    
        BranchE     <= rom_array[4'b1010][0];    
        ALUControlE <= rom_array[4'b1011][2:0];  
        ALUSrcE     <= rom_array[4'b1100][0];    

    end

endmodule
