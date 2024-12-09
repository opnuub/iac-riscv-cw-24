// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPRegDecode.h for the primary calling header

#include "verilated.h"

#include "VPRegDecode___024root.h"

VL_ATTR_COLD void VPRegDecode___024root___settle__TOP__0(VPRegDecode___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPRegDecode__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegDecode___024root___settle__TOP__0\n"); );
    // Body
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

VL_ATTR_COLD void VPRegDecode___024root___eval_initial(VPRegDecode___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPRegDecode__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegDecode___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void VPRegDecode___024root___eval_settle(VPRegDecode___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPRegDecode__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegDecode___024root___eval_settle\n"); );
    // Body
    VPRegDecode___024root___settle__TOP__0(vlSelf);
}

VL_ATTR_COLD void VPRegDecode___024root___final(VPRegDecode___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPRegDecode__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegDecode___024root___final\n"); );
}

VL_ATTR_COLD void VPRegDecode___024root___ctor_var_reset(VPRegDecode___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPRegDecode__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPRegDecode___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->rd1 = VL_RAND_RESET_I(32);
    vlSelf->rd2 = VL_RAND_RESET_I(32);
    vlSelf->PCd = VL_RAND_RESET_I(32);
    vlSelf->ImmExtD = VL_RAND_RESET_I(32);
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->RdD = VL_RAND_RESET_I(5);
    vlSelf->PCPlus4D = VL_RAND_RESET_I(32);
    vlSelf->rd1E = VL_RAND_RESET_I(32);
    vlSelf->rd2E = VL_RAND_RESET_I(32);
    vlSelf->PCe = VL_RAND_RESET_I(32);
    vlSelf->RdE = VL_RAND_RESET_I(5);
    vlSelf->ImmExtE = VL_RAND_RESET_I(32);
    vlSelf->PcPlus4E = VL_RAND_RESET_I(32);
    vlSelf->RegWriteD = VL_RAND_RESET_I(1);
    vlSelf->ResultSrcD = VL_RAND_RESET_I(2);
    vlSelf->MemWriteD = VL_RAND_RESET_I(1);
    vlSelf->JumpD = VL_RAND_RESET_I(1);
    vlSelf->BranchD = VL_RAND_RESET_I(1);
    vlSelf->ALUControl = VL_RAND_RESET_I(3);
    vlSelf->ALUSrcD = VL_RAND_RESET_I(1);
    vlSelf->RegWriteE = VL_RAND_RESET_I(1);
    vlSelf->ResultSrcE = VL_RAND_RESET_I(2);
    vlSelf->MemWriteE = VL_RAND_RESET_I(1);
    vlSelf->JumpE = VL_RAND_RESET_I(1);
    vlSelf->BranchE = VL_RAND_RESET_I(1);
    vlSelf->ALUControlE = VL_RAND_RESET_I(3);
    vlSelf->ALUSrcE = VL_RAND_RESET_I(1);
    for (int __Vi0=0; __Vi0<16; ++__Vi0) {
        vlSelf->PRegDecode__DOT__rom_array[__Vi0] = VL_RAND_RESET_I(32);
    }
}
