module f1 #(
    parameter DATA_WIDTH = 32
) (
    input   logic                   clk,
    input   logic                   rst,
    input   logic                   trigger,
    output  logic [DATA_WIDTH-1:0]  a0
);

    logic       delayed_clk;
    logic [3:0] random_delay;

    lfsr lfsr (
        .clk (clk),
        .data_out (random_delay)
    );

    clktick clktick (
        .N (32'd38),
        .random_delay (random_delay),
        .a0 (a0),
        .rst (rst),
        .clk_i (clk),
        .clk_o (delayed_clk)
    );

    top top (
        .clk (delayed_clk),
        .rst (rst),
        .trigger (trigger),
        .a0 (a0)
    );

endmodule
