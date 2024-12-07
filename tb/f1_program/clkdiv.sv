module clkdiv(
    input   logic [7:0] delay,
    input   logic       rst,
    input   logic       clkin,
    output  logic       clkout
);

    logic [7:0] count;

    always_ff @ (posedge clkin)
        if (rst) begin
            clkout <= 1'b0;
            count <= delay;
        end
        else begin
            if (count == 0) begin
                clkout <= 1'b1;
                count <= delay;
            end
            else begin
                clkout <= 1'b0;
                count <= count - 1'b1;
            end
        end    
endmodule
