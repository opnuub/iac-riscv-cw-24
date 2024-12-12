module l3_cache #(
    parameter ADDR_WIDTH = 32,
    parameter DATA_WIDTH = 32,
    parameter BLOCK_SIZE = 4,
    parameter NUM_SETS = 2048,
    parameter NUM_WAYS = 4,
    parameter TAG_WIDTH = ADDR_WIDTH - $clog2(NUM_SETS) - $clog2(BLOCK_SIZE)
) (
    input  logic                        clk,
    input  logic                        rst,
    input  logic                        l2_rd_en_i,
    input  logic                        l2_wr_en_i,
    input  logic [ADDR_WIDTH-1:0]       l2_addr_i,
    input  logic [DATA_WIDTH-1:0]       l2_wr_data_i,
    input  logic [3:0]                  l2_byte_en_i,
    output logic [DATA_WIDTH-1:0]       l2_rd_data_o,
    output logic                        l2_cache_hit_o,
    input  logic                        mem_valid_i,
    input  logic [DATA_WIDTH-1:0]       mem_data_i,
    output logic                        mem_rd_en_o,
    output logic                        mem_wr_en_o,
    output logic [ADDR_WIDTH-1:0]       mem_addr_o,
    output logic [DATA_WIDTH-1:0]       mem_wr_data_o
);

    logic [DATA_WIDTH-1:0] cache_data [NUM_SETS-1:0][NUM_WAYS-1:0];
    logic [TAG_WIDTH-1:0]  cache_tags [NUM_SETS-1:0][NUM_WAYS-1:0];
    logic                  valid [NUM_SETS-1:0][NUM_WAYS-1:0];
    logic                  dirty [NUM_SETS-1:0][NUM_WAYS-1:0];
    logic [1:0]           lru [NUM_SETS-1:0][NUM_WAYS-1:0];

    logic [TAG_WIDTH-1:0]                tag;
    logic [$clog2(NUM_SETS)-1:0]         index;
    logic [$clog2(BLOCK_SIZE)-1:0]       offset;
    

    logic                                hit;
    logic [$clog2(NUM_WAYS)-1:0]         hit_way;
    logic [$clog2(NUM_WAYS)-1:0]         replace_way;
    logic                                need_wb;
    logic [DATA_WIDTH-1:0]               rd_data;


    assign tag = l2_addr_i[ADDR_WIDTH-1 : ADDR_WIDTH-TAG_WIDTH];
    assign index = l2_addr_i[ADDR_WIDTH-TAG_WIDTH-1 : $clog2(BLOCK_SIZE)];
    assign offset = l2_addr_i[$clog2(BLOCK_SIZE)-1 : 0];

    // Check for miss
    always_comb begin
        hit = 1'b0;
        hit_way = '0;
        
        for (int i = 0; i < NUM_WAYS; i++) begin
            if (valid[index][i] && (cache_tags[index][i] == tag)) begin
                hit = 1'b1;
                hit_way = i;
                break;
            end
        end
    end

    // LRU Updater
    always_comb begin
        replace_way = '0;
        for (int i = 1; i < NUM_WAYS; i++) begin
            if (lru[index][i] < lru[index][replace_way]) begin
                replace_way = i;
            end
        end
        need_wb = valid[index][replace_way] && dirty[index][replace_way];
    end

    // LRU Update
    always_ff @(posedge clk) begin
        if (rst) begin
            for (int i = 0; i < NUM_SETS; i++) begin
                for (int j = 0; j < NUM_WAYS; j++) begin
                    lru[i][j] <= j;
                end
            end
        end 
        else if (hit && (l2_rd_en_i || l2_wr_en_i)) begin
            for (int i = 0; i < NUM_WAYS; i++) begin
                if (i == hit_way)
                    lru[index][i] <= NUM_WAYS - 1;
                else if (lru[index][i] > lru[index][hit_way])
                    lru[index][i] <= lru[index][i] - 1;
            end
        end
        else if (!hit && mem_valid_i) begin
            for (int i = 0; i < NUM_WAYS; i++) begin
                if (i == replace_way)
                    lru[index][i] <= NUM_WAYS - 1;
                else if (lru[index][i] > lru[index][replace_way])
                    lru[index][i] <= lru[index][i] - 1;
            end
        end
    end

    // Memory access and update
    always_ff @(posedge clk) begin
        if (rst) begin
            for (int i = 0; i < NUM_SETS; i++) begin
                for (int j = 0; j < NUM_WAYS; j++) begin
                    valid[i][j] <= 1'b0;
                    dirty[i][j] <= 1'b0;
                    cache_tags[i][j] <= '0;
                    cache_data[i][j] <= '0;
                end
            end
            mem_rd_en_o <= 1'b0;
            mem_wr_en_o <= 1'b0;
        end 
        else begin
            mem_rd_en_o <= !hit && (l2_rd_en_i || l2_wr_en_i) && !need_wb;
            mem_wr_en_o <= !hit && need_wb;

            // Hit update
            if ((l2_rd_en_i || l2_wr_en_i) && hit && l2_wr_en_i) begin
                for (int i = 0; i < 4; i++) begin
                    if (l2_byte_en_i[i]) begin
                        cache_data[index][hit_way][i*8 +: 8] <= l2_wr_data_i[i*8 +: 8];
                    end
                end
                dirty[index][hit_way] <= 1'b1;
            end
            // miss update
            else if (!hit && mem_valid_i) begin
                cache_tags[index][replace_way] <= tag;
                cache_data[index][replace_way] <= mem_data_i;
                valid[index][replace_way] <= 1'b1;
                dirty[index][replace_way] <= l2_wr_en_i;
                
                if (l2_wr_en_i) begin
                    for (int i = 0; i < 4; i++) begin
                        if (l2_byte_en_i[i]) begin
                            cache_data[index][replace_way][i*8 +: 8] <= l2_wr_data_i[i*8 +: 8];
                        end
                    end
                end
            end
        end
    end

    // 
    always_comb begin
        // Address reading
        mem_addr_o = need_wb ? {cache_tags[index][replace_way], index, {$clog2(BLOCK_SIZE){1'b0}}} : l2_addr_i;
        mem_wr_data_o = need_wb ? cache_data[index][replace_way] : l2_wr_data_i;
        
        // Reading data
        if (hit)
            rd_data = cache_data[index][hit_way];
        else if (mem_valid_i)
            rd_data = mem_data_i;
        else
            rd_data = '0;
    end

    assign l2_cache_hit_o = hit;
    assign l2_rd_data_o = rd_data;

endmodule