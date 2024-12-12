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

For the Pipeline CPU I made various changes both to separate the stages Fetch, Decode, Execute, Memory and WriteBack, and to various components in order to adjust them to these stages. First of all I added 4 regsters to separate the above stated stages initially only taking the inputs from one stage and passing them to the next after a clock tick, innitially here I thought it would be a good idea to give these registers a memory, but later i decide to make them act like 32-bit flip flops. After that I edited the control unit and added outputs including JumpD to decide when I would Jump, BranchD to decide when I would Branch, I then used the component PCMuxSelect to AND the zeroE output of the branch unit with JumpE (JumpD output after passing through the Decode -> Execute stage), and then ORed the output of this AND gate with BranchE. I removed the PCsrc Output and i changed my ReultSrc output from 1 to 2 bits, this is because I wanted the register in the writeback stage of the alu to select between 3 values (where I made the 4th input be a default 00 as this would never be used). The reason for now using a 4 input mux was that i combined 2 muxes from the single-cycle stage (resultMux and JumpMux) to better follow the schematic given to us and to keep everything as compact as possible. I also changed ALUControl from 3 to 4 bits, this change was made in order to allow the alu and branch unit to act seperateley, as with 3 bits their operations would overlap in the same stage and leed to errors. Hence, due to this change in ALUControl I changed the bit allocation

Initial Pipeline - No Hazard Unit:

<img src="Pipeline/images/no_hazard_pipeline.png" width="950" height="550" alt="Pipeline 5 stages passed">

Finished Pipelined - Full hazard unit implemented: 

<img src="Pipeline/images/finished_pipeline_cpu.jpeg" width="850" height="550" alt="Pipeline 5 stages passed">

---

## Components

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