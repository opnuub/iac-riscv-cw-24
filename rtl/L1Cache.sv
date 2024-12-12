module L1Cache #(
    parameter DATA_WIDTH = 32,
    parameter SET_WIDTH = 9,
    parameter TAG_WIDTH = DATA_WIDTH - SET_WIDTH - 2
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
    typedef enum logic [2:0] {
        IDLE,
        READ_MISS,
        WRITE_MISS,
        WRITE_BACK,
        UPDATE
    } state_t;

    state_t state;
    
    typedef struct packed {
        logic valid;
        logic dirty;
        logic [TAG_WIDTH-1:0] tag;
        logic [DATA_WIDTH-1:0] data;
    } line_t;
    
    line_t cache[2**SET_WIDTH][2];
    logic [2**SET_WIDTH-1:0] lru;
    
    logic [TAG_WIDTH-1:0] tag;
    logic [SET_WIDTH-1:0] index;
    logic way;
    logic hit_way;
    
    assign tag = address[DATA_WIDTH-1:SET_WIDTH+2];
    assign index = address[SET_WIDTH+1:2];
    
    always_comb begin
        hit = 0;
        hit_way = 0;
        
        if(cache[index][0].valid && cache[index][0].tag == tag) begin
            hit = 1;
            hit_way = 0;
        end else if(cache[index][1].valid && cache[index][1].tag == tag) begin
            hit = 1;
            hit_way = 1;
        end
        
        way = lru[index];
        if(!cache[index][0].valid) way = 0;
        else if(!cache[index][1].valid) way = 1;
        
        miss = !hit && (load || store);
        mem_write_data = cache[index][way].data;
        data_out = hit ? cache[index][hit_way].data : mem_data;
    end
    
    always_ff @(posedge clk or negedge rst_n) begin
        
        if(!rst_n) begin
            state <= IDLE;
            busy <= 0;
            mem_read <= 0;
            mem_write <= 0;
            lru <= 0;
            for(int i = 0; i < 2**SET_WIDTH; i++) begin
                cache[i][0] <= '0;
                cache[i][1] <= '0;
            end
        end else begin
            unique case(state)
                IDLE: begin
                    if(miss) begin
                        busy <= 1;
                        if(cache[index][way].valid && cache[index][way].dirty) begin
                            mem_write <= 1;
                            state <= WRITE_BACK;
                        end else if(load) begin
                            mem_read <= 1;
                            state <= READ_MISS;
                        end else begin
                            state <= WRITE_MISS;
                        end
                    end else begin
                        busy <= 0;
                        mem_write <= 0;
                        mem_read <= 0;
                        if(hit && store) begin
                            cache[index][hit_way].data <= data_in;
                            cache[index][hit_way].dirty <= 1;
                            lru[index] <= !hit_way;
                        end else if(store) begin 
                            cache[index][way].dirty <= 1;
                        end
                    end
                end
                
                WRITE_BACK: begin
                    if(mem_ready) begin
                        mem_write <= 0;
                        mem_read <= load;
                        state <= load ? READ_MISS : WRITE_MISS;
                    end
                end
                
                READ_MISS: begin
                    if(mem_ready) begin
                        mem_read <= 0;
                        state <= UPDATE;
                    end
                end
                
                WRITE_MISS: begin
                    state <= UPDATE;
                end
                
                UPDATE: begin
                    busy <= 0;
                    cache[index][way].valid <= 1;
                    cache[index][way].dirty <= store;
                    cache[index][way].tag <= tag;
                    cache[index][way].data <= store ? data_in : mem_data;
                    lru[index] <= !way;
                    state <= IDLE;
                end
            endcase
        end
    end
    
endmodule
