// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPRegExecute.h for the primary calling header

#include "verilated.h"

#include "VPRegExecute___024root.h"

VL_INLINE_OPT void VPRegExecute___024root___sequent__TOP__0(VPRegExecute___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPRegExecute__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegExecute___024root___sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ __Vdlyvval__PRegExecute__DOT__rom_array__v0;
    IData/*31:0*/ __Vdlyvval__PRegExecute__DOT__rom_array__v1;
    IData/*31:0*/ __Vdlyvval__PRegExecute__DOT__rom_array__v2;
    IData/*31:0*/ __Vdlyvval__PRegExecute__DOT__rom_array__v3;
    IData/*31:0*/ __Vdlyvval__PRegExecute__DOT__rom_array__v4;
    IData/*31:0*/ __Vdlyvval__PRegExecute__DOT__rom_array__v5;
    IData/*31:0*/ __Vdlyvval__PRegExecute__DOT__rom_array__v6;
    // Body
    __Vdlyvval__PRegExecute__DOT__rom_array__v0 = vlSelf->ALUout;
    __Vdlyvval__PRegExecute__DOT__rom_array__v1 = vlSelf->WriteData;
    __Vdlyvval__PRegExecute__DOT__rom_array__v2 = vlSelf->PCPlus4E;
    __Vdlyvval__PRegExecute__DOT__rom_array__v3 = vlSelf->RdE;
    __Vdlyvval__PRegExecute__DOT__rom_array__v4 = vlSelf->RegWriteE;
    __Vdlyvval__PRegExecute__DOT__rom_array__v5 = vlSelf->ResultSrcE;
    __Vdlyvval__PRegExecute__DOT__rom_array__v6 = vlSelf->MemWriteE;
    vlSelf->PRegExecute__DOT__rom_array[0U] = __Vdlyvval__PRegExecute__DOT__rom_array__v0;
    vlSelf->PRegExecute__DOT__rom_array[1U] = __Vdlyvval__PRegExecute__DOT__rom_array__v1;
    vlSelf->PRegExecute__DOT__rom_array[2U] = __Vdlyvval__PRegExecute__DOT__rom_array__v2;
    vlSelf->PRegExecute__DOT__rom_array[3U] = __Vdlyvval__PRegExecute__DOT__rom_array__v3;
    vlSelf->PRegExecute__DOT__rom_array[4U] = __Vdlyvval__PRegExecute__DOT__rom_array__v4;
    vlSelf->PRegExecute__DOT__rom_array[5U] = __Vdlyvval__PRegExecute__DOT__rom_array__v5;
    vlSelf->PRegExecute__DOT__rom_array[6U] = __Vdlyvval__PRegExecute__DOT__rom_array__v6;
    vlSelf->ALUResultM = vlSelf->PRegExecute__DOT__rom_array
        [0U];
    vlSelf->MemWriteM = (1U & vlSelf->PRegExecute__DOT__rom_array
                         [6U]);
    vlSelf->WriteDataM = vlSelf->PRegExecute__DOT__rom_array
        [1U];
    vlSelf->PCPlus4M = vlSelf->PRegExecute__DOT__rom_array
        [2U];
    vlSelf->RdM = (0x1fU & vlSelf->PRegExecute__DOT__rom_array
                   [3U]);
    vlSelf->RegWriteM = (1U & vlSelf->PRegExecute__DOT__rom_array
                         [4U]);
    vlSelf->ResultSrcM = (3U & vlSelf->PRegExecute__DOT__rom_array
                          [5U]);
}

void VPRegExecute___024root___eval(VPRegExecute___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPRegExecute__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegExecute___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        VPRegExecute___024root___sequent__TOP__0(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

#ifdef VL_DEBUG
void VPRegExecute___024root___eval_debug_assertions(VPRegExecute___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPRegExecute__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegExecute___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->RdE & 0xe0U))) {
        Verilated::overWidthError("RdE");}
    if (VL_UNLIKELY((vlSelf->RegWriteE & 0xfeU))) {
        Verilated::overWidthError("RegWriteE");}
    if (VL_UNLIKELY((vlSelf->ResultSrcE & 0xfcU))) {
        Verilated::overWidthError("ResultSrcE");}
    if (VL_UNLIKELY((vlSelf->MemWriteE & 0xfeU))) {
        Verilated::overWidthError("MemWriteE");}
}
#endif  // VL_DEBUG
