# RISC-V CPU Memory System and Pipeline Control Implementation
## Personal Statement of Contributions

### Project Overview

In this RISC-V CPU project, I was primarily responsible for designing and implementing the memory system architecture and pipeline control. When I first received this task, I recognized the significant impact of the memory system on CPU performance. Consequently, I decided to implement a three-level cache structure to balance memory access latency and hardware overhead.

### Cache System Design

#### Multi-level Cache Architecture

In designing the cache system, I adopted a hierarchical approach. I first implemented the L1 cache, then gradually added L2 and L3 caches. Each cache level had its specific design considerations:

**L1 Cache Design Approach**:
```verilog
typedef struct packed {
    logic valid;
    logic dirty;
    logic [TAG_WIDTH-1:0] tag;
    logic [DATA_WIDTH-1:0] data;
} line_t;
```

I chose a 2-way set-associative structure after weighing several factors:
- Direct mapping, while simple, has a high conflict miss rate
- Full associativity, while having a low miss rate, has high hardware complexity and power consumption
- 2-way set-associative strikes a good balance between these extremes

The implementation of the LRU replacement policy was an interesting challenge. Initially, I considered using counters but found that a bitmap approach was more efficient:
```verilog
logic [2**SET_WIDTH-1:0] lru;
...
lru[index] <= !way;
```

#### Cache State Machine

The cache state machine design underwent multiple iterations. The initial version only had simple read/write states, but timing issues emerged when handling write-backs and cache replacements. The final state machine implementation includes five states:

```verilog
typedef enum logic [2:0] {
    IDLE,
    READ_MISS,
    WRITE_MISS,
    WRITE_BACK,
    UPDATE
} state_t;
```

Each state was carefully considered:
- IDLE state implements hit check logic
- READ_MISS and WRITE_MISS are handled separately for code clarity
- WRITE_BACK state manages dirty data write-back
- UPDATE state handles cache line updates uniformly

### Memory Controller Implementation

Implementing the memory controller was particularly challenging. I needed to handle access requests of different data widths while managing interactions between three cache levels.

The most complex part was handling alignment and extension:
```verilog
case (SizeCtr)
    3'b010: // Word
        main_mem_data = {main_memory[addr+3], main_memory[addr+2], 
                       main_memory[addr+1], main_memory[addr]};
    3'b001: // Halfword (signed)
        main_mem_data = {{16{main_memory[addr+1][7]}}, 
                       main_memory[addr+1], main_memory[addr]};
```

The sign extension logic appears simple, but debugging revealed several subtle issues:
- Byte order choice affects data correctness
- Sign extension needs to consider requirements of different instructions
- Address alignment requires special handling

### Pipeline Hazard Control

Pipeline hazard handling is one of the aspects I'm most proud of. Implementing this part deepened my understanding of instruction dependencies.

Data hazard handling employs forwarding techniques:
```verilog
if (RegWriteM && (destReg_m != 5'b0) && (destReg_m == Rs1E)) begin
    ForwardAE = 2'b10; // Forward from Memory stage
end
```

A key discovery during implementation was that not all data hazards require pipeline stalls. Through careful analysis of instruction dependencies, I implemented selective forwarding logic, significantly improving performance.

### Technical Challenges

During the project, I encountered several interesting technical challenges:

1. **Cache Coherency Issues**

The initial design showed data inconsistencies during write-backs. Through careful waveform analysis, I found timing issues in state transitions. The solution involved:
- Introducing dirty bits to track modifications
- Implementing write-back buffers
- Optimizing state transition logic

2. **Load-Use Hazard Handling**
```verilog
assign load_use_hazard = memoryRead_e &&
    ((RdE == Rs1D && Rs1D != 5'b0) || (RdE == Rs2D && Rs2D != 5'b0));
```
This problem was particularly interesting as it involved balancing performance and correctness. My initial implementation always inserted bubbles, but I later optimized it to stall only when necessary.

### Testing Strategy

The testing strategy evolved progressively:

1. **Functional Verification**
- Wrote dedicated test programs
- Used waveform analysis for timing verification
- Implemented assertions for checking critical properties

2. **Performance Testing**

Developed a specialized test platform to measure:
- Cache hit rates
- Pipeline stall frequency
- Instruction throughput

### Personal Reflection

This project provided many insights. The biggest takeaway was understanding the importance of trade-offs in hardware design:
- Balance between performance and complexity
- Trade-offs between functionality completeness and implementation difficulty
- Balance between debugging convenience and hardware overhead

An interesting observation: while implementing advanced features, I often found ways to improve basic components, highlighting the importance of initial planning.

### Future Improvements

1. **Cache Optimization**
- Implement smarter prefetching mechanisms
- Optimize replacement strategies
- Add performance counters

2. **Pipeline Improvements**
- Implement dynamic branch prediction
- Optimize hazard detection logic
- Add more debugging capabilities

### Conclusion

This project not only enhanced my technical skills but also transformed my understanding of hardware design. I learned:
- How to systematically analyze and solve complex problems
- Making reasonable design decisions under various constraints
- Writing clear, maintainable hardware description code

Finally, I believe the project's success lies in not only achieving the intended functionality but also establishing a solid architectural foundation for future improvements. While there's room for optimization, the current implementation demonstrates a complete solution for RISC-V CPU memory system and pipeline control.

Looking forward, I hope to apply these experiences in more complex processor design projects, particularly in optimizing cache coherency and branch prediction.