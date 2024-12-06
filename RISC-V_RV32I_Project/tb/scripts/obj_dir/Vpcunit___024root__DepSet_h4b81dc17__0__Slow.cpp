// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpcunit.h for the primary calling header

#include "verilated.h"

#include "Vpcunit___024root.h"

VL_ATTR_COLD void Vpcunit___024root___settle__TOP__0(Vpcunit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpcunit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpcunit___024root___settle__TOP__0\n"); );
    // Body
    vlSelf->pc_o = vlSelf->pcunit__DOT__pc_q;
    vlSelf->next_pc_o = ((IData)(4U) + vlSelf->pcunit__DOT__pc_q);
    vlSelf->next_pc_o = ((4U & (IData)(vlSelf->next_pc_sel_i))
                          ? ((IData)(4U) + vlSelf->pcunit__DOT__pc_q)
                          : ((2U & (IData)(vlSelf->next_pc_sel_i))
                              ? ((1U & (IData)(vlSelf->next_pc_sel_i))
                                  ? (0xfffffffeU & vlSelf->alu_result_i)
                                  : (vlSelf->pcunit__DOT__pc_q 
                                     + vlSelf->imm_i))
                              : ((1U & (IData)(vlSelf->next_pc_sel_i))
                                  ? (vlSelf->pcunit__DOT__pc_q 
                                     + vlSelf->imm_i)
                                  : ((IData)(4U) + vlSelf->pcunit__DOT__pc_q))));
}

VL_ATTR_COLD void Vpcunit___024root___eval_initial(Vpcunit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpcunit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpcunit___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk_i = vlSelf->clk_i;
    vlSelf->__Vclklast__TOP__rst_ni = vlSelf->rst_ni;
}

VL_ATTR_COLD void Vpcunit___024root___eval_settle(Vpcunit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpcunit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpcunit___024root___eval_settle\n"); );
    // Body
    Vpcunit___024root___settle__TOP__0(vlSelf);
}

VL_ATTR_COLD void Vpcunit___024root___final(Vpcunit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpcunit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpcunit___024root___final\n"); );
}

VL_ATTR_COLD void Vpcunit___024root___ctor_var_reset(Vpcunit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpcunit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpcunit___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk_i = VL_RAND_RESET_I(1);
    vlSelf->rst_ni = VL_RAND_RESET_I(1);
    vlSelf->next_pc_sel_i = VL_RAND_RESET_I(3);
    vlSelf->alu_result_i = VL_RAND_RESET_I(32);
    vlSelf->imm_i = VL_RAND_RESET_I(32);
    vlSelf->pc_o = VL_RAND_RESET_I(32);
    vlSelf->next_pc_o = VL_RAND_RESET_I(32);
    vlSelf->pcunit__DOT__pc_q = VL_RAND_RESET_I(32);
}
