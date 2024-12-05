#include <cstdlib>
#include <utility>

#include "Vdut.h"  
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "gtest/gtest.h"

// STILL NEED TO CHANGE THIS
class TopTest : public ::testing::Test {
protected:
    Vdut* dut;
    vluint64_t sim_time = 0;

    void SetUp() override {
        Verilated::traceEverOn(true);
        dut = new Vdut;

        dut->clk_i = 0;
        dut->rst_ni = 0;
        dut->trigger_i = 0;
    }

    void TearDown() override {
        dut->final();
        delete dut;
    }

    void tick(int count = 1) {
        for(int i = 0; i < count; i++) {
            dut->clk_i = 0;
            dut->eval();
            sim_time++;

            dut->clk_i = 1; 
            dut->eval();
            sim_time++;
        }
    }
};

TEST_F(TopTest, ResetTest) {

    dut->rst_ni = 0;
    tick(5); 
    dut->rst_ni = 1;
    tick(5);
    
    EXPECT_EQ(dut->a0_o, 0) << "a0_o should be 0 after reset";
}

TEST_F(TopTest, TriggerTest) {
    dut->rst_ni = 0;
    tick(5);
    dut->rst_ni = 1;
    tick(5);

    dut->trigger_i = 1;
    tick(1);
    dut->trigger_i = 0;
    
    tick(100);

    EXPECT_NE(dut->a0_o, 0) << "a0_o should change after trigger";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}