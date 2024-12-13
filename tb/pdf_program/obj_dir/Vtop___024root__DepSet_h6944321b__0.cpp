// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

void Vtop___024root___act_sequent__TOP__0(Vtop___024root* vlSelf);

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vtop___024root___act_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

extern const VlUnpacked<CData/*2:0*/, 256> Vtop__ConstPool__TABLE_h542a1d33_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtop__ConstPool__TABLE_h9bc97e4f_0;
extern const VlUnpacked<CData/*1:0*/, 256> Vtop__ConstPool__TABLE_h56d757c6_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtop__ConstPool__TABLE_hc9ad782a_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtop__ConstPool__TABLE_hbbfdeb8a_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtop__ConstPool__TABLE_had775587_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtop__ConstPool__TABLE_hef04e450_0;
extern const VlUnpacked<CData/*1:0*/, 256> Vtop__ConstPool__TABLE_h645962c8_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtop__ConstPool__TABLE_h2ceb209c_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtop__ConstPool__TABLE_h3cc597fe_0;

VL_INLINE_OPT void Vtop___024root___act_sequent__TOP__0(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___act_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*7:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    // Body
    __Vtableidx2 = ((((3U == ((2U & (vlSelfRef.top__DOT__instrMemory__DOT__rom
                                     [(0xfffU & vlSelfRef.top__DOT__pc)] 
                                     >> 4U)) | (1U 
                                                & (vlSelfRef.top__DOT__instrMemory__DOT__rom
                                                   [
                                                   (0xfffU 
                                                    & ((IData)(3U) 
                                                       + vlSelfRef.top__DOT__pc))] 
                                                   >> 6U))))
                       ? 1U : 0U) << 5U) | (((IData)(vlSelfRef.top__DOT____Vcellinp__dataMemory__SizeCtr) 
                                             << 2U) 
                                            | (IData)(vlSelfRef.top__DOT__controlUnit__DOT__aluOp)));
    vlSelfRef.top__DOT__aluControl = Vtop__ConstPool__TABLE_h542a1d33_0
        [__Vtableidx2];
    __Vtableidx1 = ((((4U & (IData)(vlSelfRef.top__DOT__aluControl))
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
                                    >> 1U))) && ((1U 
                                                  & (IData)(vlSelfRef.top__DOT__aluControl))
                                                  ? 
                                                 (0U 
                                                  != 
                                                  (vlSelfRef.top__DOT__srcA 
                                                   - vlSelfRef.top__DOT__regOp2))
                                                  : 
                                                 (0U 
                                                  == 
                                                  (vlSelfRef.top__DOT__srcA 
                                                   - vlSelfRef.top__DOT__regOp2))))) 
                     << 7U) | (0x7fU & vlSelfRef.top__DOT__instrMemory__DOT__rom
                               [(0xfffU & vlSelfRef.top__DOT__pc)]));
    vlSelfRef.top__DOT__regWrite = Vtop__ConstPool__TABLE_h9bc97e4f_0
        [__Vtableidx1];
    vlSelfRef.top__DOT__immSrc = Vtop__ConstPool__TABLE_h56d757c6_0
        [__Vtableidx1];
    vlSelfRef.top__DOT__aluSrc = Vtop__ConstPool__TABLE_hc9ad782a_0
        [__Vtableidx1];
    vlSelfRef.top__DOT__memWrite = Vtop__ConstPool__TABLE_hbbfdeb8a_0
        [__Vtableidx1];
    vlSelfRef.top__DOT__resultSrc = Vtop__ConstPool__TABLE_had775587_0
        [__Vtableidx1];
    vlSelfRef.top__DOT__pcSrc = Vtop__ConstPool__TABLE_hef04e450_0
        [__Vtableidx1];
    vlSelfRef.top__DOT__controlUnit__DOT__aluOp = Vtop__ConstPool__TABLE_h645962c8_0
        [__Vtableidx1];
    vlSelfRef.top__DOT__jalrSrc = Vtop__ConstPool__TABLE_h2ceb209c_0
        [__Vtableidx1];
    vlSelfRef.top__DOT__jumpSrc = Vtop__ConstPool__TABLE_h3cc597fe_0
        [__Vtableidx1];
    vlSelfRef.top__DOT__immOp = ((2U & (IData)(vlSelfRef.top__DOT__immSrc))
                                  ? ((1U & (IData)(vlSelfRef.top__DOT__immSrc))
                                      ? ((IData)(vlSelfRef.top__DOT__jumpSrc)
                                          ? (((- (IData)(
                                                         (vlSelfRef.top__DOT__instr 
                                                          >> 0x1fU))) 
                                              << 0x15U) 
                                             | ((0x100000U 
                                                 & (vlSelfRef.top__DOT__instr 
                                                    >> 0xbU)) 
                                                | ((0xff000U 
                                                    & vlSelfRef.top__DOT__instr) 
                                                   | ((0x800U 
                                                       & (vlSelfRef.top__DOT__instr 
                                                          >> 9U)) 
                                                      | (0x7feU 
                                                         & (vlSelfRef.top__DOT__instr 
                                                            >> 0x14U))))))
                                          : (0xfffff000U 
                                             & vlSelfRef.top__DOT__instr))
                                      : (((- (IData)(
                                                     (vlSelfRef.top__DOT__instr 
                                                      >> 0x1fU))) 
                                          << 0xcU) 
                                         | ((0x800U 
                                             & (vlSelfRef.top__DOT__instr 
                                                << 4U)) 
                                            | ((0x7e0U 
                                                & (vlSelfRef.top__DOT__instr 
                                                   >> 0x14U)) 
                                               | (0x1eU 
                                                  & (vlSelfRef.top__DOT__instr 
                                                     >> 7U))))))
                                  : ((1U & (IData)(vlSelfRef.top__DOT__immSrc))
                                      ? (((- (IData)(
                                                     (vlSelfRef.top__DOT__instr 
                                                      >> 0x1fU))) 
                                          << 0xcU) 
                                         | ((0xfe0U 
                                             & (vlSelfRef.top__DOT__instr 
                                                >> 0x14U)) 
                                            | (0x1fU 
                                               & (vlSelfRef.top__DOT__instr 
                                                  >> 7U))))
                                      : (((- (IData)(
                                                     (vlSelfRef.top__DOT__instr 
                                                      >> 0x1fU))) 
                                          << 0xcU) 
                                         | (vlSelfRef.top__DOT__instr 
                                            >> 0x14U))));
    vlSelfRef.top__DOT__srcB = ((IData)(vlSelfRef.top__DOT__aluSrc)
                                 ? vlSelfRef.top__DOT__immOp
                                 : vlSelfRef.top__DOT__regOp2);
    vlSelfRef.top__DOT__aluResult = ((4U & (IData)(vlSelfRef.top__DOT__aluControl))
                                      ? ((2U & (IData)(vlSelfRef.top__DOT__aluControl))
                                          ? ((1U & (IData)(vlSelfRef.top__DOT__aluControl))
                                              ? (vlSelfRef.top__DOT__srcA 
                                                 >> 
                                                 (0x1fU 
                                                  & vlSelfRef.top__DOT__srcB))
                                              : (vlSelfRef.top__DOT__srcA 
                                                 << 
                                                 (0x1fU 
                                                  & vlSelfRef.top__DOT__srcB)))
                                          : ((1U & (IData)(vlSelfRef.top__DOT__aluControl))
                                              ? (VL_LTS_III(32, vlSelfRef.top__DOT__srcA, vlSelfRef.top__DOT__srcB)
                                                  ? 1U
                                                  : 0U)
                                              : vlSelfRef.top__DOT__srcB))
                                      : ((2U & (IData)(vlSelfRef.top__DOT__aluControl))
                                          ? ((1U & (IData)(vlSelfRef.top__DOT__aluControl))
                                              ? (vlSelfRef.top__DOT__srcA 
                                                 | vlSelfRef.top__DOT__srcB)
                                              : (vlSelfRef.top__DOT__srcA 
                                                 & vlSelfRef.top__DOT__srcB))
                                          : ((1U & (IData)(vlSelfRef.top__DOT__aluControl))
                                              ? (vlSelfRef.top__DOT__srcA 
                                                 - vlSelfRef.top__DOT__srcB)
                                              : (vlSelfRef.top__DOT__srcA 
                                                 + vlSelfRef.top__DOT__srcB))));
    vlSelfRef.top__DOT__readData = ((4U & (IData)(vlSelfRef.top__DOT____Vcellinp__dataMemory__SizeCtr))
                                     ? ((2U & (IData)(vlSelfRef.top__DOT____Vcellinp__dataMemory__SizeCtr))
                                         ? 0U : ((1U 
                                                  & (IData)(vlSelfRef.top__DOT____Vcellinp__dataMemory__SizeCtr))
                                                  ? 
                                                 ((vlSelfRef.top__DOT__dataMemory__DOT__memory
                                                   [
                                                   (0x1ffffU 
                                                    & ((IData)(1U) 
                                                       + vlSelfRef.top__DOT__aluResult))] 
                                                   << 8U) 
                                                  | vlSelfRef.top__DOT__dataMemory__DOT__memory
                                                  [
                                                  (0x1ffffU 
                                                   & vlSelfRef.top__DOT__aluResult)])
                                                  : 
                                                 vlSelfRef.top__DOT__dataMemory__DOT__memory
                                                 [(0x1ffffU 
                                                   & vlSelfRef.top__DOT__aluResult)]))
                                     : ((2U & (IData)(vlSelfRef.top__DOT____Vcellinp__dataMemory__SizeCtr))
                                         ? ((1U & (IData)(vlSelfRef.top__DOT____Vcellinp__dataMemory__SizeCtr))
                                             ? 0U : 
                                            ((vlSelfRef.top__DOT__dataMemory__DOT__memory
                                              [(0x1ffffU 
                                                & ((IData)(3U) 
                                                   + vlSelfRef.top__DOT__aluResult))] 
                                              << 0x18U) 
                                             | ((vlSelfRef.top__DOT__dataMemory__DOT__memory
                                                 [(0x1ffffU 
                                                   & ((IData)(2U) 
                                                      + vlSelfRef.top__DOT__aluResult))] 
                                                 << 0x10U) 
                                                | ((vlSelfRef.top__DOT__dataMemory__DOT__memory
                                                    [
                                                    (0x1ffffU 
                                                     & ((IData)(1U) 
                                                        + vlSelfRef.top__DOT__aluResult))] 
                                                    << 8U) 
                                                   | vlSelfRef.top__DOT__dataMemory__DOT__memory
                                                   [
                                                   (0x1ffffU 
                                                    & vlSelfRef.top__DOT__aluResult)]))))
                                         : ((1U & (IData)(vlSelfRef.top__DOT____Vcellinp__dataMemory__SizeCtr))
                                             ? (((- (IData)(
                                                            (1U 
                                                             & (vlSelfRef.top__DOT__dataMemory__DOT__memory
                                                                [
                                                                (0x1ffffU 
                                                                 & ((IData)(1U) 
                                                                    + vlSelfRef.top__DOT__aluResult))] 
                                                                >> 7U)))) 
                                                 << 0x10U) 
                                                | ((vlSelfRef.top__DOT__dataMemory__DOT__memory
                                                    [
                                                    (0x1ffffU 
                                                     & ((IData)(1U) 
                                                        + vlSelfRef.top__DOT__aluResult))] 
                                                    << 8U) 
                                                   | vlSelfRef.top__DOT__dataMemory__DOT__memory
                                                   [
                                                   (0x1ffffU 
                                                    & vlSelfRef.top__DOT__aluResult)]))
                                             : (((- (IData)(
                                                            (1U 
                                                             & (vlSelfRef.top__DOT__dataMemory__DOT__memory
                                                                [
                                                                (0x1ffffU 
                                                                 & vlSelfRef.top__DOT__aluResult)] 
                                                                >> 7U)))) 
                                                 << 8U) 
                                                | vlSelfRef.top__DOT__dataMemory__DOT__memory
                                                [(0x1ffffU 
                                                  & vlSelfRef.top__DOT__aluResult)]))));
    vlSelfRef.top__DOT__result = ((IData)(vlSelfRef.top__DOT__resultSrc)
                                   ? vlSelfRef.top__DOT__readData
                                   : vlSelfRef.top__DOT__aluResult);
    vlSelfRef.top__DOT__nextPC = ((IData)(vlSelfRef.top__DOT__pcSrc)
                                   ? ((IData)(vlSelfRef.top__DOT__jalrSrc)
                                       ? vlSelfRef.top__DOT__result
                                       : (vlSelfRef.top__DOT__immOp 
                                          + vlSelfRef.top__DOT__pc))
                                   : ((IData)(4U) + vlSelfRef.top__DOT__pc));
}

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf);

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___act_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __VdlyVal__top__DOT__dataMemory__DOT__memory__v0;
    __VdlyVal__top__DOT__dataMemory__DOT__memory__v0 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__dataMemory__DOT__memory__v0;
    __VdlyDim0__top__DOT__dataMemory__DOT__memory__v0 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__dataMemory__DOT__memory__v1;
    __VdlyVal__top__DOT__dataMemory__DOT__memory__v1 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__dataMemory__DOT__memory__v1;
    __VdlyDim0__top__DOT__dataMemory__DOT__memory__v1 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__dataMemory__DOT__memory__v2;
    __VdlyVal__top__DOT__dataMemory__DOT__memory__v2 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__dataMemory__DOT__memory__v2;
    __VdlyDim0__top__DOT__dataMemory__DOT__memory__v2 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__dataMemory__DOT__memory__v3;
    __VdlyVal__top__DOT__dataMemory__DOT__memory__v3 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__dataMemory__DOT__memory__v3;
    __VdlyDim0__top__DOT__dataMemory__DOT__memory__v3 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__dataMemory__DOT__memory__v4;
    __VdlyVal__top__DOT__dataMemory__DOT__memory__v4 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__dataMemory__DOT__memory__v4;
    __VdlyDim0__top__DOT__dataMemory__DOT__memory__v4 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__dataMemory__DOT__memory__v5;
    __VdlyVal__top__DOT__dataMemory__DOT__memory__v5 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__dataMemory__DOT__memory__v5;
    __VdlyDim0__top__DOT__dataMemory__DOT__memory__v5 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__dataMemory__DOT__memory__v6;
    __VdlyVal__top__DOT__dataMemory__DOT__memory__v6 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__dataMemory__DOT__memory__v6;
    __VdlyDim0__top__DOT__dataMemory__DOT__memory__v6 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__regFile__DOT__rom_array__v0;
    __VdlyVal__top__DOT__regFile__DOT__rom_array__v0 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__regFile__DOT__rom_array__v0;
    __VdlyDim0__top__DOT__regFile__DOT__rom_array__v0 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__dataMemory__DOT__memory__v0;
    __VdlySet__top__DOT__dataMemory__DOT__memory__v0 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__dataMemory__DOT__memory__v4;
    __VdlySet__top__DOT__dataMemory__DOT__memory__v4 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__dataMemory__DOT__memory__v6;
    __VdlySet__top__DOT__dataMemory__DOT__memory__v6 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regFile__DOT__rom_array__v0;
    __VdlySet__top__DOT__regFile__DOT__rom_array__v0 = 0;
    // Body
    __VdlySet__top__DOT__dataMemory__DOT__memory__v0 = 0U;
    __VdlySet__top__DOT__dataMemory__DOT__memory__v4 = 0U;
    __VdlySet__top__DOT__dataMemory__DOT__memory__v6 = 0U;
    __VdlySet__top__DOT__regFile__DOT__rom_array__v0 = 0U;
    if (vlSelfRef.top__DOT__memWrite) {
        if ((2U == (IData)(vlSelfRef.top__DOT____Vcellinp__dataMemory__SizeCtr))) {
            __VdlyVal__top__DOT__dataMemory__DOT__memory__v0 
                = (0xffU & vlSelfRef.top__DOT__regOp2);
            __VdlyDim0__top__DOT__dataMemory__DOT__memory__v0 
                = (0x1ffffU & vlSelfRef.top__DOT__aluResult);
            __VdlySet__top__DOT__dataMemory__DOT__memory__v0 = 1U;
            __VdlyVal__top__DOT__dataMemory__DOT__memory__v1 
                = (0xffU & (vlSelfRef.top__DOT__regOp2 
                            >> 8U));
            __VdlyDim0__top__DOT__dataMemory__DOT__memory__v1 
                = (0x1ffffU & ((IData)(1U) + vlSelfRef.top__DOT__aluResult));
            __VdlyVal__top__DOT__dataMemory__DOT__memory__v2 
                = (0xffU & (vlSelfRef.top__DOT__regOp2 
                            >> 0x10U));
            __VdlyDim0__top__DOT__dataMemory__DOT__memory__v2 
                = (0x1ffffU & ((IData)(2U) + vlSelfRef.top__DOT__aluResult));
            __VdlyVal__top__DOT__dataMemory__DOT__memory__v3 
                = (vlSelfRef.top__DOT__regOp2 >> 0x18U);
            __VdlyDim0__top__DOT__dataMemory__DOT__memory__v3 
                = (0x1ffffU & ((IData)(3U) + vlSelfRef.top__DOT__aluResult));
        } else if ((1U == (IData)(vlSelfRef.top__DOT____Vcellinp__dataMemory__SizeCtr))) {
            __VdlyVal__top__DOT__dataMemory__DOT__memory__v4 
                = (0xffU & vlSelfRef.top__DOT__regOp2);
            __VdlyDim0__top__DOT__dataMemory__DOT__memory__v4 
                = (0x1ffffU & vlSelfRef.top__DOT__aluResult);
            __VdlySet__top__DOT__dataMemory__DOT__memory__v4 = 1U;
            __VdlyVal__top__DOT__dataMemory__DOT__memory__v5 
                = (0xffU & (vlSelfRef.top__DOT__regOp2 
                            >> 8U));
            __VdlyDim0__top__DOT__dataMemory__DOT__memory__v5 
                = (0x1ffffU & ((IData)(1U) + vlSelfRef.top__DOT__aluResult));
        } else if ((0U == (IData)(vlSelfRef.top__DOT____Vcellinp__dataMemory__SizeCtr))) {
            __VdlyVal__top__DOT__dataMemory__DOT__memory__v6 
                = (0xffU & vlSelfRef.top__DOT__regOp2);
            __VdlyDim0__top__DOT__dataMemory__DOT__memory__v6 
                = (0x1ffffU & vlSelfRef.top__DOT__aluResult);
            __VdlySet__top__DOT__dataMemory__DOT__memory__v6 = 1U;
        }
    }
    if (((IData)(vlSelfRef.top__DOT__regWrite) & (0U 
                                                  != 
                                                  (0x1fU 
                                                   & ((IData)(vlSelfRef.__VdfgRegularize_h6171c202_0_0) 
                                                      >> 7U))))) {
        __VdlyVal__top__DOT__regFile__DOT__rom_array__v0 
            = ((IData)(vlSelfRef.top__DOT__jumpSrc)
                ? ((IData)(4U) + vlSelfRef.top__DOT__pc)
                : vlSelfRef.top__DOT__result);
        __VdlyDim0__top__DOT__regFile__DOT__rom_array__v0 
            = (0x1fU & ((IData)(vlSelfRef.__VdfgRegularize_h6171c202_0_0) 
                        >> 7U));
        __VdlySet__top__DOT__regFile__DOT__rom_array__v0 = 1U;
    }
    vlSelfRef.a0 = vlSelfRef.top__DOT__regFile__DOT__rom_array
        [0xaU];
    if (__VdlySet__top__DOT__dataMemory__DOT__memory__v0) {
        vlSelfRef.top__DOT__dataMemory__DOT__memory[__VdlyDim0__top__DOT__dataMemory__DOT__memory__v0] 
            = __VdlyVal__top__DOT__dataMemory__DOT__memory__v0;
        vlSelfRef.top__DOT__dataMemory__DOT__memory[__VdlyDim0__top__DOT__dataMemory__DOT__memory__v1] 
            = __VdlyVal__top__DOT__dataMemory__DOT__memory__v1;
        vlSelfRef.top__DOT__dataMemory__DOT__memory[__VdlyDim0__top__DOT__dataMemory__DOT__memory__v2] 
            = __VdlyVal__top__DOT__dataMemory__DOT__memory__v2;
        vlSelfRef.top__DOT__dataMemory__DOT__memory[__VdlyDim0__top__DOT__dataMemory__DOT__memory__v3] 
            = __VdlyVal__top__DOT__dataMemory__DOT__memory__v3;
    }
    if (__VdlySet__top__DOT__dataMemory__DOT__memory__v4) {
        vlSelfRef.top__DOT__dataMemory__DOT__memory[__VdlyDim0__top__DOT__dataMemory__DOT__memory__v4] 
            = __VdlyVal__top__DOT__dataMemory__DOT__memory__v4;
        vlSelfRef.top__DOT__dataMemory__DOT__memory[__VdlyDim0__top__DOT__dataMemory__DOT__memory__v5] 
            = __VdlyVal__top__DOT__dataMemory__DOT__memory__v5;
    }
    if (__VdlySet__top__DOT__dataMemory__DOT__memory__v6) {
        vlSelfRef.top__DOT__dataMemory__DOT__memory[__VdlyDim0__top__DOT__dataMemory__DOT__memory__v6] 
            = __VdlyVal__top__DOT__dataMemory__DOT__memory__v6;
    }
    if (__VdlySet__top__DOT__regFile__DOT__rom_array__v0) {
        vlSelfRef.top__DOT__regFile__DOT__rom_array[__VdlyDim0__top__DOT__regFile__DOT__rom_array__v0] 
            = __VdlyVal__top__DOT__regFile__DOT__rom_array__v0;
    }
    vlSelfRef.top__DOT__pc = ((IData)(vlSelfRef.rst)
                               ? 0xbfc00000U : vlSelfRef.top__DOT__nextPC);
    vlSelfRef.top__DOT____Vcellinp__dataMemory__SizeCtr 
        = (7U & (vlSelfRef.top__DOT__instrMemory__DOT__rom
                 [(0xfffU & ((IData)(1U) + vlSelfRef.top__DOT__pc))] 
                 >> 4U));
    vlSelfRef.__VdfgRegularize_h6171c202_0_0 = ((vlSelfRef.top__DOT__instrMemory__DOT__rom
                                                 [(0xfffU 
                                                   & ((IData)(1U) 
                                                      + vlSelfRef.top__DOT__pc))] 
                                                 << 8U) 
                                                | vlSelfRef.top__DOT__instrMemory__DOT__rom
                                                [(0xfffU 
                                                  & vlSelfRef.top__DOT__pc)]);
    vlSelfRef.__VdfgRegularize_h6171c202_0_1 = ((vlSelfRef.top__DOT__instrMemory__DOT__rom
                                                 [(0xfffU 
                                                   & ((IData)(2U) 
                                                      + vlSelfRef.top__DOT__pc))] 
                                                 << 0x10U) 
                                                | (IData)(vlSelfRef.__VdfgRegularize_h6171c202_0_0));
    vlSelfRef.top__DOT__srcA = vlSelfRef.top__DOT__regFile__DOT__rom_array
        [(0x1fU & (vlSelfRef.__VdfgRegularize_h6171c202_0_1 
                   >> 0xfU))];
    vlSelfRef.top__DOT__instr = ((vlSelfRef.top__DOT__instrMemory__DOT__rom
                                  [(0xfffU & ((IData)(3U) 
                                              + vlSelfRef.top__DOT__pc))] 
                                  << 0x18U) | vlSelfRef.__VdfgRegularize_h6171c202_0_1);
    vlSelfRef.top__DOT__regOp2 = vlSelfRef.top__DOT__regFile__DOT__rom_array
        [(0x1fU & (vlSelfRef.top__DOT__instr >> 0x14U))];
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtop___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("top.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("top.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtop___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtop___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelfRef.rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelfRef.trigger & 0xfeU))) {
        Verilated::overWidthError("trigger");}
}
#endif  // VL_DEBUG
