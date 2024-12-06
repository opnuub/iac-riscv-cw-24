// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VPRegFetch.h for the primary calling header

#ifndef VERILATED_VPREGFETCH___024ROOT_H_
#define VERILATED_VPREGFETCH___024ROOT_H_  // guard

#include "verilated.h"

class VPRegFetch__Syms;

class VPRegFetch___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    CData/*0:0*/ __Vclklast__TOP__clk;
    VL_IN(instr,31,0);
    VL_IN(PCf,31,0);
    VL_IN(PCPlus4F,31,0);
    VL_OUT(PCPlus4D,31,0);
    VL_OUT(PCd,31,0);
    VL_OUT(InstrD,31,0);
    VlUnpacked<IData/*31:0*/, 8> PRegFetch__DOT__rom_array;

    // INTERNAL VARIABLES
    VPRegFetch__Syms* const vlSymsp;

    // CONSTRUCTORS
    VPRegFetch___024root(VPRegFetch__Syms* symsp, const char* name);
    ~VPRegFetch___024root();
    VL_UNCOPYABLE(VPRegFetch___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
