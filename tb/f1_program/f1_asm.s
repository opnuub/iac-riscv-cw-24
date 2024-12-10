main: 
    li     t2, 0x2000        # Load 0x2000 into t2
    li     t1, 0x2000        # Load 0x2000 into t1 for comparison

loop:
    lw      s0, 0(t2)        # Load word from memory address in t2 into s0
    addi    t1, x0, 0x2000   # Set t1 to 0x2000 for comparison (x0 is the zero register)
    beq     t2, t1, call_subroutine  # Branch to call_subroutine if t2 == t1
    addi    a0, x0, 0x0      # Reset a0 to 0
    j       loop             # Unconditional jump back to loop

call_subroutine:
    sw      ra, 0(sp)        # Save return address
    jal     ra, subroutine   # Jump and link to subroutine
    lw      ra, 0(sp)        # Restore return address
    addi    sp, sp, 4        # Adjust stack pointer
    ret

subroutine:
    addi   a0, x0, 0x1      # Set a0 to 1
    addi   a0, x0, 0x3      # Set a0 to 3
    addi   a0, x0, 0x7      # Set a0 to 7
    addi   a0, x0, 0xf      # Set a0 to 15
    addi   a0, x0, 0x1f     # Set a0 to 31
    addi   a0, x0, 0x3f     # Set a0 to 63
    addi   a0, x0, 0x7f     # Set a0 to 127
    addi   a0, x0, 0xff     # Set a0 to 255
    ret
