main: 
    li      t2, 0x2000           # Load base address for light control (or some other value)
    addi    t2, zero, 0x7        # Set a condition value (e.g., 7 lights in the sequence)
loop:
    lw      s0, 0(t2)            # Load word from memory address in t2 into s0 (simulate reading light status)
    addi    t1, zero, 0x1        # Set a condition value (e.g., 1) into t1
    beq     s0, t1, call_subroutine # If condition is met, jump to call_subroutine
    addi    a0, zero, 0x0        # Reset a0 to 0
    j       loop                 # Jump back to loop

call_subroutine:
    # Simulate light control sequence
    addi    sp, sp, -4           # Allocate stack space
    sw      t0, 0(sp)            # Save the return address (t0 will act as the return pointer)
    la      t0, ret_call_subroutine # Store the return label address in t0
    j       subroutine           # Jump to subroutine

ret_call_subroutine:
    lw      t0, 0(sp)            # Restore the return address
    addi    sp, sp, 4            # Restore stack pointer
    j       t0                   # Return to the caller

subroutine:
    addi    a0, zero, 0x1        # Turn on 1st light (bit 0)
    addi    a0, zero, 0x3        # Turn on 2nd light (bit 1)
    addi    a0, zero, 0x7        # Turn on 3rd light (bit 2)
    addi    a0, zero, 0xf        # Turn on 4th light (bit 3)
    addi    a0, zero, 0x1f       # Turn on 5th light (bit 4)
    addi    a0, zero, 0x3f       # Turn on 6th light (bit 5)
    addi    a0, zero, 0x7f       # Turn on 7th light (bit 6)
    
    # Random delay for the last light
    # The random delay value is assumed to be in a1
    # Wait until the value in a1 is non-zero before continuing
    beq     a1, zero, final_subroutine  # Jump to final_subroutine only if a1 is non-zero
    j       t0                   # Return to the caller

final_subroutine:
    # Turn on the last light after random delay
    addi    a0, zero, 0xff       # Turn on all lights (bit 7 is the last light)
    j       t0                   # Return to the caller
