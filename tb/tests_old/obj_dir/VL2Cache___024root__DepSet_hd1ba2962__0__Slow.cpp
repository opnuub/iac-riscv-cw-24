// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VL2Cache.h for the primary calling header

#include "VL2Cache__pch.h"
#include "VL2Cache__Syms.h"
#include "VL2Cache___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VL2Cache___024root___dump_triggers__stl(VL2Cache___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void VL2Cache___024root___eval_triggers__stl(VL2Cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VL2Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL2Cache___024root___eval_triggers__stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.set(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VL2Cache___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
