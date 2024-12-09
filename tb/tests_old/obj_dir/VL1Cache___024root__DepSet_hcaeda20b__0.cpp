// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VL1Cache.h for the primary calling header

#include "VL1Cache__pch.h"
#include "VL1Cache___024root.h"

void VL1Cache___024root___ico_sequent__TOP__0(VL1Cache___024root* vlSelf);

void VL1Cache___024root___eval_ico(VL1Cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VL1Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL1Cache___024root___eval_ico\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL1Cache___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void VL1Cache___024root___ico_sequent__TOP__0(VL1Cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VL1Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL1Cache___024root___ico_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.L1Cache__DOT__way = (1U & (vlSelfRef.L1Cache__DOT__lru 
                                         >> (0x1fU 
                                             & (vlSelfRef.address 
                                                >> 2U))));
    if ((1U & (IData)((vlSelfRef.L1Cache__DOT__cache
                       [(0x1fU & (vlSelfRef.address 
                                  >> 2U))][0U] >> 0x3aU)))) {
        if ((1U & (~ (IData)((vlSelfRef.L1Cache__DOT__cache
                              [(0x1fU & (vlSelfRef.address 
                                         >> 2U))][1U] 
                              >> 0x3aU))))) {
            vlSelfRef.L1Cache__DOT__way = 1U;
        }
    } else {
        vlSelfRef.L1Cache__DOT__way = 0U;
    }
    vlSelfRef.mem_write_data = (IData)(vlSelfRef.L1Cache__DOT__cache
                                       [(0x1fU & (vlSelfRef.address 
                                                  >> 2U))]
                                       [vlSelfRef.L1Cache__DOT__way]);
    vlSelfRef.hit = 0U;
    vlSelfRef.L1Cache__DOT__hit_way = 0U;
    if (((IData)((vlSelfRef.L1Cache__DOT__cache[(0x1fU 
                                                 & (vlSelfRef.address 
                                                    >> 2U))]
                  [0U] >> 0x3aU)) & ((0x1ffffffU & (IData)(
                                                           (vlSelfRef.L1Cache__DOT__cache
                                                            [
                                                            (0x1fU 
                                                             & (vlSelfRef.address 
                                                                >> 2U))]
                                                            [0U] 
                                                            >> 0x20U))) 
                                     == (vlSelfRef.address 
                                         >> 7U)))) {
        vlSelfRef.hit = 1U;
        vlSelfRef.L1Cache__DOT__hit_way = 0U;
    } else if (((IData)((vlSelfRef.L1Cache__DOT__cache
                         [(0x1fU & (vlSelfRef.address 
                                    >> 2U))][1U] >> 0x3aU)) 
                & ((0x1ffffffU & (IData)((vlSelfRef.L1Cache__DOT__cache
                                          [(0x1fU & 
                                            (vlSelfRef.address 
                                             >> 2U))]
                                          [1U] >> 0x20U))) 
                   == (vlSelfRef.address >> 7U)))) {
        vlSelfRef.hit = 1U;
        vlSelfRef.L1Cache__DOT__hit_way = 1U;
    }
    vlSelfRef.miss = ((~ (IData)(vlSelfRef.hit)) & 
                      ((IData)(vlSelfRef.load) | (IData)(vlSelfRef.store)));
    vlSelfRef.data_out = ((IData)(vlSelfRef.hit) ? (IData)(
                                                           vlSelfRef.L1Cache__DOT__cache
                                                           [
                                                           (0x1fU 
                                                            & (vlSelfRef.address 
                                                               >> 2U))]
                                                           [vlSelfRef.L1Cache__DOT__hit_way])
                           : vlSelfRef.mem_data);
}

void VL1Cache___024root___eval_triggers__ico(VL1Cache___024root* vlSelf);

bool VL1Cache___024root___eval_phase__ico(VL1Cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VL1Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL1Cache___024root___eval_phase__ico\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    VL1Cache___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        VL1Cache___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void VL1Cache___024root___eval_act(VL1Cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VL1Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL1Cache___024root___eval_act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

void VL1Cache___024root___nba_sequent__TOP__0(VL1Cache___024root* vlSelf);

void VL1Cache___024root___eval_nba(VL1Cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VL1Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL1Cache___024root___eval_nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL1Cache___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

VL_INLINE_OPT void VL1Cache___024root___nba_sequent__TOP__0(VL1Cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VL1Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL1Cache___024root___nba_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*4:0*/ __VdlyDim0__L1Cache__DOT__cache__v0;
    __VdlyDim0__L1Cache__DOT__cache__v0 = 0;
    CData/*0:0*/ __VdlyDim1__L1Cache__DOT__cache__v0;
    __VdlyDim1__L1Cache__DOT__cache__v0 = 0;
    CData/*2:0*/ __Vdly__L1Cache__DOT__state;
    __Vdly__L1Cache__DOT__state = 0;
    CData/*0:0*/ __VdlyVal__L1Cache__DOT__cache__v1;
    __VdlyVal__L1Cache__DOT__cache__v1 = 0;
    CData/*4:0*/ __VdlyDim0__L1Cache__DOT__cache__v1;
    __VdlyDim0__L1Cache__DOT__cache__v1 = 0;
    CData/*0:0*/ __VdlyDim1__L1Cache__DOT__cache__v1;
    __VdlyDim1__L1Cache__DOT__cache__v1 = 0;
    IData/*24:0*/ __VdlyVal__L1Cache__DOT__cache__v2;
    __VdlyVal__L1Cache__DOT__cache__v2 = 0;
    CData/*4:0*/ __VdlyDim0__L1Cache__DOT__cache__v2;
    __VdlyDim0__L1Cache__DOT__cache__v2 = 0;
    CData/*0:0*/ __VdlyDim1__L1Cache__DOT__cache__v2;
    __VdlyDim1__L1Cache__DOT__cache__v2 = 0;
    IData/*31:0*/ __VdlyVal__L1Cache__DOT__cache__v3;
    __VdlyVal__L1Cache__DOT__cache__v3 = 0;
    CData/*4:0*/ __VdlyDim0__L1Cache__DOT__cache__v3;
    __VdlyDim0__L1Cache__DOT__cache__v3 = 0;
    CData/*0:0*/ __VdlyDim1__L1Cache__DOT__cache__v3;
    __VdlyDim1__L1Cache__DOT__cache__v3 = 0;
    IData/*31:0*/ __VdlyVal__L1Cache__DOT__cache__v4;
    __VdlyVal__L1Cache__DOT__cache__v4 = 0;
    CData/*4:0*/ __VdlyDim0__L1Cache__DOT__cache__v4;
    __VdlyDim0__L1Cache__DOT__cache__v4 = 0;
    CData/*0:0*/ __VdlyDim1__L1Cache__DOT__cache__v4;
    __VdlyDim1__L1Cache__DOT__cache__v4 = 0;
    CData/*4:0*/ __VdlyDim0__L1Cache__DOT__cache__v5;
    __VdlyDim0__L1Cache__DOT__cache__v5 = 0;
    CData/*0:0*/ __VdlyDim1__L1Cache__DOT__cache__v5;
    __VdlyDim1__L1Cache__DOT__cache__v5 = 0;
    CData/*0:0*/ __VdlySet__L1Cache__DOT__cache__v0;
    __VdlySet__L1Cache__DOT__cache__v0 = 0;
    CData/*0:0*/ __VdlySet__L1Cache__DOT__cache__v1;
    __VdlySet__L1Cache__DOT__cache__v1 = 0;
    CData/*0:0*/ __VdlySet__L1Cache__DOT__cache__v4;
    __VdlySet__L1Cache__DOT__cache__v4 = 0;
    CData/*0:0*/ __VdlySet__L1Cache__DOT__cache__v5;
    __VdlySet__L1Cache__DOT__cache__v5 = 0;
    CData/*0:0*/ __VdlySet__L1Cache__DOT__cache__v6;
    __VdlySet__L1Cache__DOT__cache__v6 = 0;
    // Body
    __Vdly__L1Cache__DOT__state = vlSelfRef.L1Cache__DOT__state;
    __VdlySet__L1Cache__DOT__cache__v0 = 0U;
    __VdlySet__L1Cache__DOT__cache__v1 = 0U;
    __VdlySet__L1Cache__DOT__cache__v4 = 0U;
    __VdlySet__L1Cache__DOT__cache__v5 = 0U;
    __VdlySet__L1Cache__DOT__cache__v6 = 0U;
    if ((1U & (~ (IData)(vlSelfRef.rst_n)))) {
        vlSelfRef.L1Cache__DOT__unnamedblk1__DOT__i = 0x20U;
    }
    if (vlSelfRef.rst_n) {
        if ((4U & (IData)(vlSelfRef.L1Cache__DOT__state))) {
            if ((1U & (~ ((IData)(vlSelfRef.L1Cache__DOT__state) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlSelfRef.L1Cache__DOT__state)))) {
                    vlSelfRef.busy = 0U;
                    __VdlyDim0__L1Cache__DOT__cache__v0 
                        = (0x1fU & (vlSelfRef.address 
                                    >> 2U));
                    __VdlyDim1__L1Cache__DOT__cache__v0 
                        = vlSelfRef.L1Cache__DOT__way;
                    __VdlySet__L1Cache__DOT__cache__v0 = 1U;
                    vlSelfRef.L1Cache__DOT__lru = (
                                                   ((~ 
                                                     ((IData)(1U) 
                                                      << 
                                                      (0x1fU 
                                                       & (vlSelfRef.address 
                                                          >> 2U)))) 
                                                    & vlSelfRef.L1Cache__DOT__lru) 
                                                   | (0xffffffffULL 
                                                      & ((1U 
                                                          & (~ (IData)(vlSelfRef.L1Cache__DOT__way))) 
                                                         << 
                                                         (0x1fU 
                                                          & (vlSelfRef.address 
                                                             >> 2U)))));
                    __Vdly__L1Cache__DOT__state = 0U;
                    __VdlyVal__L1Cache__DOT__cache__v1 
                        = vlSelfRef.store;
                    __VdlyDim0__L1Cache__DOT__cache__v1 
                        = (0x1fU & (vlSelfRef.address 
                                    >> 2U));
                    __VdlyDim1__L1Cache__DOT__cache__v1 
                        = vlSelfRef.L1Cache__DOT__way;
                    __VdlySet__L1Cache__DOT__cache__v1 = 1U;
                    __VdlyVal__L1Cache__DOT__cache__v2 
                        = (vlSelfRef.address >> 7U);
                    __VdlyDim0__L1Cache__DOT__cache__v2 
                        = (0x1fU & (vlSelfRef.address 
                                    >> 2U));
                    __VdlyDim1__L1Cache__DOT__cache__v2 
                        = vlSelfRef.L1Cache__DOT__way;
                    __VdlyVal__L1Cache__DOT__cache__v3 
                        = ((IData)(vlSelfRef.store)
                            ? vlSelfRef.data_in : vlSelfRef.mem_data);
                    __VdlyDim0__L1Cache__DOT__cache__v3 
                        = (0x1fU & (vlSelfRef.address 
                                    >> 2U));
                    __VdlyDim1__L1Cache__DOT__cache__v3 
                        = vlSelfRef.L1Cache__DOT__way;
                }
            }
        } else if ((2U & (IData)(vlSelfRef.L1Cache__DOT__state))) {
            if ((1U & (IData)(vlSelfRef.L1Cache__DOT__state))) {
                if (vlSelfRef.mem_ready) {
                    vlSelfRef.mem_write = 0U;
                    if (vlSelfRef.load) {
                        vlSelfRef.mem_read = 1U;
                        __Vdly__L1Cache__DOT__state = 1U;
                    } else {
                        vlSelfRef.mem_read = 0U;
                        __Vdly__L1Cache__DOT__state = 2U;
                    }
                }
            } else {
                __Vdly__L1Cache__DOT__state = 4U;
            }
        } else if ((1U & (IData)(vlSelfRef.L1Cache__DOT__state))) {
            if (vlSelfRef.mem_ready) {
                vlSelfRef.mem_read = 0U;
                __Vdly__L1Cache__DOT__state = 4U;
            }
        } else if (vlSelfRef.miss) {
            vlSelfRef.busy = 1U;
            if ((1U & ((IData)((vlSelfRef.L1Cache__DOT__cache
                                [(0x1fU & (vlSelfRef.address 
                                           >> 2U))]
                                [vlSelfRef.L1Cache__DOT__way] 
                                >> 0x3aU)) & (IData)(
                                                     (vlSelfRef.L1Cache__DOT__cache
                                                      [
                                                      (0x1fU 
                                                       & (vlSelfRef.address 
                                                          >> 2U))]
                                                      [vlSelfRef.L1Cache__DOT__way] 
                                                      >> 0x39U))))) {
                vlSelfRef.mem_write = 1U;
                __Vdly__L1Cache__DOT__state = 3U;
            } else if (vlSelfRef.load) {
                vlSelfRef.mem_read = 1U;
                __Vdly__L1Cache__DOT__state = 1U;
            } else {
                __Vdly__L1Cache__DOT__state = 2U;
            }
        } else {
            vlSelfRef.busy = 0U;
            vlSelfRef.mem_write = 0U;
            vlSelfRef.mem_read = 0U;
            if (((IData)(vlSelfRef.hit) & (IData)(vlSelfRef.store))) {
                __VdlyVal__L1Cache__DOT__cache__v4 
                    = vlSelfRef.data_in;
                __VdlyDim0__L1Cache__DOT__cache__v4 
                    = (0x1fU & (vlSelfRef.address >> 2U));
                __VdlyDim1__L1Cache__DOT__cache__v4 
                    = vlSelfRef.L1Cache__DOT__hit_way;
                __VdlySet__L1Cache__DOT__cache__v4 = 1U;
                vlSelfRef.L1Cache__DOT__lru = (((~ 
                                                 ((IData)(1U) 
                                                  << 
                                                  (0x1fU 
                                                   & (vlSelfRef.address 
                                                      >> 2U)))) 
                                                & vlSelfRef.L1Cache__DOT__lru) 
                                               | (0xffffffffULL 
                                                  & ((1U 
                                                      & (~ (IData)(vlSelfRef.L1Cache__DOT__hit_way))) 
                                                     << 
                                                     (0x1fU 
                                                      & (vlSelfRef.address 
                                                         >> 2U)))));
                __VdlyDim0__L1Cache__DOT__cache__v5 
                    = (0x1fU & (vlSelfRef.address >> 2U));
                __VdlyDim1__L1Cache__DOT__cache__v5 
                    = vlSelfRef.L1Cache__DOT__hit_way;
                __VdlySet__L1Cache__DOT__cache__v5 = 1U;
            }
        }
    } else {
        __Vdly__L1Cache__DOT__state = 0U;
        vlSelfRef.busy = 0U;
        vlSelfRef.mem_read = 0U;
        vlSelfRef.mem_write = 0U;
        vlSelfRef.L1Cache__DOT__lru = 0U;
        __VdlySet__L1Cache__DOT__cache__v6 = 1U;
    }
    vlSelfRef.L1Cache__DOT__state = __Vdly__L1Cache__DOT__state;
    if (__VdlySet__L1Cache__DOT__cache__v0) {
        vlSelfRef.L1Cache__DOT__cache[__VdlyDim0__L1Cache__DOT__cache__v0][__VdlyDim1__L1Cache__DOT__cache__v0] 
            = (0x400000000000000ULL | vlSelfRef.L1Cache__DOT__cache
               [__VdlyDim0__L1Cache__DOT__cache__v0]
               [__VdlyDim1__L1Cache__DOT__cache__v0]);
    }
    if (__VdlySet__L1Cache__DOT__cache__v1) {
        vlSelfRef.L1Cache__DOT__cache[__VdlyDim0__L1Cache__DOT__cache__v1][__VdlyDim1__L1Cache__DOT__cache__v1] 
            = ((0x5ffffffffffffffULL & vlSelfRef.L1Cache__DOT__cache
                [__VdlyDim0__L1Cache__DOT__cache__v1]
                [__VdlyDim1__L1Cache__DOT__cache__v1]) 
               | ((QData)((IData)(__VdlyVal__L1Cache__DOT__cache__v1)) 
                  << 0x39U));
        vlSelfRef.L1Cache__DOT__cache[__VdlyDim0__L1Cache__DOT__cache__v2][__VdlyDim1__L1Cache__DOT__cache__v2] 
            = ((0x6000000ffffffffULL & vlSelfRef.L1Cache__DOT__cache
                [__VdlyDim0__L1Cache__DOT__cache__v2]
                [__VdlyDim1__L1Cache__DOT__cache__v2]) 
               | ((QData)((IData)(__VdlyVal__L1Cache__DOT__cache__v2)) 
                  << 0x20U));
        vlSelfRef.L1Cache__DOT__cache[__VdlyDim0__L1Cache__DOT__cache__v3][__VdlyDim1__L1Cache__DOT__cache__v3] 
            = ((0x7ffffff00000000ULL & vlSelfRef.L1Cache__DOT__cache
                [__VdlyDim0__L1Cache__DOT__cache__v3]
                [__VdlyDim1__L1Cache__DOT__cache__v3]) 
               | (IData)((IData)(__VdlyVal__L1Cache__DOT__cache__v3)));
    }
    if (__VdlySet__L1Cache__DOT__cache__v4) {
        vlSelfRef.L1Cache__DOT__cache[__VdlyDim0__L1Cache__DOT__cache__v4][__VdlyDim1__L1Cache__DOT__cache__v4] 
            = ((0x7ffffff00000000ULL & vlSelfRef.L1Cache__DOT__cache
                [__VdlyDim0__L1Cache__DOT__cache__v4]
                [__VdlyDim1__L1Cache__DOT__cache__v4]) 
               | (IData)((IData)(__VdlyVal__L1Cache__DOT__cache__v4)));
    }
    if (__VdlySet__L1Cache__DOT__cache__v5) {
        vlSelfRef.L1Cache__DOT__cache[__VdlyDim0__L1Cache__DOT__cache__v5][__VdlyDim1__L1Cache__DOT__cache__v5] 
            = (0x200000000000000ULL | vlSelfRef.L1Cache__DOT__cache
               [__VdlyDim0__L1Cache__DOT__cache__v5]
               [__VdlyDim1__L1Cache__DOT__cache__v5]);
    }
    if (__VdlySet__L1Cache__DOT__cache__v6) {
        vlSelfRef.L1Cache__DOT__cache[0U][0U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0U][1U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[1U][0U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[1U][1U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[2U][0U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[2U][1U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[3U][0U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[3U][1U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[4U][0U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[4U][1U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[5U][0U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[5U][1U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[6U][0U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[6U][1U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[7U][0U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[7U][1U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[8U][0U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[8U][1U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[9U][0U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[9U][1U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0xaU][0U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0xaU][1U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0xbU][0U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0xbU][1U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0xcU][0U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0xcU][1U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0xdU][0U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0xdU][1U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0xeU][0U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0xeU][1U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0xfU][0U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0xfU][1U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0x10U][0U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0x10U][1U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0x11U][0U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0x11U][1U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0x12U][0U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0x12U][1U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0x13U][0U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0x13U][1U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0x14U][0U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0x14U][1U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0x15U][0U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0x15U][1U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0x16U][0U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0x16U][1U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0x17U][0U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0x17U][1U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0x18U][0U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0x18U][1U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0x19U][0U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0x19U][1U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0x1aU][0U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0x1aU][1U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0x1bU][0U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0x1bU][1U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0x1cU][0U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0x1cU][1U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0x1dU][0U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0x1dU][1U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0x1eU][0U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0x1eU][1U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0x1fU][0U] = 0ULL;
        vlSelfRef.L1Cache__DOT__cache[0x1fU][1U] = 0ULL;
    }
    vlSelfRef.L1Cache__DOT__way = (1U & (vlSelfRef.L1Cache__DOT__lru 
                                         >> (0x1fU 
                                             & (vlSelfRef.address 
                                                >> 2U))));
    if ((1U & (IData)((vlSelfRef.L1Cache__DOT__cache
                       [(0x1fU & (vlSelfRef.address 
                                  >> 2U))][0U] >> 0x3aU)))) {
        if ((1U & (~ (IData)((vlSelfRef.L1Cache__DOT__cache
                              [(0x1fU & (vlSelfRef.address 
                                         >> 2U))][1U] 
                              >> 0x3aU))))) {
            vlSelfRef.L1Cache__DOT__way = 1U;
        }
    } else {
        vlSelfRef.L1Cache__DOT__way = 0U;
    }
    vlSelfRef.mem_write_data = (IData)(vlSelfRef.L1Cache__DOT__cache
                                       [(0x1fU & (vlSelfRef.address 
                                                  >> 2U))]
                                       [vlSelfRef.L1Cache__DOT__way]);
    vlSelfRef.hit = 0U;
    vlSelfRef.L1Cache__DOT__hit_way = 0U;
    if (((IData)((vlSelfRef.L1Cache__DOT__cache[(0x1fU 
                                                 & (vlSelfRef.address 
                                                    >> 2U))]
                  [0U] >> 0x3aU)) & ((0x1ffffffU & (IData)(
                                                           (vlSelfRef.L1Cache__DOT__cache
                                                            [
                                                            (0x1fU 
                                                             & (vlSelfRef.address 
                                                                >> 2U))]
                                                            [0U] 
                                                            >> 0x20U))) 
                                     == (vlSelfRef.address 
                                         >> 7U)))) {
        vlSelfRef.hit = 1U;
        vlSelfRef.L1Cache__DOT__hit_way = 0U;
    } else if (((IData)((vlSelfRef.L1Cache__DOT__cache
                         [(0x1fU & (vlSelfRef.address 
                                    >> 2U))][1U] >> 0x3aU)) 
                & ((0x1ffffffU & (IData)((vlSelfRef.L1Cache__DOT__cache
                                          [(0x1fU & 
                                            (vlSelfRef.address 
                                             >> 2U))]
                                          [1U] >> 0x20U))) 
                   == (vlSelfRef.address >> 7U)))) {
        vlSelfRef.hit = 1U;
        vlSelfRef.L1Cache__DOT__hit_way = 1U;
    }
    vlSelfRef.miss = ((~ (IData)(vlSelfRef.hit)) & 
                      ((IData)(vlSelfRef.load) | (IData)(vlSelfRef.store)));
    vlSelfRef.data_out = ((IData)(vlSelfRef.hit) ? (IData)(
                                                           vlSelfRef.L1Cache__DOT__cache
                                                           [
                                                           (0x1fU 
                                                            & (vlSelfRef.address 
                                                               >> 2U))]
                                                           [vlSelfRef.L1Cache__DOT__hit_way])
                           : vlSelfRef.mem_data);
}

void VL1Cache___024root___eval_triggers__act(VL1Cache___024root* vlSelf);

bool VL1Cache___024root___eval_phase__act(VL1Cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VL1Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL1Cache___024root___eval_phase__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VL1Cache___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        VL1Cache___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VL1Cache___024root___eval_phase__nba(VL1Cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VL1Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL1Cache___024root___eval_phase__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        VL1Cache___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VL1Cache___024root___dump_triggers__ico(VL1Cache___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VL1Cache___024root___dump_triggers__nba(VL1Cache___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VL1Cache___024root___dump_triggers__act(VL1Cache___024root* vlSelf);
#endif  // VL_DEBUG

void VL1Cache___024root___eval(VL1Cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VL1Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL1Cache___024root___eval\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            VL1Cache___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("../../rtl/L1Cache.sv", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (VL1Cache___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            VL1Cache___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../../rtl/L1Cache.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                VL1Cache___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../../rtl/L1Cache.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (VL1Cache___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (VL1Cache___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VL1Cache___024root___eval_debug_assertions(VL1Cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VL1Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL1Cache___024root___eval_debug_assertions\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelfRef.rst_n & 0xfeU))) {
        Verilated::overWidthError("rst_n");}
    if (VL_UNLIKELY((vlSelfRef.load & 0xfeU))) {
        Verilated::overWidthError("load");}
    if (VL_UNLIKELY((vlSelfRef.store & 0xfeU))) {
        Verilated::overWidthError("store");}
    if (VL_UNLIKELY((vlSelfRef.mem_ready & 0xfeU))) {
        Verilated::overWidthError("mem_ready");}
}
#endif  // VL_DEBUG
