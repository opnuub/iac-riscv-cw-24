module JalrMux #(
    parameter ADDR_WIDTH = 32
) (
    input   logic [ADDR_WIDTH-1:0]  Rd1E,
    input   logic [ADDR_WIDTH-1:0]  PcE,
    input   logic                   JalrE,
    output  logic [ADDR_WIDTH-1:0]  PCEn
);
    assign PCEn = JalrE ? Rd1E : PcE;
    
endmodule
