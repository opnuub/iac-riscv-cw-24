// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdut.h for the primary calling header

#include "Vdut__pch.h"
#include "Vdut___024root.h"

void Vdut___024root___eval_act(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

void Vdut___024root___nba_sequent__TOP__0(Vdut___024root* vlSelf);
void Vdut___024root___nba_sequent__TOP__1(Vdut___024root* vlSelf);
void Vdut___024root___nba_sequent__TOP__2(Vdut___024root* vlSelf);
void Vdut___024root___nba_sequent__TOP__3(Vdut___024root* vlSelf);
void Vdut___024root___nba_sequent__TOP__4(Vdut___024root* vlSelf);
void Vdut___024root___nba_comb__TOP__0(Vdut___024root* vlSelf);

void Vdut___024root___eval_nba(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vdut___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vdut___024root___nba_sequent__TOP__1(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vdut___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vdut___024root___nba_sequent__TOP__3(vlSelf);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vdut___024root___nba_sequent__TOP__4(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    if ((5ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vdut___024root___nba_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
    }
}

VL_INLINE_OPT void Vdut___024root___nba_sequent__TOP__0(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___nba_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__top__DOT__regfile__DOT__rom_array__v0 = 0U;
    if (((IData)(vlSelfRef.top__DOT__RegWriteW) & (0U 
                                                   != (IData)(vlSelfRef.top__DOT__RdW)))) {
        vlSelfRef.__VdlyVal__top__DOT__regfile__DOT__rom_array__v0 
            = vlSelfRef.top__DOT__ResultW;
        vlSelfRef.__VdlyDim0__top__DOT__regfile__DOT__rom_array__v0 
            = vlSelfRef.top__DOT__RdW;
        vlSelfRef.__VdlySet__top__DOT__regfile__DOT__rom_array__v0 = 1U;
    }
}

VL_INLINE_OPT void Vdut___024root___nba_sequent__TOP__1(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___nba_sequent__TOP__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vdly__top__DOT__MemoryController__DOT__l1_cache__DOT__state 
        = vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__state;
    vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v0 = 0U;
    vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v64 = 0U;
    vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v65 = 0U;
    vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v68 = 0U;
    vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v69 = 0U;
    vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v70 = 0U;
    vlSelfRef.__Vdly__top__DOT__MemoryController__DOT__l2_cache__DOT__state 
        = vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__state;
    vlSelfRef.__Vdly__top__DOT__MemoryController__DOT__l2_busy 
        = vlSelfRef.top__DOT__MemoryController__DOT__l2_busy;
    vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v0 = 0U;
    vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v128 = 0U;
    vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v129 = 0U;
    vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v130 = 0U;
    vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v131 = 0U;
    vlSelfRef.__Vdly__top__DOT__MemoryController__DOT__l3_cache__DOT__state 
        = vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__state;
    vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v0 = 0U;
    vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v1 = 0U;
    vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2 = 0U;
    vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v3 = 0U;
    vlSelfRef.__Vdly__top__DOT__MemoryController__DOT__l3_data_out 
        = vlSelfRef.top__DOT__MemoryController__DOT__l3_data_out;
    vlSelfRef.__Vdly__top__DOT__MemoryController__DOT__l3_busy 
        = vlSelfRef.top__DOT__MemoryController__DOT__l3_busy;
    if (vlSelfRef.rst) {
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__unnamedblk1__DOT__i = 0x20U;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__unnamedblk1__DOT__i = 0x40U;
        vlSelfRef.top__DOT__ALUControlE = 0U;
        vlSelfRef.top__DOT__ImmExtE = 0U;
        vlSelfRef.top__DOT__ReadDataW = 0U;
        vlSelfRef.top__DOT__PCe = 0U;
        vlSelfRef.top__DOT__ResultSrcW = 0U;
        vlSelfRef.top__DOT__Rs1E = 0U;
        vlSelfRef.top__DOT__rd2E = 0U;
        vlSelfRef.top__DOT__Rs2E = 0U;
        vlSelfRef.top__DOT__rd1E = 0U;
        vlSelfRef.top__DOT__PCPlus4W = 0U;
        vlSelfRef.top__DOT__ALUResultW = 0U;
        vlSelfRef.top__DOT__RdW = 0U;
        vlSelfRef.top__DOT__PCd = 0U;
        vlSelfRef.top__DOT__ResultSrcM = 0U;
        vlSelfRef.top__DOT__PCPlus4M = 0U;
        vlSelfRef.top__DOT__RdM = 0U;
        vlSelfRef.top__DOT__ResultSrcE = 0U;
        vlSelfRef.top__DOT__PCPlus4E = 0U;
        vlSelfRef.top__DOT__RdE = 0U;
        vlSelfRef.top__DOT__PCPlus4D = 0U;
        vlSelfRef.top__DOT__instrD = 0U;
        vlSelfRef.top__DOT__pc = 0xbfc00000U;
    } else {
        vlSelfRef.top__DOT__ReadDataW = vlSelfRef.top__DOT__ReadData;
        vlSelfRef.top__DOT__ResultSrcW = vlSelfRef.top__DOT__ResultSrcM;
        vlSelfRef.top__DOT__PCPlus4W = vlSelfRef.top__DOT__PCPlus4M;
        vlSelfRef.top__DOT__ALUResultW = vlSelfRef.top__DOT__ALUResultM;
        vlSelfRef.top__DOT__RdW = vlSelfRef.top__DOT__RdM;
        if (vlSelfRef.top__DOT__FlushE) {
            vlSelfRef.top__DOT__ALUControlE = 0U;
            vlSelfRef.top__DOT__ImmExtE = 0U;
            vlSelfRef.top__DOT__PCe = 0U;
            vlSelfRef.top__DOT__ResultSrcM = vlSelfRef.top__DOT__ResultSrcE;
            vlSelfRef.top__DOT__PCPlus4M = vlSelfRef.top__DOT__PCPlus4E;
            vlSelfRef.top__DOT__RdM = vlSelfRef.top__DOT__RdE;
            vlSelfRef.top__DOT__Rs1E = 0U;
            vlSelfRef.top__DOT__rd2E = 0U;
            vlSelfRef.top__DOT__Rs2E = 0U;
            vlSelfRef.top__DOT__rd1E = 0U;
            vlSelfRef.top__DOT__ResultSrcE = 0U;
            vlSelfRef.top__DOT__PCPlus4E = 0U;
            vlSelfRef.top__DOT__RdE = 0U;
        } else {
            vlSelfRef.top__DOT__ALUControlE = vlSelfRef.top__DOT__ALUControlD;
            vlSelfRef.top__DOT__ImmExtE = vlSelfRef.top__DOT__ImmExtD;
            vlSelfRef.top__DOT__PCe = vlSelfRef.top__DOT__PCd;
            vlSelfRef.top__DOT__ResultSrcM = vlSelfRef.top__DOT__ResultSrcE;
            vlSelfRef.top__DOT__PCPlus4M = vlSelfRef.top__DOT__PCPlus4E;
            vlSelfRef.top__DOT__RdM = vlSelfRef.top__DOT__RdE;
            vlSelfRef.top__DOT__Rs1E = (0x1fU & (vlSelfRef.top__DOT__instrD 
                                                 >> 0xfU));
            vlSelfRef.top__DOT__rd2E = vlSelfRef.top__DOT__regfile__DOT__rom_array
                [(0x1fU & (vlSelfRef.top__DOT__instrD 
                           >> 0x14U))];
            vlSelfRef.top__DOT__Rs2E = (0x1fU & (vlSelfRef.top__DOT__instrD 
                                                 >> 0x14U));
            vlSelfRef.top__DOT__rd1E = vlSelfRef.top__DOT__regfile__DOT__rom_array
                [(0x1fU & (vlSelfRef.top__DOT__instrD 
                           >> 0xfU))];
            vlSelfRef.top__DOT__ResultSrcE = vlSelfRef.top__DOT__ResultSrcD;
            vlSelfRef.top__DOT__PCPlus4E = vlSelfRef.top__DOT__PCPlus4D;
            vlSelfRef.top__DOT__RdE = (0x1fU & (vlSelfRef.top__DOT__instrD 
                                                >> 7U));
        }
        if (vlSelfRef.top__DOT__FlushD) {
            vlSelfRef.top__DOT__PCd = 0U;
            vlSelfRef.top__DOT__PCPlus4D = 0U;
            vlSelfRef.top__DOT__instrD = 0U;
        } else if ((1U & (~ (IData)(vlSelfRef.top__DOT__stall)))) {
            vlSelfRef.top__DOT__PCd = vlSelfRef.top__DOT__pc;
            vlSelfRef.top__DOT__PCPlus4D = ((IData)(4U) 
                                            + vlSelfRef.top__DOT__pc);
            vlSelfRef.top__DOT__instrD = ((vlSelfRef.top__DOT__instrMemory__DOT__rom
                                           [(0xfffU 
                                             & ((IData)(3U) 
                                                + vlSelfRef.top__DOT__pc))] 
                                           << 0x18U) 
                                          | ((vlSelfRef.top__DOT__instrMemory__DOT__rom
                                              [(0xfffU 
                                                & ((IData)(2U) 
                                                   + vlSelfRef.top__DOT__pc))] 
                                              << 0x10U) 
                                             | ((vlSelfRef.top__DOT__instrMemory__DOT__rom
                                                 [(0xfffU 
                                                   & ((IData)(1U) 
                                                      + vlSelfRef.top__DOT__pc))] 
                                                 << 8U) 
                                                | vlSelfRef.top__DOT__instrMemory__DOT__rom
                                                [(0xfffU 
                                                  & vlSelfRef.top__DOT__pc)])));
        }
        if ((1U & (~ (IData)(vlSelfRef.top__DOT__stall)))) {
            vlSelfRef.top__DOT__pc = vlSelfRef.top__DOT__nextPC;
        }
    }
    vlSelfRef.__Vdly__top__DOT__MemoryController__DOT__l3_busy 
        = ((~ (IData)(vlSelfRef.rst)) & ((IData)(vlSelfRef.top__DOT__MemoryController__DOT__l2_mem_write) 
                                         | (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l2_mem_read)));
    vlSelfRef.top__DOT__JalrE = ((1U & (~ (IData)(vlSelfRef.rst))) 
                                 && ((1U & (~ (IData)(vlSelfRef.top__DOT__FlushE))) 
                                     && (IData)(vlSelfRef.top__DOT__jalrSrc)));
    vlSelfRef.top__DOT__BranchE = ((1U & (~ (IData)(vlSelfRef.rst))) 
                                   && ((1U & (~ (IData)(vlSelfRef.top__DOT__FlushE))) 
                                       && (IData)(vlSelfRef.top__DOT__BranchD)));
    vlSelfRef.top__DOT__JumpE = ((1U & (~ (IData)(vlSelfRef.rst))) 
                                 && ((1U & (~ (IData)(vlSelfRef.top__DOT__FlushE))) 
                                     && (IData)(vlSelfRef.top__DOT__JumpD)));
    vlSelfRef.top__DOT__ALUSrcE = ((1U & (~ (IData)(vlSelfRef.rst))) 
                                   && ((1U & (~ (IData)(vlSelfRef.top__DOT__FlushE))) 
                                       && (IData)(vlSelfRef.top__DOT__ALUSrcD)));
    vlSelfRef.top__DOT__RegWriteW = ((1U & (~ (IData)(vlSelfRef.rst))) 
                                     && (IData)(vlSelfRef.top__DOT__RegWriteM));
    vlSelfRef.top__DOT__ResultW = ((0U == (IData)(vlSelfRef.top__DOT__ResultSrcW))
                                    ? vlSelfRef.top__DOT__ALUResultW
                                    : ((1U == (IData)(vlSelfRef.top__DOT__ResultSrcW))
                                        ? vlSelfRef.top__DOT__ReadDataW
                                        : ((2U == (IData)(vlSelfRef.top__DOT__ResultSrcW))
                                            ? vlSelfRef.top__DOT__PCPlus4W
                                            : 0U)));
    vlSelfRef.top__DOT__RegWriteM = ((1U & (~ (IData)(vlSelfRef.rst))) 
                                     && (IData)(vlSelfRef.top__DOT__RegWriteE));
    vlSelfRef.top__DOT__RegWriteE = ((1U & (~ (IData)(vlSelfRef.rst))) 
                                     && ((1U & (~ (IData)(vlSelfRef.top__DOT__FlushE))) 
                                         && (IData)(vlSelfRef.top__DOT__RegWriteD)));
    vlSelfRef.top__DOT__ForwardAE = 0U;
    if ((((IData)(vlSelfRef.top__DOT__RegWriteM) & 
          (0U != (IData)(vlSelfRef.top__DOT__RdM))) 
         & ((IData)(vlSelfRef.top__DOT__RdM) == (IData)(vlSelfRef.top__DOT__Rs1E)))) {
        vlSelfRef.top__DOT__ForwardAE = 2U;
    } else if ((((IData)(vlSelfRef.top__DOT__RegWriteW) 
                 & (0U != (IData)(vlSelfRef.top__DOT__RdW))) 
                & ((IData)(vlSelfRef.top__DOT__RdW) 
                   == (IData)(vlSelfRef.top__DOT__Rs1E)))) {
        vlSelfRef.top__DOT__ForwardAE = 1U;
    }
    vlSelfRef.top__DOT__ForwardBE = 0U;
    if ((((IData)(vlSelfRef.top__DOT__RegWriteM) & 
          (0U != (IData)(vlSelfRef.top__DOT__RdM))) 
         & ((IData)(vlSelfRef.top__DOT__RdM) == (IData)(vlSelfRef.top__DOT__Rs2E)))) {
        vlSelfRef.top__DOT__ForwardBE = 2U;
    } else if ((((IData)(vlSelfRef.top__DOT__RegWriteW) 
                 & (0U != (IData)(vlSelfRef.top__DOT__RdW))) 
                & ((IData)(vlSelfRef.top__DOT__RdW) 
                   == (IData)(vlSelfRef.top__DOT__Rs2E)))) {
        vlSelfRef.top__DOT__ForwardBE = 1U;
    }
}

VL_INLINE_OPT void Vdut___024root___nba_sequent__TOP__2(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___nba_sequent__TOP__2\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __VdlyVal__top__DOT__MemoryController__DOT__main_memory__v0;
    __VdlyVal__top__DOT__MemoryController__DOT__main_memory__v0 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__MemoryController__DOT__main_memory__v0;
    __VdlyDim0__top__DOT__MemoryController__DOT__main_memory__v0 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__MemoryController__DOT__main_memory__v1;
    __VdlyVal__top__DOT__MemoryController__DOT__main_memory__v1 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__MemoryController__DOT__main_memory__v1;
    __VdlyDim0__top__DOT__MemoryController__DOT__main_memory__v1 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__MemoryController__DOT__main_memory__v2;
    __VdlyVal__top__DOT__MemoryController__DOT__main_memory__v2 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__MemoryController__DOT__main_memory__v2;
    __VdlyDim0__top__DOT__MemoryController__DOT__main_memory__v2 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__MemoryController__DOT__main_memory__v3;
    __VdlyVal__top__DOT__MemoryController__DOT__main_memory__v3 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__MemoryController__DOT__main_memory__v3;
    __VdlyDim0__top__DOT__MemoryController__DOT__main_memory__v3 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__MemoryController__DOT__main_memory__v4;
    __VdlyVal__top__DOT__MemoryController__DOT__main_memory__v4 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__MemoryController__DOT__main_memory__v4;
    __VdlyDim0__top__DOT__MemoryController__DOT__main_memory__v4 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__MemoryController__DOT__main_memory__v5;
    __VdlyVal__top__DOT__MemoryController__DOT__main_memory__v5 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__MemoryController__DOT__main_memory__v5;
    __VdlyDim0__top__DOT__MemoryController__DOT__main_memory__v5 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__MemoryController__DOT__main_memory__v6;
    __VdlyVal__top__DOT__MemoryController__DOT__main_memory__v6 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__MemoryController__DOT__main_memory__v6;
    __VdlyDim0__top__DOT__MemoryController__DOT__main_memory__v6 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__MemoryController__DOT__main_memory__v0;
    __VdlySet__top__DOT__MemoryController__DOT__main_memory__v0 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__MemoryController__DOT__main_memory__v4;
    __VdlySet__top__DOT__MemoryController__DOT__main_memory__v4 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__MemoryController__DOT__main_memory__v6;
    __VdlySet__top__DOT__MemoryController__DOT__main_memory__v6 = 0;
    // Body
    __VdlySet__top__DOT__MemoryController__DOT__main_memory__v0 = 0U;
    __VdlySet__top__DOT__MemoryController__DOT__main_memory__v4 = 0U;
    __VdlySet__top__DOT__MemoryController__DOT__main_memory__v6 = 0U;
    if ((1U & (~ (IData)(vlSelfRef.rst)))) {
        if (((((IData)(vlSelfRef.top__DOT__MemWriteM) 
               & (~ (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l1_hit))) 
              & (~ (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l2_hit))) 
             & (~ (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l3_hit)))) {
            if ((2U == (IData)(vlSelfRef.top__DOT__sizeSrcM))) {
                __VdlyVal__top__DOT__MemoryController__DOT__main_memory__v0 
                    = (0xffU & vlSelfRef.top__DOT__WriteDataM);
                __VdlyDim0__top__DOT__MemoryController__DOT__main_memory__v0 
                    = (0x1ffffU & vlSelfRef.top__DOT__ALUResultM);
                __VdlySet__top__DOT__MemoryController__DOT__main_memory__v0 = 1U;
                __VdlyVal__top__DOT__MemoryController__DOT__main_memory__v1 
                    = (0xffU & (vlSelfRef.top__DOT__WriteDataM 
                                >> 8U));
                __VdlyDim0__top__DOT__MemoryController__DOT__main_memory__v1 
                    = (0x1ffffU & ((IData)(1U) + vlSelfRef.top__DOT__ALUResultM));
                __VdlyVal__top__DOT__MemoryController__DOT__main_memory__v2 
                    = (0xffU & (vlSelfRef.top__DOT__WriteDataM 
                                >> 0x10U));
                __VdlyDim0__top__DOT__MemoryController__DOT__main_memory__v2 
                    = (0x1ffffU & ((IData)(2U) + vlSelfRef.top__DOT__ALUResultM));
                __VdlyVal__top__DOT__MemoryController__DOT__main_memory__v3 
                    = (vlSelfRef.top__DOT__WriteDataM 
                       >> 0x18U);
                __VdlyDim0__top__DOT__MemoryController__DOT__main_memory__v3 
                    = (0x1ffffU & ((IData)(3U) + vlSelfRef.top__DOT__ALUResultM));
            } else if ((1U == (IData)(vlSelfRef.top__DOT__sizeSrcM))) {
                __VdlyVal__top__DOT__MemoryController__DOT__main_memory__v4 
                    = (0xffU & vlSelfRef.top__DOT__WriteDataM);
                __VdlyDim0__top__DOT__MemoryController__DOT__main_memory__v4 
                    = (0x1ffffU & vlSelfRef.top__DOT__ALUResultM);
                __VdlySet__top__DOT__MemoryController__DOT__main_memory__v4 = 1U;
                __VdlyVal__top__DOT__MemoryController__DOT__main_memory__v5 
                    = (0xffU & (vlSelfRef.top__DOT__WriteDataM 
                                >> 8U));
                __VdlyDim0__top__DOT__MemoryController__DOT__main_memory__v5 
                    = (0x1ffffU & ((IData)(1U) + vlSelfRef.top__DOT__ALUResultM));
            } else if ((0U == (IData)(vlSelfRef.top__DOT__sizeSrcM))) {
                __VdlyVal__top__DOT__MemoryController__DOT__main_memory__v6 
                    = (0xffU & vlSelfRef.top__DOT__WriteDataM);
                __VdlyDim0__top__DOT__MemoryController__DOT__main_memory__v6 
                    = (0x1ffffU & vlSelfRef.top__DOT__ALUResultM);
                __VdlySet__top__DOT__MemoryController__DOT__main_memory__v6 = 1U;
            }
        }
    }
    vlSelfRef.top__DOT__MemoryController__DOT__main_mem_ready_reg 
        = ((1U & (~ (IData)(vlSelfRef.rst))) && ((((IData)(vlSelfRef.top__DOT__MemWriteM) 
                                                   & (~ (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l1_hit))) 
                                                  & (~ (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l2_hit))) 
                                                 & (~ (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l3_hit))));
    if (__VdlySet__top__DOT__MemoryController__DOT__main_memory__v0) {
        vlSelfRef.top__DOT__MemoryController__DOT__main_memory[__VdlyDim0__top__DOT__MemoryController__DOT__main_memory__v0] 
            = __VdlyVal__top__DOT__MemoryController__DOT__main_memory__v0;
        vlSelfRef.top__DOT__MemoryController__DOT__main_memory[__VdlyDim0__top__DOT__MemoryController__DOT__main_memory__v1] 
            = __VdlyVal__top__DOT__MemoryController__DOT__main_memory__v1;
        vlSelfRef.top__DOT__MemoryController__DOT__main_memory[__VdlyDim0__top__DOT__MemoryController__DOT__main_memory__v2] 
            = __VdlyVal__top__DOT__MemoryController__DOT__main_memory__v2;
        vlSelfRef.top__DOT__MemoryController__DOT__main_memory[__VdlyDim0__top__DOT__MemoryController__DOT__main_memory__v3] 
            = __VdlyVal__top__DOT__MemoryController__DOT__main_memory__v3;
    }
    if (__VdlySet__top__DOT__MemoryController__DOT__main_memory__v4) {
        vlSelfRef.top__DOT__MemoryController__DOT__main_memory[__VdlyDim0__top__DOT__MemoryController__DOT__main_memory__v4] 
            = __VdlyVal__top__DOT__MemoryController__DOT__main_memory__v4;
        vlSelfRef.top__DOT__MemoryController__DOT__main_memory[__VdlyDim0__top__DOT__MemoryController__DOT__main_memory__v5] 
            = __VdlyVal__top__DOT__MemoryController__DOT__main_memory__v5;
    }
    if (__VdlySet__top__DOT__MemoryController__DOT__main_memory__v6) {
        vlSelfRef.top__DOT__MemoryController__DOT__main_memory[__VdlyDim0__top__DOT__MemoryController__DOT__main_memory__v6] 
            = __VdlyVal__top__DOT__MemoryController__DOT__main_memory__v6;
    }
}

VL_INLINE_OPT void Vdut___024root___nba_sequent__TOP__3(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___nba_sequent__TOP__3\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__VdlySet__top__DOT__regfile__DOT__rom_array__v0) {
        vlSelfRef.top__DOT__regfile__DOT__rom_array[vlSelfRef.__VdlyDim0__top__DOT__regfile__DOT__rom_array__v0] 
            = vlSelfRef.__VdlyVal__top__DOT__regfile__DOT__rom_array__v0;
    }
    vlSelfRef.a0 = vlSelfRef.top__DOT__regfile__DOT__rom_array
        [0xaU];
}

extern const VlUnpacked<CData/*0:0*/, 1024> Vdut__ConstPool__TABLE_hd4ac5ba3_0;
extern const VlUnpacked<CData/*0:0*/, 1024> Vdut__ConstPool__TABLE_hd0fa4f3e_0;
extern const VlUnpacked<CData/*0:0*/, 1024> Vdut__ConstPool__TABLE_hf71398c3_0;
extern const VlUnpacked<CData/*1:0*/, 1024> Vdut__ConstPool__TABLE_h64d436c7_0;
extern const VlUnpacked<CData/*1:0*/, 1024> Vdut__ConstPool__TABLE_h82129edf_0;
extern const VlUnpacked<CData/*0:0*/, 1024> Vdut__ConstPool__TABLE_hceb9c733_0;
extern const VlUnpacked<CData/*0:0*/, 1024> Vdut__ConstPool__TABLE_hec9e4992_0;
extern const VlUnpacked<CData/*0:0*/, 1024> Vdut__ConstPool__TABLE_h04deb1ff_0;
extern const VlUnpacked<CData/*1:0*/, 1024> Vdut__ConstPool__TABLE_h64afccad_0;
extern const VlUnpacked<CData/*2:0*/, 1024> Vdut__ConstPool__TABLE_h60a80785_0;
extern const VlUnpacked<CData/*3:0*/, 512> Vdut__ConstPool__TABLE_h37780e30_0;

VL_INLINE_OPT void Vdut___024root___nba_sequent__TOP__4(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___nba_sequent__TOP__4\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*9:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    SData/*8:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    CData/*7:0*/ __VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v0;
    __VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v0 = 0;
    CData/*7:0*/ __VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v1;
    __VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v1 = 0;
    VlWide<16>/*511:0*/ __VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2;
    VL_ZERO_W(512, __VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2);
    CData/*7:0*/ __VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2;
    __VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2 = 0;
    SData/*13:0*/ __VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v3;
    __VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v3 = 0;
    CData/*7:0*/ __VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v3;
    __VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v3 = 0;
    CData/*7:0*/ __VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v4;
    __VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v4 = 0;
    CData/*0:0*/ __VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v5;
    __VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v5 = 0;
    CData/*7:0*/ __VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v5;
    __VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v5 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v64;
    __VdlyDim0__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v64 = 0;
    CData/*0:0*/ __VdlyDim1__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v64;
    __VdlyDim1__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v64 = 0;
    CData/*0:0*/ __VdlyVal__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v65;
    __VdlyVal__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v65 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v65;
    __VdlyDim0__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v65 = 0;
    CData/*0:0*/ __VdlyDim1__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v65;
    __VdlyDim1__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v65 = 0;
    IData/*24:0*/ __VdlyVal__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v66;
    __VdlyVal__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v66 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v66;
    __VdlyDim0__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v66 = 0;
    CData/*0:0*/ __VdlyDim1__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v66;
    __VdlyDim1__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v66 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v67;
    __VdlyVal__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v67 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v67;
    __VdlyDim0__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v67 = 0;
    CData/*0:0*/ __VdlyDim1__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v67;
    __VdlyDim1__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v67 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v68;
    __VdlyVal__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v68 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v68;
    __VdlyDim0__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v68 = 0;
    CData/*0:0*/ __VdlyDim1__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v68;
    __VdlyDim1__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v68 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v69;
    __VdlyDim0__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v69 = 0;
    CData/*0:0*/ __VdlyDim1__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v69;
    __VdlyDim1__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v69 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v70;
    __VdlyDim0__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v70 = 0;
    CData/*0:0*/ __VdlyDim1__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v70;
    __VdlyDim1__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v70 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v128;
    __VdlyVal__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v128 = 0;
    CData/*5:0*/ __VdlyDim0__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v128;
    __VdlyDim0__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v128 = 0;
    CData/*0:0*/ __VdlyDim1__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v128;
    __VdlyDim1__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v128 = 0;
    CData/*5:0*/ __VdlyDim0__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v129;
    __VdlyDim0__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v129 = 0;
    CData/*0:0*/ __VdlyDim1__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v129;
    __VdlyDim1__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v129 = 0;
    CData/*5:0*/ __VdlyDim0__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v130;
    __VdlyDim0__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v130 = 0;
    CData/*0:0*/ __VdlyDim1__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v130;
    __VdlyDim1__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v130 = 0;
    CData/*0:0*/ __VdlyVal__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v131;
    __VdlyVal__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v131 = 0;
    CData/*5:0*/ __VdlyDim0__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v131;
    __VdlyDim0__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v131 = 0;
    CData/*0:0*/ __VdlyDim1__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v131;
    __VdlyDim1__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v131 = 0;
    IData/*23:0*/ __VdlyVal__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v132;
    __VdlyVal__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v132 = 0;
    CData/*5:0*/ __VdlyDim0__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v132;
    __VdlyDim0__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v132 = 0;
    CData/*0:0*/ __VdlyDim1__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v132;
    __VdlyDim1__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v132 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v133;
    __VdlyVal__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v133 = 0;
    CData/*5:0*/ __VdlyDim0__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v133;
    __VdlyDim0__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v133 = 0;
    CData/*0:0*/ __VdlyDim1__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v133;
    __VdlyDim1__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v133 = 0;
    // Body
    if (vlSelfRef.rst) {
        vlSelfRef.top__DOT__sizeSrcM = 0U;
        vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__unnamedblk1__DOT__i = 0U;
        vlSelfRef.__Vdly__top__DOT__MemoryController__DOT__l3_cache__DOT__state = 0U;
        vlSelfRef.__Vdly__top__DOT__MemoryController__DOT__l3_data_out = 0U;
        vlSelfRef.top__DOT__MemoryController__DOT__l3_hit = 0U;
        vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__mem_read = 0U;
        vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__mem_write = 0U;
        vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__stall = 0U;
        while (VL_GTS_III(32, 0x100U, vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__unnamedblk1__DOT__i)) {
            vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache[(0xffU 
                                                                             & vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__unnamedblk1__DOT__i)][0U] 
                = (0xfffffffdU & vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache
                   [(0xffU & vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__unnamedblk1__DOT__i)][0U]);
            vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache[(0xffU 
                                                                             & vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__unnamedblk1__DOT__i)][0U] 
                = (0xfffffffeU & vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache
                   [(0xffU & vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__unnamedblk1__DOT__i)][0U]);
            vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache[(0xffU 
                                                                             & vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__unnamedblk1__DOT__i)][0x10U] 
                = (3U & vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache
                   [(0xffU & vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__unnamedblk1__DOT__i)][0x10U]);
            vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__unnamedblk1__DOT__i 
                = ((IData)(1U) + vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__unnamedblk1__DOT__i);
        }
        vlSelfRef.top__DOT__sizeSrcE = 0U;
        vlSelfRef.__Vdly__top__DOT__MemoryController__DOT__l2_cache__DOT__state = 0U;
        vlSelfRef.__Vdly__top__DOT__MemoryController__DOT__l2_busy = 0U;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_mem_read = 0U;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_mem_write = 0U;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__lru = 0ULL;
        vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v0 = 1U;
        vlSelfRef.__Vdly__top__DOT__MemoryController__DOT__l1_cache__DOT__state = 0U;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_busy = 0U;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_mem_read = 0U;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_mem_write = 0U;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__lru = 0U;
        vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v0 = 1U;
        vlSelfRef.top__DOT__WriteDataM = 0U;
        vlSelfRef.top__DOT__ALUResultM = 0U;
    } else {
        vlSelfRef.top__DOT__sizeSrcM = vlSelfRef.top__DOT__sizeSrcE;
        if ((2U & (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__state))) {
            if ((1U & (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__state))) {
                vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__stall = 0U;
                vlSelfRef.__Vdly__top__DOT__MemoryController__DOT__l3_cache__DOT__state = 0U;
            } else {
                vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__stall = 1U;
                vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__mem_write = 1U;
                vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__mem_address 
                    = ((0x3fff000U & (vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache
                                      [(0xffU & (vlSelfRef.top__DOT__ALUResultM 
                                                 >> 4U))][0x10U] 
                                      << 0xaU)) | (0xff0U 
                                                   & vlSelfRef.top__DOT__ALUResultM));
                vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__mem_write_data 
                    = ((vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache
                        [(0xffU & (vlSelfRef.top__DOT__ALUResultM 
                                   >> 4U))][1U] << 0x1eU) 
                       | (vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache
                          [(0xffU & (vlSelfRef.top__DOT__ALUResultM 
                                     >> 4U))][0U] >> 2U));
                if (vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__mem_ready) {
                    vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__mem_write = 0U;
                    __VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v0 
                        = (0xffU & (vlSelfRef.top__DOT__ALUResultM 
                                    >> 4U));
                    vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v0 = 1U;
                    vlSelfRef.__Vdly__top__DOT__MemoryController__DOT__l3_cache__DOT__state = 1U;
                    __VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v1 
                        = (0xffU & (vlSelfRef.top__DOT__ALUResultM 
                                    >> 4U));
                    vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v1 = 1U;
                }
            }
        } else if ((1U & (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__state))) {
            vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__stall = 1U;
            vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__mem_read = 1U;
            vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__mem_address 
                = (0x1ffffU & vlSelfRef.top__DOT__ALUResultM);
            if (vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__mem_ready) {
                __VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[0U] 
                    = vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__mem_read_data;
                __VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[1U] = 0U;
                __VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[2U] = 0U;
                __VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[3U] = 0U;
                __VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[4U] = 0U;
                __VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[5U] = 0U;
                __VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[6U] = 0U;
                __VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[7U] = 0U;
                __VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[8U] = 0U;
                __VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[9U] = 0U;
                __VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[0xaU] = 0U;
                __VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[0xbU] = 0U;
                __VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[0xcU] = 0U;
                __VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[0xdU] = 0U;
                __VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[0xeU] = 0U;
                __VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[0xfU] = 0U;
                __VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2 
                    = (0xffU & (vlSelfRef.top__DOT__ALUResultM 
                                >> 4U));
                vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2 = 1U;
                vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__mem_read = 0U;
                vlSelfRef.__Vdly__top__DOT__MemoryController__DOT__l3_cache__DOT__state = 3U;
                __VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v3 
                    = (0x1fU & (vlSelfRef.top__DOT__ALUResultM 
                                >> 0xcU));
                __VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v3 
                    = (0xffU & (vlSelfRef.top__DOT__ALUResultM 
                                >> 4U));
                vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v3 = 1U;
                __VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v4 
                    = (0xffU & (vlSelfRef.top__DOT__ALUResultM 
                                >> 4U));
                __VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v5 
                    = vlSelfRef.top__DOT__MemoryController__DOT__l2_mem_write;
                __VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v5 
                    = (0xffU & (vlSelfRef.top__DOT__ALUResultM 
                                >> 4U));
            }
        } else {
            vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__stall = 0U;
            if (((vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache
                  [(0xffU & (vlSelfRef.top__DOT__ALUResultM 
                             >> 4U))][0U] >> 1U) & 
                 ((0x3fffU & (vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache
                              [(0xffU & (vlSelfRef.top__DOT__ALUResultM 
                                         >> 4U))][0x10U] 
                              >> 2U)) == (0x1fU & (vlSelfRef.top__DOT__ALUResultM 
                                                   >> 0xcU))))) {
                vlSelfRef.top__DOT__MemoryController__DOT__l3_hit = 1U;
                vlSelfRef.__Vdly__top__DOT__MemoryController__DOT__l3_data_out 
                    = ((0x20fU >= ((IData)(2U) + (0x1ffU 
                                                  & VL_SHIFTL_III(9,32,32, 
                                                                  (0xfU 
                                                                   & vlSelfRef.top__DOT__ALUResultM), 5U))))
                        ? (((0U == (0x1fU & ((IData)(2U) 
                                             + (0x1ffU 
                                                & VL_SHIFTL_III(9,32,32, 
                                                                (0xfU 
                                                                 & vlSelfRef.top__DOT__ALUResultM), 5U)))))
                             ? 0U : (vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache
                                     [(0xffU & (vlSelfRef.top__DOT__ALUResultM 
                                                >> 4U))][
                                     (((IData)(0x21U) 
                                       + (0x1ffU & 
                                          VL_SHIFTL_III(9,32,32, 
                                                        (0xfU 
                                                         & vlSelfRef.top__DOT__ALUResultM), 5U))) 
                                      >> 5U)] << ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(2U) 
                                                      + 
                                                      (0x1ffU 
                                                       & VL_SHIFTL_III(9,32,32, 
                                                                       (0xfU 
                                                                        & vlSelfRef.top__DOT__ALUResultM), 5U))))))) 
                           | (vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache
                              [(0xffU & (vlSelfRef.top__DOT__ALUResultM 
                                         >> 4U))][(
                                                   ((IData)(2U) 
                                                    + 
                                                    (0x1ffU 
                                                     & VL_SHIFTL_III(9,32,32, 
                                                                     (0xfU 
                                                                      & vlSelfRef.top__DOT__ALUResultM), 5U))) 
                                                   >> 5U)] 
                              >> (0x1fU & ((IData)(2U) 
                                           + (0x1ffU 
                                              & VL_SHIFTL_III(9,32,32, 
                                                              (0xfU 
                                                               & vlSelfRef.top__DOT__ALUResultM), 5U))))))
                        : 0U);
            } else {
                vlSelfRef.top__DOT__MemoryController__DOT__l3_hit = 0U;
                vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__stall = 1U;
                vlSelfRef.__Vdly__top__DOT__MemoryController__DOT__l3_cache__DOT__state 
                    = ((1U & vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache
                        [(0xffU & (vlSelfRef.top__DOT__ALUResultM 
                                   >> 4U))][0U]) ? 2U
                        : 1U);
            }
        }
        if ((1U & (~ (IData)(vlSelfRef.top__DOT__FlushE)))) {
            vlSelfRef.top__DOT__sizeSrcE = vlSelfRef.top__DOT__sizeSrcD;
        }
        if ((0U == (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__state))) {
            if (vlSelfRef.top__DOT__MemoryController__DOT__l2_miss) {
                vlSelfRef.__Vdly__top__DOT__MemoryController__DOT__l2_busy = 1U;
                if ((1U & ((IData)((vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache
                                    [(0x3fU & (vlSelfRef.top__DOT__ALUResultM 
                                               >> 2U))]
                                    [vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__way] 
                                    >> 0x39U)) & (IData)(
                                                         (vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache
                                                          [
                                                          (0x3fU 
                                                           & (vlSelfRef.top__DOT__ALUResultM 
                                                              >> 2U))]
                                                          [vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__way] 
                                                          >> 0x38U))))) {
                    vlSelfRef.top__DOT__MemoryController__DOT__l2_mem_write = 1U;
                    vlSelfRef.__Vdly__top__DOT__MemoryController__DOT__l2_cache__DOT__state = 3U;
                } else if (vlSelfRef.top__DOT__MemoryController__DOT__l1_mem_read) {
                    vlSelfRef.top__DOT__MemoryController__DOT__l2_mem_read = 1U;
                    vlSelfRef.__Vdly__top__DOT__MemoryController__DOT__l2_cache__DOT__state = 1U;
                } else {
                    vlSelfRef.__Vdly__top__DOT__MemoryController__DOT__l2_cache__DOT__state = 2U;
                }
            } else {
                vlSelfRef.__Vdly__top__DOT__MemoryController__DOT__l2_busy = 0U;
                if (((IData)(vlSelfRef.top__DOT__MemoryController__DOT__l2_hit) 
                     & (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l1_mem_write))) {
                    __VdlyVal__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v128 
                        = vlSelfRef.top__DOT__MemoryController__DOT__l1_mem_write_data;
                    __VdlyDim0__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v128 
                        = (0x3fU & (vlSelfRef.top__DOT__ALUResultM 
                                    >> 2U));
                    __VdlyDim1__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v128 
                        = vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__hit_way;
                    vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v128 = 1U;
                    vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__lru 
                        = (((~ (1ULL << (0x3fU & (vlSelfRef.top__DOT__ALUResultM 
                                                  >> 2U)))) 
                            & vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__lru) 
                           | ((QData)((IData)((1U & 
                                               (~ (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__hit_way))))) 
                              << (0x3fU & (vlSelfRef.top__DOT__ALUResultM 
                                           >> 2U))));
                    __VdlyDim0__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v129 
                        = (0x3fU & (vlSelfRef.top__DOT__ALUResultM 
                                    >> 2U));
                    __VdlyDim1__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v129 
                        = vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__hit_way;
                    vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v129 = 1U;
                }
            }
        } else if ((3U == (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__state))) {
            if ((1U & (~ (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l3_busy)))) {
                vlSelfRef.top__DOT__MemoryController__DOT__l2_mem_write = 0U;
                if (vlSelfRef.top__DOT__MemoryController__DOT__l1_mem_read) {
                    vlSelfRef.top__DOT__MemoryController__DOT__l2_mem_read = 1U;
                    vlSelfRef.__Vdly__top__DOT__MemoryController__DOT__l2_cache__DOT__state = 1U;
                } else {
                    vlSelfRef.top__DOT__MemoryController__DOT__l2_mem_read = 0U;
                    vlSelfRef.__Vdly__top__DOT__MemoryController__DOT__l2_cache__DOT__state = 2U;
                }
            }
        } else if ((1U == (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__state))) {
            if ((1U & (~ (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l3_busy)))) {
                vlSelfRef.top__DOT__MemoryController__DOT__l2_mem_read = 0U;
                vlSelfRef.__Vdly__top__DOT__MemoryController__DOT__l2_cache__DOT__state = 4U;
            }
        } else if ((2U == (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__state))) {
            vlSelfRef.__Vdly__top__DOT__MemoryController__DOT__l2_cache__DOT__state = 4U;
        } else if ((4U == (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__state))) {
            vlSelfRef.__Vdly__top__DOT__MemoryController__DOT__l2_busy = 0U;
            __VdlyDim0__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v130 
                = (0x3fU & (vlSelfRef.top__DOT__ALUResultM 
                            >> 2U));
            __VdlyDim1__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v130 
                = vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__way;
            vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v130 = 1U;
            vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__lru 
                = (((~ (1ULL << (0x3fU & (vlSelfRef.top__DOT__ALUResultM 
                                          >> 2U)))) 
                    & vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__lru) 
                   | ((QData)((IData)((1U & (~ (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__way))))) 
                      << (0x3fU & (vlSelfRef.top__DOT__ALUResultM 
                                   >> 2U))));
            vlSelfRef.__Vdly__top__DOT__MemoryController__DOT__l2_cache__DOT__state = 0U;
            __VdlyVal__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v131 
                = vlSelfRef.top__DOT__MemoryController__DOT__l1_mem_write;
            __VdlyDim0__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v131 
                = (0x3fU & (vlSelfRef.top__DOT__ALUResultM 
                            >> 2U));
            __VdlyDim1__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v131 
                = vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__way;
            vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v131 = 1U;
            __VdlyVal__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v132 
                = (0x1ffU & (vlSelfRef.top__DOT__ALUResultM 
                             >> 8U));
            __VdlyDim0__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v132 
                = (0x3fU & (vlSelfRef.top__DOT__ALUResultM 
                            >> 2U));
            __VdlyDim1__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v132 
                = vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__way;
            __VdlyVal__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v133 
                = ((IData)(vlSelfRef.top__DOT__MemoryController__DOT__l1_mem_write)
                    ? vlSelfRef.top__DOT__MemoryController__DOT__l1_mem_write_data
                    : vlSelfRef.top__DOT__MemoryController__DOT__l3_data_out);
            __VdlyDim0__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v133 
                = (0x3fU & (vlSelfRef.top__DOT__ALUResultM 
                            >> 2U));
            __VdlyDim1__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v133 
                = vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__way;
        }
        if ((4U & (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__state))) {
            if ((1U & (~ ((IData)(vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__state) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__state)))) {
                    vlSelfRef.top__DOT__MemoryController__DOT__l1_busy = 0U;
                    __VdlyDim0__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v64 
                        = (0x1fU & (vlSelfRef.top__DOT__ALUResultM 
                                    >> 2U));
                    __VdlyDim1__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v64 
                        = vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__way;
                    vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v64 = 1U;
                    vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__lru 
                        = (((~ ((IData)(1U) << (0x1fU 
                                                & (vlSelfRef.top__DOT__ALUResultM 
                                                   >> 2U)))) 
                            & vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__lru) 
                           | (0xffffffffULL & ((1U 
                                                & (~ (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__way))) 
                                               << (0x1fU 
                                                   & (vlSelfRef.top__DOT__ALUResultM 
                                                      >> 2U)))));
                    vlSelfRef.__Vdly__top__DOT__MemoryController__DOT__l1_cache__DOT__state = 0U;
                    __VdlyVal__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v65 
                        = vlSelfRef.top__DOT__MemoryController__DOT____Vcellinp__l1_cache__store;
                    __VdlyDim0__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v65 
                        = (0x1fU & (vlSelfRef.top__DOT__ALUResultM 
                                    >> 2U));
                    __VdlyDim1__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v65 
                        = vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__way;
                    vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v65 = 1U;
                    __VdlyVal__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v66 
                        = (0x3ffU & (vlSelfRef.top__DOT__ALUResultM 
                                     >> 7U));
                    __VdlyDim0__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v66 
                        = (0x1fU & (vlSelfRef.top__DOT__ALUResultM 
                                    >> 2U));
                    __VdlyDim1__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v66 
                        = vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__way;
                    __VdlyVal__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v67 
                        = ((IData)(vlSelfRef.top__DOT__MemoryController__DOT____Vcellinp__l1_cache__store)
                            ? vlSelfRef.top__DOT__WriteDataM
                            : vlSelfRef.top__DOT__MemoryController__DOT__l2_data_out);
                    __VdlyDim0__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v67 
                        = (0x1fU & (vlSelfRef.top__DOT__ALUResultM 
                                    >> 2U));
                    __VdlyDim1__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v67 
                        = vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__way;
                }
            }
        } else if ((2U & (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__state))) {
            if ((1U & (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__state))) {
                if ((1U & (~ (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l2_busy)))) {
                    vlSelfRef.top__DOT__MemoryController__DOT__l1_mem_write = 0U;
                    if (vlSelfRef.top__DOT__MemoryController__DOT____Vcellinp__l1_cache__load) {
                        vlSelfRef.top__DOT__MemoryController__DOT__l1_mem_read = 1U;
                        vlSelfRef.__Vdly__top__DOT__MemoryController__DOT__l1_cache__DOT__state = 1U;
                    } else {
                        vlSelfRef.top__DOT__MemoryController__DOT__l1_mem_read = 0U;
                        vlSelfRef.__Vdly__top__DOT__MemoryController__DOT__l1_cache__DOT__state = 2U;
                    }
                }
            } else {
                vlSelfRef.__Vdly__top__DOT__MemoryController__DOT__l1_cache__DOT__state = 4U;
            }
        } else if ((1U & (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__state))) {
            if ((1U & (~ (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l2_busy)))) {
                vlSelfRef.top__DOT__MemoryController__DOT__l1_mem_read = 0U;
                vlSelfRef.__Vdly__top__DOT__MemoryController__DOT__l1_cache__DOT__state = 4U;
            }
        } else if (vlSelfRef.top__DOT__MemoryController__DOT__l1_miss) {
            vlSelfRef.top__DOT__MemoryController__DOT__l1_busy = 1U;
            if ((1U & ((IData)((vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache
                                [(0x1fU & (vlSelfRef.top__DOT__ALUResultM 
                                           >> 2U))]
                                [vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__way] 
                                >> 0x3aU)) & (IData)(
                                                     (vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache
                                                      [
                                                      (0x1fU 
                                                       & (vlSelfRef.top__DOT__ALUResultM 
                                                          >> 2U))]
                                                      [vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__way] 
                                                      >> 0x39U))))) {
                vlSelfRef.top__DOT__MemoryController__DOT__l1_mem_write = 1U;
                vlSelfRef.__Vdly__top__DOT__MemoryController__DOT__l1_cache__DOT__state = 3U;
            } else if (vlSelfRef.top__DOT__MemoryController__DOT____Vcellinp__l1_cache__load) {
                vlSelfRef.top__DOT__MemoryController__DOT__l1_mem_read = 1U;
                vlSelfRef.__Vdly__top__DOT__MemoryController__DOT__l1_cache__DOT__state = 1U;
            } else {
                vlSelfRef.__Vdly__top__DOT__MemoryController__DOT__l1_cache__DOT__state = 2U;
            }
        } else {
            vlSelfRef.top__DOT__MemoryController__DOT__l1_busy = 0U;
            vlSelfRef.top__DOT__MemoryController__DOT__l1_mem_write = 0U;
            vlSelfRef.top__DOT__MemoryController__DOT__l1_mem_read = 0U;
            if (((IData)(vlSelfRef.top__DOT__MemoryController__DOT__l1_hit) 
                 & (IData)(vlSelfRef.top__DOT__MemoryController__DOT____Vcellinp__l1_cache__store))) {
                __VdlyVal__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v68 
                    = vlSelfRef.top__DOT__WriteDataM;
                __VdlyDim0__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v68 
                    = (0x1fU & (vlSelfRef.top__DOT__ALUResultM 
                                >> 2U));
                __VdlyDim1__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v68 
                    = vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__hit_way;
                vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v68 = 1U;
                vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__lru 
                    = (((~ ((IData)(1U) << (0x1fU & 
                                            (vlSelfRef.top__DOT__ALUResultM 
                                             >> 2U)))) 
                        & vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__lru) 
                       | (0xffffffffULL & ((1U & (~ (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__hit_way))) 
                                           << (0x1fU 
                                               & (vlSelfRef.top__DOT__ALUResultM 
                                                  >> 2U)))));
                __VdlyDim0__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v69 
                    = (0x1fU & (vlSelfRef.top__DOT__ALUResultM 
                                >> 2U));
                __VdlyDim1__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v69 
                    = vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__hit_way;
                vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v69 = 1U;
            } else if (vlSelfRef.top__DOT__MemoryController__DOT____Vcellinp__l1_cache__store) {
                __VdlyDim0__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v70 
                    = (0x1fU & (vlSelfRef.top__DOT__ALUResultM 
                                >> 2U));
                __VdlyDim1__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v70 
                    = vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__way;
                vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v70 = 1U;
            }
        }
        vlSelfRef.top__DOT__WriteDataM = vlSelfRef.top__DOT__WriteDataE;
        vlSelfRef.top__DOT__ALUResultM = vlSelfRef.top__DOT__aluResult;
    }
    vlSelfRef.top__DOT__MemWriteM = ((1U & (~ (IData)(vlSelfRef.rst))) 
                                     && (IData)(vlSelfRef.top__DOT__MemWriteE));
    vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__state 
        = vlSelfRef.__Vdly__top__DOT__MemoryController__DOT__l3_cache__DOT__state;
    if (vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v0) {
        vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache[__VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v0][0U] 
            = (0xfffffffeU & vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache
               [__VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v0][0U]);
    }
    if (vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v1) {
        vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache[__VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v1][0U] 
            = (0xfffffffdU & vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache
               [__VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v1][0U]);
    }
    if (vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2) {
        vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache[__VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2][0U] 
            = ((3U & vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache
                [__VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2][0U]) 
               | (__VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[0U] 
                  << 2U));
        vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache[__VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2][1U] 
            = ((__VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[0U] 
                >> 0x1eU) | (__VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[1U] 
                             << 2U));
        vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache[__VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2][2U] 
            = ((__VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[1U] 
                >> 0x1eU) | (__VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[2U] 
                             << 2U));
        vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache[__VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2][3U] 
            = ((__VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[2U] 
                >> 0x1eU) | (__VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[3U] 
                             << 2U));
        vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache[__VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2][4U] 
            = ((__VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[3U] 
                >> 0x1eU) | (__VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[4U] 
                             << 2U));
        vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache[__VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2][5U] 
            = ((__VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[4U] 
                >> 0x1eU) | (__VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[5U] 
                             << 2U));
        vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache[__VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2][6U] 
            = ((__VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[5U] 
                >> 0x1eU) | (__VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[6U] 
                             << 2U));
        vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache[__VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2][7U] 
            = ((__VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[6U] 
                >> 0x1eU) | (__VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[7U] 
                             << 2U));
        vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache[__VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2][8U] 
            = ((__VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[7U] 
                >> 0x1eU) | (__VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[8U] 
                             << 2U));
        vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache[__VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2][9U] 
            = ((__VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[8U] 
                >> 0x1eU) | (__VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[9U] 
                             << 2U));
        vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache[__VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2][0xaU] 
            = ((__VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[9U] 
                >> 0x1eU) | (__VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[0xaU] 
                             << 2U));
        vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache[__VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2][0xbU] 
            = ((__VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[0xaU] 
                >> 0x1eU) | (__VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[0xbU] 
                             << 2U));
        vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache[__VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2][0xcU] 
            = ((__VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[0xbU] 
                >> 0x1eU) | (__VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[0xcU] 
                             << 2U));
        vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache[__VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2][0xdU] 
            = ((__VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[0xcU] 
                >> 0x1eU) | (__VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[0xdU] 
                             << 2U));
        vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache[__VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2][0xeU] 
            = ((__VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[0xdU] 
                >> 0x1eU) | (__VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[0xeU] 
                             << 2U));
        vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache[__VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2][0xfU] 
            = ((__VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[0xeU] 
                >> 0x1eU) | (__VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[0xfU] 
                             << 2U));
        vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache[__VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2][0x10U] 
            = ((0xfffcU & vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache
                [__VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2][0x10U]) 
               | (0xffffU & (__VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2[0xfU] 
                             >> 0x1eU)));
    }
    if (vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v3) {
        vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache[__VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v3][0x10U] 
            = ((3U & vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache
                [__VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v3][0x10U]) 
               | (0xffffU & ((IData)(__VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v3) 
                             << 2U)));
        vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache[__VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v4][0U] 
            = (2U | vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache
               [__VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v4][0U]);
        vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache[__VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v5][0U] 
            = ((0xfffffffeU & vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__cache
                [__VdlyDim0__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v5][0U]) 
               | (IData)(__VdlyVal__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v5));
    }
    vlSelfRef.top__DOT__MemWriteE = ((1U & (~ (IData)(vlSelfRef.rst))) 
                                     && ((1U & (~ (IData)(vlSelfRef.top__DOT__FlushE))) 
                                         && (IData)(vlSelfRef.top__DOT__MemWriteD)));
    vlSelfRef.top__DOT__MemoryController__DOT__mem_access 
        = ((IData)(vlSelfRef.top__DOT__MemWriteM) | 
           (7U != (IData)(vlSelfRef.top__DOT__sizeSrcM)));
    __Vtableidx1 = ((0x380U & (vlSelfRef.top__DOT__instrD 
                               >> 5U)) | (0x7fU & vlSelfRef.top__DOT__instrD));
    vlSelfRef.top__DOT__RegWriteD = Vdut__ConstPool__TABLE_hd4ac5ba3_0
        [__Vtableidx1];
    vlSelfRef.top__DOT__MemWriteD = Vdut__ConstPool__TABLE_hd0fa4f3e_0
        [__Vtableidx1];
    vlSelfRef.top__DOT__ALUSrcD = Vdut__ConstPool__TABLE_hf71398c3_0
        [__Vtableidx1];
    vlSelfRef.top__DOT__immSrcD = Vdut__ConstPool__TABLE_h64d436c7_0
        [__Vtableidx1];
    vlSelfRef.top__DOT__ResultSrcD = Vdut__ConstPool__TABLE_h82129edf_0
        [__Vtableidx1];
    vlSelfRef.top__DOT__BranchD = Vdut__ConstPool__TABLE_hceb9c733_0
        [__Vtableidx1];
    vlSelfRef.top__DOT__JumpD = Vdut__ConstPool__TABLE_hec9e4992_0
        [__Vtableidx1];
    vlSelfRef.top__DOT__jalrSrc = Vdut__ConstPool__TABLE_h04deb1ff_0
        [__Vtableidx1];
    vlSelfRef.top__DOT__controlUnit__DOT__aluOp = Vdut__ConstPool__TABLE_h64afccad_0
        [__Vtableidx1];
    vlSelfRef.top__DOT__sizeSrcD = Vdut__ConstPool__TABLE_h60a80785_0
        [__Vtableidx1];
    vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__state 
        = vlSelfRef.__Vdly__top__DOT__MemoryController__DOT__l2_cache__DOT__state;
    vlSelfRef.top__DOT__MemoryController__DOT__l3_busy 
        = vlSelfRef.__Vdly__top__DOT__MemoryController__DOT__l3_busy;
    vlSelfRef.top__DOT__MemoryController__DOT__l3_data_out 
        = vlSelfRef.__Vdly__top__DOT__MemoryController__DOT__l3_data_out;
    if (vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v0) {
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[1U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[1U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[2U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[2U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[3U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[3U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[4U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[4U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[5U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[5U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[6U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[6U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[7U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[7U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[8U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[8U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[9U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[9U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0xaU][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0xaU][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0xbU][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0xbU][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0xcU][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0xcU][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0xdU][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0xdU][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0xeU][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0xeU][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0xfU][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0xfU][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x10U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x10U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x11U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x11U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x12U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x12U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x13U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x13U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x14U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x14U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x15U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x15U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x16U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x16U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x17U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x17U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x18U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x18U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x19U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x19U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x1aU][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x1aU][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x1bU][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x1bU][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x1cU][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x1cU][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x1dU][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x1dU][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x1eU][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x1eU][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x1fU][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x1fU][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x20U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x20U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x21U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x21U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x22U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x22U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x23U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x23U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x24U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x24U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x25U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x25U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x26U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x26U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x27U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x27U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x28U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x28U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x29U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x29U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x2aU][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x2aU][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x2bU][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x2bU][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x2cU][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x2cU][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x2dU][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x2dU][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x2eU][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x2eU][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x2fU][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x2fU][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x30U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x30U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x31U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x31U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x32U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x32U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x33U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x33U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x34U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x34U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x35U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x35U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x36U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x36U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x37U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x37U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x38U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x38U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x39U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x39U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x3aU][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x3aU][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x3bU][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x3bU][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x3cU][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x3cU][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x3dU][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x3dU][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x3eU][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x3eU][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x3fU][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[0x3fU][1U] = 0ULL;
    }
    if (vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v128) {
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[__VdlyDim0__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v128][__VdlyDim1__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v128] 
            = ((0x3ffffff00000000ULL & vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache
                [__VdlyDim0__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v128]
                [__VdlyDim1__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v128]) 
               | (IData)((IData)(__VdlyVal__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v128)));
    }
    if (vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v129) {
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[__VdlyDim0__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v129][__VdlyDim1__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v129] 
            = (0x100000000000000ULL | vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache
               [__VdlyDim0__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v129]
               [__VdlyDim1__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v129]);
    }
    if (vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v130) {
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[__VdlyDim0__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v130][__VdlyDim1__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v130] 
            = (0x200000000000000ULL | vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache
               [__VdlyDim0__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v130]
               [__VdlyDim1__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v130]);
    }
    if (vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v131) {
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[__VdlyDim0__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v131][__VdlyDim1__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v131] 
            = ((0x2ffffffffffffffULL & vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache
                [__VdlyDim0__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v131]
                [__VdlyDim1__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v131]) 
               | ((QData)((IData)(__VdlyVal__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v131)) 
                  << 0x38U));
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[__VdlyDim0__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v132][__VdlyDim1__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v132] 
            = ((0x3000000ffffffffULL & vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache
                [__VdlyDim0__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v132]
                [__VdlyDim1__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v132]) 
               | ((QData)((IData)(__VdlyVal__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v132)) 
                  << 0x20U));
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache[__VdlyDim0__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v133][__VdlyDim1__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v133] 
            = ((0x3ffffff00000000ULL & vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache
                [__VdlyDim0__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v133]
                [__VdlyDim1__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v133]) 
               | (IData)((IData)(__VdlyVal__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v133)));
    }
    vlSelfRef.top__DOT__ImmExtD = ((2U & (IData)(vlSelfRef.top__DOT__immSrcD))
                                    ? ((1U & (IData)(vlSelfRef.top__DOT__immSrcD))
                                        ? ((IData)(vlSelfRef.top__DOT__JumpD)
                                            ? (((- (IData)(
                                                           (vlSelfRef.top__DOT__instrD 
                                                            >> 0x1fU))) 
                                                << 0x15U) 
                                               | ((0x100000U 
                                                   & (vlSelfRef.top__DOT__instrD 
                                                      >> 0xbU)) 
                                                  | ((0xff000U 
                                                      & vlSelfRef.top__DOT__instrD) 
                                                     | ((0x800U 
                                                         & (vlSelfRef.top__DOT__instrD 
                                                            >> 9U)) 
                                                        | (0x7feU 
                                                           & (vlSelfRef.top__DOT__instrD 
                                                              >> 0x14U))))))
                                            : (0xfffff000U 
                                               & vlSelfRef.top__DOT__instrD))
                                        : (((- (IData)(
                                                       (vlSelfRef.top__DOT__instrD 
                                                        >> 0x1fU))) 
                                            << 0xcU) 
                                           | ((0x800U 
                                               & (vlSelfRef.top__DOT__instrD 
                                                  << 4U)) 
                                              | ((0x7e0U 
                                                  & (vlSelfRef.top__DOT__instrD 
                                                     >> 0x14U)) 
                                                 | (0x1eU 
                                                    & (vlSelfRef.top__DOT__instrD 
                                                       >> 7U))))))
                                    : ((1U & (IData)(vlSelfRef.top__DOT__immSrcD))
                                        ? (((- (IData)(
                                                       (vlSelfRef.top__DOT__instrD 
                                                        >> 0x1fU))) 
                                            << 0xcU) 
                                           | ((0xfe0U 
                                               & (vlSelfRef.top__DOT__instrD 
                                                  >> 0x14U)) 
                                              | (0x1fU 
                                                 & (vlSelfRef.top__DOT__instrD 
                                                    >> 7U))))
                                        : (((- (IData)(
                                                       (vlSelfRef.top__DOT__instrD 
                                                        >> 0x1fU))) 
                                            << 0xcU) 
                                           | (vlSelfRef.top__DOT__instrD 
                                              >> 0x14U))));
    __Vtableidx2 = ((((3U == ((2U & (vlSelfRef.top__DOT__instrD 
                                     >> 4U)) | (1U 
                                                & (vlSelfRef.top__DOT__instrD 
                                                   >> 0x1eU))))
                       ? 1U : 0U) << 5U) | ((0x1cU 
                                             & (vlSelfRef.top__DOT__instrD 
                                                >> 0xaU)) 
                                            | (IData)(vlSelfRef.top__DOT__controlUnit__DOT__aluOp)));
    vlSelfRef.top__DOT__ALUControlD = Vdut__ConstPool__TABLE_h37780e30_0
        [__Vtableidx2];
    vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__state 
        = vlSelfRef.__Vdly__top__DOT__MemoryController__DOT__l1_cache__DOT__state;
    vlSelfRef.top__DOT__MemoryController__DOT__l2_busy 
        = vlSelfRef.__Vdly__top__DOT__MemoryController__DOT__l2_busy;
    vlSelfRef.top__DOT__MemoryController__DOT____Vcellinp__l1_cache__store 
        = ((IData)(vlSelfRef.top__DOT__MemWriteM) & (IData)(vlSelfRef.top__DOT__MemoryController__DOT__mem_access));
    vlSelfRef.top__DOT__MemoryController__DOT____Vcellinp__l1_cache__load 
        = ((~ (IData)(vlSelfRef.top__DOT__MemWriteM)) 
           & (IData)(vlSelfRef.top__DOT__MemoryController__DOT__mem_access));
    if (vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v0) {
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[1U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[1U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[2U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[2U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[3U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[3U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[4U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[4U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[5U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[5U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[6U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[6U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[7U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[7U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[8U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[8U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[9U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[9U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0xaU][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0xaU][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0xbU][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0xbU][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0xcU][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0xcU][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0xdU][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0xdU][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0xeU][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0xeU][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0xfU][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0xfU][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0x10U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0x10U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0x11U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0x11U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0x12U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0x12U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0x13U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0x13U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0x14U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0x14U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0x15U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0x15U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0x16U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0x16U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0x17U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0x17U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0x18U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0x18U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0x19U][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0x19U][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0x1aU][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0x1aU][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0x1bU][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0x1bU][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0x1cU][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0x1cU][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0x1dU][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0x1dU][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0x1eU][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0x1eU][1U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0x1fU][0U] = 0ULL;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[0x1fU][1U] = 0ULL;
    }
    if (vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v64) {
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[__VdlyDim0__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v64][__VdlyDim1__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v64] 
            = (0x400000000000000ULL | vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache
               [__VdlyDim0__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v64]
               [__VdlyDim1__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v64]);
    }
    if (vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v65) {
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[__VdlyDim0__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v65][__VdlyDim1__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v65] 
            = ((0x5ffffffffffffffULL & vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache
                [__VdlyDim0__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v65]
                [__VdlyDim1__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v65]) 
               | ((QData)((IData)(__VdlyVal__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v65)) 
                  << 0x39U));
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[__VdlyDim0__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v66][__VdlyDim1__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v66] 
            = ((0x6000000ffffffffULL & vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache
                [__VdlyDim0__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v66]
                [__VdlyDim1__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v66]) 
               | ((QData)((IData)(__VdlyVal__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v66)) 
                  << 0x20U));
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[__VdlyDim0__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v67][__VdlyDim1__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v67] 
            = ((0x7ffffff00000000ULL & vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache
                [__VdlyDim0__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v67]
                [__VdlyDim1__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v67]) 
               | (IData)((IData)(__VdlyVal__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v67)));
    }
    if (vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v68) {
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[__VdlyDim0__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v68][__VdlyDim1__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v68] 
            = ((0x7ffffff00000000ULL & vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache
                [__VdlyDim0__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v68]
                [__VdlyDim1__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v68]) 
               | (IData)((IData)(__VdlyVal__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v68)));
    }
    if (vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v69) {
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[__VdlyDim0__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v69][__VdlyDim1__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v69] 
            = (0x200000000000000ULL | vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache
               [__VdlyDim0__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v69]
               [__VdlyDim1__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v69]);
    }
    if (vlSelfRef.__VdlySet__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v70) {
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache[__VdlyDim0__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v70][__VdlyDim1__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v70] 
            = (0x200000000000000ULL | vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache
               [__VdlyDim0__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v70]
               [__VdlyDim1__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v70]);
    }
    vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__way 
        = (1U & (vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__lru 
                 >> (0x1fU & (vlSelfRef.top__DOT__ALUResultM 
                              >> 2U))));
    if ((1U & (IData)((vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache
                       [(0x1fU & (vlSelfRef.top__DOT__ALUResultM 
                                  >> 2U))][0U] >> 0x3aU)))) {
        if ((1U & (~ (IData)((vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache
                              [(0x1fU & (vlSelfRef.top__DOT__ALUResultM 
                                         >> 2U))][1U] 
                              >> 0x3aU))))) {
            vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__way = 1U;
        }
    } else {
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__way = 0U;
    }
    vlSelfRef.top__DOT__MemoryController__DOT__l1_mem_write_data 
        = (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache
                  [(0x1fU & (vlSelfRef.top__DOT__ALUResultM 
                             >> 2U))][vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__way]);
    vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__way 
        = (1U & (IData)((vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__lru 
                         >> (0x3fU & (vlSelfRef.top__DOT__ALUResultM 
                                      >> 2U)))));
    if ((1U & (IData)((vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache
                       [(0x3fU & (vlSelfRef.top__DOT__ALUResultM 
                                  >> 2U))][0U] >> 0x39U)))) {
        if ((1U & (~ (IData)((vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache
                              [(0x3fU & (vlSelfRef.top__DOT__ALUResultM 
                                         >> 2U))][1U] 
                              >> 0x39U))))) {
            vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__way = 1U;
        }
    } else {
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__way = 0U;
    }
    vlSelfRef.top__DOT__MemoryController__DOT__l2_mem_write_data 
        = (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache
                  [(0x3fU & (vlSelfRef.top__DOT__ALUResultM 
                             >> 2U))][vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__way]);
    vlSelfRef.top__DOT__SrcAE = ((0U == (IData)(vlSelfRef.top__DOT__ForwardAE))
                                  ? vlSelfRef.top__DOT__rd1E
                                  : ((1U == (IData)(vlSelfRef.top__DOT__ForwardAE))
                                      ? vlSelfRef.top__DOT__ResultW
                                      : ((2U == (IData)(vlSelfRef.top__DOT__ForwardAE))
                                          ? vlSelfRef.top__DOT__ALUResultM
                                          : vlSelfRef.top__DOT__rd1E)));
    vlSelfRef.top__DOT__WriteDataE = ((0U == (IData)(vlSelfRef.top__DOT__ForwardBE))
                                       ? vlSelfRef.top__DOT__rd2E
                                       : ((1U == (IData)(vlSelfRef.top__DOT__ForwardBE))
                                           ? vlSelfRef.top__DOT__ResultW
                                           : ((2U == (IData)(vlSelfRef.top__DOT__ForwardBE))
                                               ? vlSelfRef.top__DOT__ALUResultM
                                               : vlSelfRef.top__DOT__rd2E)));
    vlSelfRef.top__DOT__MemoryController__DOT__l2_hit = 0U;
    vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__hit_way = 0U;
    if (((IData)((vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache
                  [(0x3fU & (vlSelfRef.top__DOT__ALUResultM 
                             >> 2U))][0U] >> 0x39U)) 
         & ((0xffffffU & (IData)((vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache
                                  [(0x3fU & (vlSelfRef.top__DOT__ALUResultM 
                                             >> 2U))]
                                  [0U] >> 0x20U))) 
            == (0x1ffU & (vlSelfRef.top__DOT__ALUResultM 
                          >> 8U))))) {
        vlSelfRef.top__DOT__MemoryController__DOT__l2_hit = 1U;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__hit_way = 0U;
    } else if (((IData)((vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache
                         [(0x3fU & (vlSelfRef.top__DOT__ALUResultM 
                                    >> 2U))][1U] >> 0x39U)) 
                & ((0xffffffU & (IData)((vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache
                                         [(0x3fU & 
                                           (vlSelfRef.top__DOT__ALUResultM 
                                            >> 2U))]
                                         [1U] >> 0x20U))) 
                   == (0x1ffU & (vlSelfRef.top__DOT__ALUResultM 
                                 >> 8U))))) {
        vlSelfRef.top__DOT__MemoryController__DOT__l2_hit = 1U;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__hit_way = 1U;
    }
    vlSelfRef.top__DOT__MemoryController__DOT__l2_miss 
        = ((~ (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l2_hit)) 
           & ((IData)(vlSelfRef.top__DOT__MemoryController__DOT__l1_mem_read) 
              | (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l1_mem_write)));
    vlSelfRef.top__DOT__MemoryController__DOT__l2_data_out 
        = ((IData)(vlSelfRef.top__DOT__MemoryController__DOT__l2_hit)
            ? (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache
                      [(0x3fU & (vlSelfRef.top__DOT__ALUResultM 
                                 >> 2U))][vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__hit_way])
            : vlSelfRef.top__DOT__MemoryController__DOT__l3_data_out);
    vlSelfRef.top__DOT__srcB = ((IData)(vlSelfRef.top__DOT__ALUSrcE)
                                 ? vlSelfRef.top__DOT__ImmExtE
                                 : vlSelfRef.top__DOT__WriteDataE);
    vlSelfRef.top__DOT__MemoryController__DOT__l1_hit = 0U;
    vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__hit_way = 0U;
    if (((IData)((vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache
                  [(0x1fU & (vlSelfRef.top__DOT__ALUResultM 
                             >> 2U))][0U] >> 0x3aU)) 
         & ((0x1ffffffU & (IData)((vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache
                                   [(0x1fU & (vlSelfRef.top__DOT__ALUResultM 
                                              >> 2U))]
                                   [0U] >> 0x20U))) 
            == (0x3ffU & (vlSelfRef.top__DOT__ALUResultM 
                          >> 7U))))) {
        vlSelfRef.top__DOT__MemoryController__DOT__l1_hit = 1U;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__hit_way = 0U;
    } else if (((IData)((vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache
                         [(0x1fU & (vlSelfRef.top__DOT__ALUResultM 
                                    >> 2U))][1U] >> 0x3aU)) 
                & ((0x1ffffffU & (IData)((vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache
                                          [(0x1fU & 
                                            (vlSelfRef.top__DOT__ALUResultM 
                                             >> 2U))]
                                          [1U] >> 0x20U))) 
                   == (0x3ffU & (vlSelfRef.top__DOT__ALUResultM 
                                 >> 7U))))) {
        vlSelfRef.top__DOT__MemoryController__DOT__l1_hit = 1U;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__hit_way = 1U;
    }
    vlSelfRef.top__DOT__MemoryController__DOT__l1_miss 
        = ((~ (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l1_hit)) 
           & ((IData)(vlSelfRef.top__DOT__MemoryController__DOT____Vcellinp__l1_cache__load) 
              | (IData)(vlSelfRef.top__DOT__MemoryController__DOT____Vcellinp__l1_cache__store)));
    vlSelfRef.top__DOT__MemoryController__DOT__l1_data_out 
        = ((IData)(vlSelfRef.top__DOT__MemoryController__DOT__l1_hit)
            ? (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache
                      [(0x1fU & (vlSelfRef.top__DOT__ALUResultM 
                                 >> 2U))][vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__hit_way])
            : vlSelfRef.top__DOT__MemoryController__DOT__l2_data_out);
    if (((((((((0U == (IData)(vlSelfRef.top__DOT__ALUControlE)) 
               | (1U == (IData)(vlSelfRef.top__DOT__ALUControlE))) 
              | (2U == (IData)(vlSelfRef.top__DOT__ALUControlE))) 
             | (3U == (IData)(vlSelfRef.top__DOT__ALUControlE))) 
            | (4U == (IData)(vlSelfRef.top__DOT__ALUControlE))) 
           | (5U == (IData)(vlSelfRef.top__DOT__ALUControlE))) 
          | (6U == (IData)(vlSelfRef.top__DOT__ALUControlE))) 
         | (7U == (IData)(vlSelfRef.top__DOT__ALUControlE)))) {
        vlSelfRef.top__DOT__aluResult = ((0U == (IData)(vlSelfRef.top__DOT__ALUControlE))
                                          ? (vlSelfRef.top__DOT__SrcAE 
                                             + vlSelfRef.top__DOT__srcB)
                                          : ((1U == (IData)(vlSelfRef.top__DOT__ALUControlE))
                                              ? (vlSelfRef.top__DOT__SrcAE 
                                                 - vlSelfRef.top__DOT__srcB)
                                              : ((2U 
                                                  == (IData)(vlSelfRef.top__DOT__ALUControlE))
                                                  ? 
                                                 (vlSelfRef.top__DOT__SrcAE 
                                                  & vlSelfRef.top__DOT__srcB)
                                                  : 
                                                 ((3U 
                                                   == (IData)(vlSelfRef.top__DOT__ALUControlE))
                                                   ? 
                                                  (vlSelfRef.top__DOT__SrcAE 
                                                   | vlSelfRef.top__DOT__srcB)
                                                   : 
                                                  ((4U 
                                                    == (IData)(vlSelfRef.top__DOT__ALUControlE))
                                                    ? vlSelfRef.top__DOT__srcB
                                                    : 
                                                   ((5U 
                                                     == (IData)(vlSelfRef.top__DOT__ALUControlE))
                                                     ? 
                                                    (VL_LTS_III(32, vlSelfRef.top__DOT__SrcAE, vlSelfRef.top__DOT__srcB)
                                                      ? 1U
                                                      : 0U)
                                                     : 
                                                    ((6U 
                                                      == (IData)(vlSelfRef.top__DOT__ALUControlE))
                                                      ? 
                                                     (vlSelfRef.top__DOT__SrcAE 
                                                      << 
                                                      (0x1fU 
                                                       & vlSelfRef.top__DOT__srcB))
                                                      : 
                                                     (vlSelfRef.top__DOT__SrcAE 
                                                      >> 
                                                      (0x1fU 
                                                       & vlSelfRef.top__DOT__srcB)))))))));
    }
    vlSelfRef.top__DOT__zero = ((1U & ((IData)(vlSelfRef.top__DOT__ALUControlE) 
                                       >> 3U)) && (
                                                   (4U 
                                                    & (IData)(vlSelfRef.top__DOT__ALUControlE))
                                                    ? 
                                                   ((2U 
                                                     & (IData)(vlSelfRef.top__DOT__ALUControlE))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlSelfRef.top__DOT__ALUControlE))
                                                      ? 
                                                     (vlSelfRef.top__DOT__SrcAE 
                                                      >= vlSelfRef.top__DOT__srcB)
                                                      : 
                                                     (vlSelfRef.top__DOT__SrcAE 
                                                      < vlSelfRef.top__DOT__srcB))
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlSelfRef.top__DOT__ALUControlE))
                                                      ? 
                                                     VL_GTES_III(32, vlSelfRef.top__DOT__SrcAE, vlSelfRef.top__DOT__srcB)
                                                      : 
                                                     VL_LTS_III(32, vlSelfRef.top__DOT__SrcAE, vlSelfRef.top__DOT__srcB)))
                                                    : 
                                                   ((1U 
                                                     & (~ 
                                                        ((IData)(vlSelfRef.top__DOT__ALUControlE) 
                                                         >> 1U))) 
                                                    && ((1U 
                                                         & (IData)(vlSelfRef.top__DOT__ALUControlE))
                                                         ? 
                                                        (0U 
                                                         != 
                                                         (vlSelfRef.top__DOT__SrcAE 
                                                          - vlSelfRef.top__DOT__srcB))
                                                         : 
                                                        (0U 
                                                         == 
                                                         (vlSelfRef.top__DOT__SrcAE 
                                                          - vlSelfRef.top__DOT__srcB))))));
    vlSelfRef.top__DOT__nextPC = (((IData)(vlSelfRef.top__DOT__JumpE) 
                                   | ((IData)(vlSelfRef.top__DOT__BranchE) 
                                      & (IData)(vlSelfRef.top__DOT__zero)))
                                   ? (((IData)(vlSelfRef.top__DOT__JalrE)
                                        ? vlSelfRef.top__DOT__rd1E
                                        : vlSelfRef.top__DOT__PCe) 
                                      + vlSelfRef.top__DOT__ImmExtE)
                                   : ((IData)(4U) + vlSelfRef.top__DOT__pc));
}

VL_INLINE_OPT void Vdut___024root___nba_comb__TOP__0(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___nba_comb__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__MemoryController__DOT__main_mem_data 
        = ((4U & (IData)(vlSelfRef.top__DOT__sizeSrcM))
            ? ((2U & (IData)(vlSelfRef.top__DOT__sizeSrcM))
                ? 0U : ((1U & (IData)(vlSelfRef.top__DOT__sizeSrcM))
                         ? ((vlSelfRef.top__DOT__MemoryController__DOT__main_memory
                             [(0x1ffffU & ((IData)(1U) 
                                           + vlSelfRef.top__DOT__ALUResultM))] 
                             << 8U) | vlSelfRef.top__DOT__MemoryController__DOT__main_memory
                            [(0x1ffffU & vlSelfRef.top__DOT__ALUResultM)])
                         : vlSelfRef.top__DOT__MemoryController__DOT__main_memory
                        [(0x1ffffU & vlSelfRef.top__DOT__ALUResultM)]))
            : ((2U & (IData)(vlSelfRef.top__DOT__sizeSrcM))
                ? ((1U & (IData)(vlSelfRef.top__DOT__sizeSrcM))
                    ? 0U : ((vlSelfRef.top__DOT__MemoryController__DOT__main_memory
                             [(0x1ffffU & ((IData)(3U) 
                                           + vlSelfRef.top__DOT__ALUResultM))] 
                             << 0x18U) | ((vlSelfRef.top__DOT__MemoryController__DOT__main_memory
                                           [(0x1ffffU 
                                             & ((IData)(2U) 
                                                + vlSelfRef.top__DOT__ALUResultM))] 
                                           << 0x10U) 
                                          | ((vlSelfRef.top__DOT__MemoryController__DOT__main_memory
                                              [(0x1ffffU 
                                                & ((IData)(1U) 
                                                   + vlSelfRef.top__DOT__ALUResultM))] 
                                              << 8U) 
                                             | vlSelfRef.top__DOT__MemoryController__DOT__main_memory
                                             [(0x1ffffU 
                                               & vlSelfRef.top__DOT__ALUResultM)]))))
                : ((1U & (IData)(vlSelfRef.top__DOT__sizeSrcM))
                    ? (((- (IData)((1U & (vlSelfRef.top__DOT__MemoryController__DOT__main_memory
                                          [(0x1ffffU 
                                            & ((IData)(1U) 
                                               + vlSelfRef.top__DOT__ALUResultM))] 
                                          >> 7U)))) 
                        << 0x10U) | ((vlSelfRef.top__DOT__MemoryController__DOT__main_memory
                                      [(0x1ffffU & 
                                        ((IData)(1U) 
                                         + vlSelfRef.top__DOT__ALUResultM))] 
                                      << 8U) | vlSelfRef.top__DOT__MemoryController__DOT__main_memory
                                     [(0x1ffffU & vlSelfRef.top__DOT__ALUResultM)]))
                    : (((- (IData)((1U & (vlSelfRef.top__DOT__MemoryController__DOT__main_memory
                                          [(0x1ffffU 
                                            & vlSelfRef.top__DOT__ALUResultM)] 
                                          >> 7U)))) 
                        << 8U) | vlSelfRef.top__DOT__MemoryController__DOT__main_memory
                       [(0x1ffffU & vlSelfRef.top__DOT__ALUResultM)]))));
    vlSelfRef.top__DOT__MemReady = ((IData)(vlSelfRef.top__DOT__MemoryController__DOT__l1_hit) 
                                    || ((IData)(vlSelfRef.top__DOT__MemoryController__DOT__l2_hit) 
                                        || ((IData)(vlSelfRef.top__DOT__MemoryController__DOT__l3_hit) 
                                            || ((((IData)(vlSelfRef.top__DOT__MemoryController__DOT__main_mem_ready_reg) 
                                                  & (~ (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l1_busy))) 
                                                 & (~ (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l2_busy))) 
                                                & (~ (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l3_busy))))));
    vlSelfRef.top__DOT__ReadData = ((IData)(vlSelfRef.top__DOT__MemoryController__DOT__l1_hit)
                                     ? vlSelfRef.top__DOT__MemoryController__DOT__l1_data_out
                                     : ((IData)(vlSelfRef.top__DOT__MemoryController__DOT__l2_hit)
                                         ? vlSelfRef.top__DOT__MemoryController__DOT__l2_data_out
                                         : ((IData)(vlSelfRef.top__DOT__MemoryController__DOT__l3_hit)
                                             ? vlSelfRef.top__DOT__MemoryController__DOT__l3_data_out
                                             : vlSelfRef.top__DOT__MemoryController__DOT__main_mem_data)));
    vlSelfRef.top__DOT__stall = 0U;
    vlSelfRef.top__DOT__FlushD = 0U;
    vlSelfRef.top__DOT__FlushE = 0U;
    vlSelfRef.top__DOT__HazardUnit__DOT__load_use_hazard 
        = ((1U == (IData)(vlSelfRef.top__DOT__ResultSrcE)) 
           & ((((IData)(vlSelfRef.top__DOT__RdE) == 
                (0x1fU & (vlSelfRef.top__DOT__instrD 
                          >> 0xfU))) & (0U != (0x1fU 
                                               & (vlSelfRef.top__DOT__instrD 
                                                  >> 0xfU)))) 
              | (((IData)(vlSelfRef.top__DOT__RdE) 
                  == (0x1fU & (vlSelfRef.top__DOT__instrD 
                               >> 0x14U))) & (0U != 
                                              (0x1fU 
                                               & (vlSelfRef.top__DOT__instrD 
                                                  >> 0x14U))))));
    vlSelfRef.top__DOT__HazardUnit__DOT__control_hazard 
        = ((IData)(vlSelfRef.top__DOT__zero) | (IData)(vlSelfRef.top__DOT__JumpE));
    if (vlSelfRef.top__DOT__HazardUnit__DOT__load_use_hazard) {
        vlSelfRef.top__DOT__stall = 1U;
        vlSelfRef.top__DOT__FlushE = 1U;
        vlSelfRef.top__DOT__FlushD = 0U;
    } else if (vlSelfRef.top__DOT__HazardUnit__DOT__control_hazard) {
        vlSelfRef.top__DOT__stall = 0U;
        vlSelfRef.top__DOT__FlushD = 1U;
        vlSelfRef.top__DOT__FlushE = 1U;
    } else if (vlSelfRef.top__DOT__MemReady) {
        vlSelfRef.top__DOT__stall = 0U;
        vlSelfRef.top__DOT__FlushD = 0U;
        vlSelfRef.top__DOT__FlushE = 0U;
    } else {
        vlSelfRef.top__DOT__stall = 1U;
        vlSelfRef.top__DOT__FlushE = 1U;
        vlSelfRef.top__DOT__FlushD = 0U;
    }
}

void Vdut___024root___eval_triggers__act(Vdut___024root* vlSelf);

bool Vdut___024root___eval_phase__act(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_phase__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vdut___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vdut___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vdut___024root___eval_phase__nba(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_phase__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vdut___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdut___024root___dump_triggers__nba(Vdut___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vdut___024root___dump_triggers__act(Vdut___024root* vlSelf);
#endif  // VL_DEBUG

void Vdut___024root___eval(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vdut___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/Users/michaelli/Documents/GitHub/iac-riscv-cw-24/rtl/top.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vdut___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/Users/michaelli/Documents/GitHub/iac-riscv-cw-24/rtl/top.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vdut___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vdut___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vdut___024root___eval_debug_assertions(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_debug_assertions\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelfRef.rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
