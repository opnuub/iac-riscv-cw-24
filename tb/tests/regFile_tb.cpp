//IGNORE THIS TEST
#include "cpu_testbench.h"

// Test writing and reading from registers in the regFile
TEST_F(CpuTestbench, RegFileReadWrite) {
    setupTest("regfile_test"); // Assemble and load the "regfile_test" program
    initSimulation();         // Initialize the simulation
    
    // Run enough cycles to execute the write and read operations
    runSimulation(50);

    // Example: Verify that writing to a register works as expected
    EXPECT_EQ(top_->register_file[2], 42); // Check if register x2 contains 42
    EXPECT_EQ(top_->register_file[3], 84); // Check if register x3 contains 84

    // Example: Verify that the zero register always contains 0
    EXPECT_EQ(top_->register_file[0], 0);  // x0 must always be 0
}

// Test the zero-register behavior
TEST_F(CpuTestbench, ZeroRegister) {
    setupTest("7_zero_register_test");
    initSimulation();

    // Run enough cycles to test the zero register logic
    runSimulation(30);

    // Assert that writes to the zero register have no effect
    EXPECT_EQ(top_->register_file[0], 0);  // x0 must remain 0 even after a write attempt
}