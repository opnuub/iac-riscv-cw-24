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
        bufp->chgIData(oldp+0,(vlSelfRef.top__DOT__dmem__DOT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+1,(vlSelfRef.top__DOT__regfile__DOT__rf_reg[0]),32);
        bufp->chgIData(oldp+2,(vlSelfRef.top__DOT__regfile__DOT__rf_reg[1]),32);
        bufp->chgIData(oldp+3,(vlSelfRef.top__DOT__regfile__DOT__rf_reg[2]),32);
        bufp->chgIData(oldp+4,(vlSelfRef.top__DOT__regfile__DOT__rf_reg[3]),32);
        bufp->chgIData(oldp+5,(vlSelfRef.top__DOT__regfile__DOT__rf_reg[4]),32);
        bufp->chgIData(oldp+6,(vlSelfRef.top__DOT__regfile__DOT__rf_reg[5]),32);
        bufp->chgIData(oldp+7,(vlSelfRef.top__DOT__regfile__DOT__rf_reg[6]),32);
        bufp->chgIData(oldp+8,(vlSelfRef.top__DOT__regfile__DOT__rf_reg[7]),32);
        bufp->chgIData(oldp+9,(vlSelfRef.top__DOT__regfile__DOT__rf_reg[8]),32);
        bufp->chgIData(oldp+10,(vlSelfRef.top__DOT__regfile__DOT__rf_reg[9]),32);
        bufp->chgIData(oldp+11,(vlSelfRef.top__DOT__regfile__DOT__rf_reg[10]),32);
        bufp->chgIData(oldp+12,(vlSelfRef.top__DOT__regfile__DOT__rf_reg[11]),32);
        bufp->chgIData(oldp+13,(vlSelfRef.top__DOT__regfile__DOT__rf_reg[12]),32);
        bufp->chgIData(oldp+14,(vlSelfRef.top__DOT__regfile__DOT__rf_reg[13]),32);
        bufp->chgIData(oldp+15,(vlSelfRef.top__DOT__regfile__DOT__rf_reg[14]),32);
        bufp->chgIData(oldp+16,(vlSelfRef.top__DOT__regfile__DOT__rf_reg[15]),32);
        bufp->chgIData(oldp+17,(vlSelfRef.top__DOT__regfile__DOT__rf_reg[16]),32);
        bufp->chgIData(oldp+18,(vlSelfRef.top__DOT__regfile__DOT__rf_reg[17]),32);
        bufp->chgIData(oldp+19,(vlSelfRef.top__DOT__regfile__DOT__rf_reg[18]),32);
        bufp->chgIData(oldp+20,(vlSelfRef.top__DOT__regfile__DOT__rf_reg[19]),32);
        bufp->chgIData(oldp+21,(vlSelfRef.top__DOT__regfile__DOT__rf_reg[20]),32);
        bufp->chgIData(oldp+22,(vlSelfRef.top__DOT__regfile__DOT__rf_reg[21]),32);
        bufp->chgIData(oldp+23,(vlSelfRef.top__DOT__regfile__DOT__rf_reg[22]),32);
        bufp->chgIData(oldp+24,(vlSelfRef.top__DOT__regfile__DOT__rf_reg[23]),32);
        bufp->chgIData(oldp+25,(vlSelfRef.top__DOT__regfile__DOT__rf_reg[24]),32);
        bufp->chgIData(oldp+26,(vlSelfRef.top__DOT__regfile__DOT__rf_reg[25]),32);
        bufp->chgIData(oldp+27,(vlSelfRef.top__DOT__regfile__DOT__rf_reg[26]),32);
        bufp->chgIData(oldp+28,(vlSelfRef.top__DOT__regfile__DOT__rf_reg[27]),32);
        bufp->chgIData(oldp+29,(vlSelfRef.top__DOT__regfile__DOT__rf_reg[28]),32);
        bufp->chgIData(oldp+30,(vlSelfRef.top__DOT__regfile__DOT__rf_reg[29]),32);
        bufp->chgIData(oldp+31,(vlSelfRef.top__DOT__regfile__DOT__rf_reg[30]),32);
        bufp->chgIData(oldp+32,(vlSelfRef.top__DOT__regfile__DOT__rf_reg[31]),32);
        bufp->chgIData(oldp+33,(vlSelfRef.top__DOT__regfile__DOT__unnamedblk1__DOT__i),32);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+34,(vlSelfRef.top__DOT__instr),32);
        bufp->chgCData(oldp+35,((0x7fU & vlSelfRef.top__DOT__instr)),7);
        bufp->chgCData(oldp+36,((7U & (vlSelfRef.top__DOT__instr 
                                       >> 0xcU))),3);
        bufp->chgCData(oldp+37,((vlSelfRef.top__DOT__instr 
                                 >> 0x19U)),7);
        bufp->chgCData(oldp+38,((0x1fU & (vlSelfRef.top__DOT__instr 
                                          >> 0xfU))),5);
        bufp->chgCData(oldp+39,((0x1fU & (vlSelfRef.top__DOT__instr 
                                          >> 0x14U))),5);
        bufp->chgCData(oldp+40,((0x1fU & (vlSelfRef.top__DOT__instr 
                                          >> 7U))),5);
        bufp->chgIData(oldp+41,(vlSelfRef.top__DOT__imm),32);
        bufp->chgBit(oldp+42,(vlSelfRef.top__DOT__rf_wen));
        bufp->chgCData(oldp+43,(vlSelfRef.top__DOT__rf_wdata_sel),2);
        bufp->chgCData(oldp+44,(vlSelfRef.top__DOT__alu_op),4);
        bufp->chgCData(oldp+45,(vlSelfRef.top__DOT__alu_src1_sel),2);
        bufp->chgCData(oldp+46,(vlSelfRef.top__DOT__alu_src2_sel),2);
        bufp->chgBit(oldp+47,(vlSelfRef.top__DOT__mem_wen));
        bufp->chgCData(oldp+48,(vlSelfRef.top__DOT__mem_size),3);
        bufp->chgBit(oldp+49,(vlSelfRef.top__DOT__mem_signed));
        bufp->chgBit(oldp+50,(vlSelfRef.top__DOT__illegal_instr));
        bufp->chgCData(oldp+51,(vlSelfRef.top__DOT__controller__DOT__imm_type_o),3);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[3U])) {
        bufp->chgIData(oldp+52,(vlSelfRef.top__DOT__rs1_data),32);
        bufp->chgIData(oldp+53,(vlSelfRef.top__DOT__rs2_data),32);
        bufp->chgIData(oldp+54,(vlSelfRef.top__DOT__alu_result),32);
        bufp->chgIData(oldp+55,(vlSelfRef.top__DOT__dmem__DOT__rdata_aligned),32);
        bufp->chgBit(oldp+56,(vlSelfRef.top__DOT__branch_eq));
        bufp->chgBit(oldp+57,(vlSelfRef.top__DOT__branch_lt));
        bufp->chgBit(oldp+58,(vlSelfRef.top__DOT__branch_ltu));
        bufp->chgCData(oldp+59,(vlSelfRef.top__DOT__next_pc_sel),3);
        bufp->chgIData(oldp+60,(vlSelfRef.top__DOT__alu_src1),32);
        bufp->chgIData(oldp+61,(vlSelfRef.top__DOT__alu_src2),32);
        bufp->chgIData(oldp+62,(VL_LTS_III(32, vlSelfRef.top__DOT__alu_src1, vlSelfRef.top__DOT__alu_src2)),32);
        bufp->chgIData(oldp+63,((vlSelfRef.top__DOT__alu_src1 
                                 < vlSelfRef.top__DOT__alu_src2)),32);
        bufp->chgIData(oldp+64,((vlSelfRef.top__DOT__alu_src1 
                                 << (0x1fU & vlSelfRef.top__DOT__alu_src2))),32);
        bufp->chgIData(oldp+65,((vlSelfRef.top__DOT__alu_src1 
                                 >> (0x1fU & vlSelfRef.top__DOT__alu_src2))),32);
        bufp->chgIData(oldp+66,(VL_SHIFTRS_III(32,32,5, vlSelfRef.top__DOT__alu_src1, 
                                               (0x1fU 
                                                & vlSelfRef.top__DOT__alu_src2))),32);
        bufp->chgBit(oldp+67,(vlSelfRef.top__DOT__branch__DOT__branch_taken_o));
    }
    bufp->chgBit(oldp+68,(vlSelfRef.clk_i));
    bufp->chgBit(oldp+69,(vlSelfRef.rst_ni));
    bufp->chgIData(oldp+70,(vlSelfRef.a0_o),32);
    bufp->chgIData(oldp+71,(vlSelfRef.top__DOT__pcunit__DOT__pc_q),32);
    bufp->chgIData(oldp+72,(((0U == (IData)(vlSelfRef.top__DOT__rf_wdata_sel))
                              ? vlSelfRef.top__DOT__alu_result
                              : ((1U == (IData)(vlSelfRef.top__DOT__rf_wdata_sel))
                                  ? vlSelfRef.top__DOT__dmem__DOT__rdata_aligned
                                  : ((2U == (IData)(vlSelfRef.top__DOT__rf_wdata_sel))
                                      ? ((IData)(4U) 
                                         + vlSelfRef.top__DOT__pcunit__DOT__pc_q)
                                      : vlSelfRef.top__DOT__alu_result)))),32);
    bufp->chgIData(oldp+73,(((1U == (IData)(vlSelfRef.top__DOT__alu_op))
                              ? (vlSelfRef.top__DOT__alu_src1 
                                 - vlSelfRef.top__DOT__alu_src2)
                              : (vlSelfRef.top__DOT__alu_src1 
                                 + vlSelfRef.top__DOT__alu_src2))),32);
    bufp->chgIData(oldp+74,(((4U & (IData)(vlSelfRef.top__DOT__next_pc_sel))
                              ? ((IData)(4U) + vlSelfRef.top__DOT__pcunit__DOT__pc_q)
                              : ((2U & (IData)(vlSelfRef.top__DOT__next_pc_sel))
                                  ? ((1U & (IData)(vlSelfRef.top__DOT__next_pc_sel))
                                      ? (0xfffffffeU 
                                         & vlSelfRef.top__DOT__alu_result)
                                      : (vlSelfRef.top__DOT__pcunit__DOT__pc_q 
                                         + vlSelfRef.top__DOT__imm))
                                  : ((1U & (IData)(vlSelfRef.top__DOT__next_pc_sel))
                                      ? (vlSelfRef.top__DOT__pcunit__DOT__pc_q 
                                         + vlSelfRef.top__DOT__imm)
                                      : ((IData)(4U) 
                                         + vlSelfRef.top__DOT__pcunit__DOT__pc_q))))),32);
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
