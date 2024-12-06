// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Valu.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Valu___024root.h"

VL_INLINE_OPT void Valu___024root___combo__TOP__0(Valu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu___024root___combo__TOP__0\n"); );
    // Body
    vlSelf->result_o = ((8U & (IData)(vlSelf->operator_i))
                         ? ((4U & (IData)(vlSelf->operator_i))
                             ? 0U : ((2U & (IData)(vlSelf->operator_i))
                                      ? ((1U & (IData)(vlSelf->operator_i))
                                          ? 0U : vlSelf->operand_b_i)
                                      : ((1U & (IData)(vlSelf->operator_i))
                                          ? (vlSelf->operand_a_i 
                                             & vlSelf->operand_b_i)
                                          : (vlSelf->operand_a_i 
                                             | vlSelf->operand_b_i))))
                         : ((4U & (IData)(vlSelf->operator_i))
                             ? ((2U & (IData)(vlSelf->operator_i))
                                 ? ((1U & (IData)(vlSelf->operator_i))
                                     ? VL_SHIFTRS_III(32,32,5, vlSelf->operand_a_i, 
                                                      (0x1fU 
                                                       & vlSelf->operand_b_i))
                                     : (vlSelf->operand_a_i 
                                        >> (0x1fU & vlSelf->operand_b_i)))
                                 : ((1U & (IData)(vlSelf->operator_i))
                                     ? (vlSelf->operand_a_i 
                                        ^ vlSelf->operand_b_i)
                                     : (vlSelf->operand_a_i 
                                        < vlSelf->operand_b_i)))
                             : ((2U & (IData)(vlSelf->operator_i))
                                 ? ((1U & (IData)(vlSelf->operator_i))
                                     ? VL_LTS_III(32, vlSelf->operand_a_i, vlSelf->operand_b_i)
                                     : (vlSelf->operand_a_i 
                                        << (0x1fU & vlSelf->operand_b_i)))
                                 : ((1U == (IData)(vlSelf->operator_i))
                                     ? (vlSelf->operand_a_i 
                                        - vlSelf->operand_b_i)
                                     : (vlSelf->operand_a_i 
                                        + vlSelf->operand_b_i)))));
}

void Valu___024root___eval(Valu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu___024root___eval\n"); );
    // Body
    Valu___024root___combo__TOP__0(vlSelf);
}

#ifdef VL_DEBUG
void Valu___024root___eval_debug_assertions(Valu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->operator_i & 0xf0U))) {
        Verilated::overWidthError("operator_i");}
}
#endif  // VL_DEBUG
