module dataMemory #(
    parameter DATA_WIDTH = 32,
    parameter ADDR_WIDTH = 17
) (
    input   logic                   clk,
    input   logic [2:0]             SizeCtr,        // 3-bit Size Control: Selects lb, lh, lw, lbu, lhu
    input   logic [ADDR_WIDTH-1:0]  ALUResult,      // Address
    input   logic [DATA_WIDTH-1:0]  WriteData,      // Data to Write
    input   logic                   MemWrite,       // Memory Write Enable
    output  logic [DATA_WIDTH-1:0]  ReadData        // Data Read from Memory
);

logic [7:0] memory [2**ADDR_WIDTH-1:0];  // Byte-addressable memory

    always_ff @(posedge clk) begin
        if (MemWrite) begin
            case (SizeCtr)
                3'b010: begin // sw (Store Word)
                    memory[ALUResult]     <= WriteData[7:0];
                    memory[ALUResult+1]   <= WriteData[15:8];
                    memory[ALUResult+2]   <= WriteData[23:16];
                    memory[ALUResult+3]   <= WriteData[31:24];
                end
                3'b001: begin // sh (Store Halfword)
                    memory[ALUResult]     <= WriteData[7:0];
                    memory[ALUResult+1]   <= WriteData[15:8];
                end
                3'b000: begin // sb (Store Byte)
                    memory[ALUResult]     <= WriteData[7:0];
                end
                default: ; // No action for other cases
            endcase
        end
    end

    always_comb begin
        case (SizeCtr)
            3'b010: begin // lw (Load Word)
                ReadData = {memory[ALUResult+3], memory[ALUResult+2], memory[ALUResult+1], memory[ALUResult]};
            end
            3'b001: begin // lh (Load Halfword)
                ReadData = {{16{memory[ALUResult+1][7]}}, memory[ALUResult+1], memory[ALUResult]}; // Sign-extend
            end
            3'b000: begin // lb (Load Byte)
                ReadData = {{24{memory[ALUResult][7]}}, memory[ALUResult]}; // Sign-extend
            end
            3'b100: begin // lbu (Load Byte Unsigned)
                ReadData = {24'b0, memory[ALUResult]}; // Zero-extend
            end
            3'b101: begin // lhu (Load Halfword Unsigned)
                ReadData = {16'b0, memory[ALUResult+1], memory[ALUResult]}; // Zero-extend
            end
            default: ReadData = 32'b0; // Default value
        endcase
    end
    
endmodule