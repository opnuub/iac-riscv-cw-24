module L3Cache #(
    parameter DATA_WIDTH = 32,
    parameter SET_WIDTH = 8,
    parameter LINE_SIZE = 16,  // 16 words per cache line
    parameter TAG_WIDTH = DATA_WIDTH - SET_WIDTH - 2 - $clog2(LINE_SIZE)
) (
    input  logic                    clk,
    input  logic                    reset,
    input  logic [DATA_WIDTH-1:0]   address,
    input  logic [DATA_WIDTH-1:0]   writeData,
    input  logic                    writeEnable,
    output logic [DATA_WIDTH-1:0]   readData,
    output logic                    hit,
    output logic                    stall,
    output logic                    mem_read,
    output logic                    mem_write,
    output logic [DATA_WIDTH-1:0]   mem_address,
    output logic [DATA_WIDTH-1:0]   mem_write_data,
    input  logic [DATA_WIDTH-1:0]   mem_read_data,
    input  logic                    mem_ready
);

    // Cache line structure
    typedef struct packed {
        logic valid;
        logic dirty;
        logic [TAG_WIDTH-1:0] tag;
        logic [LINE_SIZE-1:0][DATA_WIDTH-1:0] data;
        logic [LINE_SIZE-1:0] valid_bits;  // Per-word valid bits
    } cache_line_t;

    // Cache storage
    cache_line_t cache [2**SET_WIDTH];
    
    // Address breakdown
    logic [TAG_WIDTH-1:0] tag;
    logic [SET_WIDTH-1:0] index;
    logic [$clog2(LINE_SIZE)-1:0] line_offset;
    logic [1:0] byte_offset;
    
    assign tag = address[DATA_WIDTH-1:SET_WIDTH+$clog2(LINE_SIZE)+2];
    assign index = address[SET_WIDTH+$clog2(LINE_SIZE)+1:$clog2(LINE_SIZE)+2];
    assign line_offset = address[$clog2(LINE_SIZE)+1:2];
    assign byte_offset = address[1:0];

    // FSM states
    typedef enum logic [2:0] {
        IDLE,
        READ_MISS,
        WRITE_MISS,
        WRITE_BACK,
        LINE_FILL,
        UPDATE,
        WAIT_MEMORY
    } state_t;

    state_t state;
    logic [$clog2(LINE_SIZE)-1:0] word_counter;
    logic [LINE_SIZE-1:0][DATA_WIDTH-1:0] line_buffer;

    logic write_back_done;
    logic [LINE_SIZE-1:0] valid_words;

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            state <= IDLE;
            word_counter <= '0;
            mem_read <= 1'b0;
            mem_write <= 1'b0;
            stall <= 1'b0;
            hit <= 1'b0;
            readData <= '0;
            for (int i = 0; i < 2**SET_WIDTH; i++) begin
                cache[i].valid <= 1'b0;
                cache[i].dirty <= 1'b0;
                cache[i].valid_bits <= '0;
            end
        end else begin
            case (state)
                IDLE: begin
                    stall <= 1'b1;
                    if (cache[index].valid && cache[index].tag == tag) begin
                        hit <= 1'b1;
                        readData <= cache[index].data[line_offset];
                        stall <= 1'b0;
                        state <= IDLE;
                    end else if (writeEnable) begin
                        if (cache[index].valid && cache[index].dirty) begin
                            state <= WRITE_BACK;
                            mem_write <= 1;
                            write_back_done <= 1'b0;
                            valid_words <= '0;
                            mem_write_data <= cache[index].data[0];
                            mem_address <= {cache[index].tag, index, {$clog2(LINE_SIZE){1'b0}}, 2'b00};
                        end else begin
                            state <= WRITE_MISS;
                        end
                    end else begin
                        state <= READ_MISS;
                        mem_read <= 1;
                    end
                end

                WRITE_BACK: begin
                    if (mem_ready) begin
                        valid_words[word_counter] <= 1'b1;
                        if (word_counter == LINE_SIZE - 1) begin
                            if (&valid_words) begin
                                mem_write <= 1'b0;
                                write_back_done <= 1'b1;
                                cache[index].dirty <= 1'b0;
                                word_counter <= 0;
                                state <= (writeEnable ? WRITE_MISS : READ_MISS);
                                if (!writeEnable) mem_read <= 1;
                                valid_words <= '0;
                            end
                        end else begin
                            word_counter <= word_counter + 1;
                            mem_write_data <= cache[index].data[word_counter + 1];
                            mem_address <= {cache[index].tag, index, word_counter + 1, 2'b00};
                        end
                    end
                end

                READ_MISS: begin
                    if (mem_ready) begin
                        line_buffer[word_counter] <= mem_read_data;
                        if (word_counter == LINE_SIZE - 1) begin
                            state <= LINE_FILL;
                            mem_read <= 1'b0;
                        end else begin
                            word_counter <= word_counter + 1;
                            mem_address <= {tag, index, word_counter + 1, 2'b00};
                        end
                    end
                end

                LINE_FILL: begin
                    cache[index].valid <= 1'b1;
                    cache[index].dirty <= 1'b0;
                    cache[index].tag <= tag;
                    cache[index].data <= line_buffer;
                    cache[index].valid_bits <= '1;
                    state <= UPDATE;
                end

                WRITE_MISS: begin
                    if (mem_ready) begin
                        cache[index].valid <= 1'b1;
                        cache[index].dirty <= 1'b1;
                        cache[index].tag <= tag;
                        cache[index].data[line_offset] <= writeData;
                        cache[index].valid_bits[line_offset] <= 1'b1;
                        state <= UPDATE;
                    end
                end

                UPDATE: begin
                    stall <= 1'b0;
                    state <= IDLE;
                end

                default: state <= IDLE;
            endcase
        end
    end
endmodule