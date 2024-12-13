# Personal Statement: Soon Yung
**Name:**Soon Yung  </br>
**CID:** 02390909   </br>
**Github username:** so0nyung


## Summary
- My role in the team was to write testbenches and integrate code to test their validity
- I was also in-charge of implementing the F1 Lights and PDF plotting.


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
|fsm.sv     |Ensures that the reset state is enforced       |
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
There are two clk cycles: one to simulate the `always_ff` and one to output a signal indicating that the random delay has been applied and the countdown has begun.


3. fsm.sv
During testing, I noticed that the reset was always delayed, which led to a bug where one more light would go off before the F1 lights reset. To ensure this bug didn't occur, I added a finite-state machine (FSM) to eliminate this delay issue. 
```
        RST: begin (When rst = 1);
                a0 <= 0;
                if (tmp_a0 == 32'd1)    next = NRST;
                else                    next = RST;
            end
```

If the next value (`tmp_a0`) is a  `32'd1`, the system wil continue as per usual, allowing the output to continue. 
```
        NRST: begin // When rst == 0
                a0 <= tmp_a0;
                next = NRST;
            end
```

Otherwise, it will cut the signal short and give it a `0` by default.


4. f1_asm:
The assembly code went through the most iterations and greatly influenced the rest of the files. The main portion of the assembly code is very simple - simply adding 1s to register a0. The hard part was implementing both the random number generator and the reset function.

Initially, I had first thought of making a trigger within the assembly code using a beq function (View [commit here](https://github.com/opnuub/iac-riscv-cw-16/commit/dabe4cceb595ad3fc03d3f3027d8d1797f2d3615)). But, it was extremely tedious and unecessarily extended the code. I eventually changed the `clktick.sv` to include a rst function.

To create the random number generator, I had first considered following a Linear Congruential Generator within the assembly code that following the formula:
[LFG Equation](images/LFG_Eqn.jpg)
But that made the code too long and our CPU did not have all the necessary functions to implement it correctly (E.g. full multiplication). </br>

In the end, I settled on the lfsr used in the lectures as a sufficient pseudorandom number generator.

The end result was a simple code that fulfilled the requirements of the F1:</br>
![F1 Assembly Code](/images/F1_assem.jpg) </br>

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
|top_tb.cpp |test bench to output file into vbuddy  |


1. <u>Starting point</u>. We were provided with the `pdf.s` to follow. The task was to develop a testbench that would be able to receive the data and translate it properly and plot it in vBuddy.
2. <u>pdf.s amendements</u>. While reading through the pdf.s file, I realised the display section:

![Display assembly code](images/pdf_dispcode.jpg) </br>
    was when one loop of building the pdf function was finished. I could use this as a break for my testbench to extract the data and plot it. Hence, I added an `addi` function:</br>
    
![New Display Assembly code](images/pdf_newdis.jpg)</br>

which allowed me to identify when one loop of building the pdf was complete.

3. <u>PDF Plotting testbench</u>. The testbench has a very similar structure to most testbenches outputting to vBuddy: initialise verilator values, run the files and output the data into vBuddy. The problem is there is too much data to output each value one by one (The gaussian.mem is over 8 thousans lines long). It could lead to all sorts of issues To minimise them, I decided to input data into a vector after every loop and upload all that data in the vBuddy.

First I added three new variables:</br>
![Pdf New Variables](images/pdf_newVar.jpg)</br>
a. discyc - to capture the clock cycles </br>
b. norm_dist - to capture the values in each loop </br>
c. startDisplaying - a boolean flag to indicate when to dump values to vBuddy

Next, I added logic to detect when a loop is finished and to start collecting data: </br>
![Pdf Conditions](images/pdf_conditions.jpg)</br>
Which simply collects the next 240 values in `a0` (which are loaded in from data memory storing pdf data) and outputs it into the `vbdPlot()`.


4. <u>testing</u>. The main issue of the pdf came in testing, where I encountered some difficulties. (See [Difficulties Faced](##Difficulties-Faced)). However, when I managed to get a good reading very soon. However, I noticed that the readings were biased to the right: </br>

|Signal|Graphic|
|------|-------|
|Gaussian|[Old Gaussian Graph](images/Gaussian_Graph.jpg)  |
|Noisy   |[Old Noisy Graph](images/Noisy_Graph.jpg)        |
|Triangle|[Old Triangle Graph](images/Triangle_Graph.jpg)       |

The effect was particulary noticeable in the `noisy.mem` graph. To compensate this, I adjusted the number of cycles `discyc` is given, thereby increasing the frequency of collection. This shifted the graph to the left to show the full images, which can be found in the [`README.md`](https://github.com/opnuub/iac-riscv-cw-16/blob/main/README.md) file.


### Testing

My approach for testing was to provide additional test cases to extend the testing.

## What I learned
Truth be told, I came into this project pretty confused, despite doing the labs. Nonetheless, it was been an enjoyable (mostly) and truly enriching experience.

I learnt how to use a lot of different softwares, of note:
1. <u>GitHub commands</u>. I learnt a lot of commands on how to navigate using GitHub and branches. Though I am not proficient in the least, I am certainly more comfortable usin git on Ubuntu.</br>

2. <u>*.sh* file types</u>. I had previous experience with *.sv* from the labs, but very little manipulating the *.sh* files provided. Given my group's work style, there were new folders made to test the circuits, leading to adjustments constantly being made. This forced me to understand the commands used in shell files and rewrite them. 

Above all, I think this project gave me a very realistic look into how working as a team on a technical project looks like, which is a rare and valuable experience. 
## Difficulties faced

1. <u>Personal Hardware /Software issues</u>. Towards the end of the project, I discovered that at some point, my computer was unable to execute the *assemble.sh* file correctly , which greatly reduced my capability in testing assembly language files. Sadly, because it was too close to the deadline, I had to send files to my teammates to test that they were working, which slowed down progress a lot.


2. <u>Theory</u>. As hard as I tried, my theory and understanding of concepts held me back significantly, and led me to revist the lecture slides constantly and ask my friends for guidance. Whilst it was a surmountable obstacle, I think it was worth sharing.
 
## What I would do differently
- <u>Been more aggressive in using GitHub</u>. More often than not I would just send files over to my friends via our communciation platforms (WhatsApp, Discord, etc.) rather than commiting the updated file. This led to a signficantly smaller commit history than other members.
- <u>Proactive in testing</u>. I was initially very passive in testing and only doing it once the whole CPU was finished before testing. As a result I had periods of lull and periods of intense work, which was not ideal
- <u>Time Management</u>. Whilst the team planned it well, there were definitely more crunch moments than I would have liked, in no small part to my passiveness in testing parts. In the future I plan to map out in greater details my tasks.
- <u>Design</u>. There were defintely moments in hindsight where it would have been beneficial to discuss a design with my teammates instead of testing out multiple designs that would not work. In future projects this is something that I will try. 

## Conclusion + Reflections
This project work was defintely challenging and pushed me to learn about system verilog and take ownership in my learning of this module. It's been a very enjoyable journey.

## Acknowledgements
Thank you to Cole (@opnuub) for guiding me through using GitHub and helping me debug my shell files and F1 and pdf testbenches. Thank you to Michael (@Happymic) for helping me verify the testbenches and find the right frequency for the PDF testbench. And thank you to Flavio for providing guidance on the componennts. In general, my group has been extremely surpportive in guiding and making sure we are all on the same page. It was a joy to be in this group.