// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VPRegMemory.h for the primary calling header

#ifndef VERILATED_VPREGMEMORY___024ROOT_H_
#define VERILATED_VPREGMEMORY___024ROOT_H_  // guard

#include "verilated.h"

class VPRegMemory__Syms;

class VPRegMemory___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(RdM,4,0);
    VL_OUT8(RdW,4,0);
    VL_IN8(RegWriteM,0,0);
    VL_IN8(ResultSrcM,1,0);
    VL_OUT8(RegWriteW,0,0);
    VL_OUT8(ResultSrcW,1,0);
    CData/*0:0*/ __Vclklast__TOP__clk;
    VL_IN(ALUResultM,31,0);
    VL_IN(DMRd,31,0);
    VL_IN(PCPlus4M,31,0);
    VL_OUT(ALUResultW,31,0);
    VL_OUT(WriteDataW,31,0);
    VL_OUT(PCPlus4W,31,0);
    VlUnpacked<IData/*31:0*/, 8> PRegMemory__DOT__rom_array;

    // INTERNAL VARIABLES
    VPRegMemory__Syms* const vlSymsp;

    // CONSTRUCTORS
    VPRegMemory___024root(VPRegMemory__Syms* symsp, const char* name);
    ~VPRegMemory___024root();
    VL_UNCOPYABLE(VPRegMemory___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
