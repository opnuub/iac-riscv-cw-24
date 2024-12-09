// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPRegFetch.h for the primary calling header

#include "VPRegFetch__pch.h"
#include "VPRegFetch___024root.h"

VL_ATTR_COLD void VPRegFetch___024root___eval_static(VPRegFetch___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPRegFetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegFetch___024root___eval_static\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VPRegFetch___024root___eval_initial(VPRegFetch___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPRegFetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegFetch___024root___eval_initial\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst__0 = vlSelfRef.rst;
}

VL_ATTR_COLD void VPRegFetch___024root___eval_final(VPRegFetch___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPRegFetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegFetch___024root___eval_final\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VPRegFetch___024root___eval_settle(VPRegFetch___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPRegFetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegFetch___024root___eval_settle\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VPRegFetch___024root___dump_triggers__act(VPRegFetch___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPRegFetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegFetch___024root___dump_triggers__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk or posedge rst)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VPRegFetch___024root___dump_triggers__nba(VPRegFetch___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPRegFetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegFetch___024root___dump_triggers__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk or posedge rst)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VPRegFetch___024root___ctor_var_reset(VPRegFetch___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPRegFetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegFetch___024root___ctor_var_reset\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->instr = VL_RAND_RESET_I(32);
    vlSelf->PCf = VL_RAND_RESET_I(32);
    vlSelf->PCPlus4F = VL_RAND_RESET_I(32);
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->FlushF = VL_RAND_RESET_I(1);
    vlSelf->PCPlus4D = VL_RAND_RESET_I(32);
    vlSelf->PCd = VL_RAND_RESET_I(32);
    vlSelf->InstrD = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst__0 = VL_RAND_RESET_I(1);
}
