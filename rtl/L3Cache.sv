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
    localparam INDEX_BITS = $clog2(CACHE_SIZE / LINE_SIZE);
    localparam OFFSET_BITS = $clog2(LINE_SIZE);

    typedef struct packed {
        logic [TAG_WIDTH-1:0] tag;
        logic [LINE_SIZE-1:0][31:0] data;
        logic valid;
        logic dirty;
    } CacheLine;

    CacheLine cache[CACHE_SIZE / LINE_SIZE];

    logic [INDEX_BITS-1:0] index;
    logic [OFFSET_BITS-1:0] offset;
    logic [TAG_WIDTH-1:0] tag_in;

    assign index = address[INDEX_BITS + OFFSET_BITS - 1:OFFSET_BITS];
    assign offset = address[OFFSET_BITS-1:0];
    assign tag_in = address[31:INDEX_BITS + OFFSET_BITS];

    typedef enum logic [1:0] {
        IDLE,
        READ_MISS,
        WRITE_BACK,
        UPDATE
    } state_t;

    state_t state;

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            state <= IDLE;
            for (int i = 0; i < CACHE_SIZE / LINE_SIZE; i++) begin
                cache[i].valid = 0;
                cache[i].dirty = 0;
                cache[i].tag = '0;
            end
            readData <= '0;
            hit <= 0;
        end else begin
            unique case (state)
                IDLE: begin
                    if (cache[index].valid && cache[index].tag == tag_in) begin
                        hit <= 1;
                        readData <= cache[index].data[offset];
                    end else begin
                        hit <= 0;
                        if (writeEnable) begin
                            if (cache[index].dirty) begin
                                state <= WRITE_BACK;
                            end else begin
                                state <= READ_MISS;
                            end
                        end
                    end
                end

                WRITE_BACK: begin
                    cache[index].dirty <= 0;
                    state <= READ_MISS;
                end

                READ_MISS: begin
                    cache[index].tag <= tag_in;
                    cache[index].data[offset] <= writeData;
                    cache[index].valid <= 1;
                    cache[index].dirty <= writeEnable;
                    state <= UPDATE;
                end

                UPDATE: begin
                    state <= IDLE;
                end
            endcase
        end
    end
endmodule
