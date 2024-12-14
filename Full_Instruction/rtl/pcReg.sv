module pcReg #(
    parameter OFFSET = 4,
    parameter ADDR_WIDTH = 32
) (
    input   logic [ADDR_WIDTH-1:0]  nextPC,
    input   logic                   clk,
    input   logic                   rst,    
    input   logic                   stall,    
    output  logic [ADDR_WIDTH-1:0]  PCPlus4F,
    output  logic [ADDR_WIDTH-1:0]  pc
);

    always_comb begin
        PCPlus4F = pc + OFFSET;
    end

    always_ff @ (posedge clk or posedge rst)
        if (rst)
            pc <= 32'hBFC00000; // instruction 
        else if (!stall)
            pc <= nextPC;

endmodule
