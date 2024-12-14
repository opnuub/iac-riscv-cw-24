// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VHazardUnit__Syms.h"


void VHazardUnit___024root__trace_chg_0_sub_0(VHazardUnit___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VHazardUnit___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VHazardUnit___024root__trace_chg_0\n"); );
    // Init
    VHazardUnit___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VHazardUnit___024root*>(voidSelf);
    VHazardUnit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VHazardUnit___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void VHazardUnit___024root__trace_chg_0_sub_0(VHazardUnit___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    VHazardUnit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VHazardUnit___024root__trace_chg_0_sub_0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgCData(oldp+0,(vlSelfRef.Rs1E),5);
    bufp->chgCData(oldp+1,(vlSelfRef.Rs2E),5);
    bufp->chgCData(oldp+2,(vlSelfRef.Rs1D),5);
    bufp->chgCData(oldp+3,(vlSelfRef.Rs2D),5);
    bufp->chgCData(oldp+4,(vlSelfRef.RdE),5);
    bufp->chgCData(oldp+5,(vlSelfRef.destReg_m),5);
    bufp->chgCData(oldp+6,(vlSelfRef.destReg_w),5);
    bufp->chgBit(oldp+7,(vlSelfRef.memoryRead_e));
    bufp->chgBit(oldp+8,(vlSelfRef.RegWriteM));
    bufp->chgBit(oldp+9,(vlSelfRef.RegWriteW));
    bufp->chgBit(oldp+10,(vlSelfRef.zero_hazard));
    bufp->chgBit(oldp+11,(vlSelfRef.jump_hazard));
    bufp->chgCData(oldp+12,(vlSelfRef.ForwardAE),2);
    bufp->chgCData(oldp+13,(vlSelfRef.ForwardBE),2);
    bufp->chgBit(oldp+14,(vlSelfRef.stall));
    bufp->chgBit(oldp+15,(vlSelfRef.Flush));
}

void VHazardUnit___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VHazardUnit___024root__trace_cleanup\n"); );
    // Init
    VHazardUnit___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VHazardUnit___024root*>(voidSelf);
    VHazardUnit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
