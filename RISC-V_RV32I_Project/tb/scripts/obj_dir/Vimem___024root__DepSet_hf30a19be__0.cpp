// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vimem.h for the primary calling header

#include "Vimem__pch.h"
#include "Vimem__Syms.h"
#include "Vimem___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vimem___024root___dump_triggers__act(Vimem___024root* vlSelf);
#endif  // VL_DEBUG

void Vimem___024root___eval_triggers__act(Vimem___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vimem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vimem___024root___eval_triggers__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, ((IData)(vlSelfRef.clk_i) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk_i__0))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk_i__0 = vlSelfRef.clk_i;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vimem___024root___dump_triggers__act(vlSelf);
    }
#endif
}
