.global _start

_start:
    # Test signed comparisons
    li      x1, -10           # Negative number
    li      x2, 5             # Positive number
    slt     x3, x1, x2        # -10 < 5 = 1
    slti    x4, x1, 0         # -10 < 0 = 1
    
    # Test unsigned comparisons
    li      x5, 0xFFFFFFFF    # Maximum unsigned value
    li      x6, 5             # Small positive number
    sltu    x7, x6, x5        # 5 < 0xFFFFFFFF = 1
    sltiu   x8, x6, -1        # 5 < 0xFFFFFFFF = 1
    
    # Combine results: x3, x4, x7, x8 should all be 1
    add     x9, x3, x4        # Should be 2
    add     x10, x7, x8       # Should be 2
    add     a0, x9, x10       # Should be 4 if all tests pass

infinite:
    j       infinite
    