#include "Vcontroller.h"
#include "gtest/gtest.h"

class ControllerTest : public ::testing::Test {
protected:
    Vcontroller *dut;

    void SetUp() override {
        dut = new Vcontroller;
    }

    void TearDown() override {
        delete dut;
    }
};

TEST_F(ControllerTest, TestRType) {
    // Set inputs for R-Type instruction, opcode: 0110011
    dut->opcode_i = 0x33;  // R-Type opcode in hex
    dut->funct3_i = 0x0;   // funct3: 000
    dut->funct7_i = 0x00;  // funct7: 0000000

    dut->eval();
    EXPECT_EQ(dut->rf_wen_o, 1);          // Register write enabled
    EXPECT_EQ(dut->alu_op_o, 0x0);        // ALU_ADD

    // Change funct7 to test SUB
    dut->funct7_i = 0x20;  // funct7: 0100000
    dut->eval();
    EXPECT_EQ(dut->alu_op_o, 0x1);        // ALU_SUB
}

TEST_F(ControllerTest, TestLoad) {
    // Set inputs for Load instruction, opcode: 0000011
    dut->opcode_i = 0x03;  // Load opcode in hex
    dut->funct3_i = 0x2;   // funct3: LW
    dut->eval();

    EXPECT_EQ(dut->rf_wen_o, 1);          // Register write enabled
    EXPECT_EQ(dut->mem_wen_o, 0);         // Memory write disabled
    EXPECT_EQ(dut->mem_size_o, 0x2);      // Word access
}

TEST_F(ControllerTest, TestBranch) {
    // Set inputs for Branch instruction, opcode: 1100011
    dut->opcode_i = 0x63;  // Branch opcode in hex
    dut->funct3_i = 0x0;   // funct3: BEQ
    dut->branch_eq_i = 1;
    dut->eval();

    EXPECT_EQ(dut->next_pc_sel_o, 0x1);   // Branch taken

    // Test branch not taken
    dut->branch_eq_i = 0;
    dut->eval();
    EXPECT_EQ(dut->next_pc_sel_o, 0x0);   // Sequential PC
}

TEST_F(ControllerTest, TestIllegalInstruction) {
    // Set inputs for an illegal instruction
    dut->opcode_i = 0x7F;  // Illegal opcode
    dut->eval();
    EXPECT_EQ(dut->illegal_instr_o, 1);   // Illegal instruction detected
}