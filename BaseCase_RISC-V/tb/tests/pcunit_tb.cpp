#include <gtest/gtest.h>
#include "Vpcunit.h"
#include "verilated.h"

class PcUnitTest : public ::testing::Test {
protected:
    Vpcunit* pcunit;

    void SetUp() override {
        pcunit = new Vpcunit;
        pcunit->rst_ni = 0;  // Reset active low
        pcunit->clk_i = 0;
        pcunit->eval();
        pcunit->rst_ni = 1;  // Release reset
        pcunit->eval();
    }

    void TearDown() override {
        delete pcunit;
    }

    void toggleClock() {
        pcunit->clk_i = 1;
        pcunit->eval();
        pcunit->clk_i = 0;
        pcunit->eval();
    }
};

TEST_F(PcUnitTest, SequentialIncrement) {
    pcunit->next_pc_sel_i = 0b000;
    toggleClock();
    ASSERT_EQ(pcunit->pc_o, 0x00000004);

    toggleClock();
    ASSERT_EQ(pcunit->pc_o, 0x00000008);
}

TEST_F(PcUnitTest, Branch) {
    pcunit->next_pc_sel_i = 0b001;
    pcunit->imm_i = 0x00000008;
    toggleClock();
    ASSERT_EQ(pcunit->pc_o, 0x00000008);
}

TEST_F(PcUnitTest, JumpAndLink) {
    pcunit->next_pc_sel_i = 0b010;
    pcunit->imm_i = 0x00000010;
    toggleClock();
    ASSERT_EQ(pcunit->pc_o, 0x00000010);
}

TEST_F(PcUnitTest, JumpAndLinkRegister) {
    pcunit->next_pc_sel_i = 0b011;
    pcunit->alu_result_i = 0x00000014;
    toggleClock();
    ASSERT_EQ(pcunit->pc_o, 0x00000014 & ~0x1);  // Align to the nearest even address
}

TEST_F(PcUnitTest, ResetBehavior) {
    pcunit->rst_ni = 0;  // Assert reset
    pcunit->eval();
    ASSERT_EQ(pcunit->pc_o, 0x00000000);

    pcunit->rst_ni = 1;  // Deassert reset
    pcunit->eval();
    pcunit->next_pc_sel_i = 0b000;
    toggleClock();
    ASSERT_EQ(pcunit->pc_o, 0x00000004);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}