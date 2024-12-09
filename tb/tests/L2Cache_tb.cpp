#include "VL2Cache.h"
#include "verilated.h"
#include "gtest/gtest.h"

class L2CacheTest : public ::testing::Test {
protected:
    VL2Cache* top;

    void SetUp() override {
        top = new VL2Cache;
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

TEST_F(L2CacheTest, Initialization) {
    EXPECT_EQ(top->hit, 0); 
}

TEST_F(L2CacheTest, CacheHit) {
    top->reset = 0;
    top->address = 0x00001010;
    top->writeData = 0xABCD1234;
    top->writeEnable = 1;
    tick();
    tick();

    top->writeEnable = 0;
    top->address = 0x00001010;
    tick();
    EXPECT_EQ(top->hit, 1);
    EXPECT_EQ(top->readData, 0xABCD1234);
}

TEST_F(L2CacheTest, CacheMiss) {
    top->reset = 0;
    top->address = 0x00002020;
    top->writeData = 0xCAFEBABE;
    top->writeEnable = 1;
    tick();
    tick();

    top->address = 0x00003030; // different address to cause a miss
    top->writeEnable = 0;
    tick();
    EXPECT_EQ(top->hit, 0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}