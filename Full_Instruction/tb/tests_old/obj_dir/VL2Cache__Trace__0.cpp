// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VL2Cache__Syms.h"


void VL2Cache___024root__trace_chg_0_sub_0(VL2Cache___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VL2Cache___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL2Cache___024root__trace_chg_0\n"); );
    // Init
    VL2Cache___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VL2Cache___024root*>(voidSelf);
    VL2Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VL2Cache___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void VL2Cache___024root__trace_chg_0_sub_0(VL2Cache___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    VL2Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL2Cache___024root__trace_chg_0_sub_0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+0,(vlSelfRef.L2Cache__DOT__state),3);
        bufp->chgQData(oldp+1,(vlSelfRef.L2Cache__DOT__lru),64);
        bufp->chgIData(oldp+3,(vlSelfRef.L2Cache__DOT__unnamedblk1__DOT__i),32);
    }
    bufp->chgBit(oldp+4,(vlSelfRef.clk));
    bufp->chgBit(oldp+5,(vlSelfRef.rst_n));
    bufp->chgBit(oldp+6,(vlSelfRef.load));
    bufp->chgBit(oldp+7,(vlSelfRef.store));
    bufp->chgIData(oldp+8,(vlSelfRef.address),32);
    bufp->chgIData(oldp+9,(vlSelfRef.data_in),32);
    bufp->chgIData(oldp+10,(vlSelfRef.mem_data),32);
    bufp->chgBit(oldp+11,(vlSelfRef.mem_ready));
    bufp->chgBit(oldp+12,(vlSelfRef.hit));
    bufp->chgBit(oldp+13,(vlSelfRef.miss));
    bufp->chgBit(oldp+14,(vlSelfRef.mem_write));
    bufp->chgBit(oldp+15,(vlSelfRef.mem_read));
    bufp->chgBit(oldp+16,(vlSelfRef.busy));
    bufp->chgIData(oldp+17,(vlSelfRef.data_out),32);
    bufp->chgIData(oldp+18,(vlSelfRef.mem_write_data),32);
    bufp->chgIData(oldp+19,((vlSelfRef.address >> 8U)),24);
    bufp->chgCData(oldp+20,((0x3fU & (vlSelfRef.address 
                                      >> 2U))),6);
    bufp->chgBit(oldp+21,(vlSelfRef.L2Cache__DOT__way));
    bufp->chgBit(oldp+22,(vlSelfRef.L2Cache__DOT__hit_way));
}

void VL2Cache___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL2Cache___024root__trace_cleanup\n"); );
    // Init
    VL2Cache___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VL2Cache___024root*>(voidSelf);
    VL2Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
