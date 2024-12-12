module L3Cache (
    input  logic        clk,
    input  logic        reset,
    input  logic [31:0] address,          
    input  logic [31:0] writeData,        
    input  logic        writeEnable,      
    output logic [31:0] readData,         
    output logic        hit,              
    output logic        stall,            
    output logic        mem_read,        
    output logic        mem_write,        
    output logic [31:0] mem_address,      
    output logic [31:0] mem_write_data,   
    input  logic [31:0] mem_read_data,    
    input  logic        mem_ready         
);

    parameter CACHE_SIZE = 4096;  
    parameter LINE_SIZE  = 16;   //
    parameter TAG_WIDTH  = 14;   
    localparam INDEX_BITS  = $clog2(CACHE_SIZE / LINE_SIZE);
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
    typedef enum logic [1:0] {
        IDLE,
        READ_MISS,
        WRITE_BACK,
        UPDATE
    } state_t;

    state_t state;

    assign index   = address[INDEX_BITS + OFFSET_BITS - 1:OFFSET_BITS];
    assign offset  = address[OFFSET_BITS-1:0];
    assign tag_in  = address[31:INDEX_BITS + OFFSET_BITS];

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            state <= IDLE;
            readData <= 0;
            hit <= 0;
            mem_read <= 0;
            mem_write <= 0;
            stall <= 0;
            for (int i = 0; i < CACHE_SIZE / LINE_SIZE; i++) begin
                cache[i].valid = 0;
                cache[i].dirty = 0;
                cache[i].tag = 0;
            end
        end else begin
            unique case (state)
                IDLE: begin
                    stall <= 0; 
                    if (cache[index].valid && cache[index].tag == tag_in) begin
                        hit <= 1;
                        readData <= cache[index].data[offset];
                    end else begin
                        hit <= 0;
                        stall <= 1; 
                        if (cache[index].dirty) begin
                            state <= WRITE_BACK;
                        end else begin
                            state <= READ_MISS;
                        end
                    end
                end

                WRITE_BACK: begin
                    stall <= 1;
                    mem_write <= 1;
                    
                    mem_address <= {cache[index].tag, index, {OFFSET_BITS{1'b0}}}; 
                    
                    mem_write_data <= cache[index].data[0]; 
                    
                    if (mem_ready) begin
                        mem_write <= 0;
                        cache[index].dirty <= 0;
                        cache[index].valid <= 0; 
                        state <= READ_MISS;
                    end
                end

                READ_MISS: begin
                    stall <= 1; 
                    mem_read <= 1;
                    mem_address <= address;
                    if (mem_ready) begin
                        cache[index].data <= mem_read_data;
                        cache[index].tag <= tag_in;
                        cache[index].valid <= 1;
                        cache[index].dirty <= writeEnable; 
                        mem_read <= 0;
                        state <= UPDATE;
                    end
                end


                UPDATE: begin
                    stall <= 0;
                    state <= IDLE;
                end
            endcase
        end
    end

endmodule