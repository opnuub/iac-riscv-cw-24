module imem_tb;
    localparam ADDR_WIDTH = 32;
    localparam INSTR_WIDTH = 32;

    logic                   clk_i;
    logic [ADDR_WIDTH-1:0]  addr_i;
    logic [INSTR_WIDTH-1:0] rdata_o;
    
    logic [7:0] test_data [4096];
    
    initial begin
        clk_i = 0;
        forever #5 clk_i = ~clk_i;
    end

    imem dut (
        .clk_i(clk_i),
        .addr_i(addr_i),
        .rdata_o(rdata_o)
    );

    // Helper function to get expected instruction
    function logic [31:0] get_expected_instr(logic [31:0] addr);
        return {test_data[addr+3], test_data[addr+2], 
                test_data[addr+1], test_data[addr]};
    endfunction

    // Test stimulus
    initial begin
        $readmemh("/Users/michaelli/Documents/GitHub/iac-riscv-cw-24/RISC-V_RV32I_Project/rtl/program.hex", test_data);
        addr_i = '0;

        #10;

        // Test sequential addresses
        for (int i = 0; i < 16; i += 4) begin
            addr_i = i;
            @(posedge clk_i);
            @(negedge clk_i);
            if (rdata_o !== get_expected_instr(i)) begin
                $error("Mismatch at addr %0h: expected %h, got %h", 
                        i, get_expected_instr(i), rdata_o);
            end
        end

        addr_i = 'h5;
        @(posedge clk_i);
        @(negedge clk_i);
        if (rdata_o !== get_expected_instr('h4)) begin
            $error("Unaligned access failed");
        end

        $display("Test completed");
        $finish;
    end

endmodule