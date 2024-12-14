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
        bufp->chgCData(oldp+0,(vlSelfRef.L1Cache__DOT__state),3);
        bufp->chgIData(oldp+1,(vlSelfRef.L1Cache__DOT__lru),32);
        bufp->chgIData(oldp+2,(vlSelfRef.L1Cache__DOT__unnamedblk1__DOT__i),32);
    }
    bufp->chgBit(oldp+3,(vlSelfRef.clk));
    bufp->chgBit(oldp+4,(vlSelfRef.rst_n));
    bufp->chgBit(oldp+5,(vlSelfRef.load));
    bufp->chgBit(oldp+6,(vlSelfRef.store));
    bufp->chgIData(oldp+7,(vlSelfRef.address),32);
    bufp->chgIData(oldp+8,(vlSelfRef.data_in),32);
    bufp->chgIData(oldp+9,(vlSelfRef.mem_data),32);
    bufp->chgBit(oldp+10,(vlSelfRef.mem_ready));
    bufp->chgBit(oldp+11,(vlSelfRef.hit));
    bufp->chgBit(oldp+12,(vlSelfRef.miss));
    bufp->chgBit(oldp+13,(vlSelfRef.mem_write));
    bufp->chgBit(oldp+14,(vlSelfRef.mem_read));
    bufp->chgBit(oldp+15,(vlSelfRef.busy));
    bufp->chgIData(oldp+16,(vlSelfRef.data_out),32);
    bufp->chgIData(oldp+17,(vlSelfRef.mem_write_data),32);
    bufp->chgIData(oldp+18,((vlSelfRef.address >> 7U)),25);
    bufp->chgCData(oldp+19,((0x1fU & (vlSelfRef.address 
                                      >> 2U))),5);
    bufp->chgBit(oldp+20,(vlSelfRef.L1Cache__DOT__way));
    bufp->chgBit(oldp+21,(vlSelfRef.L1Cache__DOT__hit_way));
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
