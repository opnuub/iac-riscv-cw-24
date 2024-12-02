// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+12,"clk", false,-1);
    tracep->declBit(c+13,"rst", false,-1);
    tracep->declBit(c+14,"PCsrcE", false,-1);
    tracep->declBus(c+15,"PCTargetE", false,-1, 31,0);
    tracep->declBus(c+16,"InstrD", false,-1, 31,0);
    tracep->declBus(c+17,"PCd", false,-1, 31,0);
    tracep->declBus(c+18,"PCPlus4D", false,-1, 31,0);
    tracep->pushNamePrefix("top ");
    tracep->declBus(c+20,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+12,"clk", false,-1);
    tracep->declBit(c+13,"rst", false,-1);
    tracep->declBit(c+14,"PCsrcE", false,-1);
    tracep->declBus(c+15,"PCTargetE", false,-1, 31,0);
    tracep->declBus(c+16,"InstrD", false,-1, 31,0);
    tracep->declBus(c+17,"PCd", false,-1, 31,0);
    tracep->declBus(c+18,"PCPlus4D", false,-1, 31,0);
    tracep->declBus(c+19,"PCFp", false,-1, 31,0);
    tracep->declBus(c+1,"PCf", false,-1, 31,0);
    tracep->declBus(c+2,"PCPlus4F", false,-1, 31,0);
    tracep->declBus(c+3,"Rd", false,-1, 31,0);
    tracep->pushNamePrefix("PCReg ");
    tracep->declBus(c+20,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+19,"PCFp", false,-1, 31,0);
    tracep->declBit(c+12,"clk", false,-1);
    tracep->declBit(c+13,"rst", false,-1);
    tracep->declBus(c+1,"PCf", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("PRegFetch ");
    tracep->declBus(c+20,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+21,"REG_DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+3,"Rd", false,-1, 31,0);
    tracep->declBus(c+1,"PCf", false,-1, 31,0);
    tracep->declBus(c+2,"PCPlus4F", false,-1, 31,0);
    tracep->declBit(c+12,"clk", false,-1);
    tracep->declBus(c+18,"PCPlus4D", false,-1, 31,0);
    tracep->declBus(c+17,"PCd", false,-1, 31,0);
    tracep->declBus(c+16,"InstrD", false,-1, 31,0);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+4+i*1,"rom_array", true,(i+0), 31,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("adder ");
    tracep->declBus(c+20,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+1,"PCf", false,-1, 31,0);
    tracep->declBus(c+2,"PCPlus4F", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("fakeinstmem ");
    tracep->declBus(c+20,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+1,"PCf", false,-1, 31,0);
    tracep->declBus(c+3,"Rd", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("mux ");
    tracep->declBus(c+20,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+2,"PCPlus4F", false,-1, 31,0);
    tracep->declBus(c+15,"PCTargetE", false,-1, 31,0);
    tracep->declBit(c+14,"PCsrcE", false,-1);
    tracep->declBus(c+19,"PCFp", false,-1, 31,0);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vtop___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vtop___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->top__DOT__PCf),32);
    bufp->fullIData(oldp+2,(((IData)(4U) + vlSelf->top__DOT__PCf)),32);
    bufp->fullIData(oldp+3,(((IData)(0xaU) + vlSelf->top__DOT__PCf)),32);
    bufp->fullIData(oldp+4,(vlSelf->top__DOT__PRegFetch__DOT__rom_array[0]),32);
    bufp->fullIData(oldp+5,(vlSelf->top__DOT__PRegFetch__DOT__rom_array[1]),32);
    bufp->fullIData(oldp+6,(vlSelf->top__DOT__PRegFetch__DOT__rom_array[2]),32);
    bufp->fullIData(oldp+7,(vlSelf->top__DOT__PRegFetch__DOT__rom_array[3]),32);
    bufp->fullIData(oldp+8,(vlSelf->top__DOT__PRegFetch__DOT__rom_array[4]),32);
    bufp->fullIData(oldp+9,(vlSelf->top__DOT__PRegFetch__DOT__rom_array[5]),32);
    bufp->fullIData(oldp+10,(vlSelf->top__DOT__PRegFetch__DOT__rom_array[6]),32);
    bufp->fullIData(oldp+11,(vlSelf->top__DOT__PRegFetch__DOT__rom_array[7]),32);
    bufp->fullBit(oldp+12,(vlSelf->clk));
    bufp->fullBit(oldp+13,(vlSelf->rst));
    bufp->fullBit(oldp+14,(vlSelf->PCsrcE));
    bufp->fullIData(oldp+15,(vlSelf->PCTargetE),32);
    bufp->fullIData(oldp+16,(vlSelf->InstrD),32);
    bufp->fullIData(oldp+17,(vlSelf->PCd),32);
    bufp->fullIData(oldp+18,(vlSelf->PCPlus4D),32);
    bufp->fullIData(oldp+19,(((IData)(vlSelf->PCsrcE)
                               ? vlSelf->PCTargetE : 
                              ((IData)(4U) + vlSelf->top__DOT__PCf))),32);
    bufp->fullIData(oldp+20,(0x20U),32);
    bufp->fullIData(oldp+21,(3U),32);
}
