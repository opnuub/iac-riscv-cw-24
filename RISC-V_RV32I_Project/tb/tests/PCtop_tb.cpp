#include <gtest/gtest.h>
#include "VPCtop.h"
#include "verilated.h"

// Test class for PCtop
class PCtopTest : public ::testing::Test {
protected:
    VPCtop* dut;  // Device Under Test (DUT)

    virtual void SetUp() {
        Verilated::traceEverOn(true);  // Enable trace
        dut = new VPCtop;             // Create DUT instance
        dut->clk = 0;                 // Initialize clock
        dut->rst = 1;                 // Start with reset asserted
    }

    virtual void TearDown() {
        delete dut;  // Cleanup DUT instance
    }

    // Helper to toggle clock and evaluate DUT
    void toggleClock() {
        dut->clk = !dut->clk;
        dut->eval();
    }

    // Helper to simulate a clock cycle
    void clockCycle() {
        toggleClock();  // Rising edge
        toggleClock();  // Falling edge
    }
};

// Test case: Reset behavior
TEST_F(PCtopTest, ResetTest) {
    dut->rst = 1;       // Assert reset
    dut->eval();        // Evaluate once
    EXPECT_EQ(dut->PCd, 0);  // PCd should reset to 0
    EXPECT_EQ(dut->PCPlus4D, 0);  // PCPlus4D should also reset
}

// Test case: Default PC increment (PCPlus4F)
TEST_F(PCtopTest, IncrementTest) {
    dut->rst = 0;       // Deassert reset
    dut->PCsrcE = 0;    // Default PC increment
    dut->eval();

    // Simulate 2 clock cycles
    clockCycle();
    clockCycle();

    EXPECT_EQ(dut->PCd, 4);  // PC should increment by 4
}

// Test case: Branch to PCTargetE
TEST_F(PCtopTest, BranchTest) {
    dut->rst = 0;       // Deassert reset
    dut->PCsrcE = 1;    // Take branch
    dut->PCTargetE = 16; // Branch target
    dut->eval();

    // Simulate 2 clock cycles
    clockCycle();
    clockCycle();

    EXPECT_EQ(dut->PCd, 16);  // PC should branch to 16
}

// Test case: Multiple sequential increments
TEST_F(PCtopTest, MultipleIncrementTest) {
    dut->rst = 0;       // Deassert reset
    dut->PCsrcE = 0;    // Default PC increment
    dut->eval();

    // Simulate a total of 6 clock cycles (1 extra to account for delay)
    for (int i = 0; i < 6; ++i) {
        clockCycle();
        printf("Cycle %d: PCd=%d, PCPlus4D=%d\n", i, dut->PCd, dut->PCPlus4D);
    }

    // After 6 cycles, the fifth increment should be reflected in PCd
    EXPECT_EQ(dut->PCd, 20);  // PC should increment by 20 after 6 cycles
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
