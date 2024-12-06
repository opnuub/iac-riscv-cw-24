// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbranch.h for the primary calling header

#include "verilated.h"

#include "Vbranch___024root.h"

VL_ATTR_COLD void Vbranch___024root___eval_initial(Vbranch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbranch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch___024root___eval_initial\n"); );
}

void Vbranch___024root___combo__TOP__0(Vbranch___024root* vlSelf);

VL_ATTR_COLD void Vbranch___024root___eval_settle(Vbranch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbranch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch___024root___eval_settle\n"); );
    // Body
    Vbranch___024root___combo__TOP__0(vlSelf);
}

VL_ATTR_COLD void Vbranch___024root___final(Vbranch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbranch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch___024root___final\n"); );
}

VL_ATTR_COLD void Vbranch___024root___ctor_var_reset(Vbranch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbranch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->rs1_data_i = VL_RAND_RESET_I(32);
    vlSelf->rs2_data_i = VL_RAND_RESET_I(32);
    vlSelf->funct3_i = VL_RAND_RESET_I(3);
    vlSelf->branch_taken_o = VL_RAND_RESET_I(1);
    vlSelf->branch_eq_o = VL_RAND_RESET_I(1);
    vlSelf->branch_lt_o = VL_RAND_RESET_I(1);
    vlSelf->branch_ltu_o = VL_RAND_RESET_I(1);
}
