// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpiptop.h for the primary calling header

#include "verilated.h"

#include "Vpiptop___024root.h"

VL_ATTR_COLD void Vpiptop___024root___initial__TOP__0(Vpiptop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpiptop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpiptop___024root___initial__TOP__0\n"); );
    // Init
    VlWide<4>/*127:0*/ __Vtemp_h044bf4ee__0;
    VlWide<5>/*159:0*/ __Vtemp_hbdd2015e__0;
    // Body
    __Vtemp_h044bf4ee__0[0U] = 0x2e686578U;
    __Vtemp_h044bf4ee__0[1U] = 0x64617461U;
    __Vtemp_h044bf4ee__0[2U] = 0x72746c2fU;
    __Vtemp_h044bf4ee__0[3U] = 0x2e2e2fU;
    VL_READMEM_N(true, 8, 131072, 0, VL_CVT_PACK_STR_NW(4, __Vtemp_h044bf4ee__0)
                 ,  &(vlSelf->piptop__DOT__DataMemory__DOT__memory)
                 , 0, ~0ULL);
    __Vtemp_hbdd2015e__0[0U] = 0x2e686578U;
    __Vtemp_hbdd2015e__0[1U] = 0x6772616dU;
    __Vtemp_hbdd2015e__0[2U] = 0x2f70726fU;
    __Vtemp_hbdd2015e__0[3U] = 0x2f72746cU;
    __Vtemp_hbdd2015e__0[4U] = 0x2e2eU;
    VL_READMEM_N(true, 8, 4096, 0, VL_CVT_PACK_STR_NW(5, __Vtemp_hbdd2015e__0)
                 ,  &(vlSelf->piptop__DOT__instrMemory__DOT__rom)
                 , 0, ~0ULL);
}

extern const VlUnpacked<CData/*0:0*/, 256> Vpiptop__ConstPool__TABLE_h284d473c_0;
extern const VlUnpacked<CData/*1:0*/, 256> Vpiptop__ConstPool__TABLE_hd0a7031d_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vpiptop__ConstPool__TABLE_hc1441e35_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vpiptop__ConstPool__TABLE_h9bdefb87_0;
extern const VlUnpacked<CData/*1:0*/, 256> Vpiptop__ConstPool__TABLE_h745e4cf0_0;
extern const VlUnpacked<CData/*1:0*/, 256> Vpiptop__ConstPool__TABLE_haf1b65cc_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vpiptop__ConstPool__TABLE_h0947e088_0;
extern const VlUnpacked<CData/*2:0*/, 128> Vpiptop__ConstPool__TABLE_ha4123b68_0;

VL_ATTR_COLD void Vpiptop___024root___settle__TOP__0(Vpiptop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpiptop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpiptop___024root___settle__TOP__0\n"); );
    // Init
    CData/*0:0*/ piptop__DOT__jumpSrc;
    CData/*1:0*/ piptop__DOT__immSrc;
    CData/*1:0*/ piptop__DOT__controlUnit__DOT__aluOp;
    CData/*7:0*/ __Vtableidx1;
    CData/*6:0*/ __Vtableidx2;
    // Body
    vlSelf->piptop__DOT__srcB = ((1U & vlSelf->piptop__DOT__PRegDecode__DOT__rom_array
                                  [0xcU]) ? vlSelf->piptop__DOT__PRegDecode__DOT__rom_array
                                 [4U] : vlSelf->piptop__DOT__PRegDecode__DOT__rom_array
                                 [1U]);
    if ((0U == vlSelf->piptop__DOT__triggerFSM__DOT__current_state)) {
        vlSelf->piptop__DOT__triggerFSM__DOT__next_state 
            = ((IData)(vlSelf->trigger) ? 1U : vlSelf->piptop__DOT__triggerFSM__DOT__current_state);
    } else if ((1U == vlSelf->piptop__DOT__triggerFSM__DOT__current_state)) {
        vlSelf->piptop__DOT__triggerFSM__DOT__next_state = 1U;
    }
    vlSelf->piptop__DOT__instr = ((vlSelf->piptop__DOT__instrMemory__DOT__rom
                                   [(0xfffU & ((IData)(3U) 
                                               + vlSelf->piptop__DOT__pc))] 
                                   << 0x18U) | ((vlSelf->piptop__DOT__instrMemory__DOT__rom
                                                 [(0xfffU 
                                                   & ((IData)(2U) 
                                                      + vlSelf->piptop__DOT__pc))] 
                                                 << 0x10U) 
                                                | ((vlSelf->piptop__DOT__instrMemory__DOT__rom
                                                    [
                                                    (0xfffU 
                                                     & ((IData)(1U) 
                                                        + vlSelf->piptop__DOT__pc))] 
                                                    << 8U) 
                                                   | vlSelf->piptop__DOT__instrMemory__DOT__rom
                                                   [
                                                   (0xfffU 
                                                    & vlSelf->piptop__DOT__pc)])));
    vlSelf->piptop__DOT__ReadData = ((0x4000U & vlSelf->piptop__DOT__instr)
                                      ? ((0x2000U & vlSelf->piptop__DOT__instr)
                                          ? 0U : ((0x1000U 
                                                   & vlSelf->piptop__DOT__instr)
                                                   ? 
                                                  ((vlSelf->piptop__DOT__DataMemory__DOT__memory
                                                    [
                                                    (0x1ffffU 
                                                     & ((IData)(1U) 
                                                        + 
                                                        vlSelf->piptop__DOT__PRegExecute__DOT__rom_array
                                                        [0U]))] 
                                                    << 8U) 
                                                   | vlSelf->piptop__DOT__DataMemory__DOT__memory
                                                   [
                                                   (0x1ffffU 
                                                    & vlSelf->piptop__DOT__PRegExecute__DOT__rom_array
                                                    [0U])])
                                                   : 
                                                  vlSelf->piptop__DOT__DataMemory__DOT__memory
                                                  [
                                                  (0x1ffffU 
                                                   & vlSelf->piptop__DOT__PRegExecute__DOT__rom_array
                                                   [0U])]))
                                      : ((0x2000U & vlSelf->piptop__DOT__instr)
                                          ? ((0x1000U 
                                              & vlSelf->piptop__DOT__instr)
                                              ? 0U : 
                                             ((vlSelf->piptop__DOT__DataMemory__DOT__memory
                                               [(0x1ffffU 
                                                 & ((IData)(3U) 
                                                    + 
                                                    vlSelf->piptop__DOT__PRegExecute__DOT__rom_array
                                                    [0U]))] 
                                               << 0x18U) 
                                              | ((vlSelf->piptop__DOT__DataMemory__DOT__memory
                                                  [
                                                  (0x1ffffU 
                                                   & ((IData)(2U) 
                                                      + 
                                                      vlSelf->piptop__DOT__PRegExecute__DOT__rom_array
                                                      [0U]))] 
                                                  << 0x10U) 
                                                 | ((vlSelf->piptop__DOT__DataMemory__DOT__memory
                                                     [
                                                     (0x1ffffU 
                                                      & ((IData)(1U) 
                                                         + 
                                                         vlSelf->piptop__DOT__PRegExecute__DOT__rom_array
                                                         [0U]))] 
                                                     << 8U) 
                                                    | vlSelf->piptop__DOT__DataMemory__DOT__memory
                                                    [
                                                    (0x1ffffU 
                                                     & vlSelf->piptop__DOT__PRegExecute__DOT__rom_array
                                                     [0U])]))))
                                          : ((0x1000U 
                                              & vlSelf->piptop__DOT__instr)
                                              ? (((- (IData)(
                                                             (1U 
                                                              & (vlSelf->piptop__DOT__DataMemory__DOT__memory
                                                                 [
                                                                 (0x1ffffU 
                                                                  & ((IData)(1U) 
                                                                     + 
                                                                     vlSelf->piptop__DOT__PRegExecute__DOT__rom_array
                                                                     [0U]))] 
                                                                 >> 7U)))) 
                                                  << 0x10U) 
                                                 | ((vlSelf->piptop__DOT__DataMemory__DOT__memory
                                                     [
                                                     (0x1ffffU 
                                                      & ((IData)(1U) 
                                                         + 
                                                         vlSelf->piptop__DOT__PRegExecute__DOT__rom_array
                                                         [0U]))] 
                                                     << 8U) 
                                                    | vlSelf->piptop__DOT__DataMemory__DOT__memory
                                                    [
                                                    (0x1ffffU 
                                                     & vlSelf->piptop__DOT__PRegExecute__DOT__rom_array
                                                     [0U])]))
                                              : (((- (IData)(
                                                             (1U 
                                                              & (vlSelf->piptop__DOT__DataMemory__DOT__memory
                                                                 [
                                                                 (0x1ffffU 
                                                                  & vlSelf->piptop__DOT__PRegExecute__DOT__rom_array
                                                                  [0U])] 
                                                                 >> 7U)))) 
                                                  << 8U) 
                                                 | vlSelf->piptop__DOT__DataMemory__DOT__memory
                                                 [(0x1ffffU 
                                                   & vlSelf->piptop__DOT__PRegExecute__DOT__rom_array
                                                   [0U])]))));
    __Vtableidx1 = (((IData)(vlSelf->piptop__DOT__zero) 
                     << 7U) | (0x7fU & vlSelf->piptop__DOT__instr));
    vlSelf->piptop__DOT__RegWriteD = Vpiptop__ConstPool__TABLE_h284d473c_0
        [__Vtableidx1];
    piptop__DOT__immSrc = Vpiptop__ConstPool__TABLE_hd0a7031d_0
        [__Vtableidx1];
    vlSelf->piptop__DOT__ALUSrcD = Vpiptop__ConstPool__TABLE_hc1441e35_0
        [__Vtableidx1];
    vlSelf->piptop__DOT__MemWriteD = Vpiptop__ConstPool__TABLE_h9bdefb87_0
        [__Vtableidx1];
    vlSelf->piptop__DOT__ResultSrcD = Vpiptop__ConstPool__TABLE_h745e4cf0_0
        [__Vtableidx1];
    piptop__DOT__controlUnit__DOT__aluOp = Vpiptop__ConstPool__TABLE_haf1b65cc_0
        [__Vtableidx1];
    piptop__DOT__jumpSrc = Vpiptop__ConstPool__TABLE_h0947e088_0
        [__Vtableidx1];
    vlSelf->piptop__DOT__immExt = ((2U & (IData)(piptop__DOT__immSrc))
                                    ? ((1U & (IData)(piptop__DOT__immSrc))
                                        ? ((IData)(piptop__DOT__jumpSrc)
                                            ? (((- (IData)(
                                                           (vlSelf->piptop__DOT__instr 
                                                            >> 0x1fU))) 
                                                << 0x15U) 
                                               | ((0x100000U 
                                                   & (vlSelf->piptop__DOT__instr 
                                                      >> 0xbU)) 
                                                  | ((0xff000U 
                                                      & vlSelf->piptop__DOT__instr) 
                                                     | ((0x800U 
                                                         & (vlSelf->piptop__DOT__instr 
                                                            >> 9U)) 
                                                        | (0x7feU 
                                                           & (vlSelf->piptop__DOT__instr 
                                                              >> 0x14U))))))
                                            : (0xfffff000U 
                                               & vlSelf->piptop__DOT__instr))
                                        : (((- (IData)(
                                                       (vlSelf->piptop__DOT__instr 
                                                        >> 0x1fU))) 
                                            << 0xcU) 
                                           | ((0x800U 
                                               & (vlSelf->piptop__DOT__instr 
                                                  << 4U)) 
                                              | ((0x7e0U 
                                                  & (vlSelf->piptop__DOT__instr 
                                                     >> 0x14U)) 
                                                 | (0x1eU 
                                                    & (vlSelf->piptop__DOT__instr 
                                                       >> 7U))))))
                                    : ((1U & (IData)(piptop__DOT__immSrc))
                                        ? (((- (IData)(
                                                       (vlSelf->piptop__DOT__instr 
                                                        >> 0x1fU))) 
                                            << 0xcU) 
                                           | ((0xfe0U 
                                               & (vlSelf->piptop__DOT__instr 
                                                  >> 0x14U)) 
                                              | (0x1fU 
                                                 & (vlSelf->piptop__DOT__instr 
                                                    >> 7U))))
                                        : (((- (IData)(
                                                       (vlSelf->piptop__DOT__instr 
                                                        >> 0x1fU))) 
                                            << 0xcU) 
                                           | (vlSelf->piptop__DOT__instr 
                                              >> 0x14U))));
    __Vtableidx2 = (((0x40U & (vlSelf->piptop__DOT__instr 
                               << 1U)) | (0x20U & (vlSelf->piptop__DOT__instr 
                                                   >> 0x19U))) 
                    | ((0x1cU & (vlSelf->piptop__DOT__instr 
                                 >> 0xaU)) | (IData)(piptop__DOT__controlUnit__DOT__aluOp)));
    vlSelf->piptop__DOT__ALUControlD = Vpiptop__ConstPool__TABLE_ha4123b68_0
        [__Vtableidx2];
}

VL_ATTR_COLD void Vpiptop___024root___eval_initial(Vpiptop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpiptop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpiptop___024root___eval_initial\n"); );
    // Body
    Vpiptop___024root___initial__TOP__0(vlSelf);
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void Vpiptop___024root___eval_settle(Vpiptop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpiptop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpiptop___024root___eval_settle\n"); );
    // Body
    Vpiptop___024root___settle__TOP__0(vlSelf);
}

VL_ATTR_COLD void Vpiptop___024root___final(Vpiptop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpiptop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpiptop___024root___final\n"); );
}

VL_ATTR_COLD void Vpiptop___024root___ctor_var_reset(Vpiptop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpiptop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpiptop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->trigger = VL_RAND_RESET_I(1);
    vlSelf->a0 = VL_RAND_RESET_I(32);
    vlSelf->piptop__DOT__pc = VL_RAND_RESET_I(32);
    vlSelf->piptop__DOT__nextPC = VL_RAND_RESET_I(32);
    vlSelf->piptop__DOT__instr = VL_RAND_RESET_I(32);
    vlSelf->piptop__DOT__immExt = VL_RAND_RESET_I(32);
    vlSelf->piptop__DOT__RegWriteD = VL_RAND_RESET_I(1);
    vlSelf->piptop__DOT__MemWriteD = VL_RAND_RESET_I(1);
    vlSelf->piptop__DOT__JumpD = VL_RAND_RESET_I(1);
    vlSelf->piptop__DOT__BranchD = VL_RAND_RESET_I(1);
    vlSelf->piptop__DOT__ALUSrcD = VL_RAND_RESET_I(1);
    vlSelf->piptop__DOT__ALUControlD = VL_RAND_RESET_I(3);
    vlSelf->piptop__DOT__ResultSrcD = VL_RAND_RESET_I(2);
    vlSelf->piptop__DOT__srcB = VL_RAND_RESET_I(32);
    vlSelf->piptop__DOT__ReadData = VL_RAND_RESET_I(32);
    vlSelf->piptop__DOT__ALUResultW = VL_RAND_RESET_I(32);
    vlSelf->piptop__DOT__PCPlus4W = VL_RAND_RESET_I(32);
    vlSelf->piptop__DOT__RdW = VL_RAND_RESET_I(5);
    vlSelf->piptop__DOT__RegWriteW = VL_RAND_RESET_I(1);
    vlSelf->piptop__DOT__ResultSrcW = VL_RAND_RESET_I(2);
    vlSelf->piptop__DOT__zero = VL_RAND_RESET_I(1);
    vlSelf->piptop__DOT__triggerFSM__DOT__current_state = 0;
    vlSelf->piptop__DOT__triggerFSM__DOT__next_state = 0;
    for (int __Vi0=0; __Vi0<4096; ++__Vi0) {
        vlSelf->piptop__DOT__instrMemory__DOT__rom[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0=0; __Vi0<8; ++__Vi0) {
        vlSelf->piptop__DOT__PRegFetch__DOT__rom_array[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0=0; __Vi0<32; ++__Vi0) {
        vlSelf->piptop__DOT__regfile__DOT__rom_array[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0=0; __Vi0<16; ++__Vi0) {
        vlSelf->piptop__DOT__PRegDecode__DOT__rom_array[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0=0; __Vi0<8; ++__Vi0) {
        vlSelf->piptop__DOT__PRegExecute__DOT__rom_array[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0=0; __Vi0<131072; ++__Vi0) {
        vlSelf->piptop__DOT__DataMemory__DOT__memory[__Vi0] = VL_RAND_RESET_I(8);
    }
}
