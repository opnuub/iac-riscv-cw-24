module regfile (
    input  logic        clk_i,
    input  logic        rst_ni,
    
    // Write port
    input  logic        wen_i,
    input  logic [4:0]  waddr_i,
    input  logic [31:0] wdata_i,
    
    // Read port 1
    input  logic [4:0]  raddr1_i,
    output logic [31:0] rdata1_o,
    
    // Read port 2
    input  logic [4:0]  raddr2_i,
    output logic [31:0] rdata2_o,
    
    // Output a0 register value
    output logic [31:0] a0_o
);

// Register file storage
logic [31:0] rf_reg [32];

// Write operation
always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
        for (int i = 0; i < 32; i++) begin
            rf_reg[i] <= 32'b0;
        end
    end else if (wen_i && (waddr_i != 5'b0)) begin
        rf_reg[waddr_i] <= wdata_i;
    end
end

// Read operations
always_comb begin
    // Read port 1
    rdata1_o = (raddr1_i == 5'b0) ? 32'b0 : rf_reg[raddr1_i];
    
    // Read port 2
    rdata2_o = (raddr2_i == 5'b0) ? 32'b0 : rf_reg[raddr2_i];
end

// Assign a0 register value
assign a0_o = rf_reg[10]; // a0 is x10

endmodule
