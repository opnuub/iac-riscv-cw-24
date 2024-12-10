module lfsr #(
    parameter WIDTH = 4,              // Configurable width of the LFSR
    parameter RESET_VAL = {WIDTH{1'b1}} // Reset value (default to all ones)
) (
    input   logic               clk,    // Clock input
    input   logic               rst,    // Reset input
    input   logic               en,     // Enable signal
    output  logic [WIDTH-1:0]   data_out // LFSR output
);

    logic [WIDTH-1:0] sreg = RESET_VAL; // Shift register with default reset value

    // Shift logic
    always_ff @ (posedge clk)
        if (rst)
            sreg <= RESET_VAL;          // Reset to parameterized value
        else if (en)
            sreg <= {sreg[WIDTH-2:0], sreg[WIDTH-1] ^ sreg[WIDTH-2]}; // LFSR shift

    // Assign output
    assign data_out = sreg;

endmodule
