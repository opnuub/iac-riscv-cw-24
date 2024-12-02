module PCReg #(
    DATA_WIDTH = 32
) (
    input   logic [DATA_WIDTH-1:0]  PCFp,
    input   logic                   clk,
    input   logic                   rst,
    output  logic [DATA_WIDTH-1:0]  PCf
);  

    always_ff @ (posedge clk, posedge rst)
        if (rst)
            PCf <= 32'b0;
        else
            PCf <= PCFp;

endmodule
