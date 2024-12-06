#include <gtest/gtest.h>
#include "VPRegDecode.h"  // Verilator-generated class for PRegDecode
#include "verilated.h"

class PRegDecodeTest : public ::testing::Test {
protected:
    VPRegDecode* dut;

    void SetUp() override {
        Verilated::traceEverOn(true);
        dut = new VPRegDecode();
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

TEST_F(PRegDecodeTest, TestInitialValues) {
    // Default values; ensure all outputs are initialized to zero
    EXPECT_EQ(dut->rd1E, 0);
    EXPECT_EQ(dut->rd2E, 0);
    EXPECT_EQ(dut->PCe, 0);
    EXPECT_EQ(dut->RdE, 0);
    EXPECT_EQ(dut->ImmExtE, 0);
    EXPECT_EQ(dut->PcPlus4E, 0);
    EXPECT_EQ(dut->RegWriteE, 0);
    EXPECT_EQ(dut->ResultSrcE, 0);
    EXPECT_EQ(dut->MemWriteE, 0);
    EXPECT_EQ(dut->JumpE, 0);
    EXPECT_EQ(dut->BranchE, 0);
    EXPECT_EQ(dut->ALUControlE, 0);
    EXPECT_EQ(dut->ALUSrcE, 0);
}

TEST_F(PRegDecodeTest, TestLoadingValues) {
    // Apply inputs
    dut->rd1 = 0xA5A5A5A5;
    dut->rd2 = 0x5A5A5A5A;
    dut->PCd = 0x12345678;
    dut->ImmExtD = 0x87654321;
    dut->RdD = 0x1F;
    dut->PCPlus4D = 0x11111111;
    dut->RegWriteD = 1;
    dut->ResultSrcD = 2;
    dut->MemWriteD = 1;
    dut->JumpD = 0;
    dut->BranchD = 1;
    dut->ALUControl = 5;  // 3'b101
    dut->ALUSrcD = 1;

    advanceClock(); // Advance one clock cycle

    // Check outputs
    EXPECT_EQ(dut->rd1E, 0xA5A5A5A5);
    EXPECT_EQ(dut->rd2E, 0x5A5A5A5A);
    EXPECT_EQ(dut->PCe, 0x12345678);
    EXPECT_EQ(dut->RdE, 0x1F);
    EXPECT_EQ(dut->ImmExtE, 0x87654321);
    EXPECT_EQ(dut->PcPlus4E, 0x11111111);
    EXPECT_EQ(dut->RegWriteE, 1);
    EXPECT_EQ(dut->ResultSrcE, 2);
    EXPECT_EQ(dut->MemWriteE, 1);
    EXPECT_EQ(dut->JumpE, 0);
    EXPECT_EQ(dut->BranchE, 1);
    EXPECT_EQ(dut->ALUControlE, 5);  // 3'b101
    EXPECT_EQ(dut->ALUSrcE, 1);
}

TEST_F(PRegDecodeTest, TestOverwritingValues) {
    // Apply new inputs
    dut->rd1 = 0xDEADBEEF;
    dut->rd2 = 0xCAFEBABE;
    dut->PCd = 0xABCDEF01;
    dut->ImmExtD = 0x13572468;
    dut->RdD = 0x0A;
    dut->PCPlus4D = 0x22222222;
    dut->RegWriteD = 0;
    dut->ResultSrcD = 1;
    dut->MemWriteD = 0;
    dut->JumpD = 1;
    dut->BranchD = 0;
    dut->ALUControl = 2;  // 3'b010
    dut->ALUSrcD = 0;

    advanceClock(); // Advance one clock cycle

    // Check outputs
    EXPECT_EQ(dut->rd1E, 0xDEADBEEF);
    EXPECT_EQ(dut->rd2E, 0xCAFEBABE);
    EXPECT_EQ(dut->PCe, 0xABCDEF01);
    EXPECT_EQ(dut->RdE, 0x0A);
    EXPECT_EQ(dut->ImmExtE, 0x13572468);
    EXPECT_EQ(dut->PcPlus4E, 0x22222222);
    EXPECT_EQ(dut->RegWriteE, 0);
    EXPECT_EQ(dut->ResultSrcE, 1);
    EXPECT_EQ(dut->MemWriteE, 0);
    EXPECT_EQ(dut->JumpE, 1);
    EXPECT_EQ(dut->BranchE, 0);
    EXPECT_EQ(dut->ALUControlE, 2);  // 3'b010
    EXPECT_EQ(dut->ALUSrcE, 0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
