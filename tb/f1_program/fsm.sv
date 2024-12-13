module fsm (
    input   logic           rst,
    input   logic           clk,
    input   logic [31:0]    tmp_a0,
    output  logic [31:0]    a0
);

    typedef enum {RST, NRST} my_state;
    my_state current, next;

    always_ff @(posedge clk, posedge rst)
        if (rst) current <= RST;
        else     current <= next;

    always_comb
        case (current)
            RST: begin
                a0 <= 0;
                if (tmp_a0 == 32'd1)    next = NRST;
                else                    next = RST;
            end
            NRST: begin
                a0 <= tmp_a0;
                next = NRST;
            end
        endcase

endmodule
