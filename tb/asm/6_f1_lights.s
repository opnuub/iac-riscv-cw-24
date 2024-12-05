# This is our F1 assembly code instruction

main: 
    li 		t2, 0x2000
loop:
    lw      s0, 0(t2)          # Load word from memory address in t2 into s0
    addi    t1, zero, 0x1      # Set a condition value (e.g., 1) into t1
    j     call_subroutine     # Branch to subroutine if s0 == t1 --> switched to j call_subroutine to make testing easier
    addi    a0, zero, 0x0      # Reset a0 to 0
    j       loop               # Unconditional jump back to loop
    ret


call_subroutine:
    sw      ra, 0(sp)
    jal     ra, subroutine
    lw      ra, 0(sp)
    addi    sp,sp,4
    ret


subroutine:
    addi 	a0, zero, 0x1
    addi 	a0, zero, 0x2
    addi 	a0, zero, 0x3
    addi 	a0, zero, 0x4
    addi 	a0, zero, 0x5
    addi 	a0, zero, 0x6
    addi 	a0, zero, 0x7
    addi    a0, zero, 0x8
    ret