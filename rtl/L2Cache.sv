module L2Cache #(
    parameter DATA_WIDTH = 32,
    parameter SET_WIDTH = 10,
    parameter LINE_SIZE = 4,  // 4 words per cache line
    parameter TAG_WIDTH = DATA_WIDTH - SET_WIDTH - 2 - $clog2(LINE_SIZE)
) (
    input  logic clk,
    input  logic rst_n,
    input  logic load,
    input  logic store,
    input  logic [DATA_WIDTH-1:0] address,
    input  logic [DATA_WIDTH-1:0] data_in,
    input  logic [DATA_WIDTH-1:0] mem_data,
    input  logic mem_ready,
    output logic hit,
    output logic miss,
    output logic mem_write,
    output logic mem_read,
    output logic busy,
    output logic [DATA_WIDTH-1:0] data_out,
    output logic [DATA_WIDTH-1:0] mem_write_data
);

    // Enhanced cache line structure
    typedef struct packed {
        logic valid;
        logic dirty;
        logic [TAG_WIDTH-1:0] tag;
        logic [LINE_SIZE-1:0][DATA_WIDTH-1:0] data;
    } line_t;

    // Cache storage and LRU table
    line_t cache[2**SET_WIDTH][2];
    logic [2**SET_WIDTH-1:0] lru;

    // Address decomposition
    logic [TAG_WIDTH-1:0] tag;
    logic [SET_WIDTH-1:0] index;
    logic [$clog2(LINE_SIZE)-1:0] line_offset;
    logic [1:0] word_offset;

    assign tag = address[DATA_WIDTH-1:SET_WIDTH+$clog2(LINE_SIZE)+2];
    assign index = address[SET_WIDTH+$clog2(LINE_SIZE)+1:$clog2(LINE_SIZE)+2];
    assign line_offset = address[$clog2(LINE_SIZE)+1:2];
    
    logic hit_way;
    logic way;
    logic [$clog2(LINE_SIZE)-1:0] current_word;

    logic [LINE_SIZE-1:0][DATA_WIDTH-1:0] write_buffer;
    logic write_back_complete;

    logic write_back_error;
    logic [3:0] retry_count;

    typedef enum logic [2:0] {
        IDLE,
        READ_MISS,
        WRITE_MISS,
        WRITE_BACK,
        LINE_FILL,
        UPDATE
    } state_t;

    state_t state;
    logic [1:0] word_count;

    always_comb begin
        hit = 0;
        miss = 0;
        hit_way = 0;

        // Check both ways for hit
        if (cache[index][0].valid && cache[index][0].tag == tag) begin
            hit = 1;
            hit_way = 0;
        end else if (cache[index][1].valid && cache[index][1].tag == tag) begin
            hit = 1;
            hit_way = 1;
        end

        miss = !hit && (load || store);

        // LRU way selection
        way = lru[index];
        if (!cache[index][0].valid) way = 0;
        else if (!cache[index][1].valid) way = 1;

        // Output data selection
        data_out = hit ? cache[index][hit_way].data[line_offset] : mem_data;
        mem_write_data = cache[index][way].data[current_word];
    end
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            retry_count = 0;
            write_back_error = 0; 
        end else if (state == WRITE_BACK) begin
            if (retry_count == 4'hF) begin 
                write_back_error = 1;
                state = IDLE;
            end else if (!mem_ready) begin
                retry_count = retry_count + 1;
            end
        end
    end

    logic write_back_done;
    logic [LINE_SIZE-1:0] valid_words;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state = IDLE;
            busy = 0;
            mem_read = 0;
            mem_write = 0;
            current_word = 0;
            word_count = 0;
            write_back_done = 0;
            valid_words = '0;
            lru = 0;
            
            for (int i = 0; i < 2**SET_WIDTH; i++) begin
                cache[i][0] = '0;
                cache[i][1] = '0;
            end
        end else begin
            case (state)
                IDLE: begin
                    if (miss) begin
                        busy = 1;
                        current_word = 0;
                        word_count = 0;
                        write_back_done = 0;
                        valid_words = '0;
                        
                        if (cache[index][way].valid && cache[index][way].dirty) begin
                            mem_write = 1;
                            state = WRITE_BACK;
                            
                            mem_write_data = cache[index][way].data[0];
                        end else if (load) begin
                            mem_read = 1;
                            state = READ_MISS;
                        end else begin
                            state = WRITE_MISS;
                        end
                    end else begin
                        busy = 0;
                        if (hit && store) begin
                            cache[index][hit_way].data[line_offset] = data_in;
                            cache[index][hit_way].dirty = 1;
                            lru[index] = !hit_way;
                        end
                    end
                end

                WRITE_BACK: begin
                    if (mem_ready) begin
                        valid_words[current_word] = 1;
                        
                        if (word_count == LINE_SIZE - 1) begin
                            if (&valid_words[LINE_SIZE-2:0]) begin  // 检查之前的所有字是否已写回
                                mem_write = 0;
                                write_back_done = 1;
                                // 清除脏位,因为数据已经写回
                                cache[index][way].dirty = 0;
                                
                                // 转换到下一个状态
                                if (load) begin
                                    mem_read = 1;
                                    state = READ_MISS;
                                end else begin
                                    state = WRITE_MISS;
                                end
                                
                                // 重置计数器和标志位
                                word_count = 0;
                                current_word = 0;
                                valid_words = '0;
                            end
                        end else begin
                            // 准备下一个要写回的字
                            word_count = word_count + 1;
                            current_word = current_word + 1;
                            mem_write_data = cache[index][way].data[current_word + 1];
                        end
                    end
                end

                READ_MISS: begin
                    if (mem_ready) begin
                        if (word_count == LINE_SIZE - 1) begin
                            mem_read = 0;
                            state = LINE_FILL;
                        end else begin
                            word_count = word_count + 1;
                            current_word = current_word + 1;
                            cache[index][way].data[current_word] = mem_data;
                        end
                    end
                end

                LINE_FILL: begin
                    cache[index][way].valid = 1;
                    cache[index][way].dirty = 0;
                    cache[index][way].tag = tag;
                    state = UPDATE;
                end

                WRITE_MISS: begin
                    cache[index][way].data[line_offset] = data_in;
                    cache[index][way].valid = 1;
                    cache[index][way].dirty = 1;
                    cache[index][way].tag = tag;
                    state = UPDATE;
                end

                UPDATE: begin
                    busy = 0;
                    lru[index] = !way;
                    state = IDLE;
                end

                default: state = IDLE;
            endcase
        end
    end
endmodule