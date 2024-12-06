// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vimem.h for the primary calling header

#include "verilated.h"

#include "Vimem___024root.h"

extern const VlWide<22>/*703:0*/ Vimem__ConstPool__CONST_hbbe01394_0;

VL_ATTR_COLD void Vimem___024root___initial__TOP__0(Vimem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vimem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vimem___024root___initial__TOP__0\n"); );
    // Body
    VL_WRITEF("Loading program into instruction memory...\n");
    VL_READMEM_N(true, 8, 4096, 0, VL_CVT_PACK_STR_NW(22, Vimem__ConstPool__CONST_hbbe01394_0)
                 ,  &(vlSelf->imem__DOT__mem), 0, ~0ULL);
}

VL_ATTR_COLD void Vimem___024root___eval_initial(Vimem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vimem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vimem___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk_i = vlSelf->clk_i;
    Vimem___024root___initial__TOP__0(vlSelf);
}

VL_ATTR_COLD void Vimem___024root___eval_settle(Vimem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vimem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vimem___024root___eval_settle\n"); );
}

VL_ATTR_COLD void Vimem___024root___final(Vimem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vimem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vimem___024root___final\n"); );
}

VL_ATTR_COLD void Vimem___024root___ctor_var_reset(Vimem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vimem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vimem___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk_i = VL_RAND_RESET_I(1);
    vlSelf->addr_i = VL_RAND_RESET_I(32);
    vlSelf->rdata_o = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<4096; ++__Vi0) {
        vlSelf->imem__DOT__mem[__Vi0] = VL_RAND_RESET_I(8);
    }
}
