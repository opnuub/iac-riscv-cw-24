// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPRegFetch.h for the primary calling header

#include "verilated.h"

#include "VPRegFetch___024root.h"

VL_INLINE_OPT void VPRegFetch___024root___sequent__TOP__0(VPRegFetch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPRegFetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegFetch___024root___sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ __Vdlyvval__PRegFetch__DOT__rom_array__v0;
    IData/*31:0*/ __Vdlyvval__PRegFetch__DOT__rom_array__v1;
    IData/*31:0*/ __Vdlyvval__PRegFetch__DOT__rom_array__v2;
    // Body
    __Vdlyvval__PRegFetch__DOT__rom_array__v0 = vlSelf->instr;
    __Vdlyvval__PRegFetch__DOT__rom_array__v1 = vlSelf->PCf;
    __Vdlyvval__PRegFetch__DOT__rom_array__v2 = vlSelf->PCPlus4F;
    vlSelf->PRegFetch__DOT__rom_array[0U] = __Vdlyvval__PRegFetch__DOT__rom_array__v0;
    vlSelf->PRegFetch__DOT__rom_array[1U] = __Vdlyvval__PRegFetch__DOT__rom_array__v1;
    vlSelf->PRegFetch__DOT__rom_array[2U] = __Vdlyvval__PRegFetch__DOT__rom_array__v2;
    vlSelf->InstrD = vlSelf->PRegFetch__DOT__rom_array
        [0U];
    vlSelf->PCd = vlSelf->PRegFetch__DOT__rom_array
        [1U];
    vlSelf->PCPlus4D = vlSelf->PRegFetch__DOT__rom_array
        [2U];
}

void VPRegFetch___024root___eval(VPRegFetch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPRegFetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegFetch___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        VPRegFetch___024root___sequent__TOP__0(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

#ifdef VL_DEBUG
void VPRegFetch___024root___eval_debug_assertions(VPRegFetch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPRegFetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegFetch___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
}
#endif  // VL_DEBUG
