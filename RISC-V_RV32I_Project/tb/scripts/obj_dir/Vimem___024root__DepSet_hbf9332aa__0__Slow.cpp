// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vimem.h for the primary calling header

#include "Vimem__pch.h"
#include "Vimem___024root.h"

VL_ATTR_COLD void Vimem___024root___eval_static(Vimem___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vimem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vimem___024root___eval_static\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vimem___024root___eval_initial__TOP(Vimem___024root* vlSelf);

VL_ATTR_COLD void Vimem___024root___eval_initial(Vimem___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vimem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vimem___024root___eval_initial\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vimem___024root___eval_initial__TOP(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__clk_i__0 = vlSelfRef.clk_i;
}

extern const VlWide<22>/*703:0*/ Vimem__ConstPool__CONST_hbbe01394_0;

VL_ATTR_COLD void Vimem___024root___eval_initial__TOP(Vimem___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vimem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vimem___024root___eval_initial__TOP\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_WRITEF_NX("Loading program into instruction memory...\n",0);
    VL_READMEM_N(true, 8, 4096, 0, VL_CVT_PACK_STR_NW(22, Vimem__ConstPool__CONST_hbbe01394_0)
                 ,  &(vlSelfRef.imem__DOT__mem), 0, ~0ULL);
}

VL_ATTR_COLD void Vimem___024root___eval_final(Vimem___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vimem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vimem___024root___eval_final\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vimem___024root___eval_settle(Vimem___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vimem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vimem___024root___eval_settle\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vimem___024root___dump_triggers__act(Vimem___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vimem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vimem___024root___dump_triggers__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk_i)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vimem___024root___dump_triggers__nba(Vimem___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vimem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vimem___024root___dump_triggers__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk_i)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vimem___024root___ctor_var_reset(Vimem___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vimem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vimem___024root___ctor_var_reset\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk_i = VL_RAND_RESET_I(1);
    vlSelf->addr_i = VL_RAND_RESET_I(32);
    vlSelf->rdata_o = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->imem__DOT__mem[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->__Vtrigprevexpr___TOP__clk_i__0 = VL_RAND_RESET_I(1);
}
