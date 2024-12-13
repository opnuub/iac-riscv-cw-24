// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdut.h for the primary calling header

#include "Vdut__pch.h"
#include "Vdut___024root.h"

VL_ATTR_COLD void Vdut___024root___eval_static(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_static\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vdut___024root___eval_initial__TOP(Vdut___024root* vlSelf);

VL_ATTR_COLD void Vdut___024root___eval_initial(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_initial\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vdut___024root___eval_initial__TOP(vlSelf);
    vlSelfRef.__Vm_traceActivity[4U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst__0 = vlSelfRef.rst;
}

VL_ATTR_COLD void Vdut___024root___eval_initial__TOP(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_initial__TOP\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<5>/*159:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e686578U;
    __Vtemp_1[1U] = 0x6772616dU;
    __Vtemp_1[2U] = 0x2f70726fU;
    __Vtemp_1[3U] = 0x2f72746cU;
    __Vtemp_1[4U] = 0x2e2eU;
    VL_READMEM_N(true, 8, 4096, 0, VL_CVT_PACK_STR_NW(5, __Vtemp_1)
                 ,  &(vlSelfRef.top__DOT__instrMemory__DOT__rom)
                 , 0, ~0ULL);
    VL_READMEM_N(true, 8, 131072, 0, std::string{"data.hex"}
                 ,  &(vlSelfRef.top__DOT__MemoryController__DOT__main_memory)
                 , 0x10000U, ~0ULL);
}

VL_ATTR_COLD void Vdut___024root___eval_final(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_final\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdut___024root___dump_triggers__stl(Vdut___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vdut___024root___eval_phase__stl(Vdut___024root* vlSelf);

VL_ATTR_COLD void Vdut___024root___eval_settle(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_settle\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vdut___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("/Users/michaelli/Documents/GitHub/iac-riscv-cw-24/rtl/top.sv", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vdut___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdut___024root___dump_triggers__stl(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___dump_triggers__stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vdut___024root___stl_sequent__TOP__0(Vdut___024root* vlSelf);

VL_ATTR_COLD void Vdut___024root___eval_stl(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vdut___024root___stl_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
        vlSelfRef.__Vm_traceActivity[0U] = 1U;
    }
}

extern const VlUnpacked<CData/*0:0*/, 1024> Vdut__ConstPool__TABLE_hd4ac5ba3_0;
extern const VlUnpacked<CData/*0:0*/, 1024> Vdut__ConstPool__TABLE_hd0fa4f3e_0;
extern const VlUnpacked<CData/*0:0*/, 1024> Vdut__ConstPool__TABLE_hf71398c3_0;
extern const VlUnpacked<CData/*1:0*/, 1024> Vdut__ConstPool__TABLE_h64d436c7_0;
extern const VlUnpacked<CData/*1:0*/, 1024> Vdut__ConstPool__TABLE_h82129edf_0;
extern const VlUnpacked<CData/*0:0*/, 1024> Vdut__ConstPool__TABLE_hceb9c733_0;
extern const VlUnpacked<CData/*0:0*/, 1024> Vdut__ConstPool__TABLE_hec9e4992_0;
extern const VlUnpacked<CData/*0:0*/, 1024> Vdut__ConstPool__TABLE_h04deb1ff_0;
extern const VlUnpacked<CData/*1:0*/, 1024> Vdut__ConstPool__TABLE_h64afccad_0;
extern const VlUnpacked<CData/*2:0*/, 1024> Vdut__ConstPool__TABLE_h60a80785_0;
extern const VlUnpacked<CData/*3:0*/, 512> Vdut__ConstPool__TABLE_h37780e30_0;

VL_ATTR_COLD void Vdut___024root___stl_sequent__TOP__0(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___stl_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*9:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    SData/*8:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    // Body
    vlSelfRef.a0 = vlSelfRef.top__DOT__regfile__DOT__rom_array
        [0xaU];
    vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__way 
        = (1U & (vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__lru 
                 >> (0x1fU & (vlSelfRef.top__DOT__ALUResultM 
                              >> 2U))));
    if ((1U & (IData)((vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache
                       [(0x1fU & (vlSelfRef.top__DOT__ALUResultM 
                                  >> 2U))][0U] >> 0x3aU)))) {
        if ((1U & (~ (IData)((vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache
                              [(0x1fU & (vlSelfRef.top__DOT__ALUResultM 
                                         >> 2U))][1U] 
                              >> 0x3aU))))) {
            vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__way = 1U;
        }
    } else {
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__way = 0U;
    }
    vlSelfRef.top__DOT__MemoryController__DOT__l1_mem_write_data 
        = (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache
                  [(0x1fU & (vlSelfRef.top__DOT__ALUResultM 
                             >> 2U))][vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__way]);
    vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__way 
        = (1U & (IData)((vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__lru 
                         >> (0x3fU & (vlSelfRef.top__DOT__ALUResultM 
                                      >> 2U)))));
    if ((1U & (IData)((vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache
                       [(0x3fU & (vlSelfRef.top__DOT__ALUResultM 
                                  >> 2U))][0U] >> 0x39U)))) {
        if ((1U & (~ (IData)((vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache
                              [(0x3fU & (vlSelfRef.top__DOT__ALUResultM 
                                         >> 2U))][1U] 
                              >> 0x39U))))) {
            vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__way = 1U;
        }
    } else {
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__way = 0U;
    }
    vlSelfRef.top__DOT__MemoryController__DOT__l2_mem_write_data 
        = (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache
                  [(0x3fU & (vlSelfRef.top__DOT__ALUResultM 
                             >> 2U))][vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__way]);
    vlSelfRef.top__DOT__MemoryController__DOT__main_mem_data 
        = ((4U & (IData)(vlSelfRef.top__DOT__sizeSrcM))
            ? ((2U & (IData)(vlSelfRef.top__DOT__sizeSrcM))
                ? 0U : ((1U & (IData)(vlSelfRef.top__DOT__sizeSrcM))
                         ? ((vlSelfRef.top__DOT__MemoryController__DOT__main_memory
                             [(0x1ffffU & ((IData)(1U) 
                                           + vlSelfRef.top__DOT__ALUResultM))] 
                             << 8U) | vlSelfRef.top__DOT__MemoryController__DOT__main_memory
                            [(0x1ffffU & vlSelfRef.top__DOT__ALUResultM)])
                         : vlSelfRef.top__DOT__MemoryController__DOT__main_memory
                        [(0x1ffffU & vlSelfRef.top__DOT__ALUResultM)]))
            : ((2U & (IData)(vlSelfRef.top__DOT__sizeSrcM))
                ? ((1U & (IData)(vlSelfRef.top__DOT__sizeSrcM))
                    ? 0U : ((vlSelfRef.top__DOT__MemoryController__DOT__main_memory
                             [(0x1ffffU & ((IData)(3U) 
                                           + vlSelfRef.top__DOT__ALUResultM))] 
                             << 0x18U) | ((vlSelfRef.top__DOT__MemoryController__DOT__main_memory
                                           [(0x1ffffU 
                                             & ((IData)(2U) 
                                                + vlSelfRef.top__DOT__ALUResultM))] 
                                           << 0x10U) 
                                          | ((vlSelfRef.top__DOT__MemoryController__DOT__main_memory
                                              [(0x1ffffU 
                                                & ((IData)(1U) 
                                                   + vlSelfRef.top__DOT__ALUResultM))] 
                                              << 8U) 
                                             | vlSelfRef.top__DOT__MemoryController__DOT__main_memory
                                             [(0x1ffffU 
                                               & vlSelfRef.top__DOT__ALUResultM)]))))
                : ((1U & (IData)(vlSelfRef.top__DOT__sizeSrcM))
                    ? (((- (IData)((1U & (vlSelfRef.top__DOT__MemoryController__DOT__main_memory
                                          [(0x1ffffU 
                                            & ((IData)(1U) 
                                               + vlSelfRef.top__DOT__ALUResultM))] 
                                          >> 7U)))) 
                        << 0x10U) | ((vlSelfRef.top__DOT__MemoryController__DOT__main_memory
                                      [(0x1ffffU & 
                                        ((IData)(1U) 
                                         + vlSelfRef.top__DOT__ALUResultM))] 
                                      << 8U) | vlSelfRef.top__DOT__MemoryController__DOT__main_memory
                                     [(0x1ffffU & vlSelfRef.top__DOT__ALUResultM)]))
                    : (((- (IData)((1U & (vlSelfRef.top__DOT__MemoryController__DOT__main_memory
                                          [(0x1ffffU 
                                            & vlSelfRef.top__DOT__ALUResultM)] 
                                          >> 7U)))) 
                        << 8U) | vlSelfRef.top__DOT__MemoryController__DOT__main_memory
                       [(0x1ffffU & vlSelfRef.top__DOT__ALUResultM)]))));
    vlSelfRef.top__DOT__ForwardAE = 0U;
    if ((((IData)(vlSelfRef.top__DOT__RegWriteM) & 
          (0U != (IData)(vlSelfRef.top__DOT__RdM))) 
         & ((IData)(vlSelfRef.top__DOT__RdM) == (IData)(vlSelfRef.top__DOT__Rs1E)))) {
        vlSelfRef.top__DOT__ForwardAE = 2U;
    } else if ((((IData)(vlSelfRef.top__DOT__RegWriteW) 
                 & (0U != (IData)(vlSelfRef.top__DOT__RdW))) 
                & ((IData)(vlSelfRef.top__DOT__RdW) 
                   == (IData)(vlSelfRef.top__DOT__Rs1E)))) {
        vlSelfRef.top__DOT__ForwardAE = 1U;
    }
    __Vtableidx1 = ((0x380U & (vlSelfRef.top__DOT__instrD 
                               >> 5U)) | (0x7fU & vlSelfRef.top__DOT__instrD));
    vlSelfRef.top__DOT__RegWriteD = Vdut__ConstPool__TABLE_hd4ac5ba3_0
        [__Vtableidx1];
    vlSelfRef.top__DOT__MemWriteD = Vdut__ConstPool__TABLE_hd0fa4f3e_0
        [__Vtableidx1];
    vlSelfRef.top__DOT__ALUSrcD = Vdut__ConstPool__TABLE_hf71398c3_0
        [__Vtableidx1];
    vlSelfRef.top__DOT__immSrcD = Vdut__ConstPool__TABLE_h64d436c7_0
        [__Vtableidx1];
    vlSelfRef.top__DOT__ResultSrcD = Vdut__ConstPool__TABLE_h82129edf_0
        [__Vtableidx1];
    vlSelfRef.top__DOT__BranchD = Vdut__ConstPool__TABLE_hceb9c733_0
        [__Vtableidx1];
    vlSelfRef.top__DOT__JumpD = Vdut__ConstPool__TABLE_hec9e4992_0
        [__Vtableidx1];
    vlSelfRef.top__DOT__jalrSrc = Vdut__ConstPool__TABLE_h04deb1ff_0
        [__Vtableidx1];
    vlSelfRef.top__DOT__controlUnit__DOT__aluOp = Vdut__ConstPool__TABLE_h64afccad_0
        [__Vtableidx1];
    vlSelfRef.top__DOT__sizeSrcD = Vdut__ConstPool__TABLE_h60a80785_0
        [__Vtableidx1];
    vlSelfRef.top__DOT__ForwardBE = 0U;
    if ((((IData)(vlSelfRef.top__DOT__RegWriteM) & 
          (0U != (IData)(vlSelfRef.top__DOT__RdM))) 
         & ((IData)(vlSelfRef.top__DOT__RdM) == (IData)(vlSelfRef.top__DOT__Rs2E)))) {
        vlSelfRef.top__DOT__ForwardBE = 2U;
    } else if ((((IData)(vlSelfRef.top__DOT__RegWriteW) 
                 & (0U != (IData)(vlSelfRef.top__DOT__RdW))) 
                & ((IData)(vlSelfRef.top__DOT__RdW) 
                   == (IData)(vlSelfRef.top__DOT__Rs2E)))) {
        vlSelfRef.top__DOT__ForwardBE = 1U;
    }
    vlSelfRef.top__DOT__ResultW = ((0U == (IData)(vlSelfRef.top__DOT__ResultSrcW))
                                    ? vlSelfRef.top__DOT__ALUResultW
                                    : ((1U == (IData)(vlSelfRef.top__DOT__ResultSrcW))
                                        ? vlSelfRef.top__DOT__ReadDataW
                                        : ((2U == (IData)(vlSelfRef.top__DOT__ResultSrcW))
                                            ? vlSelfRef.top__DOT__PCPlus4W
                                            : 0U)));
    vlSelfRef.top__DOT__MemoryController__DOT__l2_hit = 0U;
    vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__hit_way = 0U;
    if (((IData)((vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache
                  [(0x3fU & (vlSelfRef.top__DOT__ALUResultM 
                             >> 2U))][0U] >> 0x39U)) 
         & ((0xffffffU & (IData)((vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache
                                  [(0x3fU & (vlSelfRef.top__DOT__ALUResultM 
                                             >> 2U))]
                                  [0U] >> 0x20U))) 
            == (0x1ffU & (vlSelfRef.top__DOT__ALUResultM 
                          >> 8U))))) {
        vlSelfRef.top__DOT__MemoryController__DOT__l2_hit = 1U;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__hit_way = 0U;
    } else if (((IData)((vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache
                         [(0x3fU & (vlSelfRef.top__DOT__ALUResultM 
                                    >> 2U))][1U] >> 0x39U)) 
                & ((0xffffffU & (IData)((vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache
                                         [(0x3fU & 
                                           (vlSelfRef.top__DOT__ALUResultM 
                                            >> 2U))]
                                         [1U] >> 0x20U))) 
                   == (0x1ffU & (vlSelfRef.top__DOT__ALUResultM 
                                 >> 8U))))) {
        vlSelfRef.top__DOT__MemoryController__DOT__l2_hit = 1U;
        vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__hit_way = 1U;
    }
    vlSelfRef.top__DOT__MemoryController__DOT__l2_miss 
        = ((~ (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l2_hit)) 
           & ((IData)(vlSelfRef.top__DOT__MemoryController__DOT__l1_mem_read) 
              | (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l1_mem_write)));
    vlSelfRef.top__DOT__MemoryController__DOT__l2_data_out 
        = ((IData)(vlSelfRef.top__DOT__MemoryController__DOT__l2_hit)
            ? (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__cache
                      [(0x3fU & (vlSelfRef.top__DOT__ALUResultM 
                                 >> 2U))][vlSelfRef.top__DOT__MemoryController__DOT__l2_cache__DOT__hit_way])
            : vlSelfRef.top__DOT__MemoryController__DOT__l3_data_out);
    vlSelfRef.top__DOT__MemoryController__DOT__mem_access 
        = ((IData)(vlSelfRef.top__DOT__MemWriteM) | 
           (7U != (IData)(vlSelfRef.top__DOT__sizeSrcM)));
    vlSelfRef.top__DOT__ImmExtD = ((2U & (IData)(vlSelfRef.top__DOT__immSrcD))
                                    ? ((1U & (IData)(vlSelfRef.top__DOT__immSrcD))
                                        ? ((IData)(vlSelfRef.top__DOT__JumpD)
                                            ? (((- (IData)(
                                                           (vlSelfRef.top__DOT__instrD 
                                                            >> 0x1fU))) 
                                                << 0x15U) 
                                               | ((0x100000U 
                                                   & (vlSelfRef.top__DOT__instrD 
                                                      >> 0xbU)) 
                                                  | ((0xff000U 
                                                      & vlSelfRef.top__DOT__instrD) 
                                                     | ((0x800U 
                                                         & (vlSelfRef.top__DOT__instrD 
                                                            >> 9U)) 
                                                        | (0x7feU 
                                                           & (vlSelfRef.top__DOT__instrD 
                                                              >> 0x14U))))))
                                            : (0xfffff000U 
                                               & vlSelfRef.top__DOT__instrD))
                                        : (((- (IData)(
                                                       (vlSelfRef.top__DOT__instrD 
                                                        >> 0x1fU))) 
                                            << 0xcU) 
                                           | ((0x800U 
                                               & (vlSelfRef.top__DOT__instrD 
                                                  << 4U)) 
                                              | ((0x7e0U 
                                                  & (vlSelfRef.top__DOT__instrD 
                                                     >> 0x14U)) 
                                                 | (0x1eU 
                                                    & (vlSelfRef.top__DOT__instrD 
                                                       >> 7U))))))
                                    : ((1U & (IData)(vlSelfRef.top__DOT__immSrcD))
                                        ? (((- (IData)(
                                                       (vlSelfRef.top__DOT__instrD 
                                                        >> 0x1fU))) 
                                            << 0xcU) 
                                           | ((0xfe0U 
                                               & (vlSelfRef.top__DOT__instrD 
                                                  >> 0x14U)) 
                                              | (0x1fU 
                                                 & (vlSelfRef.top__DOT__instrD 
                                                    >> 7U))))
                                        : (((- (IData)(
                                                       (vlSelfRef.top__DOT__instrD 
                                                        >> 0x1fU))) 
                                            << 0xcU) 
                                           | (vlSelfRef.top__DOT__instrD 
                                              >> 0x14U))));
    __Vtableidx2 = ((((3U == ((2U & (vlSelfRef.top__DOT__instrD 
                                     >> 4U)) | (1U 
                                                & (vlSelfRef.top__DOT__instrD 
                                                   >> 0x1eU))))
                       ? 1U : 0U) << 5U) | ((0x1cU 
                                             & (vlSelfRef.top__DOT__instrD 
                                                >> 0xaU)) 
                                            | (IData)(vlSelfRef.top__DOT__controlUnit__DOT__aluOp)));
    vlSelfRef.top__DOT__ALUControlD = Vdut__ConstPool__TABLE_h37780e30_0
        [__Vtableidx2];
    vlSelfRef.top__DOT__SrcAE = ((0U == (IData)(vlSelfRef.top__DOT__ForwardAE))
                                  ? vlSelfRef.top__DOT__rd1E
                                  : ((1U == (IData)(vlSelfRef.top__DOT__ForwardAE))
                                      ? vlSelfRef.top__DOT__ResultW
                                      : ((2U == (IData)(vlSelfRef.top__DOT__ForwardAE))
                                          ? vlSelfRef.top__DOT__ALUResultM
                                          : vlSelfRef.top__DOT__rd1E)));
    vlSelfRef.top__DOT__WriteDataE = ((0U == (IData)(vlSelfRef.top__DOT__ForwardBE))
                                       ? vlSelfRef.top__DOT__rd2E
                                       : ((1U == (IData)(vlSelfRef.top__DOT__ForwardBE))
                                           ? vlSelfRef.top__DOT__ResultW
                                           : ((2U == (IData)(vlSelfRef.top__DOT__ForwardBE))
                                               ? vlSelfRef.top__DOT__ALUResultM
                                               : vlSelfRef.top__DOT__rd2E)));
    vlSelfRef.top__DOT__MemoryController__DOT____Vcellinp__l1_cache__load 
        = ((~ (IData)(vlSelfRef.top__DOT__MemWriteM)) 
           & (IData)(vlSelfRef.top__DOT__MemoryController__DOT__mem_access));
    vlSelfRef.top__DOT__MemoryController__DOT____Vcellinp__l1_cache__store 
        = ((IData)(vlSelfRef.top__DOT__MemWriteM) & (IData)(vlSelfRef.top__DOT__MemoryController__DOT__mem_access));
    vlSelfRef.top__DOT__srcB = ((IData)(vlSelfRef.top__DOT__ALUSrcE)
                                 ? vlSelfRef.top__DOT__ImmExtE
                                 : vlSelfRef.top__DOT__WriteDataE);
    vlSelfRef.top__DOT__MemoryController__DOT__l1_hit = 0U;
    vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__hit_way = 0U;
    if (((IData)((vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache
                  [(0x1fU & (vlSelfRef.top__DOT__ALUResultM 
                             >> 2U))][0U] >> 0x3aU)) 
         & ((0x1ffffffU & (IData)((vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache
                                   [(0x1fU & (vlSelfRef.top__DOT__ALUResultM 
                                              >> 2U))]
                                   [0U] >> 0x20U))) 
            == (0x3ffU & (vlSelfRef.top__DOT__ALUResultM 
                          >> 7U))))) {
        vlSelfRef.top__DOT__MemoryController__DOT__l1_hit = 1U;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__hit_way = 0U;
    } else if (((IData)((vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache
                         [(0x1fU & (vlSelfRef.top__DOT__ALUResultM 
                                    >> 2U))][1U] >> 0x3aU)) 
                & ((0x1ffffffU & (IData)((vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache
                                          [(0x1fU & 
                                            (vlSelfRef.top__DOT__ALUResultM 
                                             >> 2U))]
                                          [1U] >> 0x20U))) 
                   == (0x3ffU & (vlSelfRef.top__DOT__ALUResultM 
                                 >> 7U))))) {
        vlSelfRef.top__DOT__MemoryController__DOT__l1_hit = 1U;
        vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__hit_way = 1U;
    }
    vlSelfRef.top__DOT__MemoryController__DOT__l1_miss 
        = ((~ (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l1_hit)) 
           & ((IData)(vlSelfRef.top__DOT__MemoryController__DOT____Vcellinp__l1_cache__load) 
              | (IData)(vlSelfRef.top__DOT__MemoryController__DOT____Vcellinp__l1_cache__store)));
    if (vlSelfRef.top__DOT__MemoryController__DOT__l1_hit) {
        vlSelfRef.top__DOT__MemoryController__DOT__l1_data_out 
            = (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__cache
                      [(0x1fU & (vlSelfRef.top__DOT__ALUResultM 
                                 >> 2U))][vlSelfRef.top__DOT__MemoryController__DOT__l1_cache__DOT__hit_way]);
        vlSelfRef.top__DOT__ReadData = vlSelfRef.top__DOT__MemoryController__DOT__l1_data_out;
    } else {
        vlSelfRef.top__DOT__MemoryController__DOT__l1_data_out 
            = vlSelfRef.top__DOT__MemoryController__DOT__l2_data_out;
        vlSelfRef.top__DOT__ReadData = ((IData)(vlSelfRef.top__DOT__MemoryController__DOT__l2_hit)
                                         ? vlSelfRef.top__DOT__MemoryController__DOT__l2_data_out
                                         : ((IData)(vlSelfRef.top__DOT__MemoryController__DOT__l3_hit)
                                             ? vlSelfRef.top__DOT__MemoryController__DOT__l3_data_out
                                             : vlSelfRef.top__DOT__MemoryController__DOT__main_mem_data));
    }
    if (((((((((0U == (IData)(vlSelfRef.top__DOT__ALUControlE)) 
               | (1U == (IData)(vlSelfRef.top__DOT__ALUControlE))) 
              | (2U == (IData)(vlSelfRef.top__DOT__ALUControlE))) 
             | (3U == (IData)(vlSelfRef.top__DOT__ALUControlE))) 
            | (4U == (IData)(vlSelfRef.top__DOT__ALUControlE))) 
           | (5U == (IData)(vlSelfRef.top__DOT__ALUControlE))) 
          | (6U == (IData)(vlSelfRef.top__DOT__ALUControlE))) 
         | (7U == (IData)(vlSelfRef.top__DOT__ALUControlE)))) {
        vlSelfRef.top__DOT__aluResult = ((0U == (IData)(vlSelfRef.top__DOT__ALUControlE))
                                          ? (vlSelfRef.top__DOT__SrcAE 
                                             + vlSelfRef.top__DOT__srcB)
                                          : ((1U == (IData)(vlSelfRef.top__DOT__ALUControlE))
                                              ? (vlSelfRef.top__DOT__SrcAE 
                                                 - vlSelfRef.top__DOT__srcB)
                                              : ((2U 
                                                  == (IData)(vlSelfRef.top__DOT__ALUControlE))
                                                  ? 
                                                 (vlSelfRef.top__DOT__SrcAE 
                                                  & vlSelfRef.top__DOT__srcB)
                                                  : 
                                                 ((3U 
                                                   == (IData)(vlSelfRef.top__DOT__ALUControlE))
                                                   ? 
                                                  (vlSelfRef.top__DOT__SrcAE 
                                                   | vlSelfRef.top__DOT__srcB)
                                                   : 
                                                  ((4U 
                                                    == (IData)(vlSelfRef.top__DOT__ALUControlE))
                                                    ? vlSelfRef.top__DOT__srcB
                                                    : 
                                                   ((5U 
                                                     == (IData)(vlSelfRef.top__DOT__ALUControlE))
                                                     ? 
                                                    (VL_LTS_III(32, vlSelfRef.top__DOT__SrcAE, vlSelfRef.top__DOT__srcB)
                                                      ? 1U
                                                      : 0U)
                                                     : 
                                                    ((6U 
                                                      == (IData)(vlSelfRef.top__DOT__ALUControlE))
                                                      ? 
                                                     (vlSelfRef.top__DOT__SrcAE 
                                                      << 
                                                      (0x1fU 
                                                       & vlSelfRef.top__DOT__srcB))
                                                      : 
                                                     (vlSelfRef.top__DOT__SrcAE 
                                                      >> 
                                                      (0x1fU 
                                                       & vlSelfRef.top__DOT__srcB)))))))));
    }
    vlSelfRef.top__DOT__zero = ((1U & ((IData)(vlSelfRef.top__DOT__ALUControlE) 
                                       >> 3U)) && (
                                                   (4U 
                                                    & (IData)(vlSelfRef.top__DOT__ALUControlE))
                                                    ? 
                                                   ((2U 
                                                     & (IData)(vlSelfRef.top__DOT__ALUControlE))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlSelfRef.top__DOT__ALUControlE))
                                                      ? 
                                                     (vlSelfRef.top__DOT__SrcAE 
                                                      >= vlSelfRef.top__DOT__srcB)
                                                      : 
                                                     (vlSelfRef.top__DOT__SrcAE 
                                                      < vlSelfRef.top__DOT__srcB))
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlSelfRef.top__DOT__ALUControlE))
                                                      ? 
                                                     VL_GTES_III(32, vlSelfRef.top__DOT__SrcAE, vlSelfRef.top__DOT__srcB)
                                                      : 
                                                     VL_LTS_III(32, vlSelfRef.top__DOT__SrcAE, vlSelfRef.top__DOT__srcB)))
                                                    : 
                                                   ((1U 
                                                     & (~ 
                                                        ((IData)(vlSelfRef.top__DOT__ALUControlE) 
                                                         >> 1U))) 
                                                    && ((1U 
                                                         & (IData)(vlSelfRef.top__DOT__ALUControlE))
                                                         ? 
                                                        (0U 
                                                         != 
                                                         (vlSelfRef.top__DOT__SrcAE 
                                                          - vlSelfRef.top__DOT__srcB))
                                                         : 
                                                        (0U 
                                                         == 
                                                         (vlSelfRef.top__DOT__SrcAE 
                                                          - vlSelfRef.top__DOT__srcB))))));
    vlSelfRef.top__DOT__MemReady = ((IData)(vlSelfRef.top__DOT__MemoryController__DOT__l1_hit) 
                                    || ((IData)(vlSelfRef.top__DOT__MemoryController__DOT__l2_hit) 
                                        || ((IData)(vlSelfRef.top__DOT__MemoryController__DOT__l3_hit) 
                                            || ((((IData)(vlSelfRef.top__DOT__MemoryController__DOT__main_mem_ready_reg) 
                                                  & (~ (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l1_busy))) 
                                                 & (~ (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l2_busy))) 
                                                & (~ (IData)(vlSelfRef.top__DOT__MemoryController__DOT__l3_busy))))));
    vlSelfRef.top__DOT__nextPC = (((IData)(vlSelfRef.top__DOT__JumpE) 
                                   | ((IData)(vlSelfRef.top__DOT__BranchE) 
                                      & (IData)(vlSelfRef.top__DOT__zero)))
                                   ? (((IData)(vlSelfRef.top__DOT__JalrE)
                                        ? vlSelfRef.top__DOT__rd1E
                                        : vlSelfRef.top__DOT__PCe) 
                                      + vlSelfRef.top__DOT__ImmExtE)
                                   : ((IData)(4U) + vlSelfRef.top__DOT__pc));
    vlSelfRef.top__DOT__stall = 0U;
    vlSelfRef.top__DOT__FlushD = 0U;
    vlSelfRef.top__DOT__FlushE = 0U;
    vlSelfRef.top__DOT__HazardUnit__DOT__load_use_hazard 
        = ((1U == (IData)(vlSelfRef.top__DOT__ResultSrcE)) 
           & ((((IData)(vlSelfRef.top__DOT__RdE) == 
                (0x1fU & (vlSelfRef.top__DOT__instrD 
                          >> 0xfU))) & (0U != (0x1fU 
                                               & (vlSelfRef.top__DOT__instrD 
                                                  >> 0xfU)))) 
              | (((IData)(vlSelfRef.top__DOT__RdE) 
                  == (0x1fU & (vlSelfRef.top__DOT__instrD 
                               >> 0x14U))) & (0U != 
                                              (0x1fU 
                                               & (vlSelfRef.top__DOT__instrD 
                                                  >> 0x14U))))));
    vlSelfRef.top__DOT__HazardUnit__DOT__control_hazard 
        = ((IData)(vlSelfRef.top__DOT__zero) | (IData)(vlSelfRef.top__DOT__JumpE));
    if (vlSelfRef.top__DOT__HazardUnit__DOT__load_use_hazard) {
        vlSelfRef.top__DOT__stall = 1U;
        vlSelfRef.top__DOT__FlushE = 1U;
        vlSelfRef.top__DOT__FlushD = 0U;
    } else if (vlSelfRef.top__DOT__HazardUnit__DOT__control_hazard) {
        vlSelfRef.top__DOT__stall = 0U;
        vlSelfRef.top__DOT__FlushD = 1U;
        vlSelfRef.top__DOT__FlushE = 1U;
    } else if (vlSelfRef.top__DOT__MemReady) {
        vlSelfRef.top__DOT__stall = 0U;
        vlSelfRef.top__DOT__FlushD = 0U;
        vlSelfRef.top__DOT__FlushE = 0U;
    } else {
        vlSelfRef.top__DOT__stall = 1U;
        vlSelfRef.top__DOT__FlushE = 1U;
        vlSelfRef.top__DOT__FlushD = 0U;
    }
}

VL_ATTR_COLD void Vdut___024root___eval_triggers__stl(Vdut___024root* vlSelf);

VL_ATTR_COLD bool Vdut___024root___eval_phase__stl(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_phase__stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vdut___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vdut___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdut___024root___dump_triggers__act(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___dump_triggers__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk or posedge rst)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge clk)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdut___024root___dump_triggers__nba(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___dump_triggers__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk or posedge rst)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge clk)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vdut___024root___ctor_var_reset(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___ctor_var_reset\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
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
    vlSelf->top__DOT__FlushD = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__FlushE = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__stall = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ForwardAE = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__ForwardBE = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__SrcAE = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__WriteDataE = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__Rs1E = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__Rs2E = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__jalrSrc = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__zero = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__JalrE = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__MemReady = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__HazardUnit__DOT__load_use_hazard = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__HazardUnit__DOT__control_hazard = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->top__DOT__instrMemory__DOT__rom[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->top__DOT__controlUnit__DOT__aluOp = VL_RAND_RESET_I(2);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__regfile__DOT__rom_array[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->top__DOT__MemoryController__DOT__s0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__MemoryController__DOT__l1_hit = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__MemoryController__DOT__l1_miss = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__MemoryController__DOT__l1_mem_write = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__MemoryController__DOT__l1_mem_read = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__MemoryController__DOT__l1_busy = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__MemoryController__DOT__l1_data_out = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__MemoryController__DOT__l1_mem_write_data = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__MemoryController__DOT__l2_hit = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__MemoryController__DOT__l2_miss = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__MemoryController__DOT__l2_mem_write = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__MemoryController__DOT__l2_mem_read = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__MemoryController__DOT__l2_busy = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__MemoryController__DOT__l2_data_out = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__MemoryController__DOT__l2_mem_write_data = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__MemoryController__DOT__l3_hit = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__MemoryController__DOT__l3_busy = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__MemoryController__DOT__l3_data_out = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__MemoryController__DOT__main_mem_data = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__MemoryController__DOT__main_mem_ready_reg = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__MemoryController__DOT__mem_access = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__MemoryController__DOT____Vcellinp__l1_cache__store = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__MemoryController__DOT____Vcellinp__l1_cache__load = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 131072; ++__Vi0) {
        vlSelf->top__DOT__MemoryController__DOT__main_memory[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->top__DOT__MemoryController__DOT__l1_cache__DOT__state = VL_RAND_RESET_I(3);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 2; ++__Vi1) {
            vlSelf->top__DOT__MemoryController__DOT__l1_cache__DOT__cache[__Vi0][__Vi1] = VL_RAND_RESET_Q(59);
        }
    }
    vlSelf->top__DOT__MemoryController__DOT__l1_cache__DOT__lru = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__MemoryController__DOT__l1_cache__DOT__way = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__MemoryController__DOT__l1_cache__DOT__hit_way = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__MemoryController__DOT__l1_cache__DOT__unnamedblk1__DOT__i = 0;
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 2; ++__Vi1) {
            vlSelf->top__DOT__MemoryController__DOT__l2_cache__DOT__cache[__Vi0][__Vi1] = VL_RAND_RESET_Q(58);
        }
    }
    vlSelf->top__DOT__MemoryController__DOT__l2_cache__DOT__lru = VL_RAND_RESET_Q(64);
    vlSelf->top__DOT__MemoryController__DOT__l2_cache__DOT__hit_way = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__MemoryController__DOT__l2_cache__DOT__way = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__MemoryController__DOT__l2_cache__DOT__state = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__MemoryController__DOT__l2_cache__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->top__DOT__MemoryController__DOT__l3_cache__DOT__stall = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__MemoryController__DOT__l3_cache__DOT__mem_read = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__MemoryController__DOT__l3_cache__DOT__mem_write = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__MemoryController__DOT__l3_cache__DOT__mem_address = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__MemoryController__DOT__l3_cache__DOT__mem_write_data = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__MemoryController__DOT__l3_cache__DOT__mem_read_data = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__MemoryController__DOT__l3_cache__DOT__mem_ready = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        VL_RAND_RESET_W(528, vlSelf->top__DOT__MemoryController__DOT__l3_cache__DOT__cache[__Vi0]);
    }
    vlSelf->top__DOT__MemoryController__DOT__l3_cache__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__MemoryController__DOT__l3_cache__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->__Vdly__top__DOT__MemoryController__DOT__l3_cache__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->__Vdly__top__DOT__MemoryController__DOT__l3_data_out = VL_RAND_RESET_I(32);
    vlSelf->__VdlyVal__top__DOT__regfile__DOT__rom_array__v0 = VL_RAND_RESET_I(32);
    vlSelf->__VdlyDim0__top__DOT__regfile__DOT__rom_array__v0 = VL_RAND_RESET_I(5);
    vlSelf->__Vdly__top__DOT__MemoryController__DOT__l3_busy = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__top__DOT__MemoryController__DOT__l1_cache__DOT__state = VL_RAND_RESET_I(3);
    vlSelf->__Vdly__top__DOT__MemoryController__DOT__l2_cache__DOT__state = VL_RAND_RESET_I(3);
    vlSelf->__Vdly__top__DOT__MemoryController__DOT__l2_busy = VL_RAND_RESET_I(1);
    vlSelf->__VdlySet__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v0 = 0;
    vlSelf->__VdlySet__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v1 = 0;
    vlSelf->__VdlySet__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v2 = 0;
    vlSelf->__VdlySet__top__DOT__MemoryController__DOT__l3_cache__DOT__cache__v3 = 0;
    vlSelf->__VdlySet__top__DOT__regfile__DOT__rom_array__v0 = 0;
    vlSelf->__VdlySet__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v0 = 0;
    vlSelf->__VdlySet__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v64 = 0;
    vlSelf->__VdlySet__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v65 = 0;
    vlSelf->__VdlySet__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v68 = 0;
    vlSelf->__VdlySet__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v69 = 0;
    vlSelf->__VdlySet__top__DOT__MemoryController__DOT__l1_cache__DOT__cache__v70 = 0;
    vlSelf->__VdlySet__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v0 = 0;
    vlSelf->__VdlySet__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v128 = 0;
    vlSelf->__VdlySet__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v129 = 0;
    vlSelf->__VdlySet__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v130 = 0;
    vlSelf->__VdlySet__top__DOT__MemoryController__DOT__l2_cache__DOT__cache__v131 = 0;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
