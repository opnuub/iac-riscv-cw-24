module pcReg #(
    parameter OFFSET = 4,
    parameter ADDR_WIDTH = 12
) (
    input   logic [ADDR_WIDTH-1:0]  nextPC,
    input   logic                   clk,
    input   logic                   rst,
    input   logic [ADDR_WIDTH:0]    immOp, // 13 bits
    output  logic [ADDR_WIDTH-1:0]  branchPC,          
    output  logic [ADDR_WIDTH-1:0]  incPC,
    output  logic [ADDR_WIDTH-1:0]  pc
);

    always_comb begin
        incPC = pc + OFFSET;
        branchPC = pc + immOp;
    end

    always_ff @ (posedge clk)
        if (rst)
            pc <= 0;
        else
            pc <= nextPC;

endmodule
