// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VPRegDecode.h for the primary calling header

#ifndef VERILATED_VPREGDECODE___024ROOT_H_
#define VERILATED_VPREGDECODE___024ROOT_H_  // guard

#include "verilated.h"

class VPRegDecode__Syms;

class VPRegDecode___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(RdD,4,0);
    VL_OUT8(RdE,4,0);
    VL_IN8(RegWriteD,0,0);
    VL_IN8(ResultSrcD,1,0);
    VL_IN8(MemWriteD,0,0);
    VL_IN8(JumpD,0,0);
    VL_IN8(BranchD,0,0);
    VL_IN8(ALUControl,2,0);
    VL_IN8(ALUSrcD,0,0);
    VL_OUT8(RegWriteE,0,0);
    VL_OUT8(ResultSrcE,1,0);
    VL_OUT8(MemWriteE,0,0);
    VL_OUT8(JumpE,0,0);
    VL_OUT8(BranchE,0,0);
    VL_OUT8(ALUControlE,2,0);
    VL_OUT8(ALUSrcE,0,0);
    CData/*0:0*/ __Vclklast__TOP__clk;
    VL_IN(rd1,31,0);
    VL_IN(rd2,31,0);
    VL_IN(PCd,31,0);
    VL_IN(ImmExtD,31,0);
    VL_IN(PCPlus4D,31,0);
    VL_OUT(rd1E,31,0);
    VL_OUT(rd2E,31,0);
    VL_OUT(PCe,31,0);
    VL_OUT(ImmExtE,31,0);
    VL_OUT(PcPlus4E,31,0);
    VlUnpacked<IData/*31:0*/, 16> PRegDecode__DOT__rom_array;

    // INTERNAL VARIABLES
    VPRegDecode__Syms* const vlSymsp;

    // CONSTRUCTORS
    VPRegDecode___024root(VPRegDecode__Syms* symsp, const char* name);
    ~VPRegDecode___024root();
    VL_UNCOPYABLE(VPRegDecode___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
