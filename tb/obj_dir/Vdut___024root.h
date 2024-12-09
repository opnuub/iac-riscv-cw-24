// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vdut.h for the primary calling header

#ifndef VERILATED_VDUT___024ROOT_H_
#define VERILATED_VDUT___024ROOT_H_  // guard

#include "verilated.h"

class Vdut__Syms;

class Vdut___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst,0,0);
        CData/*0:0*/ top__DOT__RegWriteD;
        CData/*0:0*/ top__DOT__MemWriteD;
        CData/*0:0*/ top__DOT__JumpD;
        CData/*0:0*/ top__DOT__BranchD;
        CData/*0:0*/ top__DOT__ALUSrcD;
        CData/*2:0*/ top__DOT__sizeSrcD;
        CData/*1:0*/ top__DOT__ResultSrcD;
        CData/*1:0*/ top__DOT__immSrcD;
        CData/*3:0*/ top__DOT__ALUControlD;
        CData/*4:0*/ top__DOT__RdE;
        CData/*0:0*/ top__DOT__RegWriteE;
        CData/*0:0*/ top__DOT__MemWriteE;
        CData/*0:0*/ top__DOT__JumpE;
        CData/*0:0*/ top__DOT__BranchE;
        CData/*0:0*/ top__DOT__ALUSrcE;
        CData/*2:0*/ top__DOT__sizeSrcE;
        CData/*1:0*/ top__DOT__ResultSrcE;
        CData/*3:0*/ top__DOT__ALUControlE;
        CData/*4:0*/ top__DOT__RdM;
        CData/*0:0*/ top__DOT__RegWriteM;
        CData/*0:0*/ top__DOT__MemWriteM;
        CData/*2:0*/ top__DOT__sizeSrcM;
        CData/*1:0*/ top__DOT__ResultSrcM;
        CData/*4:0*/ top__DOT__RdW;
        CData/*0:0*/ top__DOT__RegWriteW;
        CData/*1:0*/ top__DOT__ResultSrcW;
        CData/*0:0*/ top__DOT__Flush;
        CData/*0:0*/ top__DOT__stall;
        CData/*1:0*/ top__DOT__ForwardAE;
        CData/*1:0*/ top__DOT__ForwardBE;
        CData/*4:0*/ top__DOT__Rs1E;
        CData/*4:0*/ top__DOT__Rs2E;
        CData/*0:0*/ top__DOT__jalrSrc;
        CData/*0:0*/ top__DOT__zero;
        CData/*1:0*/ top__DOT__controlUnit__DOT__aluOp;
        CData/*4:0*/ __Vdlyvdim0__top__DOT__regfile__DOT__rom_array__v0;
        CData/*0:0*/ __Vdlyvset__top__DOT__regfile__DOT__rom_array__v0;
        CData/*0:0*/ __Vclklast__TOP__clk;
        CData/*0:0*/ __Vclklast__TOP__rst;
        VL_OUT(a0,31,0);
        IData/*31:0*/ top__DOT__pc;
        IData/*31:0*/ top__DOT__nextPC;
        IData/*31:0*/ top__DOT__PCd;
        IData/*31:0*/ top__DOT__PCPlus4D;
        IData/*31:0*/ top__DOT__ImmExtD;
        IData/*31:0*/ top__DOT__instrD;
        IData/*31:0*/ top__DOT__PCe;
        IData/*31:0*/ top__DOT__PCPlus4E;
        IData/*31:0*/ top__DOT__ImmExtE;
        IData/*31:0*/ top__DOT__rd1E;
        IData/*31:0*/ top__DOT__rd2E;
        IData/*31:0*/ top__DOT__srcB;
        IData/*31:0*/ top__DOT__aluResult;
        IData/*31:0*/ top__DOT__ALUResultM;
        IData/*31:0*/ top__DOT__WriteDataM;
        IData/*31:0*/ top__DOT__ReadData;
        IData/*31:0*/ top__DOT__PCPlus4M;
        IData/*31:0*/ top__DOT__ALUResultW;
        IData/*31:0*/ top__DOT__ReadDataW;
        IData/*31:0*/ top__DOT__PCPlus4W;
        IData/*31:0*/ top__DOT__ResultW;
        IData/*31:0*/ top__DOT__SrcAE;
    };
    struct {
        IData/*31:0*/ top__DOT__WriteDataE;
        IData/*31:0*/ __Vdlyvval__top__DOT__regfile__DOT__rom_array__v0;
        VlUnpacked<CData/*7:0*/, 4096> top__DOT__instrMemory__DOT__rom;
        VlUnpacked<IData/*31:0*/, 32> top__DOT__regfile__DOT__rom_array;
        VlUnpacked<CData/*7:0*/, 131072> top__DOT__DataMemory__DOT__memory;
        VlUnpacked<CData/*0:0*/, 4> __Vm_traceActivity;
    };

    // INTERNAL VARIABLES
    Vdut__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vdut___024root(Vdut__Syms* symsp, const char* name);
    ~Vdut___024root();
    VL_UNCOPYABLE(Vdut___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
