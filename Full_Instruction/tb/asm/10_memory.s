.global _start

_start:
    # Test word operations
    li      x1, 0x12345678    # Test value
    sw      x1, 0(x0)         # Store word
    lw      x2, 0(x0)         # Load word
    
    # Test halfword operations
    li      x3, 0xABCD        # Test value
    sh      x3, 4(x0)         # Store halfword
    lh      x4, 4(x0)         # Load signed halfword
    lhu     x5, 4(x0)         # Load unsigned halfword
    
    # Test byte operations
    li      x6, 0xFF          # Test value
    sb      x6, 8(x0)         # Store byte
    lb      x7, 8(x0)         # Load signed byte
    lbu     x8, 8(x0)         # Load unsigned byte
    
    # Verify results: Check the word load
    mv      a0, x2            # Should be 0x12345678

infinite:
    j       infinite
    