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
    vlSelfRef.__Vtrigprevexpr___TOP__clk_i__0 = vlSelfRef.clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_ni__0 = vlSelfRef.rst_ni;
}

extern const VlWide<22>/*703:0*/ Vdut__ConstPool__CONST_hbbe01394_0;

VL_ATTR_COLD void Vdut___024root___eval_initial__TOP(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_initial__TOP\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_WRITEF_NX("Loading program into instruction memory...\n",0);
    VL_READMEM_N(true, 8, 4096, 0, VL_CVT_PACK_STR_NW(22, Vdut__ConstPool__CONST_hbbe01394_0)
                 ,  &(vlSelfRef.top__DOT__imem__DOT__mem)
                 , 0, ~0ULL);
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
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
        vlSelfRef.__Vm_traceActivity[0U] = 1U;
    }
}

extern const VlUnpacked<CData/*0:0*/, 512> Vdut__ConstPool__TABLE_h4a44e999_0;

VL_ATTR_COLD void Vdut___024root___stl_sequent__TOP__0(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___stl_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*8:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelfRef.top__DOT__rf_wen = 0U;
    vlSelfRef.top__DOT__controller__DOT__imm_type_o = 0U;
    vlSelfRef.top__DOT__mem_wen = 0U;
    vlSelfRef.top__DOT__illegal_instr = 0U;
    vlSelfRef.top__DOT__rf_wdata_sel = 0U;
    vlSelfRef.a0_o = vlSelfRef.top__DOT__regfile__DOT__rf_reg
        [0xaU];
    vlSelfRef.top__DOT__mem_signed = 1U;
    vlSelfRef.top__DOT__mem_size = (7U & (vlSelfRef.top__DOT__instr 
                                          >> 0xcU));
    vlSelfRef.top__DOT__alu_op = 0U;
    vlSelfRef.top__DOT__alu_src1_sel = 0U;
    if ((1U & (~ (vlSelfRef.top__DOT__instr >> 6U)))) {
        if ((0x20U & vlSelfRef.top__DOT__instr)) {
            if ((1U & (~ (vlSelfRef.top__DOT__instr 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.top__DOT__instr 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.top__DOT__instr 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.top__DOT__instr)) {
                            if ((1U & vlSelfRef.top__DOT__instr)) {
                                vlSelfRef.top__DOT__mem_wen = 1U;
                                if ((((0U == (7U & 
                                              (vlSelfRef.top__DOT__instr 
                                               >> 0xcU))) 
                                      || (1U == (7U 
                                                 & (vlSelfRef.top__DOT__instr 
                                                    >> 0xcU)))) 
                                     || (2U == (7U 
                                                & (vlSelfRef.top__DOT__instr 
                                                   >> 0xcU))))) {
                                    vlSelfRef.top__DOT__mem_size 
                                        = (7U & (vlSelfRef.top__DOT__instr 
                                                 >> 0xcU));
                                }
                            }
                        }
                    }
                }
            }
            if ((0x10U & vlSelfRef.top__DOT__instr)) {
                if ((1U & (~ (vlSelfRef.top__DOT__instr 
                              >> 3U)))) {
                    if ((4U & vlSelfRef.top__DOT__instr)) {
                        if ((2U & vlSelfRef.top__DOT__instr)) {
                            if ((1U & vlSelfRef.top__DOT__instr)) {
                                vlSelfRef.top__DOT__alu_op = 0xaU;
                            }
                        }
                    } else if ((2U & vlSelfRef.top__DOT__instr)) {
                        if ((1U & vlSelfRef.top__DOT__instr)) {
                            vlSelfRef.top__DOT__alu_op 
                                = ((0x4000U & vlSelfRef.top__DOT__instr)
                                    ? ((0x2000U & vlSelfRef.top__DOT__instr)
                                        ? ((0x1000U 
                                            & vlSelfRef.top__DOT__instr)
                                            ? 9U : 8U)
                                        : ((0x1000U 
                                            & vlSelfRef.top__DOT__instr)
                                            ? ((0x40000000U 
                                                & vlSelfRef.top__DOT__instr)
                                                ? 7U
                                                : 6U)
                                            : 5U)) : 
                                   ((0x2000U & vlSelfRef.top__DOT__instr)
                                     ? ((0x1000U & vlSelfRef.top__DOT__instr)
                                         ? 4U : 3U)
                                     : ((0x1000U & vlSelfRef.top__DOT__instr)
                                         ? 2U : ((0x40000000U 
                                                  & vlSelfRef.top__DOT__instr)
                                                  ? 1U
                                                  : 0U))));
                        }
                    }
                }
            }
        } else {
            if ((1U & (~ (vlSelfRef.top__DOT__instr 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.top__DOT__instr 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.top__DOT__instr 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.top__DOT__instr)) {
                            if ((1U & vlSelfRef.top__DOT__instr)) {
                                if ((0x4000U & vlSelfRef.top__DOT__instr)) {
                                    if ((1U & (~ (vlSelfRef.top__DOT__instr 
                                                  >> 0xdU)))) {
                                        vlSelfRef.top__DOT__mem_size 
                                            = (7U & 
                                               (vlSelfRef.top__DOT__instr 
                                                >> 0xcU));
                                    }
                                } else if ((0x2000U 
                                            & vlSelfRef.top__DOT__instr)) {
                                    if ((1U & (~ (vlSelfRef.top__DOT__instr 
                                                  >> 0xcU)))) {
                                        vlSelfRef.top__DOT__mem_size 
                                            = (7U & 
                                               (vlSelfRef.top__DOT__instr 
                                                >> 0xcU));
                                    }
                                } else {
                                    vlSelfRef.top__DOT__mem_size 
                                        = (7U & (vlSelfRef.top__DOT__instr 
                                                 >> 0xcU));
                                }
                            }
                        }
                    }
                }
            }
            if ((0x10U & vlSelfRef.top__DOT__instr)) {
                if ((1U & (~ (vlSelfRef.top__DOT__instr 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.top__DOT__instr 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.top__DOT__instr)) {
                            if ((1U & vlSelfRef.top__DOT__instr)) {
                                vlSelfRef.top__DOT__alu_op 
                                    = ((0x4000U & vlSelfRef.top__DOT__instr)
                                        ? ((0x2000U 
                                            & vlSelfRef.top__DOT__instr)
                                            ? ((0x1000U 
                                                & vlSelfRef.top__DOT__instr)
                                                ? 9U
                                                : 8U)
                                            : ((0x1000U 
                                                & vlSelfRef.top__DOT__instr)
                                                ? (
                                                   (0x40000000U 
                                                    & vlSelfRef.top__DOT__instr)
                                                    ? 7U
                                                    : 6U)
                                                : 5U))
                                        : ((0x2000U 
                                            & vlSelfRef.top__DOT__instr)
                                            ? ((0x1000U 
                                                & vlSelfRef.top__DOT__instr)
                                                ? 4U
                                                : 3U)
                                            : ((0x1000U 
                                                & vlSelfRef.top__DOT__instr)
                                                ? 2U
                                                : 0U)));
                            }
                        }
                    }
                }
            }
        }
        if ((1U & (~ (vlSelfRef.top__DOT__instr >> 5U)))) {
            if ((1U & (~ (vlSelfRef.top__DOT__instr 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.top__DOT__instr 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.top__DOT__instr 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.top__DOT__instr)) {
                            if ((1U & vlSelfRef.top__DOT__instr)) {
                                vlSelfRef.top__DOT__mem_signed 
                                    = (1U & (~ (vlSelfRef.top__DOT__instr 
                                                >> 0xeU)));
                            }
                        }
                    }
                }
            }
            if ((0x10U & vlSelfRef.top__DOT__instr)) {
                if ((1U & (~ (vlSelfRef.top__DOT__instr 
                              >> 3U)))) {
                    if ((4U & vlSelfRef.top__DOT__instr)) {
                        if ((2U & vlSelfRef.top__DOT__instr)) {
                            if ((1U & vlSelfRef.top__DOT__instr)) {
                                vlSelfRef.top__DOT__alu_src1_sel = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlSelfRef.top__DOT__alu_src2_sel = 0U;
    vlSelfRef.top__DOT__rs1_data = ((0U == (0x1fU & 
                                            (vlSelfRef.top__DOT__instr 
                                             >> 0xfU)))
                                     ? 0U : vlSelfRef.top__DOT__regfile__DOT__rf_reg
                                    [(0x1fU & (vlSelfRef.top__DOT__instr 
                                               >> 0xfU))]);
    vlSelfRef.top__DOT__rs2_data = ((0U == (0x1fU & 
                                            (vlSelfRef.top__DOT__instr 
                                             >> 0x14U)))
                                     ? 0U : vlSelfRef.top__DOT__regfile__DOT__rf_reg
                                    [(0x1fU & (vlSelfRef.top__DOT__instr 
                                               >> 0x14U))]);
    if ((0x40U & vlSelfRef.top__DOT__instr)) {
        if ((0x20U & vlSelfRef.top__DOT__instr)) {
            if ((1U & (~ (vlSelfRef.top__DOT__instr 
                          >> 4U)))) {
                if ((8U & vlSelfRef.top__DOT__instr)) {
                    if ((4U & vlSelfRef.top__DOT__instr)) {
                        if ((2U & vlSelfRef.top__DOT__instr)) {
                            if ((1U & vlSelfRef.top__DOT__instr)) {
                                vlSelfRef.top__DOT__rf_wen = 1U;
                                vlSelfRef.top__DOT__controller__DOT__imm_type_o = 4U;
                                vlSelfRef.top__DOT__rf_wdata_sel = 2U;
                            }
                        }
                    }
                } else if ((4U & vlSelfRef.top__DOT__instr)) {
                    if ((2U & vlSelfRef.top__DOT__instr)) {
                        if ((1U & vlSelfRef.top__DOT__instr)) {
                            vlSelfRef.top__DOT__rf_wen = 1U;
                            vlSelfRef.top__DOT__controller__DOT__imm_type_o = 0U;
                            vlSelfRef.top__DOT__rf_wdata_sel = 2U;
                        }
                    }
                } else if ((2U & vlSelfRef.top__DOT__instr)) {
                    if ((1U & vlSelfRef.top__DOT__instr)) {
                        vlSelfRef.top__DOT__controller__DOT__imm_type_o = 2U;
                    }
                }
                if ((1U & (~ (vlSelfRef.top__DOT__instr 
                              >> 3U)))) {
                    if ((4U & vlSelfRef.top__DOT__instr)) {
                        if ((2U & vlSelfRef.top__DOT__instr)) {
                            if ((1U & vlSelfRef.top__DOT__instr)) {
                                vlSelfRef.top__DOT__alu_src2_sel = 1U;
                            }
                        }
                    }
                }
            }
            if ((0x10U & vlSelfRef.top__DOT__instr)) {
                vlSelfRef.top__DOT__illegal_instr = 1U;
                vlSelfRef.top__DOT__imm = 0U;
            } else if ((8U & vlSelfRef.top__DOT__instr)) {
                if ((4U & vlSelfRef.top__DOT__instr)) {
                    if ((2U & vlSelfRef.top__DOT__instr)) {
                        if ((1U & (~ vlSelfRef.top__DOT__instr))) {
                            vlSelfRef.top__DOT__illegal_instr = 1U;
                        }
                        vlSelfRef.top__DOT__imm = (
                                                   (1U 
                                                    & vlSelfRef.top__DOT__instr)
                                                    ? 
                                                   (((- (IData)(
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
                                                    : 0U);
                    } else {
                        vlSelfRef.top__DOT__illegal_instr = 1U;
                        vlSelfRef.top__DOT__imm = 0U;
                    }
                } else {
                    vlSelfRef.top__DOT__illegal_instr = 1U;
                    vlSelfRef.top__DOT__imm = 0U;
                }
            } else if ((4U & vlSelfRef.top__DOT__instr)) {
                if ((2U & vlSelfRef.top__DOT__instr)) {
                    if ((1U & (~ vlSelfRef.top__DOT__instr))) {
                        vlSelfRef.top__DOT__illegal_instr = 1U;
                    }
                    vlSelfRef.top__DOT__imm = ((1U 
                                                & vlSelfRef.top__DOT__instr)
                                                ? (
                                                   ((- (IData)(
                                                               (vlSelfRef.top__DOT__instr 
                                                                >> 0x1fU))) 
                                                    << 0xcU) 
                                                   | (vlSelfRef.top__DOT__instr 
                                                      >> 0x14U))
                                                : 0U);
                } else {
                    vlSelfRef.top__DOT__illegal_instr = 1U;
                    vlSelfRef.top__DOT__imm = 0U;
                }
            } else if ((2U & vlSelfRef.top__DOT__instr)) {
                if ((1U & vlSelfRef.top__DOT__instr)) {
                    if ((1U & (~ (vlSelfRef.top__DOT__instr 
                                  >> 0xeU)))) {
                        if ((0x2000U & vlSelfRef.top__DOT__instr)) {
                            vlSelfRef.top__DOT__illegal_instr = 1U;
                        }
                    }
                    vlSelfRef.top__DOT__imm = (((- (IData)(
                                                           (vlSelfRef.top__DOT__instr 
                                                            >> 0x1fU))) 
                                                << 0xdU) 
                                               | ((0x1000U 
                                                   & (vlSelfRef.top__DOT__instr 
                                                      >> 0x13U)) 
                                                  | ((0x800U 
                                                      & (vlSelfRef.top__DOT__instr 
                                                         << 4U)) 
                                                     | ((0x7e0U 
                                                         & (vlSelfRef.top__DOT__instr 
                                                            >> 0x14U)) 
                                                        | (0x1eU 
                                                           & (vlSelfRef.top__DOT__instr 
                                                              >> 7U))))));
                } else {
                    vlSelfRef.top__DOT__illegal_instr = 1U;
                    vlSelfRef.top__DOT__imm = 0U;
                }
            } else {
                vlSelfRef.top__DOT__illegal_instr = 1U;
                vlSelfRef.top__DOT__imm = 0U;
            }
        } else {
            vlSelfRef.top__DOT__illegal_instr = 1U;
            vlSelfRef.top__DOT__imm = 0U;
        }
    } else {
        if ((0x20U & vlSelfRef.top__DOT__instr)) {
            if ((0x10U & vlSelfRef.top__DOT__instr)) {
                if ((1U & (~ (vlSelfRef.top__DOT__instr 
                              >> 3U)))) {
                    if ((4U & vlSelfRef.top__DOT__instr)) {
                        if ((2U & vlSelfRef.top__DOT__instr)) {
                            if ((1U & vlSelfRef.top__DOT__instr)) {
                                vlSelfRef.top__DOT__rf_wen = 1U;
                                vlSelfRef.top__DOT__controller__DOT__imm_type_o = 3U;
                                vlSelfRef.top__DOT__alu_src2_sel = 2U;
                            }
                        }
                    } else if ((2U & vlSelfRef.top__DOT__instr)) {
                        if ((1U & vlSelfRef.top__DOT__instr)) {
                            vlSelfRef.top__DOT__rf_wen = 1U;
                        }
                    }
                }
                if ((8U & vlSelfRef.top__DOT__instr)) {
                    vlSelfRef.top__DOT__illegal_instr = 1U;
                    vlSelfRef.top__DOT__imm = 0U;
                } else if ((4U & vlSelfRef.top__DOT__instr)) {
                    if ((2U & vlSelfRef.top__DOT__instr)) {
                        if ((1U & (~ vlSelfRef.top__DOT__instr))) {
                            vlSelfRef.top__DOT__illegal_instr = 1U;
                        }
                        vlSelfRef.top__DOT__imm = (
                                                   (1U 
                                                    & vlSelfRef.top__DOT__instr)
                                                    ? 
                                                   (0xfffff000U 
                                                    & vlSelfRef.top__DOT__instr)
                                                    : 0U);
                    } else {
                        vlSelfRef.top__DOT__illegal_instr = 1U;
                        vlSelfRef.top__DOT__imm = 0U;
                    }
                } else {
                    if ((2U & vlSelfRef.top__DOT__instr)) {
                        if ((1U & (~ vlSelfRef.top__DOT__instr))) {
                            vlSelfRef.top__DOT__illegal_instr = 1U;
                        }
                    } else {
                        vlSelfRef.top__DOT__illegal_instr = 1U;
                    }
                    vlSelfRef.top__DOT__imm = 0U;
                }
            } else {
                if ((1U & (~ (vlSelfRef.top__DOT__instr 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.top__DOT__instr 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.top__DOT__instr)) {
                            if ((1U & vlSelfRef.top__DOT__instr)) {
                                vlSelfRef.top__DOT__controller__DOT__imm_type_o = 1U;
                                vlSelfRef.top__DOT__alu_src2_sel = 1U;
                            }
                        }
                    }
                }
                if ((8U & vlSelfRef.top__DOT__instr)) {
                    vlSelfRef.top__DOT__illegal_instr = 1U;
                    vlSelfRef.top__DOT__imm = 0U;
                } else if ((4U & vlSelfRef.top__DOT__instr)) {
                    vlSelfRef.top__DOT__illegal_instr = 1U;
                    vlSelfRef.top__DOT__imm = 0U;
                } else if ((2U & vlSelfRef.top__DOT__instr)) {
                    if ((1U & vlSelfRef.top__DOT__instr)) {
                        if ((1U & (~ (((0U == (7U & 
                                               (vlSelfRef.top__DOT__instr 
                                                >> 0xcU))) 
                                       || (1U == (7U 
                                                  & (vlSelfRef.top__DOT__instr 
                                                     >> 0xcU)))) 
                                      || (2U == (7U 
                                                 & (vlSelfRef.top__DOT__instr 
                                                    >> 0xcU))))))) {
                            vlSelfRef.top__DOT__illegal_instr = 1U;
                        }
                        vlSelfRef.top__DOT__imm = (
                                                   ((- (IData)(
                                                               (vlSelfRef.top__DOT__instr 
                                                                >> 0x1fU))) 
                                                    << 0xcU) 
                                                   | ((0xfe0U 
                                                       & (vlSelfRef.top__DOT__instr 
                                                          >> 0x14U)) 
                                                      | (0x1fU 
                                                         & (vlSelfRef.top__DOT__instr 
                                                            >> 7U))));
                    } else {
                        vlSelfRef.top__DOT__illegal_instr = 1U;
                        vlSelfRef.top__DOT__imm = 0U;
                    }
                } else {
                    vlSelfRef.top__DOT__illegal_instr = 1U;
                    vlSelfRef.top__DOT__imm = 0U;
                }
            }
        } else if ((0x10U & vlSelfRef.top__DOT__instr)) {
            if ((1U & (~ (vlSelfRef.top__DOT__instr 
                          >> 3U)))) {
                if ((4U & vlSelfRef.top__DOT__instr)) {
                    if ((2U & vlSelfRef.top__DOT__instr)) {
                        if ((1U & vlSelfRef.top__DOT__instr)) {
                            vlSelfRef.top__DOT__rf_wen = 1U;
                            vlSelfRef.top__DOT__controller__DOT__imm_type_o = 3U;
                            vlSelfRef.top__DOT__alu_src2_sel = 2U;
                        }
                    }
                } else if ((2U & vlSelfRef.top__DOT__instr)) {
                    if ((1U & vlSelfRef.top__DOT__instr)) {
                        vlSelfRef.top__DOT__rf_wen = 1U;
                        vlSelfRef.top__DOT__controller__DOT__imm_type_o = 0U;
                        vlSelfRef.top__DOT__alu_src2_sel = 1U;
                    }
                }
            }
            if ((8U & vlSelfRef.top__DOT__instr)) {
                vlSelfRef.top__DOT__illegal_instr = 1U;
                vlSelfRef.top__DOT__imm = 0U;
            } else if ((4U & vlSelfRef.top__DOT__instr)) {
                if ((2U & vlSelfRef.top__DOT__instr)) {
                    if ((1U & (~ vlSelfRef.top__DOT__instr))) {
                        vlSelfRef.top__DOT__illegal_instr = 1U;
                    }
                    vlSelfRef.top__DOT__imm = ((1U 
                                                & vlSelfRef.top__DOT__instr)
                                                ? (0xfffff000U 
                                                   & vlSelfRef.top__DOT__instr)
                                                : 0U);
                } else {
                    vlSelfRef.top__DOT__illegal_instr = 1U;
                    vlSelfRef.top__DOT__imm = 0U;
                }
            } else if ((2U & vlSelfRef.top__DOT__instr)) {
                if ((1U & (~ vlSelfRef.top__DOT__instr))) {
                    vlSelfRef.top__DOT__illegal_instr = 1U;
                }
                vlSelfRef.top__DOT__imm = ((1U & vlSelfRef.top__DOT__instr)
                                            ? (((- (IData)(
                                                           (vlSelfRef.top__DOT__instr 
                                                            >> 0x1fU))) 
                                                << 0xcU) 
                                               | (vlSelfRef.top__DOT__instr 
                                                  >> 0x14U))
                                            : 0U);
            } else {
                vlSelfRef.top__DOT__illegal_instr = 1U;
                vlSelfRef.top__DOT__imm = 0U;
            }
        } else {
            if ((1U & (~ (vlSelfRef.top__DOT__instr 
                          >> 3U)))) {
                if ((1U & (~ (vlSelfRef.top__DOT__instr 
                              >> 2U)))) {
                    if ((2U & vlSelfRef.top__DOT__instr)) {
                        if ((1U & vlSelfRef.top__DOT__instr)) {
                            vlSelfRef.top__DOT__rf_wen = 1U;
                            vlSelfRef.top__DOT__controller__DOT__imm_type_o = 0U;
                            vlSelfRef.top__DOT__alu_src2_sel = 1U;
                        }
                    }
                }
            }
            if ((8U & vlSelfRef.top__DOT__instr)) {
                vlSelfRef.top__DOT__illegal_instr = 1U;
                vlSelfRef.top__DOT__imm = 0U;
            } else if ((4U & vlSelfRef.top__DOT__instr)) {
                vlSelfRef.top__DOT__illegal_instr = 1U;
                vlSelfRef.top__DOT__imm = 0U;
            } else if ((2U & vlSelfRef.top__DOT__instr)) {
                if ((1U & vlSelfRef.top__DOT__instr)) {
                    if ((0x4000U & vlSelfRef.top__DOT__instr)) {
                        if ((0x2000U & vlSelfRef.top__DOT__instr)) {
                            vlSelfRef.top__DOT__illegal_instr = 1U;
                        }
                    } else if ((0x2000U & vlSelfRef.top__DOT__instr)) {
                        if ((0x1000U & vlSelfRef.top__DOT__instr)) {
                            vlSelfRef.top__DOT__illegal_instr = 1U;
                        }
                    }
                    vlSelfRef.top__DOT__imm = (((- (IData)(
                                                           (vlSelfRef.top__DOT__instr 
                                                            >> 0x1fU))) 
                                                << 0xcU) 
                                               | (vlSelfRef.top__DOT__instr 
                                                  >> 0x14U));
                } else {
                    vlSelfRef.top__DOT__illegal_instr = 1U;
                    vlSelfRef.top__DOT__imm = 0U;
                }
            } else {
                vlSelfRef.top__DOT__illegal_instr = 1U;
                vlSelfRef.top__DOT__imm = 0U;
            }
        }
        if ((1U & (~ (vlSelfRef.top__DOT__instr >> 5U)))) {
            if ((1U & (~ (vlSelfRef.top__DOT__instr 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.top__DOT__instr 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.top__DOT__instr 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.top__DOT__instr)) {
                            if ((1U & vlSelfRef.top__DOT__instr)) {
                                vlSelfRef.top__DOT__rf_wdata_sel = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    VL_WRITEF_NX("instr_i: %b\nopcode_o: %b\nrd_addr_o: %b, rs1_addr_o: %b, rs2_addr_o: %b\nfunct3_o: %b, funct7_o: %b\nimm_debug: %b, imm_sign_extended: %11d\n",0,
                 32,vlSelfRef.top__DOT__instr,7,(0x7fU 
                                                 & vlSelfRef.top__DOT__instr),
                 5,(0x1fU & (vlSelfRef.top__DOT__instr 
                             >> 7U)),5,(0x1fU & (vlSelfRef.top__DOT__instr 
                                                 >> 0xfU)),
                 5,(0x1fU & (vlSelfRef.top__DOT__instr 
                             >> 0x14U)),3,(7U & (vlSelfRef.top__DOT__instr 
                                                 >> 0xcU)),
                 7,(vlSelfRef.top__DOT__instr >> 0x19U),
                 32,vlSelfRef.top__DOT__imm,32,vlSelfRef.top__DOT__imm);
    vlSelfRef.top__DOT__alu_src1 = ((0U == (IData)(vlSelfRef.top__DOT__alu_src1_sel))
                                     ? vlSelfRef.top__DOT__rs1_data
                                     : ((1U == (IData)(vlSelfRef.top__DOT__alu_src1_sel))
                                         ? vlSelfRef.top__DOT__pcunit__DOT__pc_q
                                         : vlSelfRef.top__DOT__rs1_data));
    vlSelfRef.top__DOT__alu_src2 = ((0U == (IData)(vlSelfRef.top__DOT__alu_src2_sel))
                                     ? vlSelfRef.top__DOT__rs2_data
                                     : ((1U == (IData)(vlSelfRef.top__DOT__alu_src2_sel))
                                         ? vlSelfRef.top__DOT__imm
                                         : ((2U == (IData)(vlSelfRef.top__DOT__alu_src2_sel))
                                             ? vlSelfRef.top__DOT__imm
                                             : vlSelfRef.top__DOT__rs2_data)));
    vlSelfRef.top__DOT__branch_eq = (vlSelfRef.top__DOT__rs1_data 
                                     == vlSelfRef.top__DOT__rs2_data);
    vlSelfRef.top__DOT__branch_lt = VL_LTS_III(32, vlSelfRef.top__DOT__rs1_data, vlSelfRef.top__DOT__rs2_data);
    vlSelfRef.top__DOT__branch_ltu = (vlSelfRef.top__DOT__rs1_data 
                                      < vlSelfRef.top__DOT__rs2_data);
    vlSelfRef.top__DOT__alu_result = ((8U & (IData)(vlSelfRef.top__DOT__alu_op))
                                       ? ((4U & (IData)(vlSelfRef.top__DOT__alu_op))
                                           ? 0U : (
                                                   (2U 
                                                    & (IData)(vlSelfRef.top__DOT__alu_op))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.top__DOT__alu_op))
                                                     ? 0U
                                                     : vlSelfRef.top__DOT__alu_src2)
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.top__DOT__alu_op))
                                                     ? 
                                                    (vlSelfRef.top__DOT__alu_src1 
                                                     & vlSelfRef.top__DOT__alu_src2)
                                                     : 
                                                    (vlSelfRef.top__DOT__alu_src1 
                                                     | vlSelfRef.top__DOT__alu_src2))))
                                       : ((4U & (IData)(vlSelfRef.top__DOT__alu_op))
                                           ? ((2U & (IData)(vlSelfRef.top__DOT__alu_op))
                                               ? ((1U 
                                                   & (IData)(vlSelfRef.top__DOT__alu_op))
                                                   ? 
                                                  VL_SHIFTRS_III(32,32,5, vlSelfRef.top__DOT__alu_src1, 
                                                                 (0x1fU 
                                                                  & vlSelfRef.top__DOT__alu_src2))
                                                   : 
                                                  (vlSelfRef.top__DOT__alu_src1 
                                                   >> 
                                                   (0x1fU 
                                                    & vlSelfRef.top__DOT__alu_src2)))
                                               : ((1U 
                                                   & (IData)(vlSelfRef.top__DOT__alu_op))
                                                   ? 
                                                  (vlSelfRef.top__DOT__alu_src1 
                                                   ^ vlSelfRef.top__DOT__alu_src2)
                                                   : 
                                                  (vlSelfRef.top__DOT__alu_src1 
                                                   < vlSelfRef.top__DOT__alu_src2)))
                                           : ((2U & (IData)(vlSelfRef.top__DOT__alu_op))
                                               ? ((1U 
                                                   & (IData)(vlSelfRef.top__DOT__alu_op))
                                                   ? 
                                                  VL_LTS_III(32, vlSelfRef.top__DOT__alu_src1, vlSelfRef.top__DOT__alu_src2)
                                                   : 
                                                  (vlSelfRef.top__DOT__alu_src1 
                                                   << 
                                                   (0x1fU 
                                                    & vlSelfRef.top__DOT__alu_src2)))
                                               : ((1U 
                                                   == (IData)(vlSelfRef.top__DOT__alu_op))
                                                   ? 
                                                  (vlSelfRef.top__DOT__alu_src1 
                                                   - vlSelfRef.top__DOT__alu_src2)
                                                   : 
                                                  (vlSelfRef.top__DOT__alu_src1 
                                                   + vlSelfRef.top__DOT__alu_src2)))));
    __Vtableidx1 = (((IData)(vlSelfRef.top__DOT__branch_eq) 
                     << 8U) | ((0x80U & ((~ (IData)(vlSelfRef.top__DOT__branch_eq)) 
                                         << 7U)) | 
                               (((IData)(vlSelfRef.top__DOT__branch_lt) 
                                 << 6U) | ((0x20U & 
                                            ((~ (IData)(vlSelfRef.top__DOT__branch_lt)) 
                                             << 5U)) 
                                           | (((IData)(vlSelfRef.top__DOT__branch_ltu) 
                                               << 4U) 
                                              | ((8U 
                                                  & ((~ (IData)(vlSelfRef.top__DOT__branch_ltu)) 
                                                     << 3U)) 
                                                 | (7U 
                                                    & (vlSelfRef.top__DOT__instr 
                                                       >> 0xcU))))))));
    vlSelfRef.top__DOT__branch__DOT__branch_taken_o 
        = Vdut__ConstPool__TABLE_h4a44e999_0[__Vtableidx1];
    vlSelfRef.top__DOT__next_pc_sel = 0U;
    if ((0x40U & vlSelfRef.top__DOT__instr)) {
        if ((0x20U & vlSelfRef.top__DOT__instr)) {
            if ((1U & (~ (vlSelfRef.top__DOT__instr 
                          >> 4U)))) {
                if ((8U & vlSelfRef.top__DOT__instr)) {
                    if ((4U & vlSelfRef.top__DOT__instr)) {
                        if ((2U & vlSelfRef.top__DOT__instr)) {
                            if ((1U & vlSelfRef.top__DOT__instr)) {
                                vlSelfRef.top__DOT__next_pc_sel = 2U;
                            }
                        }
                    }
                } else if ((4U & vlSelfRef.top__DOT__instr)) {
                    if ((2U & vlSelfRef.top__DOT__instr)) {
                        if ((1U & vlSelfRef.top__DOT__instr)) {
                            vlSelfRef.top__DOT__next_pc_sel = 3U;
                        }
                    }
                } else if ((2U & vlSelfRef.top__DOT__instr)) {
                    if ((1U & vlSelfRef.top__DOT__instr)) {
                        if ((0x4000U & vlSelfRef.top__DOT__instr)) {
                            vlSelfRef.top__DOT__next_pc_sel 
                                = ((0x2000U & vlSelfRef.top__DOT__instr)
                                    ? ((0x1000U & vlSelfRef.top__DOT__instr)
                                        ? ((IData)(vlSelfRef.top__DOT__branch_ltu)
                                            ? 0U : 1U)
                                        : ((IData)(vlSelfRef.top__DOT__branch_ltu)
                                            ? 1U : 0U))
                                    : ((0x1000U & vlSelfRef.top__DOT__instr)
                                        ? ((IData)(vlSelfRef.top__DOT__branch_lt)
                                            ? 0U : 1U)
                                        : ((IData)(vlSelfRef.top__DOT__branch_lt)
                                            ? 1U : 0U)));
                        } else if ((1U & (~ (vlSelfRef.top__DOT__instr 
                                             >> 0xdU)))) {
                            vlSelfRef.top__DOT__next_pc_sel 
                                = ((0x1000U & vlSelfRef.top__DOT__instr)
                                    ? ((IData)(vlSelfRef.top__DOT__branch_eq)
                                        ? 0U : 1U) : 
                                   ((IData)(vlSelfRef.top__DOT__branch_eq)
                                     ? 1U : 0U));
                        }
                    }
                }
            }
        }
    }
    vlSelfRef.top__DOT__dmem__DOT__rdata_aligned = 
        ((0U == (IData)(vlSelfRef.top__DOT__mem_size))
          ? (((- (IData)(((IData)(vlSelfRef.top__DOT__mem_signed) 
                          & (vlSelfRef.top__DOT__dmem__DOT__mem
                             [(0x1fffU & vlSelfRef.top__DOT__alu_result)] 
                             >> 7U)))) << 8U) | vlSelfRef.top__DOT__dmem__DOT__mem
             [(0x1fffU & vlSelfRef.top__DOT__alu_result)])
          : ((1U == (IData)(vlSelfRef.top__DOT__mem_size))
              ? ((0x2000U > ((IData)(1U) + vlSelfRef.top__DOT__alu_result))
                  ? (((- (IData)(((IData)(vlSelfRef.top__DOT__mem_signed) 
                                  & (vlSelfRef.top__DOT__dmem__DOT__mem
                                     [(0x1fffU & ((IData)(1U) 
                                                  + vlSelfRef.top__DOT__alu_result))] 
                                     >> 7U)))) << 0x10U) 
                     | ((vlSelfRef.top__DOT__dmem__DOT__mem
                         [(0x1fffU & ((IData)(1U) + vlSelfRef.top__DOT__alu_result))] 
                         << 8U) | vlSelfRef.top__DOT__dmem__DOT__mem
                        [(0x1fffU & vlSelfRef.top__DOT__alu_result)]))
                  : 0U) : ((2U == (IData)(vlSelfRef.top__DOT__mem_size))
                            ? ((0x2000U > ((IData)(3U) 
                                           + vlSelfRef.top__DOT__alu_result))
                                ? ((vlSelfRef.top__DOT__dmem__DOT__mem
                                    [(0x1fffU & ((IData)(3U) 
                                                 + vlSelfRef.top__DOT__alu_result))] 
                                    << 0x18U) | ((vlSelfRef.top__DOT__dmem__DOT__mem
                                                  [
                                                  (0x1fffU 
                                                   & ((IData)(2U) 
                                                      + vlSelfRef.top__DOT__alu_result))] 
                                                  << 0x10U) 
                                                 | ((vlSelfRef.top__DOT__dmem__DOT__mem
                                                     [
                                                     (0x1fffU 
                                                      & ((IData)(1U) 
                                                         + vlSelfRef.top__DOT__alu_result))] 
                                                     << 8U) 
                                                    | vlSelfRef.top__DOT__dmem__DOT__mem
                                                    [
                                                    (0x1fffU 
                                                     & vlSelfRef.top__DOT__alu_result)])))
                                : 0U) : 0U)));
    vlSelfRef.top__DOT__pcunit__DOT__next_pc_o = ((4U 
                                                   & (IData)(vlSelfRef.top__DOT__next_pc_sel))
                                                   ? 
                                                  ((IData)(4U) 
                                                   + vlSelfRef.top__DOT__pcunit__DOT__pc_q)
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlSelfRef.top__DOT__next_pc_sel))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.top__DOT__next_pc_sel))
                                                     ? 
                                                    (0xfffffffeU 
                                                     & vlSelfRef.top__DOT__alu_result)
                                                     : 
                                                    (vlSelfRef.top__DOT__pcunit__DOT__pc_q 
                                                     + vlSelfRef.top__DOT__imm))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.top__DOT__next_pc_sel))
                                                     ? 
                                                    (vlSelfRef.top__DOT__pcunit__DOT__pc_q 
                                                     + vlSelfRef.top__DOT__imm)
                                                     : 
                                                    ((IData)(4U) 
                                                     + vlSelfRef.top__DOT__pcunit__DOT__pc_q))));
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
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk_i)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge clk_i or negedge rst_ni)\n");
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
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk_i)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge clk_i or negedge rst_ni)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vdut___024root___ctor_var_reset(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___ctor_var_reset\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk_i = VL_RAND_RESET_I(1);
    vlSelf->rst_ni = VL_RAND_RESET_I(1);
    vlSelf->a0_o = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__instr = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__rs1_data = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__rs2_data = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__alu_result = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__branch_eq = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__branch_lt = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__branch_ltu = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__imm = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__rf_wen = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__rf_wdata_sel = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__alu_op = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__alu_src1_sel = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__alu_src2_sel = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__mem_wen = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__mem_size = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__mem_signed = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__next_pc_sel = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__illegal_instr = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__alu_src1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__alu_src2 = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->top__DOT__imem__DOT__mem[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->top__DOT__controller__DOT__imm_type_o = VL_RAND_RESET_I(3);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__regfile__DOT__rf_reg[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->top__DOT__regfile__DOT__unnamedblk1__DOT__i = 0;
    for (int __Vi0 = 0; __Vi0 < 8192; ++__Vi0) {
        vlSelf->top__DOT__dmem__DOT__mem[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->top__DOT__dmem__DOT__rdata_aligned = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dmem__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->top__DOT__branch__DOT__branch_taken_o = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__pcunit__DOT__next_pc_o = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__pcunit__DOT__pc_q = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__clk_i__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst_ni__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
