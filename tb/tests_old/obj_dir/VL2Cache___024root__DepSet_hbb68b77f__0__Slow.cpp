// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VL2Cache.h for the primary calling header

#include "VL2Cache__pch.h"
#include "VL2Cache___024root.h"

VL_ATTR_COLD void VL2Cache___024root___eval_static(VL2Cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VL2Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL2Cache___024root___eval_static\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VL2Cache___024root___eval_initial(VL2Cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VL2Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL2Cache___024root___eval_initial\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.rst_n;
}

VL_ATTR_COLD void VL2Cache___024root___eval_final(VL2Cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VL2Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL2Cache___024root___eval_final\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VL2Cache___024root___dump_triggers__stl(VL2Cache___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VL2Cache___024root___eval_phase__stl(VL2Cache___024root* vlSelf);

VL_ATTR_COLD void VL2Cache___024root___eval_settle(VL2Cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VL2Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL2Cache___024root___eval_settle\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            VL2Cache___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("../../rtl/L2Cache.sv", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (VL2Cache___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VL2Cache___024root___dump_triggers__stl(VL2Cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VL2Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL2Cache___024root___dump_triggers__stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void VL2Cache___024root___ico_sequent__TOP__0(VL2Cache___024root* vlSelf);

VL_ATTR_COLD void VL2Cache___024root___eval_stl(VL2Cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VL2Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL2Cache___024root___eval_stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL2Cache___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void VL2Cache___024root___eval_triggers__stl(VL2Cache___024root* vlSelf);

VL_ATTR_COLD bool VL2Cache___024root___eval_phase__stl(VL2Cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VL2Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL2Cache___024root___eval_phase__stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    VL2Cache___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        VL2Cache___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VL2Cache___024root___dump_triggers__ico(VL2Cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VL2Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL2Cache___024root___dump_triggers__ico\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VL2Cache___024root___dump_triggers__act(VL2Cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VL2Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL2Cache___024root___dump_triggers__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk or negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VL2Cache___024root___dump_triggers__nba(VL2Cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VL2Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL2Cache___024root___dump_triggers__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk or negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VL2Cache___024root___ctor_var_reset(VL2Cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VL2Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL2Cache___024root___ctor_var_reset\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst_n = VL_RAND_RESET_I(1);
    vlSelf->load = VL_RAND_RESET_I(1);
    vlSelf->store = VL_RAND_RESET_I(1);
    vlSelf->address = VL_RAND_RESET_I(32);
    vlSelf->data_in = VL_RAND_RESET_I(32);
    vlSelf->mem_data = VL_RAND_RESET_I(32);
    vlSelf->mem_ready = VL_RAND_RESET_I(1);
    vlSelf->hit = VL_RAND_RESET_I(1);
    vlSelf->miss = VL_RAND_RESET_I(1);
    vlSelf->mem_write = VL_RAND_RESET_I(1);
    vlSelf->mem_read = VL_RAND_RESET_I(1);
    vlSelf->busy = VL_RAND_RESET_I(1);
    vlSelf->data_out = VL_RAND_RESET_I(32);
    vlSelf->mem_write_data = VL_RAND_RESET_I(32);
    vlSelf->L2Cache__DOT__state = VL_RAND_RESET_I(3);
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 2; ++__Vi1) {
            vlSelf->L2Cache__DOT__cache[__Vi0][__Vi1] = VL_RAND_RESET_Q(58);
        }
    }
    vlSelf->L2Cache__DOT__lru = VL_RAND_RESET_Q(64);
    vlSelf->L2Cache__DOT__way = VL_RAND_RESET_I(1);
    vlSelf->L2Cache__DOT__hit_way = VL_RAND_RESET_I(1);
    vlSelf->L2Cache__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
