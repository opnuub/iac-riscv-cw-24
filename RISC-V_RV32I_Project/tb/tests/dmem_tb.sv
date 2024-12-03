module dmem_tb;

  logic clk, rst_ni, wen_i, signed_i;
  logic [2:0] size_i;
  logic [31:0] addr_i, wdata_i, rdata_o;

  dmem uut (
    .clk_i(clk),
    .rst_ni(rst_ni),
    .wen_i(wen_i),
    .size_i(size_i),
    .signed_i(signed_i),
    .addr_i(addr_i),
    .wdata_i(wdata_i),
    .rdata_o(rdata_o)
  );

  initial begin
    rst_ni = 0; wen_i = 0; signed_i = 1;
    addr_i = 32'h0; wdata_i = 32'hAABBCCDD; size_i = 3'b010;
    #10 rst_ni = 1; wen_i = 1;
    #10 wen_i = 0;
    assert(uut.mem[0] == 8'hDD) else $error("Write failed");
    assert(uut.mem[1] == 8'hCC) else $error("Write failed");
    #10 $finish;
  end

  always #5 clk = ~clk; 
endmodule