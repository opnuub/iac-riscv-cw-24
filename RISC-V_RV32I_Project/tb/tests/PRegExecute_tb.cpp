#include <gtest/gtest.h>
#include "VPRegExecute.h"  // Verilator-generated class for PRegExecute
#include "verilated.h"

class PRegExecuteTest : public ::testing::Test {
protected:
    VPRegExecute* dut;

    void SetUp() override {
        Verilated::traceEverOn(true);
        dut = new VPRegExecute();
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

TEST_F(PRegExecuteTest, TestInitialValues) {
    // Check that all outputs are zero-initialized
    EXPECT_EQ(dut->ALUResultM, 0);
    EXPECT_EQ(dut->WriteDataM, 0);
    EXPECT_EQ(dut->PCPlus4M, 0);
    EXPECT_EQ(dut->RdM, 0);
    EXPECT_EQ(dut->RegWriteM, 0);
    EXPECT_EQ(dut->ResultSrcM, 0);
    EXPECT_EQ(dut->MemWriteM, 0);
}

TEST_F(PRegExecuteTest, TestLoadingValues) {
    // Apply inputs
    dut->ALUout = 0xDEADBEEF;
    dut->WriteData = 0xCAFEBABE;
    dut->PCPlus4E = 0xABCDEF01;
    dut->RdE = 0x1F;
    dut->RegWriteE = 1;
    dut->ResultSrcE = 2;
    dut->MemWriteE = 0;

    advanceClock(); // Advance one clock cycle

    // Check outputs
    EXPECT_EQ(dut->ALUResultM, 0xDEADBEEF);
    EXPECT_EQ(dut->WriteDataM, 0xCAFEBABE);
    EXPECT_EQ(dut->PCPlus4M, 0xABCDEF01);
    EXPECT_EQ(dut->RdM, 0x1F);
    EXPECT_EQ(dut->RegWriteM, 1);
    EXPECT_EQ(dut->ResultSrcM, 2);
    EXPECT_EQ(dut->MemWriteM, 0);
}

TEST_F(PRegExecuteTest, TestOverwritingValues) {
    // Apply new inputs
    dut->ALUout = 0xA5A5A5A5;
    dut->WriteData = 0x5A5A5A5A;
    dut->PCPlus4E = 0x12345678;
    dut->RdE = 0x0A;
    dut->RegWriteE = 0;
    dut->ResultSrcE = 1;
    dut->MemWriteE = 1;

    advanceClock(); // Advance one clock cycle

    // Check outputs
    EXPECT_EQ(dut->ALUResultM, 0xA5A5A5A5);
    EXPECT_EQ(dut->WriteDataM, 0x5A5A5A5A);
    EXPECT_EQ(dut->PCPlus4M, 0x12345678);
    EXPECT_EQ(dut->RdM, 0x0A);
    EXPECT_EQ(dut->RegWriteM, 0);
    EXPECT_EQ(dut->ResultSrcM, 1);
    EXPECT_EQ(dut->MemWriteM, 1);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}