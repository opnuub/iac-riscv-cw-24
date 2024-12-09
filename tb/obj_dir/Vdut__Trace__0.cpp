// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdut__Syms.h"


void Vdut___024root__trace_chg_sub_0(Vdut___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vdut___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_chg_top_0\n"); );
    // Init
    Vdut___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdut___024root*>(voidSelf);
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vdut___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vdut___024root__trace_chg_sub_0(Vdut___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+0,(vlSelf->top__DOT__rd1E),32);
        bufp->chgBit(oldp+1,(vlSelf->top__DOT__ALUSrcE));
        bufp->chgIData(oldp+2,(vlSelf->top__DOT__ReadDataW),32);
        bufp->chgCData(oldp+3,(vlSelf->top__DOT__ResultSrcW),2);
        bufp->chgCData(oldp+4,(vlSelf->top__DOT__Rs1E),5);
        bufp->chgCData(oldp+5,(vlSelf->top__DOT__Rs2E),5);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+6,(((IData)(4U) + vlSelf->top__DOT__pc)),32);
        bufp->chgIData(oldp+7,(((vlSelf->top__DOT__instrMemory__DOT__rom
                                 [(0xfffU & ((IData)(3U) 
                                             + vlSelf->top__DOT__pc))] 
                                 << 0x18U) | ((vlSelf->top__DOT__instrMemory__DOT__rom
                                               [(0xfffU 
                                                 & ((IData)(2U) 
                                                    + vlSelf->top__DOT__pc))] 
                                               << 0x10U) 
                                              | ((vlSelf->top__DOT__instrMemory__DOT__rom
                                                  [
                                                  (0xfffU 
                                                   & ((IData)(1U) 
                                                      + vlSelf->top__DOT__pc))] 
                                                  << 8U) 
                                                 | vlSelf->top__DOT__instrMemory__DOT__rom
                                                 [(0xfffU 
                                                   & vlSelf->top__DOT__pc)])))),32);
        bufp->chgIData(oldp+8,(vlSelf->top__DOT__pc),32);
        bufp->chgIData(oldp+9,(((IData)(vlSelf->top__DOT__jalrSrc)
                                 ? vlSelf->top__DOT__ResultW
                                 : (vlSelf->top__DOT__PCe 
                                    + vlSelf->top__DOT__ImmExtE))),32);
        bufp->chgIData(oldp+10,((((IData)(vlSelf->top__DOT__JumpE) 
                                  | ((IData)(vlSelf->top__DOT__BranchE) 
                                     & (IData)(vlSelf->top__DOT__zero)))
                                  ? ((IData)(vlSelf->top__DOT__jalrSrc)
                                      ? vlSelf->top__DOT__ResultW
                                      : (vlSelf->top__DOT__PCe 
                                         + vlSelf->top__DOT__ImmExtE))
                                  : ((IData)(4U) + vlSelf->top__DOT__pc))),32);
        bufp->chgIData(oldp+11,(vlSelf->top__DOT__PCd),32);
        bufp->chgIData(oldp+12,(vlSelf->top__DOT__PCPlus4D),32);
        bufp->chgIData(oldp+13,(vlSelf->top__DOT__ImmExtD),32);
        bufp->chgIData(oldp+14,(vlSelf->top__DOT__instrD),32);
        bufp->chgBit(oldp+15,(vlSelf->top__DOT__RegWriteD));
        bufp->chgBit(oldp+16,(vlSelf->top__DOT__MemWriteD));
        bufp->chgBit(oldp+17,(vlSelf->top__DOT__JumpD));
        bufp->chgBit(oldp+18,(vlSelf->top__DOT__BranchD));
        bufp->chgBit(oldp+19,(vlSelf->top__DOT__ALUSrcD));
        bufp->chgCData(oldp+20,(vlSelf->top__DOT__sizeSrcD),3);
        bufp->chgCData(oldp+21,(vlSelf->top__DOT__ResultSrcD),2);
        bufp->chgCData(oldp+22,(vlSelf->top__DOT__immSrcD),2);
        bufp->chgCData(oldp+23,(vlSelf->top__DOT__ALUControlD),4);
        bufp->chgIData(oldp+24,(vlSelf->top__DOT__PCe),32);
        bufp->chgIData(oldp+25,(vlSelf->top__DOT__PCPlus4E),32);
        bufp->chgIData(oldp+26,(vlSelf->top__DOT__ImmExtE),32);
        bufp->chgIData(oldp+27,(vlSelf->top__DOT__rd2E),32);
        bufp->chgIData(oldp+28,(vlSelf->top__DOT__srcB),32);
        bufp->chgIData(oldp+29,(vlSelf->top__DOT__aluResult),32);
        bufp->chgCData(oldp+30,(vlSelf->top__DOT__RdE),5);
        bufp->chgBit(oldp+31,(vlSelf->top__DOT__RegWriteE));
        bufp->chgBit(oldp+32,(vlSelf->top__DOT__MemWriteE));
        bufp->chgBit(oldp+33,(vlSelf->top__DOT__JumpE));
        bufp->chgBit(oldp+34,(vlSelf->top__DOT__BranchE));
        bufp->chgCData(oldp+35,(vlSelf->top__DOT__sizeSrcE),3);
        bufp->chgCData(oldp+36,(vlSelf->top__DOT__ResultSrcE),2);
        bufp->chgCData(oldp+37,(vlSelf->top__DOT__ALUControlE),4);
        bufp->chgIData(oldp+38,(vlSelf->top__DOT__ALUResultM),32);
        bufp->chgIData(oldp+39,(vlSelf->top__DOT__WriteDataM),32);
        bufp->chgIData(oldp+40,(vlSelf->top__DOT__ReadData),32);
        bufp->chgIData(oldp+41,(vlSelf->top__DOT__PCPlus4M),32);
        bufp->chgCData(oldp+42,(vlSelf->top__DOT__RdM),5);
        bufp->chgBit(oldp+43,(vlSelf->top__DOT__RegWriteM));
        bufp->chgBit(oldp+44,(vlSelf->top__DOT__MemWriteM));
        bufp->chgCData(oldp+45,(vlSelf->top__DOT__sizeSrcM),3);
        bufp->chgCData(oldp+46,(vlSelf->top__DOT__ResultSrcM),2);
        bufp->chgIData(oldp+47,(vlSelf->top__DOT__ALUResultW),32);
        bufp->chgIData(oldp+48,(vlSelf->top__DOT__PCPlus4W),32);
        bufp->chgIData(oldp+49,(vlSelf->top__DOT__ResultW),32);
        bufp->chgCData(oldp+50,(vlSelf->top__DOT__RdW),5);
        bufp->chgBit(oldp+51,(vlSelf->top__DOT__RegWriteW));
        bufp->chgBit(oldp+52,(vlSelf->top__DOT__Flush));
        bufp->chgBit(oldp+53,(vlSelf->top__DOT__stall));
        bufp->chgBit(oldp+54,((1U == (IData)(vlSelf->top__DOT__ResultSrcE))));
        bufp->chgCData(oldp+55,(vlSelf->top__DOT__ForwardAE),2);
        bufp->chgCData(oldp+56,(vlSelf->top__DOT__ForwardBE),2);
        bufp->chgIData(oldp+57,(vlSelf->top__DOT__SrcAE),32);
        bufp->chgIData(oldp+58,(vlSelf->top__DOT__WriteDataE),32);
        bufp->chgBit(oldp+59,(vlSelf->top__DOT__jalrSrc));
        bufp->chgBit(oldp+60,(((IData)(vlSelf->top__DOT__JumpE) 
                               | ((IData)(vlSelf->top__DOT__BranchE) 
                                  & (IData)(vlSelf->top__DOT__zero)))));
        bufp->chgBit(oldp+61,(vlSelf->top__DOT__zero));
        bufp->chgIData(oldp+62,((0x1ffffU & vlSelf->top__DOT__ALUResultM)),17);
        bufp->chgCData(oldp+63,((0x1fU & (vlSelf->top__DOT__instrD 
                                          >> 0xfU))),5);
        bufp->chgCData(oldp+64,((0x1fU & (vlSelf->top__DOT__instrD 
                                          >> 0x14U))),5);
        bufp->chgCData(oldp+65,((0x1fU & (vlSelf->top__DOT__instrD 
                                          >> 7U))),5);
        bufp->chgCData(oldp+66,((0x7fU & vlSelf->top__DOT__instrD)),7);
        bufp->chgCData(oldp+67,((7U & (vlSelf->top__DOT__instrD 
                                       >> 0xcU))),3);
        bufp->chgBit(oldp+68,((1U & (vlSelf->top__DOT__instrD 
                                     >> 0x1eU))));
        bufp->chgCData(oldp+69,(vlSelf->top__DOT__controlUnit__DOT__aluOp),2);
        bufp->chgBit(oldp+70,((1U & (vlSelf->top__DOT__instrD 
                                     >> 5U))));
        bufp->chgCData(oldp+71,(((2U & (vlSelf->top__DOT__instrD 
                                        >> 4U)) | (1U 
                                                   & (vlSelf->top__DOT__instrD 
                                                      >> 0x1eU)))),2);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[3U])) {
        bufp->chgIData(oldp+72,(vlSelf->top__DOT__regfile__DOT__rom_array[0]),32);
        bufp->chgIData(oldp+73,(vlSelf->top__DOT__regfile__DOT__rom_array[1]),32);
        bufp->chgIData(oldp+74,(vlSelf->top__DOT__regfile__DOT__rom_array[2]),32);
        bufp->chgIData(oldp+75,(vlSelf->top__DOT__regfile__DOT__rom_array[3]),32);
        bufp->chgIData(oldp+76,(vlSelf->top__DOT__regfile__DOT__rom_array[4]),32);
        bufp->chgIData(oldp+77,(vlSelf->top__DOT__regfile__DOT__rom_array[5]),32);
        bufp->chgIData(oldp+78,(vlSelf->top__DOT__regfile__DOT__rom_array[6]),32);
        bufp->chgIData(oldp+79,(vlSelf->top__DOT__regfile__DOT__rom_array[7]),32);
        bufp->chgIData(oldp+80,(vlSelf->top__DOT__regfile__DOT__rom_array[8]),32);
        bufp->chgIData(oldp+81,(vlSelf->top__DOT__regfile__DOT__rom_array[9]),32);
        bufp->chgIData(oldp+82,(vlSelf->top__DOT__regfile__DOT__rom_array[10]),32);
        bufp->chgIData(oldp+83,(vlSelf->top__DOT__regfile__DOT__rom_array[11]),32);
        bufp->chgIData(oldp+84,(vlSelf->top__DOT__regfile__DOT__rom_array[12]),32);
        bufp->chgIData(oldp+85,(vlSelf->top__DOT__regfile__DOT__rom_array[13]),32);
        bufp->chgIData(oldp+86,(vlSelf->top__DOT__regfile__DOT__rom_array[14]),32);
        bufp->chgIData(oldp+87,(vlSelf->top__DOT__regfile__DOT__rom_array[15]),32);
        bufp->chgIData(oldp+88,(vlSelf->top__DOT__regfile__DOT__rom_array[16]),32);
        bufp->chgIData(oldp+89,(vlSelf->top__DOT__regfile__DOT__rom_array[17]),32);
        bufp->chgIData(oldp+90,(vlSelf->top__DOT__regfile__DOT__rom_array[18]),32);
        bufp->chgIData(oldp+91,(vlSelf->top__DOT__regfile__DOT__rom_array[19]),32);
        bufp->chgIData(oldp+92,(vlSelf->top__DOT__regfile__DOT__rom_array[20]),32);
        bufp->chgIData(oldp+93,(vlSelf->top__DOT__regfile__DOT__rom_array[21]),32);
        bufp->chgIData(oldp+94,(vlSelf->top__DOT__regfile__DOT__rom_array[22]),32);
        bufp->chgIData(oldp+95,(vlSelf->top__DOT__regfile__DOT__rom_array[23]),32);
        bufp->chgIData(oldp+96,(vlSelf->top__DOT__regfile__DOT__rom_array[24]),32);
        bufp->chgIData(oldp+97,(vlSelf->top__DOT__regfile__DOT__rom_array[25]),32);
        bufp->chgIData(oldp+98,(vlSelf->top__DOT__regfile__DOT__rom_array[26]),32);
        bufp->chgIData(oldp+99,(vlSelf->top__DOT__regfile__DOT__rom_array[27]),32);
        bufp->chgIData(oldp+100,(vlSelf->top__DOT__regfile__DOT__rom_array[28]),32);
        bufp->chgIData(oldp+101,(vlSelf->top__DOT__regfile__DOT__rom_array[29]),32);
        bufp->chgIData(oldp+102,(vlSelf->top__DOT__regfile__DOT__rom_array[30]),32);
        bufp->chgIData(oldp+103,(vlSelf->top__DOT__regfile__DOT__rom_array[31]),32);
    }
    bufp->chgBit(oldp+104,(vlSelf->clk));
    bufp->chgBit(oldp+105,(vlSelf->rst));
    bufp->chgIData(oldp+106,(vlSelf->a0),32);
    bufp->chgIData(oldp+107,(vlSelf->top__DOT__regfile__DOT__rom_array
                             [(0x1fU & (vlSelf->top__DOT__instrD 
                                        >> 0xfU))]),32);
    bufp->chgIData(oldp+108,(vlSelf->top__DOT__regfile__DOT__rom_array
                             [(0x1fU & (vlSelf->top__DOT__instrD 
                                        >> 0x14U))]),32);
}

void Vdut___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_cleanup\n"); );
    // Init
    Vdut___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdut___024root*>(voidSelf);
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}
