#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vtop.h"
#include <iostream>

#define MAX_SIM_CYC 20

int main(int argc, char **argv, char **env)
{
    int simcyc; // simulation clock count
    int tick;   // each clk cycle has two ticks for two edges

    Verilated::commandArgs(argc, argv);

    Vtop *top = new Vtop;

    VerilatedVcdC *tfp = new VerilatedVcdC;

    Verilated::traceEverOn(true);
    top->trace(tfp, 99);
    tfp->open("waveform.vcd");
    
    top->clk = 0;
    top->rst = 1;
    top->PCsrcE = 0;
    top->PCTargetE = 100;

    for (simcyc = 0; simcyc < MAX_SIM_CYC; simcyc++)
    {
        // Toggle clock for two ticks per cycle (rising and falling edges)
        for (tick = 0; tick < 2; tick++)
        {
            tfp->dump(2 * simcyc + tick);
            top->clk = !top->clk;
            top->eval();
        }

        if(simcyc == 2){
            top->rst = 1;
        }
        if(simcyc == 4){
            top->rst = 0;
        }

        // Control logic for reset and PC branching

        // Print the current PC value on every cycle
        std::cout << "Cycle " << simcyc << std::endl;
        std::cout<< "InstrD = " << top->InstrD << std::endl;
        std::cout << "PCD = " << top->PCd << std::endl;
        std::cout << "PCPlus4D = " << top->PCPlus4D << std::endl;

        // Check for simulation finish condition or key press (if used with Vbuddy)
        if (Verilated::gotFinish())
            break;
    }

    tfp->close();
    delete top;
    delete tfp;
    return 0;
}