module L1Cache (
    input logic clk,
    input logic reset,
    /* verilator lint_off UNUSED */
    input logic [31:0] address,
    /* verilator lint_on UNUSED */
    input logic [31:0] writeData,  
    input logic writeEnable,       
    output logic [31:0] readData, 
    output logic hit               
);
    parameter CACHE_SIZE = 256;   
    parameter LINE_SIZE = 4;      
    parameter TAG_WIDTH = 20;    

    typedef struct {
        logic [TAG_WIDTH-1:0] tag;        
        logic [LINE_SIZE-1:0][31:0] data; 
        logic valid;                      
    } CacheLine;

    CacheLine cache[CACHE_SIZE];  

    logic [7:0] index;   
    logic [1:0] offset;  

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
  
            for (int i = 0; i < CACHE_SIZE; i++) begin
                cache[i].valid <= 0;
            end
            hit <= 0;
        end else begin

            index <= address[9:2];
            offset <= address[1:0];


            if (cache[index].valid && cache[index].tag == address[31:12]) begin
                hit <= 1;
                readData <= cache[index].data[offset];
            end else begin
                hit <= 0;
                cache[index].tag <= address[31:12];  
                cache[index].data[offset] <= writeData; 
                cache[index].valid <= 1;
            end


            if (writeEnable) begin
                cache[index].data[offset] <= writeData;
            end
        end
    end
endmodule
