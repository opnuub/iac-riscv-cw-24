// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VbranchUnit__Syms.h"


void VbranchUnit___024root__trace_chg_0_sub_0(VbranchUnit___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VbranchUnit___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VbranchUnit___024root__trace_chg_0\n"); );
    // Init
    VbranchUnit___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VbranchUnit___024root*>(voidSelf);
    VbranchUnit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VbranchUnit___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void VbranchUnit___024root__trace_chg_0_sub_0(VbranchUnit___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    VbranchUnit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VbranchUnit___024root__trace_chg_0_sub_0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgIData(oldp+0,(vlSelfRef.srcA),32);
    bufp->chgIData(oldp+1,(vlSelfRef.srcB),32);
    bufp->chgCData(oldp+2,(vlSelfRef.aluControl),4);
    bufp->chgBit(oldp+3,(vlSelfRef.zero));
}

void VbranchUnit___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VbranchUnit___024root__trace_cleanup\n"); );
    // Init
    VbranchUnit___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VbranchUnit___024root*>(voidSelf);
    VbranchUnit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
