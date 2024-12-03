// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdmem.h for the primary calling header

#include "Vdmem__pch.h"
#include "Vdmem___024root.h"

void Vdmem___024root___ico_sequent__TOP__0(Vdmem___024root* vlSelf);

void Vdmem___024root___eval_ico(Vdmem___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdmem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdmem___024root___eval_ico\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vdmem___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vdmem___024root___ico_sequent__TOP__0(Vdmem___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdmem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdmem___024root___ico_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ dmem__DOT__rdata_aligned;
    dmem__DOT__rdata_aligned = 0;
    // Body
    dmem__DOT__rdata_aligned = ((0U == (IData)(vlSelfRef.size_i))
                                 ? (((- (IData)(((IData)(vlSelfRef.signed_i) 
                                                 & (vlSelfRef.dmem__DOT__mem
                                                    [
                                                    (0x1fffU 
                                                     & vlSelfRef.addr_i)] 
                                                    >> 7U)))) 
                                     << 8U) | vlSelfRef.dmem__DOT__mem
                                    [(0x1fffU & vlSelfRef.addr_i)])
                                 : ((1U == (IData)(vlSelfRef.size_i))
                                     ? ((0x2000U > 
                                         ((IData)(1U) 
                                          + vlSelfRef.addr_i))
                                         ? (((- (IData)(
                                                        ((IData)(vlSelfRef.signed_i) 
                                                         & (vlSelfRef.dmem__DOT__mem
                                                            [
                                                            (0x1fffU 
                                                             & ((IData)(1U) 
                                                                + vlSelfRef.addr_i))] 
                                                            >> 7U)))) 
                                             << 0x10U) 
                                            | ((vlSelfRef.dmem__DOT__mem
                                                [(0x1fffU 
                                                  & ((IData)(1U) 
                                                     + vlSelfRef.addr_i))] 
                                                << 8U) 
                                               | vlSelfRef.dmem__DOT__mem
                                               [(0x1fffU 
                                                 & vlSelfRef.addr_i)]))
                                         : 0U) : ((2U 
                                                   == (IData)(vlSelfRef.size_i))
                                                   ? 
                                                  ((0x2000U 
                                                    > 
                                                    ((IData)(3U) 
                                                     + vlSelfRef.addr_i))
                                                    ? 
                                                   ((vlSelfRef.dmem__DOT__mem
                                                     [
                                                     (0x1fffU 
                                                      & ((IData)(3U) 
                                                         + vlSelfRef.addr_i))] 
                                                     << 0x18U) 
                                                    | ((vlSelfRef.dmem__DOT__mem
                                                        [
                                                        (0x1fffU 
                                                         & ((IData)(2U) 
                                                            + vlSelfRef.addr_i))] 
                                                        << 0x10U) 
                                                       | ((vlSelfRef.dmem__DOT__mem
                                                           [
                                                           (0x1fffU 
                                                            & ((IData)(1U) 
                                                               + vlSelfRef.addr_i))] 
                                                           << 8U) 
                                                          | vlSelfRef.dmem__DOT__mem
                                                          [
                                                          (0x1fffU 
                                                           & vlSelfRef.addr_i)])))
                                                    : 0U)
                                                   : 0U)));
    vlSelfRef.rdata_o = dmem__DOT__rdata_aligned;
}

void Vdmem___024root___eval_triggers__ico(Vdmem___024root* vlSelf);

bool Vdmem___024root___eval_phase__ico(Vdmem___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdmem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdmem___024root___eval_phase__ico\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vdmem___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vdmem___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vdmem___024root___eval_act(Vdmem___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdmem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdmem___024root___eval_act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

void Vdmem___024root___nba_sequent__TOP__0(Vdmem___024root* vlSelf);

void Vdmem___024root___eval_nba(Vdmem___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdmem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdmem___024root___eval_nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vdmem___024root___nba_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vdmem___024root___nba_sequent__TOP__0(Vdmem___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdmem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdmem___024root___nba_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ dmem__DOT__rdata_aligned;
    dmem__DOT__rdata_aligned = 0;
    CData/*7:0*/ __VdlyVal__dmem__DOT__mem__v0;
    __VdlyVal__dmem__DOT__mem__v0 = 0;
    SData/*12:0*/ __VdlyDim0__dmem__DOT__mem__v0;
    __VdlyDim0__dmem__DOT__mem__v0 = 0;
    CData/*7:0*/ __VdlyVal__dmem__DOT__mem__v1;
    __VdlyVal__dmem__DOT__mem__v1 = 0;
    SData/*12:0*/ __VdlyDim0__dmem__DOT__mem__v1;
    __VdlyDim0__dmem__DOT__mem__v1 = 0;
    CData/*7:0*/ __VdlyVal__dmem__DOT__mem__v2;
    __VdlyVal__dmem__DOT__mem__v2 = 0;
    SData/*12:0*/ __VdlyDim0__dmem__DOT__mem__v2;
    __VdlyDim0__dmem__DOT__mem__v2 = 0;
    CData/*7:0*/ __VdlyVal__dmem__DOT__mem__v3;
    __VdlyVal__dmem__DOT__mem__v3 = 0;
    SData/*12:0*/ __VdlyDim0__dmem__DOT__mem__v3;
    __VdlyDim0__dmem__DOT__mem__v3 = 0;
    CData/*7:0*/ __VdlyVal__dmem__DOT__mem__v4;
    __VdlyVal__dmem__DOT__mem__v4 = 0;
    SData/*12:0*/ __VdlyDim0__dmem__DOT__mem__v4;
    __VdlyDim0__dmem__DOT__mem__v4 = 0;
    CData/*7:0*/ __VdlyVal__dmem__DOT__mem__v5;
    __VdlyVal__dmem__DOT__mem__v5 = 0;
    SData/*12:0*/ __VdlyDim0__dmem__DOT__mem__v5;
    __VdlyDim0__dmem__DOT__mem__v5 = 0;
    CData/*7:0*/ __VdlyVal__dmem__DOT__mem__v6;
    __VdlyVal__dmem__DOT__mem__v6 = 0;
    SData/*12:0*/ __VdlyDim0__dmem__DOT__mem__v6;
    __VdlyDim0__dmem__DOT__mem__v6 = 0;
    SData/*12:0*/ __VdlyDim0__dmem__DOT__mem__v7;
    __VdlyDim0__dmem__DOT__mem__v7 = 0;
    // Body
    if (vlSelfRef.rst_ni) {
        if (vlSelfRef.wen_i) {
            if ((0U == (IData)(vlSelfRef.size_i))) {
                __VdlyVal__dmem__DOT__mem__v0 = (0xffU 
                                                 & vlSelfRef.wdata_i);
                __VdlyDim0__dmem__DOT__mem__v0 = (0x1fffU 
                                                  & vlSelfRef.addr_i);
                vlSelfRef.__VdlyCommitQueue__dmem__DOT__mem__v0.enqueue(__VdlyVal__dmem__DOT__mem__v0, (IData)(__VdlyDim0__dmem__DOT__mem__v0));
            } else if ((1U == (IData)(vlSelfRef.size_i))) {
                if ((0x2000U > ((IData)(1U) + vlSelfRef.addr_i))) {
                    __VdlyVal__dmem__DOT__mem__v1 = 
                        (0xffU & vlSelfRef.wdata_i);
                    __VdlyDim0__dmem__DOT__mem__v1 
                        = (0x1fffU & vlSelfRef.addr_i);
                    vlSelfRef.__VdlyCommitQueue__dmem__DOT__mem__v0.enqueue(__VdlyVal__dmem__DOT__mem__v1, (IData)(__VdlyDim0__dmem__DOT__mem__v1));
                    __VdlyVal__dmem__DOT__mem__v2 = 
                        (0xffU & (vlSelfRef.wdata_i 
                                  >> 8U));
                    __VdlyDim0__dmem__DOT__mem__v2 
                        = (0x1fffU & ((IData)(1U) + vlSelfRef.addr_i));
                    vlSelfRef.__VdlyCommitQueue__dmem__DOT__mem__v0.enqueue(__VdlyVal__dmem__DOT__mem__v2, (IData)(__VdlyDim0__dmem__DOT__mem__v2));
                }
            } else if ((2U == (IData)(vlSelfRef.size_i))) {
                if ((0x2000U > ((IData)(3U) + vlSelfRef.addr_i))) {
                    __VdlyVal__dmem__DOT__mem__v3 = 
                        (0xffU & vlSelfRef.wdata_i);
                    __VdlyDim0__dmem__DOT__mem__v3 
                        = (0x1fffU & vlSelfRef.addr_i);
                    vlSelfRef.__VdlyCommitQueue__dmem__DOT__mem__v0.enqueue(__VdlyVal__dmem__DOT__mem__v3, (IData)(__VdlyDim0__dmem__DOT__mem__v3));
                    __VdlyVal__dmem__DOT__mem__v4 = 
                        (0xffU & (vlSelfRef.wdata_i 
                                  >> 8U));
                    __VdlyDim0__dmem__DOT__mem__v4 
                        = (0x1fffU & ((IData)(1U) + vlSelfRef.addr_i));
                    vlSelfRef.__VdlyCommitQueue__dmem__DOT__mem__v0.enqueue(__VdlyVal__dmem__DOT__mem__v4, (IData)(__VdlyDim0__dmem__DOT__mem__v4));
                    __VdlyVal__dmem__DOT__mem__v5 = 
                        (0xffU & (vlSelfRef.wdata_i 
                                  >> 0x10U));
                    __VdlyDim0__dmem__DOT__mem__v5 
                        = (0x1fffU & ((IData)(2U) + vlSelfRef.addr_i));
                    vlSelfRef.__VdlyCommitQueue__dmem__DOT__mem__v0.enqueue(__VdlyVal__dmem__DOT__mem__v5, (IData)(__VdlyDim0__dmem__DOT__mem__v5));
                    __VdlyVal__dmem__DOT__mem__v6 = 
                        (vlSelfRef.wdata_i >> 0x18U);
                    __VdlyDim0__dmem__DOT__mem__v6 
                        = (0x1fffU & ((IData)(3U) + vlSelfRef.addr_i));
                    vlSelfRef.__VdlyCommitQueue__dmem__DOT__mem__v0.enqueue(__VdlyVal__dmem__DOT__mem__v6, (IData)(__VdlyDim0__dmem__DOT__mem__v6));
                }
            }
        }
    } else {
        vlSelfRef.dmem__DOT__unnamedblk1__DOT__i = 0U;
        while (VL_GTS_III(32, 0x2000U, vlSelfRef.dmem__DOT__unnamedblk1__DOT__i)) {
            __VdlyDim0__dmem__DOT__mem__v7 = (0x1fffU 
                                              & vlSelfRef.dmem__DOT__unnamedblk1__DOT__i);
            vlSelfRef.__VdlyCommitQueue__dmem__DOT__mem__v0.enqueue(0U, (IData)(__VdlyDim0__dmem__DOT__mem__v7));
            vlSelfRef.dmem__DOT__unnamedblk1__DOT__i 
                = ((IData)(1U) + vlSelfRef.dmem__DOT__unnamedblk1__DOT__i);
        }
    }
    vlSelfRef.__VdlyCommitQueue__dmem__DOT__mem__v0.commit(vlSelfRef.dmem__DOT__mem);
    dmem__DOT__rdata_aligned = ((0U == (IData)(vlSelfRef.size_i))
                                 ? (((- (IData)(((IData)(vlSelfRef.signed_i) 
                                                 & (vlSelfRef.dmem__DOT__mem
                                                    [
                                                    (0x1fffU 
                                                     & vlSelfRef.addr_i)] 
                                                    >> 7U)))) 
                                     << 8U) | vlSelfRef.dmem__DOT__mem
                                    [(0x1fffU & vlSelfRef.addr_i)])
                                 : ((1U == (IData)(vlSelfRef.size_i))
                                     ? ((0x2000U > 
                                         ((IData)(1U) 
                                          + vlSelfRef.addr_i))
                                         ? (((- (IData)(
                                                        ((IData)(vlSelfRef.signed_i) 
                                                         & (vlSelfRef.dmem__DOT__mem
                                                            [
                                                            (0x1fffU 
                                                             & ((IData)(1U) 
                                                                + vlSelfRef.addr_i))] 
                                                            >> 7U)))) 
                                             << 0x10U) 
                                            | ((vlSelfRef.dmem__DOT__mem
                                                [(0x1fffU 
                                                  & ((IData)(1U) 
                                                     + vlSelfRef.addr_i))] 
                                                << 8U) 
                                               | vlSelfRef.dmem__DOT__mem
                                               [(0x1fffU 
                                                 & vlSelfRef.addr_i)]))
                                         : 0U) : ((2U 
                                                   == (IData)(vlSelfRef.size_i))
                                                   ? 
                                                  ((0x2000U 
                                                    > 
                                                    ((IData)(3U) 
                                                     + vlSelfRef.addr_i))
                                                    ? 
                                                   ((vlSelfRef.dmem__DOT__mem
                                                     [
                                                     (0x1fffU 
                                                      & ((IData)(3U) 
                                                         + vlSelfRef.addr_i))] 
                                                     << 0x18U) 
                                                    | ((vlSelfRef.dmem__DOT__mem
                                                        [
                                                        (0x1fffU 
                                                         & ((IData)(2U) 
                                                            + vlSelfRef.addr_i))] 
                                                        << 0x10U) 
                                                       | ((vlSelfRef.dmem__DOT__mem
                                                           [
                                                           (0x1fffU 
                                                            & ((IData)(1U) 
                                                               + vlSelfRef.addr_i))] 
                                                           << 8U) 
                                                          | vlSelfRef.dmem__DOT__mem
                                                          [
                                                          (0x1fffU 
                                                           & vlSelfRef.addr_i)])))
                                                    : 0U)
                                                   : 0U)));
    vlSelfRef.rdata_o = dmem__DOT__rdata_aligned;
}

void Vdmem___024root___eval_triggers__act(Vdmem___024root* vlSelf);

bool Vdmem___024root___eval_phase__act(Vdmem___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdmem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdmem___024root___eval_phase__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vdmem___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vdmem___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vdmem___024root___eval_phase__nba(Vdmem___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdmem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdmem___024root___eval_phase__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vdmem___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdmem___024root___dump_triggers__ico(Vdmem___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vdmem___024root___dump_triggers__nba(Vdmem___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vdmem___024root___dump_triggers__act(Vdmem___024root* vlSelf);
#endif  // VL_DEBUG

void Vdmem___024root___eval(Vdmem___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdmem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdmem___024root___eval\n"); );
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
            Vdmem___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/Users/michaelli/Documents/GitHub/iac-riscv-cw-24/RISC-V_RV32I_Project/rtl/dmem.sv", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vdmem___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vdmem___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/Users/michaelli/Documents/GitHub/iac-riscv-cw-24/RISC-V_RV32I_Project/rtl/dmem.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vdmem___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/Users/michaelli/Documents/GitHub/iac-riscv-cw-24/RISC-V_RV32I_Project/rtl/dmem.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vdmem___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vdmem___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vdmem___024root___eval_debug_assertions(Vdmem___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdmem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdmem___024root___eval_debug_assertions\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.clk_i & 0xfeU))) {
        Verilated::overWidthError("clk_i");}
    if (VL_UNLIKELY((vlSelfRef.rst_ni & 0xfeU))) {
        Verilated::overWidthError("rst_ni");}
    if (VL_UNLIKELY((vlSelfRef.wen_i & 0xfeU))) {
        Verilated::overWidthError("wen_i");}
    if (VL_UNLIKELY((vlSelfRef.size_i & 0xf8U))) {
        Verilated::overWidthError("size_i");}
    if (VL_UNLIKELY((vlSelfRef.signed_i & 0xfeU))) {
        Verilated::overWidthError("signed_i");}
}
#endif  // VL_DEBUG
