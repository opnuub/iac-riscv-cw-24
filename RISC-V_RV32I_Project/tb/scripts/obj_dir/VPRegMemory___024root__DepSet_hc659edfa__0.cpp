// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPRegMemory.h for the primary calling header

#include "verilated.h"

#include "VPRegMemory___024root.h"

VL_INLINE_OPT void VPRegMemory___024root___sequent__TOP__0(VPRegMemory___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPRegMemory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegMemory___024root___sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ __Vdlyvval__PRegMemory__DOT__rom_array__v0;
    IData/*31:0*/ __Vdlyvval__PRegMemory__DOT__rom_array__v1;
    IData/*31:0*/ __Vdlyvval__PRegMemory__DOT__rom_array__v2;
    IData/*31:0*/ __Vdlyvval__PRegMemory__DOT__rom_array__v3;
    IData/*31:0*/ __Vdlyvval__PRegMemory__DOT__rom_array__v4;
    IData/*31:0*/ __Vdlyvval__PRegMemory__DOT__rom_array__v5;
    // Body
    __Vdlyvval__PRegMemory__DOT__rom_array__v0 = vlSelf->ALUResultM;
    __Vdlyvval__PRegMemory__DOT__rom_array__v1 = vlSelf->DMRd;
    __Vdlyvval__PRegMemory__DOT__rom_array__v2 = vlSelf->RdM;
    __Vdlyvval__PRegMemory__DOT__rom_array__v3 = vlSelf->PCPlus4M;
    __Vdlyvval__PRegMemory__DOT__rom_array__v4 = vlSelf->RegWriteM;
    __Vdlyvval__PRegMemory__DOT__rom_array__v5 = vlSelf->ResultSrcM;
    vlSelf->PRegMemory__DOT__rom_array[0U] = __Vdlyvval__PRegMemory__DOT__rom_array__v0;
    vlSelf->PRegMemory__DOT__rom_array[1U] = __Vdlyvval__PRegMemory__DOT__rom_array__v1;
    vlSelf->PRegMemory__DOT__rom_array[2U] = __Vdlyvval__PRegMemory__DOT__rom_array__v2;
    vlSelf->PRegMemory__DOT__rom_array[3U] = __Vdlyvval__PRegMemory__DOT__rom_array__v3;
    vlSelf->PRegMemory__DOT__rom_array[4U] = __Vdlyvval__PRegMemory__DOT__rom_array__v4;
    vlSelf->PRegMemory__DOT__rom_array[5U] = __Vdlyvval__PRegMemory__DOT__rom_array__v5;
    vlSelf->ALUResultW = vlSelf->PRegMemory__DOT__rom_array
        [0U];
    vlSelf->WriteDataW = vlSelf->PRegMemory__DOT__rom_array
        [1U];
    vlSelf->RdW = (0x1fU & vlSelf->PRegMemory__DOT__rom_array
                   [2U]);
    vlSelf->PCPlus4W = vlSelf->PRegMemory__DOT__rom_array
        [3U];
    vlSelf->RegWriteW = (1U & vlSelf->PRegMemory__DOT__rom_array
                         [4U]);
    vlSelf->ResultSrcW = (3U & vlSelf->PRegMemory__DOT__rom_array
                          [5U]);
}

void VPRegMemory___024root___eval(VPRegMemory___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPRegMemory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegMemory___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        VPRegMemory___024root___sequent__TOP__0(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

#ifdef VL_DEBUG
void VPRegMemory___024root___eval_debug_assertions(VPRegMemory___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPRegMemory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegMemory___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->RdM & 0xe0U))) {
        Verilated::overWidthError("RdM");}
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->RegWriteM & 0xfeU))) {
        Verilated::overWidthError("RegWriteM");}
    if (VL_UNLIKELY((vlSelf->ResultSrcM & 0xfcU))) {
        Verilated::overWidthError("ResultSrcM");}
}
#endif  // VL_DEBUG
