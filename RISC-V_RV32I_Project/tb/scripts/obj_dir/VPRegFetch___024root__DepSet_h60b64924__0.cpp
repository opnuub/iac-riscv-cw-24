// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPRegFetch.h for the primary calling header

#include "VPRegFetch__pch.h"
#include "VPRegFetch___024root.h"

void VPRegFetch___024root___eval_act(VPRegFetch___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPRegFetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegFetch___024root___eval_act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

void VPRegFetch___024root___nba_sequent__TOP__0(VPRegFetch___024root* vlSelf);

void VPRegFetch___024root___eval_nba(VPRegFetch___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPRegFetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegFetch___024root___eval_nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VPRegFetch___024root___nba_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void VPRegFetch___024root___nba_sequent__TOP__0(VPRegFetch___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPRegFetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegFetch___024root___nba_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (((IData)(vlSelfRef.rst) | (IData)(vlSelfRef.FlushF))) {
        vlSelfRef.PCPlus4D = 0U;
        vlSelfRef.PCd = 0U;
        vlSelfRef.InstrD = 0U;
    } else {
        vlSelfRef.PCPlus4D = vlSelfRef.PCPlus4F;
        vlSelfRef.PCd = vlSelfRef.PCf;
        vlSelfRef.InstrD = vlSelfRef.instr;
    }
}

void VPRegFetch___024root___eval_triggers__act(VPRegFetch___024root* vlSelf);

bool VPRegFetch___024root___eval_phase__act(VPRegFetch___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPRegFetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegFetch___024root___eval_phase__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VPRegFetch___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        VPRegFetch___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VPRegFetch___024root___eval_phase__nba(VPRegFetch___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPRegFetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegFetch___024root___eval_phase__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        VPRegFetch___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VPRegFetch___024root___dump_triggers__nba(VPRegFetch___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VPRegFetch___024root___dump_triggers__act(VPRegFetch___024root* vlSelf);
#endif  // VL_DEBUG

void VPRegFetch___024root___eval(VPRegFetch___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPRegFetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegFetch___024root___eval\n"); );
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
            VPRegFetch___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/Users/michaelli/Documents/GitHub/iac-riscv-cw-24/RISC-V_RV32I_Project/rtl/PRegFetch.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                VPRegFetch___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/Users/michaelli/Documents/GitHub/iac-riscv-cw-24/RISC-V_RV32I_Project/rtl/PRegFetch.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (VPRegFetch___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (VPRegFetch___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VPRegFetch___024root___eval_debug_assertions(VPRegFetch___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VPRegFetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegFetch___024root___eval_debug_assertions\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelfRef.rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelfRef.FlushF & 0xfeU))) {
        Verilated::overWidthError("FlushF");}
}
#endif  // VL_DEBUG
