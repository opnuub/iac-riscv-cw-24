.global _start

_start:
    # Test LUI
    lui     x1, 0x12345     # Load upper immediate
    
    # Test AUIPC (add upper immediate to pc)
    auipc   x2, 0x1000     # PC + (0x1000 << 12)
    
    # Verify LUI result
    mv      a0, x1         # Should be 0x12345000

infinite:
    j       infinite