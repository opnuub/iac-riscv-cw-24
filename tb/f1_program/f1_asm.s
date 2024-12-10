# This is our F1 assembly code instruction

main:
    lw      s0, 0(t2)          # Load word from memory address in t2 into s0
    addi    t1, zero, 0x1      # Set a condition value (e.g., 1) into t1
    addi    a2, zero, 0x1
    #beq     a2, t1, call_subroutine  # Branch to subroutine if a2 == t1
    j        call_subroutine
    addi    a0, zero, 0x0      # Reset a0 to 0
    j       main               # Unconditional jump back to loop
    ret


call_subroutine:
    sw      ra, 0(sp)
    jal     ra, subroutine
    lw      ra, 0(sp)
    addi    sp,sp,4
    ret 


subroutine:
    addi 	a0, zero, 0x1
    addi 	a0, zero, 0x3
    addi 	a0, zero, 0x7
    addi 	a0, zero, 0xf
    addi 	a0, zero, 0x1f
    addi 	a0, zero, 0x3f
    addi 	a0, zero, 0x7f
    addi    a0, zero, 0xff
    ret