// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VL1Cache__Syms.h"


void VL1Cache___024root__trace_chg_0_sub_0(VL1Cache___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VL1Cache___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL1Cache___024root__trace_chg_0\n"); );
    // Init
    VL1Cache___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VL1Cache___024root*>(voidSelf);
    VL1Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VL1Cache___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void VL1Cache___024root__trace_chg_0_sub_0(VL1Cache___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    VL1Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL1Cache___024root__trace_chg_0_sub_0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+0,(vlSelfRef.L1Cache__DOT__index),8);
        bufp->chgCData(oldp+1,(vlSelfRef.L1Cache__DOT__offset),2);
        bufp->chgIData(oldp+2,(vlSelfRef.L1Cache__DOT__unnamedblk1__DOT__i),32);
    }
    bufp->chgBit(oldp+3,(vlSelfRef.clk));
    bufp->chgBit(oldp+4,(vlSelfRef.reset));
    bufp->chgIData(oldp+5,(vlSelfRef.address),32);
    bufp->chgIData(oldp+6,(vlSelfRef.writeData),32);
    bufp->chgBit(oldp+7,(vlSelfRef.writeEnable));
    bufp->chgIData(oldp+8,(vlSelfRef.readData),32);
    bufp->chgBit(oldp+9,(vlSelfRef.hit));
}

void VL1Cache___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL1Cache___024root__trace_cleanup\n"); );
    // Init
    VL1Cache___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VL1Cache___024root*>(voidSelf);
    VL1Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
