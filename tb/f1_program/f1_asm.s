main:
    addi    t0, zero, 0x1
    jal     ra, subroutine
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
    li      a0, 0x0
