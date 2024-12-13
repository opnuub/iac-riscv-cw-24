// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdut.h for the primary calling header

#include "Vdut__pch.h"
#include "Vdut___024root.h"

void Vdut___024root___eval_act(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

void Vdut___024root___nba_sequent__TOP__0(Vdut___024root* vlSelf);
void Vdut___024root___nba_sequent__TOP__1(Vdut___024root* vlSelf);
void Vdut___024root___nba_sequent__TOP__2(Vdut___024root* vlSelf);
void Vdut___024root___nba_comb__TOP__0(Vdut___024root* vlSelf);

void Vdut___024root___eval_nba(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vdut___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vdut___024root___nba_sequent__TOP__1(vlSelf);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vdut___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vdut___024root___nba_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
}

VL_INLINE_OPT void Vdut___024root___nba_sequent__TOP__0(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___nba_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VdlyVal__top__DOT__regfile__DOT__rf_reg__v0;
    __VdlyVal__top__DOT__regfile__DOT__rf_reg__v0 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__regfile__DOT__rf_reg__v0;
    __VdlyDim0__top__DOT__regfile__DOT__rf_reg__v0 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__dmem__DOT__mem__v0;
    __VdlyVal__top__DOT__dmem__DOT__mem__v0 = 0;
    SData/*12:0*/ __VdlyDim0__top__DOT__dmem__DOT__mem__v0;
    __VdlyDim0__top__DOT__dmem__DOT__mem__v0 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__dmem__DOT__mem__v1;
    __VdlyVal__top__DOT__dmem__DOT__mem__v1 = 0;
    SData/*12:0*/ __VdlyDim0__top__DOT__dmem__DOT__mem__v1;
    __VdlyDim0__top__DOT__dmem__DOT__mem__v1 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__dmem__DOT__mem__v2;
    __VdlyVal__top__DOT__dmem__DOT__mem__v2 = 0;
    SData/*12:0*/ __VdlyDim0__top__DOT__dmem__DOT__mem__v2;
    __VdlyDim0__top__DOT__dmem__DOT__mem__v2 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__dmem__DOT__mem__v3;
    __VdlyVal__top__DOT__dmem__DOT__mem__v3 = 0;
    SData/*12:0*/ __VdlyDim0__top__DOT__dmem__DOT__mem__v3;
    __VdlyDim0__top__DOT__dmem__DOT__mem__v3 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__dmem__DOT__mem__v4;
    __VdlyVal__top__DOT__dmem__DOT__mem__v4 = 0;
    SData/*12:0*/ __VdlyDim0__top__DOT__dmem__DOT__mem__v4;
    __VdlyDim0__top__DOT__dmem__DOT__mem__v4 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__dmem__DOT__mem__v5;
    __VdlyVal__top__DOT__dmem__DOT__mem__v5 = 0;
    SData/*12:0*/ __VdlyDim0__top__DOT__dmem__DOT__mem__v5;
    __VdlyDim0__top__DOT__dmem__DOT__mem__v5 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__dmem__DOT__mem__v6;
    __VdlyVal__top__DOT__dmem__DOT__mem__v6 = 0;
    SData/*12:0*/ __VdlyDim0__top__DOT__dmem__DOT__mem__v6;
    __VdlyDim0__top__DOT__dmem__DOT__mem__v6 = 0;
    SData/*12:0*/ __VdlyDim0__top__DOT__dmem__DOT__mem__v7;
    __VdlyDim0__top__DOT__dmem__DOT__mem__v7 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regfile__DOT__rf_reg__v0;
    __VdlySet__top__DOT__regfile__DOT__rf_reg__v0 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regfile__DOT__rf_reg__v1;
    __VdlySet__top__DOT__regfile__DOT__rf_reg__v1 = 0;
    // Body
    __VdlySet__top__DOT__regfile__DOT__rf_reg__v0 = 0U;
    __VdlySet__top__DOT__regfile__DOT__rf_reg__v1 = 0U;
    if ((1U & (~ (IData)(vlSelfRef.rst_ni)))) {
        vlSelfRef.top__DOT__regfile__DOT__unnamedblk1__DOT__i = 0x20U;
    }
    if (vlSelfRef.rst_ni) {
        if (vlSelfRef.top__DOT__mem_wen) {
            if ((0U == (IData)(vlSelfRef.top__DOT__mem_size))) {
                __VdlyVal__top__DOT__dmem__DOT__mem__v0 
                    = (0xffU & vlSelfRef.top__DOT__rs2_data);
                __VdlyDim0__top__DOT__dmem__DOT__mem__v0 
                    = (0x1fffU & vlSelfRef.top__DOT__alu_result);
                vlSelfRef.__VdlyCommitQueue__top__DOT__dmem__DOT__mem__v0.enqueue(__VdlyVal__top__DOT__dmem__DOT__mem__v0, (IData)(__VdlyDim0__top__DOT__dmem__DOT__mem__v0));
            } else if ((1U == (IData)(vlSelfRef.top__DOT__mem_size))) {
                if ((0x2000U > ((IData)(1U) + vlSelfRef.top__DOT__alu_result))) {
                    __VdlyVal__top__DOT__dmem__DOT__mem__v1 
                        = (0xffU & vlSelfRef.top__DOT__rs2_data);
                    __VdlyDim0__top__DOT__dmem__DOT__mem__v1 
                        = (0x1fffU & vlSelfRef.top__DOT__alu_result);
                    vlSelfRef.__VdlyCommitQueue__top__DOT__dmem__DOT__mem__v0.enqueue(__VdlyVal__top__DOT__dmem__DOT__mem__v1, (IData)(__VdlyDim0__top__DOT__dmem__DOT__mem__v1));
                    __VdlyVal__top__DOT__dmem__DOT__mem__v2 
                        = (0xffU & (vlSelfRef.top__DOT__rs2_data 
                                    >> 8U));
                    __VdlyDim0__top__DOT__dmem__DOT__mem__v2 
                        = (0x1fffU & ((IData)(1U) + vlSelfRef.top__DOT__alu_result));
                    vlSelfRef.__VdlyCommitQueue__top__DOT__dmem__DOT__mem__v0.enqueue(__VdlyVal__top__DOT__dmem__DOT__mem__v2, (IData)(__VdlyDim0__top__DOT__dmem__DOT__mem__v2));
                }
            } else if ((2U == (IData)(vlSelfRef.top__DOT__mem_size))) {
                if ((0x2000U > ((IData)(3U) + vlSelfRef.top__DOT__alu_result))) {
                    __VdlyVal__top__DOT__dmem__DOT__mem__v3 
                        = (0xffU & vlSelfRef.top__DOT__rs2_data);
                    __VdlyDim0__top__DOT__dmem__DOT__mem__v3 
                        = (0x1fffU & vlSelfRef.top__DOT__alu_result);
                    vlSelfRef.__VdlyCommitQueue__top__DOT__dmem__DOT__mem__v0.enqueue(__VdlyVal__top__DOT__dmem__DOT__mem__v3, (IData)(__VdlyDim0__top__DOT__dmem__DOT__mem__v3));
                    __VdlyVal__top__DOT__dmem__DOT__mem__v4 
                        = (0xffU & (vlSelfRef.top__DOT__rs2_data 
                                    >> 8U));
                    __VdlyDim0__top__DOT__dmem__DOT__mem__v4 
                        = (0x1fffU & ((IData)(1U) + vlSelfRef.top__DOT__alu_result));
                    vlSelfRef.__VdlyCommitQueue__top__DOT__dmem__DOT__mem__v0.enqueue(__VdlyVal__top__DOT__dmem__DOT__mem__v4, (IData)(__VdlyDim0__top__DOT__dmem__DOT__mem__v4));
                    __VdlyVal__top__DOT__dmem__DOT__mem__v5 
                        = (0xffU & (vlSelfRef.top__DOT__rs2_data 
                                    >> 0x10U));
                    __VdlyDim0__top__DOT__dmem__DOT__mem__v5 
                        = (0x1fffU & ((IData)(2U) + vlSelfRef.top__DOT__alu_result));
                    vlSelfRef.__VdlyCommitQueue__top__DOT__dmem__DOT__mem__v0.enqueue(__VdlyVal__top__DOT__dmem__DOT__mem__v5, (IData)(__VdlyDim0__top__DOT__dmem__DOT__mem__v5));
                    __VdlyVal__top__DOT__dmem__DOT__mem__v6 
                        = (vlSelfRef.top__DOT__rs2_data 
                           >> 0x18U);
                    __VdlyDim0__top__DOT__dmem__DOT__mem__v6 
                        = (0x1fffU & ((IData)(3U) + vlSelfRef.top__DOT__alu_result));
                    vlSelfRef.__VdlyCommitQueue__top__DOT__dmem__DOT__mem__v0.enqueue(__VdlyVal__top__DOT__dmem__DOT__mem__v6, (IData)(__VdlyDim0__top__DOT__dmem__DOT__mem__v6));
                }
            }
        }
    } else {
        vlSelfRef.top__DOT__dmem__DOT__unnamedblk1__DOT__i = 0U;
        while (VL_GTS_III(32, 0x2000U, vlSelfRef.top__DOT__dmem__DOT__unnamedblk1__DOT__i)) {
            __VdlyDim0__top__DOT__dmem__DOT__mem__v7 
                = (0x1fffU & vlSelfRef.top__DOT__dmem__DOT__unnamedblk1__DOT__i);
            vlSelfRef.__VdlyCommitQueue__top__DOT__dmem__DOT__mem__v0.enqueue(0U, (IData)(__VdlyDim0__top__DOT__dmem__DOT__mem__v7));
            vlSelfRef.top__DOT__dmem__DOT__unnamedblk1__DOT__i 
                = ((IData)(1U) + vlSelfRef.top__DOT__dmem__DOT__unnamedblk1__DOT__i);
        }
    }
    if (vlSelfRef.rst_ni) {
        if (((IData)(vlSelfRef.top__DOT__rf_wen) & 
             (0U != (0x1fU & (vlSelfRef.top__DOT__instr 
                              >> 7U))))) {
            __VdlyVal__top__DOT__regfile__DOT__rf_reg__v0 
                = ((0U == (IData)(vlSelfRef.top__DOT__rf_wdata_sel))
                    ? vlSelfRef.top__DOT__alu_result
                    : ((1U == (IData)(vlSelfRef.top__DOT__rf_wdata_sel))
                        ? vlSelfRef.top__DOT__dmem__DOT__rdata_aligned
                        : ((2U == (IData)(vlSelfRef.top__DOT__rf_wdata_sel))
                            ? ((IData)(4U) + vlSelfRef.top__DOT__pcunit__DOT__pc_q)
                            : vlSelfRef.top__DOT__alu_result)));
            __VdlyDim0__top__DOT__regfile__DOT__rf_reg__v0 
                = (0x1fU & (vlSelfRef.top__DOT__instr 
                            >> 7U));
            __VdlySet__top__DOT__regfile__DOT__rf_reg__v0 = 1U;
        }
    } else {
        __VdlySet__top__DOT__regfile__DOT__rf_reg__v1 = 1U;
    }
    vlSelfRef.__VdlyCommitQueue__top__DOT__dmem__DOT__mem__v0.commit(vlSelfRef.top__DOT__dmem__DOT__mem);
    if (__VdlySet__top__DOT__regfile__DOT__rf_reg__v0) {
        vlSelfRef.top__DOT__regfile__DOT__rf_reg[__VdlyDim0__top__DOT__regfile__DOT__rf_reg__v0] 
            = __VdlyVal__top__DOT__regfile__DOT__rf_reg__v0;
    }
    if (__VdlySet__top__DOT__regfile__DOT__rf_reg__v1) {
        vlSelfRef.top__DOT__regfile__DOT__rf_reg[0U] = 0U;
        vlSelfRef.top__DOT__regfile__DOT__rf_reg[1U] = 0U;
        vlSelfRef.top__DOT__regfile__DOT__rf_reg[2U] = 0U;
        vlSelfRef.top__DOT__regfile__DOT__rf_reg[3U] = 0U;
        vlSelfRef.top__DOT__regfile__DOT__rf_reg[4U] = 0U;
        vlSelfRef.top__DOT__regfile__DOT__rf_reg[5U] = 0U;
        vlSelfRef.top__DOT__regfile__DOT__rf_reg[6U] = 0U;
        vlSelfRef.top__DOT__regfile__DOT__rf_reg[7U] = 0U;
        vlSelfRef.top__DOT__regfile__DOT__rf_reg[8U] = 0U;
        vlSelfRef.top__DOT__regfile__DOT__rf_reg[9U] = 0U;
        vlSelfRef.top__DOT__regfile__DOT__rf_reg[0xaU] = 0U;
        vlSelfRef.top__DOT__regfile__DOT__rf_reg[0xbU] = 0U;
        vlSelfRef.top__DOT__regfile__DOT__rf_reg[0xcU] = 0U;
        vlSelfRef.top__DOT__regfile__DOT__rf_reg[0xdU] = 0U;
        vlSelfRef.top__DOT__regfile__DOT__rf_reg[0xeU] = 0U;
        vlSelfRef.top__DOT__regfile__DOT__rf_reg[0xfU] = 0U;
        vlSelfRef.top__DOT__regfile__DOT__rf_reg[0x10U] = 0U;
        vlSelfRef.top__DOT__regfile__DOT__rf_reg[0x11U] = 0U;
        vlSelfRef.top__DOT__regfile__DOT__rf_reg[0x12U] = 0U;
        vlSelfRef.top__DOT__regfile__DOT__rf_reg[0x13U] = 0U;
        vlSelfRef.top__DOT__regfile__DOT__rf_reg[0x14U] = 0U;
        vlSelfRef.top__DOT__regfile__DOT__rf_reg[0x15U] = 0U;
        vlSelfRef.top__DOT__regfile__DOT__rf_reg[0x16U] = 0U;
        vlSelfRef.top__DOT__regfile__DOT__rf_reg[0x17U] = 0U;
        vlSelfRef.top__DOT__regfile__DOT__rf_reg[0x18U] = 0U;
        vlSelfRef.top__DOT__regfile__DOT__rf_reg[0x19U] = 0U;
        vlSelfRef.top__DOT__regfile__DOT__rf_reg[0x1aU] = 0U;
        vlSelfRef.top__DOT__regfile__DOT__rf_reg[0x1bU] = 0U;
        vlSelfRef.top__DOT__regfile__DOT__rf_reg[0x1cU] = 0U;
        vlSelfRef.top__DOT__regfile__DOT__rf_reg[0x1dU] = 0U;
        vlSelfRef.top__DOT__regfile__DOT__rf_reg[0x1eU] = 0U;
        vlSelfRef.top__DOT__regfile__DOT__rf_reg[0x1fU] = 0U;
    }
    vlSelfRef.a0_o = vlSelfRef.top__DOT__regfile__DOT__rf_reg
        [0xaU];
}

VL_INLINE_OPT void Vdut___024root___nba_sequent__TOP__1(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___nba_sequent__TOP__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__instr = ((vlSelfRef.top__DOT__imem__DOT__mem
                                  [(3U | (0xffcU & vlSelfRef.top__DOT__pcunit__DOT__pc_q))] 
                                  << 0x18U) | ((vlSelfRef.top__DOT__imem__DOT__mem
                                                [(2U 
                                                  | (0xffcU 
                                                     & vlSelfRef.top__DOT__pcunit__DOT__pc_q))] 
                                                << 0x10U) 
                                               | ((vlSelfRef.top__DOT__imem__DOT__mem
                                                   [
                                                   (1U 
                                                    | (0xffcU 
                                                       & vlSelfRef.top__DOT__pcunit__DOT__pc_q))] 
                                                   << 8U) 
                                                  | vlSelfRef.top__DOT__imem__DOT__mem
                                                  [
                                                  (0xffcU 
                                                   & vlSelfRef.top__DOT__pcunit__DOT__pc_q)])));
    vlSelfRef.top__DOT__rf_wen = 0U;
    vlSelfRef.top__DOT__controller__DOT__imm_type_o = 0U;
    vlSelfRef.top__DOT__mem_wen = 0U;
    vlSelfRef.top__DOT__illegal_instr = 0U;
    vlSelfRef.top__DOT__rf_wdata_sel = 0U;
    vlSelfRef.top__DOT__mem_signed = 1U;
    vlSelfRef.top__DOT__mem_size = (7U & (vlSelfRef.top__DOT__instr 
                                          >> 0xcU));
    vlSelfRef.top__DOT__alu_op = 0U;
    vlSelfRef.top__DOT__alu_src1_sel = 0U;
    if ((1U & (~ (vlSelfRef.top__DOT__instr >> 6U)))) {
        if ((0x20U & vlSelfRef.top__DOT__instr)) {
            if ((1U & (~ (vlSelfRef.top__DOT__instr 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.top__DOT__instr 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.top__DOT__instr 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.top__DOT__instr)) {
                            if ((1U & vlSelfRef.top__DOT__instr)) {
                                vlSelfRef.top__DOT__mem_wen = 1U;
                                if ((((0U == (7U & 
                                              (vlSelfRef.top__DOT__instr 
                                               >> 0xcU))) 
                                      || (1U == (7U 
                                                 & (vlSelfRef.top__DOT__instr 
                                                    >> 0xcU)))) 
                                     || (2U == (7U 
                                                & (vlSelfRef.top__DOT__instr 
                                                   >> 0xcU))))) {
                                    vlSelfRef.top__DOT__mem_size 
                                        = (7U & (vlSelfRef.top__DOT__instr 
                                                 >> 0xcU));
                                }
                            }
                        }
                    }
                }
            }
            if ((0x10U & vlSelfRef.top__DOT__instr)) {
                if ((1U & (~ (vlSelfRef.top__DOT__instr 
                              >> 3U)))) {
                    if ((4U & vlSelfRef.top__DOT__instr)) {
                        if ((2U & vlSelfRef.top__DOT__instr)) {
                            if ((1U & vlSelfRef.top__DOT__instr)) {
                                vlSelfRef.top__DOT__alu_op = 0xaU;
                            }
                        }
                    } else if ((2U & vlSelfRef.top__DOT__instr)) {
                        if ((1U & vlSelfRef.top__DOT__instr)) {
                            vlSelfRef.top__DOT__alu_op 
                                = ((0x4000U & vlSelfRef.top__DOT__instr)
                                    ? ((0x2000U & vlSelfRef.top__DOT__instr)
                                        ? ((0x1000U 
                                            & vlSelfRef.top__DOT__instr)
                                            ? 9U : 8U)
                                        : ((0x1000U 
                                            & vlSelfRef.top__DOT__instr)
                                            ? ((0x40000000U 
                                                & vlSelfRef.top__DOT__instr)
                                                ? 7U
                                                : 6U)
                                            : 5U)) : 
                                   ((0x2000U & vlSelfRef.top__DOT__instr)
                                     ? ((0x1000U & vlSelfRef.top__DOT__instr)
                                         ? 4U : 3U)
                                     : ((0x1000U & vlSelfRef.top__DOT__instr)
                                         ? 2U : ((0x40000000U 
                                                  & vlSelfRef.top__DOT__instr)
                                                  ? 1U
                                                  : 0U))));
                        }
                    }
                }
            }
        } else {
            if ((1U & (~ (vlSelfRef.top__DOT__instr 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.top__DOT__instr 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.top__DOT__instr 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.top__DOT__instr)) {
                            if ((1U & vlSelfRef.top__DOT__instr)) {
                                if ((0x4000U & vlSelfRef.top__DOT__instr)) {
                                    if ((1U & (~ (vlSelfRef.top__DOT__instr 
                                                  >> 0xdU)))) {
                                        vlSelfRef.top__DOT__mem_size 
                                            = (7U & 
                                               (vlSelfRef.top__DOT__instr 
                                                >> 0xcU));
                                    }
                                } else if ((0x2000U 
                                            & vlSelfRef.top__DOT__instr)) {
                                    if ((1U & (~ (vlSelfRef.top__DOT__instr 
                                                  >> 0xcU)))) {
                                        vlSelfRef.top__DOT__mem_size 
                                            = (7U & 
                                               (vlSelfRef.top__DOT__instr 
                                                >> 0xcU));
                                    }
                                } else {
                                    vlSelfRef.top__DOT__mem_size 
                                        = (7U & (vlSelfRef.top__DOT__instr 
                                                 >> 0xcU));
                                }
                            }
                        }
                    }
                }
            }
            if ((0x10U & vlSelfRef.top__DOT__instr)) {
                if ((1U & (~ (vlSelfRef.top__DOT__instr 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.top__DOT__instr 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.top__DOT__instr)) {
                            if ((1U & vlSelfRef.top__DOT__instr)) {
                                vlSelfRef.top__DOT__alu_op 
                                    = ((0x4000U & vlSelfRef.top__DOT__instr)
                                        ? ((0x2000U 
                                            & vlSelfRef.top__DOT__instr)
                                            ? ((0x1000U 
                                                & vlSelfRef.top__DOT__instr)
                                                ? 9U
                                                : 8U)
                                            : ((0x1000U 
                                                & vlSelfRef.top__DOT__instr)
                                                ? (
                                                   (0x40000000U 
                                                    & vlSelfRef.top__DOT__instr)
                                                    ? 7U
                                                    : 6U)
                                                : 5U))
                                        : ((0x2000U 
                                            & vlSelfRef.top__DOT__instr)
                                            ? ((0x1000U 
                                                & vlSelfRef.top__DOT__instr)
                                                ? 4U
                                                : 3U)
                                            : ((0x1000U 
                                                & vlSelfRef.top__DOT__instr)
                                                ? 2U
                                                : 0U)));
                            }
                        }
                    }
                }
            }
        }
        if ((1U & (~ (vlSelfRef.top__DOT__instr >> 5U)))) {
            if ((1U & (~ (vlSelfRef.top__DOT__instr 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.top__DOT__instr 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.top__DOT__instr 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.top__DOT__instr)) {
                            if ((1U & vlSelfRef.top__DOT__instr)) {
                                vlSelfRef.top__DOT__mem_signed 
                                    = (1U & (~ (vlSelfRef.top__DOT__instr 
                                                >> 0xeU)));
                            }
                        }
                    }
                }
            }
            if ((0x10U & vlSelfRef.top__DOT__instr)) {
                if ((1U & (~ (vlSelfRef.top__DOT__instr 
                              >> 3U)))) {
                    if ((4U & vlSelfRef.top__DOT__instr)) {
                        if ((2U & vlSelfRef.top__DOT__instr)) {
                            if ((1U & vlSelfRef.top__DOT__instr)) {
                                vlSelfRef.top__DOT__alu_src1_sel = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlSelfRef.top__DOT__alu_src2_sel = 0U;
    if ((0x40U & vlSelfRef.top__DOT__instr)) {
        if ((0x20U & vlSelfRef.top__DOT__instr)) {
            if ((1U & (~ (vlSelfRef.top__DOT__instr 
                          >> 4U)))) {
                if ((8U & vlSelfRef.top__DOT__instr)) {
                    if ((4U & vlSelfRef.top__DOT__instr)) {
                        if ((2U & vlSelfRef.top__DOT__instr)) {
                            if ((1U & vlSelfRef.top__DOT__instr)) {
                                vlSelfRef.top__DOT__rf_wen = 1U;
                                vlSelfRef.top__DOT__controller__DOT__imm_type_o = 4U;
                                vlSelfRef.top__DOT__rf_wdata_sel = 2U;
                            }
                        }
                    }
                } else if ((4U & vlSelfRef.top__DOT__instr)) {
                    if ((2U & vlSelfRef.top__DOT__instr)) {
                        if ((1U & vlSelfRef.top__DOT__instr)) {
                            vlSelfRef.top__DOT__rf_wen = 1U;
                            vlSelfRef.top__DOT__controller__DOT__imm_type_o = 0U;
                            vlSelfRef.top__DOT__rf_wdata_sel = 2U;
                        }
                    }
                } else if ((2U & vlSelfRef.top__DOT__instr)) {
                    if ((1U & vlSelfRef.top__DOT__instr)) {
                        vlSelfRef.top__DOT__controller__DOT__imm_type_o = 2U;
                    }
                }
                if ((1U & (~ (vlSelfRef.top__DOT__instr 
                              >> 3U)))) {
                    if ((4U & vlSelfRef.top__DOT__instr)) {
                        if ((2U & vlSelfRef.top__DOT__instr)) {
                            if ((1U & vlSelfRef.top__DOT__instr)) {
                                vlSelfRef.top__DOT__alu_src2_sel = 1U;
                            }
                        }
                    }
                }
            }
            if ((0x10U & vlSelfRef.top__DOT__instr)) {
                vlSelfRef.top__DOT__illegal_instr = 1U;
                vlSelfRef.top__DOT__imm = 0U;
            } else if ((8U & vlSelfRef.top__DOT__instr)) {
                if ((4U & vlSelfRef.top__DOT__instr)) {
                    if ((2U & vlSelfRef.top__DOT__instr)) {
                        if ((1U & (~ vlSelfRef.top__DOT__instr))) {
                            vlSelfRef.top__DOT__illegal_instr = 1U;
                        }
                        vlSelfRef.top__DOT__imm = (
                                                   (1U 
                                                    & vlSelfRef.top__DOT__instr)
                                                    ? 
                                                   (((- (IData)(
                                                                (vlSelfRef.top__DOT__instr 
                                                                 >> 0x1fU))) 
                                                     << 0x15U) 
                                                    | ((0x100000U 
                                                        & (vlSelfRef.top__DOT__instr 
                                                           >> 0xbU)) 
                                                       | ((0xff000U 
                                                           & vlSelfRef.top__DOT__instr) 
                                                          | ((0x800U 
                                                              & (vlSelfRef.top__DOT__instr 
                                                                 >> 9U)) 
                                                             | (0x7feU 
                                                                & (vlSelfRef.top__DOT__instr 
                                                                   >> 0x14U))))))
                                                    : 0U);
                    } else {
                        vlSelfRef.top__DOT__illegal_instr = 1U;
                        vlSelfRef.top__DOT__imm = 0U;
                    }
                } else {
                    vlSelfRef.top__DOT__illegal_instr = 1U;
                    vlSelfRef.top__DOT__imm = 0U;
                }
            } else if ((4U & vlSelfRef.top__DOT__instr)) {
                if ((2U & vlSelfRef.top__DOT__instr)) {
                    if ((1U & (~ vlSelfRef.top__DOT__instr))) {
                        vlSelfRef.top__DOT__illegal_instr = 1U;
                    }
                    vlSelfRef.top__DOT__imm = ((1U 
                                                & vlSelfRef.top__DOT__instr)
                                                ? (
                                                   ((- (IData)(
                                                               (vlSelfRef.top__DOT__instr 
                                                                >> 0x1fU))) 
                                                    << 0xcU) 
                                                   | (vlSelfRef.top__DOT__instr 
                                                      >> 0x14U))
                                                : 0U);
                } else {
                    vlSelfRef.top__DOT__illegal_instr = 1U;
                    vlSelfRef.top__DOT__imm = 0U;
                }
            } else if ((2U & vlSelfRef.top__DOT__instr)) {
                if ((1U & vlSelfRef.top__DOT__instr)) {
                    if ((1U & (~ (vlSelfRef.top__DOT__instr 
                                  >> 0xeU)))) {
                        if ((0x2000U & vlSelfRef.top__DOT__instr)) {
                            vlSelfRef.top__DOT__illegal_instr = 1U;
                        }
                    }
                    vlSelfRef.top__DOT__imm = (((- (IData)(
                                                           (vlSelfRef.top__DOT__instr 
                                                            >> 0x1fU))) 
                                                << 0xdU) 
                                               | ((0x1000U 
                                                   & (vlSelfRef.top__DOT__instr 
                                                      >> 0x13U)) 
                                                  | ((0x800U 
                                                      & (vlSelfRef.top__DOT__instr 
                                                         << 4U)) 
                                                     | ((0x7e0U 
                                                         & (vlSelfRef.top__DOT__instr 
                                                            >> 0x14U)) 
                                                        | (0x1eU 
                                                           & (vlSelfRef.top__DOT__instr 
                                                              >> 7U))))));
                } else {
                    vlSelfRef.top__DOT__illegal_instr = 1U;
                    vlSelfRef.top__DOT__imm = 0U;
                }
            } else {
                vlSelfRef.top__DOT__illegal_instr = 1U;
                vlSelfRef.top__DOT__imm = 0U;
            }
        } else {
            vlSelfRef.top__DOT__illegal_instr = 1U;
            vlSelfRef.top__DOT__imm = 0U;
        }
    } else {
        if ((0x20U & vlSelfRef.top__DOT__instr)) {
            if ((0x10U & vlSelfRef.top__DOT__instr)) {
                if ((1U & (~ (vlSelfRef.top__DOT__instr 
                              >> 3U)))) {
                    if ((4U & vlSelfRef.top__DOT__instr)) {
                        if ((2U & vlSelfRef.top__DOT__instr)) {
                            if ((1U & vlSelfRef.top__DOT__instr)) {
                                vlSelfRef.top__DOT__rf_wen = 1U;
                                vlSelfRef.top__DOT__controller__DOT__imm_type_o = 3U;
                                vlSelfRef.top__DOT__alu_src2_sel = 2U;
                            }
                        }
                    } else if ((2U & vlSelfRef.top__DOT__instr)) {
                        if ((1U & vlSelfRef.top__DOT__instr)) {
                            vlSelfRef.top__DOT__rf_wen = 1U;
                        }
                    }
                }
                if ((8U & vlSelfRef.top__DOT__instr)) {
                    vlSelfRef.top__DOT__illegal_instr = 1U;
                    vlSelfRef.top__DOT__imm = 0U;
                } else if ((4U & vlSelfRef.top__DOT__instr)) {
                    if ((2U & vlSelfRef.top__DOT__instr)) {
                        if ((1U & (~ vlSelfRef.top__DOT__instr))) {
                            vlSelfRef.top__DOT__illegal_instr = 1U;
                        }
                        vlSelfRef.top__DOT__imm = (
                                                   (1U 
                                                    & vlSelfRef.top__DOT__instr)
                                                    ? 
                                                   (0xfffff000U 
                                                    & vlSelfRef.top__DOT__instr)
                                                    : 0U);
                    } else {
                        vlSelfRef.top__DOT__illegal_instr = 1U;
                        vlSelfRef.top__DOT__imm = 0U;
                    }
                } else {
                    if ((2U & vlSelfRef.top__DOT__instr)) {
                        if ((1U & (~ vlSelfRef.top__DOT__instr))) {
                            vlSelfRef.top__DOT__illegal_instr = 1U;
                        }
                    } else {
                        vlSelfRef.top__DOT__illegal_instr = 1U;
                    }
                    vlSelfRef.top__DOT__imm = 0U;
                }
            } else {
                if ((1U & (~ (vlSelfRef.top__DOT__instr 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.top__DOT__instr 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.top__DOT__instr)) {
                            if ((1U & vlSelfRef.top__DOT__instr)) {
                                vlSelfRef.top__DOT__controller__DOT__imm_type_o = 1U;
                                vlSelfRef.top__DOT__alu_src2_sel = 1U;
                            }
                        }
                    }
                }
                if ((8U & vlSelfRef.top__DOT__instr)) {
                    vlSelfRef.top__DOT__illegal_instr = 1U;
                    vlSelfRef.top__DOT__imm = 0U;
                } else if ((4U & vlSelfRef.top__DOT__instr)) {
                    vlSelfRef.top__DOT__illegal_instr = 1U;
                    vlSelfRef.top__DOT__imm = 0U;
                } else if ((2U & vlSelfRef.top__DOT__instr)) {
                    if ((1U & vlSelfRef.top__DOT__instr)) {
                        if ((1U & (~ (((0U == (7U & 
                                               (vlSelfRef.top__DOT__instr 
                                                >> 0xcU))) 
                                       || (1U == (7U 
                                                  & (vlSelfRef.top__DOT__instr 
                                                     >> 0xcU)))) 
                                      || (2U == (7U 
                                                 & (vlSelfRef.top__DOT__instr 
                                                    >> 0xcU))))))) {
                            vlSelfRef.top__DOT__illegal_instr = 1U;
                        }
                        vlSelfRef.top__DOT__imm = (
                                                   ((- (IData)(
                                                               (vlSelfRef.top__DOT__instr 
                                                                >> 0x1fU))) 
                                                    << 0xcU) 
                                                   | ((0xfe0U 
                                                       & (vlSelfRef.top__DOT__instr 
                                                          >> 0x14U)) 
                                                      | (0x1fU 
                                                         & (vlSelfRef.top__DOT__instr 
                                                            >> 7U))));
                    } else {
                        vlSelfRef.top__DOT__illegal_instr = 1U;
                        vlSelfRef.top__DOT__imm = 0U;
                    }
                } else {
                    vlSelfRef.top__DOT__illegal_instr = 1U;
                    vlSelfRef.top__DOT__imm = 0U;
                }
            }
        } else if ((0x10U & vlSelfRef.top__DOT__instr)) {
            if ((1U & (~ (vlSelfRef.top__DOT__instr 
                          >> 3U)))) {
                if ((4U & vlSelfRef.top__DOT__instr)) {
                    if ((2U & vlSelfRef.top__DOT__instr)) {
                        if ((1U & vlSelfRef.top__DOT__instr)) {
                            vlSelfRef.top__DOT__rf_wen = 1U;
                            vlSelfRef.top__DOT__controller__DOT__imm_type_o = 3U;
                            vlSelfRef.top__DOT__alu_src2_sel = 2U;
                        }
                    }
                } else if ((2U & vlSelfRef.top__DOT__instr)) {
                    if ((1U & vlSelfRef.top__DOT__instr)) {
                        vlSelfRef.top__DOT__rf_wen = 1U;
                        vlSelfRef.top__DOT__controller__DOT__imm_type_o = 0U;
                        vlSelfRef.top__DOT__alu_src2_sel = 1U;
                    }
                }
            }
            if ((8U & vlSelfRef.top__DOT__instr)) {
                vlSelfRef.top__DOT__illegal_instr = 1U;
                vlSelfRef.top__DOT__imm = 0U;
            } else if ((4U & vlSelfRef.top__DOT__instr)) {
                if ((2U & vlSelfRef.top__DOT__instr)) {
                    if ((1U & (~ vlSelfRef.top__DOT__instr))) {
                        vlSelfRef.top__DOT__illegal_instr = 1U;
                    }
                    vlSelfRef.top__DOT__imm = ((1U 
                                                & vlSelfRef.top__DOT__instr)
                                                ? (0xfffff000U 
                                                   & vlSelfRef.top__DOT__instr)
                                                : 0U);
                } else {
                    vlSelfRef.top__DOT__illegal_instr = 1U;
                    vlSelfRef.top__DOT__imm = 0U;
                }
            } else if ((2U & vlSelfRef.top__DOT__instr)) {
                if ((1U & (~ vlSelfRef.top__DOT__instr))) {
                    vlSelfRef.top__DOT__illegal_instr = 1U;
                }
                vlSelfRef.top__DOT__imm = ((1U & vlSelfRef.top__DOT__instr)
                                            ? (((- (IData)(
                                                           (vlSelfRef.top__DOT__instr 
                                                            >> 0x1fU))) 
                                                << 0xcU) 
                                               | (vlSelfRef.top__DOT__instr 
                                                  >> 0x14U))
                                            : 0U);
            } else {
                vlSelfRef.top__DOT__illegal_instr = 1U;
                vlSelfRef.top__DOT__imm = 0U;
            }
        } else {
            if ((1U & (~ (vlSelfRef.top__DOT__instr 
                          >> 3U)))) {
                if ((1U & (~ (vlSelfRef.top__DOT__instr 
                              >> 2U)))) {
                    if ((2U & vlSelfRef.top__DOT__instr)) {
                        if ((1U & vlSelfRef.top__DOT__instr)) {
                            vlSelfRef.top__DOT__rf_wen = 1U;
                            vlSelfRef.top__DOT__controller__DOT__imm_type_o = 0U;
                            vlSelfRef.top__DOT__alu_src2_sel = 1U;
                        }
                    }
                }
            }
            if ((8U & vlSelfRef.top__DOT__instr)) {
                vlSelfRef.top__DOT__illegal_instr = 1U;
                vlSelfRef.top__DOT__imm = 0U;
            } else if ((4U & vlSelfRef.top__DOT__instr)) {
                vlSelfRef.top__DOT__illegal_instr = 1U;
                vlSelfRef.top__DOT__imm = 0U;
            } else if ((2U & vlSelfRef.top__DOT__instr)) {
                if ((1U & vlSelfRef.top__DOT__instr)) {
                    if ((0x4000U & vlSelfRef.top__DOT__instr)) {
                        if ((0x2000U & vlSelfRef.top__DOT__instr)) {
                            vlSelfRef.top__DOT__illegal_instr = 1U;
                        }
                    } else if ((0x2000U & vlSelfRef.top__DOT__instr)) {
                        if ((0x1000U & vlSelfRef.top__DOT__instr)) {
                            vlSelfRef.top__DOT__illegal_instr = 1U;
                        }
                    }
                    vlSelfRef.top__DOT__imm = (((- (IData)(
                                                           (vlSelfRef.top__DOT__instr 
                                                            >> 0x1fU))) 
                                                << 0xcU) 
                                               | (vlSelfRef.top__DOT__instr 
                                                  >> 0x14U));
                } else {
                    vlSelfRef.top__DOT__illegal_instr = 1U;
                    vlSelfRef.top__DOT__imm = 0U;
                }
            } else {
                vlSelfRef.top__DOT__illegal_instr = 1U;
                vlSelfRef.top__DOT__imm = 0U;
            }
        }
        if ((1U & (~ (vlSelfRef.top__DOT__instr >> 5U)))) {
            if ((1U & (~ (vlSelfRef.top__DOT__instr 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.top__DOT__instr 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.top__DOT__instr 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.top__DOT__instr)) {
                            if ((1U & vlSelfRef.top__DOT__instr)) {
                                vlSelfRef.top__DOT__rf_wdata_sel = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    VL_WRITEF_NX("instr_i: %b\nopcode_o: %b\nrd_addr_o: %b, rs1_addr_o: %b, rs2_addr_o: %b\nfunct3_o: %b, funct7_o: %b\nimm_debug: %b, imm_sign_extended: %11d\n",0,
                 32,vlSelfRef.top__DOT__instr,7,(0x7fU 
                                                 & vlSelfRef.top__DOT__instr),
                 5,(0x1fU & (vlSelfRef.top__DOT__instr 
                             >> 7U)),5,(0x1fU & (vlSelfRef.top__DOT__instr 
                                                 >> 0xfU)),
                 5,(0x1fU & (vlSelfRef.top__DOT__instr 
                             >> 0x14U)),3,(7U & (vlSelfRef.top__DOT__instr 
                                                 >> 0xcU)),
                 7,(vlSelfRef.top__DOT__instr >> 0x19U),
                 32,vlSelfRef.top__DOT__imm,32,vlSelfRef.top__DOT__imm);
}

VL_INLINE_OPT void Vdut___024root___nba_sequent__TOP__2(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___nba_sequent__TOP__2\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__pcunit__DOT__pc_q = ((IData)(vlSelfRef.rst_ni)
                                              ? vlSelfRef.top__DOT__pcunit__DOT__next_pc_o
                                              : 0U);
}

extern const VlUnpacked<CData/*0:0*/, 512> Vdut__ConstPool__TABLE_h4a44e999_0;

VL_INLINE_OPT void Vdut___024root___nba_comb__TOP__0(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___nba_comb__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*8:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelfRef.top__DOT__rs1_data = ((0U == (0x1fU & 
                                            (vlSelfRef.top__DOT__instr 
                                             >> 0xfU)))
                                     ? 0U : vlSelfRef.top__DOT__regfile__DOT__rf_reg
                                    [(0x1fU & (vlSelfRef.top__DOT__instr 
                                               >> 0xfU))]);
    vlSelfRef.top__DOT__rs2_data = ((0U == (0x1fU & 
                                            (vlSelfRef.top__DOT__instr 
                                             >> 0x14U)))
                                     ? 0U : vlSelfRef.top__DOT__regfile__DOT__rf_reg
                                    [(0x1fU & (vlSelfRef.top__DOT__instr 
                                               >> 0x14U))]);
    vlSelfRef.top__DOT__alu_src1 = ((0U == (IData)(vlSelfRef.top__DOT__alu_src1_sel))
                                     ? vlSelfRef.top__DOT__rs1_data
                                     : ((1U == (IData)(vlSelfRef.top__DOT__alu_src1_sel))
                                         ? vlSelfRef.top__DOT__pcunit__DOT__pc_q
                                         : vlSelfRef.top__DOT__rs1_data));
    vlSelfRef.top__DOT__alu_src2 = ((0U == (IData)(vlSelfRef.top__DOT__alu_src2_sel))
                                     ? vlSelfRef.top__DOT__rs2_data
                                     : ((1U == (IData)(vlSelfRef.top__DOT__alu_src2_sel))
                                         ? vlSelfRef.top__DOT__imm
                                         : ((2U == (IData)(vlSelfRef.top__DOT__alu_src2_sel))
                                             ? vlSelfRef.top__DOT__imm
                                             : vlSelfRef.top__DOT__rs2_data)));
    vlSelfRef.top__DOT__branch_eq = (vlSelfRef.top__DOT__rs1_data 
                                     == vlSelfRef.top__DOT__rs2_data);
    vlSelfRef.top__DOT__branch_lt = VL_LTS_III(32, vlSelfRef.top__DOT__rs1_data, vlSelfRef.top__DOT__rs2_data);
    vlSelfRef.top__DOT__branch_ltu = (vlSelfRef.top__DOT__rs1_data 
                                      < vlSelfRef.top__DOT__rs2_data);
    vlSelfRef.top__DOT__alu_result = ((8U & (IData)(vlSelfRef.top__DOT__alu_op))
                                       ? ((4U & (IData)(vlSelfRef.top__DOT__alu_op))
                                           ? 0U : (
                                                   (2U 
                                                    & (IData)(vlSelfRef.top__DOT__alu_op))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.top__DOT__alu_op))
                                                     ? 0U
                                                     : vlSelfRef.top__DOT__alu_src2)
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.top__DOT__alu_op))
                                                     ? 
                                                    (vlSelfRef.top__DOT__alu_src1 
                                                     & vlSelfRef.top__DOT__alu_src2)
                                                     : 
                                                    (vlSelfRef.top__DOT__alu_src1 
                                                     | vlSelfRef.top__DOT__alu_src2))))
                                       : ((4U & (IData)(vlSelfRef.top__DOT__alu_op))
                                           ? ((2U & (IData)(vlSelfRef.top__DOT__alu_op))
                                               ? ((1U 
                                                   & (IData)(vlSelfRef.top__DOT__alu_op))
                                                   ? 
                                                  VL_SHIFTRS_III(32,32,5, vlSelfRef.top__DOT__alu_src1, 
                                                                 (0x1fU 
                                                                  & vlSelfRef.top__DOT__alu_src2))
                                                   : 
                                                  (vlSelfRef.top__DOT__alu_src1 
                                                   >> 
                                                   (0x1fU 
                                                    & vlSelfRef.top__DOT__alu_src2)))
                                               : ((1U 
                                                   & (IData)(vlSelfRef.top__DOT__alu_op))
                                                   ? 
                                                  (vlSelfRef.top__DOT__alu_src1 
                                                   ^ vlSelfRef.top__DOT__alu_src2)
                                                   : 
                                                  (vlSelfRef.top__DOT__alu_src1 
                                                   < vlSelfRef.top__DOT__alu_src2)))
                                           : ((2U & (IData)(vlSelfRef.top__DOT__alu_op))
                                               ? ((1U 
                                                   & (IData)(vlSelfRef.top__DOT__alu_op))
                                                   ? 
                                                  VL_LTS_III(32, vlSelfRef.top__DOT__alu_src1, vlSelfRef.top__DOT__alu_src2)
                                                   : 
                                                  (vlSelfRef.top__DOT__alu_src1 
                                                   << 
                                                   (0x1fU 
                                                    & vlSelfRef.top__DOT__alu_src2)))
                                               : ((1U 
                                                   == (IData)(vlSelfRef.top__DOT__alu_op))
                                                   ? 
                                                  (vlSelfRef.top__DOT__alu_src1 
                                                   - vlSelfRef.top__DOT__alu_src2)
                                                   : 
                                                  (vlSelfRef.top__DOT__alu_src1 
                                                   + vlSelfRef.top__DOT__alu_src2)))));
    __Vtableidx1 = (((IData)(vlSelfRef.top__DOT__branch_eq) 
                     << 8U) | ((0x80U & ((~ (IData)(vlSelfRef.top__DOT__branch_eq)) 
                                         << 7U)) | 
                               (((IData)(vlSelfRef.top__DOT__branch_lt) 
                                 << 6U) | ((0x20U & 
                                            ((~ (IData)(vlSelfRef.top__DOT__branch_lt)) 
                                             << 5U)) 
                                           | (((IData)(vlSelfRef.top__DOT__branch_ltu) 
                                               << 4U) 
                                              | ((8U 
                                                  & ((~ (IData)(vlSelfRef.top__DOT__branch_ltu)) 
                                                     << 3U)) 
                                                 | (7U 
                                                    & (vlSelfRef.top__DOT__instr 
                                                       >> 0xcU))))))));
    vlSelfRef.top__DOT__branch__DOT__branch_taken_o 
        = Vdut__ConstPool__TABLE_h4a44e999_0[__Vtableidx1];
    vlSelfRef.top__DOT__next_pc_sel = 0U;
    if ((0x40U & vlSelfRef.top__DOT__instr)) {
        if ((0x20U & vlSelfRef.top__DOT__instr)) {
            if ((1U & (~ (vlSelfRef.top__DOT__instr 
                          >> 4U)))) {
                if ((8U & vlSelfRef.top__DOT__instr)) {
                    if ((4U & vlSelfRef.top__DOT__instr)) {
                        if ((2U & vlSelfRef.top__DOT__instr)) {
                            if ((1U & vlSelfRef.top__DOT__instr)) {
                                vlSelfRef.top__DOT__next_pc_sel = 2U;
                            }
                        }
                    }
                } else if ((4U & vlSelfRef.top__DOT__instr)) {
                    if ((2U & vlSelfRef.top__DOT__instr)) {
                        if ((1U & vlSelfRef.top__DOT__instr)) {
                            vlSelfRef.top__DOT__next_pc_sel = 3U;
                        }
                    }
                } else if ((2U & vlSelfRef.top__DOT__instr)) {
                    if ((1U & vlSelfRef.top__DOT__instr)) {
                        if ((0x4000U & vlSelfRef.top__DOT__instr)) {
                            vlSelfRef.top__DOT__next_pc_sel 
                                = ((0x2000U & vlSelfRef.top__DOT__instr)
                                    ? ((0x1000U & vlSelfRef.top__DOT__instr)
                                        ? ((IData)(vlSelfRef.top__DOT__branch_ltu)
                                            ? 0U : 1U)
                                        : ((IData)(vlSelfRef.top__DOT__branch_ltu)
                                            ? 1U : 0U))
                                    : ((0x1000U & vlSelfRef.top__DOT__instr)
                                        ? ((IData)(vlSelfRef.top__DOT__branch_lt)
                                            ? 0U : 1U)
                                        : ((IData)(vlSelfRef.top__DOT__branch_lt)
                                            ? 1U : 0U)));
                        } else if ((1U & (~ (vlSelfRef.top__DOT__instr 
                                             >> 0xdU)))) {
                            vlSelfRef.top__DOT__next_pc_sel 
                                = ((0x1000U & vlSelfRef.top__DOT__instr)
                                    ? ((IData)(vlSelfRef.top__DOT__branch_eq)
                                        ? 0U : 1U) : 
                                   ((IData)(vlSelfRef.top__DOT__branch_eq)
                                     ? 1U : 0U));
                        }
                    }
                }
            }
        }
    }
    vlSelfRef.top__DOT__dmem__DOT__rdata_aligned = 
        ((0U == (IData)(vlSelfRef.top__DOT__mem_size))
          ? (((- (IData)(((IData)(vlSelfRef.top__DOT__mem_signed) 
                          & (vlSelfRef.top__DOT__dmem__DOT__mem
                             [(0x1fffU & vlSelfRef.top__DOT__alu_result)] 
                             >> 7U)))) << 8U) | vlSelfRef.top__DOT__dmem__DOT__mem
             [(0x1fffU & vlSelfRef.top__DOT__alu_result)])
          : ((1U == (IData)(vlSelfRef.top__DOT__mem_size))
              ? ((0x2000U > ((IData)(1U) + vlSelfRef.top__DOT__alu_result))
                  ? (((- (IData)(((IData)(vlSelfRef.top__DOT__mem_signed) 
                                  & (vlSelfRef.top__DOT__dmem__DOT__mem
                                     [(0x1fffU & ((IData)(1U) 
                                                  + vlSelfRef.top__DOT__alu_result))] 
                                     >> 7U)))) << 0x10U) 
                     | ((vlSelfRef.top__DOT__dmem__DOT__mem
                         [(0x1fffU & ((IData)(1U) + vlSelfRef.top__DOT__alu_result))] 
                         << 8U) | vlSelfRef.top__DOT__dmem__DOT__mem
                        [(0x1fffU & vlSelfRef.top__DOT__alu_result)]))
                  : 0U) : ((2U == (IData)(vlSelfRef.top__DOT__mem_size))
                            ? ((0x2000U > ((IData)(3U) 
                                           + vlSelfRef.top__DOT__alu_result))
                                ? ((vlSelfRef.top__DOT__dmem__DOT__mem
                                    [(0x1fffU & ((IData)(3U) 
                                                 + vlSelfRef.top__DOT__alu_result))] 
                                    << 0x18U) | ((vlSelfRef.top__DOT__dmem__DOT__mem
                                                  [
                                                  (0x1fffU 
                                                   & ((IData)(2U) 
                                                      + vlSelfRef.top__DOT__alu_result))] 
                                                  << 0x10U) 
                                                 | ((vlSelfRef.top__DOT__dmem__DOT__mem
                                                     [
                                                     (0x1fffU 
                                                      & ((IData)(1U) 
                                                         + vlSelfRef.top__DOT__alu_result))] 
                                                     << 8U) 
                                                    | vlSelfRef.top__DOT__dmem__DOT__mem
                                                    [
                                                    (0x1fffU 
                                                     & vlSelfRef.top__DOT__alu_result)])))
                                : 0U) : 0U)));
    vlSelfRef.top__DOT__pcunit__DOT__next_pc_o = ((4U 
                                                   & (IData)(vlSelfRef.top__DOT__next_pc_sel))
                                                   ? 
                                                  ((IData)(4U) 
                                                   + vlSelfRef.top__DOT__pcunit__DOT__pc_q)
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlSelfRef.top__DOT__next_pc_sel))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.top__DOT__next_pc_sel))
                                                     ? 
                                                    (0xfffffffeU 
                                                     & vlSelfRef.top__DOT__alu_result)
                                                     : 
                                                    (vlSelfRef.top__DOT__pcunit__DOT__pc_q 
                                                     + vlSelfRef.top__DOT__imm))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.top__DOT__next_pc_sel))
                                                     ? 
                                                    (vlSelfRef.top__DOT__pcunit__DOT__pc_q 
                                                     + vlSelfRef.top__DOT__imm)
                                                     : 
                                                    ((IData)(4U) 
                                                     + vlSelfRef.top__DOT__pcunit__DOT__pc_q))));
}

void Vdut___024root___eval_triggers__act(Vdut___024root* vlSelf);

bool Vdut___024root___eval_phase__act(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_phase__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vdut___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vdut___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vdut___024root___eval_phase__nba(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_phase__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vdut___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdut___024root___dump_triggers__nba(Vdut___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vdut___024root___dump_triggers__act(Vdut___024root* vlSelf);
#endif  // VL_DEBUG

void Vdut___024root___eval(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval\n"); );
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
            Vdut___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/Users/michaelli/Documents/GitHub/iac-riscv-cw-24/rtl/top.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vdut___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/Users/michaelli/Documents/GitHub/iac-riscv-cw-24/rtl/top.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vdut___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vdut___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vdut___024root___eval_debug_assertions(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_debug_assertions\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.clk_i & 0xfeU))) {
        Verilated::overWidthError("clk_i");}
    if (VL_UNLIKELY((vlSelfRef.rst_ni & 0xfeU))) {
        Verilated::overWidthError("rst_ni");}
}
#endif  // VL_DEBUG
