module clktick # (
    parameter DATA_WIDTH = 32
)   (
    input   logic [DATA_WIDTH-1:0]  N,
    input   logic [3:0]             random_delay,
    input   logic [DATA_WIDTH-1:0]  a0,
    input   logic                   rst,
    input   logic                   clk_i,
    output  logic                   clk_o
);

    logic [DATA_WIDTH-1:0] count;

    always_ff @ (posedge clk_i)
        if (rst) begin
            clk_o <= 1'b1;
            count <= 0;
        end
        else begin
            if (count == 0 && a0 == 32'h7F) begin
                clk_o <= 1'b1;
                count <= N+(N*random_delay)/3;
            end
            else if (count == 0 && a0 != 32'h7F) begin
                clk_o <= 1'b1;
                count <= N;
            end
            else begin
                clk_o <= 1'b0;
                count <= count - 1'b1;
            end
        end    
endmodule
