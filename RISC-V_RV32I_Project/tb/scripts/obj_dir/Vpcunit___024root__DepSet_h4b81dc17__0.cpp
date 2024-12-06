// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpcunit.h for the primary calling header

#include "verilated.h"

#include "Vpcunit___024root.h"

VL_INLINE_OPT void Vpcunit___024root___sequent__TOP__0(Vpcunit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpcunit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpcunit___024root___sequent__TOP__0\n"); );
    // Body
    vlSelf->pcunit__DOT__pc_q = ((IData)(vlSelf->rst_ni)
                                  ? vlSelf->next_pc_o
                                  : 0U);
    vlSelf->pc_o = vlSelf->pcunit__DOT__pc_q;
}

VL_INLINE_OPT void Vpcunit___024root___combo__TOP__0(Vpcunit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpcunit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpcunit___024root___combo__TOP__0\n"); );
    // Body
    vlSelf->next_pc_o = ((IData)(4U) + vlSelf->pcunit__DOT__pc_q);
    vlSelf->next_pc_o = ((4U & (IData)(vlSelf->next_pc_sel_i))
                          ? ((IData)(4U) + vlSelf->pcunit__DOT__pc_q)
                          : ((2U & (IData)(vlSelf->next_pc_sel_i))
                              ? ((1U & (IData)(vlSelf->next_pc_sel_i))
                                  ? (0xfffffffeU & vlSelf->alu_result_i)
                                  : (vlSelf->pcunit__DOT__pc_q 
                                     + vlSelf->imm_i))
                              : ((1U & (IData)(vlSelf->next_pc_sel_i))
                                  ? (vlSelf->pcunit__DOT__pc_q 
                                     + vlSelf->imm_i)
                                  : ((IData)(4U) + vlSelf->pcunit__DOT__pc_q))));
}

void Vpcunit___024root___eval(Vpcunit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpcunit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpcunit___024root___eval\n"); );
    // Body
    if ((((IData)(vlSelf->clk_i) & (~ (IData)(vlSelf->__Vclklast__TOP__clk_i))) 
         | ((~ (IData)(vlSelf->rst_ni)) & (IData)(vlSelf->__Vclklast__TOP__rst_ni)))) {
        Vpcunit___024root___sequent__TOP__0(vlSelf);
    }
    Vpcunit___024root___combo__TOP__0(vlSelf);
    // Final
    vlSelf->__Vclklast__TOP__clk_i = vlSelf->clk_i;
    vlSelf->__Vclklast__TOP__rst_ni = vlSelf->rst_ni;
}

#ifdef VL_DEBUG
void Vpcunit___024root___eval_debug_assertions(Vpcunit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpcunit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpcunit___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk_i & 0xfeU))) {
        Verilated::overWidthError("clk_i");}
    if (VL_UNLIKELY((vlSelf->rst_ni & 0xfeU))) {
        Verilated::overWidthError("rst_ni");}
    if (VL_UNLIKELY((vlSelf->next_pc_sel_i & 0xf8U))) {
        Verilated::overWidthError("next_pc_sel_i");}
}
#endif  // VL_DEBUG
