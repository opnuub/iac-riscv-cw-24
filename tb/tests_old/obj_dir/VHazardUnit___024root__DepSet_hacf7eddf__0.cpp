// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VHazardUnit.h for the primary calling header

#include "VHazardUnit__pch.h"
#include "VHazardUnit___024root.h"

void VHazardUnit___024root___ico_sequent__TOP__0(VHazardUnit___024root* vlSelf);

void VHazardUnit___024root___eval_ico(VHazardUnit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VHazardUnit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VHazardUnit___024root___eval_ico\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VHazardUnit___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void VHazardUnit___024root___ico_sequent__TOP__0(VHazardUnit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VHazardUnit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VHazardUnit___024root___ico_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.Flush = 0U;
    vlSelfRef.Flush = ((IData)(vlSelfRef.zero_hazard) 
                       | (IData)(vlSelfRef.jump_hazard));
    vlSelfRef.stall = 0U;
    vlSelfRef.stall = ((IData)(vlSelfRef.memoryRead_e) 
                       & (((IData)(vlSelfRef.RdE) == (IData)(vlSelfRef.Rs1D)) 
                          | ((IData)(vlSelfRef.RdE) 
                             == (IData)(vlSelfRef.Rs2D))));
    vlSelfRef.ForwardAE = 0U;
    vlSelfRef.ForwardAE = ((((IData)(vlSelfRef.RegWriteM) 
                             & (0U != (IData)(vlSelfRef.destReg_m))) 
                            & ((IData)(vlSelfRef.destReg_m) 
                               == (IData)(vlSelfRef.Rs1E)))
                            ? 2U : ((((IData)(vlSelfRef.RegWriteW) 
                                      & (0U != (IData)(vlSelfRef.destReg_w))) 
                                     & ((IData)(vlSelfRef.destReg_w) 
                                        == (IData)(vlSelfRef.Rs1E)))
                                     ? 1U : 0U));
    vlSelfRef.ForwardBE = 0U;
    vlSelfRef.ForwardBE = ((((IData)(vlSelfRef.RegWriteM) 
                             & (0U != (IData)(vlSelfRef.destReg_m))) 
                            & ((IData)(vlSelfRef.destReg_m) 
                               == (IData)(vlSelfRef.Rs2E)))
                            ? 2U : ((((IData)(vlSelfRef.RegWriteW) 
                                      & (0U != (IData)(vlSelfRef.destReg_w))) 
                                     & ((IData)(vlSelfRef.destReg_w) 
                                        == (IData)(vlSelfRef.Rs2E)))
                                     ? 1U : 0U));
}

void VHazardUnit___024root___eval_triggers__ico(VHazardUnit___024root* vlSelf);

bool VHazardUnit___024root___eval_phase__ico(VHazardUnit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VHazardUnit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VHazardUnit___024root___eval_phase__ico\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    VHazardUnit___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        VHazardUnit___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void VHazardUnit___024root___eval_act(VHazardUnit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VHazardUnit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VHazardUnit___024root___eval_act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

void VHazardUnit___024root___eval_nba(VHazardUnit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VHazardUnit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VHazardUnit___024root___eval_nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

void VHazardUnit___024root___eval_triggers__act(VHazardUnit___024root* vlSelf);

bool VHazardUnit___024root___eval_phase__act(VHazardUnit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VHazardUnit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VHazardUnit___024root___eval_phase__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<0> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VHazardUnit___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        VHazardUnit___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VHazardUnit___024root___eval_phase__nba(VHazardUnit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VHazardUnit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VHazardUnit___024root___eval_phase__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        VHazardUnit___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VHazardUnit___024root___dump_triggers__ico(VHazardUnit___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VHazardUnit___024root___dump_triggers__nba(VHazardUnit___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VHazardUnit___024root___dump_triggers__act(VHazardUnit___024root* vlSelf);
#endif  // VL_DEBUG

void VHazardUnit___024root___eval(VHazardUnit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VHazardUnit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VHazardUnit___024root___eval\n"); );
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
            VHazardUnit___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("../../rtl/HazardUnit.sv", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (VHazardUnit___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            VHazardUnit___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../../rtl/HazardUnit.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                VHazardUnit___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../../rtl/HazardUnit.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (VHazardUnit___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (VHazardUnit___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VHazardUnit___024root___eval_debug_assertions(VHazardUnit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VHazardUnit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VHazardUnit___024root___eval_debug_assertions\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.Rs1E & 0xe0U))) {
        Verilated::overWidthError("Rs1E");}
    if (VL_UNLIKELY((vlSelfRef.Rs2E & 0xe0U))) {
        Verilated::overWidthError("Rs2E");}
    if (VL_UNLIKELY((vlSelfRef.Rs1D & 0xe0U))) {
        Verilated::overWidthError("Rs1D");}
    if (VL_UNLIKELY((vlSelfRef.Rs2D & 0xe0U))) {
        Verilated::overWidthError("Rs2D");}
    if (VL_UNLIKELY((vlSelfRef.RdE & 0xe0U))) {
        Verilated::overWidthError("RdE");}
    if (VL_UNLIKELY((vlSelfRef.destReg_m & 0xe0U))) {
        Verilated::overWidthError("destReg_m");}
    if (VL_UNLIKELY((vlSelfRef.destReg_w & 0xe0U))) {
        Verilated::overWidthError("destReg_w");}
    if (VL_UNLIKELY((vlSelfRef.memoryRead_e & 0xfeU))) {
        Verilated::overWidthError("memoryRead_e");}
    if (VL_UNLIKELY((vlSelfRef.RegWriteM & 0xfeU))) {
        Verilated::overWidthError("RegWriteM");}
    if (VL_UNLIKELY((vlSelfRef.RegWriteW & 0xfeU))) {
        Verilated::overWidthError("RegWriteW");}
    if (VL_UNLIKELY((vlSelfRef.zero_hazard & 0xfeU))) {
        Verilated::overWidthError("zero_hazard");}
    if (VL_UNLIKELY((vlSelfRef.jump_hazard & 0xfeU))) {
        Verilated::overWidthError("jump_hazard");}
}
#endif  // VL_DEBUG
