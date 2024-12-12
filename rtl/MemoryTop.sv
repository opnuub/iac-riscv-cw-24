module MemoryTop #(
    parameter ADDR_WIDTH = 32,
    parameter DATA_WIDTH = 32,
    parameter MEM_ADDR_WIDTH = 17
) (
    input  logic                        clk,
    input  logic                        rst,
    input  logic                        mem_write_i,
    input  logic [2:0]                  size_src_i,
    input  logic [ADDR_WIDTH-1:0]       addr_i,
    input  logic [DATA_WIDTH-1:0]       write_data_i,
    output logic [DATA_WIDTH-1:0]       read_data_o,
    output logic                        data_valid_o
);
    logic l1_hit, l2_hit, l3_hit;
    logic l1_rd_en, l1_wr_en;
    logic l2_rd_en, l2_wr_en;
    logic l3_rd_en, l3_wr_en;
    logic mem_rd_en, mem_wr_en;
    logic mem_ready;

    logic [DATA_WIDTH-1:0] l1_rd_data, l2_rd_data, l3_rd_data, mem_rd_data;
    logic [3:0] byte_en;

    always_comb begin
        case (size_src_i)
            3'b000: byte_en = 4'b0001;
            3'b001: byte_en = 4'b0011;
            3'b010: byte_en = 4'b1111;
            default: byte_en = 4'b0000;
        endcase
    end

    always_comb begin
        {l1_rd_en, l1_wr_en} = 2'b00;
        {l2_rd_en, l2_wr_en} = 2'b00;
        {l3_rd_en, l3_wr_en} = 2'b00;
        {mem_rd_en, mem_wr_en} = 2'b00;

        if (!l1_hit && !l2_hit && !l3_hit) begin
            mem_rd_en = !mem_write_i;
            mem_wr_en = mem_write_i;
        end else if (!l1_hit && !l2_hit) begin
            l3_rd_en = !mem_write_i;
            l3_wr_en = mem_write_i;
        end else if (!l1_hit) begin
            l2_rd_en = !mem_write_i;
            l2_wr_en = mem_write_i;
        end else begin
            l1_rd_en = !mem_write_i;
            l1_wr_en = mem_write_i;
        end
    end

    always_comb begin
        if (l1_hit)
            read_data_o = l1_rd_data;
        else if (l2_hit)
            read_data_o = l2_rd_data;
        else if (l3_hit)
            read_data_o = l3_rd_data;
        else if (mem_ready)
            read_data_o = mem_rd_data;
        else
            read_data_o = '0;

        data_valid_o = l1_hit || l2_hit || l3_hit || 
                      (mem_ready && (mem_rd_en || mem_wr_en));
    end

    l1_cache #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) l1_cache_inst (
        .clk                (clk),
        .rst                (rst),
        .wr_en_i            (l1_wr_en),
        .addr_i             (addr_i),
        .wr_data_i          (write_data_i),
        .byte_en_i          (byte_en),
        .l2_cache_valid_i   (l2_hit),
        .l2_cache_data_i    (l2_rd_data),
        .l1_rd_data_o       (l1_rd_data),
        .l1_cache_hit_o     (l1_hit)
    );

    l2_cache #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) l2_cache_inst (
        .clk                (clk),
        .rst                (rst),
        .l1_rd_en_i         (l2_rd_en),
        .l1_wr_en_i         (l2_wr_en),
        .l1_addr_i          (addr_i),
        .l1_wr_data_i       (write_data_i),
        .l1_byte_en_i       (byte_en),
        .l1_rd_data_o       (l2_rd_data),
        .l1_cache_hit_o     (l2_hit),
        .l3_cache_valid_i   (l3_hit),
        .l3_cache_data_i    (l3_rd_data),
        .l3_rd_en_o         (l2_to_l3_rd_en),
        .l3_wr_en_o         (l2_to_l3_wr_en),
        .l3_addr_o          (l2_addr),
        .l3_wr_data_o       (l2_wr_data)
    );

    l3_cache #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) l3_cache_inst (
        .clk                (clk),
        .rst                (rst),
        .l2_rd_en_i         (l3_rd_en),
        .l2_wr_en_i         (l3_wr_en),
        .l2_addr_i          (addr_i),
        .l2_wr_data_i       (write_data_i),
        .l2_byte_en_i       (byte_en),
        .l2_rd_data_o       (l3_rd_data),
        .l2_cache_hit_o     (l3_hit),
        .mem_valid_i        (mem_ready),
        .mem_data_i         (mem_rd_data),
        .mem_rd_en_o        (l3_to_mem_rd_en),
        .mem_wr_en_o        (l3_to_mem_wr_en),
        .mem_addr_o         (l3_addr),
        .mem_wr_data_o      (l3_wr_data)
    );

    DataMemory #(
        .DATA_WIDTH(DATA_WIDTH),
        .ADDR_WIDTH(MEM_ADDR_WIDTH)
    ) data_memory (
        .clk            (clk),
        .SizeCtr        (size_src_i),
        .ALUResult      (addr_i[MEM_ADDR_WIDTH-1:0]),
        .WriteData      (write_data_i),
        .MemWrite       (mem_wr_en),
        .ReadData       (mem_rd_data)
    );

    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            mem_ready <= 1'b0;
        end else begin
            mem_ready <= mem_rd_en || mem_wr_en;
        end
    end

endmodule