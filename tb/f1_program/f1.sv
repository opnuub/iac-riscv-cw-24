module f1 #(
    parameter DATA_WIDTH = 32
) (
    input   logic                   clk,
    input   logic                   rst,
    input   logic                   trigger,
    output  logic [DATA_WIDTH-1:0]  a0,
    output  logic [3:0]             a1,
);

    logic           triggerRst;
    logic           delayed_clk;
    logic           en = 1'b1;

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

    lfsr lfsr(
        .clk        (clk),
        .rst        (rst),
        .en         (en),
        .data_out   (a1)
    );

endmodule