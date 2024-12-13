#include <cstdlib>
#include <utility>

#include "cpu_testbench.h"

#define CYCLES 10000

TEST_F(CpuTestbench, TestAddiBne)
{
    setupTest("1_addi_bne");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 254);
}

TEST_F(CpuTestbench, TestLiAdd)
{
    setupTest("2_li_add");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 1000);
}

TEST_F(CpuTestbench, TestLbuSb)
{
    setupTest("3_lbu_sb");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 300);
}

TEST_F(CpuTestbench, TestJalRet)
{
    setupTest("4_jal_ret");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 53);
}

TEST_F(CpuTestbench, TestPdf)
{
    setupTest("5_pdf");
    setData("reference/gaussian.mem");
    initSimulation();
    runSimulation(CYCLES * 100);
    EXPECT_EQ(top_->a0, 15363);
}

TEST_F(CpuTestbench, TestReg)
{
    setupTest("6_regfile");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0,84);
}

TEST_F(CpuTestbench, ZeroReg)
{
    setupTest("7_zero_register_test");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0,99);
}

TEST_F(CpuTestbench, JumpTest)
{
    setupTest("8_jump");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0,3);
}

// Branch Test bench is testing all the ALU functions implemented
// as well as branch and load instructions
// Will return a0 = 0 if all pass
TEST_T(CpuTestbench, BranchTb)
{
    setupTest("9_branchtb");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top->a0,0);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    auto res = RUN_ALL_TESTS();
    return res;
}
