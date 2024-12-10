# Pipeline CPU 

## Pipeline Registers

### Overview
Pipeline registers are essential components in a pipelined CPU. They store and propagate intermediate data and control signals between pipeline stages. This ensures that each stage operates independently and concurrently, maintaining the sequential flow of instruction execution.

---

### **PRegFetch** (Fetch → Decode)
#### Purpose
The `PRegFetch` module separates the Fetch stage from the Decode stage. It passes the program counter (PC), instruction, and PC+4 values to the Decode stage.

#### Inputs
- `instr`: Instruction fetched from memory.
- `PCf`: Current program counter.
- `PCPlus4F`: PC incremented by 4.
- `clk`: Clock signal for synchronization.
- `Flush`: Clears the pipeline when a hazard is detected.
- `rst`: Resets the register values to defaults.
- `stall`: Pauses updates to outputs during hazards.

#### Outputs
- `PCPlus4D`: PC+4 value passed to the Decode stage.
- `PCd`: Program counter passed to the Decode stage.
- `InstrD`: Instruction passed to the Decode stage.

#### Functionality
- On reset (`rst`) or flush (`Flush`), all outputs are set to default values (`0`).
- When `stall` is inactive, the fetched instruction, PC, and PC+4 values are stored and passed to the Decode stage.

---

### **PRegDecode** (Decode → Execute)
#### Purpose
The `PRegDecode` module separates the Decode stage from the Execute stage. It passes decoded data, control signals, and register values to the Execute stage.

#### Inputs
- **Data:**
  - `rd1`, `rd2`: Register data from the Decode stage.
  - `PCd`, `ImmExtD`, `PCPlus4D`: Program counter, sign-extended immediate value, and PC+4.
- **Control Signals:**
  - `RegWriteD`, `ResultSrcD`, `MemWriteD`, `JumpD`, `BranchD`, `ALUControl`, `ALUSrcD`, `sizeSrcD`, `jalrSrc`: Control signals from the Decode stage.
  - `Rs1D`, `Rs2D`, `RdD`: Source and destination register addresses.
- **Others:**
  - `clk`, `rst`, `Flush`.

#### Outputs
- **Data:**
  - `rd1E`, `rd2E`: Register data passed to the Execute stage.
  - `PCe`, `ImmExtE`, `PcPlus4E`: Program counter, sign-extended immediate value, and PC+4.
- **Control Signals:**
  - `RegWriteE`, `ResultSrcE`, `MemWriteE`, `JumpE`, `BranchE`, `ALUControlE`, `ALUSrcE`, `sizeSrcE`: Control signals passed to the Execute stage.
  - `Rs1E`, `Rs2E`, `RdE`: Source and destination register addresses.
  - `JalrE`: Signal for jump and link register instructions.

#### Functionality
- On reset or flush, all outputs are set to default values.
- During normal operation, data and control signals are propagated to the Execute stage.

---

### **PRegExecute** (Execute → Memory)
#### Purpose
The `PRegExecute` module separates the Execute stage from the Memory stage. It passes ALU results, write data, and control signals to the Memory stage.

#### Inputs
- **Data:**
  - `ALUout`: Result from the ALU.
  - `WriteData`: Data to be written to memory.
  - `PCPlus4E`: PC+4 value from the Execute stage.
- **Control Signals:**
  - `RegWriteE`, `ResultSrcE`, `MemWriteE`, `sizeSrcE`: Control signals for the Memory stage.
  - `RdE`: Destination register address.
- **Others:**
  - `clk`, `rst`.

#### Outputs
- **Data:**
  - `ALUResultM`: ALU result passed to the Memory stage.
  - `WriteDataM`: Data to be written to memory in the Memory stage.
  - `PCPlus4M`: PC+4 value passed to the Memory stage.
- **Control Signals:**
  - `RegWriteM`, `ResultSrcM`, `MemWriteM`, `sizeSrcM`: Control signals for the Memory stage.
  - `RdM`: Destination register address.

#### Functionality
- On reset, all outputs are set to default values.
- During normal operation, inputs are stored and propagated to the Memory stage.

---

### **PRegMemory** (Memory → Writeback)
#### Purpose
The `PRegMemory` module separates the Memory stage from the Writeback stage. It passes memory read data, ALU results, and control signals to the Writeback stage.

#### Inputs
- **Data:**
  - `ALUResultM`: ALU result from the Memory stage.
  - `DMRd`: Data read from memory.
  - `PCPlus4M`: PC+4 value from the Memory stage.
- **Control Signals:**
  - `RegWriteM`, `ResultSrcM`: Control signals for the Writeback stage.
  - `RdM`: Destination register address.
- **Others:**
  - `clk`, `rst`.

#### Outputs
- **Data:**
  - `ALUResultW`: ALU result passed to the Writeback stage.
  - `ReadDataW`: Data read from memory passed to the Writeback stage.
  - `PCPlus4W`: PC+4 value passed to the Writeback stage.
- **Control Signals:**
  - `RegWriteW`, `ResultSrcW`: Control signals for the Writeback stage.
  - `RdW`: Destination register address.

#### Functionality
- On reset, all outputs are set to default values.
- During normal operation, inputs are stored and propagated to the Writeback stage.

---

### Summary of Pipeline Registers
- **PRegFetch:** Passes fetched instruction and PC values to Decode stage.
- **PRegDecode:** Passes decoded data and control signals to Execute stage.
- **PRegExecute:** Passes ALU results and control signals to Memory stage.
- **PRegMemory:** Passes memory results and control signals to Writeback stage.

These registers are critical for maintaining data flow and synchronization across the pipeline stages, ensuring smooth and concurrent execution of instructions.

## Control Unit: Pipelined Version

### Overview
The original control unit was designed for a single-cycle CPU, where control signals directly dictated the flow of a single instruction. For a pipelined CPU, significant changes were made to the control unit to support concurrent execution across multiple stages and to integrate the **branch unit** for precise control over branching conditions.

---

### Key Changes for Pipelining

#### **1. Expanded `aluControl` Signal**
- **Reason for Expansion:** The `aluControl` signal was expanded from 3 bits to 4 bits to prevent conflicts between ALU operations and branch evaluations.
  - In the pipelined CPU, the **branch unit** uses the 3 least significant bits of `aluControl` to determine branch conditions.
  - This ensures no overlap between ALU operations (e.g., `add`, `sub`) and branch conditions (e.g., `beq`, `bne`).

- **Integration with Branch Unit:**
  - The branch unit evaluates conditions such as equality, signed comparisons, and unsigned comparisons based on the `aluControl` signal.
  - For example:
    - `aluControl = 3'b000`: Evaluates `beq` (Branch if Equal).
    - `aluControl = 3'b101`: Evaluates `bge` (Branch if Greater or Equal, signed).

#### **2. Branch Unit Integration**
- **Branch Unit Functionality:**
  - The branch unit calculates the `zero` signal in the Execute stage based on:
    - `srcA` and `srcB`: Operands for the comparison.
    - `aluControl`: Determines the type of comparison (e.g., equality, signed/unsigned comparisons).

- **Control Unit Role:**
  - The control unit generates the `aluControl` signal in the Decode stage for both ALU operations and branch evaluations.
  - The `Branch` signal from the control unit is propagated through the pipeline to indicate whether a branch is active.
  - The branch unit's `zero` output interacts with the hazard unit to determine whether a flush is necessary.

#### **3. Split of `pcSrc` into Multiple Signals**
- The single-cycle `pcSrc` signal was replaced with:
  - **`Branch`:** Activates when a branch condition needs to be evaluated.
  - **`jumpSrc` and `jalrSrc`:** Control jumps (`JAL`, `JALR`) in coordination with the hazard and flush mechanisms.
- This split ensures more precise control over the program counter updates in a pipelined environment.

#### **4. Added Control Signals**
- **`sizeSrc`:** Determines the size of memory operations (e.g., byte, halfword, word).
- **`resultSrc`:** Expanded to 2 bits to support additional sources, such as `PC+4` for jump instructions.
- **`aluSrc`:** Determines the second ALU input (register data or immediate).

#### **5. Modified Pipeline Flow**
- Control signals required by later stages (e.g., `Branch`, `aluControl`, `sizeSrc`) are generated in the Decode stage and passed forward using pipeline registers.
- The expanded `aluControl` ensures both ALU and branch operations are handled without conflicts.

---

### Branch Unit Integration

#### Functionality
The branch unit evaluates branch conditions based on the `aluControl` signal and operands (`srcA` and `srcB`):
- **Branch Operations Supported:**
  - `3'b000`: `beq` (Branch if Equal).
  - `3'b001`: `bne` (Branch if Not Equal).
  - `3'b100`: `blt` (Branch if Less Than, signed).
  - `3'b101`: `bge` (Branch if Greater or Equal, signed).
  - `3'b110`: `bltu` (Branch if Less Than, unsigned).
  - `3'b111`: `bgeu` (Branch if Greater or Equal, unsigned).
- **Output:**
  - `zero`: Indicates whether the branch condition is met.

#### Example
- For a `beq` instruction:
  - The control unit sets `aluControl = 3'b000` in the Decode stage.
  - The branch unit compares `srcA` and `srcB` in the Execute stage.
  - If the condition is true (`srcA == srcB`), the branch unit sets `zero = 1`.
  - This triggers the hazard unit to flush subsequent pipeline stages and redirect the program counter.

---

### Updated Control Signal Mapping

| **Signal**       | **Original Version**                  | **Pipelined Version**                    |
|-------------------|---------------------------------------|------------------------------------------|
| `pcSrc`           | Combined branch and jump control.     | Split into `Branch`, `jumpSrc`, `jalrSrc`.|
| `aluControl`      | 3 bits, limited operations.           | 4 bits, supports ALU and branch operations without overlap. |
| `resultSrc`       | 1 bit, simple ALU/memory result.      | 2 bits, includes `PC+4` for jump instructions. |
| `sizeSrc`         | Not present.                         | Added for load/store instruction sizes.  |

---

### Integration in the Pipeline

#### **Decode Stage**
- The control unit generates:
  - `aluControl` for ALU and branch evaluations.
  - `Branch`, `jumpSrc`, and `jalrSrc` for program counter updates.
  - `sizeSrc` for memory operations.

#### **Execute Stage**
- The branch unit evaluates the branch condition (`zero`) based on `aluControl`, `srcA`, and `srcB`.
- The ALU performs arithmetic or logical operations based on the same `aluControl` signal, ensuring no conflicts.

---

### Benefits of Changes
- **Conflict-Free Branch and ALU Operations:** The expanded `aluControl` signal ensures branch conditions and ALU operations are evaluated independently without overlapping values.
- **Improved Branch Handling:** The integration of the branch unit allows precise evaluation of complex branch conditions (e.g., signed/unsigned comparisons).
- **Pipeline Efficiency:** By splitting control signals and propagating them forward, the control unit minimizes hazards and ensures seamless data flow.

---

### Summary
These changes transform the control unit into a pipelined-ready module that supports both complex ALU operations and advanced branch handling. The integration of the branch unit and the expanded `aluControl` signal ensures efficient and conflict-free operation across the pipeline stages.


## Hazard Unit and Hazard Mux Modules

### Hazard Unit

#### Purpose
The Hazard Unit is responsible for detecting hazards in the pipeline and generating control signals to resolve them. It prevents incorrect data flow and ensures that the pipeline executes instructions accurately and efficiently.

#### Inputs
- **Registers:**
  - `Rs1E`, `Rs2E`: Source registers from the Execute stage.
  - `Rs1D`, `Rs2D`: Source registers from the Decode stage.
  - `RdE`, `destReg_m`, `destReg_w`: Destination registers from the Execute, Memory, and Writeback stages.
- **Control Signals:**
  - `memoryRead_e`: Indicates whether the instruction in the Execute stage is reading memory (derived from `ResultSrcE`).
  - `RegWriteM`, `RegWriteW`: Indicate whether the Memory and Writeback stages are writing to a register.
  - `zero_hazard`, `jump_hazard`: Flags for control hazards due to branch or jump instructions.

#### Outputs
- **Forwarding Signals:**
  - `ForwardAE`, `ForwardBE`: Determine the data source for Source A and Source B in the Execute stage.
- **Pipeline Control Signals:**
  - `stall`: Pauses the Fetch and Decode stages when a data hazard is detected.
  - `FlushD`, `FlushE`: Clear instructions in the Decode and Execute stages during hazards.

#### Functionality
1. **Forwarding Control:**
   - If a source register in the Execute stage matches a destination register from the Memory or Writeback stages, the Hazard Unit generates forwarding signals (`ForwardAE`, `ForwardBE`).
   - Forwarding sources:
     - **Memory Stage:** `Forward = 2'b10`.
     - **Writeback Stage:** `Forward = 2'b01`.
     - **No Forwarding:** `Forward = 2'b00`.

2. **Stall Signal:**
   - If the instruction in the Execute stage is a memory load (`memoryRead_e`), and its result is required in the Decode stage, the pipeline stalls to allow the data to propagate.

3. **Flush Signals:**
   - Clears instructions in the Decode and Execute stages if a branch or jump hazard is detected (`zero_hazard` or `jump_hazard`).

---

### Hazard Mux 1 and 2

#### Purpose
The Hazard Mux ensures the ALU receives the most up-to-date data, resolving data hazards by selecting the correct data source based on forwarding signals from the Hazard Unit.

#### Inputs
- **Data Inputs:**
  - `rdE`: Data from the Execute stage.
  - `ResultW`: Data from the Writeback stage.
  - `ALUResultM`: ALU result from the Memory stage.
- **Forwarding Signal:**
  - `Forward`: Control signal from the Hazard Unit, determining which data source to select.

#### Output
- **Out:** The selected data to be used in the ALU.

#### Functionality
- **Forwarding Logic:**
  - `Forward = 2'b00`: Use data from the Execute stage (`rdE`).
  - `Forward = 2'b01`: Use data from the Writeback stage (`ResultW`).
  - `Forward = 2'b10`: Use data from the Memory stage (`ALUResultM`).

- **Default Case:**
  - If no forwarding is required, the default is to use data from the Execute stage (`rdE`).

#### Integration in the Pipeline
Two instances of the Hazard Mux handle data forwarding:
1. **HazardMux1:** Handles Source A (`SrcAE`) in the ALU.
2. **HazardMux2:** Handles Source B (`WriteDataE`) in the ALU.

---

### Integration in the Pipeline

#### Hazard Unit in the Top File
- The **Hazard Unit** generates control signals for:
  - Forwarding (`ForwardAE`, `ForwardBE`).
  - Pipeline stalls (`stall`).
  - Flush signals (`FlushD`, `FlushE`).

#### Hazard Mux in the Top File
- Two instances of the **Hazard Mux** handle forwarding for the ALU:
  - `HazardMux1`: For Source A (`SrcAE`).
  - `HazardMux2`: For Source B (`WriteDataE`).

These components work together to resolve data hazards and ensure the ALU operates with the correct data at each stage of the pipeline.



# Development Log

## Introduction

This log documents the development of the Pipeline CPU, highlighting key milestones and contributions. The main tasks I worked on include:

- **Design and Implementation of the Pipeline CPU:**
  - Built the entire pipeline section of the CPU by leveraging the single-cycle version.
  - Added new components, such as `Hazard Unit`, `Pipeline Registers`, and `JalrMux`, to support pipelining.
  - Made extensive modifications to existing components, including the `Control Unit`, `Branch Unit`, and `ALU`, to integrate them into the pipeline.

- **Debugging and Optimization:**
  - Debugged and tested the pipeline to ensure compatibility with all test cases.
  - Fixed errors in connections, such as incorrect pins in the branch unit and memory read issues.

- **Task-Specific Enhancements:**
  - Implemented the `Jalr` instruction using a dedicated multiplexer.
  - Enhanced the testbench to work with the pipelined CPU, ensuring robust verification.

- **Code Organization and Cleanup:**
  - Organized files into the `Pipeline/` folder for clarity.
  - Removed unnecessary testing displays and irrelevant files to streamline the repository.

---

## December 10, 2024

### Merged Pipeline into Main
- Resolved conflicts and merged the `pipeline` branch into `main`.
- Organized all project files for clarity.

#### Key Actions:
- Combined all pipeline-related files into the `Pipeline/` folder.
- Removed unnecessary testing displays and irrelevant files for better structure.

---

## December 9, 2024

### Task 5 Finalization
- Successfully completed Task 5 of the pipeline CPU with the help of Michael Li.
- Added a separate multiplexer to implement the `Jalr` instruction.

#### Key Changes:
- Debugged and tested the pipeline CPU, ensuring compatibility with all test cases.
- Fixed a connection issue in the branch unit by correctly linking the output of `HazardMux1`.
- Enhanced the testbench to work with the pipelined CPU and verified all tests.

---

## December 8, 2024

### Hazard Unit and Debugging
- Introduced and refined the hazard unit for pipeline control.
- Improved debugging with displays and fixed issues causing errors in the test results.

#### Key Changes:
- Added a basic hazard unit and displays for debugging.
- Resolved issues with the `ALUControl` input to the branch unit and out-of-bounds memory reads.

---

## December 6–7, 2024

### Initial Pipeline Development
- Developed and tested the pipeline CPU.
- Focused on integrating pipeline registers and refining control units.

#### Key Actions:
- Added the first version of the pipelined CPU registers, including `Control Unit Outputs`.
- Rearranged folder structures for better organization.
- Addressed compilation errors by refining the `ALU`, `ResultMux`, and `Control Unit`.

---

## December 1–5, 2024

### Foundation of the Pipeline CPU
- Completed the first stage of the pipeline and set up the foundation for further tasks.
- Focused on enhancing the program counter (PC) and testing memory components.

#### Key Changes:
- Added registers for the first stage of the pipeline.
- Improved memory handling in the pipeline CPU by integrating signed and unsigned instructions.
- Created initial test cases and debugging tools to verify functionality.

---

## November 26–30, 2024

### Core CPU Components
- Designed and implemented the foundational components of the pipeline CPU.
- Created `DataMemory`, `RegFile`, and the `ALU`.

#### Key Actions:
- Added Version 1 of `DataMemory` and `ALU` to support testing.
- Developed `Mux` and `ResultMux` for proper data flow within the CPU.
- Introduced testing tools like `doit.sh` for continuous testing.

---

## Summary

This log reflects the extensive work done to develop the Pipeline CPU, from foundational components to a fully functional pipeline architecture. The main challenges included debugging intricate pipeline issues, implementing task-specific features like `Jalr`, and ensuring compatibility with all test cases. The resulting design is modular, well-documented, and robust.
