module dmem (
    input  logic        clk_i,
    input  logic        rst_ni,
    
    input  logic        wen_i,       
    input  logic [2:0]  size_i,      
    input  logic        signed_i,    
    input  logic [31:0] addr_i,      
    input  logic [31:0] wdata_i,     
    output logic [31:0] rdata_o  
);

    logic [7:0] mem [0:8191];
    logic [31:0] rdata_aligned;

    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni) begin
            for (int i = 0; i < 8192; i++) begin
                mem[i] <= 8'b0;
            end
        end else if (wen_i) begin
            case (size_i)
                3'b000: begin
                    mem[addr_i] <= wdata_i[7:0];
                end
                3'b001: begin 
                    if (addr_i + 1 < 8192) begin
                        mem[addr_i] <= wdata_i[7:0];
                        mem[addr_i + 1] <= wdata_i[15:8];
                    end
                end
                3'b010: begin 
                    if (addr_i + 3 < 8192) begin
                        mem[addr_i] <= wdata_i[7:0];
                        mem[addr_i + 1] <= wdata_i[15:8];
                        mem[addr_i + 2] <= wdata_i[23:16];
                        mem[addr_i + 3] <= wdata_i[31:24];
                    end
                end
                default: ; 
            endcase
        end
    end


    always_comb begin
        case (size_i)
            3'b000: begin 
                rdata_aligned = {{24{signed_i & mem[addr_i][7]}}, mem[addr_i]};
            end
            3'b001: begin
                if (addr_i + 1 < 8192) begin
                    rdata_aligned = {{16{signed_i & mem[addr_i + 1][7]}}, 
                                     mem[addr_i + 1], mem[addr_i]};
                end else begin
                    rdata_aligned = 32'b0; 
                end
            end
            3'b010: begin 
                if (addr_i + 3 < 8192) begin
                    rdata_aligned = {mem[addr_i + 3], mem[addr_i + 2], 
                                     mem[addr_i + 1], mem[addr_i]};
                end else begin
                    rdata_aligned = 32'b0; 
                end
            end
            default: rdata_aligned = 32'b0; 
        endcase
    end

    assign rdata_o = rdata_aligned;

endmodule