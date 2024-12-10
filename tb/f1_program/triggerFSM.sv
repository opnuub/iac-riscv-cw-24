module triggerFSM (
    input   logic   clk,
    input   logic   rst,
    input   logic   trigger,
    output  logic   triggerRst
);
    
    typedef enum {IDLE, RUN} my_state;
    my_state current_state, next_state;

    always_ff @(posedge clk) begin
        if (rst)            current_state <= IDLE;
        else                current_state <= next_state;
    end

    always_comb
        case (current_state)
            IDLE:   if (trigger==1'b1)  next_state = RUN;
                    else                next_state = current_state;
            RUN:    next_state = RUN;
        endcase

    assign triggerRst = (current_state == IDLE);

endmodule