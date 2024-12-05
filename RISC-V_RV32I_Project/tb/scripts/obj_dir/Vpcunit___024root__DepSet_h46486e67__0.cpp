// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpcunit.h for the primary calling header

#include "Vpcunit__pch.h"
#include "Vpcunit___024root.h"

void Vpcunit___024root___ico_sequent__TOP__0(Vpcunit___024root* vlSelf);

void Vpcunit___024root___eval_ico(Vpcunit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vpcunit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpcunit___024root___eval_ico\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vpcunit___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vpcunit___024root___ico_sequent__TOP__0(Vpcunit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vpcunit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpcunit___024root___ico_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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

void Vpcunit___024root___eval_triggers__ico(Vpcunit___024root* vlSelf);

bool Vpcunit___024root___eval_phase__ico(Vpcunit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vpcunit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpcunit___024root___eval_phase__ico\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vpcunit___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vpcunit___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vpcunit___024root___eval_act(Vpcunit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vpcunit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpcunit___024root___eval_act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

void Vpcunit___024root___nba_sequent__TOP__0(Vpcunit___024root* vlSelf);

void Vpcunit___024root___eval_nba(Vpcunit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vpcunit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpcunit___024root___eval_nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vpcunit___024root___nba_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vpcunit___024root___nba_sequent__TOP__0(Vpcunit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vpcunit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpcunit___024root___nba_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.pcunit__DOT__pc_q = ((IData)(vlSelfRef.rst_ni)
                                    ? vlSelfRef.next_pc_o
                                    : 0U);
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

void Vpcunit___024root___eval_triggers__act(Vpcunit___024root* vlSelf);

bool Vpcunit___024root___eval_phase__act(Vpcunit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vpcunit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpcunit___024root___eval_phase__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vpcunit___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vpcunit___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vpcunit___024root___eval_phase__nba(Vpcunit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vpcunit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpcunit___024root___eval_phase__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vpcunit___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpcunit___024root___dump_triggers__ico(Vpcunit___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vpcunit___024root___dump_triggers__nba(Vpcunit___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vpcunit___024root___dump_triggers__act(Vpcunit___024root* vlSelf);
#endif  // VL_DEBUG

void Vpcunit___024root___eval(Vpcunit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vpcunit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpcunit___024root___eval\n"); );
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
            Vpcunit___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/Users/michaelli/Documents/GitHub/iac-riscv-cw-24/RISC-V_RV32I_Project/rtl/pcunit.sv", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vpcunit___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vpcunit___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/Users/michaelli/Documents/GitHub/iac-riscv-cw-24/RISC-V_RV32I_Project/rtl/pcunit.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vpcunit___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/Users/michaelli/Documents/GitHub/iac-riscv-cw-24/RISC-V_RV32I_Project/rtl/pcunit.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vpcunit___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vpcunit___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vpcunit___024root___eval_debug_assertions(Vpcunit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vpcunit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpcunit___024root___eval_debug_assertions\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.clk_i & 0xfeU))) {
        Verilated::overWidthError("clk_i");}
    if (VL_UNLIKELY((vlSelfRef.rst_ni & 0xfeU))) {
        Verilated::overWidthError("rst_ni");}
    if (VL_UNLIKELY((vlSelfRef.next_pc_sel_i & 0xf8U))) {
        Verilated::overWidthError("next_pc_sel_i");}
}
#endif  // VL_DEBUG
