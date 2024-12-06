module resultMux #(
    parameter DATA_WIDTH = 32
) (
    input   logic [DATA_WIDTH-1:0]  ReadDataW,
    input   logic [DATA_WIDTH-1:0]  ALUResult,
    input   logic [DATA_WIDTH-1:0]  PCPlus4,
    input   logic [1:0]             ResultSrc,
    output  logic [DATA_WIDTH-1:0]  Result
);

    always_comb begin
        // Default assignment to avoid latches
        Result = '0;

        // Explicitly handle all cases
        case (ResultSrc)
            2'b00: Result = ALUResult;
            2'b01: Result = ReadData;
            2'b10: Result = PCPlus4;
            // No need for 2'b11 since Immediate is not used
            default: Result = '0; // For safety
        endcase
    end

endmodule
