// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vregfile.h for the primary calling header

#include "verilated.h"

#include "Vregfile___024root.h"

VL_ATTR_COLD void Vregfile___024root___settle__TOP__0(Vregfile___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vregfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregfile___024root___settle__TOP__0\n"); );
    // Body
    vlSelf->a0_o = vlSelf->regfile__DOT__rf_reg[0xaU];
    vlSelf->rdata1_o = ((0U == (IData)(vlSelf->raddr1_i))
                         ? 0U : vlSelf->regfile__DOT__rf_reg
                        [vlSelf->raddr1_i]);
    vlSelf->rdata2_o = ((0U == (IData)(vlSelf->raddr2_i))
                         ? 0U : vlSelf->regfile__DOT__rf_reg
                        [vlSelf->raddr2_i]);
}

VL_ATTR_COLD void Vregfile___024root___eval_initial(Vregfile___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vregfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregfile___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk_i = vlSelf->clk_i;
    vlSelf->__Vclklast__TOP__rst_ni = vlSelf->rst_ni;
}

VL_ATTR_COLD void Vregfile___024root___eval_settle(Vregfile___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vregfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregfile___024root___eval_settle\n"); );
    // Body
    Vregfile___024root___settle__TOP__0(vlSelf);
}

VL_ATTR_COLD void Vregfile___024root___final(Vregfile___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vregfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregfile___024root___final\n"); );
}

VL_ATTR_COLD void Vregfile___024root___ctor_var_reset(Vregfile___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vregfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregfile___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk_i = VL_RAND_RESET_I(1);
    vlSelf->rst_ni = VL_RAND_RESET_I(1);
    vlSelf->wen_i = VL_RAND_RESET_I(1);
    vlSelf->waddr_i = VL_RAND_RESET_I(5);
    vlSelf->wdata_i = VL_RAND_RESET_I(32);
    vlSelf->raddr1_i = VL_RAND_RESET_I(5);
    vlSelf->rdata1_o = VL_RAND_RESET_I(32);
    vlSelf->raddr2_i = VL_RAND_RESET_I(5);
    vlSelf->rdata2_o = VL_RAND_RESET_I(32);
    vlSelf->a0_o = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<32; ++__Vi0) {
        vlSelf->regfile__DOT__rf_reg[__Vi0] = VL_RAND_RESET_I(32);
    }
}
