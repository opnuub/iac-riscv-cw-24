// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VDataMemory.h for the primary calling header

#include "verilated.h"

#include "VDataMemory___024root.h"

VL_ATTR_COLD void VDataMemory___024root___eval_initial(VDataMemory___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDataMemory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDataMemory___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

void VDataMemory___024root___combo__TOP__0(VDataMemory___024root* vlSelf);

VL_ATTR_COLD void VDataMemory___024root___eval_settle(VDataMemory___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDataMemory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDataMemory___024root___eval_settle\n"); );
    // Body
    VDataMemory___024root___combo__TOP__0(vlSelf);
}

VL_ATTR_COLD void VDataMemory___024root___final(VDataMemory___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDataMemory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDataMemory___024root___final\n"); );
}

VL_ATTR_COLD void VDataMemory___024root___ctor_var_reset(VDataMemory___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDataMemory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDataMemory___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->SizeCtr = VL_RAND_RESET_I(3);
    vlSelf->ALUResult = VL_RAND_RESET_I(17);
    vlSelf->WriteData = VL_RAND_RESET_I(32);
    vlSelf->MemWrite = VL_RAND_RESET_I(1);
    vlSelf->ReadData = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<131072; ++__Vi0) {
        vlSelf->DataMemory__DOT__memory[__Vi0] = VL_RAND_RESET_I(8);
    }
}
