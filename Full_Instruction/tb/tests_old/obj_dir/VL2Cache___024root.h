// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VL2Cache.h for the primary calling header

#ifndef VERILATED_VL2CACHE___024ROOT_H_
#define VERILATED_VL2CACHE___024ROOT_H_  // guard

#include "verilated.h"


class VL2Cache__Syms;

class alignas(VL_CACHE_LINE_BYTES) VL2Cache___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_IN8(load,0,0);
    VL_IN8(store,0,0);
    VL_IN8(mem_ready,0,0);
    VL_OUT8(hit,0,0);
    VL_OUT8(miss,0,0);
    VL_OUT8(mem_write,0,0);
    VL_OUT8(mem_read,0,0);
    VL_OUT8(busy,0,0);
    CData/*2:0*/ L2Cache__DOT__state;
    CData/*0:0*/ L2Cache__DOT__way;
    CData/*0:0*/ L2Cache__DOT__hit_way;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
    CData/*0:0*/ __VactContinue;
    VL_IN(address,31,0);
    VL_IN(data_in,31,0);
    VL_IN(mem_data,31,0);
    VL_OUT(data_out,31,0);
    VL_OUT(mem_write_data,31,0);
    IData/*31:0*/ L2Cache__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ __VactIterCount;
    QData/*63:0*/ L2Cache__DOT__lru;
    VlUnpacked<VlUnpacked<QData/*57:0*/, 2>, 64> L2Cache__DOT__cache;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    VL2Cache__Syms* const vlSymsp;

    // CONSTRUCTORS
    VL2Cache___024root(VL2Cache__Syms* symsp, const char* v__name);
    ~VL2Cache___024root();
    VL_UNCOPYABLE(VL2Cache___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
