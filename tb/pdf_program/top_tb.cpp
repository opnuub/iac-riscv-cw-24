#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp"
#include "Vtop.h"
#include <vector>
#define MAX_SIM_CYC 1000000

int main(int argc, char **argv, char **env){
    Verilated::commandArgs(argc,argv);
    // initiate top verilog instance
    Verilated::traceEverOn(true);
    Vtop* top = new Vtop();
    VerilatedVcdC* tfp = new VerilatedVcdC;

    if (vbdOpen() != 1){
        return (-1);
    }
    vbdHeader("Plotting");
    vbdSetMode(1);
    int simcyc;
    int tick;
    top->clk =1;
    top->rst = 0;
    top->trigger = 1;

    int discyc;
    std::vector<int> norm_dist;
    bool startDisplaying = false;

    for (simcyc=0; simcyc<MAX_SIM_CYC; simcyc++) {
        // dump variables into VCD file and toggle clock
        for (tick=0; tick<2; tick++) {
            tfp->dump (2*simcyc+tick);
            top->clk = !top->clk;
            top->eval ();
        }
        
        //Plot RAM input
        //vbdPlot(int (),0, 255);
        if (int(top->a0) == -1){
            startDisplaying = true;
            discyc = simcyc+2;
        }

        if (startDisplaying and simcyc == discyc and norm_dist.size()<240){
            norm_dist.push_back(int(top->a0));
            discyc += 2;
        }

        if(Verilated::gotFinish() || (vbdGetkey()=='q')){
            exit (0);
        }
    }

    for (int i=0; i<norm_dist.size(); i++){
        vbdPlot(int(norm_dist[i]), 0, 255);
        vbdCycle(i+1);
    }

    vbdClose();
    tfp->close();
    printf("Exiting\n");
    exit(0);
}