module jumpMux #(
    parameter DATA_WIDTH = 32
) (
    input   logic [DATA_WIDTH-1:0]  result,
    input   logic [DATA_WIDTH-1:0]  incPC,
    input   logic                   jumpSrc,
    output  logic [DATA_WIDTH-1:0]  ALUout
);

    assign ALUout = jumpSrc ? incPC : result;
    
endmodule
