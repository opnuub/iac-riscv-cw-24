#include <gtest/gtest.h>
#include "VPRegFetch.h" // Generated Verilator header
#include "verilated.h"

class PRegFetchTest : public ::testing::Test {
protected:
    VPRegFetch* dut; // Device under test

    void SetUp() override {
        Verilated::traceEverOn(true);
        dut = new VPRegFetch;
        dut->clk = 0; // Initialize clock
        dut->eval();
    }

    void TearDown() override {
        delete dut;
    }

    void toggleClock() {
        dut->clk = !dut->clk;
        dut->eval();
    }
};

TEST_F(PRegFetchTest, TestInitialValues) {
    EXPECT_EQ(dut->InstrD, 0);
    EXPECT_EQ(dut->PCd, 0);
    EXPECT_EQ(dut->PCPlus4D, 0);
}

TEST_F(PRegFetchTest, TestLoadingValues) {
    dut->instr = 0xA5A5A5A5;
    dut->PCf = 0x12345678;
    dut->PCPlus4F = 0x87654321;

    toggleClock(); // Rising edge
    toggleClock(); // Falling edge

    EXPECT_EQ(dut->InstrD, 0xA5A5A5A5);
    EXPECT_EQ(dut->PCd, 0x12345678);
    EXPECT_EQ(dut->PCPlus4D, 0x87654321);
}

TEST_F(PRegFetchTest, TestOverwritingValues) {
    dut->instr = 0xFFFFFFFF;
    dut->PCf = 0x11111111;
    dut->PCPlus4F = 0x22222222;

    toggleClock(); // Rising edge
    toggleClock(); // Falling edge

    EXPECT_EQ(dut->InstrD, 0xFFFFFFFF);
    EXPECT_EQ(dut->PCd, 0x11111111);
    EXPECT_EQ(dut->PCPlus4D, 0x22222222);
}

TEST_F(PRegFetchTest, TestZeroValues) {
    dut->instr = 0x0;
    dut->PCf = 0x0;
    dut->PCPlus4F = 0x0;

    toggleClock(); // Rising edge
    toggleClock(); // Falling edge

    EXPECT_EQ(dut->InstrD, 0x0);
    EXPECT_EQ(dut->PCd, 0x0);
    EXPECT_EQ(dut->PCPlus4D, 0x0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
