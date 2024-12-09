#include "VL3Cache.h"
#include "verilated.h"
#include "gtest/gtest.h"

class L3CacheTest : public ::testing::Test {
protected:
    VL3Cache* top;

    void SetUp() override {
        top = new VL3Cache;
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

TEST_F(L3CacheTest, Initialization) {
    EXPECT_EQ(top->hit, 0); 
}

TEST_F(L3CacheTest, CacheHit) {
    top->reset = 0;
    top->address = 0x00010010;
    top->writeData = 0xFACEFEED;
    top->writeEnable = 1;
    tick();
    tick();

    top->writeEnable = 0;
    top->address = 0x00010010;
    tick();
    EXPECT_EQ(top->hit, 1);
    EXPECT_EQ(top->readData, 0xFACEFEED);
}

TEST_F(L3CacheTest, CacheMiss) {
    top->reset = 0;
    top->address = 0x00020020;
    top->writeData = 0xBADF00D;
    top->writeEnable = 1;
    tick();
    tick();

    top->address = 0x00030030; // different address to cause a miss
    top->writeEnable = 0;
    tick();
    EXPECT_EQ(top->hit, 0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}