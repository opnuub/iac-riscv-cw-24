#include <gtest/gtest.h>
#include "Vdecoder.h"  
#include "verilated.h"
#include <iostream>
#include <bitset>

class DecoderTest : public ::testing::Test {
protected:
    Vdecoder* dut; 

    void SetUp() override {
        dut = new Vdecoder;  
    }

    void TearDown() override {
        delete dut; 
    }

    // Helper function for sign-extension
    int32_t sign_extend(uint32_t value, int bits) {
        int32_t mask = 1 << (bits - 1);
        return (value ^ mask) - mask;
    }
};

// Test R-type instruction
TEST_F(DecoderTest, RTypeInstruction) {
    dut->instr_i = 0x00C585B3;  // a R-type instruction
    dut->eval();

    std::cout << "Testing R-Type Instruction:" << std::endl;
    std::cout << "instr_i: " << std::bitset<32>(dut->instr_i) << std::endl;
    std::cout << "opcode_o: " << std::bitset<7>(dut->opcode_o) << std::endl;
    std::cout << "funct3_o: " << std::bitset<3>(dut->funct3_o) << std::endl;
    std::cout << "funct7_o: " << std::bitset<7>(dut->funct7_o) << std::endl;
    std::cout << "rd_addr_o: " << std::bitset<5>(dut->rd_addr_o) << std::endl;

    EXPECT_EQ(dut->opcode_o, 0b0110011);
    EXPECT_EQ(dut->funct3_o, 0b100);
    EXPECT_EQ(dut->funct7_o, 0b0000000);
    EXPECT_EQ(dut->rd_addr_o, 11);
}

// Test I-type instruction
TEST_F(DecoderTest, ITypeInstruction) {
    dut->instr_i = 0xFFF00793;  // I-type instruction
    dut->eval();

    std::cout << "Testing I-Type Instruction:" << std::endl;
    std::cout << "instr_i: " << std::bitset<32>(dut->instr_i) << std::endl;
    std::cout << "opcode_o: " << std::bitset<7>(dut->opcode_o) << std::endl;
    std::cout << "imm_o: " << dut->imm_o << std::endl;

    EXPECT_EQ(dut->opcode_o, 0b0010011);
    EXPECT_EQ(dut->imm_o, sign_extend(0xFFF, 12));  // Sign-extended immediate
}

// Test S-type instruction
TEST_F(DecoderTest, STypeInstruction) {
    dut->instr_i = 0x00F707A3;  //  S-type instruction
    dut->eval();

    std::cout << "Testing S-Type Instruction:" << std::endl;
    std::cout << "instr_i: " << std::bitset<32>(dut->instr_i) << std::endl;
    std::cout << "opcode_o: " << std::bitset<7>(dut->opcode_o) << std::endl;
    std::cout << "imm_o: " << dut->imm_o << std::endl;

    EXPECT_EQ(dut->opcode_o, 0b0100011);
    EXPECT_EQ(dut->imm_o, sign_extend(0xF0F, 12));  // Sign-extended immediate
}

// Test B-type instruction
TEST_F(DecoderTest, BTypeInstruction) {
    dut->instr_i = 0x00006063;  //  B-type instruction
    dut->eval();

    std::cout << "Testing B-Type Instruction:" << std::endl;
    std::cout << "instr_i: " << std::bitset<32>(dut->instr_i) << std::endl;
    std::cout << "opcode_o: " << std::bitset<7>(dut->opcode_o) << std::endl;
    std::cout << "imm_o: " << dut->imm_o << std::endl;

    EXPECT_EQ(dut->opcode_o, 0b1100011);
    EXPECT_EQ(dut->imm_o, sign_extend(0x6, 13));  // Sign-extended immediate
}

// Test J-type instruction
TEST_F(DecoderTest, JTypeInstruction) {
    dut->instr_i = 0x00C0006F;  // JAL instruction
    dut->eval();

    std::cout << "Testing J-Type Instruction:" << std::endl;
    std::cout << "instr_i: " << std::bitset<32>(dut->instr_i) << std::endl;
    std::cout << "opcode_o: " << std::bitset<7>(dut->opcode_o) << std::endl;
    std::cout << "imm_o: " << dut->imm_o << std::endl;

    EXPECT_EQ(dut->opcode_o, 0b1101111);
    EXPECT_EQ(dut->imm_o, sign_extend(0xC0, 21));  // Sign-extended immediate
}

// Main function
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}