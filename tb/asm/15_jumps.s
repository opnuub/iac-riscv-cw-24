.global _start

_start:
    # Initialize result
    li a0, 0x12345678

    # 1. Basic jump (j)
    j next1
    li a0, 0xBAD1     # Should be skipped
next1:

    # 2. Jump and link (jal)
    jal ra, next2     # Save return address in ra
    li a0, 0xBAD2     # Should be skipped
next2:

    # 3. Jump and link register (jalr)
    la t0, next3
    jalr zero, t0, 0  # Jump to next3
    li a0, 0xBAD3     # Should be skipped
next3:

    # 4. Branch if equal (beq)
    li t1, 5
    li t2, 5
    beq t1, t2, next4
    li a0, 0xBAD4     # Should be skipped
next4:

    # 5. Branch if not equal (bne)
    li t1, 6
    li t2, 7
    bne t1, t2, next5
    li a0, 0xBAD5     # Should be skipped
next5:

    # 6. Branch if less than (blt)
    li t1, 5
    li t2, 10
    blt t1, t2, next6
    li a0, 0xBAD6     # Should be skipped
next6:

    # 7. Branch if greater/equal (bge)
    li t1, 10
    li t2, 5
    bge t1, t2, next7
    li a0, 0xBAD7     # Should be skipped
next7:

    # 8. Branch if less than unsigned (bltu)
    li t1, 0
    li t2, -1         # -1 is largest unsigned value
    bltu t1, t2, next8
    li a0, 0xBAD8     # Should be skipped
next8:

    # 9. Branch if greater/equal unsigned (bgeu)
    li t1, -1         # Largest unsigned value
    li t2, 5
    bgeu t1, t2, done
    li a0, 0xBAD9     # Should be skipped

done:
    j infinite        # All tests passed, a0 still contains 0x12345678

infinite:
    j infinite
    