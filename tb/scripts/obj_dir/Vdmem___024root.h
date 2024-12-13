// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vdmem.h for the primary calling header

#ifndef VERILATED_VDMEM___024ROOT_H_
#define VERILATED_VDMEM___024ROOT_H_  // guard

#include "verilated.h"


class Vdmem__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vdmem___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk_i,0,0);
    VL_IN8(rst_ni,0,0);
    VL_IN8(wen_i,0,0);
    VL_IN8(size_i,2,0);
    VL_IN8(signed_i,0,0);
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk_i__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst_ni__0;
    CData/*0:0*/ __VactContinue;
    VL_IN(addr_i,31,0);
    VL_IN(wdata_i,31,0);
    VL_OUT(rdata_o,31,0);
    IData/*31:0*/ dmem__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*7:0*/, 8192> dmem__DOT__mem;
    VlNBACommitQueue<VlUnpacked<CData/*7:0*/, 8192>, false, CData/*7:0*/, 1> __VdlyCommitQueue__dmem__DOT__mem__v0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vdmem__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vdmem___024root(Vdmem__Syms* symsp, const char* v__name);
    ~Vdmem___024root();
    VL_UNCOPYABLE(Vdmem___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
