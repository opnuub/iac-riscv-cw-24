#include <gtest/gtest.h>
#include "Vdmem.h"
#include "verilated.h"

class DmemTest : public ::testing::Test {
protected:
    Vdmem *dut;
    vluint64_t main_time = 0;

    virtual void SetUp() {
        Verilated::traceEverOn(true);
        dut = new Vdmem();
        dut->clk_i = 0;
        dut->rst_ni = 0;
    }

    virtual void TearDown() {
        delete dut;
    }

    void tick() {
        dut->clk_i = !dut->clk_i;
        dut->eval();
        main_time += 5;
    }

    void resetDut() {
        dut->rst_ni = 0;
        tick();
        tick();
        dut->rst_ni = 1;
    }
};

TEST_F(DmemTest, WriteReadTest) {
    resetDut();

    dut->wen_i = 1;
    dut->signed_i = 1;
    dut->addr_i = 0x0;
    dut->wdata_i = 0xAABBCCDD;
    dut->size_i = 0b010;

    tick();
    dut->wen_i = 0;
    tick();

    EXPECT_EQ(dut->rdata_o & 0xFF, 0xDD);
    EXPECT_EQ((dut->rdata_o >> 8) & 0xFF, 0xCC);
    EXPECT_EQ((dut->rdata_o >> 16) & 0xFF, 0xBB);
    EXPECT_EQ((dut->rdata_o >> 24) & 0xFF, 0xAA);
}

TEST_F(DmemTest, ResetTest) {
    resetDut();

    EXPECT_EQ(dut->rdata_o, 0x0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}