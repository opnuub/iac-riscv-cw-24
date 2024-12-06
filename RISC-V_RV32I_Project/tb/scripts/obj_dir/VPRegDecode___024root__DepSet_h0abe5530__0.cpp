// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPRegDecode.h for the primary calling header

#include "verilated.h"

#include "VPRegDecode___024root.h"

VL_INLINE_OPT void VPRegDecode___024root___sequent__TOP__0(VPRegDecode___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPRegDecode__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegDecode___024root___sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ __Vdlyvval__PRegDecode__DOT__rom_array__v0;
    IData/*31:0*/ __Vdlyvval__PRegDecode__DOT__rom_array__v1;
    IData/*31:0*/ __Vdlyvval__PRegDecode__DOT__rom_array__v2;
    IData/*31:0*/ __Vdlyvval__PRegDecode__DOT__rom_array__v3;
    IData/*31:0*/ __Vdlyvval__PRegDecode__DOT__rom_array__v4;
    IData/*31:0*/ __Vdlyvval__PRegDecode__DOT__rom_array__v5;
    IData/*31:0*/ __Vdlyvval__PRegDecode__DOT__rom_array__v6;
    IData/*31:0*/ __Vdlyvval__PRegDecode__DOT__rom_array__v7;
    IData/*31:0*/ __Vdlyvval__PRegDecode__DOT__rom_array__v8;
    IData/*31:0*/ __Vdlyvval__PRegDecode__DOT__rom_array__v9;
    IData/*31:0*/ __Vdlyvval__PRegDecode__DOT__rom_array__v10;
    IData/*31:0*/ __Vdlyvval__PRegDecode__DOT__rom_array__v11;
    IData/*31:0*/ __Vdlyvval__PRegDecode__DOT__rom_array__v12;
    // Body
    __Vdlyvval__PRegDecode__DOT__rom_array__v0 = vlSelf->rd1;
    __Vdlyvval__PRegDecode__DOT__rom_array__v1 = vlSelf->rd2;
    __Vdlyvval__PRegDecode__DOT__rom_array__v2 = vlSelf->PCd;
    __Vdlyvval__PRegDecode__DOT__rom_array__v3 = vlSelf->RdD;
    __Vdlyvval__PRegDecode__DOT__rom_array__v4 = vlSelf->ImmExtD;
    __Vdlyvval__PRegDecode__DOT__rom_array__v5 = vlSelf->PCPlus4D;
    __Vdlyvval__PRegDecode__DOT__rom_array__v6 = vlSelf->RegWriteD;
    __Vdlyvval__PRegDecode__DOT__rom_array__v7 = vlSelf->ResultSrcD;
    __Vdlyvval__PRegDecode__DOT__rom_array__v8 = vlSelf->MemWriteD;
    __Vdlyvval__PRegDecode__DOT__rom_array__v9 = vlSelf->JumpD;
    __Vdlyvval__PRegDecode__DOT__rom_array__v10 = vlSelf->BranchD;
    __Vdlyvval__PRegDecode__DOT__rom_array__v11 = vlSelf->ALUControl;
    __Vdlyvval__PRegDecode__DOT__rom_array__v12 = vlSelf->ALUSrcD;
    vlSelf->PRegDecode__DOT__rom_array[0U] = __Vdlyvval__PRegDecode__DOT__rom_array__v0;
    vlSelf->PRegDecode__DOT__rom_array[1U] = __Vdlyvval__PRegDecode__DOT__rom_array__v1;
    vlSelf->PRegDecode__DOT__rom_array[2U] = __Vdlyvval__PRegDecode__DOT__rom_array__v2;
    vlSelf->PRegDecode__DOT__rom_array[3U] = __Vdlyvval__PRegDecode__DOT__rom_array__v3;
    vlSelf->PRegDecode__DOT__rom_array[4U] = __Vdlyvval__PRegDecode__DOT__rom_array__v4;
    vlSelf->PRegDecode__DOT__rom_array[5U] = __Vdlyvval__PRegDecode__DOT__rom_array__v5;
    vlSelf->PRegDecode__DOT__rom_array[6U] = __Vdlyvval__PRegDecode__DOT__rom_array__v6;
    vlSelf->PRegDecode__DOT__rom_array[7U] = __Vdlyvval__PRegDecode__DOT__rom_array__v7;
    vlSelf->PRegDecode__DOT__rom_array[8U] = __Vdlyvval__PRegDecode__DOT__rom_array__v8;
    vlSelf->PRegDecode__DOT__rom_array[9U] = __Vdlyvval__PRegDecode__DOT__rom_array__v9;
    vlSelf->PRegDecode__DOT__rom_array[0xaU] = __Vdlyvval__PRegDecode__DOT__rom_array__v10;
    vlSelf->PRegDecode__DOT__rom_array[0xbU] = __Vdlyvval__PRegDecode__DOT__rom_array__v11;
    vlSelf->PRegDecode__DOT__rom_array[0xcU] = __Vdlyvval__PRegDecode__DOT__rom_array__v12;
    vlSelf->rd1E = vlSelf->PRegDecode__DOT__rom_array
        [0U];
    vlSelf->RegWriteE = (1U & vlSelf->PRegDecode__DOT__rom_array
                         [6U]);
    vlSelf->rd2E = vlSelf->PRegDecode__DOT__rom_array
        [1U];
    vlSelf->PCe = vlSelf->PRegDecode__DOT__rom_array
        [2U];
    vlSelf->RdE = (0x1fU & vlSelf->PRegDecode__DOT__rom_array
                   [3U]);
    vlSelf->ImmExtE = vlSelf->PRegDecode__DOT__rom_array
        [4U];
    vlSelf->PcPlus4E = vlSelf->PRegDecode__DOT__rom_array
        [5U];
    vlSelf->ResultSrcE = (3U & vlSelf->PRegDecode__DOT__rom_array
                          [7U]);
    vlSelf->MemWriteE = (1U & vlSelf->PRegDecode__DOT__rom_array
                         [8U]);
    vlSelf->JumpE = (1U & vlSelf->PRegDecode__DOT__rom_array
                     [9U]);
    vlSelf->BranchE = (1U & vlSelf->PRegDecode__DOT__rom_array
                       [0xaU]);
    vlSelf->ALUControlE = (7U & vlSelf->PRegDecode__DOT__rom_array
                           [0xbU]);
    vlSelf->ALUSrcE = (1U & vlSelf->PRegDecode__DOT__rom_array
                       [0xcU]);
}

void VPRegDecode___024root___eval(VPRegDecode___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPRegDecode__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegDecode___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        VPRegDecode___024root___sequent__TOP__0(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

#ifdef VL_DEBUG
void VPRegDecode___024root___eval_debug_assertions(VPRegDecode___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPRegDecode__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegDecode___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->RdD & 0xe0U))) {
        Verilated::overWidthError("RdD");}
    if (VL_UNLIKELY((vlSelf->RegWriteD & 0xfeU))) {
        Verilated::overWidthError("RegWriteD");}
    if (VL_UNLIKELY((vlSelf->ResultSrcD & 0xfcU))) {
        Verilated::overWidthError("ResultSrcD");}
    if (VL_UNLIKELY((vlSelf->MemWriteD & 0xfeU))) {
        Verilated::overWidthError("MemWriteD");}
    if (VL_UNLIKELY((vlSelf->JumpD & 0xfeU))) {
        Verilated::overWidthError("JumpD");}
    if (VL_UNLIKELY((vlSelf->BranchD & 0xfeU))) {
        Verilated::overWidthError("BranchD");}
    if (VL_UNLIKELY((vlSelf->ALUControl & 0xf8U))) {
        Verilated::overWidthError("ALUControl");}
    if (VL_UNLIKELY((vlSelf->ALUSrcD & 0xfeU))) {
        Verilated::overWidthError("ALUSrcD");}
}
#endif  // VL_DEBUG
