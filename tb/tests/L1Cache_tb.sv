module L1Cache_tb;
    parameter ADDR_WIDTH = 32;
    parameter DATA_WIDTH = 32;


    reg clk;
    reg rst;
    reg [ADDR_WIDTH-1:0] address;
    reg [DATA_WIDTH-1:0] write_data;
    reg read_enable;
    reg write_enable;
    wire [DATA_WIDTH-1:0] read_data;
    wire hit;


    L1Cache #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) dut (
        .clk(clk),
        .rst(rst),
        .address(address),
        .write_data(write_data),
        .read_enable(read_enable),
        .write_enable(write_enable),
        .read_data(read_data),
        .hit(hit)
    );

    initial begin
        clk = 0;
        forever #5 clk = ~clk;  
    end


    initial begin
        rst = 1;
        address = 0;
        write_data = 0;
        read_enable = 0;
        write_enable = 0;


        #10 rst = 0;
        $display("Reset complete");


        address = 32'h00000010;  
        write_data = 32'hDEADBEEF;  
        write_enable = 1;
        #10 write_enable = 0;  
        $display("Write operation complete. Address: %h, Data: %h", address, write_data);

        // Test case 2: Read data from the cache (Hit)
        read_enable = 1;
        #10 read_enable = 0;  
        if (hit) begin
            $display("Read Hit. Address: %h, Data: %h", address, read_data);
        end else begin
            $display("Read Miss. Address: %h", address);
        end

        // Test case 3: Access an address not in the cache (Miss)
        address = 32'h00000020;  
        read_enable = 1;
        #10 read_enable = 0;  
        if (hit) begin
            $display("Read Hit. Address: %h, Data: %h", address, read_data);
        end else begin
            $display("Read Miss. Address: %h", address);
        end

        $finish;
    end

endmodule
