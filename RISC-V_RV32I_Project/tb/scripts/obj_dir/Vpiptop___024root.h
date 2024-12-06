// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vpiptop.h for the primary calling header

#ifndef VERILATED_VPIPTOP___024ROOT_H_
#define VERILATED_VPIPTOP___024ROOT_H_  // guard

#include "verilated.h"

class Vpiptop__Syms;

class Vpiptop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(trigger,0,0);
    CData/*0:0*/ piptop__DOT__RegWriteD;
    CData/*0:0*/ piptop__DOT__MemWriteD;
    CData/*0:0*/ piptop__DOT__JumpD;
    CData/*0:0*/ piptop__DOT__BranchD;
    CData/*0:0*/ piptop__DOT__ALUSrcD;
    CData/*2:0*/ piptop__DOT__ALUControlD;
    CData/*1:0*/ piptop__DOT__ResultSrcD;
    CData/*4:0*/ piptop__DOT__RdW;
    CData/*0:0*/ piptop__DOT__RegWriteW;
    CData/*1:0*/ piptop__DOT__ResultSrcW;
    CData/*0:0*/ piptop__DOT__zero;
    CData/*0:0*/ __Vclklast__TOP__clk;
    VL_OUT(a0,31,0);
    IData/*31:0*/ piptop__DOT__pc;
    IData/*31:0*/ piptop__DOT__nextPC;
    IData/*31:0*/ piptop__DOT__instr;
    IData/*31:0*/ piptop__DOT__immExt;
    IData/*31:0*/ piptop__DOT__srcB;
    IData/*31:0*/ piptop__DOT__ReadData;
    IData/*31:0*/ piptop__DOT__ALUResultW;
    IData/*31:0*/ piptop__DOT__PCPlus4W;
    IData/*31:0*/ piptop__DOT__triggerFSM__DOT__current_state;
    IData/*31:0*/ piptop__DOT__triggerFSM__DOT__next_state;
    VlUnpacked<CData/*7:0*/, 4096> piptop__DOT__instrMemory__DOT__rom;
    VlUnpacked<IData/*31:0*/, 8> piptop__DOT__PRegFetch__DOT__rom_array;
    VlUnpacked<IData/*31:0*/, 32> piptop__DOT__regfile__DOT__rom_array;
    VlUnpacked<IData/*31:0*/, 16> piptop__DOT__PRegDecode__DOT__rom_array;
    VlUnpacked<IData/*31:0*/, 8> piptop__DOT__PRegExecute__DOT__rom_array;
    VlUnpacked<CData/*7:0*/, 131072> piptop__DOT__DataMemory__DOT__memory;

    // INTERNAL VARIABLES
    Vpiptop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vpiptop___024root(Vpiptop__Syms* symsp, const char* name);
    ~Vpiptop___024root();
    VL_UNCOPYABLE(Vpiptop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
