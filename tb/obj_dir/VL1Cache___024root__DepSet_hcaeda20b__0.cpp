// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VL1Cache.h for the primary calling header

#include "VL1Cache__pch.h"
#include "VL1Cache___024root.h"

void VL1Cache___024root___eval_act(VL1Cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VL1Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL1Cache___024root___eval_act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

void VL1Cache___024root___nba_sequent__TOP__0(VL1Cache___024root* vlSelf);

void VL1Cache___024root___eval_nba(VL1Cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VL1Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL1Cache___024root___eval_nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL1Cache___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

VL_INLINE_OPT void VL1Cache___024root___nba_sequent__TOP__0(VL1Cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VL1Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL1Cache___024root___nba_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlUnpacked<VL1Cache_L1Cache__DOT__CacheLine__struct__0, 256> __Vdly__L1Cache__DOT__cache;
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        __Vdly__L1Cache__DOT__cache[__Vi0].__PVT__tag = 0;
        VL_ZERO_W(128, __Vdly__L1Cache__DOT__cache[__Vi0].__PVT__data);
        __Vdly__L1Cache__DOT__cache[__Vi0].__PVT__valid = 0;
    }
    // Body
    __Vdly__L1Cache__DOT__cache = vlSelfRef.L1Cache__DOT__cache;
    if (vlSelfRef.reset) {
        vlSelfRef.L1Cache__DOT__unnamedblk1__DOT__i = 0U;
        while (VL_GTS_III(32, 0x100U, vlSelfRef.L1Cache__DOT__unnamedblk1__DOT__i)) {
            __Vdly__L1Cache__DOT__cache[(0xffU & vlSelfRef.L1Cache__DOT__unnamedblk1__DOT__i)].__PVT__valid = 0U;
            vlSelfRef.L1Cache__DOT__unnamedblk1__DOT__i 
                = ((IData)(1U) + vlSelfRef.L1Cache__DOT__unnamedblk1__DOT__i);
        }
        vlSelfRef.hit = 0U;
    } else {
        if ((vlSelfRef.L1Cache__DOT__cache[vlSelfRef.L1Cache__DOT__index]
             .__PVT__valid & (vlSelfRef.L1Cache__DOT__cache
                              [vlSelfRef.L1Cache__DOT__index]
                              .__PVT__tag == (vlSelfRef.address 
                                              >> 0xcU)))) {
            vlSelfRef.hit = 1U;
            vlSelfRef.readData = (((0U == (0x1fU & 
                                           VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.L1Cache__DOT__offset), 5U)))
                                    ? 0U : (vlSelfRef.L1Cache__DOT__cache
                                            [vlSelfRef.L1Cache__DOT__index]
                                            .__PVT__data[
                                            (((IData)(0x1fU) 
                                              + (0x7fU 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.L1Cache__DOT__offset), 5U))) 
                                             >> 5U)] 
                                            << ((IData)(0x20U) 
                                                - (0x1fU 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.L1Cache__DOT__offset), 5U))))) 
                                  | (vlSelfRef.L1Cache__DOT__cache
                                     [vlSelfRef.L1Cache__DOT__index]
                                     .__PVT__data[(3U 
                                                   & (VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.L1Cache__DOT__offset), 5U) 
                                                      >> 5U))] 
                                     >> (0x1fU & VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.L1Cache__DOT__offset), 5U))));
        } else {
            vlSelfRef.hit = 0U;
            __Vdly__L1Cache__DOT__cache[vlSelfRef.L1Cache__DOT__index].__PVT__tag 
                = (vlSelfRef.address >> 0xcU);
            VL_ASSIGNSEL_WI(128,32,(0x7fU & VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.L1Cache__DOT__offset), 5U)), 
                            __Vdly__L1Cache__DOT__cache
                            [vlSelfRef.L1Cache__DOT__index]
                            .__PVT__data, vlSelfRef.writeData);
            __Vdly__L1Cache__DOT__cache[vlSelfRef.L1Cache__DOT__index].__PVT__valid = 1U;
        }
        if (vlSelfRef.writeEnable) {
            VL_ASSIGNSEL_WI(128,32,(0x7fU & VL_SHIFTL_III(7,32,32, (IData)(vlSelfRef.L1Cache__DOT__offset), 5U)), 
                            __Vdly__L1Cache__DOT__cache
                            [vlSelfRef.L1Cache__DOT__index]
                            .__PVT__data, vlSelfRef.writeData);
        }
    }
    vlSelfRef.L1Cache__DOT__cache = __Vdly__L1Cache__DOT__cache;
    if ((1U & (~ (IData)(vlSelfRef.reset)))) {
        vlSelfRef.L1Cache__DOT__index = (0xffU & (vlSelfRef.address 
                                                  >> 2U));
        vlSelfRef.L1Cache__DOT__offset = (3U & vlSelfRef.address);
    }
}

void VL1Cache___024root___eval_triggers__act(VL1Cache___024root* vlSelf);

bool VL1Cache___024root___eval_phase__act(VL1Cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VL1Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL1Cache___024root___eval_phase__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VL1Cache___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        VL1Cache___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VL1Cache___024root___eval_phase__nba(VL1Cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VL1Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL1Cache___024root___eval_phase__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        VL1Cache___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VL1Cache___024root___dump_triggers__nba(VL1Cache___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VL1Cache___024root___dump_triggers__act(VL1Cache___024root* vlSelf);
#endif  // VL_DEBUG

void VL1Cache___024root___eval(VL1Cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VL1Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL1Cache___024root___eval\n"); );
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
            VL1Cache___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/Users/michaelli/Documents/GitHub/iac-riscv-cw-24/rtl/L1Cache.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                VL1Cache___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/Users/michaelli/Documents/GitHub/iac-riscv-cw-24/rtl/L1Cache.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (VL1Cache___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (VL1Cache___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VL1Cache___024root___eval_debug_assertions(VL1Cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VL1Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL1Cache___024root___eval_debug_assertions\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelfRef.reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((vlSelfRef.writeEnable & 0xfeU))) {
        Verilated::overWidthError("writeEnable");}
}
#endif  // VL_DEBUG

std::string VL_TO_STRING(const VL1Cache_L1Cache__DOT__CacheLine__struct__0& obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VL1Cache___024root::VL_TO_STRING\n"); );
    // Body
    std::string out;
    out += "'{tag:" + VL_TO_STRING(obj.__PVT__tag);
        out += ", data:" + VL_TO_STRING(obj.__PVT__data);
        out += ", valid:" + VL_TO_STRING(obj.__PVT__valid);
        out += "}";
    return out;
}
