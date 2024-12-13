#include <gtest/gtest.h>
#include "Vbranch.h" 
#include "verilated.h"

class BranchTest : public ::testing::Test {
protected:
    Vbranch* dut; 

    void SetUp() override {
        Verilated::traceEverOn(true);
        dut = new Vbranch;
    }

    void TearDown() override {
        delete dut;
    }
};

TEST_F(BranchTest, TestBEQ) {
    dut->rs1_data_i = 10;
    dut->rs2_data_i = 10;
    dut->funct3_i = 0b000;  // BEQ
    dut->eval();

    EXPECT_EQ(dut->branch_eq_o, 1);  // Equal
    EXPECT_EQ(dut->branch_taken_o, 1);
}

TEST_F(BranchTest, TestBNE) {
    dut->rs1_data_i = 10;
    dut->rs2_data_i = 20;
    dut->funct3_i = 0b001;  // BNE
    dut->eval();

    EXPECT_EQ(dut->branch_eq_o, 0);  // Not Equal
    EXPECT_EQ(dut->branch_taken_o, 1);
}

TEST_F(BranchTest, TestBLT) {
    dut->rs1_data_i = 5;
    dut->rs2_data_i = 10;
    dut->funct3_i = 0b100;  // BLT
    dut->eval();

    EXPECT_EQ(dut->branch_lt_o, 1);  // Less Than
    EXPECT_EQ(dut->branch_taken_o, 1);
}

TEST_F(BranchTest, TestBGE) {
    dut->rs1_data_i = 15;
    dut->rs2_data_i = 10;
    dut->funct3_i = 0b101;  // BGE
    dut->eval();

    EXPECT_EQ(dut->branch_lt_o, 0);  // Greater or Equal
    EXPECT_EQ(dut->branch_taken_o, 1);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}