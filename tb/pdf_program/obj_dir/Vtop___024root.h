// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(trigger,0,0);
    CData/*0:0*/ top__DOT__regWrite;
    CData/*2:0*/ top__DOT__aluControl;
    CData/*0:0*/ top__DOT__aluSrc;
    CData/*1:0*/ top__DOT__immSrc;
    CData/*0:0*/ top__DOT__jalrSrc;
    CData/*0:0*/ top__DOT__jumpSrc;
    CData/*0:0*/ top__DOT__pcSrc;
    CData/*0:0*/ top__DOT__resultSrc;
    CData/*0:0*/ top__DOT__memWrite;
    CData/*2:0*/ top__DOT____Vcellinp__dataMemory__SizeCtr;
    CData/*1:0*/ top__DOT__controlUnit__DOT__aluOp;
    CData/*1:0*/ __Vtrigprevexpr___TOP__top__DOT__controlUnit__DOT__aluOp__0;
    CData/*0:0*/ __VstlDidInit;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*1:0*/ __Vtrigprevexpr___TOP__top__DOT__controlUnit__DOT__aluOp__1;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactDidInit;
    CData/*0:0*/ __VactContinue;
    SData/*15:0*/ __VdfgRegularize_h6171c202_0_0;
    VL_OUT(a0,31,0);
    IData/*31:0*/ top__DOT__pc;
    IData/*31:0*/ top__DOT__instr;
    IData/*31:0*/ top__DOT__immOp;
    IData/*31:0*/ top__DOT__srcA;
    IData/*31:0*/ top__DOT__srcB;
    IData/*31:0*/ top__DOT__regOp2;
    IData/*31:0*/ top__DOT__aluResult;
    IData/*31:0*/ top__DOT__readData;
    IData/*31:0*/ top__DOT__result;
    IData/*31:0*/ top__DOT__nextPC;
    IData/*23:0*/ __VdfgRegularize_h6171c202_0_1;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*7:0*/, 131072> top__DOT__dataMemory__DOT__memory;
    VlUnpacked<IData/*31:0*/, 32> top__DOT__regFile__DOT__rom_array;
    VlUnpacked<CData/*7:0*/, 4096> top__DOT__instrMemory__DOT__rom;
    VlUnpacked<CData/*0:0*/, 4> __Vm_traceActivity;
    VlTriggerVec<2> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
