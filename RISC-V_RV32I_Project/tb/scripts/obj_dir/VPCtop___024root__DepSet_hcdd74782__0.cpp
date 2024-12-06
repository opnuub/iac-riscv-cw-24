// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPCtop.h for the primary calling header

#include "verilated.h"

#include "VPCtop___024root.h"

VL_INLINE_OPT void VPCtop___024root___sequent__TOP__0(VPCtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPCtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPCtop___024root___sequent__TOP__0\n"); );
    // Body
    vlSelf->PCPlus4D = vlSelf->PCtop__DOT__PRegFetch__DOT__rom_array
        [2U];
    vlSelf->PCd = vlSelf->PCtop__DOT__PRegFetch__DOT__rom_array
        [1U];
    vlSelf->InstrD = vlSelf->PCtop__DOT__PRegFetch__DOT__rom_array
        [0U];
    vlSelf->PCtop__DOT__Rd = ((vlSelf->PCtop__DOT__imem__DOT__mem
                               [(3U | (0xffcU & vlSelf->PCtop__DOT__PCf))] 
                               << 0x18U) | ((vlSelf->PCtop__DOT__imem__DOT__mem
                                             [(2U | 
                                               (0xffcU 
                                                & vlSelf->PCtop__DOT__PCf))] 
                                             << 0x10U) 
                                            | ((vlSelf->PCtop__DOT__imem__DOT__mem
                                                [(1U 
                                                  | (0xffcU 
                                                     & vlSelf->PCtop__DOT__PCf))] 
                                                << 8U) 
                                               | vlSelf->PCtop__DOT__imem__DOT__mem
                                               [(0xffcU 
                                                 & vlSelf->PCtop__DOT__PCf)])));
}

VL_INLINE_OPT void VPCtop___024root___sequent__TOP__1(VPCtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPCtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPCtop___024root___sequent__TOP__1\n"); );
    // Body
    vlSelf->PCtop__DOT__PCf = ((IData)(vlSelf->rst)
                                ? 0U : vlSelf->PCtop__DOT__PCFp);
    vlSelf->PCtop__DOT__PRegFetch__DOT__rom_array[0U] 
        = vlSelf->PCtop__DOT__Rd;
    vlSelf->PCtop__DOT__PRegFetch__DOT__rom_array[1U] 
        = vlSelf->PCtop__DOT__PCf;
    vlSelf->PCtop__DOT__PRegFetch__DOT__rom_array[2U] 
        = ((IData)(4U) + vlSelf->PCtop__DOT__PCf);
}

VL_INLINE_OPT void VPCtop___024root___combo__TOP__0(VPCtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPCtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPCtop___024root___combo__TOP__0\n"); );
    // Body
    vlSelf->PCtop__DOT__PCFp = ((IData)(vlSelf->PCsrcE)
                                 ? vlSelf->PCTargetE
                                 : ((IData)(4U) + vlSelf->PCtop__DOT__PCf));
}

void VPCtop___024root___eval(VPCtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPCtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPCtop___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        VPCtop___024root___sequent__TOP__0(vlSelf);
    }
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((IData)(vlSelf->rst) & (~ (IData)(vlSelf->__Vclklast__TOP__rst))))) {
        VPCtop___024root___sequent__TOP__1(vlSelf);
    }
    VPCtop___024root___combo__TOP__0(vlSelf);
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
}

#ifdef VL_DEBUG
void VPCtop___024root___eval_debug_assertions(VPCtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPCtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPCtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->PCsrcE & 0xfeU))) {
        Verilated::overWidthError("PCsrcE");}
}
#endif  // VL_DEBUG
