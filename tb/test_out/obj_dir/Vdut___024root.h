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
    VL_IN8(clk_i,0,0);
    VL_IN8(rst_ni,0,0);
    CData/*0:0*/ top__DOT__branch_eq;
    CData/*0:0*/ top__DOT__branch_lt;
    CData/*0:0*/ top__DOT__branch_ltu;
    CData/*0:0*/ top__DOT__rf_wen;
    CData/*1:0*/ top__DOT__rf_wdata_sel;
    CData/*3:0*/ top__DOT__alu_op;
    CData/*1:0*/ top__DOT__alu_src1_sel;
    CData/*1:0*/ top__DOT__alu_src2_sel;
    CData/*0:0*/ top__DOT__mem_wen;
    CData/*2:0*/ top__DOT__mem_size;
    CData/*0:0*/ top__DOT__mem_signed;
    CData/*2:0*/ top__DOT__next_pc_sel;
    CData/*0:0*/ top__DOT__illegal_instr;
    CData/*2:0*/ top__DOT__controller__DOT__imm_type_o;
    CData/*0:0*/ top__DOT__branch__DOT__branch_taken_o;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk_i__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst_ni__0;
    CData/*0:0*/ __VactContinue;
    VL_OUT(a0_o,31,0);
    IData/*31:0*/ top__DOT__instr;
    IData/*31:0*/ top__DOT__rs1_data;
    IData/*31:0*/ top__DOT__rs2_data;
    IData/*31:0*/ top__DOT__alu_result;
    IData/*31:0*/ top__DOT__imm;
    IData/*31:0*/ top__DOT__alu_src1;
    IData/*31:0*/ top__DOT__alu_src2;
    IData/*31:0*/ top__DOT__regfile__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ top__DOT__dmem__DOT__rdata_aligned;
    IData/*31:0*/ top__DOT__dmem__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ top__DOT__pcunit__DOT__next_pc_o;
    IData/*31:0*/ top__DOT__pcunit__DOT__pc_q;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*7:0*/, 4096> top__DOT__imem__DOT__mem;
    VlUnpacked<IData/*31:0*/, 32> top__DOT__regfile__DOT__rf_reg;
    VlUnpacked<CData/*7:0*/, 8192> top__DOT__dmem__DOT__mem;
    VlUnpacked<CData/*0:0*/, 4> __Vm_traceActivity;
    VlNBACommitQueue<VlUnpacked<CData/*7:0*/, 8192>, false, CData/*7:0*/, 1> __VdlyCommitQueue__top__DOT__dmem__DOT__mem__v0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

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
