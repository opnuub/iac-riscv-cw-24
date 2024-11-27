module DataMemory #(
    parameter DATA_WIDTH = 32,
    parameter ADDR_WIDTH = 10
) (
    input   logic                   clk,
    input   logic [ADDR_WIDTH-1:0]  ALUResult,
    input   logic [DATA_WIDTH-1:0]  WriteData,
    input   logic                   MemWrite,
    output  logic [DATA_WIDTH-1:0]  ReadData
);

    logic [DATA_WIDTH-1:0] memory [2**ADDR_WIDTH-1:0];

    always_ff @(posedge clk) begin
        if (MemWrite) begin
            memory[ALUResult] <= WriteData;
        end
    end

    assign ReadData = memory[ALUResult];

endmodule
