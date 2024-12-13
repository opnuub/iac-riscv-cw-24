.global _start

_start:
    # Test AUIPC with different immediates
    auipc x1, 0x0    # Get current PC
    auipc x2, 0x1    # PC + (0x1 << 12)
    auipc x3, 0x2    # PC + (0x2 << 12)
    
    # Calculate differences to verify offsets
    sub x4, x2, x1   # Should be 0x1000
    sub x5, x3, x2   # Should be 0x1000
    
    # Combine results
    add x6, x4, x5   # Should be 0x2000
    
    # Move to a0 for verification
    mv a0, x6        # Should be 0x2000 (8192 in decimal)

infinite:
    j infinite
    