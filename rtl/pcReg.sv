module pcReg #(
    parameter OFFSET = 4,
    parameter ADDR_WIDTH = 12
) (
    input   logic [ADDR_WIDTH-1:0]  nextPC,
    input   logic                   clk,
    input   logic                   triggerRst,        
    output  logic [ADDR_WIDTH-1:0]  incPC,
    output  logic [ADDR_WIDTH-1:0]  pc
);

    always_comb begin
        incPC = pc + OFFSET;
    end

    always_ff @ (posedge clk)
        if (triggerRst)
            pc <= 0;
        else
            pc <= nextPC;

endmodule
