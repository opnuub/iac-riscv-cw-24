// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdut.h for the primary calling header

#include "verilated.h"

#include "Vdut___024root.h"

VL_ATTR_COLD void Vdut___024root___initial__TOP__0(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___initial__TOP__0\n"); );
    // Init
    VlWide<4>/*127:0*/ __Vtemp_h0235989b__0;
    VlWide<5>/*159:0*/ __Vtemp_hbdd2015e__0;
    // Body
    __Vtemp_h0235989b__0[0U] = 0x2e686578U;
    __Vtemp_h0235989b__0[1U] = 0x64617461U;
    __Vtemp_h0235989b__0[2U] = 0x2f74622fU;
    __Vtemp_h0235989b__0[3U] = 0x2e2eU;
    VL_READMEM_N(true, 8, 131072, 0, VL_CVT_PACK_STR_NW(4, __Vtemp_h0235989b__0)
                 ,  &(vlSelf->top__DOT__DataMemory__DOT__memory)
                 , 0x10000U, ~0ULL);
    __Vtemp_hbdd2015e__0[0U] = 0x2e686578U;
    __Vtemp_hbdd2015e__0[1U] = 0x6772616dU;
    __Vtemp_hbdd2015e__0[2U] = 0x2f70726fU;
    __Vtemp_hbdd2015e__0[3U] = 0x2f72746cU;
    __Vtemp_hbdd2015e__0[4U] = 0x2e2eU;
    VL_READMEM_N(true, 8, 4096, 0, VL_CVT_PACK_STR_NW(5, __Vtemp_hbdd2015e__0)
                 ,  &(vlSelf->top__DOT__instrMemory__DOT__rom)
                 , 0, ~0ULL);
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

VL_ATTR_COLD void Vdut___024root___settle__TOP__0(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___settle__TOP__0\n"); );
    // Init
    SData/*9:0*/ __Vtableidx1;
    CData/*6:0*/ __Vtableidx2;
    // Body
    vlSelf->top__DOT__ResultW = ((0U == (IData)(vlSelf->top__DOT__ResultSrcW))
                                  ? vlSelf->top__DOT__ALUResultW
                                  : ((1U == (IData)(vlSelf->top__DOT__ResultSrcW))
                                      ? vlSelf->top__DOT__ReadDataW
                                      : ((2U == (IData)(vlSelf->top__DOT__ResultSrcW))
                                          ? vlSelf->top__DOT__PCPlus4W
                                          : 0U)));
    vlSelf->a0 = vlSelf->top__DOT__regfile__DOT__rom_array
        [0xaU];
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
    vlSelf->top__DOT__SrcAE = ((0U == (IData)(vlSelf->top__DOT__ForwardAE))
                                ? vlSelf->top__DOT__rd1E
                                : ((1U == (IData)(vlSelf->top__DOT__ForwardAE))
                                    ? vlSelf->top__DOT__ResultW
                                    : ((2U == (IData)(vlSelf->top__DOT__ForwardAE))
                                        ? vlSelf->top__DOT__ALUResultM
                                        : 0U)));
    vlSelf->top__DOT__srcB = ((IData)(vlSelf->top__DOT__ALUSrcE)
                               ? vlSelf->top__DOT__ImmExtE
                               : ((0U == (IData)(vlSelf->top__DOT__ForwardBE))
                                   ? vlSelf->top__DOT__rd2E
                                   : ((1U == (IData)(vlSelf->top__DOT__ForwardBE))
                                       ? vlSelf->top__DOT__ResultW
                                       : ((2U == (IData)(vlSelf->top__DOT__ForwardBE))
                                           ? vlSelf->top__DOT__ALUResultM
                                           : 0U))));
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
                                                 (vlSelf->top__DOT__rd1E 
                                                  >= vlSelf->top__DOT__srcB)
                                                  : 
                                                 (vlSelf->top__DOT__rd1E 
                                                  < vlSelf->top__DOT__srcB))
                                              : ((1U 
                                                  & (IData)(vlSelf->top__DOT__ALUControlE))
                                                  ? 
                                                 VL_GTES_III(32, vlSelf->top__DOT__rd1E, vlSelf->top__DOT__srcB)
                                                  : 
                                                 VL_LTS_III(32, vlSelf->top__DOT__rd1E, vlSelf->top__DOT__srcB)))
                                          : ((~ ((IData)(vlSelf->top__DOT__ALUControlE) 
                                                 >> 1U)) 
                                             & ((1U 
                                                 & (IData)(vlSelf->top__DOT__ALUControlE))
                                                 ? 
                                                (0U 
                                                 != 
                                                 (vlSelf->top__DOT__rd1E 
                                                  - vlSelf->top__DOT__srcB))
                                                 : 
                                                (0U 
                                                 == 
                                                 (vlSelf->top__DOT__rd1E 
                                                  - vlSelf->top__DOT__srcB))))));
    vlSelf->top__DOT__Flush = ((IData)(vlSelf->top__DOT__zero) 
                               | (IData)(vlSelf->top__DOT__JumpE));
    vlSelf->top__DOT__nextPC = (((IData)(vlSelf->top__DOT__JumpE) 
                                 | ((IData)(vlSelf->top__DOT__BranchE) 
                                    & (IData)(vlSelf->top__DOT__zero)))
                                 ? ((IData)(vlSelf->top__DOT__jalrSrc)
                                     ? vlSelf->top__DOT__ResultW
                                     : (vlSelf->top__DOT__PCe 
                                        + vlSelf->top__DOT__ImmExtE))
                                 : ((IData)(4U) + vlSelf->top__DOT__pc));
}

VL_ATTR_COLD void Vdut___024root___eval_initial(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_initial\n"); );
    // Body
    Vdut___024root___initial__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[3U] = 1U;
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
}

VL_ATTR_COLD void Vdut___024root___eval_settle(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_settle\n"); );
    // Body
    Vdut___024root___settle__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[3U] = 1U;
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void Vdut___024root___final(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___final\n"); );
}

VL_ATTR_COLD void Vdut___024root___ctor_var_reset(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->a0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__pc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__nextPC = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__PCd = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__PCPlus4D = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ImmExtD = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__instrD = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__RegWriteD = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__MemWriteD = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__JumpD = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__BranchD = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ALUSrcD = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__sizeSrcD = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__ResultSrcD = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__immSrcD = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__ALUControlD = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__PCe = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__PCPlus4E = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ImmExtE = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__rd1E = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__rd2E = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__srcB = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__aluResult = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__RdE = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__RegWriteE = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__MemWriteE = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__JumpE = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__BranchE = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ALUSrcE = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__sizeSrcE = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__ResultSrcE = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__ALUControlE = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__ALUResultM = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__WriteDataM = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ReadData = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__PCPlus4M = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__RdM = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__RegWriteM = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__MemWriteM = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__sizeSrcM = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__ResultSrcM = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__ALUResultW = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ReadDataW = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__PCPlus4W = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ResultW = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__RdW = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__RegWriteW = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ResultSrcW = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__Flush = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__stall = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ForwardAE = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__ForwardBE = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__SrcAE = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__Rs1E = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__Rs2E = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__jalrSrc = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__zero = VL_RAND_RESET_I(1);
    for (int __Vi0=0; __Vi0<4096; ++__Vi0) {
        vlSelf->top__DOT__instrMemory__DOT__rom[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->top__DOT__controlUnit__DOT__aluOp = VL_RAND_RESET_I(2);
    for (int __Vi0=0; __Vi0<32; ++__Vi0) {
        vlSelf->top__DOT__regfile__DOT__rom_array[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0=0; __Vi0<131072; ++__Vi0) {
        vlSelf->top__DOT__DataMemory__DOT__memory[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->__Vdlyvdim0__top__DOT__regfile__DOT__rom_array__v0 = 0;
    vlSelf->__Vdlyvval__top__DOT__regfile__DOT__rom_array__v0 = VL_RAND_RESET_I(32);
    vlSelf->__Vdlyvset__top__DOT__regfile__DOT__rom_array__v0 = 0;
    for (int __Vi0=0; __Vi0<4; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
