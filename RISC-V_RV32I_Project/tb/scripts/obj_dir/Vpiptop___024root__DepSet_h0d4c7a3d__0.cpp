// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpiptop.h for the primary calling header

#include "verilated.h"

#include "Vpiptop___024root.h"

extern const VlUnpacked<CData/*0:0*/, 256> Vpiptop__ConstPool__TABLE_h284d473c_0;
extern const VlUnpacked<CData/*1:0*/, 256> Vpiptop__ConstPool__TABLE_hd0a7031d_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vpiptop__ConstPool__TABLE_hc1441e35_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vpiptop__ConstPool__TABLE_h9bdefb87_0;
extern const VlUnpacked<CData/*1:0*/, 256> Vpiptop__ConstPool__TABLE_h745e4cf0_0;
extern const VlUnpacked<CData/*1:0*/, 256> Vpiptop__ConstPool__TABLE_haf1b65cc_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vpiptop__ConstPool__TABLE_h0947e088_0;
extern const VlUnpacked<CData/*2:0*/, 128> Vpiptop__ConstPool__TABLE_ha4123b68_0;

VL_INLINE_OPT void Vpiptop___024root___sequent__TOP__0(Vpiptop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpiptop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpiptop___024root___sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ piptop__DOT__jumpSrc;
    CData/*1:0*/ piptop__DOT__immSrc;
    CData/*1:0*/ piptop__DOT__controlUnit__DOT__aluOp;
    CData/*7:0*/ __Vtableidx1;
    CData/*6:0*/ __Vtableidx2;
    IData/*31:0*/ __Vdlyvval__piptop__DOT__PRegFetch__DOT__rom_array__v0;
    IData/*31:0*/ __Vdlyvval__piptop__DOT__PRegFetch__DOT__rom_array__v1;
    IData/*31:0*/ __Vdlyvval__piptop__DOT__PRegFetch__DOT__rom_array__v2;
    CData/*4:0*/ __Vdlyvdim0__piptop__DOT__regfile__DOT__rom_array__v0;
    IData/*31:0*/ __Vdlyvval__piptop__DOT__regfile__DOT__rom_array__v0;
    CData/*0:0*/ __Vdlyvset__piptop__DOT__regfile__DOT__rom_array__v0;
    IData/*31:0*/ __Vdlyvval__piptop__DOT__PRegDecode__DOT__rom_array__v0;
    IData/*31:0*/ __Vdlyvval__piptop__DOT__PRegDecode__DOT__rom_array__v1;
    IData/*31:0*/ __Vdlyvval__piptop__DOT__PRegDecode__DOT__rom_array__v2;
    IData/*31:0*/ __Vdlyvval__piptop__DOT__PRegDecode__DOT__rom_array__v3;
    IData/*31:0*/ __Vdlyvval__piptop__DOT__PRegDecode__DOT__rom_array__v4;
    IData/*31:0*/ __Vdlyvval__piptop__DOT__PRegDecode__DOT__rom_array__v5;
    IData/*31:0*/ __Vdlyvval__piptop__DOT__PRegDecode__DOT__rom_array__v6;
    IData/*31:0*/ __Vdlyvval__piptop__DOT__PRegDecode__DOT__rom_array__v7;
    IData/*31:0*/ __Vdlyvval__piptop__DOT__PRegDecode__DOT__rom_array__v8;
    IData/*31:0*/ __Vdlyvval__piptop__DOT__PRegDecode__DOT__rom_array__v9;
    IData/*31:0*/ __Vdlyvval__piptop__DOT__PRegDecode__DOT__rom_array__v10;
    IData/*31:0*/ __Vdlyvval__piptop__DOT__PRegDecode__DOT__rom_array__v11;
    IData/*31:0*/ __Vdlyvval__piptop__DOT__PRegDecode__DOT__rom_array__v12;
    IData/*31:0*/ __Vdlyvval__piptop__DOT__PRegExecute__DOT__rom_array__v0;
    IData/*31:0*/ __Vdlyvval__piptop__DOT__PRegExecute__DOT__rom_array__v1;
    IData/*31:0*/ __Vdlyvval__piptop__DOT__PRegExecute__DOT__rom_array__v2;
    IData/*31:0*/ __Vdlyvval__piptop__DOT__PRegExecute__DOT__rom_array__v3;
    IData/*31:0*/ __Vdlyvval__piptop__DOT__PRegExecute__DOT__rom_array__v4;
    IData/*31:0*/ __Vdlyvval__piptop__DOT__PRegExecute__DOT__rom_array__v5;
    IData/*31:0*/ __Vdlyvval__piptop__DOT__PRegExecute__DOT__rom_array__v6;
    IData/*16:0*/ __Vdlyvdim0__piptop__DOT__DataMemory__DOT__memory__v0;
    CData/*7:0*/ __Vdlyvval__piptop__DOT__DataMemory__DOT__memory__v0;
    CData/*0:0*/ __Vdlyvset__piptop__DOT__DataMemory__DOT__memory__v0;
    IData/*16:0*/ __Vdlyvdim0__piptop__DOT__DataMemory__DOT__memory__v1;
    CData/*7:0*/ __Vdlyvval__piptop__DOT__DataMemory__DOT__memory__v1;
    IData/*16:0*/ __Vdlyvdim0__piptop__DOT__DataMemory__DOT__memory__v2;
    CData/*7:0*/ __Vdlyvval__piptop__DOT__DataMemory__DOT__memory__v2;
    IData/*16:0*/ __Vdlyvdim0__piptop__DOT__DataMemory__DOT__memory__v3;
    CData/*7:0*/ __Vdlyvval__piptop__DOT__DataMemory__DOT__memory__v3;
    IData/*16:0*/ __Vdlyvdim0__piptop__DOT__DataMemory__DOT__memory__v4;
    CData/*7:0*/ __Vdlyvval__piptop__DOT__DataMemory__DOT__memory__v4;
    CData/*0:0*/ __Vdlyvset__piptop__DOT__DataMemory__DOT__memory__v4;
    IData/*16:0*/ __Vdlyvdim0__piptop__DOT__DataMemory__DOT__memory__v5;
    CData/*7:0*/ __Vdlyvval__piptop__DOT__DataMemory__DOT__memory__v5;
    IData/*16:0*/ __Vdlyvdim0__piptop__DOT__DataMemory__DOT__memory__v6;
    CData/*7:0*/ __Vdlyvval__piptop__DOT__DataMemory__DOT__memory__v6;
    CData/*0:0*/ __Vdlyvset__piptop__DOT__DataMemory__DOT__memory__v6;
    // Body
    __Vdlyvset__piptop__DOT__regfile__DOT__rom_array__v0 = 0U;
    __Vdlyvset__piptop__DOT__DataMemory__DOT__memory__v0 = 0U;
    __Vdlyvset__piptop__DOT__DataMemory__DOT__memory__v4 = 0U;
    __Vdlyvset__piptop__DOT__DataMemory__DOT__memory__v6 = 0U;
    vlSelf->a0 = vlSelf->piptop__DOT__regfile__DOT__rom_array
        [0xaU];
    if (vlSelf->piptop__DOT__RegWriteW) {
        __Vdlyvval__piptop__DOT__regfile__DOT__rom_array__v0 
            = ((0U == (IData)(vlSelf->piptop__DOT__ResultSrcW))
                ? vlSelf->piptop__DOT__ALUResultW : 
               ((1U == (IData)(vlSelf->piptop__DOT__ResultSrcW))
                 ? vlSelf->piptop__DOT__ReadData : 
                ((2U == (IData)(vlSelf->piptop__DOT__ResultSrcW))
                  ? vlSelf->piptop__DOT__PCPlus4W : 0U)));
        __Vdlyvset__piptop__DOT__regfile__DOT__rom_array__v0 = 1U;
        __Vdlyvdim0__piptop__DOT__regfile__DOT__rom_array__v0 
            = vlSelf->piptop__DOT__RdW;
    }
    __Vdlyvval__piptop__DOT__PRegExecute__DOT__rom_array__v0 
        = ((4U & vlSelf->piptop__DOT__PRegDecode__DOT__rom_array
            [0xbU]) ? ((2U & vlSelf->piptop__DOT__PRegDecode__DOT__rom_array
                        [0xbU]) ? ((1U & vlSelf->piptop__DOT__PRegDecode__DOT__rom_array
                                    [0xbU]) ? (vlSelf->piptop__DOT__PRegDecode__DOT__rom_array
                                               [0U] 
                                               >> (0x1fU 
                                                   & vlSelf->piptop__DOT__srcB))
                                    : (vlSelf->piptop__DOT__PRegDecode__DOT__rom_array
                                       [0U] << (0x1fU 
                                                & vlSelf->piptop__DOT__srcB)))
                        : ((1U & vlSelf->piptop__DOT__PRegDecode__DOT__rom_array
                            [0xbU]) ? (VL_LTS_III(32, 
                                                  vlSelf->piptop__DOT__PRegDecode__DOT__rom_array
                                                  [0U], vlSelf->piptop__DOT__srcB)
                                        ? 1U : 0U) : vlSelf->piptop__DOT__srcB))
            : ((2U & vlSelf->piptop__DOT__PRegDecode__DOT__rom_array
                [0xbU]) ? ((1U & vlSelf->piptop__DOT__PRegDecode__DOT__rom_array
                            [0xbU]) ? (vlSelf->piptop__DOT__PRegDecode__DOT__rom_array
                                       [0U] | vlSelf->piptop__DOT__srcB)
                            : (vlSelf->piptop__DOT__PRegDecode__DOT__rom_array
                               [0U] & vlSelf->piptop__DOT__srcB))
                : ((1U & vlSelf->piptop__DOT__PRegDecode__DOT__rom_array
                    [0xbU]) ? (vlSelf->piptop__DOT__PRegDecode__DOT__rom_array
                               [0U] - vlSelf->piptop__DOT__srcB)
                    : (vlSelf->piptop__DOT__PRegDecode__DOT__rom_array
                       [0U] + vlSelf->piptop__DOT__srcB))));
    __Vdlyvval__piptop__DOT__PRegExecute__DOT__rom_array__v1 
        = vlSelf->piptop__DOT__PRegDecode__DOT__rom_array
        [1U];
    __Vdlyvval__piptop__DOT__PRegExecute__DOT__rom_array__v2 
        = vlSelf->piptop__DOT__PRegDecode__DOT__rom_array
        [5U];
    __Vdlyvval__piptop__DOT__PRegExecute__DOT__rom_array__v3 
        = (0x1fU & vlSelf->piptop__DOT__PRegDecode__DOT__rom_array
           [3U]);
    __Vdlyvval__piptop__DOT__PRegExecute__DOT__rom_array__v4 
        = (1U & vlSelf->piptop__DOT__PRegDecode__DOT__rom_array
           [6U]);
    __Vdlyvval__piptop__DOT__PRegExecute__DOT__rom_array__v5 
        = (3U & vlSelf->piptop__DOT__PRegDecode__DOT__rom_array
           [7U]);
    __Vdlyvval__piptop__DOT__PRegExecute__DOT__rom_array__v6 
        = (1U & vlSelf->piptop__DOT__PRegDecode__DOT__rom_array
           [8U]);
    __Vdlyvval__piptop__DOT__PRegDecode__DOT__rom_array__v0 
        = vlSelf->piptop__DOT__regfile__DOT__rom_array
        [(0x1fU & (vlSelf->piptop__DOT__instr >> 0xfU))];
    __Vdlyvval__piptop__DOT__PRegDecode__DOT__rom_array__v1 
        = vlSelf->piptop__DOT__regfile__DOT__rom_array
        [(0x1fU & (vlSelf->piptop__DOT__instr >> 0x14U))];
    __Vdlyvval__piptop__DOT__PRegDecode__DOT__rom_array__v2 
        = vlSelf->piptop__DOT__PRegFetch__DOT__rom_array
        [1U];
    __Vdlyvval__piptop__DOT__PRegDecode__DOT__rom_array__v3 
        = (0x1fU & (vlSelf->piptop__DOT__instr >> 7U));
    __Vdlyvval__piptop__DOT__PRegDecode__DOT__rom_array__v4 
        = vlSelf->piptop__DOT__immExt;
    __Vdlyvval__piptop__DOT__PRegDecode__DOT__rom_array__v5 
        = vlSelf->piptop__DOT__PRegFetch__DOT__rom_array
        [2U];
    __Vdlyvval__piptop__DOT__PRegDecode__DOT__rom_array__v6 
        = vlSelf->piptop__DOT__RegWriteD;
    __Vdlyvval__piptop__DOT__PRegDecode__DOT__rom_array__v7 
        = vlSelf->piptop__DOT__ResultSrcD;
    __Vdlyvval__piptop__DOT__PRegDecode__DOT__rom_array__v8 
        = vlSelf->piptop__DOT__MemWriteD;
    __Vdlyvval__piptop__DOT__PRegDecode__DOT__rom_array__v9 
        = vlSelf->piptop__DOT__JumpD;
    __Vdlyvval__piptop__DOT__PRegDecode__DOT__rom_array__v10 
        = vlSelf->piptop__DOT__BranchD;
    __Vdlyvval__piptop__DOT__PRegDecode__DOT__rom_array__v11 
        = vlSelf->piptop__DOT__ALUControlD;
    __Vdlyvval__piptop__DOT__PRegDecode__DOT__rom_array__v12 
        = vlSelf->piptop__DOT__ALUSrcD;
    if ((1U & vlSelf->piptop__DOT__PRegExecute__DOT__rom_array
         [6U])) {
        if ((2U == (7U & (vlSelf->piptop__DOT__instr 
                          >> 0xcU)))) {
            __Vdlyvval__piptop__DOT__DataMemory__DOT__memory__v0 
                = (0xffU & vlSelf->piptop__DOT__PRegExecute__DOT__rom_array
                   [1U]);
            __Vdlyvset__piptop__DOT__DataMemory__DOT__memory__v0 = 1U;
            __Vdlyvdim0__piptop__DOT__DataMemory__DOT__memory__v0 
                = (0x1ffffU & vlSelf->piptop__DOT__PRegExecute__DOT__rom_array
                   [0U]);
            __Vdlyvval__piptop__DOT__DataMemory__DOT__memory__v1 
                = (0xffU & (vlSelf->piptop__DOT__PRegExecute__DOT__rom_array
                            [1U] >> 8U));
            __Vdlyvdim0__piptop__DOT__DataMemory__DOT__memory__v1 
                = (0x1ffffU & ((IData)(1U) + vlSelf->piptop__DOT__PRegExecute__DOT__rom_array
                               [0U]));
            __Vdlyvval__piptop__DOT__DataMemory__DOT__memory__v2 
                = (0xffU & (vlSelf->piptop__DOT__PRegExecute__DOT__rom_array
                            [1U] >> 0x10U));
            __Vdlyvdim0__piptop__DOT__DataMemory__DOT__memory__v2 
                = (0x1ffffU & ((IData)(2U) + vlSelf->piptop__DOT__PRegExecute__DOT__rom_array
                               [0U]));
            __Vdlyvval__piptop__DOT__DataMemory__DOT__memory__v3 
                = (vlSelf->piptop__DOT__PRegExecute__DOT__rom_array
                   [1U] >> 0x18U);
            __Vdlyvdim0__piptop__DOT__DataMemory__DOT__memory__v3 
                = (0x1ffffU & ((IData)(3U) + vlSelf->piptop__DOT__PRegExecute__DOT__rom_array
                               [0U]));
        } else if ((1U == (7U & (vlSelf->piptop__DOT__instr 
                                 >> 0xcU)))) {
            __Vdlyvval__piptop__DOT__DataMemory__DOT__memory__v4 
                = (0xffU & vlSelf->piptop__DOT__PRegExecute__DOT__rom_array
                   [1U]);
            __Vdlyvset__piptop__DOT__DataMemory__DOT__memory__v4 = 1U;
            __Vdlyvdim0__piptop__DOT__DataMemory__DOT__memory__v4 
                = (0x1ffffU & vlSelf->piptop__DOT__PRegExecute__DOT__rom_array
                   [0U]);
            __Vdlyvval__piptop__DOT__DataMemory__DOT__memory__v5 
                = (0xffU & (vlSelf->piptop__DOT__PRegExecute__DOT__rom_array
                            [1U] >> 8U));
            __Vdlyvdim0__piptop__DOT__DataMemory__DOT__memory__v5 
                = (0x1ffffU & ((IData)(1U) + vlSelf->piptop__DOT__PRegExecute__DOT__rom_array
                               [0U]));
        } else if ((0U == (7U & (vlSelf->piptop__DOT__instr 
                                 >> 0xcU)))) {
            __Vdlyvval__piptop__DOT__DataMemory__DOT__memory__v6 
                = (0xffU & vlSelf->piptop__DOT__PRegExecute__DOT__rom_array
                   [1U]);
            __Vdlyvset__piptop__DOT__DataMemory__DOT__memory__v6 = 1U;
            __Vdlyvdim0__piptop__DOT__DataMemory__DOT__memory__v6 
                = (0x1ffffU & vlSelf->piptop__DOT__PRegExecute__DOT__rom_array
                   [0U]);
        }
    }
    __Vdlyvval__piptop__DOT__PRegFetch__DOT__rom_array__v0 
        = vlSelf->piptop__DOT__instr;
    __Vdlyvval__piptop__DOT__PRegFetch__DOT__rom_array__v1 
        = vlSelf->piptop__DOT__pc;
    __Vdlyvval__piptop__DOT__PRegFetch__DOT__rom_array__v2 
        = ((IData)(4U) + vlSelf->piptop__DOT__pc);
    if (__Vdlyvset__piptop__DOT__regfile__DOT__rom_array__v0) {
        vlSelf->piptop__DOT__regfile__DOT__rom_array[__Vdlyvdim0__piptop__DOT__regfile__DOT__rom_array__v0] 
            = __Vdlyvval__piptop__DOT__regfile__DOT__rom_array__v0;
    }
    vlSelf->piptop__DOT__PRegDecode__DOT__rom_array[0U] 
        = __Vdlyvval__piptop__DOT__PRegDecode__DOT__rom_array__v0;
    vlSelf->piptop__DOT__PRegDecode__DOT__rom_array[1U] 
        = __Vdlyvval__piptop__DOT__PRegDecode__DOT__rom_array__v1;
    vlSelf->piptop__DOT__PRegDecode__DOT__rom_array[2U] 
        = __Vdlyvval__piptop__DOT__PRegDecode__DOT__rom_array__v2;
    vlSelf->piptop__DOT__PRegDecode__DOT__rom_array[3U] 
        = __Vdlyvval__piptop__DOT__PRegDecode__DOT__rom_array__v3;
    vlSelf->piptop__DOT__PRegDecode__DOT__rom_array[4U] 
        = __Vdlyvval__piptop__DOT__PRegDecode__DOT__rom_array__v4;
    vlSelf->piptop__DOT__PRegDecode__DOT__rom_array[5U] 
        = __Vdlyvval__piptop__DOT__PRegDecode__DOT__rom_array__v5;
    vlSelf->piptop__DOT__PRegDecode__DOT__rom_array[6U] 
        = __Vdlyvval__piptop__DOT__PRegDecode__DOT__rom_array__v6;
    vlSelf->piptop__DOT__PRegDecode__DOT__rom_array[7U] 
        = __Vdlyvval__piptop__DOT__PRegDecode__DOT__rom_array__v7;
    vlSelf->piptop__DOT__PRegDecode__DOT__rom_array[8U] 
        = __Vdlyvval__piptop__DOT__PRegDecode__DOT__rom_array__v8;
    vlSelf->piptop__DOT__PRegDecode__DOT__rom_array[9U] 
        = __Vdlyvval__piptop__DOT__PRegDecode__DOT__rom_array__v9;
    vlSelf->piptop__DOT__PRegDecode__DOT__rom_array[0xaU] 
        = __Vdlyvval__piptop__DOT__PRegDecode__DOT__rom_array__v10;
    vlSelf->piptop__DOT__PRegDecode__DOT__rom_array[0xbU] 
        = __Vdlyvval__piptop__DOT__PRegDecode__DOT__rom_array__v11;
    vlSelf->piptop__DOT__PRegDecode__DOT__rom_array[0xcU] 
        = __Vdlyvval__piptop__DOT__PRegDecode__DOT__rom_array__v12;
    vlSelf->piptop__DOT__PRegExecute__DOT__rom_array[0U] 
        = __Vdlyvval__piptop__DOT__PRegExecute__DOT__rom_array__v0;
    vlSelf->piptop__DOT__PRegExecute__DOT__rom_array[1U] 
        = __Vdlyvval__piptop__DOT__PRegExecute__DOT__rom_array__v1;
    vlSelf->piptop__DOT__PRegExecute__DOT__rom_array[2U] 
        = __Vdlyvval__piptop__DOT__PRegExecute__DOT__rom_array__v2;
    vlSelf->piptop__DOT__PRegExecute__DOT__rom_array[3U] 
        = __Vdlyvval__piptop__DOT__PRegExecute__DOT__rom_array__v3;
    vlSelf->piptop__DOT__PRegExecute__DOT__rom_array[4U] 
        = __Vdlyvval__piptop__DOT__PRegExecute__DOT__rom_array__v4;
    vlSelf->piptop__DOT__PRegExecute__DOT__rom_array[5U] 
        = __Vdlyvval__piptop__DOT__PRegExecute__DOT__rom_array__v5;
    vlSelf->piptop__DOT__PRegExecute__DOT__rom_array[6U] 
        = __Vdlyvval__piptop__DOT__PRegExecute__DOT__rom_array__v6;
    if (__Vdlyvset__piptop__DOT__DataMemory__DOT__memory__v0) {
        vlSelf->piptop__DOT__DataMemory__DOT__memory[__Vdlyvdim0__piptop__DOT__DataMemory__DOT__memory__v0] 
            = __Vdlyvval__piptop__DOT__DataMemory__DOT__memory__v0;
        vlSelf->piptop__DOT__DataMemory__DOT__memory[__Vdlyvdim0__piptop__DOT__DataMemory__DOT__memory__v1] 
            = __Vdlyvval__piptop__DOT__DataMemory__DOT__memory__v1;
        vlSelf->piptop__DOT__DataMemory__DOT__memory[__Vdlyvdim0__piptop__DOT__DataMemory__DOT__memory__v2] 
            = __Vdlyvval__piptop__DOT__DataMemory__DOT__memory__v2;
        vlSelf->piptop__DOT__DataMemory__DOT__memory[__Vdlyvdim0__piptop__DOT__DataMemory__DOT__memory__v3] 
            = __Vdlyvval__piptop__DOT__DataMemory__DOT__memory__v3;
    }
    if (__Vdlyvset__piptop__DOT__DataMemory__DOT__memory__v4) {
        vlSelf->piptop__DOT__DataMemory__DOT__memory[__Vdlyvdim0__piptop__DOT__DataMemory__DOT__memory__v4] 
            = __Vdlyvval__piptop__DOT__DataMemory__DOT__memory__v4;
        vlSelf->piptop__DOT__DataMemory__DOT__memory[__Vdlyvdim0__piptop__DOT__DataMemory__DOT__memory__v5] 
            = __Vdlyvval__piptop__DOT__DataMemory__DOT__memory__v5;
    }
    if (__Vdlyvset__piptop__DOT__DataMemory__DOT__memory__v6) {
        vlSelf->piptop__DOT__DataMemory__DOT__memory[__Vdlyvdim0__piptop__DOT__DataMemory__DOT__memory__v6] 
            = __Vdlyvval__piptop__DOT__DataMemory__DOT__memory__v6;
    }
    vlSelf->piptop__DOT__PRegFetch__DOT__rom_array[0U] 
        = __Vdlyvval__piptop__DOT__PRegFetch__DOT__rom_array__v0;
    vlSelf->piptop__DOT__PRegFetch__DOT__rom_array[1U] 
        = __Vdlyvval__piptop__DOT__PRegFetch__DOT__rom_array__v1;
    vlSelf->piptop__DOT__PRegFetch__DOT__rom_array[2U] 
        = __Vdlyvval__piptop__DOT__PRegFetch__DOT__rom_array__v2;
    vlSelf->piptop__DOT__srcB = ((1U & vlSelf->piptop__DOT__PRegDecode__DOT__rom_array
                                  [0xcU]) ? vlSelf->piptop__DOT__PRegDecode__DOT__rom_array
                                 [4U] : vlSelf->piptop__DOT__PRegDecode__DOT__rom_array
                                 [1U]);
    vlSelf->piptop__DOT__pc = ((0U == vlSelf->piptop__DOT__triggerFSM__DOT__current_state)
                                ? 0xbfc00000U : vlSelf->piptop__DOT__nextPC);
    vlSelf->piptop__DOT__triggerFSM__DOT__current_state 
        = ((IData)(vlSelf->rst) ? 0U : vlSelf->piptop__DOT__triggerFSM__DOT__next_state);
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

VL_INLINE_OPT void Vpiptop___024root___combo__TOP__0(Vpiptop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpiptop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpiptop___024root___combo__TOP__0\n"); );
    // Body
    if ((0U == vlSelf->piptop__DOT__triggerFSM__DOT__current_state)) {
        vlSelf->piptop__DOT__triggerFSM__DOT__next_state 
            = ((IData)(vlSelf->trigger) ? 1U : vlSelf->piptop__DOT__triggerFSM__DOT__current_state);
    } else if ((1U == vlSelf->piptop__DOT__triggerFSM__DOT__current_state)) {
        vlSelf->piptop__DOT__triggerFSM__DOT__next_state = 1U;
    }
}

void Vpiptop___024root___eval(Vpiptop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpiptop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpiptop___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vpiptop___024root___sequent__TOP__0(vlSelf);
    }
    Vpiptop___024root___combo__TOP__0(vlSelf);
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

#ifdef VL_DEBUG
void Vpiptop___024root___eval_debug_assertions(Vpiptop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpiptop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpiptop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->trigger & 0xfeU))) {
        Verilated::overWidthError("trigger");}
}
#endif  // VL_DEBUG
