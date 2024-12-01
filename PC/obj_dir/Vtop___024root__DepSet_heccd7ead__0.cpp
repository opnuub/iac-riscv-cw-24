// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

VL_INLINE_OPT void Vtop___024root___sequent__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__1\n"); );
    // Init
    IData/*31:0*/ __Vdlyvval__top__DOT__PRegFetch__DOT__rom_array__v0;
    IData/*31:0*/ __Vdlyvval__top__DOT__PRegFetch__DOT__rom_array__v1;
    IData/*31:0*/ __Vdlyvval__top__DOT__PRegFetch__DOT__rom_array__v2;
    // Body
    vlSelf->InstrD = vlSelf->top__DOT__PRegFetch__DOT__rom_array
        [0U];
    vlSelf->PCd = vlSelf->top__DOT__PRegFetch__DOT__rom_array
        [1U];
    vlSelf->PCPlus4D = vlSelf->top__DOT__PRegFetch__DOT__rom_array
        [2U];
    __Vdlyvval__top__DOT__PRegFetch__DOT__rom_array__v0 
        = ((IData)(0xaU) + vlSelf->top__DOT__PCf);
    __Vdlyvval__top__DOT__PRegFetch__DOT__rom_array__v1 
        = vlSelf->top__DOT__PCf;
    __Vdlyvval__top__DOT__PRegFetch__DOT__rom_array__v2 
        = ((IData)(4U) + vlSelf->top__DOT__PCf);
    vlSelf->top__DOT__PRegFetch__DOT__rom_array[0U] 
        = __Vdlyvval__top__DOT__PRegFetch__DOT__rom_array__v0;
    vlSelf->top__DOT__PRegFetch__DOT__rom_array[1U] 
        = __Vdlyvval__top__DOT__PRegFetch__DOT__rom_array__v1;
    vlSelf->top__DOT__PRegFetch__DOT__rom_array[2U] 
        = __Vdlyvval__top__DOT__PRegFetch__DOT__rom_array__v2;
}

VL_INLINE_OPT void Vtop___024root___sequent__TOP__2(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__2\n"); );
    // Body
    vlSelf->top__DOT__PCf = ((IData)(vlSelf->rst) ? 0U
                              : vlSelf->top__DOT__PCFp);
}

VL_INLINE_OPT void Vtop___024root___combo__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___combo__TOP__0\n"); );
    // Body
    vlSelf->top__DOT__PCFp = ((IData)(vlSelf->PCsrcE)
                               ? vlSelf->PCTargetE : 
                              ((IData)(4U) + vlSelf->top__DOT__PCf));
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vtop___024root___sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((IData)(vlSelf->rst) & (~ (IData)(vlSelf->__Vclklast__TOP__rst))))) {
        Vtop___024root___sequent__TOP__2(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    Vtop___024root___combo__TOP__0(vlSelf);
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->PCsrcE & 0xfeU))) {
        Verilated::overWidthError("PCsrcE");}
}
#endif  // VL_DEBUG
