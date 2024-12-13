.global _start

_start:
    # Test logical right shift (srl)
    li x1, 0xF0       # Load 1111 0000
    srli x2, x1, 4    # Shift right by 4, should be 0000 1111
    
    # Test logical right shift with register
    li x3, 4          # Number of positions to shift
    srl x4, x1, x3    # Should be same as srli x2, x1, 4
    
    # Test arithmetic right shift (sra)
    li x5, -8         # Load negative number
    srai x6, x5, 1    # Shift right by 1, should preserve sign bit
    
    # Test arithmetic right shift with register
    li x7, 1          # Number of positions to shift
    sra x8, x5, x7    # Should be same as srai x6, x5, 1
    
    # Store result in a0 for checking
    add a0, x2, x0    # Move result to a0
    
infinite:
    j infinite        # Infinite loop