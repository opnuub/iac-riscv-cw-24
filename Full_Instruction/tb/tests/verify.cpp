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
    setData("/Users/michaelli/Documents/GitHub/iac-riscv-cw-24/tb/reference/gaussian.mem");
    initSimulation();
    runSimulation(CYCLES * 100);
    EXPECT_EQ(top_->a0, 15363);

}

// New comprehensive tests full of RISC-V instructions
TEST_F(CpuTestbench, TestLogicalOps)
{
    setupTest("7_test");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 0xFF); 
}

TEST_F(CpuTestbench, TestShifts)
{
    setupTest("8_shifts");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 0x40);  // Shift left by 6 bits (1 -> 64)
}

TEST_F(CpuTestbench, TestSLT)
{
    setupTest("9_slt");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 4);  // All four comparison tests passed
}

TEST_F(CpuTestbench, TestMemoryOps)
{
    setupTest("10_memory");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 0x12345678);  // Load/store test pattern
}

TEST_F(CpuTestbench, TestBranches)
{
    setupTest("11_branches");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 6);  // Six branch tests passed
}

TEST_F(CpuTestbench, TestUpperImm)
{
    setupTest("12_upper_imm");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 0x12345000);  // LUI test result
}

TEST_F(CpuTestbench, TestHazards)
{
    setupTest("13_hazards");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 22);  // Result after hazard handling
}

TEST_F(CpuTestbench, TestEdgeCases)
{
    setupTest("14_edge_cases");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 0x80000000);  // Minimum signed 32-bit value
}

TEST_F(CpuTestbench, TestJumps)
{
    setupTest("15_jumps");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 0x12345678);  // Jump to address 0x12345678
}

TEST_F(CpuTestbench, TestShiftRight)
{
    setupTest("16_shift_right_test");  // Assuming the assembly file is named "shift_right.s"
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 0x0F);
}

TEST_F(CpuTestbench, TestMissingInstructions)
{
    setupTest("17_missing_instr");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, -64);  // 0xFFFFFFC0 in two's complement
}

TEST_F(CpuTestbench, TestAuipcInstructions)
{
    setupTest("18_auipc_test");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 8192);  // 0x2000 = 8192 in decimal
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    auto res = RUN_ALL_TESTS();
    return res;
}