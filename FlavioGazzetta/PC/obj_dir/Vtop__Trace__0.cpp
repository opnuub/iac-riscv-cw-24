// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+0,(vlSelf->top__DOT__PCf),32);
        bufp->chgIData(oldp+1,(((IData)(4U) + vlSelf->top__DOT__PCf)),32);
        bufp->chgIData(oldp+2,(((IData)(0xaU) + vlSelf->top__DOT__PCf)),32);
        bufp->chgIData(oldp+3,(vlSelf->top__DOT__PRegFetch__DOT__rom_array[0]),32);
        bufp->chgIData(oldp+4,(vlSelf->top__DOT__PRegFetch__DOT__rom_array[1]),32);
        bufp->chgIData(oldp+5,(vlSelf->top__DOT__PRegFetch__DOT__rom_array[2]),32);
        bufp->chgIData(oldp+6,(vlSelf->top__DOT__PRegFetch__DOT__rom_array[3]),32);
        bufp->chgIData(oldp+7,(vlSelf->top__DOT__PRegFetch__DOT__rom_array[4]),32);
        bufp->chgIData(oldp+8,(vlSelf->top__DOT__PRegFetch__DOT__rom_array[5]),32);
        bufp->chgIData(oldp+9,(vlSelf->top__DOT__PRegFetch__DOT__rom_array[6]),32);
        bufp->chgIData(oldp+10,(vlSelf->top__DOT__PRegFetch__DOT__rom_array[7]),32);
    }
    bufp->chgBit(oldp+11,(vlSelf->clk));
    bufp->chgBit(oldp+12,(vlSelf->rst));
    bufp->chgBit(oldp+13,(vlSelf->PCsrcE));
    bufp->chgIData(oldp+14,(vlSelf->PCTargetE),32);
    bufp->chgIData(oldp+15,(vlSelf->InstrD),32);
    bufp->chgIData(oldp+16,(vlSelf->PCd),32);
    bufp->chgIData(oldp+17,(vlSelf->PCPlus4D),32);
    bufp->chgIData(oldp+18,(((IData)(vlSelf->PCsrcE)
                              ? vlSelf->PCTargetE : 
                             ((IData)(4U) + vlSelf->top__DOT__PCf))),32);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
