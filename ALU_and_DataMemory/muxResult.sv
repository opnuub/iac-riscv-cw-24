module muxResult #(
    parameter DATA_WIDTH = 32
) (
    input   logic [DATA_WIDTH-1:0]  ReadData,
    input   logic [DATA_WIDTH-1:0]  ALUResult,
    input   logic                   ResultSrc,
    output  logic [DATA_WIDTH-1:0]  Result
);


    assign Result = ResultSrc ? ReadData : ALUResult;

endmodule
