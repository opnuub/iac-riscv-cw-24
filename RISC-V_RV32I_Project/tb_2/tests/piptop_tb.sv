module top_tb;

    // Parameters
    parameter DATA_WIDTH = 32;
    parameter INSTR_WIDTH = 32;
    parameter ADDR_WIDTH = 32;
    parameter MEM_ADDR_WIDTH = 17;
    parameter REG_DATA_WIDTH = 5;
    parameter OFFSET = 4;

    // Signals
    logic clk, rst, trigger;
    logic [DATA_WIDTH-1:0] a0;

    // Instantiate the DUT (Device Under Test)
    top #(
        .DATA_WIDTH(DATA_WIDTH),
        .INSTR_WIDTH(INSTR_WIDTH),
        .ADDR_WIDTH(ADDR_WIDTH),
        .MEM_ADDR_WIDTH(MEM_ADDR_WIDTH),
        .REG_DATA_WIDTH(REG_DATA_WIDTH),
        .OFFSET(OFFSET)
    ) uut (
        .clk(clk),
        .rst(rst),
        .trigger(trigger),
        .a0(a0)
    );

    // Clock generation
    initial clk = 0;
    always #5 clk = ~clk; // 10ns clock period

    // Test sequence
    initial begin
        $display("Starting pipelined RISC-V CPU test...");

        // Test case 1: Reset behavior
        rst = 1;
        trigger = 0;
        @(posedge clk);
        rst = 0;
        if (a0 !== 0) $fatal("Test case 1 failed: Reset failed to clear output!");

        // Test case 2: Basic instruction propagation
        trigger = 1;
        repeat(5) @(posedge clk); // Allow a few cycles for pipeline to fill
        trigger = 0;
        @(posedge clk);
        if (a0 === 0) $fatal("Test case 2 failed: Instruction propagation failed!");

        // Test case 3: Check pipeline synchronization
        repeat(10) @(posedge clk);
        if (uut.PRegDecode.rd1E !== uut.PRegFetch.InstrD[19:15])
            $fatal("Test case 3 failed: Pipeline synchronization error (Decode Stage)!");
        if (uut.PRegExecute.ALUResultM !== uut.alu.aluResult)
            $fatal("Test case 3 failed: Pipeline synchronization error (Execute Stage)!");
        if (uut.PRegMemory.ALUResultW !== uut.PRegExecute.ALUResultM)
            $fatal("Test case 3 failed: Pipeline synchronization error (Memory Stage)!");

        // Test case 4: Branching and jumping
        uut.controlUnit.pcSrc = 1; // Simulate a branch taken
        @(posedge clk);
        if (uut.pcReg.pc !== uut.PRegDecode.PCe) $fatal("Test case 4 failed: Branching not working!");
        uut.controlUnit.jumpSrc = 1; // Simulate a jump
        @(posedge clk);
        if (uut.pcReg.pc !== uut.extendPC.result) $fatal("Test case 4 failed: Jumping not working!");

        // Test case 5: Memory access and write-back
        uut.DataMemory.MemWrite = 1; // Simulate a memory write
        uut.PRegMemory.RegWriteW = 1; // Enable write-back
        uut.DataMemory.WriteData = 32'hCAFEBABE;
        @(posedge clk);
        if (uut.DataMemory.ReadData !== 32'hCAFEBABE)
            $fatal("Test case 5 failed: Memory write-back failed!");
        if (uut.a0 !== uut.DataMemory.ReadData)
            $fatal("Test case 5 failed: Write-back to register file failed!");

        // Test case 6: Stalling and forwarding
        uut.PRegDecode.rd1E = uut.PRegExecute.ALUResultM; // Simulate forwarding
        @(posedge clk);
        if (uut.alu.srcA !== uut.PRegExecute.ALUResultM)
            $fatal("Test case 6 failed: Forwarding mechanism failed!");
        uut.PRegDecode.rd1E = 0; // Simulate stalling
        repeat(2) @(posedge clk);
        if (uut.PRegDecode.rd1E !== 0) $fatal("Test case 6 failed: Stalling failed!");

        $display("All test cases passed!");
        $finish;
    end

endmodule
