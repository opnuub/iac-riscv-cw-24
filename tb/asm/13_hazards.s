.global _start

_start:
    # Test RAW (Read After Write) hazards
    li      x1, 10
    addi    x2, x1, 1      # Use x1 immediately
    addi    x3, x2, 1      # Use x2 immediately
    
    # Test load-use hazard
    sw      x1, 0(x0)      # Store to memory
    lw      x4, 0(x0)      # Load from memory
    addi    x5, x4, 1      # Use loaded value immediately
    
    # Test forwarding from memory stage
    sw      x2, 4(x0)      # Store x2
    lw      x6, 4(x0)      # Load x2's value
    add     x7, x6, x5     # Use value from memory
    
    # If all hazards handled correctly
    # x7 should be: (10 + 1) + (10 + 1)
    mv      a0, x7         # Should be 22

infinite:
    j       infinite