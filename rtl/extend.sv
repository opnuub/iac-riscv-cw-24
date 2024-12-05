module extend #(
    parameter INSTR_WIDTH = 32,
    parameter DATA_WIDTH = 32
) (
    input   logic [INSTR_WIDTH-1:0] instruction,  
    input   logic [1:0]             immSrc,       
    input   logic                   jumpSrc,  
    output  logic [DATA_WIDTH-1:0]  immExt       
);
    always_comb begin
        case (immSrc)
            2'b00: immExt = {{20{instruction[31]}}, instruction[31:20]};
            2'b01: immExt = {{20{instruction[31]}}, instruction[31:25], instruction[11:7]};
            2'b10: immExt = {{20{instruction[31]}}, instruction[7], instruction[30:25], instruction[11:8], 1'b0};
            2'b11: begin
                if (jumpSrc)
                    immExt = {instruction[31:12], 12'b0};
                else
                    immExt = {{11{instruction[31]}}, instruction[31], instruction[19:12], instruction[20], instruction[30:21], 1'b0};
            end
        endcase
    end
endmodule
