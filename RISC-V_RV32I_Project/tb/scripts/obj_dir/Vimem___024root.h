// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vimem.h for the primary calling header

#ifndef VERILATED_VIMEM___024ROOT_H_
#define VERILATED_VIMEM___024ROOT_H_  // guard

#include "verilated.h"

class Vimem__Syms;

class Vimem___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk_i,0,0);
    CData/*0:0*/ __Vclklast__TOP__clk_i;
    VL_IN(addr_i,31,0);
    VL_OUT(rdata_o,31,0);
    VlUnpacked<CData/*7:0*/, 4096> imem__DOT__mem;

    // INTERNAL VARIABLES
    Vimem__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vimem___024root(Vimem__Syms* symsp, const char* name);
    ~Vimem___024root();
    VL_UNCOPYABLE(Vimem___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
