#include <gtest/gtest.h>
#include "Valu.h"  
#include "verilated.h"

// Test fixture for ALU module
class ALUTest : public ::testing::Test {
protected:
    Valu* dut;  

    void SetUp() override {
        Verilated::traceEverOn(true); 
        dut = new Valu;
    }

    void TearDown() override {
        delete dut;
    }
};

TEST_F(ALUTest, TestAddition) {
    dut->operand_a_i = 10;
    dut->operand_b_i = 20;
    dut->operator_i = 0b0000;  // ALU_ADD
    dut->eval();

    EXPECT_EQ(dut->result_o, 30);
}

TEST_F(ALUTest, TestSubtraction) {
    dut->operand_a_i = 50;
    dut->operand_b_i = 20;
    dut->operator_i = 0b0001;  // ALU_SUB
    dut->eval();

    EXPECT_EQ(dut->result_o, 30);
}

TEST_F(ALUTest, TestAnd) {
    dut->operand_a_i = 0b1010;
    dut->operand_b_i = 0b1100;
    dut->operator_i = 0b1001;  // ALU_AND
    dut->eval();

    EXPECT_EQ(dut->result_o, 0b1000);
}

TEST_F(ALUTest, TestShiftLeft) {
    dut->operand_a_i = 1;
    dut->operand_b_i = 2;
    dut->operator_i = 0b0010;  // ALU_SLL
    dut->eval();

    EXPECT_EQ(dut->result_o, 4);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}