#include <gtest/gtest.h>
#include "VPRegMemory.h"  // Verilator-generated class for PRegMemory
#include "verilated.h"

class PRegMemoryTest : public ::testing::Test {
protected:
    VPRegMemory* dut;

    void SetUp() override {
        Verilated::traceEverOn(true);
        dut = new VPRegMemory();
        dut->clk = 0; // Initialize clock
        dut->eval();
    }

    void TearDown() override {
        delete dut;
    }

    void toggleClock() {
        dut->clk = !dut->clk; // Toggle clock
        dut->eval();
    }

    void advanceClock() {
        toggleClock(); // Rising edge
        toggleClock(); // Falling edge
    }
};

TEST_F(PRegMemoryTest, TestInitialValues) {
    // Check that all outputs are zero-initialized
    EXPECT_EQ(dut->ALUResultW, 0);
    EXPECT_EQ(dut->WriteDataW, 0);
    EXPECT_EQ(dut->RdW, 0);
    EXPECT_EQ(dut->PCPlus4W, 0);
    EXPECT_EQ(dut->RegWriteW, 0);
    EXPECT_EQ(dut->ResultSrcW, 0);
}

TEST_F(PRegMemoryTest, TestLoadingValues) {
    // Apply inputs
    dut->ALUResultM = 0xDEADBEEF;
    dut->DMRd = 0xCAFEBABE;
    dut->RdM = 0x1F;
    dut->PCPlus4M = 0xABCDEF01;
    dut->RegWriteM = 1;
    dut->ResultSrcM = 2;

    advanceClock(); // Advance one clock cycle

    // Check outputs
    EXPECT_EQ(dut->ALUResultW, 0xDEADBEEF);
    EXPECT_EQ(dut->WriteDataW, 0xCAFEBABE);
    EXPECT_EQ(dut->RdW, 0x1F);
    EXPECT_EQ(dut->PCPlus4W, 0xABCDEF01);
    EXPECT_EQ(dut->RegWriteW, 1);
    EXPECT_EQ(dut->ResultSrcW, 2);
}

TEST_F(PRegMemoryTest, TestOverwritingValues) {
    // Apply new inputs
    dut->ALUResultM = 0xA5A5A5A5;
    dut->DMRd = 0x5A5A5A5A;
    dut->RdM = 0x0A;
    dut->PCPlus4M = 0x12345678;
    dut->RegWriteM = 0;
    dut->ResultSrcM = 1;

    advanceClock(); // Advance one clock cycle

    // Check outputs
    EXPECT_EQ(dut->ALUResultW, 0xA5A5A5A5);
    EXPECT_EQ(dut->WriteDataW, 0x5A5A5A5A);
    EXPECT_EQ(dut->RdW, 0x0A);
    EXPECT_EQ(dut->PCPlus4W, 0x12345678);
    EXPECT_EQ(dut->RegWriteW, 0);
    EXPECT_EQ(dut->ResultSrcW, 1);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
