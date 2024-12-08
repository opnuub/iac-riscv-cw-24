module HazardUnit #(
    parameter DATA_WIDTH = 32
) (
    input   logic   zero,
    output  logic   Flush
);

    always_comb begin 

        if(zero == 1)begin
            Flush = 1;
        end else begin 
            Flush = 0;
        end
    
    end

endmodule
