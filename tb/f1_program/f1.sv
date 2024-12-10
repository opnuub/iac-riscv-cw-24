// module f1 #(
//     parameter DATA_WIDTH = 32,
//     parameter LFSR_WIDTH = 4,              // Width of the LFSR
//     parameter LFSR_RESET_VAL = {LFSR_WIDTH{1'b1}} // Reset value for the LFSR
// ) (
//     input   logic                   clk,
//     input   logic                   rst,
//     input   logic                   trigger,
//     output  logic [DATA_WIDTH-1:0]  a0
// );

//     // Do not declare triggerRst and delayed_clk here again, 
//     // as they are already handled inside the submodules.
    
//     // Use these signals directly from the submodules
//     clkdiv clkdiv_inst (
//         .delay (8'hF),
//         .rst (rst),
//         .clkin (clk),
//         .clkout (delayed_clk)   // Output is connected to delayed_clk in the top
//     );

//     triggerFSM triggerFSM_inst (
//         .clk (clk),
//         .rst (rst),
//         .trigger (trigger),
//         .triggerRst (triggerRst)   // Output is connected to triggerRst in the top
//     );

//     top top_inst (
//         .clk (delayed_clk),
//         .rst (rst),
//         .trigger (triggerRst),
//         .a0 (a0)
//     );

    // LFSR Module
    // lfsr #(
    //     .WIDTH      (LFSR_WIDTH),       // Parameterized LFSR width
    //     .RESET_VAL  (LFSR_RESET_VAL)    // Parameterized reset value
    // ) lfsr_inst (
    //     .clk        (clk),              // Clock input
    //     .rst        (rst),              // Reset input for LFSR
    //     .en         (trigger),          // Enable LFSR when trigger is active
    //     .data_out   (lfsr_out)          // LFSR output signal
    // );

// endmodule
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