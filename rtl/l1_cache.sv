module l1_cache #(
    parameter ADDR_WIDTH = 32,
    parameter DATA_WIDTH = 32,
    parameter BLOCK_SIZE = 4,
    parameter NUM_SETS = 256,
    parameter NUM_WAYS = 4,
    parameter TAG_WIDTH = ADDR_WIDTH - $clog2(NUM_SETS) - $clog2(BLOCK_SIZE)
) (
    input  logic                        clk,
    input  logic                        rst,
    input  logic                        wr_en_i,
    input  logic [ADDR_WIDTH-1:0]       addr_i,
    input  logic [DATA_WIDTH-1:0]       wr_data_i,
    input  logic [3:0]                  byte_en_i,
    input  logic                        l2_cache_valid_i,
    input  logic [DATA_WIDTH-1:0]       l2_cache_data_i,
    output logic [DATA_WIDTH-1:0]       l1_rd_data_o,
    output logic                        l1_cache_hit_o
);
    // Cache storage
    logic [DATA_WIDTH-1:0] cache_data [NUM_SETS-1:0][NUM_WAYS-1:0];
    logic [TAG_WIDTH-1:0]  cache_tags [NUM_SETS-1:0][NUM_WAYS-1:0];
    logic                  valid [NUM_SETS-1:0][NUM_WAYS-1:0];
    logic [1:0]            lru [NUM_SETS-1:0][NUM_WAYS-1:0];

    // Address breakdown
    logic [TAG_WIDTH-1:0]                tag;
    logic [$clog2(NUM_SETS)-1:0]         index;
    logic [$clog2(BLOCK_SIZE)-1:0]       offset;

    // Cache operation signals
    logic                                hit;
    logic [$clog2(NUM_WAYS)-1:0]         hit_way;
    logic [$clog2(NUM_WAYS)-1:0]         replace_way;
    logic [DATA_WIDTH-1:0]               rd_data;

    // Address breakdown
    assign tag = addr_i[ADDR_WIDTH-1 : ADDR_WIDTH-TAG_WIDTH];
    assign index = addr_i[ADDR_WIDTH-TAG_WIDTH-1 : $clog2(BLOCK_SIZE)];
    assign offset = addr_i[$clog2(BLOCK_SIZE)-1 : 0];

    // Hit detection
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

    // Replacement way selection
    always_comb begin
        replace_way = '0;
        for (int i = 0; i < NUM_WAYS; i++) begin
            if (!valid[index][i]) begin
                replace_way = i;
                break;
            end
        end
        if (valid[index][replace_way]) begin
            for (int i = 1; i < NUM_WAYS; i++) begin
                if (lru[index][i] < lru[index][replace_way]) begin
                    replace_way = i;
                end
            end
        end
    end

    // LRU update logic
    always_ff @(posedge clk) begin
        if (rst) begin
            for (int i = 0; i < NUM_SETS; i++) begin
                for (int j = 0; j < NUM_WAYS; j++) begin
                    lru[i][j] <= 0;
                end
            end
        end 
        else if (hit) begin
            for (int i = 0; i < NUM_WAYS; i++) begin
                if (i == hit_way)
                    lru[index][i] <= NUM_WAYS - 1;
                else if (lru[index][i] > lru[index][hit_way])
                    lru[index][i] <= lru[index][i] - 1;
            end
        end
    end

    // Cache update logic - Simplified based on new rules
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            for (int i = 0; i < NUM_SETS; i++) begin
                for (int j = 0; j < NUM_WAYS; j++) begin
                    valid[i][j] <= 1'b0;
                    cache_tags[i][j] <= '0;
                    cache_data[i][j] <= '0;
                end
            end
        end 
        else begin
            if (wr_en_i) begin
                if (hit) begin
                    // On hit, write data to cache
                    for (int i = 0; i < 4; i++) begin
                        if (byte_en_i[i]) begin
                            cache_data[index][hit_way][i*8 +: 8] <= wr_data_i[i*8 +: 8];
                        end
                    end
                end 
            end 
            else if (!hit && l2_cache_valid_i) begin
                // On miss with valid next level data, write to cache
                cache_tags[index][replace_way] <= tag;
                cache_data[index][replace_way] <= l2_cache_data_i;
                valid[index][replace_way] <= 1'b1;
            end
        end
    end

    // Read data selection
    always_comb begin
        if (hit)
            rd_data = cache_data[index][hit_way];
        else if (l2_cache_valid_i)
            rd_data = l2_cache_data_i;
        else
            rd_data = '0;
    end

    // Output assignments
    assign l1_cache_hit_o = hit;
    assign l1_rd_data_o = rd_data;

endmodule