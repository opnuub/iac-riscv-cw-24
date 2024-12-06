// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VDataMemory.h for the primary calling header

#include "verilated.h"

#include "VDataMemory___024root.h"

VL_INLINE_OPT void VDataMemory___024root___sequent__TOP__0(VDataMemory___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDataMemory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDataMemory___024root___sequent__TOP__0\n"); );
    // Init
    IData/*16:0*/ __Vdlyvdim0__DataMemory__DOT__memory__v0;
    CData/*7:0*/ __Vdlyvval__DataMemory__DOT__memory__v0;
    CData/*0:0*/ __Vdlyvset__DataMemory__DOT__memory__v0;
    IData/*16:0*/ __Vdlyvdim0__DataMemory__DOT__memory__v1;
    CData/*7:0*/ __Vdlyvval__DataMemory__DOT__memory__v1;
    IData/*16:0*/ __Vdlyvdim0__DataMemory__DOT__memory__v2;
    CData/*7:0*/ __Vdlyvval__DataMemory__DOT__memory__v2;
    IData/*16:0*/ __Vdlyvdim0__DataMemory__DOT__memory__v3;
    CData/*7:0*/ __Vdlyvval__DataMemory__DOT__memory__v3;
    IData/*16:0*/ __Vdlyvdim0__DataMemory__DOT__memory__v4;
    CData/*7:0*/ __Vdlyvval__DataMemory__DOT__memory__v4;
    CData/*0:0*/ __Vdlyvset__DataMemory__DOT__memory__v4;
    IData/*16:0*/ __Vdlyvdim0__DataMemory__DOT__memory__v5;
    CData/*7:0*/ __Vdlyvval__DataMemory__DOT__memory__v5;
    IData/*16:0*/ __Vdlyvdim0__DataMemory__DOT__memory__v6;
    CData/*7:0*/ __Vdlyvval__DataMemory__DOT__memory__v6;
    CData/*0:0*/ __Vdlyvset__DataMemory__DOT__memory__v6;
    // Body
    __Vdlyvset__DataMemory__DOT__memory__v0 = 0U;
    __Vdlyvset__DataMemory__DOT__memory__v4 = 0U;
    __Vdlyvset__DataMemory__DOT__memory__v6 = 0U;
    if (vlSelf->MemWrite) {
        if ((2U == (IData)(vlSelf->SizeCtr))) {
            __Vdlyvval__DataMemory__DOT__memory__v0 
                = (0xffU & vlSelf->WriteData);
            __Vdlyvset__DataMemory__DOT__memory__v0 = 1U;
            __Vdlyvdim0__DataMemory__DOT__memory__v0 
                = vlSelf->ALUResult;
            __Vdlyvval__DataMemory__DOT__memory__v1 
                = (0xffU & (vlSelf->WriteData >> 8U));
            __Vdlyvdim0__DataMemory__DOT__memory__v1 
                = (0x1ffffU & ((IData)(1U) + vlSelf->ALUResult));
            __Vdlyvval__DataMemory__DOT__memory__v2 
                = (0xffU & (vlSelf->WriteData >> 0x10U));
            __Vdlyvdim0__DataMemory__DOT__memory__v2 
                = (0x1ffffU & ((IData)(2U) + vlSelf->ALUResult));
            __Vdlyvval__DataMemory__DOT__memory__v3 
                = (vlSelf->WriteData >> 0x18U);
            __Vdlyvdim0__DataMemory__DOT__memory__v3 
                = (0x1ffffU & ((IData)(3U) + vlSelf->ALUResult));
        } else if ((1U == (IData)(vlSelf->SizeCtr))) {
            __Vdlyvval__DataMemory__DOT__memory__v4 
                = (0xffU & vlSelf->WriteData);
            __Vdlyvset__DataMemory__DOT__memory__v4 = 1U;
            __Vdlyvdim0__DataMemory__DOT__memory__v4 
                = vlSelf->ALUResult;
            __Vdlyvval__DataMemory__DOT__memory__v5 
                = (0xffU & (vlSelf->WriteData >> 8U));
            __Vdlyvdim0__DataMemory__DOT__memory__v5 
                = (0x1ffffU & ((IData)(1U) + vlSelf->ALUResult));
        } else if ((0U == (IData)(vlSelf->SizeCtr))) {
            __Vdlyvval__DataMemory__DOT__memory__v6 
                = (0xffU & vlSelf->WriteData);
            __Vdlyvset__DataMemory__DOT__memory__v6 = 1U;
            __Vdlyvdim0__DataMemory__DOT__memory__v6 
                = vlSelf->ALUResult;
        }
    }
    if (__Vdlyvset__DataMemory__DOT__memory__v0) {
        vlSelf->DataMemory__DOT__memory[__Vdlyvdim0__DataMemory__DOT__memory__v0] 
            = __Vdlyvval__DataMemory__DOT__memory__v0;
        vlSelf->DataMemory__DOT__memory[__Vdlyvdim0__DataMemory__DOT__memory__v1] 
            = __Vdlyvval__DataMemory__DOT__memory__v1;
        vlSelf->DataMemory__DOT__memory[__Vdlyvdim0__DataMemory__DOT__memory__v2] 
            = __Vdlyvval__DataMemory__DOT__memory__v2;
        vlSelf->DataMemory__DOT__memory[__Vdlyvdim0__DataMemory__DOT__memory__v3] 
            = __Vdlyvval__DataMemory__DOT__memory__v3;
    }
    if (__Vdlyvset__DataMemory__DOT__memory__v4) {
        vlSelf->DataMemory__DOT__memory[__Vdlyvdim0__DataMemory__DOT__memory__v4] 
            = __Vdlyvval__DataMemory__DOT__memory__v4;
        vlSelf->DataMemory__DOT__memory[__Vdlyvdim0__DataMemory__DOT__memory__v5] 
            = __Vdlyvval__DataMemory__DOT__memory__v5;
    }
    if (__Vdlyvset__DataMemory__DOT__memory__v6) {
        vlSelf->DataMemory__DOT__memory[__Vdlyvdim0__DataMemory__DOT__memory__v6] 
            = __Vdlyvval__DataMemory__DOT__memory__v6;
    }
}

VL_INLINE_OPT void VDataMemory___024root___combo__TOP__0(VDataMemory___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDataMemory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDataMemory___024root___combo__TOP__0\n"); );
    // Body
    vlSelf->ReadData = ((4U & (IData)(vlSelf->SizeCtr))
                         ? ((2U & (IData)(vlSelf->SizeCtr))
                             ? 0U : ((1U & (IData)(vlSelf->SizeCtr))
                                      ? ((vlSelf->DataMemory__DOT__memory
                                          [(0x1ffffU 
                                            & ((IData)(1U) 
                                               + vlSelf->ALUResult))] 
                                          << 8U) | 
                                         vlSelf->DataMemory__DOT__memory
                                         [vlSelf->ALUResult])
                                      : vlSelf->DataMemory__DOT__memory
                                     [vlSelf->ALUResult]))
                         : ((2U & (IData)(vlSelf->SizeCtr))
                             ? ((1U & (IData)(vlSelf->SizeCtr))
                                 ? 0U : ((vlSelf->DataMemory__DOT__memory
                                          [(0x1ffffU 
                                            & ((IData)(3U) 
                                               + vlSelf->ALUResult))] 
                                          << 0x18U) 
                                         | ((vlSelf->DataMemory__DOT__memory
                                             [(0x1ffffU 
                                               & ((IData)(2U) 
                                                  + vlSelf->ALUResult))] 
                                             << 0x10U) 
                                            | ((vlSelf->DataMemory__DOT__memory
                                                [(0x1ffffU 
                                                  & ((IData)(1U) 
                                                     + vlSelf->ALUResult))] 
                                                << 8U) 
                                               | vlSelf->DataMemory__DOT__memory
                                               [vlSelf->ALUResult]))))
                             : ((1U & (IData)(vlSelf->SizeCtr))
                                 ? (((- (IData)((1U 
                                                 & (vlSelf->DataMemory__DOT__memory
                                                    [
                                                    (0x1ffffU 
                                                     & ((IData)(1U) 
                                                        + vlSelf->ALUResult))] 
                                                    >> 7U)))) 
                                     << 0x10U) | ((
                                                   vlSelf->DataMemory__DOT__memory
                                                   [
                                                   (0x1ffffU 
                                                    & ((IData)(1U) 
                                                       + vlSelf->ALUResult))] 
                                                   << 8U) 
                                                  | vlSelf->DataMemory__DOT__memory
                                                  [vlSelf->ALUResult]))
                                 : (((- (IData)((1U 
                                                 & (vlSelf->DataMemory__DOT__memory
                                                    [vlSelf->ALUResult] 
                                                    >> 7U)))) 
                                     << 8U) | vlSelf->DataMemory__DOT__memory
                                    [vlSelf->ALUResult]))));
}

void VDataMemory___024root___eval(VDataMemory___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDataMemory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDataMemory___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        VDataMemory___024root___sequent__TOP__0(vlSelf);
    }
    VDataMemory___024root___combo__TOP__0(vlSelf);
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

#ifdef VL_DEBUG
void VDataMemory___024root___eval_debug_assertions(VDataMemory___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDataMemory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDataMemory___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->SizeCtr & 0xf8U))) {
        Verilated::overWidthError("SizeCtr");}
    if (VL_UNLIKELY((vlSelf->ALUResult & 0xfffe0000U))) {
        Verilated::overWidthError("ALUResult");}
    if (VL_UNLIKELY((vlSelf->MemWrite & 0xfeU))) {
        Verilated::overWidthError("MemWrite");}
}
#endif  // VL_DEBUG
