// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPRegFetch.h for the primary calling header

#include "verilated.h"

#include "VPRegFetch___024root.h"

VL_ATTR_COLD void VPRegFetch___024root___settle__TOP__0(VPRegFetch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPRegFetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegFetch___024root___settle__TOP__0\n"); );
    // Body
    vlSelf->InstrD = vlSelf->PRegFetch__DOT__rom_array
        [0U];
    vlSelf->PCd = vlSelf->PRegFetch__DOT__rom_array
        [1U];
    vlSelf->PCPlus4D = vlSelf->PRegFetch__DOT__rom_array
        [2U];
}

VL_ATTR_COLD void VPRegFetch___024root___eval_initial(VPRegFetch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPRegFetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegFetch___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void VPRegFetch___024root___eval_settle(VPRegFetch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPRegFetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegFetch___024root___eval_settle\n"); );
    // Body
    VPRegFetch___024root___settle__TOP__0(vlSelf);
}

VL_ATTR_COLD void VPRegFetch___024root___final(VPRegFetch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPRegFetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegFetch___024root___final\n"); );
}

VL_ATTR_COLD void VPRegFetch___024root___ctor_var_reset(VPRegFetch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPRegFetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegFetch___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->instr = VL_RAND_RESET_I(32);
    vlSelf->PCf = VL_RAND_RESET_I(32);
    vlSelf->PCPlus4F = VL_RAND_RESET_I(32);
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->PCPlus4D = VL_RAND_RESET_I(32);
    vlSelf->PCd = VL_RAND_RESET_I(32);
    vlSelf->InstrD = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<8; ++__Vi0) {
        vlSelf->PRegFetch__DOT__rom_array[__Vi0] = VL_RAND_RESET_I(32);
    }
}
