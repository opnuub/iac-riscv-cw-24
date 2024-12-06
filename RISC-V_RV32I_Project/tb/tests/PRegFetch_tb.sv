module PRegFetch_tb;

    parameter DATA_WIDTH = 32;
    parameter REG_DATA_WIDTH = 3;

    logic [DATA_WIDTH-1:0] instr;
    logic [DATA_WIDTH-1:0] PCf;
    logic [DATA_WIDTH-1:0] PCPlus4F;
    logic clk;
    logic [DATA_WIDTH-1:0] PCPlus4D;
    logic [DATA_WIDTH-1:0] PCd;
    logic [DATA_WIDTH-1:0] InstrD;

    // Instantiate the PRegFetch module
    PRegFetch #(
        .DATA_WIDTH(DATA_WIDTH),
        .REG_DATA_WIDTH(REG_DATA_WIDTH)
    ) uut (
        .instr(instr),
        .PCf(PCf),
        .PCPlus4F(PCPlus4F),
        .clk(clk),
        .PCPlus4D(PCPlus4D),
        .PCd(PCd),
        .InstrD(InstrD)
    );

    // Clock generation
    initial clk = 0;
    always #5 clk = ~clk; // Toggle clock every 5 time units

    // Test logic
    initial begin
        $display("Starting PRegFetch test...");

        // Test case 1: Write initial values and verify outputs
        instr = 32'hA5A5A5A5;
        PCf = 32'h12345678;
        PCPlus4F = 32'h87654321;
        @(posedge clk); // Wait for one clock cycle
        if (InstrD !== 32'hA5A5A5A5 || PCd !== 32'h12345678 || PCPlus4D !== 32'h87654321) begin
            $fatal("Test case 1 failed: Incorrect outputs after 1st clock cycle.");
        end

        // Test case 2: Overwrite values and verify outputs
        instr = 32'hFFFFFFFF;
        PCf = 32'h11111111;
        PCPlus4F = 32'h22222222;
        @(posedge clk); // Wait for one clock cycle
        if (InstrD !== 32'hFFFFFFFF || PCd !== 32'h11111111 || PCPlus4D !== 32'h22222222) begin
            $fatal("Test case 2 failed: Incorrect outputs after 2nd clock cycle.");
        end

        // Test case 3: Write new values and verify outputs
        instr = 32'h0;
        PCf = 32'h33333333;
        PCPlus4F = 32'h44444444;
        @(posedge clk); // Wait for one clock cycle
        if (InstrD !== 32'h0 || PCd !== 32'h33333333 || PCPlus4D !== 32'h44444444) begin
            $fatal("Test case 3 failed: Incorrect outputs after 3rd clock cycle.");
        end

        // Test case 4: Verify previous values remain correct in ROM (indirect check via outputs)
        instr = 32'h55555555;  // New input; these values won’t be stored until the next clock
        PCf = 32'h66666666;
        PCPlus4F = 32'h77777777;
        #2; // Hold inputs for a short duration without a clock tick
        if (uut.rom_array[3'b00] !== 32'h0 || uut.rom_array[3'b01] !== 32'h33333333 || uut.rom_array[3'b10] !== 32'h44444444) begin
            $fatal("Test case 4 failed: Previous ROM values incorrect before new clock cycle.");
        end

        @(posedge clk); // Now let the new values be stored
        if (uut.rom_array[3'b00] !== 32'h55555555 || uut.rom_array[3'b01] !== 32'h66666666 || uut.rom_array[3'b10] !== 32'h77777777) begin
            $fatal("Test case 5 failed: ROM values incorrect after new clock cycle.");
        end

        $display("All test cases passed.");
        $finish;
    end

endmodule
