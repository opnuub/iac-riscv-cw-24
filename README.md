# Instruction Architecture RISC-V Coursework - Group Error404

## Overview

|Tag	|Descripton			|Statement		|
|-------|-------------------------------|-----------------------|
|[Tag]	| Lab 4 - Simplified RISC-V CPU	|[Link]			|
|[Tag]	|	Basic  RISC-V CPU	| [Link]		|
|[Tag]	|Pipelined RV32I Design		| [Link]		|
|[Tag]	|Data Memory Cache		|[Link]			|

## Personal Statements
|Member   |Personal Statement             |Logbook              |
|---------|-------------------------------|---------------------|
|Cole     |[Peronal Statement](Github.com)|[Logbook](google.com)|
|Flavio   |[Peronal Statement](Github.com)|[Logbook](google.com)|
|Michael  |[Peronal Statement](Github.com)|[Logbook](google.com)|
|Soon Yung|[Peronal Statement](Github.com)|[Logbook](google.com)|


## Working Evidence
| Dataset|Graph |Dataset |Graph |
|-|-|-|-|

## Contributions

### Single Cycle Processor

| Part           | File  | Flavio (@FlavioGazzetta)| Cole (@opnuub)| Michael (@Happymic)| Soon (@so0nyung)      |
|:---------------|:------|:-----------------------:|:------------:|:-------------------:|:---------:|
| Program Counter| PCReg.sv, PCTOP.sv, PCMux.sv| F           |      P       |             |           |
| ALU & RegisterFile         | ALU.sv, ALUMux1.sv, ALUMux3.sv, ALUTop.sv                               | F           |      P       |             |           |
|                            | RegisterFile.sv, ALUMux2.sv                                             | F           |      P       |             |           |
| Instruction Processing     | InstructionMemory.sv                                                    |             |      F       |    P        |           |
|                            | extend.sv.sv                                                            |             |      F       |    P        |           |
|                            | ControlUnit.sv                                                          |             |      F       |    P        |           |
|                            | branchUnit.sv                                                           |             |      F       |             |           |
| Full Integration           | top.sv                                                                  |             |      F       |             |           |
| Data Memory                | DataMemory.sv                                                           | F           |      P       |             |          |
| F1 Program    | f1.s      |               |      F       |        |           |
|               | f1.sv     |               |           |           |           |
|               | f1_tb.cpp |               |           |               ||
| PDF Plotting| pdf_tb.cpp  |             |              |             | F         |
|           |               |               |               |           |
|Unit Testing|              |               |               |           |

&nbsp;

### Pipelined Processor
| Part                       | File                                                                    | Flavio      | Cole         | Michael     | Soon      |
|:---------------------------|:------------------------------------------------------------------------|:-----------:|:------------:|:-----------:|:---------:|
| Pipeline Registers         | PRegFetch.sv, PRegDecode.sv, PRegExecute.sv, PRegMemory.sv              |       F     |              |             |           |
| Jump Control               | BandJSelector.sv                                                        |       F     |              |             |           |
| Module signal reconnection | ALU.sv, Control Unit.sv, Extend.sv, ...                                 |       F     |              |             |           |
| Reformat Intermediate TOPs | FetchTOP.sv, DecodeTOP.sv, ExecuteTOP.sv, MemoryTOP.sv, WritebackTOP.sv |       F     |              |             |           |
| Hazard Handling            | HazardUnit.sv                                                           |       F     |              |             |           |
|                            | ExecuteFwdMuxA.sv, ExecuteFwdMuxB.sv                                    |       F     |              |             |           |
| Full Integration           | top.sv                                                                  |       F     |              |             |           |

&nbsp;

### Set Associative Cache
| Part             | File     | Flavio  | Cole | Michael  | Soon      |
|:-----------------|:---------|:-------:|:----:|:--------:|:-------:|
| Two-way set cache| HazardUnit.sv (Cache - Memory stall)|P | |F|   |
|| MemoryControler.sv|||    F        ||
|| L1Cache.sv        |||    F        ||
|| L2Cache.sv        |||    F        ||
|| L3Cache.sv        |||    F        ||

## File Layout

##### Directory

##### Files to Take Note
1. README.md file
[`logbooks`](docs/logbooks/)