#include <gtest/gtest.h>
#include "Valu.h" // Generated Verilator header for ALU
#include "verilated.h"

class ALUTest : public ::testing::Test {
protected:
    Valu* dut; // Pointer to the ALU module

    void SetUp() override {
        Verilated::traceEverOn(true);
        dut = new Valu;
    }

    void TearDown() override {
        delete dut;
    }
};

TEST_F(ALUTest, TestAddition) {
    dut->srcA = 15;
    dut->srcB = 10;
    dut->aluControl = 0b000; // ADD
    dut->eval();

    EXPECT_EQ(dut->aluResult, 15 + 10) << "Addition operation failed";
}

TEST_F(ALUTest, TestSubtraction) {
    dut->srcA = 20;
    dut->srcB = 5;
    dut->aluControl = 0b001; // SUB
    dut->eval();

    EXPECT_EQ(dut->aluResult, 20 - 5) << "Subtraction operation failed";
}

TEST_F(ALUTest, TestAndOperation) {
    dut->srcA = 0xA5A5A5A5;
    dut->srcB = 0x5A5A5A5A;
    dut->aluControl = 0b010; // AND
    dut->eval();

    EXPECT_EQ(dut->aluResult, 0xA5A5A5A5 & 0x5A5A5A5A) << "AND operation failed";
}

TEST_F(ALUTest, TestOrOperation) {
    dut->srcA = 0xA5A5A5A5;
    dut->srcB = 0x5A5A5A5A;
    dut->aluControl = 0b011; // OR
    dut->eval();

    EXPECT_EQ(dut->aluResult, 0xA5A5A5A5 | 0x5A5A5A5A) << "OR operation failed";
}

TEST_F(ALUTest, TestLoadUpper) {
    dut->srcA = 0x12345678;
    dut->srcB = 0x87654321;
    dut->aluControl = 0b100; // LUI
    dut->eval();

    EXPECT_EQ(dut->aluResult, 0x87654321) << "LUI operation failed";
}

TEST_F(ALUTest, TestSetLessThan) {
    dut->srcA = -5;
    dut->srcB = 10;
    dut->aluControl = 0b101; // SLT
    dut->eval();

    EXPECT_EQ(dut->aluResult, 1) << "Set Less Than operation failed";
}

TEST_F(ALUTest, TestShiftLeftLogical) {
    dut->srcA = 1;
    dut->srcB = 4;
    dut->aluControl = 0b110; // SLL
    dut->eval();

    EXPECT_EQ(dut->aluResult, 1 << 4) << "Shift Left Logical operation failed";
}

TEST_F(ALUTest, TestShiftRightLogical) {
    dut->srcA = 16;
    dut->srcB = 2;
    dut->aluControl = 0b111; // SRL
    dut->eval();

    EXPECT_EQ(dut->aluResult, 16 >> 2) << "Shift Right Logical operation failed";
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
