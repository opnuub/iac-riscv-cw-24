// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbranch.h for the primary calling header

#include "Vbranch__pch.h"
#include "Vbranch___024root.h"

void Vbranch___024root___ico_sequent__TOP__0(Vbranch___024root* vlSelf);

void Vbranch___024root___eval_ico(Vbranch___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vbranch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch___024root___eval_ico\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vbranch___024root___ico_sequent__TOP__0(vlSelf);
    }
}

extern const VlUnpacked<CData/*0:0*/, 512> Vbranch__ConstPool__TABLE_h4a44e999_0;

VL_INLINE_OPT void Vbranch___024root___ico_sequent__TOP__0(Vbranch___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vbranch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch___024root___ico_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*8:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelfRef.branch_eq_o = (vlSelfRef.rs1_data_i == vlSelfRef.rs2_data_i);
    vlSelfRef.branch_lt_o = VL_LTS_III(32, vlSelfRef.rs1_data_i, vlSelfRef.rs2_data_i);
    vlSelfRef.branch_ltu_o = (vlSelfRef.rs1_data_i 
                              < vlSelfRef.rs2_data_i);
    __Vtableidx1 = (((IData)(vlSelfRef.branch_eq_o) 
                     << 8U) | ((0x80U & ((~ (IData)(vlSelfRef.branch_eq_o)) 
                                         << 7U)) | 
                               (((IData)(vlSelfRef.branch_lt_o) 
                                 << 6U) | ((0x20U & 
                                            ((~ (IData)(vlSelfRef.branch_lt_o)) 
                                             << 5U)) 
                                           | (((IData)(vlSelfRef.branch_ltu_o) 
                                               << 4U) 
                                              | ((8U 
                                                  & ((~ (IData)(vlSelfRef.branch_ltu_o)) 
                                                     << 3U)) 
                                                 | (IData)(vlSelfRef.funct3_i)))))));
    vlSelfRef.branch_taken_o = Vbranch__ConstPool__TABLE_h4a44e999_0
        [__Vtableidx1];
}

void Vbranch___024root___eval_triggers__ico(Vbranch___024root* vlSelf);

bool Vbranch___024root___eval_phase__ico(Vbranch___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vbranch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch___024root___eval_phase__ico\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vbranch___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vbranch___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vbranch___024root___eval_act(Vbranch___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vbranch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch___024root___eval_act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

void Vbranch___024root___eval_nba(Vbranch___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vbranch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch___024root___eval_nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

void Vbranch___024root___eval_triggers__act(Vbranch___024root* vlSelf);

bool Vbranch___024root___eval_phase__act(Vbranch___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vbranch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch___024root___eval_phase__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<0> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vbranch___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vbranch___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vbranch___024root___eval_phase__nba(Vbranch___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vbranch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch___024root___eval_phase__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vbranch___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vbranch___024root___dump_triggers__ico(Vbranch___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vbranch___024root___dump_triggers__nba(Vbranch___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vbranch___024root___dump_triggers__act(Vbranch___024root* vlSelf);
#endif  // VL_DEBUG

void Vbranch___024root___eval(Vbranch___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vbranch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch___024root___eval\n"); );
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
            Vbranch___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/Users/michaelli/Documents/GitHub/iac-riscv-cw-24/RISC-V_RV32I_Project/rtl/branch.sv", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vbranch___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vbranch___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/Users/michaelli/Documents/GitHub/iac-riscv-cw-24/RISC-V_RV32I_Project/rtl/branch.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vbranch___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/Users/michaelli/Documents/GitHub/iac-riscv-cw-24/RISC-V_RV32I_Project/rtl/branch.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vbranch___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vbranch___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vbranch___024root___eval_debug_assertions(Vbranch___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vbranch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch___024root___eval_debug_assertions\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.funct3_i & 0xf8U))) {
        Verilated::overWidthError("funct3_i");}
}
#endif  // VL_DEBUG
