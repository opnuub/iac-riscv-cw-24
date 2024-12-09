module L2Cache (
    input logic clk,
    input logic reset,
    input logic [31:0] address,
    input logic [31:0] writeData,
    input logic writeEnable,
    output logic [31:0] readData,
    output logic hit
);

    parameter CACHE_SIZE = 1024;
    parameter LINE_SIZE = 8;
    parameter TAG_WIDTH = 18;

    typedef struct {
        logic [TAG_WIDTH-1:0] tag;
        logic [LINE_SIZE-1:0][31:0] data;
        logic valid;
    } CacheLine;

    CacheLine cache[CACHE_SIZE];

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            for (int i = 0; i < CACHE_SIZE; i++) begin
                cache[i].valid <= 0;
            end
            hit <= 0;
        end else begin
            int index = address[11:2];
            int offset = address[1:0];
            if (cache[index].valid && cache[index].tag == address[31:12]) begin
                hit <= 1;
                readData <= cache[index].data[offset];
            end else begin
                hit <= 0;
            end
            if (writeEnable) begin
                cache[index].data[offset] <= writeData;
            end
        end
    end
endmodule
