#include <gtest/gtest.h>
#include "verilated.h"
#include "VL1Cache.h"

class L1CacheTest : public ::testing::Test {
protected:
    VL1Cache *dut;

    void SetUp() override {
        dut = new VL1Cache;
        dut->clk = 0;
        dut->rst_n = 0;
    }

    void TearDown() override {
        dut->final();
        delete dut;
    }

    void clockCycle() {
        dut->clk = 0;
        dut->eval();
        dut->clk = 1;
        dut->eval();
    }

    void reset() {
        dut->rst_n = 0;
        clockCycle();
        dut->rst_n = 1;
        clockCycle();
    }
};

TEST_F(L1CacheTest, StoreData) {
    reset();

    // Test: Store Data
    dut->store = 1;
    dut->address = 0x12345678;
    dut->data_in = 0xAAAABBBB;  // Corrected literal format
    clockCycle();
    dut->store = 0;
    clockCycle();

    // Check if busy signal is deasserted and no miss occurred
    EXPECT_EQ(dut->busy, 0);
    EXPECT_EQ(dut->miss, 0);
}

TEST_F(L1CacheTest, LoadData) {
    reset();

    // Simulate loading the same address stored in StoreData
    dut->load = 1;
    dut->address = 0x12345678;
    clockCycle();
    dut->load = 0;
    clockCycle();

    // Check if data is correctly returned
    EXPECT_EQ(dut->hit, 1);
    EXPECT_EQ(dut->data_out, 0xAAAABBBB);  // Corrected literal format
}