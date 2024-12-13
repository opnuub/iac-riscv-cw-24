.global _start

_start:
    # Test AUIPC (Add Upper Immediate to PC)
    auipc x1, 0x1    # Add (0x1 << 12) to PC
    auipc x2, 0x0    # Get current PC
    sub x3, x1, x2   # Should be 0x1000
    
    # Test SRA with a fixed shift amount
    li x4, -1024     # Load negative number (0xFFFFFC00)
    li x5, 4         # Load shift amount 4
    sra x6, x4, x5   # Shift right by 4, should be -64 (0xFFFFFFC0)
    
    # Move result to a0 for verification
    mv a0, x6        # Should be -64

infinite:
    j infinite