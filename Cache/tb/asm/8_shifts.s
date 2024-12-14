.global _start

_start:
    # Test logical left shifts
    li      x1, 1              # Load 1
    slli    x2, x1, 6         # 1 << 6 = 64 (0x40)
    sll     x3, x1, x2        # Should shift out of range
    
    # Test logical right shifts
    li      x4, 0xFFFFFFFF    # Load all 1s
    srli    x5, x4, 4         # 0xFFFFFFFF >> 4 = 0x0FFFFFFF
    li      x6, 4
    srl     x7, x4, x6        # Same as srli
    
    # Test arithmetic right shifts
    li      x8, 0x80000000    # Load negative number
    srai    x9, x8, 4         # Should preserve sign bit
    sra     x10, x8, x6       # Same as srai
    
    # Store test result
    mv      a0, x2            # Should be 0x40

infinite:
    j       infinite
    