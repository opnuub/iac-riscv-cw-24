module f1 #(
    parameter DATA_WIDTH = 32
) (
    input   logic                   clk,
    input   logic                   rst,
    input   logic                   trigger,
    output  logic [DATA_WIDTH-1:0]  a0
);

    logic           triggerRst;
    logic           delayed_clk;

    clkdiv clkdiv (
        .delay (8'hF),
        .rst (rst),
        .clkin (clk),
        .clkout (delayed_clk)
    );

    triggerFSM triggerFSM (
        .clk (clk),
        .rst (rst),
        .trigger (trigger),
        .triggerRst (triggerRst)
    );

    top top (
        .clk (delayed_clk),
        .rst (rst),
        .trigger (triggerRst),
        .a0 (a0)
    );

endmodule
