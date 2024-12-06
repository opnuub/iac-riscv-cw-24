// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vregfile.h for the primary calling header

#ifndef VERILATED_VREGFILE___024ROOT_H_
#define VERILATED_VREGFILE___024ROOT_H_  // guard

#include "verilated.h"

class Vregfile__Syms;

class Vregfile___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk_i,0,0);
    VL_IN8(rst_ni,0,0);
    VL_IN8(wen_i,0,0);
    VL_IN8(waddr_i,4,0);
    VL_IN8(raddr1_i,4,0);
    VL_IN8(raddr2_i,4,0);
    CData/*0:0*/ __Vclklast__TOP__clk_i;
    CData/*0:0*/ __Vclklast__TOP__rst_ni;
    VL_IN(wdata_i,31,0);
    VL_OUT(rdata1_o,31,0);
    VL_OUT(rdata2_o,31,0);
    VL_OUT(a0_o,31,0);
    VlUnpacked<IData/*31:0*/, 32> regfile__DOT__rf_reg;

    // INTERNAL VARIABLES
    Vregfile__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vregfile___024root(Vregfile__Syms* symsp, const char* name);
    ~Vregfile___024root();
    VL_UNCOPYABLE(Vregfile___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
