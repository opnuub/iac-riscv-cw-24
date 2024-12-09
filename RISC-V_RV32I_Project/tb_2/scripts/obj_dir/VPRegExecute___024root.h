// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VPRegExecute.h for the primary calling header

#ifndef VERILATED_VPREGEXECUTE___024ROOT_H_
#define VERILATED_VPREGEXECUTE___024ROOT_H_  // guard

#include "verilated.h"

class VPRegExecute__Syms;

class VPRegExecute___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(RdE,4,0);
    VL_OUT8(RdM,4,0);
    VL_IN8(RegWriteE,0,0);
    VL_IN8(ResultSrcE,1,0);
    VL_IN8(MemWriteE,0,0);
    VL_OUT8(RegWriteM,0,0);
    VL_OUT8(ResultSrcM,1,0);
    VL_OUT8(MemWriteM,0,0);
    CData/*0:0*/ __Vclklast__TOP__clk;
    VL_IN(ALUout,31,0);
    VL_IN(WriteData,31,0);
    VL_IN(PCPlus4E,31,0);
    VL_OUT(ALUResultM,31,0);
    VL_OUT(WriteDataM,31,0);
    VL_OUT(PCPlus4M,31,0);
    VlUnpacked<IData/*31:0*/, 8> PRegExecute__DOT__rom_array;

    // INTERNAL VARIABLES
    VPRegExecute__Syms* const vlSymsp;

    // CONSTRUCTORS
    VPRegExecute___024root(VPRegExecute__Syms* symsp, const char* name);
    ~VPRegExecute___024root();
    VL_UNCOPYABLE(VPRegExecute___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
