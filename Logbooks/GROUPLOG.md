# Group 16 Logbook
### 13/11/2024: WhatsApp Group Created
Our first meet up was done via WhatsApp, because several of our members were unable to make it face-to-face (be it illness or external commitments).
- Discussed and allocated roles for Lab 4 based on the recommended split:
| Description  | Files involved  |
|---------- |---------- |
|  **Flavio**    |          | 
| PC Register | PCReg.sv    |
|  Top Module | top.sv  |
|  Program Counter and related adders ||
|Mux|mux.sv|
|**Michael Li**||
|The Control Unit, the Sign-extension Unit and the instruction memory||
|Instruction Memory|instr_mem.sv|
|Control Unit|control_unit.sv||
|Sign Extend|sign_extend.sv||
|**Soon Yung+ Flavio**||
|The Register File, ALU and the related MUX||
|ALU unit|ALU.sv|Soon Yung+ Flavio|
|Register File|RegFile.sv|
|**Shenghong**||
|Integration of components and testbenching
|top_tb.cpp|Shenghong|

- At the end, our main goal was to finish Lab 4 within 2 weeks and meet up to discuss how to proceed with the project

### 26/11/2024: First physical meet up for project after lectures
By this meeting, all the components were done, however, the integration of components revealed alot of bugs in our code. We spent about 3 hours discussing which areas to fix and which code to change. By the end, we had fixed the majority of the bugs and would create our individual test benches in our own time

### 29/11/2024: Discussion Post-Lab 4 + Project discussion (After Lectures)
In this session, we reflected on our execution of Lab 4 and came to the following conclusions:
1. Clear deadlines - We realised that the laisser-faire approach was too inefficient for our group, so we set strict headlines to have the base CPU completed
2. Communication - There was very little communication between members at times, which resulted in git pushes being uncoordinated, deleting or changing files unecessarily. Going forward, we decided to utilise our individual branches first before merging (This was implemented before the meeting, but it was nonetheless a reflection)

For the project work, we decided on the following roles:
#### Technical Roles
|Member|Rough work Description| Potential Files|
|-|-|-|
|Flavio|Register File, ALU and the related MUX|RegFile.sv, MUX.sv, ALU.sv|
|Michael Li|Control Unit, the Sign-extension Unit and the instruction memory|sign.sv, intr_mem.sv|
|Soon Yung|testbenching + F1 Code|top_tb.cpp, F1_tb.cpp|
|Shenghong|Program Counter and related adders + Integration|PC.sv|

#### Non-techncial Roles
|Member|Rough work Description| Potential Files|
|-|-|-|
|Flavio|Personal Statement|Flavio_statement.md|
|Michael Li|Personal Statement|Michael_statement.md|
|Soon Yung|Personal Statemnt +  Team Statements|SY_statement.md, Team_Log.md, README.md|
|Shenghong|Personal Statement|Shenghond_statement.md|

##### Note 
These file names do not accurately reflect the final file names - they are merely a rough guideline on what: 
1) Types of files to make and,
2) The suggested content

#### Timeline
- We aimed to meet up by the end of the week with the basic CPU design finished, before discussing what to do next


### 08/12/2024: Update on progress
At this point, the group had completed pipeline with work done on the cache stretched goal. It was here that we realised we didn't actually complete the f1 lights or the pdf plots - both of which were essential for our testing. 


### 12/12/2024: Library meetup
At this meeting, the group had almost completed the two-set associative cache stretched goal and all the pdf plotting tracks. This meeting was to help each other with debugging and began the writing process 


### 13/12/2024: Final Meetup
By this meeting, the associative cache stretched goal and pdf plotting was complete. This meeting was to take pictures for the pdf plotting and assist in making our personal statements.

In this final meeting, we also took sometime to reflect on the group's experience as a whole - and accross the board we felt that we had done well. Throughout the project we felt that we had been very organised and well-informed on each other's actions.