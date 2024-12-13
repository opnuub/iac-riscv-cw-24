# Personal Statement for RISC-V RV32I Processor Coursework

### Statement Overview

1. [Project Overview](#project-overview)
   - [Introduction](#introduction)
   - [Goals and Objectives](#goals-and-objectives)
   - [Development Timeline](#development-timeline)

2. [Single-Cycle CPU Contribution](#cpu-design-and-implementation)
   - [Single Cycle CPU](#single-cycle-cpu)
   - [Component Development](#component-development)
     - [ControlUnit](#controller)
     - [Instruction Memory Unit](#memory-units)
     - [Testbench](#testbenches)

3. [Cache System Architecture](#cache-system-architecture)
   - [Cache Hierarchy](#cache-hierarchy)
     - [L1 Cache](#l1-cache)
     - [L2 Cache](#l2-cache)
     - [L3 Cache](#l3-cache)
     - [Testbench](#tb-cache)
   - [Memory Controller](#memory-controller)
   - [Cache Line Structure](#cache-line-structure)
   - [State Machine Implementation](#state-machine-implementation)
   - [Memory Access Flow](#memory-access-flow)

4. [Integrate Cache into Pipeline](#pipeline-implementation)
   - [Hazard Unit](#hazard-unit)
     - [Data Hazards](#data-hazards)
     - [Control Hazards](#control-hazards)
     - [Memory Stall](#memory-stall)
   - [Forwarding Unit](#forwarding-unit)
   - [Pipeline Stages](#pipeline-stages)

5. [Reflections and Learnings](#reflections-and-learnings)
   - [Technical Insights](#technical-insights)
   - [Future Improvements](#future-improvements)


## CPU Design and Implementation: A Personal Journey

### Initial Group Work Allocation

The first week was dedicated to understanding the fundamentals of a full-cycle single CPU. This period was marked by intense study and hands-on exploration, Our group started allocation of work distribution, which I have been assigned with the following parts: 
Single-Cycle CPU
- Controller Units
- Instruction Memory
- Unit Testing
Cache: Two-Way Set Associate
Full RISCV CPU Implementation

## Single Cycle Component Development

As I progressed, I began to develop individual components of the CPU, each in its own SystemVerilog file with Unit Testing and Testbenches for further development before integration. This modular approach allowed for a systematic and organized development process. Here's a detailed breakdown of the components I worked with:

- **Controller.sv**: The controller module managed the overall operation of the CPU, coordinating between different components to ensure smooth execution of instructions, since I have developed this part in the Lab 4. I modified the control units to implement more instructions. While our group used a simplified version for Pipelining, I developed this Controller which was used later in Stretched Goal.

To decode RISC-V instructions and generate control signals for components like the ALU, register file, memory, and PC, I designed and implemented a RISC-V controller module in SystemVerilog. Below is a breakdown of the design process and key implementation details:

Key Instruction Mapping Example
| **Instruction Type** | **Key Signals**                                    | **Logic Implemented**                                             |
|-----------------------|---------------------------------------------------|--------------------------------------------------------------------|
| **R-Type**            | `rf_wen_o = 1`, ALU operation via `funct3_i`/`funct7_i` | Configures ALU for register-based operations like ADD, AND, etc.  |
| **I-Type**            | `alu_src2_sel_o = 01`, `imm_type_o = IMM_I`       | Handles immediate values for ALU operations (e.g., ADDI, ORI).    |
| **Load**              | `rf_wen_o = 1`, `rf_wdata_sel_o = 01`             | Reads from memory and writes to a register.                       |
| **Store**             | `mem_wen_o = 1`, `imm_type_o = IMM_S`             | Writes data from a register to memory.                            |
| **Branch**            | `next_pc_sel_o` set via branch condition signals  | Updates PC based on conditions like BEQ or BLT.                   |
| **Jump (JAL/JALR)**   | `rf_wdata_sel_o = 10`, `next_pc_sel_o = 10/11`    | Saves return address and jumps to target.                         |

- **Instruction Memory (imem.sv)**: These modules simulated the memory components of a real CPU, allowing for the storage and retrieval of data and instructions.

### Testing and Validation

To ensure the correctness and reliability of my designs, I meticulously wrote unit test benches for each component. These test benches simulated various scenarios and edge cases, allowing me to identify and rectify any issues in the design. The process of testing and validation was iterative, with each iteration bringing me closer to a fully functional and efficient CPU.

# Cache System Design and Implementation Analysis

## 1. Core Cache Architecture
### 1.1 Cache Line Structure
Since one of the stretched goals was to specifically designa a two way set associate cache, so we have started to design the first cache based on this structure. :

```systemverilog
typedef struct packed {
    logic valid;           // Valid bit
    logic dirty;           // Dirty bit for write-back
    logic [TAG_WIDTH-1:0] tag;  // Tag bits
    logic [DATA_WIDTH-1:0] data; // Actual data
} line_t;
```

This structure is the fundamental building block for each cache line. The tag width is dynamically calculated based on the set width:
```systemverilog
parameter TAG_WIDTH = DATA_WIDTH - SET_WIDTH - 2
```

### 1.2 Cache Array Organization
```systemverilog
line_t cache[2**SET_WIDTH][2];  // Two-way set associative
logic [2**SET_WIDTH-1:0] lru;   // LRU bits for each set
```

The cache is organized as a 2D array where:
- First dimension: Number of sets (2^SET_WIDTH)
- Second dimension: Two ways (fixed for two-way set associative)

## 2. Address Decomposition Algorithm

### 2.1 Address Fields
```systemverilog
logic [TAG_WIDTH-1:0] tag;
logic [SET_WIDTH-1:0] index;
logic way;
logic hit_way;

assign tag = address[DATA_WIDTH-1:SET_WIDTH+2];
assign index = address[SET_WIDTH+1:2];
```

### 2.2 Hit Detection Logic
```systemverilog
always_comb begin
    hit = 0;
    hit_way = 0;

    if (cache[index][0].valid && cache[index][0].tag == tag) begin
        hit = 1;
        hit_way = 0;
    end else if (cache[index][1].valid && cache[index][1].tag == tag) begin
        hit = 1;
        hit_way = 1;
    end

    way = lru[index];
    if (!cache[index][0].valid) way = 0;
    else if (!cache[index][1].valid) way = 1;
end
```

## 3. Cache Controller State Machine

### Detailed Analysis

To provide a detailed analysis of the cache design, I created a hierarchy diagram that illustrated the structure and interactions of the various components involved. This diagram served as a visual aid, helping me and my team understand the flow of data and control within the cache system.

### 3.1 State Definitions
```systemverilog
typedef enum logic [2:0] {
    IDLE,
    READ_MISS,
    WRITE_MISS,
    WRITE_BACK,
    UPDATE
} state_t;
```
```mermaid
stateDiagram-v2, DRAW IT LATER!
    [*] --> IDLE
    
    IDLE --> READ_MISS: Miss && Load
    IDLE --> WRITE_MISS: Miss && Store
    IDLE --> WRITE_BACK: Miss && Dirty
    IDLE --> IDLE: Hit
    
    WRITE_BACK --> READ_MISS: Load Operation
    WRITE_BACK --> WRITE_MISS: Store Operation
    
    READ_MISS --> UPDATE: Memory Ready
    WRITE_MISS --> UPDATE: Direct Transition
    
    UPDATE --> IDLE: Operation Complete
```

### 3.2 State Transition Implementation
```systemverilog
always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
        state <= IDLE;
        busy <= 0;
        mem_read <= 0;
        mem_write <= 0;
        lru <= 0;
        // Initialize cache lines
        for (int i = 0; i < 2**SET_WIDTH; i++) begin
            cache[i][0] <= '0;
            cache[i][1] <= '0;
        end
    end else begin
        case (state)
            IDLE: begin
                // IDLE state logic
            end
            // Other states
        endcase
    end
end
```
### 1.3 State Details

#### IDLE State
```systemverilog
IDLE: begin
    if (miss) begin
        busy <= 1;
        if (cache[index][way].valid && cache[index][way].dirty) begin
            mem_write <= 1;
            state <= WRITE_BACK;
        end else if (load) begin
            mem_read <= 1;
            state <= READ_MISS;
        end else begin
            state <= WRITE_MISS;
        end
    end else begin
        busy <= 0;
        mem_write <= 0;
        mem_read <= 0;
        if (hit && store) begin
            cache[index][hit_way].data <= data_in;
            cache[index][hit_way].dirty <= 1;
            lru[index] <= !hit_way;
        end else if (store) begin
            cache[index][way].dirty <= 1;
        end
    end
end
```

Key Operations:
1. Hit detection
2. Miss handling initiation
3. LRU update on hits
4. Dirty bit management

#### WRITE_BACK State
```systemverilog
WRITE_BACK: begin
    if (mem_ready) begin
        mem_write <= 0;
        mem_read <= load;
        state <= load ? READ_MISS : WRITE_MISS;
    end
end
```

Key Operations:
1. Write dirty data to memory
2. Wait for memory acknowledgment
3. Transition based on original operation

#### READ_MISS State
```systemverilog
READ_MISS: begin
    if (mem_ready) begin
        mem_read <= 0;
        state <= UPDATE;
    end
end
```

Key Operations:
1. Wait for memory read completion
2. Prepare for cache update

#### WRITE_MISS State
```systemverilog
WRITE_MISS: begin
    state <= UPDATE;
end
```

Key Operations:
1. Direct transition to update
2. No memory wait required

#### UPDATE State
```systemverilog
UPDATE: begin
    busy <= 0;
    cache[index][way].valid <= 1;
    cache[index][way].dirty <= store;
    cache[index][way].tag <= tag;
    cache[index][way].data <= store ? data_in : mem_data;
    lru[index] <= !way;
    state <= IDLE;
end
```

Key Operations:
1. Update cache line
2. Set validity and dirty bits
3. Update LRU
4. Return to IDLE

## 2. LRU Implementation Details

### 2.1 LRU Bit Structure
```systemverilog
logic [2**SET_WIDTH-1:0] lru;  // One bit per set
```

### 2.2 LRU Update Logic Diagram

```mermaid
graph TD
    A[Cache Access] --> B{Hit?}
    B -->|Yes| C[Update LRU for Hit]
    B -->|No| D[Update LRU for Miss]
    
    C --> E[lru[index] = !hit_way]
    D --> F[lru[index] = !way]
    
    E --> G[Next Access]
    F --> G
```

### 2.3 LRU Decision Process

1. **On Cache Hit:**
```systemverilog
if (hit && store) begin
    cache[index][hit_way].data <= data_in;
    cache[index][hit_way].dirty <= 1;
    lru[index] <= !hit_way;  // Mark other way as LRU
end
```

2. **On Cache Miss:**
```systemverilog
way = lru[index];  // Select LRU way for replacement
if (!cache[index][0].valid) way = 0;
else if (!cache[index][1].valid) way = 1;
```

3. **After Replacement:**
```systemverilog
lru[index] <= !way;  // Mark current way as most recently used
```

### 2.4 LRU Implementation Analysis

The LRU implementation uses a single bit per set where:
- `lru[index] = 0`: Way 1 is least recently used
- `lru[index] = 1`: Way 0 is least recently used

Benefits of this implementation:
1. Minimal hardware overhead (single bit per set)
2. Simple update logic
3. Fast LRU determination
4. Efficient way selection

## 4. Memory Controller Design

### 4.1 Controller Interface
```systemverilog
module MemoryController #(
    parameter DATA_WIDTH = 32,
    parameter ADDR_WIDTH = 17
) (
    input  logic                   clk,
    input  logic                   rst_n,
    input  logic                   MemWrite,
    input  logic [2:0]            SizeCtr,
    input  logic [ADDR_WIDTH-1:0] addr,
    input  logic [DATA_WIDTH-1:0] WriteData,
    output logic [DATA_WIDTH-1:0] ReadData,
    output logic                  MemReady
);
```

### 4.2 Cache Level Interconnection
The memory controller manages the interconnection between cache levels through internal signals:

```systemverilog
// L1 Cache signals
logic l1_hit, l1_miss, l1_mem_write, l1_mem_read, l1_busy;
logic [DATA_WIDTH-1:0] l1_data_out, l1_mem_write_data;

// L2 Cache signals
logic l2_hit, l2_miss, l2_mem_write, l2_mem_read, l2_busy;
logic [DATA_WIDTH-1:0] l2_data_out, l2_mem_write_data;

// L3 Cache signals
logic l3_hit, l3_busy;
logic [DATA_WIDTH-1:0] l3_data_out;
```

## 5. Cache Level Implementations

### 5.1 L1 Cache
```systemverilog
L1Cache #(
    .DATA_WIDTH(DATA_WIDTH),
    .SET_WIDTH(5)
) l1_cache (
    .clk(clk),
    .rst_n(rst_n),
    .load(!MemWrite && mem_access),
    .store(MemWrite && mem_access),
    .address({15'b0, addr}),
    .data_in(WriteData),
    .mem_data(l2_data_out),
    .mem_ready(!l2_busy),
    // Other connections
);
```

### 5.2 L2 Cache
```systemverilog
L2Cache #(
    .DATA_WIDTH(DATA_WIDTH),
    .SET_WIDTH(6)
) l2_cache (
    .clk(clk),
    .rst_n(rst_n),
    .load(l1_mem_read),
    .store(l1_mem_write),
    .address({15'b0, addr}),
    .data_in(l1_mem_write_data),
    .mem_data(l3_data_out),
    .mem_ready(!l3_busy),
    // Other connections
);
```

### 5.3 L3 Cache
```systemverilog
L3Cache #(
    .DATA_WIDTH(DATA_WIDTH),
    .SET_WIDTH(6)
) l3_cache (
    .clk(clk),
    .rst_n(rst_n),
    .load(l2_mem_read),
    .store(l2_mem_write),
    .address({15'b0, addr}),
    .data_in(l2_mem_write_data),
    .mem_data(main_mem_data),
    .mem_ready(main_mem_ready_reg),
    // Other connections
);
```

## 6. Memory Access Implementation

### 6.1 Read Path Algorithm
```systemverilog
always_comb begin
    if (l1_hit) begin
        ReadData = l1_data_out;
        MemReady = 1;
    end else if (l2_hit) begin
        ReadData = l2_data_out;
        MemReady = 1;
    end else if (l3_hit) begin
        ReadData = l3_data_out;
        MemReady = 1;
    end else begin
        ReadData = main_mem_data;
        MemReady = main_mem_ready_reg && !l1_busy && !l2_busy && !l3_busy;
    end
end
```

### 6.2 Write Path Algorithm
```systemverilog
always_ff @(posedge clk) begin
    if (!rst_n) begin
        main_mem_ready_reg <= 0;
    end else if (MemWrite && !l1_hit && !l2_hit && !l3_hit) begin
        case (SizeCtr)
            3'b010: begin // Word
                main_memory[addr]     <= WriteData[7:0];
                main_memory[addr+1]   <= WriteData[15:8];
                main_memory[addr+2]   <= WriteData[23:16];
                main_memory[addr+3]   <= WriteData[31:24];
            end
            3'b001: begin // Halfword
                main_memory[addr]     <= WriteData[7:0];
                main_memory[addr+1]   <= WriteData[15:8];
            end
            3'b000: begin // Byte
                main_memory[addr]     <= WriteData[7:0];
            end
            default: ; 
        endcase
        main_mem_ready_reg <= 1;
    end
end
```

### Optimization and Future Directions

Reflecting on the cache design process, I recognize that there are several areas where further optimization is possible. For instance, exploring different replacement algorithms could enhance the cache's efficiency and reduce latency. Additionally, incorporating prefetching mechanisms could further improve the system's performance by anticipating and fetching data before it is needed.

## Reflections and Learnings

### 1. Deep Dive into Cache Design

The process of designing the cache was both challenging and enlightening. Initially, my understanding of caches was limited to their role as a bridge between data memory and the CPU. However, through this project, I gained a profound appreciation for the intricacies of cache design and its impact on system performance. I learned about various caching strategies, such as direct-mapped, set-associative, and fully associative caches, each with its own trade-offs in terms of complexity, cost, and performance.

Moreover, I delved into advanced topics such as cache coherence and consistency, which are crucial for multi-core systems. Understanding these concepts has sparked my interest in more advanced memory systems, including virtual memory and memory management units (MMUs).

### 2. Team Collaboration and Git Management

This project marked my first experience using Git for collaborative software development. The ability to track changes, manage branches, and merge code was invaluable, especially given the complexity and scale of our project. Through Git, I could monitor my teammates' progress, provide feedback, and contribute to the project in a structured and efficient manner.

Learning to navigate the Git workflow and resolve merge conflicts has significantly enhanced my software development skills. It has also taught me the importance of clear communication and coordination in team projects.

### 3. Testbench Development

Developing comprehensive testbenches was a critical aspect of ensuring the correctness and reliability of our designs. I invested significant time in writing and refining testbenches for each component, simulating various scenarios to uncover potential issues. This process taught me the importance of thorough testing and validation in the development lifecycle.

## Conclusion

The RISC-V RV32I Processor Coursework has been an invaluable learning experience, providing me with a deep understanding of CPU design, cache mechanisms, and collaborative software development. Through this project, I have not only honed my technical skills but also gained valuable insights into the complexities of system design and optimization. Looking ahead, I am eager to apply these learnings to more advanced projects and further explore the fascinating world of computer architecture and memory systems.