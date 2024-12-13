// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdut__Syms.h"


void Vdut___024root__trace_chg_0_sub_0(Vdut___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vdut___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_chg_0\n"); );
    // Init
    Vdut___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdut___024root*>(voidSelf);
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vdut___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vdut___024root__trace_chg_0_sub_0(Vdut___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_chg_0_sub_0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+0,(((IData)(4U) + vlSelfRef.top__DOT__pc)),32);
        bufp->chgIData(oldp+1,(((vlSelfRef.top__DOT__instrMemory__DOT__rom
                                 [(0xfffU & ((IData)(3U) 
                                             + vlSelfRef.top__DOT__pc))] 
                                 << 0x18U) | ((vlSelfRef.top__DOT__instrMemory__DOT__rom
                                               [(0xfffU 
                                                 & ((IData)(2U) 
                                                    + vlSelfRef.top__DOT__pc))] 
                                               << 0x10U) 
                                              | ((vlSelfRef.top__DOT__instrMemory__DOT__rom
                                                  [
                                                  (0xfffU 
                                                   & ((IData)(1U) 
                                                      + vlSelfRef.top__DOT__pc))] 
                                                  << 8U) 
                                                 | vlSelfRef.top__DOT__instrMemory__DOT__rom
                                                 [(0xfffU 
                                                   & vlSelfRef.top__DOT__pc)])))),32);
        bufp->chgIData(oldp+2,(vlSelfRef.top__DOT__pc),32);
        bufp->chgIData(oldp+3,((((IData)(vlSelfRef.top__DOT__JalrE)
                                  ? vlSelfRef.top__DOT__rd1E
                                  : vlSelfRef.top__DOT__PCe) 
                                + vlSelfRef.top__DOT__ImmExtE)),32);
        bufp->chgIData(oldp+4,(vlSelfRef.top__DOT__PCd),32);
        bufp->chgIData(oldp+5,(vlSelfRef.top__DOT__PCPlus4D),32);
        bufp->chgIData(oldp+6,(vlSelfRef.top__DOT__instrD),32);
        bufp->chgIData(oldp+7,(vlSelfRef.top__DOT__PCe),32);
        bufp->chgIData(oldp+8,(((IData)(vlSelfRef.top__DOT__JalrE)
                                 ? vlSelfRef.top__DOT__rd1E
                                 : vlSelfRef.top__DOT__PCe)),32);
        bufp->chgIData(oldp+9,(vlSelfRef.top__DOT__PCPlus4E),32);
        bufp->chgIData(oldp+10,(vlSelfRef.top__DOT__ImmExtE),32);
        bufp->chgIData(oldp+11,(vlSelfRef.top__DOT__rd1E),32);
        bufp->chgIData(oldp+12,(vlSelfRef.top__DOT__rd2E),32);
        bufp->chgCData(oldp+13,(vlSelfRef.top__DOT__RdE),5);
        bufp->chgBit(oldp+14,(vlSelfRef.top__DOT__RegWriteE));
        bufp->chgBit(oldp+15,(vlSelfRef.top__DOT__JumpE));
        bufp->chgBit(oldp+16,(vlSelfRef.top__DOT__BranchE));
        bufp->chgBit(oldp+17,(vlSelfRef.top__DOT__ALUSrcE));
        bufp->chgCData(oldp+18,(vlSelfRef.top__DOT__ResultSrcE),2);
        bufp->chgCData(oldp+19,(vlSelfRef.top__DOT__ALUControlE),4);
        bufp->chgIData(oldp+20,(vlSelfRef.top__DOT__PCPlus4M),32);
        bufp->chgCData(oldp+21,(vlSelfRef.top__DOT__RdM),5);
        bufp->chgBit(oldp+22,(vlSelfRef.top__DOT__RegWriteM));
        bufp->chgCData(oldp+23,(vlSelfRef.top__DOT__ResultSrcM),2);
        bufp->chgIData(oldp+24,(vlSelfRef.top__DOT__ALUResultW),32);
        bufp->chgIData(oldp+25,(vlSelfRef.top__DOT__ReadDataW),32);
        bufp->chgIData(oldp+26,(vlSelfRef.top__DOT__PCPlus4W),32);
        bufp->chgIData(oldp+27,(vlSelfRef.top__DOT__ResultW),32);
        bufp->chgCData(oldp+28,(vlSelfRef.top__DOT__RdW),5);
        bufp->chgBit(oldp+29,(vlSelfRef.top__DOT__RegWriteW));
        bufp->chgCData(oldp+30,(vlSelfRef.top__DOT__ResultSrcW),2);
        bufp->chgBit(oldp+31,((1U == (IData)(vlSelfRef.top__DOT__ResultSrcE))));
        bufp->chgCData(oldp+32,(vlSelfRef.top__DOT__ForwardAE),2);
        bufp->chgCData(oldp+33,(vlSelfRef.top__DOT__ForwardBE),2);
        bufp->chgCData(oldp+34,(vlSelfRef.top__DOT__Rs1E),5);
        bufp->chgCData(oldp+35,(vlSelfRef.top__DOT__Rs2E),5);
        bufp->chgBit(oldp+36,(vlSelfRef.top__DOT__JalrE));
        bufp->chgCData(oldp+37,((0x1fU & (vlSelfRef.top__DOT__instrD 
                                          >> 0xfU))),5);
        bufp->chgCData(oldp+38,((0x1fU & (vlSelfRef.top__DOT__instrD 
                                          >> 0x14U))),5);
        bufp->chgIData(oldp+39,(vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+40,(vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+41,((0x1fU & (vlSelfRef.top__DOT__instrD 
                                          >> 7U))),5);
        bufp->chgCData(oldp+42,((0x7fU & vlSelfRef.top__DOT__instrD)),7);
        bufp->chgCData(oldp+43,((7U & (vlSelfRef.top__DOT__instrD 
                                       >> 0xcU))),3);
        bufp->chgBit(oldp+44,((1U & (vlSelfRef.top__DOT__instrD 
                                     >> 0x1eU))));
        bufp->chgBit(oldp+45,((1U & (vlSelfRef.top__DOT__instrD 
                                     >> 5U))));
        bufp->chgCData(oldp+46,(((2U & (vlSelfRef.top__DOT__instrD 
                                        >> 4U)) | (1U 
                                                   & (vlSelfRef.top__DOT__instrD 
                                                      >> 0x1eU)))),2);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+47,(vlSelfRef.top__DOT__regfile__DOT__rom_array[0]),32);
        bufp->chgIData(oldp+48,(vlSelfRef.top__DOT__regfile__DOT__rom_array[1]),32);
        bufp->chgIData(oldp+49,(vlSelfRef.top__DOT__regfile__DOT__rom_array[2]),32);
        bufp->chgIData(oldp+50,(vlSelfRef.top__DOT__regfile__DOT__rom_array[3]),32);
        bufp->chgIData(oldp+51,(vlSelfRef.top__DOT__regfile__DOT__rom_array[4]),32);
        bufp->chgIData(oldp+52,(vlSelfRef.top__DOT__regfile__DOT__rom_array[5]),32);
        bufp->chgIData(oldp+53,(vlSelfRef.top__DOT__regfile__DOT__rom_array[6]),32);
        bufp->chgIData(oldp+54,(vlSelfRef.top__DOT__regfile__DOT__rom_array[7]),32);
        bufp->chgIData(oldp+55,(vlSelfRef.top__DOT__regfile__DOT__rom_array[8]),32);
        bufp->chgIData(oldp+56,(vlSelfRef.top__DOT__regfile__DOT__rom_array[9]),32);
        bufp->chgIData(oldp+57,(vlSelfRef.top__DOT__regfile__DOT__rom_array[10]),32);
        bufp->chgIData(oldp+58,(vlSelfRef.top__DOT__regfile__DOT__rom_array[11]),32);
        bufp->chgIData(oldp+59,(vlSelfRef.top__DOT__regfile__DOT__rom_array[12]),32);
        bufp->chgIData(oldp+60,(vlSelfRef.top__DOT__regfile__DOT__rom_array[13]),32);
        bufp->chgIData(oldp+61,(vlSelfRef.top__DOT__regfile__DOT__rom_array[14]),32);
        bufp->chgIData(oldp+62,(vlSelfRef.top__DOT__regfile__DOT__rom_array[15]),32);
        bufp->chgIData(oldp+63,(vlSelfRef.top__DOT__regfile__DOT__rom_array[16]),32);
        bufp->chgIData(oldp+64,(vlSelfRef.top__DOT__regfile__DOT__rom_array[17]),32);
        bufp->chgIData(oldp+65,(vlSelfRef.top__DOT__regfile__DOT__rom_array[18]),32);
        bufp->chgIData(oldp+66,(vlSelfRef.top__DOT__regfile__DOT__rom_array[19]),32);
        bufp->chgIData(oldp+67,(vlSelfRef.top__DOT__regfile__DOT__rom_array[20]),32);
        bufp->chgIData(oldp+68,(vlSelfRef.top__DOT__regfile__DOT__rom_array[21]),32);
        bufp->chgIData(oldp+69,(vlSelfRef.top__DOT__regfile__DOT__rom_array[22]),32);
        bufp->chgIData(oldp+70,(vlSelfRef.top__DOT__regfile__DOT__rom_array[23]),32);
        bufp->chgIData(oldp+71,(vlSelfRef.top__DOT__regfile__DOT__rom_array[24]),32);
        bufp->chgIData(oldp+72,(vlSelfRef.top__DOT__regfile__DOT__rom_array[25]),32);
        bufp->chgIData(oldp+73,(vlSelfRef.top__DOT__regfile__DOT__rom_array[26]),32);
        bufp->chgIData(oldp+74,(vlSelfRef.top__DOT__regfile__DOT__rom_array[27]),32);
        bufp->chgIData(oldp+75,(vlSelfRef.top__DOT__regfile__DOT__rom_array[28]),32);
        bufp->chgIData(oldp+76,(vlSelfRef.top__DOT__regfile__DOT__rom_array[29]),32);
        bufp->chgIData(oldp+77,(vlSelfRef.top__DOT__regfile__DOT__rom_array[30]),32);
        bufp->chgIData(oldp+78,(vlSelfRef.top__DOT__regfile__DOT__rom_array[31]),32);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[3U])) {
        bufp->chgIData(oldp+79,(vlSelfRef.top__DOT__ImmExtD),32);
        bufp->chgBit(oldp+80,(vlSelfRef.top__DOT__RegWriteD));
        bufp->chgBit(oldp+81,(vlSelfRef.top__DOT__MemWriteD));
        bufp->chgBit(oldp+82,(vlSelfRef.top__DOT__JumpD));
        bufp->chgBit(oldp+83,(vlSelfRef.top__DOT__BranchD));
        bufp->chgBit(oldp+84,(vlSelfRef.top__DOT__ALUSrcD));
        bufp->chgCData(oldp+85,(vlSelfRef.top__DOT__sizeSrcD),3);
        bufp->chgCData(oldp+86,(vlSelfRef.top__DOT__ResultSrcD),2);
        bufp->chgCData(oldp+87,(vlSelfRef.top__DOT__immSrcD),2);
        bufp->chgCData(oldp+88,(vlSelfRef.top__DOT__ALUControlD),4);
        bufp->chgIData(oldp+89,(vlSelfRef.top__DOT__srcB),32);
        bufp->chgIData(oldp+90,(vlSelfRef.top__DOT__aluResult),32);
        bufp->chgBit(oldp+91,(vlSelfRef.top__DOT__MemWriteE));
        bufp->chgCData(oldp+92,(vlSelfRef.top__DOT__sizeSrcE),3);
        bufp->chgIData(oldp+93,(vlSelfRef.top__DOT__ALUResultM),32);
        bufp->chgIData(oldp+94,(vlSelfRef.top__DOT__WriteDataM),32);
        bufp->chgBit(oldp+95,(vlSelfRef.top__DOT__MemWriteM));
        bufp->chgCData(oldp+96,(vlSelfRef.top__DOT__sizeSrcM),3);
        bufp->chgIData(oldp+97,(vlSelfRef.top__DOT__SrcAE),32);
        bufp->chgIData(oldp+98,(vlSelfRef.top__DOT__WriteDataE),32);
        bufp->chgBit(oldp+99,(vlSelfRef.top__DOT__jalrSrc));
        bufp->chgBit(oldp+100,(vlSelfRef.top__DOT__zero));
        bufp->chgIData(oldp+101,((0x1ffffU & vlSelfRef.top__DOT__ALUResultM)),17);
        bufp->chgBit(oldp+102,(vlSelfRef.top__DOT__MemoryController__DOT__l1_hit));
        bufp->chgBit(oldp+103,(vlSelfRef.top__DOT__MemoryController__DOT__l1_miss));
        bufp->chgBit(oldp+104,(vlSelfRef.top__DOT__MemoryController__DOT__l1_mem_write));
        bufp->chgBit(oldp+105,(vlSelfRef.top__DOT__MemoryController__DOT__l1_mem_read));
        bufp->chgBit(oldp+106,(vlSelfRef.top__DOT__MemoryController__DOT__l1_busy));
        bufp->chgIData(oldp+107,(vlSelfRef.top__DOT__MemoryController__DOT__l1_data_out),32);
        bufp->chgIData(oldp+108,(vlSelfRef.top__DOT__MemoryController__DOT__l1_mem_write_data),32);
        bufp->chgBit(oldp+109,(vlSelfRef.top__DOT__MemoryController__DOT__l2_hit));
        bufp->chgBit(oldp+110,(vlSelfRef.top__DOT__MemoryController__DOT__l2_miss));
        bufp->chgBit(oldp+111,(vlSelfRef.top__DOT__MemoryController__DOT__l2_mem_write));
        bufp->chgBit(oldp+112,(vlSelfRef.top__DOT__MemoryController__DOT__l2_mem_read));
        bufp->chgBit(oldp+113,(vlSelfRef.top__DOT__MemoryController__DOT__l2_busy));
        bufp->chgIData(oldp+114,(vlSelfRef.top__DOT__MemoryController__DOT__l2_data_out),32);
        bufp->chgIData(oldp+115,(vlSelfRef.top__DOT__MemoryController__DOT__l2_mem_write_data),32);
        bufp->chgBit(oldp+116,(vlSelfRef.top__DOT__MemoryController__DOT__l3_hit));
        bufp->chgBit(oldp+117,(vlSelfRef.top__DOT__MemoryController__DOT__l3_busy));
        bufp->chgIData(oldp+118,(vlSelfRef.top__DOT__MemoryController__DOT__l3_data_out),32);
        bufp->chgBit(oldp+119,(vlSelfRef.top__DOT__MemoryController__DOT__mem_access));
        bufp->chgBit(oldp+120,(vlSelfRef.top__DOT__MemoryController__DOT____Vcellinp__l1_cache__load));
        bufp->chgBit(oldp+121,(vlSelfRef.top__DOT__MemoryController__DOT____Vcellinp__l1_cache__store));
        bufp->chgIData(oldp+122,((0x1ffffU & vlSelfRef.top__DOT__ALUResultM)),32);
        bufp->chgBit(oldp+123,((1U & (~ (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l2_busy)))));
        bufp->chgCData(oldp+124,(vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__state),3);
        bufp->chgIData(oldp+125,(vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__lru),32);
        bufp->chgIData(oldp+126,((0x3ffU & (vlSelfRef.top__DOT__ALUResultM 
                                            >> 7U))),25);
        bufp->chgCData(oldp+127,((0x1fU & (vlSelfRef.top__DOT__ALUResultM 
                                           >> 2U))),5);
        bufp->chgBit(oldp+128,(vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__way));
        bufp->chgBit(oldp+129,(vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__hit_way));
        bufp->chgBit(oldp+130,((1U & (~ (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l3_busy)))));
        bufp->chgQData(oldp+131,(vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__lru),64);
        bufp->chgIData(oldp+133,((0x1ffU & (vlSelfRef.top__DOT__ALUResultM 
                                            >> 8U))),24);
        bufp->chgCData(oldp+134,((0x3fU & (vlSelfRef.top__DOT__ALUResultM 
                                           >> 2U))),6);
        bufp->chgBit(oldp+135,(vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__hit_way));
        bufp->chgBit(oldp+136,(vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__way));
        bufp->chgCData(oldp+137,(vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__state),3);
        bufp->chgBit(oldp+138,(vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__stall));
        bufp->chgBit(oldp+139,(vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__mem_read));
        bufp->chgBit(oldp+140,(vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__mem_write));
        bufp->chgIData(oldp+141,(vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__mem_address),32);
        bufp->chgIData(oldp+142,(vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__mem_write_data),32);
        bufp->chgCData(oldp+143,((0xffU & (vlSelfRef.top__DOT__ALUResultM 
                                           >> 4U))),8);
        bufp->chgCData(oldp+144,((0xfU & vlSelfRef.top__DOT__ALUResultM)),4);
        bufp->chgSData(oldp+145,((0x1fU & (vlSelfRef.top__DOT__ALUResultM 
                                           >> 0xcU))),14);
        bufp->chgCData(oldp+146,(vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__state),2);
        bufp->chgIData(oldp+147,(vlSelfRef.top__DOT__MemoryController__DOT__l3_cache__DOT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+148,(vlSelfRef.top__DOT__controlUnit__DOT__aluOp),2);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[4U])) {
        bufp->chgIData(oldp+149,(vlSelfRef.top__DOT__ReadData),32);
        bufp->chgBit(oldp+150,(vlSelfRef.top__DOT__FlushD));
        bufp->chgBit(oldp+151,(vlSelfRef.top__DOT__FlushE));
        bufp->chgBit(oldp+152,(vlSelfRef.top__DOT__stall));
        bufp->chgBit(oldp+153,(vlSelfRef.top__DOT__MemReady));
        bufp->chgBit(oldp+154,((1U & (~ (IData)(vlSelfRef.top__DOT__MemReady)))));
        bufp->chgBit(oldp+155,(vlSelfRef.top__DOT__HazardUnit__DOT__load_use_hazard));
        bufp->chgBit(oldp+156,(vlSelfRef.top__DOT__HazardUnit__DOT__control_hazard));
        bufp->chgIData(oldp+157,(vlSelfRef.top__DOT__MemoryController__DOT__main_mem_data),32);
    }
    bufp->chgBit(oldp+158,(vlSelfRef.clk));
    bufp->chgBit(oldp+159,(vlSelfRef.rst));
    bufp->chgIData(oldp+160,(vlSelfRef.a0),32);
    bufp->chgIData(oldp+161,((((IData)(vlSelfRef.top__DOT__JumpE) 
                               | ((IData)(vlSelfRef.top__DOT__BranchE) 
                                  & (IData)(vlSelfRef.top__DOT__zero)))
                               ? (((IData)(vlSelfRef.top__DOT__JalrE)
                                    ? vlSelfRef.top__DOT__rd1E
                                    : vlSelfRef.top__DOT__PCe) 
                                  + vlSelfRef.top__DOT__ImmExtE)
                               : ((IData)(4U) + vlSelfRef.top__DOT__pc))),32);
    bufp->chgIData(oldp+162,(vlSelfRef.top__DOT__regfile__DOT__rom_array
                             [(0x1fU & (vlSelfRef.top__DOT__instrD 
                                        >> 0xfU))]),32);
    bufp->chgIData(oldp+163,(vlSelfRef.top__DOT__regfile__DOT__rom_array
                             [(0x1fU & (vlSelfRef.top__DOT__instrD 
                                        >> 0x14U))]),32);
    bufp->chgBit(oldp+164,(((IData)(vlSelfRef.top__DOT__JumpE) 
                            | ((IData)(vlSelfRef.top__DOT__BranchE) 
                               & (IData)(vlSelfRef.top__DOT__zero)))));
    bufp->chgBit(oldp+165,((1U & (~ (IData)(vlSelfRef.rst)))));
    bufp->chgIData(oldp+166,(vlSelfRef.top__DOT__MemoryController__DOT__main_memory
                             [vlSelfRef.top__DOT__MemoryController__DOT__s0]),32);
    bufp->chgBit(oldp+167,(vlSelfRef.top__DOT__MemoryController__DOT__main_mem_ready_reg));
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
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
}
