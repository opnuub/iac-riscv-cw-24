// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPRegMemory.h for the primary calling header

#include "verilated.h"

#include "VPRegMemory___024root.h"

VL_ATTR_COLD void VPRegMemory___024root___settle__TOP__0(VPRegMemory___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPRegMemory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegMemory___024root___settle__TOP__0\n"); );
    // Body
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

VL_ATTR_COLD void VPRegMemory___024root___eval_initial(VPRegMemory___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPRegMemory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegMemory___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void VPRegMemory___024root___eval_settle(VPRegMemory___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPRegMemory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegMemory___024root___eval_settle\n"); );
    // Body
    VPRegMemory___024root___settle__TOP__0(vlSelf);
}

VL_ATTR_COLD void VPRegMemory___024root___final(VPRegMemory___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPRegMemory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegMemory___024root___final\n"); );
}

VL_ATTR_COLD void VPRegMemory___024root___ctor_var_reset(VPRegMemory___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPRegMemory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegMemory___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->ALUResultM = VL_RAND_RESET_I(32);
    vlSelf->DMRd = VL_RAND_RESET_I(32);
    vlSelf->RdM = VL_RAND_RESET_I(5);
    vlSelf->PCPlus4M = VL_RAND_RESET_I(32);
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->RdW = VL_RAND_RESET_I(5);
    vlSelf->ALUResultW = VL_RAND_RESET_I(32);
    vlSelf->WriteDataW = VL_RAND_RESET_I(32);
    vlSelf->PCPlus4W = VL_RAND_RESET_I(32);
    vlSelf->RegWriteM = VL_RAND_RESET_I(1);
    vlSelf->ResultSrcM = VL_RAND_RESET_I(2);
    vlSelf->RegWriteW = VL_RAND_RESET_I(1);
    vlSelf->ResultSrcW = VL_RAND_RESET_I(2);
    for (int __Vi0=0; __Vi0<8; ++__Vi0) {
        vlSelf->PRegMemory__DOT__rom_array[__Vi0] = VL_RAND_RESET_I(32);
    }
}
