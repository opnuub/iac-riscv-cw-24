module pcReg #(
    ADDR_WIDTH = 16
) (
    input   logic [ADDR_WIDTH-1:0]  nextPC,
    input   logic                   clk,
    input   logic                   rst,
    output  logic [ADDR_WIDTH-1:0]  pc
);

    always_ff @ (posedge clk)
        if (rst)
            pc <= 0;
        else
            pc <= nextPC;

endmodule
