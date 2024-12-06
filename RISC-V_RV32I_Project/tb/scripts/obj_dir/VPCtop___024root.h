// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VPCtop.h for the primary calling header

#ifndef VERILATED_VPCTOP___024ROOT_H_
#define VERILATED_VPCTOP___024ROOT_H_  // guard

#include "verilated.h"

class VPCtop__Syms;

class VPCtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(PCsrcE,0,0);
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__rst;
    VL_IN(PCTargetE,31,0);
    VL_OUT(InstrD,31,0);
    VL_OUT(PCd,31,0);
    VL_OUT(PCPlus4D,31,0);
    IData/*31:0*/ PCtop__DOT__PCFp;
    IData/*31:0*/ PCtop__DOT__PCf;
    IData/*31:0*/ PCtop__DOT__Rd;
    VlUnpacked<CData/*7:0*/, 4096> PCtop__DOT__imem__DOT__mem;
    VlUnpacked<IData/*31:0*/, 8> PCtop__DOT__PRegFetch__DOT__rom_array;

    // INTERNAL VARIABLES
    VPCtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    VPCtop___024root(VPCtop__Syms* symsp, const char* name);
    ~VPCtop___024root();
    VL_UNCOPYABLE(VPCtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
