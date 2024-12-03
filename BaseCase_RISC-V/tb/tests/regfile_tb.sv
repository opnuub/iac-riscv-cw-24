module regfile_tb;

  logic clk_i, rst_ni;
  logic wen_i;
  logic [4:0] waddr_i, raddr1_i, raddr2_i;
  logic [31:0] wdata_i;


  logic [31:0] rdata1_o, rdata2_o;

  regfile uut (
    .clk_i     (clk_i),
    .rst_ni    (rst_ni),
    .wen_i     (wen_i),
    .waddr_i   (waddr_i),
    .wdata_i   (wdata_i),
    .raddr1_i  (raddr1_i),
    .rdata1_o  (rdata1_o),
    .raddr2_i  (raddr2_i),
    .rdata2_o  (rdata2_o)
  );

  initial clk_i = 0;
  always #5 clk_i = ~clk_i; 

  initial begin
    $display("Starting regfile_tb...");

    // Reset test
    rst_ni = 0;
    #10;
    rst_ni = 1;

    // Test write operation
    wen_i = 1;
    waddr_i = 5'd1;
    wdata_i = 32'hDEADBEEF;
    #10;
    wen_i = 0;

    // Test read operation
    raddr1_i = 5'd1;
    raddr2_i = 5'd2; // Default zero
    #10;
    assert(rdata1_o == 32'hDEADBEEF) else $fatal("Read failed for raddr1!");
    assert(rdata2_o == 32'd0) else $fatal("Read failed for raddr2!");

    // Test zero register behavior
    waddr_i = 5'd0;
    wdata_i = 32'hFFFFFFFF;
    wen_i = 1;
    #10;
    wen_i = 0;
    raddr1_i = 5'd0;
    #10;
    assert(rdata1_o == 32'd0) else $fatal("Zero register write failed!");

    $display("regfile_tb passed!");
    $finish;
  end

endmodule
