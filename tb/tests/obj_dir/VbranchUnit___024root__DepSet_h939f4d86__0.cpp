// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VbranchUnit.h for the primary calling header

#include "VbranchUnit__pch.h"
#include "VbranchUnit___024root.h"

void VbranchUnit___024root___ico_sequent__TOP__0(VbranchUnit___024root* vlSelf);

void VbranchUnit___024root___eval_ico(VbranchUnit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VbranchUnit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VbranchUnit___024root___eval_ico\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VbranchUnit___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void VbranchUnit___024root___ico_sequent__TOP__0(VbranchUnit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VbranchUnit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VbranchUnit___024root___ico_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.zero = ((1U & ((IData)(vlSelfRef.aluControl) 
                             >> 3U)) && ((4U & (IData)(vlSelfRef.aluControl))
                                          ? ((2U & (IData)(vlSelfRef.aluControl))
                                              ? ((1U 
                                                  & (IData)(vlSelfRef.aluControl))
                                                  ? 
                                                 (vlSelfRef.srcA 
                                                  >= vlSelfRef.srcB)
                                                  : 
                                                 (vlSelfRef.srcA 
                                                  < vlSelfRef.srcB))
                                              : ((1U 
                                                  & (IData)(vlSelfRef.aluControl))
                                                  ? 
                                                 VL_GTES_III(32, vlSelfRef.srcA, vlSelfRef.srcB)
                                                  : 
                                                 VL_LTS_III(32, vlSelfRef.srcA, vlSelfRef.srcB)))
                                          : ((1U & 
                                              (~ ((IData)(vlSelfRef.aluControl) 
                                                  >> 1U))) 
                                             && ((1U 
                                                  & (IData)(vlSelfRef.aluControl))
                                                  ? 
                                                 (0U 
                                                  != 
                                                  (vlSelfRef.srcA 
                                                   - vlSelfRef.srcB))
                                                  : 
                                                 (0U 
                                                  == 
                                                  (vlSelfRef.srcA 
                                                   - vlSelfRef.srcB))))));
}

void VbranchUnit___024root___eval_triggers__ico(VbranchUnit___024root* vlSelf);

bool VbranchUnit___024root___eval_phase__ico(VbranchUnit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VbranchUnit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VbranchUnit___024root___eval_phase__ico\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    VbranchUnit___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        VbranchUnit___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void VbranchUnit___024root___eval_act(VbranchUnit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VbranchUnit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VbranchUnit___024root___eval_act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

void VbranchUnit___024root___eval_nba(VbranchUnit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VbranchUnit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VbranchUnit___024root___eval_nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

void VbranchUnit___024root___eval_triggers__act(VbranchUnit___024root* vlSelf);

bool VbranchUnit___024root___eval_phase__act(VbranchUnit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VbranchUnit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VbranchUnit___024root___eval_phase__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<0> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VbranchUnit___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        VbranchUnit___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VbranchUnit___024root___eval_phase__nba(VbranchUnit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VbranchUnit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VbranchUnit___024root___eval_phase__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        VbranchUnit___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VbranchUnit___024root___dump_triggers__ico(VbranchUnit___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VbranchUnit___024root___dump_triggers__nba(VbranchUnit___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VbranchUnit___024root___dump_triggers__act(VbranchUnit___024root* vlSelf);
#endif  // VL_DEBUG

void VbranchUnit___024root___eval(VbranchUnit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VbranchUnit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VbranchUnit___024root___eval\n"); );
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
            VbranchUnit___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("../../rtl/branchUnit.sv", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (VbranchUnit___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            VbranchUnit___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../../rtl/branchUnit.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                VbranchUnit___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../../rtl/branchUnit.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (VbranchUnit___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (VbranchUnit___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VbranchUnit___024root___eval_debug_assertions(VbranchUnit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VbranchUnit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VbranchUnit___024root___eval_debug_assertions\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.aluControl & 0xf0U))) {
        Verilated::overWidthError("aluControl");}
}
#endif  // VL_DEBUG
