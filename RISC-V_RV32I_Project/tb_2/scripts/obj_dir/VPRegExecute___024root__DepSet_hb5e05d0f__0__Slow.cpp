// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPRegExecute.h for the primary calling header

#include "verilated.h"

#include "VPRegExecute___024root.h"

VL_ATTR_COLD void VPRegExecute___024root___settle__TOP__0(VPRegExecute___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPRegExecute__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegExecute___024root___settle__TOP__0\n"); );
    // Body
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

VL_ATTR_COLD void VPRegExecute___024root___eval_initial(VPRegExecute___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPRegExecute__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegExecute___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void VPRegExecute___024root___eval_settle(VPRegExecute___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPRegExecute__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegExecute___024root___eval_settle\n"); );
    // Body
    VPRegExecute___024root___settle__TOP__0(vlSelf);
}

VL_ATTR_COLD void VPRegExecute___024root___final(VPRegExecute___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPRegExecute__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegExecute___024root___final\n"); );
}

VL_ATTR_COLD void VPRegExecute___024root___ctor_var_reset(VPRegExecute___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPRegExecute__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegExecute___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->ALUout = VL_RAND_RESET_I(32);
    vlSelf->WriteData = VL_RAND_RESET_I(32);
    vlSelf->PCPlus4E = VL_RAND_RESET_I(32);
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->RdE = VL_RAND_RESET_I(5);
    vlSelf->ALUResultM = VL_RAND_RESET_I(32);
    vlSelf->WriteDataM = VL_RAND_RESET_I(32);
    vlSelf->RdM = VL_RAND_RESET_I(5);
    vlSelf->PCPlus4M = VL_RAND_RESET_I(32);
    vlSelf->RegWriteE = VL_RAND_RESET_I(1);
    vlSelf->ResultSrcE = VL_RAND_RESET_I(2);
    vlSelf->MemWriteE = VL_RAND_RESET_I(1);
    vlSelf->RegWriteM = VL_RAND_RESET_I(1);
    vlSelf->ResultSrcM = VL_RAND_RESET_I(2);
    vlSelf->MemWriteM = VL_RAND_RESET_I(1);
    for (int __Vi0=0; __Vi0<8; ++__Vi0) {
        vlSelf->PRegExecute__DOT__rom_array[__Vi0] = VL_RAND_RESET_I(32);
    }
}
