#include "VL1Cache.h"
#include "verilated.h"
#include "gtest/gtest.h"

class L1CacheTest : public ::testing::Test {
protected:
    VL1Cache* top;

    void SetUp() override {
        top = new VL1Cache;
        top->clk = 0;
        top->reset = 1;
        top->eval();
    }

    void TearDown() override {
        delete top;
    }

    void tick() {
        top->clk = !top->clk;
        top->eval();
    }
};

TEST_F(L1CacheTest, Initialization) {
    EXPECT_EQ(top->hit, 0); 
}

TEST_F(L1CacheTest, CacheHit) {
    top->reset = 0;
    top->address = 0x00000010;
    top->writeData = 0xDEADBEEF;
    top->writeEnable = 1;
    tick();
    tick();

    top->writeEnable = 0;
    top->address = 0x00000010;
    tick();
    EXPECT_EQ(top->hit, 1);
    EXPECT_EQ(top->readData, 0xDEADBEEF);
}

TEST_F(L1CacheTest, CacheMiss) {
    top->reset = 0;
    top->address = 0x00000020;
    top->writeData = 0x12345678;
    top->writeEnable = 1;
    tick();
    tick();

    top->address = 0x00000030; // different address to cause a miss
    top->writeEnable = 0;
    tick();
    EXPECT_EQ(top->hit, 0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}