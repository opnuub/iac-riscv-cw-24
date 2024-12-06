module DataMemory_tb;

    // Testbench signals
    logic clk;
    logic [2:0] SizeCtr;        // Size control
    logic [9:0] ALUResult;      // Address (10 bits for the given parameter)
    logic [31:0] WriteData;     // Data to be written
    logic MemWrite;             // Memory write enable
    logic [31:0] ReadData;      // Data read from memory

    // Instantiate the DataMemory module
    DataMemory #(
        .DATA_WIDTH(32),
        .ADDR_WIDTH(10)
    ) uut (
        .clk(clk),
        .SizeCtr(SizeCtr),
        .ALUResult(ALUResult),
        .WriteData(WriteData),
        .MemWrite(MemWrite),
        .ReadData(ReadData)
    );

    // Clock generation
    initial begin
        clk = 0;
        forever #5 clk = ~clk; // 100 MHz clock
    end

    // Test sequence
    initial begin
        $display("Starting DataMemory Testbench...");

        // Initialize inputs
        MemWrite = 0;
        SizeCtr = 3'b000; // Default size
        ALUResult = 0;
        WriteData = 0;

        // Reset phase
        $display("Resetting...");
        #10;

        // Test case 1: Write and read a word
        $display("Test 1: Write and Read a Word");
        SizeCtr = 3'b010;  // Word
        ALUResult = 10'd0; // Address 0
        WriteData = 32'hAABBCCDD;
        MemWrite = 1;
        #10; // Wait for a clock edge
        MemWrite = 0; // Disable writing
        #10; // Allow ReadData to settle
        if (ReadData !== 32'hAABBCCDD) begin
            $error("Test 1 Failed: Expected 0xAABBCCDD, got 0x%h", ReadData);
        end else begin
            $display("Test 1 Passed");
        end

        // Test case 2: Write and read a byte
        $display("Test 2: Write and Read a Byte");
        SizeCtr = 3'b000;  // Byte
        ALUResult = 10'd1; // Address 1
        WriteData = 32'h00000011;
        MemWrite = 1;
        #10;
        MemWrite = 0;
        #10;
        if (ReadData[7:0] !== 8'h11) begin
            $error("Test 2 Failed: Expected 0x11, got 0x%h", ReadData[7:0]);
        end else begin
            $display("Test 2 Passed");
        end

        // Test case 3: Load halfword unsigned
        $display("Test 3: Load Halfword Unsigned");
        SizeCtr = 3'b101; // Unsigned halfword
        ALUResult = 10'd0; // Address 0
        if (ReadData[15:0] !== 16'hCCDD) begin
            $error("Test 3 Failed: Expected 0xCCDD, got 0x%h", ReadData[15:0]);
        end else begin
            $display("Test 3 Passed");
        end

        $display("All tests completed.");
        $finish;
    end
endmodule
