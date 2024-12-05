module pcReg #(
    parameter OFFSET = 4,
    parameter ADDR_WIDTH = 32
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
            pc <= 32'hBFC00000;
        else
            pc <= nextPC;

endmodule
