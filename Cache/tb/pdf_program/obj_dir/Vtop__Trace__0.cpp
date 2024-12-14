// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U] 
                     | vlSelfRef.__Vm_traceActivity
                     [3U]))) {
        bufp->chgIData(oldp+0,(vlSelfRef.top__DOT__immOp),32);
        bufp->chgBit(oldp+1,(vlSelfRef.top__DOT__regWrite));
        bufp->chgCData(oldp+2,(vlSelfRef.top__DOT__aluControl),3);
        bufp->chgBit(oldp+3,(vlSelfRef.top__DOT__aluSrc));
        bufp->chgCData(oldp+4,(vlSelfRef.top__DOT__immSrc),2);
        bufp->chgBit(oldp+5,(vlSelfRef.top__DOT__jalrSrc));
        bufp->chgBit(oldp+6,(vlSelfRef.top__DOT__jumpSrc));
        bufp->chgBit(oldp+7,(vlSelfRef.top__DOT__pcSrc));
        bufp->chgIData(oldp+8,(vlSelfRef.top__DOT__srcB),32);
        bufp->chgIData(oldp+9,(vlSelfRef.top__DOT__aluResult),32);
        bufp->chgBit(oldp+10,(vlSelfRef.top__DOT__resultSrc));
        bufp->chgBit(oldp+11,(vlSelfRef.top__DOT__memWrite));
        bufp->chgIData(oldp+12,(vlSelfRef.top__DOT__readData),32);
        bufp->chgIData(oldp+13,(vlSelfRef.top__DOT__result),32);
        bufp->chgCData(oldp+14,(vlSelfRef.top__DOT__controlUnit__DOT__aluOp),2);
        bufp->chgIData(oldp+15,((0x1ffffU & vlSelfRef.top__DOT__aluResult)),17);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+16,(vlSelfRef.top__DOT__pc),32);
        bufp->chgIData(oldp+17,(vlSelfRef.top__DOT__instr),32);
        bufp->chgIData(oldp+18,(vlSelfRef.top__DOT__srcA),32);
        bufp->chgIData(oldp+19,(vlSelfRef.top__DOT__regOp2),32);
        bufp->chgIData(oldp+20,(((IData)(4U) + vlSelfRef.top__DOT__pc)),32);
        bufp->chgCData(oldp+21,((0x7fU & vlSelfRef.top__DOT__instrMemory__DOT__rom
                                 [(0xfffU & vlSelfRef.top__DOT__pc)])),7);
        bufp->chgCData(oldp+22,(vlSelfRef.top__DOT____Vcellinp__dataMemory__SizeCtr),3);
        bufp->chgBit(oldp+23,((1U & (vlSelfRef.top__DOT__instrMemory__DOT__rom
                                     [(0xfffU & ((IData)(3U) 
                                                 + vlSelfRef.top__DOT__pc))] 
                                     >> 6U))));
        bufp->chgBit(oldp+24,((1U & (vlSelfRef.top__DOT__instrMemory__DOT__rom
                                     [(0xfffU & vlSelfRef.top__DOT__pc)] 
                                     >> 5U))));
        bufp->chgCData(oldp+25,(((2U & (vlSelfRef.top__DOT__instrMemory__DOT__rom
                                        [(0xfffU & vlSelfRef.top__DOT__pc)] 
                                        >> 4U)) | (1U 
                                                   & (vlSelfRef.top__DOT__instrMemory__DOT__rom
                                                      [
                                                      (0xfffU 
                                                       & ((IData)(3U) 
                                                          + vlSelfRef.top__DOT__pc))] 
                                                      >> 6U)))),2);
        bufp->chgCData(oldp+26,((0x1fU & (vlSelfRef.__VdfgRegularize_h6171c202_0_1 
                                          >> 0xfU))),5);
        bufp->chgCData(oldp+27,((0x1fU & (vlSelfRef.top__DOT__instr 
                                          >> 0x14U))),5);
        bufp->chgCData(oldp+28,((0x1fU & ((IData)(vlSelfRef.__VdfgRegularize_h6171c202_0_0) 
                                          >> 7U))),5);
        bufp->chgIData(oldp+29,(vlSelfRef.top__DOT__regFile__DOT__rom_array[0]),32);
        bufp->chgIData(oldp+30,(vlSelfRef.top__DOT__regFile__DOT__rom_array[1]),32);
        bufp->chgIData(oldp+31,(vlSelfRef.top__DOT__regFile__DOT__rom_array[2]),32);
        bufp->chgIData(oldp+32,(vlSelfRef.top__DOT__regFile__DOT__rom_array[3]),32);
        bufp->chgIData(oldp+33,(vlSelfRef.top__DOT__regFile__DOT__rom_array[4]),32);
        bufp->chgIData(oldp+34,(vlSelfRef.top__DOT__regFile__DOT__rom_array[5]),32);
        bufp->chgIData(oldp+35,(vlSelfRef.top__DOT__regFile__DOT__rom_array[6]),32);
        bufp->chgIData(oldp+36,(vlSelfRef.top__DOT__regFile__DOT__rom_array[7]),32);
        bufp->chgIData(oldp+37,(vlSelfRef.top__DOT__regFile__DOT__rom_array[8]),32);
        bufp->chgIData(oldp+38,(vlSelfRef.top__DOT__regFile__DOT__rom_array[9]),32);
        bufp->chgIData(oldp+39,(vlSelfRef.top__DOT__regFile__DOT__rom_array[10]),32);
        bufp->chgIData(oldp+40,(vlSelfRef.top__DOT__regFile__DOT__rom_array[11]),32);
        bufp->chgIData(oldp+41,(vlSelfRef.top__DOT__regFile__DOT__rom_array[12]),32);
        bufp->chgIData(oldp+42,(vlSelfRef.top__DOT__regFile__DOT__rom_array[13]),32);
        bufp->chgIData(oldp+43,(vlSelfRef.top__DOT__regFile__DOT__rom_array[14]),32);
        bufp->chgIData(oldp+44,(vlSelfRef.top__DOT__regFile__DOT__rom_array[15]),32);
        bufp->chgIData(oldp+45,(vlSelfRef.top__DOT__regFile__DOT__rom_array[16]),32);
        bufp->chgIData(oldp+46,(vlSelfRef.top__DOT__regFile__DOT__rom_array[17]),32);
        bufp->chgIData(oldp+47,(vlSelfRef.top__DOT__regFile__DOT__rom_array[18]),32);
        bufp->chgIData(oldp+48,(vlSelfRef.top__DOT__regFile__DOT__rom_array[19]),32);
        bufp->chgIData(oldp+49,(vlSelfRef.top__DOT__regFile__DOT__rom_array[20]),32);
        bufp->chgIData(oldp+50,(vlSelfRef.top__DOT__regFile__DOT__rom_array[21]),32);
        bufp->chgIData(oldp+51,(vlSelfRef.top__DOT__regFile__DOT__rom_array[22]),32);
        bufp->chgIData(oldp+52,(vlSelfRef.top__DOT__regFile__DOT__rom_array[23]),32);
        bufp->chgIData(oldp+53,(vlSelfRef.top__DOT__regFile__DOT__rom_array[24]),32);
        bufp->chgIData(oldp+54,(vlSelfRef.top__DOT__regFile__DOT__rom_array[25]),32);
        bufp->chgIData(oldp+55,(vlSelfRef.top__DOT__regFile__DOT__rom_array[26]),32);
        bufp->chgIData(oldp+56,(vlSelfRef.top__DOT__regFile__DOT__rom_array[27]),32);
        bufp->chgIData(oldp+57,(vlSelfRef.top__DOT__regFile__DOT__rom_array[28]),32);
        bufp->chgIData(oldp+58,(vlSelfRef.top__DOT__regFile__DOT__rom_array[29]),32);
        bufp->chgIData(oldp+59,(vlSelfRef.top__DOT__regFile__DOT__rom_array[30]),32);
        bufp->chgIData(oldp+60,(vlSelfRef.top__DOT__regFile__DOT__rom_array[31]),32);
    }
    bufp->chgBit(oldp+61,(vlSelfRef.clk));
    bufp->chgBit(oldp+62,(vlSelfRef.rst));
    bufp->chgBit(oldp+63,(vlSelfRef.trigger));
    bufp->chgIData(oldp+64,(vlSelfRef.a0),32);
    bufp->chgIData(oldp+65,(((IData)(vlSelfRef.top__DOT__jumpSrc)
                              ? ((IData)(4U) + vlSelfRef.top__DOT__pc)
                              : vlSelfRef.top__DOT__result)),32);
    bufp->chgBit(oldp+66,(((4U & (IData)(vlSelfRef.top__DOT__aluControl))
                            ? ((2U & (IData)(vlSelfRef.top__DOT__aluControl))
                                ? ((1U & (IData)(vlSelfRef.top__DOT__aluControl))
                                    ? (vlSelfRef.top__DOT__srcA 
                                       >= vlSelfRef.top__DOT__regOp2)
                                    : (vlSelfRef.top__DOT__srcA 
                                       < vlSelfRef.top__DOT__regOp2))
                                : ((1U & (IData)(vlSelfRef.top__DOT__aluControl))
                                    ? VL_GTES_III(32, vlSelfRef.top__DOT__srcA, vlSelfRef.top__DOT__regOp2)
                                    : VL_LTS_III(32, vlSelfRef.top__DOT__srcA, vlSelfRef.top__DOT__regOp2)))
                            : ((1U & (~ ((IData)(vlSelfRef.top__DOT__aluControl) 
                                         >> 1U))) && 
                               ((1U & (IData)(vlSelfRef.top__DOT__aluControl))
                                 ? (0U != (vlSelfRef.top__DOT__srcA 
                                           - vlSelfRef.top__DOT__regOp2))
                                 : (0U == (vlSelfRef.top__DOT__srcA 
                                           - vlSelfRef.top__DOT__regOp2)))))));
    bufp->chgIData(oldp+67,(((IData)(vlSelfRef.top__DOT__pcSrc)
                              ? ((IData)(vlSelfRef.top__DOT__jalrSrc)
                                  ? vlSelfRef.top__DOT__result
                                  : (vlSelfRef.top__DOT__immOp 
                                     + vlSelfRef.top__DOT__pc))
                              : ((IData)(4U) + vlSelfRef.top__DOT__pc))),32);
    bufp->chgIData(oldp+68,(((IData)(vlSelfRef.top__DOT__jalrSrc)
                              ? vlSelfRef.top__DOT__result
                              : (vlSelfRef.top__DOT__immOp 
                                 + vlSelfRef.top__DOT__pc))),32);
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
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}
