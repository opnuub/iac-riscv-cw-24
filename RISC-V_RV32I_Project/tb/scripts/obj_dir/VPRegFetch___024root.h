// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VPRegFetch.h for the primary calling header

#ifndef VERILATED_VPREGFETCH___024ROOT_H_
#define VERILATED_VPREGFETCH___024ROOT_H_  // guard

#include "verilated.h"


class VPRegFetch__Syms;

class alignas(VL_CACHE_LINE_BYTES) VPRegFetch___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(FlushF,0,0);
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst__0;
    CData/*0:0*/ __VactContinue;
    VL_IN(instr,31,0);
    VL_IN(PCf,31,0);
    VL_IN(PCPlus4F,31,0);
    VL_OUT(PCPlus4D,31,0);
    VL_OUT(PCd,31,0);
    VL_OUT(InstrD,31,0);
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    VPRegFetch__Syms* const vlSymsp;

    // CONSTRUCTORS
    VPRegFetch___024root(VPRegFetch__Syms* symsp, const char* v__name);
    ~VPRegFetch___024root();
    VL_UNCOPYABLE(VPRegFetch___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
