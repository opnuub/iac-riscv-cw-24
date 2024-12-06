#include <gtest/gtest.h>
#include "VDataMemory.h"
#include "verilated.h"

class DataMemoryTest : public ::testing::Test {
protected:
    VDataMemory* dut;
    vluint64_t main_time = 0;

    virtual void SetUp() override {
        Verilated::traceEverOn(true);
        dut = new VDataMemory();
        dut->clk = 0;
        dut->MemWrite = 0;
        dut->SizeCtr = 0;
        dut->ALUResult = 0;
        dut->WriteData = 0;
    }

    virtual void TearDown() override {
        delete dut;
    }

    void tick() {
        dut->clk = !dut->clk;
        dut->eval();
        main_time += 5;
    }

    void reset() {
        dut->MemWrite = 0;
        dut->SizeCtr = 0;
        dut->ALUResult = 0;
        dut->WriteData = 0;
        for (int i = 0; i < 2; i++) tick();
    }
};

TEST_F(DataMemoryTest, WriteReadWordTest) {
    reset();

    // Write a word
    dut->MemWrite = 1;
    dut->SizeCtr = 0b010; // Word operation
    dut->ALUResult = 0x0;
    dut->WriteData = 0xAABBCCDD;

    tick();
    dut->MemWrite = 0;
    tick();

    // Read back the word
    EXPECT_EQ(dut->ReadData, 0xAABBCCDD) << "Word read failed";
}

TEST_F(DataMemoryTest, WriteReadByteTest) {
    reset();

    // Write a byte
    dut->MemWrite = 1;
    dut->SizeCtr = 0b000; // Byte operation
    dut->ALUResult = 0x1;
    dut->WriteData = 0x11;

    tick();
    dut->MemWrite = 0;
    tick();

    // Read back the byte
    EXPECT_EQ(dut->ReadData & 0xFF, 0x11) << "Byte read failed";
}

TEST_F(DataMemoryTest, LoadHalfwordUnsignedTest) {
    reset();

    // Write a halfword
    dut->MemWrite = 1;
    dut->SizeCtr = 0b001; // Halfword operation
    dut->ALUResult = 0x0;
    dut->WriteData = 0xCCDD;

    tick();
    dut->MemWrite = 0;
    tick();

    // Read back the unsigned halfword
    dut->SizeCtr = 0b101; // Load Halfword Unsigned
    EXPECT_EQ(dut->ReadData & 0xFFFF, 0xCCDD) << "Unsigned Halfword read failed";
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
