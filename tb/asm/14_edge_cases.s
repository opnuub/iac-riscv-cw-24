.global _start

_start:
    # Test arithmetic overflow
    li      x1, 0x7FFFFFFF     # Max positive value
    addi    x2, x1, 1          # Should overflow to negative
    
    # Test negative to positive transition
    li      x3, 0x80000000     # Min negative value
    addi    x4, x3, -1         # Should underflow to positive
    
    # Test maximum shift values
    li      x5, 1
    slli    x6, x5, 31         # Maximum left shift
    srai    x7, x6, 31         # Maximum right shift
    
    # Test signed vs unsigned comparison
    li      x8, -1             # 0xFFFFFFFF
    li      x9, 1
    slt     x10, x8, x9        # Signed: -1 < 1 = 1
    sltu    x11, x8, x9        # Unsigned: 0xFFFFFFFF < 1 = 0
    
    # Store the maximum negative number result
    mv      a0, x3             # Should be 0x80000000

infinite:
    j       infinite