.global _start

_start:
    li      x1, 10          # Test value
    li      x2, 20          # Test value
    li      x3, 0           # Counter

    # Test beq/bne
    beq     x1, x1, test1   # Should branch
    j       fail
test1:
    addi    x3, x3, 1       # Counter++
    bne     x1, x2, test2   # Should branch
    j       fail
test2:
    addi    x3, x3, 1       # Counter++

    # Test blt/bge
    blt     x1, x2, test3   # Should branch (10 < 20)
    j       fail
test3:
    addi    x3, x3, 1       # Counter++
    bge     x2, x1, test4   # Should branch (20 >= 10)
    j       fail
test4:
    addi    x3, x3, 1       # Counter++

    # Test bltu/bgeu
    li      x4, 0xFFFFFFFF  # Maximum unsigned value
    bltu    x2, x4, test5   # Should branch
    j       fail
test5:
    addi    x3, x3, 1       # Counter++
    bgeu    x4, x2, test6   # Should branch
    j       fail
test6:
    addi    x3, x3, 1       # Counter++
    
    # If all tests pass, x3 should be 6
    mv      a0, x3          # Move result to a0
    j       end

fail:
    li      a0, 0           # Test failed

end:
infinite:
    j       infinite
    