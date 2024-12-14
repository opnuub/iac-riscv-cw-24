#include <verilated.h>
#include <verilated_vcd_c.h>
#include <gtest/gtest.h>
#include "VbranchUnit.h" // Auto-generated header file for the DUT

class BranchUnitTest : public ::testing::Test {
protected:
    VbranchUnit *dut;              // DUT instance
    VerilatedVcdC *trace;          // Trace for waveform
    uint64_t simulation_time = 0;  // Simulation time in Verilator

    void SetUp() override {
        Verilated::traceEverOn(true);   // Enable tracing
        dut = new VbranchUnit;         // Initialize DUT
        trace = new VerilatedVcdC;
        dut->trace(trace, 99);         // Set trace depth
        trace->open("branchUnit.vcd"); // Open trace file
    }

    void TearDown() override {
        dut->final();   // Finalize DUT
        trace->close(); // Close trace file
        delete dut;     // Clean up
        delete trace;
    }

    void step() {
        simulation_time += 1;          // Increment simulation time (1ns step)
        dut->eval();                   // Evaluate the DUT
        trace->dump(simulation_time);  // Dump waveform at current time
    }

    void setInputs(uint32_t srcA, uint32_t srcB, uint8_t aluControl) {
        dut->srcA = srcA;
        dut->srcB = srcB;
        dut->aluControl = aluControl;
        step();
    }
};
/*
// Test cases
TEST_F(BranchUnitTest, TestBeq) {
    // BEQ: srcA == srcB
    setInputs(10, 10, 0b1000); // aluControl = BEQ
    EXPECT_EQ(dut->zero, 1);   // zero 应为 1

    // BEQ: srcA != srcB
    setInputs(10, 5, 0b1000);
    EXPECT_EQ(dut->zero, 0);   // zero 应为 0
}

TEST_F(BranchUnitTest, TestBne) {
    // BNE: srcA != srcB
    setInputs(10, 5, 0b1001); // aluControl = BNE
    EXPECT_EQ(dut->zero, 1);  // zero 应为 1

    // BNE: srcA == srcB
    setInputs(10, 10, 0b1001);
    EXPECT_EQ(dut->zero, 0);  // zero 应为 0
}

TEST_F(BranchUnitTest, TestSignedComparison) {
    // Signed less than: srcA < srcB
    setInputs(-10, 5, 0b1100); // aluControl = Signed Less Than
    EXPECT_EQ(dut->zero, 1);   // zero 应为 1

    // Signed greater or equal: srcA >= srcB
    setInputs(10, -5, 0b1101); // aluControl = Signed Greater or Equal
    EXPECT_EQ(dut->zero, 1);   // zero 应为 1
}

TEST_F(BranchUnitTest, TestUnsignedComparison) {
    // Unsigned less than: srcA < srcB
    setInputs(10, 20, 0b1110); // aluControl = Unsigned Less Than
    EXPECT_EQ(dut->zero, 1);   // zero 应为 1

    // Unsigned greater or equal: srcA >= srcB
    setInputs(30, 20, 0b1111); // aluControl = Unsigned Greater or Equal
    EXPECT_EQ(dut->zero, 1);   // zero 应为 1
}
*/
TEST_F(BranchUnitTest, TestDefaultCase) {
    // Default case
    setInputs(10, 10, 0b0000); // aluControl = Default
    EXPECT_EQ(dut->zero, 0);   // zero 应为 0
}