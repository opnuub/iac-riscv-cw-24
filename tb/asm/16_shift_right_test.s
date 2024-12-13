.global _start

_start:
    # Test setup - load test values
    li x1, -8        # Load negative number (0xFFFFFFF8)
    li x2, 2         # Shift amount
    
    # Test logical right shift (SRL)
    srl x3, x1, x2   # Should fill with zeros
    
    # Test logical right shift immediate (SRLI)
    srli x4, x1, 2   # Should give same result as SRL
    
    # Test arithmetic right shift (SRA)
    sra x5, x1, x2   # Should preserve sign bit
    
    # Test arithmetic right shift immediate (SRAI)
    srai x6, x1, 2   # Should give same result as SRA
    
    # Compare SRA and SRAI results
    sub x7, x5, x6   # Should be zero if they match
    
    # Move arithmetic shift result to a0 for verification
    mv a0, x5        # Should be -2 (0xFFFFFFFE)

infinite:
    j infinite