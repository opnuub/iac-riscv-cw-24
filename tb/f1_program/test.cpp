#include "Vf1.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

#include "vbuddy.cpp" // include vbuddy code
#define MAX_SIM_CYC 100000

int main(int argc, char **argv, char **env)
{
    int simcyc;     // simulation clock count
    int tick;       // each clk cycle has two ticks for two edges
    int lights = 0; // state to toggle LED lights

    Verilated::commandArgs(argc, argv);
    // init top verilog instance
    Vf1 *top = new Vf1;
    // init trace dump
    Verilated::traceEverOn(true);
    VerilatedVcdC *tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("f1.vcd");

    // init Vbuddy
    if (vbdOpen() != 1)
        return (-1);
    vbdHeader("F1 Program");

    // initialize simulation inputs
    top->clk = 1;
    top->rst = 0;
    top->trigger = 1;

    // run simulation for MAX_SIM_CYC clock cycles
    for (simcyc = 0; simcyc < MAX_SIM_CYC; simcyc++)
    {
        // Start by polling vbdFlag() directly in C++ to manage flow
        if (vbdFlag()) {
            // Here, vbdFlag() is active, so continue simulation
            vbdHeader("Flag is set, continuing simulation.");

            // Simulation loop continues as long as the flag is set
            while (vbdFlag()) {
                // dump variables into VCD file and toggle clock
                for (tick = 0; tick < 2; tick++) {
                    tfp->dump(2 * simcyc + tick);
                    top->clk = !top->clk;
                    top->eval();
                }

                // Display toggle neopixel
                vbdBar(top->a0 & 0xFF);
                top->trigger = vbdFlag();
                vbdCycle(simcyc);

                if (Verilated::gotFinish() || vbdGetkey() == 'q')
                    exit(0);
            }
        }
        else {
            // If vbdFlag() is not set, handle accordingly
            vbdHeader("Flag is not set, resetting or doing other tasks.");
        }
    }

    vbdClose(); // ++++
    tfp->close();
    exit(0);
}
