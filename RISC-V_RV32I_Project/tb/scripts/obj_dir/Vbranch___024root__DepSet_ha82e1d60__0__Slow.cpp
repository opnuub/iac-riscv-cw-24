// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbranch.h for the primary calling header

#include "Vbranch__pch.h"
#include "Vbranch___024root.h"

VL_ATTR_COLD void Vbranch___024root___eval_static(Vbranch___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vbranch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch___024root___eval_static\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vbranch___024root___eval_initial(Vbranch___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vbranch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch___024root___eval_initial\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vbranch___024root___eval_final(Vbranch___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vbranch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch___024root___eval_final\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vbranch___024root___dump_triggers__stl(Vbranch___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vbranch___024root___eval_phase__stl(Vbranch___024root* vlSelf);

VL_ATTR_COLD void Vbranch___024root___eval_settle(Vbranch___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vbranch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch___024root___eval_settle\n"); );
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
            Vbranch___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("/Users/michaelli/Documents/GitHub/iac-riscv-cw-24/RISC-V_RV32I_Project/rtl/branch.sv", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vbranch___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vbranch___024root___dump_triggers__stl(Vbranch___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vbranch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch___024root___dump_triggers__stl\n"); );
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

void Vbranch___024root___ico_sequent__TOP__0(Vbranch___024root* vlSelf);

VL_ATTR_COLD void Vbranch___024root___eval_stl(Vbranch___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vbranch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch___024root___eval_stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vbranch___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vbranch___024root___eval_triggers__stl(Vbranch___024root* vlSelf);

VL_ATTR_COLD bool Vbranch___024root___eval_phase__stl(Vbranch___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vbranch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch___024root___eval_phase__stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vbranch___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vbranch___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vbranch___024root___dump_triggers__ico(Vbranch___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vbranch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch___024root___dump_triggers__ico\n"); );
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
VL_ATTR_COLD void Vbranch___024root___dump_triggers__act(Vbranch___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vbranch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch___024root___dump_triggers__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vbranch___024root___dump_triggers__nba(Vbranch___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vbranch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch___024root___dump_triggers__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vbranch___024root___ctor_var_reset(Vbranch___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vbranch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch___024root___ctor_var_reset\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->rs1_data_i = VL_RAND_RESET_I(32);
    vlSelf->rs2_data_i = VL_RAND_RESET_I(32);
    vlSelf->funct3_i = VL_RAND_RESET_I(3);
    vlSelf->branch_taken_o = VL_RAND_RESET_I(1);
    vlSelf->branch_eq_o = VL_RAND_RESET_I(1);
    vlSelf->branch_lt_o = VL_RAND_RESET_I(1);
    vlSelf->branch_ltu_o = VL_RAND_RESET_I(1);
}
