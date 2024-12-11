module L3Cache (
    input logic clk,
    input logic reset,
    input logic [31:0] address,   
    input logic [31:0] writeData,  
    input logic writeEnable,       
    output logic [31:0] readData,  
    output logic hit             
);

    parameter CACHE_SIZE = 4096;   
    parameter LINE_SIZE = 16;      
    parameter TAG_WIDTH = 14;      
    parameter INDEX_BITS = 12;
    parameter OFFSET_BITS = 4;

    typedef struct {
        logic [TAG_WIDTH-1:0] tag;       
        logic [LINE_SIZE-1:0][31:0] data; 
        logic valid;                      
        logic dirty;                      
    } CacheLine;

    CacheLine cache[CACHE_SIZE];  

    // Internal signals with proper widths
    logic [INDEX_BITS-1:0] index;
    logic [OFFSET_BITS-1:0] offset;
    logic [TAG_WIDTH-1:0] tag_in;

    // Address breakdown
    assign index = address[13:2];
    assign offset = address[3:0];
    assign tag_in = address[31:14];

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            for (int i = 0; i < CACHE_SIZE; i++) begin
                cache[i].valid = 0;
                cache[i].dirty = 0;
                cache[i].tag = '0;
            end
            hit = 0;
            readData = '0;
        end else begin
            if (cache[index].valid && cache[index].tag == tag_in) begin
                hit = 1;
                readData = cache[index].data[offset];
            end else begin
                hit = 0;
                if (writeEnable) begin
                    cache[index].tag = tag_in;
                    cache[index].data[offset] = writeData;
                    cache[index].valid = 1;
                    cache[index].dirty = 1;
                end
            end

            if (writeEnable) begin
                cache[index].data[offset] = writeData;
                cache[index].dirty = 1;
            end
        end
    end
endmodule
