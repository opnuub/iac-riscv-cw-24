#include <gtest/gtest.h>
#include "Vpiptop.h"
#include "verilated.h"

class PiptopTest : public ::testing::Test {
protected:
    Vpiptop* dut; // Device Under Test

    void SetUp() override {
        Verilated::traceEverOn(true);
        dut = new Vpiptop();
        dut->clk = 0;
        dut->rst = 1;
        dut->trigger = 0;
        dut->eval(); // Initial evaluation
    }

    void TearDown() override {
        delete dut;
    }

    void toggleClock() {
        dut->clk = !dut->clk;
        dut->eval();
    }

    void advanceClock() {
        toggleClock(); // Rising edge
        toggleClock(); // Falling edge
    }

    void resetDUT() {
        dut->rst = 1;
        advanceClock();
        dut->rst = 0;
    }
};

TEST_F(PiptopTest, ResetBehavior) {
    resetDUT();
    EXPECT_EQ(dut->a0, 0) << "Reset failed to clear output!";
}

TEST_F(PiptopTest, BasicOperation) {
    resetDUT();
    dut->trigger = 1; // Start the pipeline
    advanceClock(); // Initial clock to enable the trigger
    for (int i = 0; i < 20; ++i) { // Allow pipeline to fill
        advanceClock();
        if (dut->a0 != 0) break; // Exit loop early if output becomes non-zero
    }
    EXPECT_NE(dut->a0, 0) << "Pipeline operation failed to produce a non-zero output!";
}

TEST_F(PiptopTest, SteadyStateOperation) {
    resetDUT();
    dut->trigger = 1;
    uint32_t previous_a0 = 0;
    for (int i = 0; i < 20; ++i) { // Allow pipeline to stabilize
        advanceClock();
        EXPECT_NE(dut->a0, previous_a0) << "Pipeline output (a0) did not change over time!";
        previous_a0 = dut->a0;
    }
}

TEST_F(PiptopTest, OutputConsistency) {
    resetDUT();
    dut->trigger = 1;
    for (int i = 0; i < 5; ++i) { // Warm-up phase
        advanceClock();
    }

    uint32_t first_a0 = dut->a0;
    for (int i = 0; i < 10; ++i) { // Check for consistent output
        advanceClock();
        EXPECT_EQ(dut->a0, first_a0) << "Pipeline output (a0) became inconsistent!";
    }
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
