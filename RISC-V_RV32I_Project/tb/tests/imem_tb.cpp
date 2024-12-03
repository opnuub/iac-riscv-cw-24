#include <gtest/gtest.h>
#include "Vimem.h"
#include "verilated.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

class ImemTest : public ::testing::Test {
protected:
    Vimem* dut;
    std::vector<uint8_t> test_program;

    void SetUp() override {
        dut = new Vimem;
        dut->clk_i = 0;
        loadProgram("/Users/michaelli/Documents/GitHub/iac-riscv-cw-24/RISC-V_RV32I_Project/rtl/program.hex");
    }

    void TearDown() override {
        delete dut;
    }

    void tick() {
        dut->eval();
        dut->clk_i = 1;
        dut->eval();
        dut->clk_i = 0;
        dut->eval();
    }

    void loadProgram(const std::string& filename) {
        std::ifstream file(filename);
        ASSERT_TRUE(file.is_open()) << "Failed to open " << filename;

        std::string line;
        while (std::getline(file, line)) {
            if (line.empty()) continue;
            test_program.push_back(std::stoul(line, nullptr, 16));
        }
    }

    uint32_t getExpectedInstruction(uint32_t addr) {
        addr = addr & ~3U;  // Align to 4 bytes??
        if (addr + 3 >= test_program.size()) return 0;
        
        return (static_cast<uint32_t>(test_program[addr+3]) << 24) |
               (static_cast<uint32_t>(test_program[addr+2]) << 16) |
               (static_cast<uint32_t>(test_program[addr+1]) << 8) |
                static_cast<uint32_t>(test_program[addr]);
    }
};

TEST_F(ImemTest, SequentialRead) {
    ASSERT_FALSE(test_program.empty()) << "Test program not loaded";

    // Test sequential reads
    for (uint32_t addr = 0; addr < 64; addr += 4) {
        dut->addr_i = addr;
        tick();
        uint32_t expected = getExpectedInstruction(addr);
        EXPECT_EQ(dut->rdata_o, expected) 
            << std::hex << std::uppercase
            << "Address 0x" << addr 
            << " Expected: 0x" << expected 
            << " Got: 0x" << dut->rdata_o;
    }
}

TEST_F(ImemTest, UnalignedRead) {
    // Unaligned reads should read from aligned address
    for (uint32_t addr = 1; addr < 16; addr++) {
        dut->addr_i = addr;
        tick();
        uint32_t expected = getExpectedInstruction(addr);
        EXPECT_EQ(dut->rdata_o, expected)
            << "Unaligned read failed at address 0x" << std::hex << addr;
    }
}

TEST_F(ImemTest, BoundaryConditions) {
    // Test memory boundaries
    uint32_t max_addr = 4096 - 4;  // Last valid aligned address
    dut->addr_i = max_addr;
    tick();
    EXPECT_EQ(dut->rdata_o, getExpectedInstruction(max_addr))
        << "Failed at maximum address";
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}