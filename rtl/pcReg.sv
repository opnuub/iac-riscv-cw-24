module pcReg #(
    parameter OFFSET = 4,
    parameter ADDR_WIDTH = 16
) (
    input   logic [ADDR_WIDTH-1:0]  nextPC,
    input   logic                   clk,
    input   logic                   rst,
    input   logic [DATA_WIDTH-1:0]  immOp,
    output  logic [DATA_WIDTH-1:0]  branchPC,          
    output  logic [DATA_WIDTH-1:0]  incPC,
    output  logic [DATA_WIDTH-1:0]  pc
);

    always_comb begin
        incPC = pc + OFFSET;
        branchPC = pc + immOp[15:0];
    end

    always_ff @ (posedge clk)
        if (rst)
            pc <= 0;
        else
            pc <= nextPC;

endmodule
