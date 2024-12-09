module HazardMux #(
    parameter DATA_WIDTH = 32
) (
    input   logic [DATA_WIDTH-1:0]  rdE,
    input   logic [DATA_WIDTH-1:0]  ResultW,
    input   logic [DATA_WIDTH-1:0]  ALUResultM,
    input   logic [1:0]             Forward,
    output  logic [DATA_WIDTH-1:0]  Out
);

    always_comb begin
        
        Out = '0;

        case (Forward)
            2'b00: Out = rdE;
            2'b01: Out = ResultW;
            2'b10: Out = ALUResultM;
            default: Out = '0;
        endcase
    end

endmodule