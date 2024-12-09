// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdut.h for the primary calling header

#include "verilated.h"

#include "Vdut___024root.h"

VL_INLINE_OPT void Vdut___024root___sequent__TOP__0(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___sequent__TOP__0\n"); );
    // Body
    vlSelf->top__DOT__ALUSrcE = ((~ (IData)(vlSelf->rst)) 
                                 & ((~ (IData)(vlSelf->top__DOT__Flush)) 
                                    & (IData)(vlSelf->top__DOT__ALUSrcD)));
    if (vlSelf->rst) {
        vlSelf->top__DOT__rd1E = 0U;
        vlSelf->top__DOT__Rs1E = 0U;
        vlSelf->top__DOT__Rs2E = 0U;
        vlSelf->top__DOT__ReadDataW = 0U;
        vlSelf->top__DOT__ResultSrcW = 0U;
    } else {
        if (vlSelf->top__DOT__Flush) {
            vlSelf->top__DOT__rd1E = 0U;
            vlSelf->top__DOT__Rs1E = 0U;
            vlSelf->top__DOT__Rs2E = 0U;
        } else {
            vlSelf->top__DOT__rd1E = vlSelf->top__DOT__regfile__DOT__rom_array
                [(0x1fU & (vlSelf->top__DOT__instrD 
                           >> 0xfU))];
            vlSelf->top__DOT__Rs1E = (0x1fU & (vlSelf->top__DOT__instrD 
                                               >> 0xfU));
            vlSelf->top__DOT__Rs2E = (0x1fU & (vlSelf->top__DOT__instrD 
                                               >> 0x14U));
        }
        vlSelf->top__DOT__ReadDataW = vlSelf->top__DOT__ReadData;
        vlSelf->top__DOT__ResultSrcW = vlSelf->top__DOT__ResultSrcM;
    }
}

VL_INLINE_OPT void Vdut___024root___sequent__TOP__1(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___sequent__TOP__1\n"); );
    // Body
    vlSelf->__Vdlyvset__top__DOT__regfile__DOT__rom_array__v0 = 0U;
    if (((IData)(vlSelf->top__DOT__RegWriteW) & (0U 
                                                 != (IData)(vlSelf->top__DOT__RdW)))) {
        vlSelf->__Vdlyvval__top__DOT__regfile__DOT__rom_array__v0 
            = vlSelf->top__DOT__ResultW;
        vlSelf->__Vdlyvset__top__DOT__regfile__DOT__rom_array__v0 = 1U;
        vlSelf->__Vdlyvdim0__top__DOT__regfile__DOT__rom_array__v0 
            = vlSelf->top__DOT__RdW;
    }
}

VL_INLINE_OPT void Vdut___024root___sequent__TOP__2(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___sequent__TOP__2\n"); );
    // Init
    IData/*16:0*/ __Vdlyvdim0__top__DOT__DataMemory__DOT__memory__v0;
    CData/*7:0*/ __Vdlyvval__top__DOT__DataMemory__DOT__memory__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__DataMemory__DOT__memory__v0;
    IData/*16:0*/ __Vdlyvdim0__top__DOT__DataMemory__DOT__memory__v1;
    CData/*7:0*/ __Vdlyvval__top__DOT__DataMemory__DOT__memory__v1;
    IData/*16:0*/ __Vdlyvdim0__top__DOT__DataMemory__DOT__memory__v2;
    CData/*7:0*/ __Vdlyvval__top__DOT__DataMemory__DOT__memory__v2;
    IData/*16:0*/ __Vdlyvdim0__top__DOT__DataMemory__DOT__memory__v3;
    CData/*7:0*/ __Vdlyvval__top__DOT__DataMemory__DOT__memory__v3;
    IData/*16:0*/ __Vdlyvdim0__top__DOT__DataMemory__DOT__memory__v4;
    CData/*7:0*/ __Vdlyvval__top__DOT__DataMemory__DOT__memory__v4;
    CData/*0:0*/ __Vdlyvset__top__DOT__DataMemory__DOT__memory__v4;
    IData/*16:0*/ __Vdlyvdim0__top__DOT__DataMemory__DOT__memory__v5;
    CData/*7:0*/ __Vdlyvval__top__DOT__DataMemory__DOT__memory__v5;
    IData/*16:0*/ __Vdlyvdim0__top__DOT__DataMemory__DOT__memory__v6;
    CData/*7:0*/ __Vdlyvval__top__DOT__DataMemory__DOT__memory__v6;
    CData/*0:0*/ __Vdlyvset__top__DOT__DataMemory__DOT__memory__v6;
    // Body
    __Vdlyvset__top__DOT__DataMemory__DOT__memory__v0 = 0U;
    __Vdlyvset__top__DOT__DataMemory__DOT__memory__v4 = 0U;
    __Vdlyvset__top__DOT__DataMemory__DOT__memory__v6 = 0U;
    VL_WRITEF("a0: %10#\na1: %10#\nt1: %10#\n \n********** Pipeline Debug **********\nFetch Stage:\nCurrent PC: %x, Fetched Instruction: %x\nNext PC: %x, PC+4: %x\nDecode Stage:\nInstruction Decode: rd: %0#, rs1: %0#, rs2: %0#\nDecoded Immediate: %x, Branch: %b, Jump: %b, ALU Src: %b, ALU Control D: %b\nControl Signals: RegWrite: %b, MemWrite: %b, ResultSrc: %b\nExecute Stage:\nALU Inputs: SrcA: %10#, SrcB: %10#, ALU Control: %b\nALU Output: %10#, Zero: %b, PC Target: %x\nControl Signals: Branch: %b, Jump: %b, RegWrite: %b\n",
              32,vlSelf->top__DOT__regfile__DOT__rom_array
              [0xaU],32,vlSelf->top__DOT__regfile__DOT__rom_array
              [0xbU],32,vlSelf->top__DOT__regfile__DOT__rom_array
              [6U],32,vlSelf->top__DOT__pc,32,((vlSelf->top__DOT__instrMemory__DOT__rom
                                                [(0xfffU 
                                                  & ((IData)(3U) 
                                                     + vlSelf->top__DOT__pc))] 
                                                << 0x18U) 
                                               | ((vlSelf->top__DOT__instrMemory__DOT__rom
                                                   [
                                                   (0xfffU 
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
                                                     [
                                                     (0xfffU 
                                                      & vlSelf->top__DOT__pc)]))),
              32,(((IData)(vlSelf->top__DOT__JumpE) 
                   | ((IData)(vlSelf->top__DOT__BranchE) 
                      & (IData)(vlSelf->top__DOT__zero)))
                   ? ((IData)(vlSelf->top__DOT__jalrSrc)
                       ? vlSelf->top__DOT__ResultW : 
                      (vlSelf->top__DOT__PCe + vlSelf->top__DOT__ImmExtE))
                   : ((IData)(4U) + vlSelf->top__DOT__pc)),
              32,((IData)(4U) + vlSelf->top__DOT__pc),
              5,(0x1fU & (vlSelf->top__DOT__instrD 
                          >> 7U)),5,(0x1fU & (vlSelf->top__DOT__instrD 
                                              >> 0xfU)),
              5,(0x1fU & (vlSelf->top__DOT__instrD 
                          >> 0x14U)),32,vlSelf->top__DOT__ImmExtD,
              1,(IData)(vlSelf->top__DOT__BranchD),
              1,vlSelf->top__DOT__JumpD,1,(IData)(vlSelf->top__DOT__ALUSrcD),
              4,vlSelf->top__DOT__ALUControlD,1,(IData)(vlSelf->top__DOT__RegWriteD),
              1,vlSelf->top__DOT__MemWriteD,2,(IData)(vlSelf->top__DOT__ResultSrcD),
              32,vlSelf->top__DOT__SrcAE,32,vlSelf->top__DOT__srcB,
              4,(IData)(vlSelf->top__DOT__ALUControlE),
              32,vlSelf->top__DOT__aluResult,1,(IData)(vlSelf->top__DOT__zero),
              32,((IData)(vlSelf->top__DOT__jalrSrc)
                   ? vlSelf->top__DOT__ResultW : (vlSelf->top__DOT__PCe 
                                                  + vlSelf->top__DOT__ImmExtE)),
              1,(IData)(vlSelf->top__DOT__BranchE),
              1,vlSelf->top__DOT__JumpE,1,(IData)(vlSelf->top__DOT__RegWriteE));
    VL_WRITEF("Forwarding: ForwardAE: %b, ForwardBE: %b\nMemory Stage:\nMemory Address: %x, Write Data: %x, Read Data: %x\nControl Signals: MemWrite: %b, RegWrite: %b, ResultSrc: %b\nWrite-Back Stage:\nWrite Back Data: %x, ALU Result: %x, PC+4: %x\nDestination Register: %0#, RegWrite: %b\nHazard Unit:\nFlush Signal: %b, Stall Signal: %b\nForwarding: ForwardAE: %b, ForwardBE: %b\n************************************\n",
              2,vlSelf->top__DOT__ForwardAE,2,(IData)(vlSelf->top__DOT__ForwardBE),
              32,vlSelf->top__DOT__ALUResultM,32,vlSelf->top__DOT__WriteDataM,
              32,vlSelf->top__DOT__ReadData,1,(IData)(vlSelf->top__DOT__MemWriteM),
              1,vlSelf->top__DOT__RegWriteM,2,(IData)(vlSelf->top__DOT__ResultSrcM),
              32,vlSelf->top__DOT__ResultW,32,vlSelf->top__DOT__ALUResultW,
              32,vlSelf->top__DOT__PCPlus4W,5,(IData)(vlSelf->top__DOT__RdW),
              1,vlSelf->top__DOT__RegWriteW,1,(IData)(vlSelf->top__DOT__Flush),
              1,vlSelf->top__DOT__stall,2,(IData)(vlSelf->top__DOT__ForwardAE),
              2,vlSelf->top__DOT__ForwardBE);
    if (vlSelf->top__DOT__MemWriteM) {
        if ((2U == (IData)(vlSelf->top__DOT__sizeSrcM))) {
            __Vdlyvval__top__DOT__DataMemory__DOT__memory__v0 
                = (0xffU & vlSelf->top__DOT__WriteDataM);
            __Vdlyvset__top__DOT__DataMemory__DOT__memory__v0 = 1U;
            __Vdlyvdim0__top__DOT__DataMemory__DOT__memory__v0 
                = (0x1ffffU & vlSelf->top__DOT__ALUResultM);
            __Vdlyvval__top__DOT__DataMemory__DOT__memory__v1 
                = (0xffU & (vlSelf->top__DOT__WriteDataM 
                            >> 8U));
            __Vdlyvdim0__top__DOT__DataMemory__DOT__memory__v1 
                = (0x1ffffU & ((IData)(1U) + vlSelf->top__DOT__ALUResultM));
            __Vdlyvval__top__DOT__DataMemory__DOT__memory__v2 
                = (0xffU & (vlSelf->top__DOT__WriteDataM 
                            >> 0x10U));
            __Vdlyvdim0__top__DOT__DataMemory__DOT__memory__v2 
                = (0x1ffffU & ((IData)(2U) + vlSelf->top__DOT__ALUResultM));
            __Vdlyvval__top__DOT__DataMemory__DOT__memory__v3 
                = (vlSelf->top__DOT__WriteDataM >> 0x18U);
            __Vdlyvdim0__top__DOT__DataMemory__DOT__memory__v3 
                = (0x1ffffU & ((IData)(3U) + vlSelf->top__DOT__ALUResultM));
        } else if ((1U == (IData)(vlSelf->top__DOT__sizeSrcM))) {
            __Vdlyvval__top__DOT__DataMemory__DOT__memory__v4 
                = (0xffU & vlSelf->top__DOT__WriteDataM);
            __Vdlyvset__top__DOT__DataMemory__DOT__memory__v4 = 1U;
            __Vdlyvdim0__top__DOT__DataMemory__DOT__memory__v4 
                = (0x1ffffU & vlSelf->top__DOT__ALUResultM);
            __Vdlyvval__top__DOT__DataMemory__DOT__memory__v5 
                = (0xffU & (vlSelf->top__DOT__WriteDataM 
                            >> 8U));
            __Vdlyvdim0__top__DOT__DataMemory__DOT__memory__v5 
                = (0x1ffffU & ((IData)(1U) + vlSelf->top__DOT__ALUResultM));
        } else if ((0U == (IData)(vlSelf->top__DOT__sizeSrcM))) {
            __Vdlyvval__top__DOT__DataMemory__DOT__memory__v6 
                = (0xffU & vlSelf->top__DOT__WriteDataM);
            __Vdlyvset__top__DOT__DataMemory__DOT__memory__v6 = 1U;
            __Vdlyvdim0__top__DOT__DataMemory__DOT__memory__v6 
                = (0x1ffffU & vlSelf->top__DOT__ALUResultM);
        }
    }
    if (__Vdlyvset__top__DOT__DataMemory__DOT__memory__v0) {
        vlSelf->top__DOT__DataMemory__DOT__memory[__Vdlyvdim0__top__DOT__DataMemory__DOT__memory__v0] 
            = __Vdlyvval__top__DOT__DataMemory__DOT__memory__v0;
        vlSelf->top__DOT__DataMemory__DOT__memory[__Vdlyvdim0__top__DOT__DataMemory__DOT__memory__v1] 
            = __Vdlyvval__top__DOT__DataMemory__DOT__memory__v1;
        vlSelf->top__DOT__DataMemory__DOT__memory[__Vdlyvdim0__top__DOT__DataMemory__DOT__memory__v2] 
            = __Vdlyvval__top__DOT__DataMemory__DOT__memory__v2;
        vlSelf->top__DOT__DataMemory__DOT__memory[__Vdlyvdim0__top__DOT__DataMemory__DOT__memory__v3] 
            = __Vdlyvval__top__DOT__DataMemory__DOT__memory__v3;
    }
    if (__Vdlyvset__top__DOT__DataMemory__DOT__memory__v4) {
        vlSelf->top__DOT__DataMemory__DOT__memory[__Vdlyvdim0__top__DOT__DataMemory__DOT__memory__v4] 
            = __Vdlyvval__top__DOT__DataMemory__DOT__memory__v4;
        vlSelf->top__DOT__DataMemory__DOT__memory[__Vdlyvdim0__top__DOT__DataMemory__DOT__memory__v5] 
            = __Vdlyvval__top__DOT__DataMemory__DOT__memory__v5;
    }
    if (__Vdlyvset__top__DOT__DataMemory__DOT__memory__v6) {
        vlSelf->top__DOT__DataMemory__DOT__memory[__Vdlyvdim0__top__DOT__DataMemory__DOT__memory__v6] 
            = __Vdlyvval__top__DOT__DataMemory__DOT__memory__v6;
    }
}

extern const VlUnpacked<CData/*0:0*/, 1024> Vdut__ConstPool__TABLE_h22d5d5a1_0;
extern const VlUnpacked<CData/*0:0*/, 1024> Vdut__ConstPool__TABLE_h45afa79b_0;
extern const VlUnpacked<CData/*0:0*/, 1024> Vdut__ConstPool__TABLE_hab2b96bc_0;
extern const VlUnpacked<CData/*1:0*/, 1024> Vdut__ConstPool__TABLE_h65b6ba1e_0;
extern const VlUnpacked<CData/*1:0*/, 1024> Vdut__ConstPool__TABLE_hf6daef67_0;
extern const VlUnpacked<CData/*0:0*/, 1024> Vdut__ConstPool__TABLE_hff092405_0;
extern const VlUnpacked<CData/*0:0*/, 1024> Vdut__ConstPool__TABLE_hacf877fb_0;
extern const VlUnpacked<CData/*0:0*/, 1024> Vdut__ConstPool__TABLE_h087dd5e0_0;
extern const VlUnpacked<CData/*1:0*/, 1024> Vdut__ConstPool__TABLE_h10877b4f_0;
extern const VlUnpacked<CData/*2:0*/, 1024> Vdut__ConstPool__TABLE_h5872fa6d_0;
extern const VlUnpacked<CData/*3:0*/, 128> Vdut__ConstPool__TABLE_hf06b9b74_0;

VL_INLINE_OPT void Vdut___024root___sequent__TOP__3(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___sequent__TOP__3\n"); );
    // Init
    SData/*9:0*/ __Vtableidx1;
    CData/*6:0*/ __Vtableidx2;
    // Body
    vlSelf->top__DOT__BranchE = ((~ (IData)(vlSelf->rst)) 
                                 & ((~ (IData)(vlSelf->top__DOT__Flush)) 
                                    & (IData)(vlSelf->top__DOT__BranchD)));
    vlSelf->top__DOT__JumpE = ((~ (IData)(vlSelf->rst)) 
                               & ((~ (IData)(vlSelf->top__DOT__Flush)) 
                                  & (IData)(vlSelf->top__DOT__JumpD)));
    vlSelf->top__DOT__RegWriteW = ((~ (IData)(vlSelf->rst)) 
                                   & (IData)(vlSelf->top__DOT__RegWriteM));
    vlSelf->top__DOT__MemWriteM = ((~ (IData)(vlSelf->rst)) 
                                   & (IData)(vlSelf->top__DOT__MemWriteE));
    if (vlSelf->rst) {
        vlSelf->top__DOT__ALUControlE = 0U;
        vlSelf->top__DOT__PCe = 0U;
        vlSelf->top__DOT__ImmExtE = 0U;
        vlSelf->top__DOT__PCPlus4W = 0U;
        vlSelf->top__DOT__ALUResultW = 0U;
    } else {
        if (vlSelf->top__DOT__Flush) {
            vlSelf->top__DOT__ALUControlE = 0U;
            vlSelf->top__DOT__PCe = 0U;
            vlSelf->top__DOT__ImmExtE = 0U;
        } else {
            vlSelf->top__DOT__ALUControlE = vlSelf->top__DOT__ALUControlD;
            vlSelf->top__DOT__PCe = vlSelf->top__DOT__PCd;
            vlSelf->top__DOT__ImmExtE = vlSelf->top__DOT__ImmExtD;
        }
        vlSelf->top__DOT__PCPlus4W = vlSelf->top__DOT__PCPlus4M;
        vlSelf->top__DOT__ALUResultW = vlSelf->top__DOT__ALUResultM;
    }
    vlSelf->top__DOT__ResultW = ((0U == (IData)(vlSelf->top__DOT__ResultSrcW))
                                  ? vlSelf->top__DOT__ALUResultW
                                  : ((1U == (IData)(vlSelf->top__DOT__ResultSrcW))
                                      ? vlSelf->top__DOT__ReadDataW
                                      : ((2U == (IData)(vlSelf->top__DOT__ResultSrcW))
                                          ? vlSelf->top__DOT__PCPlus4W
                                          : 0U)));
    vlSelf->top__DOT__RegWriteM = ((~ (IData)(vlSelf->rst)) 
                                   & (IData)(vlSelf->top__DOT__RegWriteE));
    vlSelf->top__DOT__MemWriteE = ((~ (IData)(vlSelf->rst)) 
                                   & ((~ (IData)(vlSelf->top__DOT__Flush)) 
                                      & (IData)(vlSelf->top__DOT__MemWriteD)));
    if (vlSelf->rst) {
        vlSelf->top__DOT__ResultSrcM = 0U;
        vlSelf->top__DOT__RdW = 0U;
        vlSelf->top__DOT__sizeSrcM = 0U;
        vlSelf->top__DOT__WriteDataM = 0U;
        vlSelf->top__DOT__PCd = 0U;
        vlSelf->top__DOT__PCPlus4M = 0U;
        vlSelf->top__DOT__ALUResultM = 0U;
    } else {
        vlSelf->top__DOT__ResultSrcM = vlSelf->top__DOT__ResultSrcE;
        vlSelf->top__DOT__RdW = vlSelf->top__DOT__RdM;
        vlSelf->top__DOT__sizeSrcM = vlSelf->top__DOT__sizeSrcE;
        vlSelf->top__DOT__WriteDataM = vlSelf->top__DOT__rd2E;
        if (vlSelf->top__DOT__Flush) {
            vlSelf->top__DOT__PCd = 0U;
        } else if ((1U & (~ (IData)(vlSelf->top__DOT__stall)))) {
            vlSelf->top__DOT__PCd = vlSelf->top__DOT__pc;
        }
        vlSelf->top__DOT__PCPlus4M = vlSelf->top__DOT__PCPlus4E;
        vlSelf->top__DOT__ALUResultM = vlSelf->top__DOT__aluResult;
    }
    vlSelf->top__DOT__ReadData = ((4U & (IData)(vlSelf->top__DOT__sizeSrcM))
                                   ? ((2U & (IData)(vlSelf->top__DOT__sizeSrcM))
                                       ? 0U : ((1U 
                                                & (IData)(vlSelf->top__DOT__sizeSrcM))
                                                ? (
                                                   (vlSelf->top__DOT__DataMemory__DOT__memory
                                                    [
                                                    (0x1ffffU 
                                                     & ((IData)(1U) 
                                                        + vlSelf->top__DOT__ALUResultM))] 
                                                    << 8U) 
                                                   | vlSelf->top__DOT__DataMemory__DOT__memory
                                                   [
                                                   (0x1ffffU 
                                                    & vlSelf->top__DOT__ALUResultM)])
                                                : vlSelf->top__DOT__DataMemory__DOT__memory
                                               [(0x1ffffU 
                                                 & vlSelf->top__DOT__ALUResultM)]))
                                   : ((2U & (IData)(vlSelf->top__DOT__sizeSrcM))
                                       ? ((1U & (IData)(vlSelf->top__DOT__sizeSrcM))
                                           ? 0U : (
                                                   (vlSelf->top__DOT__DataMemory__DOT__memory
                                                    [
                                                    (0x1ffffU 
                                                     & ((IData)(3U) 
                                                        + vlSelf->top__DOT__ALUResultM))] 
                                                    << 0x18U) 
                                                   | ((vlSelf->top__DOT__DataMemory__DOT__memory
                                                       [
                                                       (0x1ffffU 
                                                        & ((IData)(2U) 
                                                           + vlSelf->top__DOT__ALUResultM))] 
                                                       << 0x10U) 
                                                      | ((vlSelf->top__DOT__DataMemory__DOT__memory
                                                          [
                                                          (0x1ffffU 
                                                           & ((IData)(1U) 
                                                              + vlSelf->top__DOT__ALUResultM))] 
                                                          << 8U) 
                                                         | vlSelf->top__DOT__DataMemory__DOT__memory
                                                         [
                                                         (0x1ffffU 
                                                          & vlSelf->top__DOT__ALUResultM)]))))
                                       : ((1U & (IData)(vlSelf->top__DOT__sizeSrcM))
                                           ? (((- (IData)(
                                                          (1U 
                                                           & (vlSelf->top__DOT__DataMemory__DOT__memory
                                                              [
                                                              (0x1ffffU 
                                                               & ((IData)(1U) 
                                                                  + vlSelf->top__DOT__ALUResultM))] 
                                                              >> 7U)))) 
                                               << 0x10U) 
                                              | ((vlSelf->top__DOT__DataMemory__DOT__memory
                                                  [
                                                  (0x1ffffU 
                                                   & ((IData)(1U) 
                                                      + vlSelf->top__DOT__ALUResultM))] 
                                                  << 8U) 
                                                 | vlSelf->top__DOT__DataMemory__DOT__memory
                                                 [(0x1ffffU 
                                                   & vlSelf->top__DOT__ALUResultM)]))
                                           : (((- (IData)(
                                                          (1U 
                                                           & (vlSelf->top__DOT__DataMemory__DOT__memory
                                                              [
                                                              (0x1ffffU 
                                                               & vlSelf->top__DOT__ALUResultM)] 
                                                              >> 7U)))) 
                                               << 8U) 
                                              | vlSelf->top__DOT__DataMemory__DOT__memory
                                              [(0x1ffffU 
                                                & vlSelf->top__DOT__ALUResultM)]))));
    vlSelf->top__DOT__RegWriteE = ((~ (IData)(vlSelf->rst)) 
                                   & ((~ (IData)(vlSelf->top__DOT__Flush)) 
                                      & (IData)(vlSelf->top__DOT__RegWriteD)));
    if (vlSelf->rst) {
        vlSelf->top__DOT__ResultSrcE = 0U;
        vlSelf->top__DOT__RdM = 0U;
    } else {
        vlSelf->top__DOT__ResultSrcE = ((IData)(vlSelf->top__DOT__Flush)
                                         ? 0U : (IData)(vlSelf->top__DOT__ResultSrcD));
        vlSelf->top__DOT__RdM = vlSelf->top__DOT__RdE;
    }
    vlSelf->top__DOT__ForwardAE = ((((IData)(vlSelf->top__DOT__RegWriteM) 
                                     & (0U != (IData)(vlSelf->top__DOT__RdM))) 
                                    & ((IData)(vlSelf->top__DOT__RdM) 
                                       == (IData)(vlSelf->top__DOT__Rs1E)))
                                    ? 2U : ((((IData)(vlSelf->top__DOT__RegWriteW) 
                                              & (0U 
                                                 != (IData)(vlSelf->top__DOT__RdW))) 
                                             & ((IData)(vlSelf->top__DOT__RdW) 
                                                == (IData)(vlSelf->top__DOT__Rs1E)))
                                             ? 1U : 0U));
    vlSelf->top__DOT__ForwardBE = ((((IData)(vlSelf->top__DOT__RegWriteM) 
                                     & (0U != (IData)(vlSelf->top__DOT__RdM))) 
                                    & ((IData)(vlSelf->top__DOT__RdM) 
                                       == (IData)(vlSelf->top__DOT__Rs2E)))
                                    ? 2U : ((((IData)(vlSelf->top__DOT__RegWriteW) 
                                              & (0U 
                                                 != (IData)(vlSelf->top__DOT__RdW))) 
                                             & ((IData)(vlSelf->top__DOT__RdW) 
                                                == (IData)(vlSelf->top__DOT__Rs2E)))
                                             ? 1U : 0U));
    vlSelf->top__DOT__SrcAE = ((0U == (IData)(vlSelf->top__DOT__ForwardAE))
                                ? vlSelf->top__DOT__rd1E
                                : ((1U == (IData)(vlSelf->top__DOT__ForwardAE))
                                    ? vlSelf->top__DOT__ResultW
                                    : ((2U == (IData)(vlSelf->top__DOT__ForwardAE))
                                        ? vlSelf->top__DOT__ALUResultM
                                        : vlSelf->top__DOT__rd1E)));
    if (vlSelf->rst) {
        vlSelf->top__DOT__sizeSrcE = 0U;
        vlSelf->top__DOT__rd2E = 0U;
        vlSelf->top__DOT__PCPlus4E = 0U;
        vlSelf->top__DOT__RdE = 0U;
    } else {
        if ((1U & (~ (IData)(vlSelf->top__DOT__Flush)))) {
            vlSelf->top__DOT__sizeSrcE = vlSelf->top__DOT__sizeSrcD;
        }
        if (vlSelf->top__DOT__Flush) {
            vlSelf->top__DOT__rd2E = 0U;
            vlSelf->top__DOT__PCPlus4E = 0U;
            vlSelf->top__DOT__RdE = 0U;
        } else {
            vlSelf->top__DOT__rd2E = vlSelf->top__DOT__regfile__DOT__rom_array
                [(0x1fU & (vlSelf->top__DOT__instrD 
                           >> 0x14U))];
            vlSelf->top__DOT__PCPlus4E = vlSelf->top__DOT__PCPlus4D;
            vlSelf->top__DOT__RdE = (0x1fU & (vlSelf->top__DOT__instrD 
                                              >> 7U));
        }
    }
    VL_WRITEF("HazardMux: Forward=%b, rdE=%x, ResultW=%x, ALUResultM=%x, Out=%x\n",
              2,vlSelf->top__DOT__ForwardAE,32,vlSelf->top__DOT__rd1E,
              32,vlSelf->top__DOT__ResultW,32,vlSelf->top__DOT__ALUResultM,
              32,vlSelf->top__DOT__SrcAE);
    vlSelf->top__DOT__WriteDataE = ((0U == (IData)(vlSelf->top__DOT__ForwardBE))
                                     ? vlSelf->top__DOT__rd2E
                                     : ((1U == (IData)(vlSelf->top__DOT__ForwardBE))
                                         ? vlSelf->top__DOT__ResultW
                                         : ((2U == (IData)(vlSelf->top__DOT__ForwardBE))
                                             ? vlSelf->top__DOT__ALUResultM
                                             : vlSelf->top__DOT__rd2E)));
    VL_WRITEF("HazardMux: Forward=%b, rdE=%x, ResultW=%x, ALUResultM=%x, Out=%x\n",
              2,vlSelf->top__DOT__ForwardBE,32,vlSelf->top__DOT__rd2E,
              32,vlSelf->top__DOT__ResultW,32,vlSelf->top__DOT__ALUResultM,
              32,vlSelf->top__DOT__WriteDataE);
    if (vlSelf->rst) {
        vlSelf->top__DOT__PCPlus4D = 0U;
        vlSelf->top__DOT__instrD = 0U;
        vlSelf->top__DOT__pc = 0xbfc00000U;
    } else {
        if (vlSelf->top__DOT__Flush) {
            vlSelf->top__DOT__PCPlus4D = 0U;
            vlSelf->top__DOT__instrD = 0U;
        } else if ((1U & (~ (IData)(vlSelf->top__DOT__stall)))) {
            vlSelf->top__DOT__PCPlus4D = ((IData)(4U) 
                                          + vlSelf->top__DOT__pc);
            vlSelf->top__DOT__instrD = ((vlSelf->top__DOT__instrMemory__DOT__rom
                                         [(0xfffU & 
                                           ((IData)(3U) 
                                            + vlSelf->top__DOT__pc))] 
                                         << 0x18U) 
                                        | ((vlSelf->top__DOT__instrMemory__DOT__rom
                                            [(0xfffU 
                                              & ((IData)(2U) 
                                                 + vlSelf->top__DOT__pc))] 
                                            << 0x10U) 
                                           | ((vlSelf->top__DOT__instrMemory__DOT__rom
                                               [(0xfffU 
                                                 & ((IData)(1U) 
                                                    + vlSelf->top__DOT__pc))] 
                                               << 8U) 
                                              | vlSelf->top__DOT__instrMemory__DOT__rom
                                              [(0xfffU 
                                                & vlSelf->top__DOT__pc)])));
        }
        if ((1U & (~ (IData)(vlSelf->top__DOT__stall)))) {
            vlSelf->top__DOT__pc = vlSelf->top__DOT__nextPC;
        }
    }
    vlSelf->top__DOT__srcB = ((IData)(vlSelf->top__DOT__ALUSrcE)
                               ? vlSelf->top__DOT__ImmExtE
                               : vlSelf->top__DOT__WriteDataE);
    if (((((((((0U == (IData)(vlSelf->top__DOT__ALUControlE)) 
               | (1U == (IData)(vlSelf->top__DOT__ALUControlE))) 
              | (2U == (IData)(vlSelf->top__DOT__ALUControlE))) 
             | (3U == (IData)(vlSelf->top__DOT__ALUControlE))) 
            | (4U == (IData)(vlSelf->top__DOT__ALUControlE))) 
           | (5U == (IData)(vlSelf->top__DOT__ALUControlE))) 
          | (6U == (IData)(vlSelf->top__DOT__ALUControlE))) 
         | (7U == (IData)(vlSelf->top__DOT__ALUControlE)))) {
        vlSelf->top__DOT__aluResult = ((0U == (IData)(vlSelf->top__DOT__ALUControlE))
                                        ? (vlSelf->top__DOT__SrcAE 
                                           + vlSelf->top__DOT__srcB)
                                        : ((1U == (IData)(vlSelf->top__DOT__ALUControlE))
                                            ? (vlSelf->top__DOT__SrcAE 
                                               - vlSelf->top__DOT__srcB)
                                            : ((2U 
                                                == (IData)(vlSelf->top__DOT__ALUControlE))
                                                ? (vlSelf->top__DOT__SrcAE 
                                                   & vlSelf->top__DOT__srcB)
                                                : (
                                                   (3U 
                                                    == (IData)(vlSelf->top__DOT__ALUControlE))
                                                    ? 
                                                   (vlSelf->top__DOT__SrcAE 
                                                    | vlSelf->top__DOT__srcB)
                                                    : 
                                                   ((4U 
                                                     == (IData)(vlSelf->top__DOT__ALUControlE))
                                                     ? vlSelf->top__DOT__srcB
                                                     : 
                                                    ((5U 
                                                      == (IData)(vlSelf->top__DOT__ALUControlE))
                                                      ? 
                                                     (VL_LTS_III(32, vlSelf->top__DOT__SrcAE, vlSelf->top__DOT__srcB)
                                                       ? 1U
                                                       : 0U)
                                                      : 
                                                     ((6U 
                                                       == (IData)(vlSelf->top__DOT__ALUControlE))
                                                       ? 
                                                      (vlSelf->top__DOT__SrcAE 
                                                       << 
                                                       (0x1fU 
                                                        & vlSelf->top__DOT__srcB))
                                                       : 
                                                      (vlSelf->top__DOT__SrcAE 
                                                       >> 
                                                       (0x1fU 
                                                        & vlSelf->top__DOT__srcB)))))))));
    }
    vlSelf->top__DOT__zero = (((IData)(vlSelf->top__DOT__ALUControlE) 
                               >> 3U) & ((4U & (IData)(vlSelf->top__DOT__ALUControlE))
                                          ? ((2U & (IData)(vlSelf->top__DOT__ALUControlE))
                                              ? ((1U 
                                                  & (IData)(vlSelf->top__DOT__ALUControlE))
                                                  ? 
                                                 (vlSelf->top__DOT__SrcAE 
                                                  >= vlSelf->top__DOT__srcB)
                                                  : 
                                                 (vlSelf->top__DOT__SrcAE 
                                                  < vlSelf->top__DOT__srcB))
                                              : ((1U 
                                                  & (IData)(vlSelf->top__DOT__ALUControlE))
                                                  ? 
                                                 VL_GTES_III(32, vlSelf->top__DOT__SrcAE, vlSelf->top__DOT__srcB)
                                                  : 
                                                 VL_LTS_III(32, vlSelf->top__DOT__SrcAE, vlSelf->top__DOT__srcB)))
                                          : ((~ ((IData)(vlSelf->top__DOT__ALUControlE) 
                                                 >> 1U)) 
                                             & ((1U 
                                                 & (IData)(vlSelf->top__DOT__ALUControlE))
                                                 ? 
                                                (0U 
                                                 != 
                                                 (vlSelf->top__DOT__SrcAE 
                                                  - vlSelf->top__DOT__srcB))
                                                 : 
                                                (0U 
                                                 == 
                                                 (vlSelf->top__DOT__SrcAE 
                                                  - vlSelf->top__DOT__srcB))))));
    vlSelf->top__DOT__Flush = ((IData)(vlSelf->top__DOT__zero) 
                               | (IData)(vlSelf->top__DOT__JumpE));
    __Vtableidx1 = ((0x380U & (vlSelf->top__DOT__instrD 
                               >> 5U)) | (0x7fU & vlSelf->top__DOT__instrD));
    vlSelf->top__DOT__RegWriteD = Vdut__ConstPool__TABLE_h22d5d5a1_0
        [__Vtableidx1];
    vlSelf->top__DOT__MemWriteD = Vdut__ConstPool__TABLE_h45afa79b_0
        [__Vtableidx1];
    vlSelf->top__DOT__ALUSrcD = Vdut__ConstPool__TABLE_hab2b96bc_0
        [__Vtableidx1];
    vlSelf->top__DOT__immSrcD = Vdut__ConstPool__TABLE_h65b6ba1e_0
        [__Vtableidx1];
    vlSelf->top__DOT__ResultSrcD = Vdut__ConstPool__TABLE_hf6daef67_0
        [__Vtableidx1];
    vlSelf->top__DOT__BranchD = Vdut__ConstPool__TABLE_hff092405_0
        [__Vtableidx1];
    vlSelf->top__DOT__JumpD = Vdut__ConstPool__TABLE_hacf877fb_0
        [__Vtableidx1];
    vlSelf->top__DOT__jalrSrc = Vdut__ConstPool__TABLE_h087dd5e0_0
        [__Vtableidx1];
    vlSelf->top__DOT__controlUnit__DOT__aluOp = Vdut__ConstPool__TABLE_h10877b4f_0
        [__Vtableidx1];
    vlSelf->top__DOT__sizeSrcD = Vdut__ConstPool__TABLE_h5872fa6d_0
        [__Vtableidx1];
    vlSelf->top__DOT__stall = ((1U == (IData)(vlSelf->top__DOT__ResultSrcE)) 
                               & (((IData)(vlSelf->top__DOT__RdE) 
                                   == (0x1fU & (vlSelf->top__DOT__instrD 
                                                >> 0xfU))) 
                                  | ((IData)(vlSelf->top__DOT__RdE) 
                                     == (0x1fU & (vlSelf->top__DOT__instrD 
                                                  >> 0x14U)))));
    vlSelf->top__DOT__ImmExtD = ((2U & (IData)(vlSelf->top__DOT__immSrcD))
                                  ? ((1U & (IData)(vlSelf->top__DOT__immSrcD))
                                      ? ((IData)(vlSelf->top__DOT__JumpD)
                                          ? (((- (IData)(
                                                         (vlSelf->top__DOT__instrD 
                                                          >> 0x1fU))) 
                                              << 0x15U) 
                                             | ((0x100000U 
                                                 & (vlSelf->top__DOT__instrD 
                                                    >> 0xbU)) 
                                                | ((0xff000U 
                                                    & vlSelf->top__DOT__instrD) 
                                                   | ((0x800U 
                                                       & (vlSelf->top__DOT__instrD 
                                                          >> 9U)) 
                                                      | (0x7feU 
                                                         & (vlSelf->top__DOT__instrD 
                                                            >> 0x14U))))))
                                          : (0xfffff000U 
                                             & vlSelf->top__DOT__instrD))
                                      : (((- (IData)(
                                                     (vlSelf->top__DOT__instrD 
                                                      >> 0x1fU))) 
                                          << 0xcU) 
                                         | ((0x800U 
                                             & (vlSelf->top__DOT__instrD 
                                                << 4U)) 
                                            | ((0x7e0U 
                                                & (vlSelf->top__DOT__instrD 
                                                   >> 0x14U)) 
                                               | (0x1eU 
                                                  & (vlSelf->top__DOT__instrD 
                                                     >> 7U))))))
                                  : ((1U & (IData)(vlSelf->top__DOT__immSrcD))
                                      ? (((- (IData)(
                                                     (vlSelf->top__DOT__instrD 
                                                      >> 0x1fU))) 
                                          << 0xcU) 
                                         | ((0xfe0U 
                                             & (vlSelf->top__DOT__instrD 
                                                >> 0x14U)) 
                                            | (0x1fU 
                                               & (vlSelf->top__DOT__instrD 
                                                  >> 7U))))
                                      : (((- (IData)(
                                                     (vlSelf->top__DOT__instrD 
                                                      >> 0x1fU))) 
                                          << 0xcU) 
                                         | (vlSelf->top__DOT__instrD 
                                            >> 0x14U))));
    __Vtableidx2 = (((0x40U & (vlSelf->top__DOT__instrD 
                               << 1U)) | (0x20U & (vlSelf->top__DOT__instrD 
                                                   >> 0x19U))) 
                    | ((0x1cU & (vlSelf->top__DOT__instrD 
                                 >> 0xaU)) | (IData)(vlSelf->top__DOT__controlUnit__DOT__aluOp)));
    vlSelf->top__DOT__ALUControlD = Vdut__ConstPool__TABLE_hf06b9b74_0
        [__Vtableidx2];
    vlSelf->top__DOT__nextPC = (((IData)(vlSelf->top__DOT__JumpE) 
                                 | ((IData)(vlSelf->top__DOT__BranchE) 
                                    & (IData)(vlSelf->top__DOT__zero)))
                                 ? ((IData)(vlSelf->top__DOT__jalrSrc)
                                     ? vlSelf->top__DOT__ResultW
                                     : (vlSelf->top__DOT__PCe 
                                        + vlSelf->top__DOT__ImmExtE))
                                 : ((IData)(4U) + vlSelf->top__DOT__pc));
}

VL_INLINE_OPT void Vdut___024root___sequent__TOP__4(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___sequent__TOP__4\n"); );
    // Body
    if (vlSelf->__Vdlyvset__top__DOT__regfile__DOT__rom_array__v0) {
        vlSelf->top__DOT__regfile__DOT__rom_array[vlSelf->__Vdlyvdim0__top__DOT__regfile__DOT__rom_array__v0] 
            = vlSelf->__Vdlyvval__top__DOT__regfile__DOT__rom_array__v0;
    }
    vlSelf->a0 = vlSelf->top__DOT__regfile__DOT__rom_array
        [0xaU];
}

void Vdut___024root___eval(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval\n"); );
    // Body
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((IData)(vlSelf->rst) & (~ (IData)(vlSelf->__Vclklast__TOP__rst))))) {
        Vdut___024root___sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    if (((~ (IData)(vlSelf->clk)) & (IData)(vlSelf->__Vclklast__TOP__clk))) {
        Vdut___024root___sequent__TOP__1(vlSelf);
    }
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vdut___024root___sequent__TOP__2(vlSelf);
    }
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((IData)(vlSelf->rst) & (~ (IData)(vlSelf->__Vclklast__TOP__rst))))) {
        Vdut___024root___sequent__TOP__3(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    if (((~ (IData)(vlSelf->clk)) & (IData)(vlSelf->__Vclklast__TOP__clk))) {
        Vdut___024root___sequent__TOP__4(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
}

#ifdef VL_DEBUG
void Vdut___024root___eval_debug_assertions(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
