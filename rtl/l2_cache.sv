module l2_cache #(
    parameter ADDR_WIDTH = 32,
    parameter DATA_WIDTH = 32,
    parameter BLOCK_SIZE = 4,
    parameter NUM_SETS = 1024,
    parameter NUM_WAYS = 4,
    parameter TAG_WIDTH = ADDR_WIDTH - $clog2(NUM_SETS) - $clog2(BLOCK_SIZE)
) (
    input  logic                        clk,
    input  logic                        rst,
    input  logic                        l1_rd_en_i,
    input  logic                        l1_wr_en_i,
    input  logic [ADDR_WIDTH-1:0]       l1_addr_i,
    input  logic [DATA_WIDTH-1:0]       l1_wr_data_i,
    input  logic [3:0]                  l1_byte_en_i,
    output logic [DATA_WIDTH-1:0]       l1_rd_data_o,
    output logic                        l1_cache_hit_o,
    input  logic                        l3_cache_valid_i,
    input  logic [DATA_WIDTH-1:0]       l3_cache_data_i,
    output logic                        l3_rd_en_o,
    output logic                        l3_wr_en_o,
    output logic [ADDR_WIDTH-1:0]       l3_addr_o,
    output logic [DATA_WIDTH-1:0]       l3_wr_data_o
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

    assign tag = l1_addr_i[ADDR_WIDTH-1 : ADDR_WIDTH-TAG_WIDTH];
    assign index = l1_addr_i[ADDR_WIDTH-TAG_WIDTH-1 : $clog2(BLOCK_SIZE)];
    assign offset = l1_addr_i[$clog2(BLOCK_SIZE)-1 : 0];

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

    always_comb begin
        replace_way = '0;
        for (int i = 1; i < NUM_WAYS; i++) begin
            if (lru[index][i] < lru[index][replace_way]) begin
                replace_way = i;
            end
        end
        need_wb = valid[index][replace_way] && dirty[index][replace_way];
    end

    always_ff @(posedge clk) begin
        if (rst) begin
            for (int i = 0; i < NUM_SETS; i++) begin
                for (int j = 0; j < NUM_WAYS; j++) begin
                    lru[i][j] <= j;
                end
            end
        end 
        else if (hit && (l1_rd_en_i || l1_wr_en_i)) begin
            for (int i = 0; i < NUM_WAYS; i++) begin
                if (i == hit_way)
                    lru[index][i] <= NUM_WAYS - 1;
                else if (lru[index][i] > lru[index][hit_way])
                    lru[index][i] <= lru[index][i] - 1;
            end
        end
        else if (!hit && l3_cache_valid_i) begin
            for (int i = 0; i < NUM_WAYS; i++) begin
                if (i == replace_way)
                    lru[index][i] <= NUM_WAYS - 1;
                else if (lru[index][i] > lru[index][replace_way])
                    lru[index][i] <= lru[index][i] - 1;
            end
        end
    end

    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            for (int i = 0; i < NUM_SETS; i++) begin
                for (int j = 0; j < NUM_WAYS; j++) begin
                    valid[i][j] <= 1'b0;
                    dirty[i][j] <= 1'b0;
                    cache_tags[i][j] <= '0;
                    cache_data[i][j] <= '0;
                end
            end
            l3_rd_en_o <= 1'b0;
            l3_wr_en_o <= 1'b0;
            l3_addr_o <= '0;
            l3_wr_data_o <= '0;
        end 
        else begin
            l3_rd_en_o <= 1'b0;
            l3_wr_en_o <= 1'b0;

            if (l1_wr_en_i || l1_rd_en_i) begin
                if (!hit) begin
                    if (need_wb) begin
                        l3_wr_en_o <= 1'b1;
                        l3_addr_o <= {cache_tags[index][replace_way], index, {$clog2(BLOCK_SIZE){1'b0}}};
                        l3_wr_data_o <= cache_data[index][replace_way];
                    end
                    l3_rd_en_o <= 1'b1;
                    l3_addr_o <= l1_addr_i;
                    
                    if (l3_cache_valid_i) begin
                        cache_tags[index][replace_way] <= tag;
                        cache_data[index][replace_way] <= l3_cache_data_i;
                        valid[index][replace_way] <= 1'b1;
                        dirty[index][replace_way] <= l1_wr_en_i;
                    end
                end
            end

            if (l1_wr_en_i && (hit || l3_cache_valid_i)) begin
                logic [$clog2(NUM_WAYS)-1:0] way_to_write;
                way_to_write = hit ? hit_way : replace_way;
                
                for (int i = 0; i < 4; i++) begin
                    if (l1_byte_en_i[i]) begin
                        cache_data[index][way_to_write][i*8 +: 8] <= l1_wr_data_i[i*8 +: 8];
                    end
                end
                dirty[index][way_to_write] <= 1'b1;
            end
        end
    end

    always_comb begin
        if (hit)
            rd_data = cache_data[index][hit_way];
        else if (l3_cache_valid_i)
            rd_data = l3_cache_data_i;
        else
            rd_data = '0;
    end

    assign l1_cache_hit_o = hit;
    assign l1_rd_data_o = rd_data;

endmodule