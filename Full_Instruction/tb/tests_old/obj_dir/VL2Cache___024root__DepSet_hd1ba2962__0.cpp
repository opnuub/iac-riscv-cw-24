// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VL2Cache.h for the primary calling header

#include "VL2Cache__pch.h"
#include "VL2Cache__Syms.h"
#include "VL2Cache___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VL2Cache___024root___dump_triggers__ico(VL2Cache___024root* vlSelf);
#endif  // VL_DEBUG

void VL2Cache___024root___eval_triggers__ico(VL2Cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VL2Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL2Cache___024root___eval_triggers__ico\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered.set(0U, (IData)(vlSelfRef.__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VL2Cache___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VL2Cache___024root___dump_triggers__act(VL2Cache___024root* vlSelf);
#endif  // VL_DEBUG

void VL2Cache___024root___eval_triggers__act(VL2Cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VL2Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL2Cache___024root___eval_triggers__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, (((IData)(vlSelfRef.clk) 
                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))) 
                                       | ((~ (IData)(vlSelfRef.rst_n)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.rst_n;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VL2Cache___024root___dump_triggers__act(vlSelf);
    }
#endif
}
