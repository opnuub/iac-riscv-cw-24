// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vregfile.h for the primary calling header

#include "verilated.h"

#include "Vregfile___024root.h"

VL_INLINE_OPT void Vregfile___024root___sequent__TOP__0(Vregfile___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vregfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregfile___024root___sequent__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vdlyvdim0__regfile__DOT__rf_reg__v0;
    IData/*31:0*/ __Vdlyvval__regfile__DOT__rf_reg__v0;
    CData/*0:0*/ __Vdlyvset__regfile__DOT__rf_reg__v0;
    CData/*0:0*/ __Vdlyvset__regfile__DOT__rf_reg__v1;
    // Body
    __Vdlyvset__regfile__DOT__rf_reg__v0 = 0U;
    __Vdlyvset__regfile__DOT__rf_reg__v1 = 0U;
    if (vlSelf->rst_ni) {
        if (((IData)(vlSelf->wen_i) & (0U != (IData)(vlSelf->waddr_i)))) {
            __Vdlyvval__regfile__DOT__rf_reg__v0 = vlSelf->wdata_i;
            __Vdlyvset__regfile__DOT__rf_reg__v0 = 1U;
            __Vdlyvdim0__regfile__DOT__rf_reg__v0 = vlSelf->waddr_i;
        }
    } else {
        __Vdlyvset__regfile__DOT__rf_reg__v1 = 1U;
    }
    if (__Vdlyvset__regfile__DOT__rf_reg__v0) {
        vlSelf->regfile__DOT__rf_reg[__Vdlyvdim0__regfile__DOT__rf_reg__v0] 
            = __Vdlyvval__regfile__DOT__rf_reg__v0;
    }
    if (__Vdlyvset__regfile__DOT__rf_reg__v1) {
        vlSelf->regfile__DOT__rf_reg[0U] = 0U;
        vlSelf->regfile__DOT__rf_reg[1U] = 0U;
        vlSelf->regfile__DOT__rf_reg[2U] = 0U;
        vlSelf->regfile__DOT__rf_reg[3U] = 0U;
        vlSelf->regfile__DOT__rf_reg[4U] = 0U;
        vlSelf->regfile__DOT__rf_reg[5U] = 0U;
        vlSelf->regfile__DOT__rf_reg[6U] = 0U;
        vlSelf->regfile__DOT__rf_reg[7U] = 0U;
        vlSelf->regfile__DOT__rf_reg[8U] = 0U;
        vlSelf->regfile__DOT__rf_reg[9U] = 0U;
        vlSelf->regfile__DOT__rf_reg[0xaU] = 0U;
        vlSelf->regfile__DOT__rf_reg[0xbU] = 0U;
        vlSelf->regfile__DOT__rf_reg[0xcU] = 0U;
        vlSelf->regfile__DOT__rf_reg[0xdU] = 0U;
        vlSelf->regfile__DOT__rf_reg[0xeU] = 0U;
        vlSelf->regfile__DOT__rf_reg[0xfU] = 0U;
        vlSelf->regfile__DOT__rf_reg[0x10U] = 0U;
        vlSelf->regfile__DOT__rf_reg[0x11U] = 0U;
        vlSelf->regfile__DOT__rf_reg[0x12U] = 0U;
        vlSelf->regfile__DOT__rf_reg[0x13U] = 0U;
        vlSelf->regfile__DOT__rf_reg[0x14U] = 0U;
        vlSelf->regfile__DOT__rf_reg[0x15U] = 0U;
        vlSelf->regfile__DOT__rf_reg[0x16U] = 0U;
        vlSelf->regfile__DOT__rf_reg[0x17U] = 0U;
        vlSelf->regfile__DOT__rf_reg[0x18U] = 0U;
        vlSelf->regfile__DOT__rf_reg[0x19U] = 0U;
        vlSelf->regfile__DOT__rf_reg[0x1aU] = 0U;
        vlSelf->regfile__DOT__rf_reg[0x1bU] = 0U;
        vlSelf->regfile__DOT__rf_reg[0x1cU] = 0U;
        vlSelf->regfile__DOT__rf_reg[0x1dU] = 0U;
        vlSelf->regfile__DOT__rf_reg[0x1eU] = 0U;
        vlSelf->regfile__DOT__rf_reg[0x1fU] = 0U;
    }
    vlSelf->a0_o = vlSelf->regfile__DOT__rf_reg[0xaU];
}

VL_INLINE_OPT void Vregfile___024root___combo__TOP__0(Vregfile___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vregfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregfile___024root___combo__TOP__0\n"); );
    // Body
    vlSelf->rdata1_o = ((0U == (IData)(vlSelf->raddr1_i))
                         ? 0U : vlSelf->regfile__DOT__rf_reg
                        [vlSelf->raddr1_i]);
    vlSelf->rdata2_o = ((0U == (IData)(vlSelf->raddr2_i))
                         ? 0U : vlSelf->regfile__DOT__rf_reg
                        [vlSelf->raddr2_i]);
}

void Vregfile___024root___eval(Vregfile___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vregfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregfile___024root___eval\n"); );
    // Body
    if ((((IData)(vlSelf->clk_i) & (~ (IData)(vlSelf->__Vclklast__TOP__clk_i))) 
         | ((~ (IData)(vlSelf->rst_ni)) & (IData)(vlSelf->__Vclklast__TOP__rst_ni)))) {
        Vregfile___024root___sequent__TOP__0(vlSelf);
    }
    Vregfile___024root___combo__TOP__0(vlSelf);
    // Final
    vlSelf->__Vclklast__TOP__clk_i = vlSelf->clk_i;
    vlSelf->__Vclklast__TOP__rst_ni = vlSelf->rst_ni;
}

#ifdef VL_DEBUG
void Vregfile___024root___eval_debug_assertions(Vregfile___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vregfile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregfile___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk_i & 0xfeU))) {
        Verilated::overWidthError("clk_i");}
    if (VL_UNLIKELY((vlSelf->rst_ni & 0xfeU))) {
        Verilated::overWidthError("rst_ni");}
    if (VL_UNLIKELY((vlSelf->wen_i & 0xfeU))) {
        Verilated::overWidthError("wen_i");}
    if (VL_UNLIKELY((vlSelf->waddr_i & 0xe0U))) {
        Verilated::overWidthError("waddr_i");}
    if (VL_UNLIKELY((vlSelf->raddr1_i & 0xe0U))) {
        Verilated::overWidthError("raddr1_i");}
    if (VL_UNLIKELY((vlSelf->raddr2_i & 0xe0U))) {
        Verilated::overWidthError("raddr2_i");}
}
#endif  // VL_DEBUG
