// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Valu.h for the primary calling header

#include "verilated.h"

#include "Valu___024root.h"

VL_INLINE_OPT void Valu___024root___combo__TOP__0(Valu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu___024root___combo__TOP__0\n"); );
    // Body
    vlSelf->aluResult = ((4U & (IData)(vlSelf->aluControl))
                          ? ((2U & (IData)(vlSelf->aluControl))
                              ? ((1U & (IData)(vlSelf->aluControl))
                                  ? (vlSelf->srcA >> 
                                     (0x1fU & vlSelf->srcB))
                                  : (vlSelf->srcA << 
                                     (0x1fU & vlSelf->srcB)))
                              : ((1U & (IData)(vlSelf->aluControl))
                                  ? (VL_LTS_III(32, vlSelf->srcA, vlSelf->srcB)
                                      ? 1U : 0U) : vlSelf->srcB))
                          : ((2U & (IData)(vlSelf->aluControl))
                              ? ((1U & (IData)(vlSelf->aluControl))
                                  ? (vlSelf->srcA | vlSelf->srcB)
                                  : (vlSelf->srcA & vlSelf->srcB))
                              : ((1U & (IData)(vlSelf->aluControl))
                                  ? (vlSelf->srcA - vlSelf->srcB)
                                  : (vlSelf->srcA + vlSelf->srcB))));
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
    if (VL_UNLIKELY((vlSelf->aluControl & 0xf8U))) {
        Verilated::overWidthError("aluControl");}
}
#endif  // VL_DEBUG
