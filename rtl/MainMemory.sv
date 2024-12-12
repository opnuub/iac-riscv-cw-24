module MainMemory #(
    parameter DATA_WIDTH = 32,
    parameter ADDR_WIDTH = 32,
    parameter MEM_SIZE = 16384  // 16KB memory
) (
    input  logic                        clk,
    input  logic                        rst_n,
    input  logic                        mem_read,
    input  logic                        mem_write,
    input  logic [ADDR_WIDTH-1:0]       address,
    input  logic [2:0]                  SizeCtr,
    input  logic [DATA_WIDTH-1:0]       write_data,
    output logic [DATA_WIDTH-1:0]       read_data,
    output logic                        mem_ready
);
    // Memory array - byte addressable memory
    logic [7:0] memory [MEM_SIZE-1:0];

    // Memory ready signal - always ready in this simplified version
    assign mem_ready = 1'b1;

    // Memory write operation
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            // Reset behavior is optional for memory
            // Memory contents undefined after reset
        end else if (mem_write) begin
            case (SizeCtr)
                3'b010: begin
                    // Write data one byte at a time
                    memory[address]     <= write_data[7:0];
                    memory[address+1]   <= write_data[15:8];
                    memory[address+2]   <= write_data[23:16];
                    memory[address+3]   <= write_data[31:24];
                end
                3'b001: begin
                    // Write data one byte at a time
                    memory[address]     <= write_data[7:0];
                    memory[address+1]   <= write_data[15:8];
                end
                3'b000: begin
                    // Write data one byte at a time
                    memory[address]     <= write_data[7:0];
                end
                default: ;
            endcase
        end
    end

    // Memory read operation
    always_comb begin
        case(SizeCtr)
            3'b010: begin
                // Read data one byte at a time and concatenate
                read_data = {
                    memory[address+3],
                    memory[address+2],
                    memory[address+1],
                    memory[address]
                };
            end
            3'b001: begin
                // Read data one byte at a time and concatenate
                read_data = {
                    memory[address+1],
                    memory[address],
                    16'b0
                };
            end
            3'b000: begin
                // Read data one byte at a time and concatenate
                read_data = {
                    memory[address],
                    24'b0
                };
            end
            3'b100: begin
                // Read data one byte at a time and concatenate
                read_data = {
                    24'b0,
                    memory[address]
                };
            end
            3'b101: begin
                // Read data one byte at a time and concatenate
                read_data = {
                    16'b0,
                    memory[address+1],
                    memory[address]
                };
            end
            default: read_data = '0;  // Output 0 when not reading
        endcase
    end

endmodule