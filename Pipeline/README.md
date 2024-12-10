# Pipeline CPU Development Log

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
