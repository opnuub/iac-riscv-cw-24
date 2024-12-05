// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vregfile.h for the primary calling header

#include "Vregfile__pch.h"
#include "Vregfile___024root.h"

void Vregfile___024root___ico_sequent__TOP__0(Vregfile___024root* vlSelf);

void Vregfile___024root___eval_ico(Vregfile___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregfile___024root___eval_ico\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vregfile___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vregfile___024root___ico_sequent__TOP__0(Vregfile___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregfile___024root___ico_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rdata1_o = ((0U == (IData)(vlSelfRef.raddr1_i))
                           ? 0U : vlSelfRef.regfile__DOT__rf_reg
                          [vlSelfRef.raddr1_i]);
    vlSelfRef.rdata2_o = ((0U == (IData)(vlSelfRef.raddr2_i))
                           ? 0U : vlSelfRef.regfile__DOT__rf_reg
                          [vlSelfRef.raddr2_i]);
}

void Vregfile___024root___eval_triggers__ico(Vregfile___024root* vlSelf);

bool Vregfile___024root___eval_phase__ico(Vregfile___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregfile___024root___eval_phase__ico\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vregfile___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vregfile___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vregfile___024root___eval_act(Vregfile___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregfile___024root___eval_act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

void Vregfile___024root___nba_sequent__TOP__0(Vregfile___024root* vlSelf);

void Vregfile___024root___eval_nba(Vregfile___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregfile___024root___eval_nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vregfile___024root___nba_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vregfile___024root___nba_sequent__TOP__0(Vregfile___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregfile___024root___nba_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VdlyVal__regfile__DOT__rf_reg__v0;
    __VdlyVal__regfile__DOT__rf_reg__v0 = 0;
    CData/*4:0*/ __VdlyDim0__regfile__DOT__rf_reg__v0;
    __VdlyDim0__regfile__DOT__rf_reg__v0 = 0;
    CData/*0:0*/ __VdlySet__regfile__DOT__rf_reg__v0;
    __VdlySet__regfile__DOT__rf_reg__v0 = 0;
    CData/*0:0*/ __VdlySet__regfile__DOT__rf_reg__v1;
    __VdlySet__regfile__DOT__rf_reg__v1 = 0;
    // Body
    __VdlySet__regfile__DOT__rf_reg__v0 = 0U;
    __VdlySet__regfile__DOT__rf_reg__v1 = 0U;
    if (vlSelfRef.rst_ni) {
        if (((IData)(vlSelfRef.wen_i) & (0U != (IData)(vlSelfRef.waddr_i)))) {
            __VdlyVal__regfile__DOT__rf_reg__v0 = vlSelfRef.wdata_i;
            __VdlyDim0__regfile__DOT__rf_reg__v0 = vlSelfRef.waddr_i;
            __VdlySet__regfile__DOT__rf_reg__v0 = 1U;
        }
    } else {
        __VdlySet__regfile__DOT__rf_reg__v1 = 1U;
    }
    if (__VdlySet__regfile__DOT__rf_reg__v0) {
        vlSelfRef.regfile__DOT__rf_reg[__VdlyDim0__regfile__DOT__rf_reg__v0] 
            = __VdlyVal__regfile__DOT__rf_reg__v0;
    }
    if (__VdlySet__regfile__DOT__rf_reg__v1) {
        vlSelfRef.regfile__DOT__rf_reg[0U] = 0U;
        vlSelfRef.regfile__DOT__rf_reg[1U] = 0U;
        vlSelfRef.regfile__DOT__rf_reg[2U] = 0U;
        vlSelfRef.regfile__DOT__rf_reg[3U] = 0U;
        vlSelfRef.regfile__DOT__rf_reg[4U] = 0U;
        vlSelfRef.regfile__DOT__rf_reg[5U] = 0U;
        vlSelfRef.regfile__DOT__rf_reg[6U] = 0U;
        vlSelfRef.regfile__DOT__rf_reg[7U] = 0U;
        vlSelfRef.regfile__DOT__rf_reg[8U] = 0U;
        vlSelfRef.regfile__DOT__rf_reg[9U] = 0U;
        vlSelfRef.regfile__DOT__rf_reg[0xaU] = 0U;
        vlSelfRef.regfile__DOT__rf_reg[0xbU] = 0U;
        vlSelfRef.regfile__DOT__rf_reg[0xcU] = 0U;
        vlSelfRef.regfile__DOT__rf_reg[0xdU] = 0U;
        vlSelfRef.regfile__DOT__rf_reg[0xeU] = 0U;
        vlSelfRef.regfile__DOT__rf_reg[0xfU] = 0U;
        vlSelfRef.regfile__DOT__rf_reg[0x10U] = 0U;
        vlSelfRef.regfile__DOT__rf_reg[0x11U] = 0U;
        vlSelfRef.regfile__DOT__rf_reg[0x12U] = 0U;
        vlSelfRef.regfile__DOT__rf_reg[0x13U] = 0U;
        vlSelfRef.regfile__DOT__rf_reg[0x14U] = 0U;
        vlSelfRef.regfile__DOT__rf_reg[0x15U] = 0U;
        vlSelfRef.regfile__DOT__rf_reg[0x16U] = 0U;
        vlSelfRef.regfile__DOT__rf_reg[0x17U] = 0U;
        vlSelfRef.regfile__DOT__rf_reg[0x18U] = 0U;
        vlSelfRef.regfile__DOT__rf_reg[0x19U] = 0U;
        vlSelfRef.regfile__DOT__rf_reg[0x1aU] = 0U;
        vlSelfRef.regfile__DOT__rf_reg[0x1bU] = 0U;
        vlSelfRef.regfile__DOT__rf_reg[0x1cU] = 0U;
        vlSelfRef.regfile__DOT__rf_reg[0x1dU] = 0U;
        vlSelfRef.regfile__DOT__rf_reg[0x1eU] = 0U;
        vlSelfRef.regfile__DOT__rf_reg[0x1fU] = 0U;
    }
    vlSelfRef.a0_o = vlSelfRef.regfile__DOT__rf_reg
        [0xaU];
    vlSelfRef.rdata1_o = ((0U == (IData)(vlSelfRef.raddr1_i))
                           ? 0U : vlSelfRef.regfile__DOT__rf_reg
                          [vlSelfRef.raddr1_i]);
    vlSelfRef.rdata2_o = ((0U == (IData)(vlSelfRef.raddr2_i))
                           ? 0U : vlSelfRef.regfile__DOT__rf_reg
                          [vlSelfRef.raddr2_i]);
}

void Vregfile___024root___eval_triggers__act(Vregfile___024root* vlSelf);

bool Vregfile___024root___eval_phase__act(Vregfile___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregfile___024root___eval_phase__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vregfile___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vregfile___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vregfile___024root___eval_phase__nba(Vregfile___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregfile___024root___eval_phase__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vregfile___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vregfile___024root___dump_triggers__ico(Vregfile___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vregfile___024root___dump_triggers__nba(Vregfile___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vregfile___024root___dump_triggers__act(Vregfile___024root* vlSelf);
#endif  // VL_DEBUG

void Vregfile___024root___eval(Vregfile___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregfile___024root___eval\n"); );
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
            Vregfile___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/Users/michaelli/Documents/GitHub/iac-riscv-cw-24/RISC-V_RV32I_Project/rtl/regfile.sv", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vregfile___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vregfile___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/Users/michaelli/Documents/GitHub/iac-riscv-cw-24/RISC-V_RV32I_Project/rtl/regfile.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vregfile___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/Users/michaelli/Documents/GitHub/iac-riscv-cw-24/RISC-V_RV32I_Project/rtl/regfile.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vregfile___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vregfile___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vregfile___024root___eval_debug_assertions(Vregfile___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregfile___024root___eval_debug_assertions\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.clk_i & 0xfeU))) {
        Verilated::overWidthError("clk_i");}
    if (VL_UNLIKELY((vlSelfRef.rst_ni & 0xfeU))) {
        Verilated::overWidthError("rst_ni");}
    if (VL_UNLIKELY((vlSelfRef.wen_i & 0xfeU))) {
        Verilated::overWidthError("wen_i");}
    if (VL_UNLIKELY((vlSelfRef.waddr_i & 0xe0U))) {
        Verilated::overWidthError("waddr_i");}
    if (VL_UNLIKELY((vlSelfRef.raddr1_i & 0xe0U))) {
        Verilated::overWidthError("raddr1_i");}
    if (VL_UNLIKELY((vlSelfRef.raddr2_i & 0xe0U))) {
        Verilated::overWidthError("raddr2_i");}
}
#endif  // VL_DEBUG
