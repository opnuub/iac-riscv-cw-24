# Define memory-mapped I/O locations for branchUnit inputs and outputs
.srcA      = 0x20000000   # Memory location for srcA
.srcB      = 0x20000004   # Memory location for srcB
.aluCtrl   = 0x20000008   # Memory location for aluControl
.zero      = 0x2000000C   # Memory location for zero output

.section .data
# Test cases: srcA, srcB, aluControl, expected zero
test_cases:
    .word 10, 10, 0b000, 1    # Case 1: srcA == srcB, zero = 1 (Equality check)
    .word 10, 20, 0b001, 1    # Case 2: srcA != srcB, zero = 1 (Inequality check)
    .word -5, 3,  0b100, 1    # Case 3: srcA < srcB (signed), zero = 1
    .word 5, -3, 0b101, 1     # Case 4: srcA >= srcB (signed), zero = 1
    .word 5, 10, 0b110, 1     # Case 5: srcA < srcB (unsigned), zero = 1
    .word 10, 5, 0b111, 1     # Case 6: srcA >= srcB (unsigned), zero = 1
    .word 0, 0,  0b011, 0     # Default case, zero = 0
test_count:
    .word 7                   # Number of test cases

.section .text
.global _start
_start:
    # Load the base address of test cases into t0
    la t0, test_cases

    # Load the number of test cases into t1
    lw t1, test_count

    # Set up a loop counter in t2
    li t2, 0

test_loop:
    # Load srcA, srcB, aluControl, and expected zero from memory
    lw t3, 0(t0)      # srcA
    lw t4, 4(t0)      # srcB
    lw t5, 8(t0)      # aluControl
    lw t6, 12(t0)     # expected zero

    # Write srcA and srcB to memory-mapped inputs
    sw t3, .srcA
    sw t4, .srcB
    sw t5, .aluCtrl

    # Read zero output from memory-mapped location
    lw t7, .zero

    # Compare zero output with expected zero
    bne t7, t6, fail_case

    # Advance to the next test case
    addi t0, t0, 16
    addi t2, t2, 1

    # Check if all test cases are done
    blt t2, t1, test_loop

    # If all tests pass, halt successfully
    li a0, 0
    ecall

fail_case:
    # If a test fails, halt with an error code
    li a0, 1
    ecall
