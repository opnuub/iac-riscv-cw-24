// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPCtop.h for the primary calling header

#include "verilated.h"

#include "VPCtop___024root.h"

extern const VlWide<22>/*703:0*/ VPCtop__ConstPool__CONST_hbbe01394_0;

VL_ATTR_COLD void VPCtop___024root___initial__TOP__0(VPCtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPCtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPCtop___024root___initial__TOP__0\n"); );
    // Init
    VlWide<4>/*127:0*/ __Vtemp_h695134fa__0;
    // Body
    VL_WRITEF("Loading program into instruction memory...\n");
    VL_READMEM_N(true, 8, 4096, 0, VL_CVT_PACK_STR_NW(22, VPCtop__ConstPool__CONST_hbbe01394_0)
                 ,  &(vlSelf->PCtop__DOT__imem__DOT__mem)
                 , 0, ~0ULL);
    VL_WRITEF("Loading rom.2\n");
    __Vtemp_h695134fa__0[0U] = 0x2e6d656dU;
    __Vtemp_h695134fa__0[1U] = 0x65746368U;
    __Vtemp_h695134fa__0[2U] = 0x52656746U;
    __Vtemp_h695134fa__0[3U] = 0x50U;
    VL_READMEM_N(true, 32, 8, 0, VL_CVT_PACK_STR_NW(4, __Vtemp_h695134fa__0)
                 ,  &(vlSelf->PCtop__DOT__PRegFetch__DOT__rom_array)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void VPCtop___024root___settle__TOP__0(VPCtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPCtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPCtop___024root___settle__TOP__0\n"); );
    // Body
    vlSelf->PCtop__DOT__PCFp = ((IData)(vlSelf->PCsrcE)
                                 ? vlSelf->PCTargetE
                                 : ((IData)(4U) + vlSelf->PCtop__DOT__PCf));
    vlSelf->PCtop__DOT__PRegFetch__DOT__rom_array[0U] 
        = vlSelf->PCtop__DOT__Rd;
    vlSelf->PCtop__DOT__PRegFetch__DOT__rom_array[1U] 
        = vlSelf->PCtop__DOT__PCf;
    vlSelf->PCtop__DOT__PRegFetch__DOT__rom_array[2U] 
        = ((IData)(4U) + vlSelf->PCtop__DOT__PCf);
}

VL_ATTR_COLD void VPCtop___024root___eval_initial(VPCtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPCtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPCtop___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
    VPCtop___024root___initial__TOP__0(vlSelf);
}

VL_ATTR_COLD void VPCtop___024root___eval_settle(VPCtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPCtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPCtop___024root___eval_settle\n"); );
    // Body
    VPCtop___024root___settle__TOP__0(vlSelf);
}

VL_ATTR_COLD void VPCtop___024root___final(VPCtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPCtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPCtop___024root___final\n"); );
}

VL_ATTR_COLD void VPCtop___024root___ctor_var_reset(VPCtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VPCtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPCtop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->PCsrcE = VL_RAND_RESET_I(1);
    vlSelf->PCTargetE = VL_RAND_RESET_I(32);
    vlSelf->InstrD = VL_RAND_RESET_I(32);
    vlSelf->PCd = VL_RAND_RESET_I(32);
    vlSelf->PCPlus4D = VL_RAND_RESET_I(32);
    vlSelf->PCtop__DOT__PCFp = VL_RAND_RESET_I(32);
    vlSelf->PCtop__DOT__PCf = VL_RAND_RESET_I(32);
    vlSelf->PCtop__DOT__Rd = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<4096; ++__Vi0) {
        vlSelf->PCtop__DOT__imem__DOT__mem[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0=0; __Vi0<8; ++__Vi0) {
        vlSelf->PCtop__DOT__PRegFetch__DOT__rom_array[__Vi0] = VL_RAND_RESET_I(32);
    }
}
