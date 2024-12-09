// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VL1Cache.h for the primary calling header

#include "VL1Cache__pch.h"
#include "VL1Cache___024root.h"

VL_ATTR_COLD void VL1Cache___024root___eval_static(VL1Cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VL1Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL1Cache___024root___eval_static\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VL1Cache___024root___eval_initial(VL1Cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VL1Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL1Cache___024root___eval_initial\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__reset__0 = vlSelfRef.reset;
}

VL_ATTR_COLD void VL1Cache___024root___eval_final(VL1Cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VL1Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL1Cache___024root___eval_final\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VL1Cache___024root___eval_settle(VL1Cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VL1Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL1Cache___024root___eval_settle\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VL1Cache___024root___dump_triggers__act(VL1Cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VL1Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL1Cache___024root___dump_triggers__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk or posedge reset)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VL1Cache___024root___dump_triggers__nba(VL1Cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VL1Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL1Cache___024root___dump_triggers__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk or posedge reset)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VL1Cache___024root___ctor_var_reset(VL1Cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VL1Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL1Cache___024root___ctor_var_reset\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->address = VL_RAND_RESET_I(32);
    vlSelf->writeData = VL_RAND_RESET_I(32);
    vlSelf->writeEnable = VL_RAND_RESET_I(1);
    vlSelf->readData = VL_RAND_RESET_I(32);
    vlSelf->hit = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->L1Cache__DOT__cache[__Vi0].__PVT__tag = VL_RAND_RESET_I(20);
        VL_RAND_RESET_W(128, vlSelf->L1Cache__DOT__cache[__Vi0].__PVT__data);
        vlSelf->L1Cache__DOT__cache[__Vi0].__PVT__valid = VL_RAND_RESET_I(1);
    }
    vlSelf->L1Cache__DOT__index = VL_RAND_RESET_I(8);
    vlSelf->L1Cache__DOT__offset = VL_RAND_RESET_I(2);
    vlSelf->L1Cache__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
