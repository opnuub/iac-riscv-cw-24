#include <gtest/gtest.h>
#include "Vregfile.h"  
#include "verilated.h"

class RegfileTest : public ::testing::Test {
protected:
    Vregfile* dut;  

    void SetUp() override {
        Verilated::traceEverOn(true);  
        dut = new Vregfile;
        dut->clk_i = 0;
        dut->rst_ni = 1;
        dut->eval(); 
    }

    void TearDown() override {
        delete dut;
    }

    void ToggleClock() {
        dut->clk_i = !dut->clk_i;
        dut->eval();
    }
};

TEST_F(RegfileTest, ResetTest) {
    dut->rst_ni = 0;
    ToggleClock();
    ToggleClock();  // Two cycles with reset low
    dut->rst_ni = 1;

    for (int i = 0; i < 32; ++i) {
        dut->raddr1_i = i;
        dut->raddr2_i = i;
        dut->eval();
        EXPECT_EQ(dut->rdata1_o, 0) << "Register " << i << " should be 0 after reset.";
        EXPECT_EQ(dut->rdata2_o, 0) << "Register " << i << " should be 0 after reset.";
    }
}

TEST_F(RegfileTest, WriteAndReadTest) {
    // Write to register 1
    dut->wen_i = 1;
    dut->waddr_i = 1;
    dut->wdata_i = 0xDEADBEEF;
    ToggleClock();
    dut->wen_i = 0;

    // Read back the value from register 1
    dut->raddr1_i = 1;
    dut->raddr2_i = 2;  // Reading from default zero
    dut->eval();
    EXPECT_EQ(dut->rdata1_o, 0xDEADBEEF) << "Read failed for register 1.";
    EXPECT_EQ(dut->rdata2_o, 0) << "Default zero read failed for register 2.";
}

TEST_F(RegfileTest, ZeroRegisterBehaviorTest) {
    // Attempt to write to register 0 , which should remain zero
    dut->wen_i = 1;
    dut->waddr_i = 0;
    dut->wdata_i = 0xFFFFFFFF;
    ToggleClock();
    dut->wen_i = 0;

    // Read back from register 0, and this should still be zero
    dut->raddr1_i = 0;
    dut->eval();
    EXPECT_EQ(dut->rdata1_o, 0) << "Zero register write behavior failed.";
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}