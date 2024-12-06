#include <gtest/gtest.h>
#include <verilated.h>
#include "Vdecoder.h"

class DecoderTest : public ::testing::Test {
protected:
    Vdecoder* dut; 

    void SetUp() override {
        Verilated::traceEverOn(true);
        dut = new Vdecoder();
    }

    void TearDown() override {
        delete dut;
    }

    void setInstruction(uint32_t instr) {
        dut->instr_i = instr;
        dut->eval();
    }
};

// Test I-Type Immediate
TEST_F(DecoderTest, ITypeImmediate) {
    uint32_t instr = 0b11111111111100000000000110010011; // ADDI x3, x0, -1
    setInstruction(instr);
    EXPECT_EQ(dut->imm_o, static_cast<int32_t>(-1)) << "I-Type immediate failed.";
    EXPECT_EQ(dut->opcode_o, 0b0010011) << "I-Type opcode failed.";
}

// Test S-Type Immediate
TEST_F(DecoderTest, STypeImmediate) {
    uint32_t instr = 0b11111111111100000000001100100011; // SW x31, -1(x0)
    setInstruction(instr);
    EXPECT_EQ(dut->imm_o, static_cast<int32_t>(-1)) << "S-Type immediate failed.";
    EXPECT_EQ(dut->opcode_o, 0b0100011) << "S-Type opcode failed.";
}

// Test B-Type Immediate
TEST_F(DecoderTest, BTypeImmediate) {
    uint32_t instr = 0b11111110000100000001011101100011; // BEQ x1, x2, -4
    setInstruction(instr);
    EXPECT_EQ(dut->imm_o, static_cast<int32_t>(-4)) << "B-Type immediate failed.";
    EXPECT_EQ(dut->opcode_o, 0b1100011) << "B-Type opcode failed.";
}

// Test U-Type Immediate
TEST_F(DecoderTest, UTypeImmediate) {
    uint32_t instr = 0b00000000000011111000000010110111; // LUI x1, 0x78000
    setInstruction(instr);
    EXPECT_EQ(dut->imm_o, 0x78000) << "U-Type immediate failed.";
    EXPECT_EQ(dut->opcode_o, 0b0110111) << "U-Type opcode failed.";
}

// Test J-Type Immediate
TEST_F(DecoderTest, JTypeImmediate) {
    uint32_t instr = 0b11111111111100000000001111101111; // JAL x1, -2
    setInstruction(instr);
    EXPECT_EQ(dut->imm_o, static_cast<int32_t>(-2)) << "J-Type immediate failed.";
    EXPECT_EQ(dut->opcode_o, 0b1101111) << "J-Type opcode failed.";
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}