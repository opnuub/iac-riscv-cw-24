// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VHazardUnit.h for the primary calling header

#ifndef VERILATED_VHAZARDUNIT___024ROOT_H_
#define VERILATED_VHAZARDUNIT___024ROOT_H_  // guard

#include "verilated.h"


class VHazardUnit__Syms;

class alignas(VL_CACHE_LINE_BYTES) VHazardUnit___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(Rs1E,4,0);
    VL_IN8(Rs2E,4,0);
    VL_IN8(Rs1D,4,0);
    VL_IN8(Rs2D,4,0);
    VL_IN8(RdE,4,0);
    VL_IN8(destReg_m,4,0);
    VL_IN8(destReg_w,4,0);
    VL_IN8(memoryRead_e,0,0);
    VL_IN8(RegWriteM,0,0);
    VL_IN8(RegWriteW,0,0);
    VL_IN8(zero_hazard,0,0);
    VL_IN8(jump_hazard,0,0);
    VL_OUT8(ForwardAE,1,0);
    VL_OUT8(ForwardBE,1,0);
    VL_OUT8(stall,0,0);
    VL_OUT8(Flush,0,0);
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    VHazardUnit__Syms* const vlSymsp;

    // CONSTRUCTORS
    VHazardUnit___024root(VHazardUnit__Syms* symsp, const char* v__name);
    ~VHazardUnit___024root();
    VL_UNCOPYABLE(VHazardUnit___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
