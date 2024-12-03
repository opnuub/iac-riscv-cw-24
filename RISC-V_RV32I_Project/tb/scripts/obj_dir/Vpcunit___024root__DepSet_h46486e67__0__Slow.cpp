// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpcunit.h for the primary calling header

#include "Vpcunit__pch.h"
#include "Vpcunit___024root.h"

VL_ATTR_COLD void Vpcunit___024root___eval_static(Vpcunit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vpcunit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpcunit___024root___eval_static\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vpcunit___024root___eval_initial(Vpcunit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vpcunit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpcunit___024root___eval_initial\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk_i__0 = vlSelfRef.clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_ni__0 = vlSelfRef.rst_ni;
}

VL_ATTR_COLD void Vpcunit___024root___eval_final(Vpcunit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vpcunit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpcunit___024root___eval_final\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpcunit___024root___dump_triggers__stl(Vpcunit___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vpcunit___024root___eval_phase__stl(Vpcunit___024root* vlSelf);

VL_ATTR_COLD void Vpcunit___024root___eval_settle(Vpcunit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vpcunit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpcunit___024root___eval_settle\n"); );
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
            Vpcunit___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("/Users/michaelli/Documents/GitHub/iac-riscv-cw-24/RISC-V_RV32I_Project/rtl/pcunit.sv", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vpcunit___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpcunit___024root___dump_triggers__stl(Vpcunit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vpcunit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpcunit___024root___dump_triggers__stl\n"); );
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

VL_ATTR_COLD void Vpcunit___024root___stl_sequent__TOP__0(Vpcunit___024root* vlSelf);

VL_ATTR_COLD void Vpcunit___024root___eval_stl(Vpcunit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vpcunit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpcunit___024root___eval_stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vpcunit___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vpcunit___024root___stl_sequent__TOP__0(Vpcunit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vpcunit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpcunit___024root___stl_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.pc_o = vlSelfRef.pcunit__DOT__pc_q;
    vlSelfRef.next_pc_o = ((IData)(4U) + vlSelfRef.pcunit__DOT__pc_q);
    vlSelfRef.next_pc_o = ((4U & (IData)(vlSelfRef.next_pc_sel_i))
                            ? ((IData)(4U) + vlSelfRef.pcunit__DOT__pc_q)
                            : ((2U & (IData)(vlSelfRef.next_pc_sel_i))
                                ? ((1U & (IData)(vlSelfRef.next_pc_sel_i))
                                    ? (0xfffffffeU 
                                       & vlSelfRef.alu_result_i)
                                    : (vlSelfRef.pcunit__DOT__pc_q 
                                       + vlSelfRef.imm_i))
                                : ((1U & (IData)(vlSelfRef.next_pc_sel_i))
                                    ? (vlSelfRef.pcunit__DOT__pc_q 
                                       + vlSelfRef.imm_i)
                                    : ((IData)(4U) 
                                       + vlSelfRef.pcunit__DOT__pc_q))));
}

VL_ATTR_COLD void Vpcunit___024root___eval_triggers__stl(Vpcunit___024root* vlSelf);

VL_ATTR_COLD bool Vpcunit___024root___eval_phase__stl(Vpcunit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vpcunit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpcunit___024root___eval_phase__stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vpcunit___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vpcunit___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpcunit___024root___dump_triggers__ico(Vpcunit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vpcunit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpcunit___024root___dump_triggers__ico\n"); );
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
VL_ATTR_COLD void Vpcunit___024root___dump_triggers__act(Vpcunit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vpcunit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpcunit___024root___dump_triggers__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk_i or negedge rst_ni)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpcunit___024root___dump_triggers__nba(Vpcunit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vpcunit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpcunit___024root___dump_triggers__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk_i or negedge rst_ni)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vpcunit___024root___ctor_var_reset(Vpcunit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vpcunit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpcunit___024root___ctor_var_reset\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk_i = VL_RAND_RESET_I(1);
    vlSelf->rst_ni = VL_RAND_RESET_I(1);
    vlSelf->next_pc_sel_i = VL_RAND_RESET_I(3);
    vlSelf->alu_result_i = VL_RAND_RESET_I(32);
    vlSelf->imm_i = VL_RAND_RESET_I(32);
    vlSelf->pc_o = VL_RAND_RESET_I(32);
    vlSelf->next_pc_o = VL_RAND_RESET_I(32);
    vlSelf->pcunit__DOT__pc_q = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__clk_i__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst_ni__0 = VL_RAND_RESET_I(1);
}
