// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vimem.h for the primary calling header

#include "verilated.h"

#include "Vimem___024root.h"

VL_INLINE_OPT void Vimem___024root___sequent__TOP__0(Vimem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vimem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vimem___024root___sequent__TOP__0\n"); );
    // Body
    vlSelf->rdata_o = ((vlSelf->imem__DOT__mem[(3U 
                                                | (0xffcU 
                                                   & vlSelf->addr_i))] 
                        << 0x18U) | ((vlSelf->imem__DOT__mem
                                      [(2U | (0xffcU 
                                              & vlSelf->addr_i))] 
                                      << 0x10U) | (
                                                   (vlSelf->imem__DOT__mem
                                                    [
                                                    (1U 
                                                     | (0xffcU 
                                                        & vlSelf->addr_i))] 
                                                    << 8U) 
                                                   | vlSelf->imem__DOT__mem
                                                   [
                                                   (0xffcU 
                                                    & vlSelf->addr_i)])));
}

void Vimem___024root___eval(Vimem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vimem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vimem___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk_i) & (~ (IData)(vlSelf->__Vclklast__TOP__clk_i)))) {
        Vimem___024root___sequent__TOP__0(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk_i = vlSelf->clk_i;
}

#ifdef VL_DEBUG
void Vimem___024root___eval_debug_assertions(Vimem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vimem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vimem___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk_i & 0xfeU))) {
        Verilated::overWidthError("clk_i");}
}
#endif  // VL_DEBUG
