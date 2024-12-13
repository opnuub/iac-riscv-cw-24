.global _start

_start:
    # Test AND operations
    li      x1, 0xFF       # Load 0xFF
    li      x2, 0xF0       # Load 0xF0
    and     x3, x1, x2     # 0xFF & 0xF0 = 0xF0
    andi    x4, x1, 0x0F   # 0xFF & 0x0F = 0x0F
    
    # Test OR operations
    li      x5, 0x0F       # Load 0x0F
    or      x6, x2, x5     # 0xF0 | 0x0F = 0xFF
    ori     x7, x2, 0x0F   # 0xF0 | 0x0F = 0xFF
    
    # Test XOR operations
    li      x8, 0xAA       # Load 0xAA
    li      x9, 0x55       # Load 0x55
    xor     x10, x8, x9    # 0xAA ^ 0x55 = 0xFF
    xori    x11, x8, 0x55  # 0xAA ^ 0x55 = 0xFF
    
    # Verify results (0xFF if all tests pass)
    xor     x12, x6, x10   # Should be 0 if both are 0xFF
    add     a0, x6, x0     # Move result (0xFF) to a0

infinite:
    j       infinite