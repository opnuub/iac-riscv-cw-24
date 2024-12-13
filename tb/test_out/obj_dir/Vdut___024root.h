// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vdut.h for the primary calling header

#ifndef VERILATED_VDUT___024ROOT_H_
#define VERILATED_VDUT___024ROOT_H_  // guard

#include "verilated.h"


class Vdut__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vdut___024root final : public VerilatedModule {
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
        CData/*0:0*/ top__DOT__FlushD;
        CData/*0:0*/ top__DOT__FlushE;
        CData/*0:0*/ top__DOT__stall;
        CData/*1:0*/ top__DOT__ForwardAE;
        CData/*1:0*/ top__DOT__ForwardBE;
        CData/*4:0*/ top__DOT__Rs1E;
        CData/*4:0*/ top__DOT__Rs2E;
        CData/*0:0*/ top__DOT__jalrSrc;
        CData/*0:0*/ top__DOT__zero;
        CData/*0:0*/ top__DOT__JalrE;
        CData/*0:0*/ top__DOT__MemReady;
        CData/*0:0*/ top__DOT__HazardUnit__DOT__load_use_hazard;
        CData/*0:0*/ top__DOT__HazardUnit__DOT__control_hazard;
        CData/*1:0*/ top__DOT__controlUnit__DOT__aluOp;
        CData/*0:0*/ top__DOT__MemoryController__DOT__s0;
        CData/*0:0*/ top__DOT__MemoryController__DOT__l1_hit;
        CData/*0:0*/ top__DOT__MemoryController__DOT__l1_miss;
        CData/*0:0*/ top__DOT__MemoryController__DOT__l1_mem_write;
        CData/*0:0*/ top__DOT__MemoryController__DOT__l1_mem_read;
        CData/*0:0*/ top__DOT__MemoryController__DOT__l1_busy;
        CData/*0:0*/ top__DOT__MemoryController__DOT__l2_hit;
        CData/*0:0*/ top__DOT__MemoryController__DOT__l2_miss;
        CData/*0:0*/ top__DOT__MemoryController__DOT__l2_mem_write;
        CData/*0:0*/ top__DOT__MemoryController__DOT__l2_mem_read;
        CData/*0:0*/ top__DOT__MemoryController__DOT__l2_busy;
        CData/*0:0*/ top__DOT__MemoryController__DOT__l3_hit;
        CData/*0:0*/ top__DOT__MemoryController__DOT__l3_busy;
        CData/*0:0*/ top__DOT__MemoryController__DOT__main_mem_ready_reg;
        CData/*0:0*/ top__DOT__MemoryController__DOT__mem_access;
        CData/*0:0*/ top__DOT__MemoryController__DOT____Vcellinp__l1_cache__store;
        CData/*0:0*/ top__DOT__MemoryController__DOT____Vcellinp__l1_cache__load;
        CData/*2:0*/ top__DOT__MemoryController__DOT__l1_cache__DOT__state;
        CData/*0:0*/ top__DOT__MemoryController__DOT__l1_cache__DOT__way;
        CData/*0:0*/ top__DOT__MemoryController__DOT__l1_cache__DOT__hit_way;
        CData/*0:0*/ top__DOT__MemoryController__DOT__l2_cache__DOT__hit_way;
        CData/*0:0*/ top__DOT__MemoryController__DOT__l2_cache__DOT__way;
    };
    struct {
        CData/*2:0*/ top__DOT__MemoryController__DOT__l2_cache__DOT__state;
        CData/*0:0*/ top__DOT__MemoryController__DOT__l3_cache__DOT__stall;
        CData/*0:0*/ top__DOT__MemoryController__DOT__l3_cache__DOT__mem_read;
        CData/*0:0*/ top__DOT__MemoryController__DOT__l3_cache__DOT__mem_write;
        CData/*0:0*/ top__DOT__MemoryController__DOT__l3_cache__DOT__mem_ready;
        CData/*1:0*/ top__DOT__MemoryController__DOT__l3_cache__DOT__state;
        CData/*1:0*/ __Vdly__top__DOT__MemoryController__DOT__l3_cache__DOT__state;
        CData/*4:0*/ __VdlyDim0__top__DOT__regfile__DOT__rom_array__v0;
        CData/*0:0*/ __Vdly__top__DOT__MemoryController__DOT__l3_busy;
        CData/*2:0*/ __Vdly__top__DOT__MemoryController__DOT__l1_cache__DOT__state;
        CData/*2:0*/ __Vdly__top__DOT__MemoryController__DOT__l2_cache__DOT__state;
        CData/*0:0*/ __Vdly__top__DOT__MemoryController__DOT__l2_busy;
        CData/*0:0*/ __VdlySet__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v0;
        CData/*0:0*/ __VdlySet__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v1;
        CData/*0:0*/ __VdlySet__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2;
        CData/*0:0*/ __VdlySet__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v3;
        CData/*0:0*/ __VdlySet__top__DOT__regfile__DOT__rom_array__v0;
        CData/*0:0*/ __VdlySet__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v0;
        CData/*0:0*/ __VdlySet__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v64;
        CData/*0:0*/ __VdlySet__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v65;
        CData/*0:0*/ __VdlySet__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v68;
        CData/*0:0*/ __VdlySet__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v69;
        CData/*0:0*/ __VdlySet__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v70;
        CData/*0:0*/ __VdlySet__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v0;
        CData/*0:0*/ __VdlySet__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v128;
        CData/*0:0*/ __VdlySet__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v129;
        CData/*0:0*/ __VdlySet__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v130;
        CData/*0:0*/ __VdlySet__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v131;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__rst__0;
        CData/*0:0*/ __VactContinue;
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
        IData/*31:0*/ top__DOT__WriteDataE;
        IData/*31:0*/ top__DOT__MemoryController__DOT__l1_data_out;
        IData/*31:0*/ top__DOT__MemoryController__DOT__l1_mem_write_data;
        IData/*31:0*/ top__DOT__MemoryController__DOT__l2_data_out;
        IData/*31:0*/ top__DOT__MemoryController__DOT__l2_mem_write_data;
        IData/*31:0*/ top__DOT__MemoryController__DOT__l3_data_out;
        IData/*31:0*/ top__DOT__MemoryController__DOT__main_mem_data;
        IData/*31:0*/ top__DOT__MemoryController__DOT__l1_cache__DOT__lru;
        IData/*31:0*/ top__DOT__MemoryController__DOT__l1_cache__DOT__unnamedblk1__DOT__i;
    };
    struct {
        IData/*31:0*/ top__DOT__MemoryController__DOT__l2_cache__DOT__unnamedblk1__DOT__i;
        IData/*31:0*/ top__DOT__MemoryController__DOT__l3_cache__DOT__mem_address;
        IData/*31:0*/ top__DOT__MemoryController__DOT__l3_cache__DOT__mem_write_data;
        IData/*31:0*/ top__DOT__MemoryController__DOT__l3_cache__DOT__mem_read_data;
        IData/*31:0*/ top__DOT__MemoryController__DOT__l3_cache__DOT__unnamedblk1__DOT__i;
        IData/*31:0*/ __Vdly__top__DOT__MemoryController__DOT__l3_data_out;
        IData/*31:0*/ __VdlyVal__top__DOT__regfile__DOT__rom_array__v0;
        IData/*31:0*/ __VactIterCount;
        QData/*63:0*/ top__DOT__MemoryController__DOT__l2_cache__DOT__lru;
        VlUnpacked<CData/*7:0*/, 4096> top__DOT__instrMemory__DOT__rom;
        VlUnpacked<IData/*31:0*/, 32> top__DOT__regfile__DOT__rom_array;
        VlUnpacked<CData/*7:0*/, 131072> top__DOT__MemoryController__DOT__main_memory;
        VlUnpacked<VlUnpacked<QData/*58:0*/, 2>, 32> top__DOT__MemoryController__DOT__l1_cache__DOT__cache;
        VlUnpacked<VlUnpacked<QData/*57:0*/, 2>, 64> top__DOT__MemoryController__DOT__l2_cache__DOT__cache;
        VlUnpacked<VlWide<17>/*527:0*/, 256> top__DOT__MemoryController__DOT__l3_cache__DOT__cache;
        VlUnpacked<CData/*0:0*/, 5> __Vm_traceActivity;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vdut__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vdut___024root(Vdut__Syms* symsp, const char* v__name);
    ~Vdut___024root();
    VL_UNCOPYABLE(Vdut___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
