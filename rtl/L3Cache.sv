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


    typedef struct {
        logic [TAG_WIDTH-1:0] tag;       
        logic [LINE_SIZE-1:0][31:0] data; 
        logic valid;                      
        logic dirty;                      
    } CacheLine;

    CacheLine cache[CACHE_SIZE];  


    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin

            for (int i = 0; i < CACHE_SIZE; i++) begin
                cache[i].valid <= 0;
                cache[i].dirty <= 0;
            end
            hit <= 0;
        end else begin

            int index = address[13:2]; 
            int offset = address[3:0];

            if (cache[index].valid && cache[index].tag == address[31:14]) begin
                hit <= 1;
                readData <= cache[index].data[offset];
            end else begin
                hit <= 0;


                if (cache[index].valid && cache[index].dirty) begin

                    // $write_memory(cache[index].tag, cache[index].data);
                end


                cache[index].tag <= address[31:14];
                cache[index].data[offset] <= writeData; 
                cache[index].valid <= 1;
                cache[index].dirty <= writeEnable;
            end

            if (writeEnable) begin
                cache[index].data[offset] <= writeData;
                cache[index].dirty <= 1;
            end
        end
    end
endmodule
