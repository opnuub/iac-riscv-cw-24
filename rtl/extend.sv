module extend #(
    parameter INSTR_WIDTH = 32,
    parameter DATA_WIDTH = 32
) (
    input  logic [INSTR_WIDTH-1:0] instruction,  
    input  logic [1:0]  immSrc,       
    output logic [DATA_WIDTH-1:0] immExt       
);
    always_comb begin
        case (immSrc)
            2'b00: immExt = {{20{instruction[31]}}, instruction[31:20]};
            2'b01: immExt = {{20{instruction[31]}}, instruction[31:25], instruction[11:7]};
            2'b10: immExt = {{20{instruction[31]}}, instruction[7], instruction[30:25], instruction[11:8], 1'b0};
            default: immExt = 32'd4; // shouldn't happen
        endcase
    end
endmodule
