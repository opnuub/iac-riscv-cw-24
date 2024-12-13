#include "cpu_testbench.h"

class ExtendTest : public CpuTestbench {
public:
    void TestExtend(logic<32> instruction, logic<2> immSrc, logic jumpSrc, logic<32> expected) {
        // Set inputs
        top_->instruction = instruction;
        top_->immSrc = immSrc;
        top_->jumpSrc = jumpSrc;

        // Run simulation
        runSimulation(1);

        // Check the output
        ASSERT_EQ(top_->immExt, expected)
            << "Failed for instruction: " << std::hex << instruction
            << ", immSrc: " << immSrc << ", jumpSrc: " << jumpSrc;
    }
};

TEST_F(ExtendTest, TestImmSrc00) {
    setupTest("extend_tb");
    initSimulation();

    // Test immSrc = 2'b00
    TestExtend(0x12345678, 0b00, 0, 0xFFFFF678);
    TestExtend(0x80000555, 0b00, 0, 0xFFFFF555);
}

TEST_F(ExtendTest, TestImmSrc01) {
    setupTest("extend_tb");
    initSimulation();

    // Test immSrc = 2'b01
    TestExtend(0x12345678, 0b01, 0, 0xFFFF6785);
    TestExtend(0x80000555, 0b01, 0, 0xFFFF5558);
}

TEST_F(ExtendTest, TestImmSrc10) {
    setupTest("extend_tb");
    initSimulation();

    // Test immSrc = 2'b10
    TestExtend(0x12345678, 0b10, 0, 0x00123450);
    TestExtend(0x80000555, 0b10, 0, 0xFFFFFFF0);
}

TEST_F(ExtendTest, TestImmSrc11Jump) {
    setupTest("extend_tb");
    initSimulation();

    // Test immSrc = 2'b11 with jumpSrc = 1
    TestExtend(0x12345678, 0b11, 1, 0x04D678);
    TestExtend(0x80000555, 0b11, 1, 0xFFFFD0);
}

TEST_F(ExtendTest, TestImmSrc11NonJump) {
    setupTest("extend_tb");
    initSimulation();

    // Test immSrc = 2'b11 with jumpSrc = 0
    TestExtend(0x12345678, 0b11, 0, 0x12345600);
    TestExtend(0x80000555, 0b11, 0, 0x80000000);
}
