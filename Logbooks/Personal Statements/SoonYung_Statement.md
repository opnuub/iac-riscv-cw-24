# Personal Statement: Soon Yung
**Name:**Soon Yung  </br>
**CID:** 02390909   </br>
**Github username:** so0nyung


## Summary
- My role in the team was to write testbenches and integrate code to test their validity
- 


## Contributions
### F1 Lights

#### Brief:
>Formula 1 (F1) racing has starting light consists of a series of red lights that turn ON one by one, until all lights are ON. Then all of them turn OFF simultaneously after a random delay.

In addition to this, I thought it would be useful to create a reset mechanism.
My interpretation of the task led me to write these files:
|File       |Description                                    |            
|-----------|-----------------------------------------------|
| f1_asm.s  |Assembly code to activate the f1 light sequence|
|f1_tb.cpp  |Outputs the assembly instructions              |
|doit.sh    |Executes the C++ file and analyses             |
|lfsr.sv    |Generates the pseudorandom number for the delay|
|clktick.sv |Controls the clock and stimulates the delay    |
|f1.sv      |Top file for the f1 lights                     |

#### Design Choices
1. lfsr.sv:
    ```
    module lfsr(
        input   logic       clk,
        output  logic [3:0] data_out
    );
    
    logic [4:1] sreg = 4'b0001;
    
    always_ff @ (posedge clk)
        sreg <= {sreg[3:1], sreg[4] ^ sreg[3]};
    
    assign data_out = sreg;
    
    endmodule
    ```

The module mirrors the lfsr given in lectures. However, the `en` and `rst` functions are removed. For our purposes, not only is it redundant (since we can keep the lfsr running at all times), it also aids in the randomness because we cannot manipulate when and where the lfsr stop (Of course that just means that the pseurandomness is slightly more complex, but that's outside the scope).

2. clktick.sv
```
                    module clktick # (
                        parameter DATA_WIDTH = 32
                    )   (
                        input   logic [DATA_WIDTH-1:0]  N,
                        input   logic [3:0]             random_delay,
                        input   logic [DATA_WIDTH-1:0]  a0,
                        input   logic                   rst,
                        input   logic                   clk_i,
                        output  logic                   clk_o
                    );
                    
                        logic [DATA_WIDTH-1:0] count;
                    
                        always_ff @ (posedge clk_i)
                            if (rst) begin
                                clk_o <= 1'b1;
                                count <= 0;
                            end
                            else begin
                                if (count == 0 && a0 == 32'h7F) begin
                                    clk_o <= 1'b1;
                                    count <= N+(N*random_delay)/3;
                                end
                                else if (count == 0 && a0 != 32'h7F) begin
                                    clk_o <= 1'b1;
                                    count <= N;
                                end
                                else begin
                                    clk_o <= 1'b0;
                                    count <= count - 1'b1;
                                end
                            end    
                    endmodule
```
There are two clk cycles: one to simulate the `always_ff` and one to output the clk


3. top.sv
```
                                module f1 #(
                                    parameter DATA_WIDTH = 32
                                ) (
                                    input   logic                   clk,
                                    input   logic                   rst,
                                    input   logic                   trigger,
                                    output  logic [DATA_WIDTH-1:0]  a0
                                );
                                
                                    logic       delayed_clk;
                                    logic [3:0] random_delay;
                                
                                    lfsr lfsr (
                                        .clk (clk),
                                        .data_out (random_delay)
                                    );
                                
                                    clktick clktick (
                                        .N (32'd38),
                                        .random_delay (random_delay),
                                        .a0 (a0),
                                        .rst (rst),
                                        .clk_i (clk),
                                        .clk_o (delayed_clk)
                                    );
                                
                                    top top (
                                        .clk (delayed_clk),
                                        .rst (rst),
                                        .trigger (trigger),
                                        .a0 (a0)
                                    );
                                
                                endmodule
```
[Write here later]


4. f1_asm:
```
                    main:
                        addi    t0, zero, 0x1
                        jal     subroutine
                    
                    subroutine:
                        addi 	a0, zero, 0x1
                        addi    zero, zero,  0x0
                        addi 	a0, zero, 0x3
                        addi    zero, zero,  0x0
                        addi 	a0, zero, 0x7
                        addi    zero, zero,  0x0
                        addi 	a0, zero, 0xf
                        addi    zero, zero,  0x0
                        addi 	a0, zero, 0x1f
                        addi    zero, zero,  0x0
                        addi 	a0, zero, 0x3f
                        addi    zero, zero,  0x0
                        addi 	a0, zero, 0x7f
                        addi    zero, zero,  0x0
                        addi    a0, zero, 0xff
                        addi    zero, zero,  0x0
                        addi    a0, zero, 0x0
                        ret

```
The assembly code is very simple - simply adding 1s to register a0. In practice, I noticed that the instructions were processing very fast, making it hard to establish a slow enough interval. In addition, the reset button mechanism would often be too slow for the F1 light, leading to a bug where an additional light goes on before the light resets.

To combat both these issues, I opted to add `NOP` instructions after every  `addi a0` instruction. Although less clean in code, it made a large enough impact to view on vbuddy and gave enough delay such that the bug is no longer shown when pressing the button.


#### Testing
To test this code, first attach the vbuddy. Next, enter the `f1_program` directory and enter the following lines:
```
                                        ./attach_usb.sh
                                        ./doit.sh
```
The code may need the `doit.sh` to be ran several times before it is executed correctly. This was a phenomenon that varied from computer to computer, and I am unsure of the reason.

### PDF
#### Brief
> Your design should also pass the reference program "pdf.asm" provided in the folder "tb/reference". Details about how this reference program works and what it does is given in the markdown file in this folder.

For this portion, I ended with the following files:

|Files      |Description                            |
|-----------|---------------------------------------|
|doit.sh    |Modified to work in pdf_program folder |
|pdf.s      |Modified (see below)                   |
|pdf_tb.cpp |test bench to output file into vbuddy  |

### Testing
>"Aint broke don't fix it"

My approach for testing was to utilise the  provided verify.cpp file and cpu_testbench.h and expand the test cases as much as possible.
## What I learned
Truth be told, I came into this project pretty confused, despite doing the labs. Nonetheless, it was been an enjoyable (mostly) and truly enriching experience.

I learnt how to use a lot of different softwares, of note:
1. GitHub commands - Learnt a lot of commands on how to navigate using GitHub and branches. Though I am not proficient in the least, I am certainly more comfortable usin git on Ubuntu / the command line
2. *.sh* file types (*.sh* etc.) I had previous experience with *.sv* from the labs, but very little manipulating the *.sh* files provided. Given my group's work style, there were new folders made to test the circuits, leading to adjustments constantly being made. This forced me to understand the commands used in shell files and rewrite them. 


Above all, I think this project gave me a very harsh look into seeing how clashing work styles looks like, which is a rare but valuable experience.
## Difficulties faced

1. <u>Personal Hardware /Software issues</u>. Towards the end of the project, I discovered that at some point, my computer was unable to execute the *assemble.sh* file correctly , which greatly reduced my capability in testing assembly language files.

##### Evidence:
**1. Number of testbenches in verify.cpp**</br>
images/NumTEST_T </br>
**2. Running Testbench Results**
images/TEST_inconsis

Given the time limit, I had to send files to my teammates to test that they were working, which slowed down progress a lot.



2. <u>Theory</u>. As hard as I tried, my theory and understanding of concepts held me back significantly, and led me to revist the lecture slides constantly and ask my friends for guidance. Whilst it was a surmountable obstacle, I think it was worth sharing.
 
## What I would do differently
- <u>Set up weekly meetings and enforce them</u>. It was an issue in Lab 4 where the workload was unbalanced. While its impact was reduced, I felt that the problem persisted through the coursework nonetheless.
- <u>Been more aggressive in using GitHub</u>. More often than not I would just send files over to my friends via our communciation platforms (WhatsApp, Discord, etc.) rather than commiting the updated file. This led to a signficantly smaller commit history than some members.
- <u> Been more flexible</u>. In many ways I think my work style greatly differed from my teamates which did impact coordination on some days. I believe that I should have been more willing to compromise in certain scenarios, which would've made the process smoother.
- <u>Proactive in testing</u>. I was initially very passive in testing and only doing it once the whole CPU was finished before testing. As a result, I was not able to test the pipelined CPU.

## Conclusion

## Other notes
- Special mention to Cole (@opnuub) for his efforts in teaching me how to use Github and the basic of debugging. Your continuous support throughout the project was also really impactful. Also to Flavio for his efforts in helping me troubleshoot my Ubuntu issues