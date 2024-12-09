// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbranch.h for the primary calling header

#include "verilated.h"

#include "Vbranch___024root.h"

extern const VlUnpacked<CData/*0:0*/, 64> Vbranch__ConstPool__TABLE_h1ecbf686_0;

VL_INLINE_OPT void Vbranch___024root___combo__TOP__0(Vbranch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbranch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch___024root___combo__TOP__0\n"); );
    // Init
    CData/*0:0*/ branch__DOT__equal;
    CData/*0:0*/ branch__DOT__less_than;
    CData/*0:0*/ branch__DOT__less_than_u;
    CData/*5:0*/ __Vtableidx1;
    // Body
    branch__DOT__equal = (vlSelf->rs1_data_i == vlSelf->rs2_data_i);
    branch__DOT__less_than = VL_LTS_III(32, vlSelf->rs1_data_i, vlSelf->rs2_data_i);
    branch__DOT__less_than_u = (vlSelf->rs1_data_i 
                                < vlSelf->rs2_data_i);
    vlSelf->branch_eq_o = branch__DOT__equal;
    vlSelf->branch_lt_o = branch__DOT__less_than;
    vlSelf->branch_ltu_o = branch__DOT__less_than_u;
    __Vtableidx1 = (((IData)(branch__DOT__equal) << 5U) 
                    | (((IData)(branch__DOT__less_than) 
                        << 4U) | (((IData)(branch__DOT__less_than_u) 
                                   << 3U) | (IData)(vlSelf->funct3_i))));
    vlSelf->branch_taken_o = Vbranch__ConstPool__TABLE_h1ecbf686_0
        [__Vtableidx1];
}

void Vbranch___024root___eval(Vbranch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbranch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch___024root___eval\n"); );
    // Body
    Vbranch___024root___combo__TOP__0(vlSelf);
}

#ifdef VL_DEBUG
void Vbranch___024root___eval_debug_assertions(Vbranch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbranch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->funct3_i & 0xf8U))) {
        Verilated::overWidthError("funct3_i");}
}
#endif  // VL_DEBUG
