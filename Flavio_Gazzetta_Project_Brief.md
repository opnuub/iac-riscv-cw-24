# RISC-V RV32I Processor Coursework  

### Personal Statement of Contributions  
**Flavio Gazzetta**  

---
---

## Overview  

During my time working on this project I initially devoted my work towards working on both the single cycle and especially a 5 stage pipelined CPU. For the single-cycle I made and tested various componets, these components were the DataMemory, the Register file, the ALU, the PC and various multiplexers. After having completed this I focused my time on the pipelining cpu for which I made many new components including a hazard unit (would decide when to flush, stall and use forwarding), hazard multiplexers (to implement forwarding), registers which would separate the stages Fetch->Decode, Decode->Execute, Execute->Memory, Memory->WriteBack, a mux which would allow the implementation of the JALR instruction and many more. 

---
---

## SingleCycle 

---

## Components

---

### Program Counter

#### Block Diagram

##### Links to Module  

[pcReg.sv](rtl/pcReg.sv)

[pcMux.sv](rtl/pcMux.sv)

#### Most Relevant Commits

1) [first version of counter](https://github.com/opnuub/Lab4/commit/66f45f5c08d823b52e3ff4d20c09211cb3410bed)

2) [first version of counter](https://github.com/opnuub/Lab4/commit/66f45f5c08d823b52e3ff4d20c09211cb3410bed)

3) [changed PCreg and top to include combinational logic inside of PC](https://github.com/opnuub/Lab4/commit/602bbcf9fe90792f2bb1aef4e45129d38d9b2730)

---

### ALU

#### Block Diagram

#### Link to Module  

[alu.sv](rtl/alu.sv)

#### Most Relevant Commits

1) [added ALU version 1](https://github.com/opnuub/iac-riscv-cw-16/commit/fc9c426b4c8af0576de1129055d2b3582990d3de)

2) [Added mux connecting to ALU](https://github.com/opnuub/iac-riscv-cw-16/commit/56752057c5c8f5cf7abfee144f58caf270d2d0e9)

3) [upadtes to ALU including singed and unsigned smaller than](https://github.com/opnuub/iac-riscv-cw-16/commit/29db9d2eeab6de3a390bccd528c7f5b89459afd2)

4) [added unchange SrcB to to allow for lui](https://github.com/opnuub/iac-riscv-cw-16/commit/4e4d1629e8dce89d05d143472dde3d0a2a077e4e)

5) [changed ALU back to 3 bits](https://github.com/opnuub/iac-riscv-cw-16/commit/5a6290178d83b32d25e95a0dfc2205948b976b7c)

this was then changed further by Cole for integration

---

### RegFile

#### Block Diagram

#### Link to Module 

[regFile.sv](rtl/regFile.sv)

#### Most Relevant Commits

1) [Added RegFile version 1](https://github.com/opnuub/iac-riscv-cw-16/commit/deb3dc83c7be3d490ad1d975ee7e690f2ce03e91)

this was later changed by cole during implementation

---

### DataMemory

#### Block Diagram

#### Link to Module

[dataMemory.sv](rtl/dataMemory.sv)

#### Most Relevant Commits

1) [Data memory](https://github.com/opnuub/iac-riscv-cw-16/commit/ddabfb75227940ec05f503a63af4c198829b5f99)

---
---

## Pipeline

For the Pipeline CPU I made various changes both to separate the stages Fetch, Decode, Execute, Memory and WriteBack, and to various components in order to adjust them to these stages. First of all I added 4 regsters to separate the stages [Fetch -> Decode](Pipeline/rtl/PRegFetch.sv), [Decode -> Execute](Pipeline/rtl/PRegDecode.sv), [Execute -> Memory](Pipeline/rtl/PRegExecute.sv), [Memory -> WriteBack](Pipeline/rtl/PRegMemory.sv). Initially these only rook the inputs from one stage and passed them to the next after a clock tick, at first here I thought it would be a good idea to give these registers a memory, but later I decide to make them act like 32-bit flip flops. After having made these I edited the [control unit](Pipeline/rtl/controlUnit.sv) (specifically making changes in the [aluDecoder.sv](Pipeline/rtl/aluDecoder.sv) and the [mainDecoder.sv](Pipeline/rtl/mainDecoder.sv)) and added outputs including JumpD to decide when I would Jump, BranchD to decide when I would Branch, I then used the component [PCMuxSelect](Pipeline/rtl/mainDecoder.sv) to AND the zeroE output of the [Branch Unit](Pipeline/rtl/branchUnit.sv) with JumpE (JumpD output after passing through the Decode -> Execute stage), and then OR'ed the output of this AND gate with BranchE. I removed the PCsrc Output and then changed my ReultSrc output from 1 to 2 bits, this is because I wanted the [result Mux](Pipeline/rtl/resultMux.sv) (register in the in the writeback stage of the alu) to select between 3 values (where I made the 4th input be a default 00 as this would never be used). The reason for now using a 4 input mux was that i combined 2 muxes from the single-cycle stage (resultMux and JumpMux) to better follow the schematic given to us and to keep everything as compact as possible. I also changed ALUControl from 3 to 4 bits, this change was made in order to allow the [alu](Pipeline/rtl/alu.sv) and [Branch Unit](Pipeline/rtl/branchUnit.sv) to act separateley, as with 3 bits their operations would overlap in the same stage and leed to errors. Hence, due to this change in ALUControl I changed the bit allocation in the [Branch Unit](Pipeline/rtl/branchUnit.sv) and [alu](Pipeline/rtl/alu.sv) (adding adding a 1 as MSB for the [Branch Unit](Pipeline/rtl/branchUnit.sv) and a 0 for the [alu](Pipeline/rtl/alu.sv)). I also added a Jalrsrc output to act as a select bit for a [Jalr Mux](Pipeline/rtl/JalrMux.sv) located in the execute stage which would select between the last program counter value or the last register1 value to be passed into the [extend PC component](Pipeline/rtl/extendPC.sv) component which would add the immediate value in the execute stage with the value passed on by the [Jalr Mux](Pipeline/rtl/JalrMux.sv), with the ouput of this component being the other input in the [PC Register](Pipeline/rtl/pcReg.sv). Of course, even with all these changes (and other minor ones) the cpu could still not pass any of the 5 tests given to us, this was because I was yet to add the [Hazard Unit](Pipeline/rtl/HazardUnit.sv) and related [HazardMux'es](Pipeline/rtl/HazardMux.sv). I made the [Hazard Unit](Pipeline/rtl/HazardUnit.sv) able to perfrom 3 different types of actions: Flushing (uses outputs FlushD and FlushE to set all the ouputs of the [Fetch -> Decode](Pipeline/rtl/PRegFetch.sv) and [Decode -> Execute](Pipeline/rtl/PRegDecode.sv) registers to 0), Stalling (uses the ouput stall to prevent the values in the [PC Register](Pipeline/rtl/pcReg.sv) and [Fetch -> Decode](Pipeline/rtl/PRegFetch.sv) registers to pass on to the next ones) and Forwarding (uses the ouputs ForwardAE and ForwardBE to select between the value of register1 and regitsr2 ouputs of the [register file](Pipeline/rtl/regfile.sv) in the execute stage, the value of the aluresult in the memory stage and the value of the result which is in the writeback stage and ). In my HazardUnit code, forwarding, stalling, and flushing are implemented to resolve hazards as follows:

Forwarding resolves data hazards by bypassing results from later stages (Memory or Writeback) to the Execute stage. For Source A (ForwardAE), the logic is as follows:

```systemverilog
if (RegWriteM && (destReg_m != 0) && (destReg_m == Rs1E)) begin
    ForwardAE = 2'b10;  // Forward from Memory stage
end else if (RegWriteW && (destReg_w != 0) && (destReg_w == Rs1E)) begin
    ForwardAE = 2'b01;  // Forward from Writeback stage
end else begin
    ForwardAE = 2'b00;  // No forwarding
end
```

Similarly, ForwardBE handles forwarding for Source B by checking Rs2E. This ensures the ALU in the Execute stage receives up-to-date data directly from the pipeline. Stalling resolves load-use hazards, where an instruction requires data from a load still in the Memory stage. If a load instruction in the Execute stage (memoryRead_e) has a destination register (RdE) that matches either source register in the Decode stage (Rs1D or Rs2D), the pipeline is stalled as follows:
```systemverilog
if (memoryRead_e && ((RdE == Rs1D) || (RdE == Rs2D))) begin
    stall = 1'b1;
end else begin
    stall = 1'b0;
end
```
When stall is asserted, the Fetch and Decode stages are frozen, and the Execute stage is cleared using:
```systemverilog
if (stall) begin
    FlushE = 1'b1;  // Clear Execute stage to avoid incorrect operation
end
```
Flushing resolves control hazards (e.g., branches or jumps) by discarding incorrect instructions fetched after a mispredicted branch or jump. If a branch condition (zero_hazard) or jump (jump_hazard) is detected, flushing is applied as follows:
```systemverilog
if (zero_hazard || jump_hazard) begin
    FlushD = 1'b1;  // Clear Decode stage
    FlushE = 1'b1;  // Clear Execute stage
end
```
This ensures any incorrectly fetched instructions are removed. 

In order to implement fulsh and stall I also changed the fregisters between [Fetch -> Decode](Pipeline/rtl/PRegFetch.sv) and [Decode -> Execute](Pipeline/rtl/PRegDecode.sv), only allowing the values to pass from Fetch to Decode when ```systemverilog !stall ``` is high and making all outputs <= 0 

Initial Pipeline - No Hazard Unit:

<img src="Pipeline/images/no_hazard_pipeline.png" width="950" height="550" alt="Pipeline 5 stages passed">

Finished Pipelined - Full hazard unit implemented: 

<img src="Pipeline/images/finished_pipeline_cpu.jpeg" width="850" height="550" alt="Pipeline 5 stages passed">

---

## Added or Edited Components

---

## Pipeline Registers

#### Blocks Diagram

#### Links to Modules

[PRegFetch.sv](Pipeline/rtl/PRegFetch.sv)

[PRegDecode.sv](Pipeline/rtl/PRegDecode.sv)

[PRegExecute.sv](Pipeline/rtl/PRegExecute.sv)

[PRegMemory.sv](Pipeline/rtl/PRegMemory.sv)

#### Most Relevant Commits

1) [Improved Pipeline Registers](https://github.com/opnuub/iac-riscv-cw-16/commit/72aea873a82f6d3353513419fee9e28bb456142d)

2) [implemented the Jalr instruction by using a seperate mux](https://github.com/opnuub/iac-riscv-cw-16/commit/aa623c2f9ed204c58805c8cf299f0bddc0a6dc05)

---

## Control Unit

#### Blocks Diagram

#### Links to Modules

[controlUnit.sv](Pipeline/rtl/controlUnit.sv)

[aluDecoder.sv](Pipeline/rtl/aluDecoder.sv)

[mainDecoder.sv](Pipeline/rtl/mainDecoder.sv)

#### Most Relevant Commits

1) [Improved Pipeline Registers](https://github.com/opnuub/iac-riscv-cw-16/commit/72aea873a82f6d3353513419fee9e28bb456142d)

2) [implemented the Jalr instruction by using a seperate mux](https://github.com/opnuub/iac-riscv-cw-16/commit/aa623c2f9ed204c58805c8cf299f0bddc0a6dc05)

---

## Additional Features and Testing  

### Features Added  

---

### Testing & Results

##### Pipeline 5 tests
Here's a smaller image:

<img src="Pipeline/images/Pipelined_all_5_tests_pass_proof.png" width="550" height="550" alt="Pipeline 5 stages passed">
 
---

## potential improvements

## Additional Comments 