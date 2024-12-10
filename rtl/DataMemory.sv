module DataMemory #(
    parameter DATA_WIDTH = 32,
    parameter ADDR_WIDTH = 17
) (
    input  logic                   clk,
    input  logic [2:0]             SizeCtr,
    input  logic [ADDR_WIDTH-1:0]  ALUResult,
    input  logic [DATA_WIDTH-1:0]  WriteData,
    input  logic                   MemWrite,
    output logic [DATA_WIDTH-1:0]  ReadData,
    // output logic [DATA_WIDTH-1:0]  rega5,
    // output logic [DATA_WIDTH-1:0]  rega6,
    input  logic [DATA_WIDTH-1:0]  a5,
    output logic [DATA_WIDTH-1:0]  a6
);

    logic [7:0] memory [2**ADDR_WIDTH-1:0];

    // assign rega5 = memory[a5];
    // assign rega6 = memory[a6];

    initial begin
        $display("Attempting to load 'data.hex'...");
        $readmemh("data.hex", memory, 17'h10000);
        $display("'data.hex' loaded into memory.");
    end

    always_ff @(posedge clk) begin
        if (MemWrite) begin
            case (SizeCtr)
                3'b010: begin
                    memory[ALUResult]     <= WriteData[7:0];
                    memory[ALUResult+1]   <= WriteData[15:8];
                    memory[ALUResult+2]   <= WriteData[23:16];
                    memory[ALUResult+3]   <= WriteData[31:24];
                end
                3'b001: begin
                    memory[ALUResult]     <= WriteData[7:0];
                    memory[ALUResult+1]   <= WriteData[15:8];
                end
                3'b000: begin
                    memory[ALUResult]     <= WriteData[7:0];
                end
                default: ;
            endcase
        end
    end

    always_comb begin
        case (SizeCtr)
            3'b010: begin
                ReadData = {memory[ALUResult+3], memory[ALUResult+2], memory[ALUResult+1], memory[ALUResult]};
            end
            3'b001: begin
                ReadData = {{16{memory[ALUResult+1][7]}}, memory[ALUResult+1], memory[ALUResult]};
            end
            3'b000: begin
                ReadData = {{24{memory[ALUResult][7]}}, memory[ALUResult]};
            end
            3'b100: begin
                ReadData = {24'b0, memory[ALUResult]};
            end
            3'b101: begin
                ReadData = {16'b0, memory[ALUResult+1], memory[ALUResult]};
            end
            default: ReadData = 32'b0;
        endcase
    end

endmodule
