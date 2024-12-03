// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcontroller.h for the primary calling header

#include "Vcontroller__pch.h"
#include "Vcontroller___024root.h"

void Vcontroller___024root___ico_sequent__TOP__0(Vcontroller___024root* vlSelf);

void Vcontroller___024root___eval_ico(Vcontroller___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcontroller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller___024root___eval_ico\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vcontroller___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vcontroller___024root___ico_sequent__TOP__0(Vcontroller___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcontroller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller___024root___ico_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rf_wen_o = 0U;
    vlSelfRef.alu_src1_sel_o = 0U;
    vlSelfRef.imm_type_o = 0U;
    vlSelfRef.alu_src2_sel_o = 0U;
    vlSelfRef.mem_wen_o = 0U;
    vlSelfRef.rf_wdata_sel_o = 0U;
    vlSelfRef.mem_signed_o = 1U;
    vlSelfRef.illegal_instr_o = 0U;
    vlSelfRef.mem_size_o = vlSelfRef.funct3_i;
    vlSelfRef.alu_op_o = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.opcode_i) >> 6U)))) {
        if ((1U & (~ ((IData)(vlSelfRef.opcode_i) >> 5U)))) {
            if ((0x10U & (IData)(vlSelfRef.opcode_i))) {
                if ((1U & (~ ((IData)(vlSelfRef.opcode_i) 
                              >> 3U)))) {
                    if ((4U & (IData)(vlSelfRef.opcode_i))) {
                        if ((2U & (IData)(vlSelfRef.opcode_i))) {
                            if ((1U & (IData)(vlSelfRef.opcode_i))) {
                                vlSelfRef.alu_src1_sel_o = 1U;
                            }
                        }
                    }
                }
            }
            if ((1U & (~ ((IData)(vlSelfRef.opcode_i) 
                          >> 4U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.opcode_i) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.opcode_i) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelfRef.opcode_i))) {
                            if ((1U & (IData)(vlSelfRef.opcode_i))) {
                                vlSelfRef.mem_signed_o 
                                    = (1U & (~ ((IData)(vlSelfRef.funct3_i) 
                                                >> 2U)));
                            }
                        }
                    }
                }
            }
        }
        if ((0x20U & (IData)(vlSelfRef.opcode_i))) {
            if ((1U & (~ ((IData)(vlSelfRef.opcode_i) 
                          >> 4U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.opcode_i) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.opcode_i) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelfRef.opcode_i))) {
                            if ((1U & (IData)(vlSelfRef.opcode_i))) {
                                vlSelfRef.mem_wen_o = 1U;
                                if ((((0U == (IData)(vlSelfRef.funct3_i)) 
                                      || (1U == (IData)(vlSelfRef.funct3_i))) 
                                     || (2U == (IData)(vlSelfRef.funct3_i)))) {
                                    vlSelfRef.mem_size_o 
                                        = vlSelfRef.funct3_i;
                                }
                            }
                        }
                    }
                }
            }
            if ((0x10U & (IData)(vlSelfRef.opcode_i))) {
                if ((1U & (~ ((IData)(vlSelfRef.opcode_i) 
                              >> 3U)))) {
                    if ((4U & (IData)(vlSelfRef.opcode_i))) {
                        if ((2U & (IData)(vlSelfRef.opcode_i))) {
                            if ((1U & (IData)(vlSelfRef.opcode_i))) {
                                vlSelfRef.alu_op_o = 0xaU;
                            }
                        }
                    } else if ((2U & (IData)(vlSelfRef.opcode_i))) {
                        if ((1U & (IData)(vlSelfRef.opcode_i))) {
                            vlSelfRef.alu_op_o = ((4U 
                                                   & (IData)(vlSelfRef.funct3_i))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(vlSelfRef.funct3_i))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.funct3_i))
                                                     ? 9U
                                                     : 8U)
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.funct3_i))
                                                     ? 
                                                    ((0x20U 
                                                      & (IData)(vlSelfRef.funct7_i))
                                                      ? 7U
                                                      : 6U)
                                                     : 5U))
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlSelfRef.funct3_i))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.funct3_i))
                                                     ? 4U
                                                     : 3U)
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.funct3_i))
                                                     ? 2U
                                                     : 
                                                    ((0x20U 
                                                      & (IData)(vlSelfRef.funct7_i))
                                                      ? 1U
                                                      : 0U))));
                        }
                    }
                }
            }
        } else {
            if ((1U & (~ ((IData)(vlSelfRef.opcode_i) 
                          >> 4U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.opcode_i) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.opcode_i) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelfRef.opcode_i))) {
                            if ((1U & (IData)(vlSelfRef.opcode_i))) {
                                if ((4U & (IData)(vlSelfRef.funct3_i))) {
                                    if ((1U & (~ ((IData)(vlSelfRef.funct3_i) 
                                                  >> 1U)))) {
                                        vlSelfRef.mem_size_o 
                                            = vlSelfRef.funct3_i;
                                    }
                                } else if ((2U & (IData)(vlSelfRef.funct3_i))) {
                                    if ((1U & (~ (IData)(vlSelfRef.funct3_i)))) {
                                        vlSelfRef.mem_size_o 
                                            = vlSelfRef.funct3_i;
                                    }
                                } else {
                                    vlSelfRef.mem_size_o 
                                        = vlSelfRef.funct3_i;
                                }
                            }
                        }
                    }
                }
            }
            if ((0x10U & (IData)(vlSelfRef.opcode_i))) {
                if ((1U & (~ ((IData)(vlSelfRef.opcode_i) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.opcode_i) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelfRef.opcode_i))) {
                            if ((1U & (IData)(vlSelfRef.opcode_i))) {
                                vlSelfRef.alu_op_o 
                                    = ((4U & (IData)(vlSelfRef.funct3_i))
                                        ? ((2U & (IData)(vlSelfRef.funct3_i))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.funct3_i))
                                                ? 9U
                                                : 8U)
                                            : ((1U 
                                                & (IData)(vlSelfRef.funct3_i))
                                                ? (
                                                   (0x20U 
                                                    & (IData)(vlSelfRef.funct7_i))
                                                    ? 7U
                                                    : 6U)
                                                : 5U))
                                        : ((2U & (IData)(vlSelfRef.funct3_i))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.funct3_i))
                                                ? 4U
                                                : 3U)
                                            : ((1U 
                                                & (IData)(vlSelfRef.funct3_i))
                                                ? 2U
                                                : 0U)));
                            }
                        }
                    }
                }
            }
        }
    }
    vlSelfRef.next_pc_sel_o = 0U;
    if ((0x40U & (IData)(vlSelfRef.opcode_i))) {
        if ((0x20U & (IData)(vlSelfRef.opcode_i))) {
            if ((1U & (~ ((IData)(vlSelfRef.opcode_i) 
                          >> 4U)))) {
                if ((8U & (IData)(vlSelfRef.opcode_i))) {
                    if ((4U & (IData)(vlSelfRef.opcode_i))) {
                        if ((2U & (IData)(vlSelfRef.opcode_i))) {
                            if ((1U & (IData)(vlSelfRef.opcode_i))) {
                                vlSelfRef.rf_wen_o = 1U;
                                vlSelfRef.imm_type_o = 4U;
                                vlSelfRef.rf_wdata_sel_o = 2U;
                                vlSelfRef.next_pc_sel_o = 2U;
                            }
                        }
                    }
                } else if ((4U & (IData)(vlSelfRef.opcode_i))) {
                    if ((2U & (IData)(vlSelfRef.opcode_i))) {
                        if ((1U & (IData)(vlSelfRef.opcode_i))) {
                            vlSelfRef.rf_wen_o = 1U;
                            vlSelfRef.imm_type_o = 0U;
                            vlSelfRef.rf_wdata_sel_o = 2U;
                            vlSelfRef.next_pc_sel_o = 3U;
                        }
                    }
                } else if ((2U & (IData)(vlSelfRef.opcode_i))) {
                    if ((1U & (IData)(vlSelfRef.opcode_i))) {
                        vlSelfRef.imm_type_o = 2U;
                        if ((4U & (IData)(vlSelfRef.funct3_i))) {
                            vlSelfRef.next_pc_sel_o 
                                = ((2U & (IData)(vlSelfRef.funct3_i))
                                    ? ((1U & (IData)(vlSelfRef.funct3_i))
                                        ? ((IData)(vlSelfRef.branch_ltu_i)
                                            ? 0U : 1U)
                                        : ((IData)(vlSelfRef.branch_ltu_i)
                                            ? 1U : 0U))
                                    : ((1U & (IData)(vlSelfRef.funct3_i))
                                        ? ((IData)(vlSelfRef.branch_lt_i)
                                            ? 0U : 1U)
                                        : ((IData)(vlSelfRef.branch_lt_i)
                                            ? 1U : 0U)));
                        } else if ((1U & (~ ((IData)(vlSelfRef.funct3_i) 
                                             >> 1U)))) {
                            vlSelfRef.next_pc_sel_o 
                                = ((1U & (IData)(vlSelfRef.funct3_i))
                                    ? ((IData)(vlSelfRef.branch_eq_i)
                                        ? 0U : 1U) : 
                                   ((IData)(vlSelfRef.branch_eq_i)
                                     ? 1U : 0U));
                        }
                    }
                }
                if ((1U & (~ ((IData)(vlSelfRef.opcode_i) 
                              >> 3U)))) {
                    if ((4U & (IData)(vlSelfRef.opcode_i))) {
                        if ((2U & (IData)(vlSelfRef.opcode_i))) {
                            if ((1U & (IData)(vlSelfRef.opcode_i))) {
                                vlSelfRef.alu_src2_sel_o = 1U;
                            }
                        }
                    }
                }
            }
            if ((0x10U & (IData)(vlSelfRef.opcode_i))) {
                vlSelfRef.illegal_instr_o = 1U;
            } else if ((8U & (IData)(vlSelfRef.opcode_i))) {
                if ((4U & (IData)(vlSelfRef.opcode_i))) {
                    if ((2U & (IData)(vlSelfRef.opcode_i))) {
                        if ((1U & (~ (IData)(vlSelfRef.opcode_i)))) {
                            vlSelfRef.illegal_instr_o = 1U;
                        }
                    } else {
                        vlSelfRef.illegal_instr_o = 1U;
                    }
                } else {
                    vlSelfRef.illegal_instr_o = 1U;
                }
            } else if ((4U & (IData)(vlSelfRef.opcode_i))) {
                if ((2U & (IData)(vlSelfRef.opcode_i))) {
                    if ((1U & (~ (IData)(vlSelfRef.opcode_i)))) {
                        vlSelfRef.illegal_instr_o = 1U;
                    }
                } else {
                    vlSelfRef.illegal_instr_o = 1U;
                }
            } else if ((2U & (IData)(vlSelfRef.opcode_i))) {
                if ((1U & (IData)(vlSelfRef.opcode_i))) {
                    if ((1U & (~ ((IData)(vlSelfRef.funct3_i) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelfRef.funct3_i))) {
                            vlSelfRef.illegal_instr_o = 1U;
                        }
                    }
                } else {
                    vlSelfRef.illegal_instr_o = 1U;
                }
            } else {
                vlSelfRef.illegal_instr_o = 1U;
            }
        } else {
            vlSelfRef.illegal_instr_o = 1U;
        }
    } else {
        if ((0x20U & (IData)(vlSelfRef.opcode_i))) {
            if ((0x10U & (IData)(vlSelfRef.opcode_i))) {
                if ((1U & (~ ((IData)(vlSelfRef.opcode_i) 
                              >> 3U)))) {
                    if ((4U & (IData)(vlSelfRef.opcode_i))) {
                        if ((2U & (IData)(vlSelfRef.opcode_i))) {
                            if ((1U & (IData)(vlSelfRef.opcode_i))) {
                                vlSelfRef.rf_wen_o = 1U;
                                vlSelfRef.imm_type_o = 3U;
                                vlSelfRef.alu_src2_sel_o = 2U;
                            }
                        }
                    } else if ((2U & (IData)(vlSelfRef.opcode_i))) {
                        if ((1U & (IData)(vlSelfRef.opcode_i))) {
                            vlSelfRef.rf_wen_o = 1U;
                        }
                    }
                }
                if ((8U & (IData)(vlSelfRef.opcode_i))) {
                    vlSelfRef.illegal_instr_o = 1U;
                } else if ((4U & (IData)(vlSelfRef.opcode_i))) {
                    if ((2U & (IData)(vlSelfRef.opcode_i))) {
                        if ((1U & (~ (IData)(vlSelfRef.opcode_i)))) {
                            vlSelfRef.illegal_instr_o = 1U;
                        }
                    } else {
                        vlSelfRef.illegal_instr_o = 1U;
                    }
                } else if ((2U & (IData)(vlSelfRef.opcode_i))) {
                    if ((1U & (~ (IData)(vlSelfRef.opcode_i)))) {
                        vlSelfRef.illegal_instr_o = 1U;
                    }
                } else {
                    vlSelfRef.illegal_instr_o = 1U;
                }
            } else {
                if ((1U & (~ ((IData)(vlSelfRef.opcode_i) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.opcode_i) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelfRef.opcode_i))) {
                            if ((1U & (IData)(vlSelfRef.opcode_i))) {
                                vlSelfRef.imm_type_o = 1U;
                                vlSelfRef.alu_src2_sel_o = 1U;
                            }
                        }
                    }
                }
                if ((8U & (IData)(vlSelfRef.opcode_i))) {
                    vlSelfRef.illegal_instr_o = 1U;
                } else if ((4U & (IData)(vlSelfRef.opcode_i))) {
                    vlSelfRef.illegal_instr_o = 1U;
                } else if ((2U & (IData)(vlSelfRef.opcode_i))) {
                    if ((1U & (IData)(vlSelfRef.opcode_i))) {
                        if ((1U & (~ (((0U == (IData)(vlSelfRef.funct3_i)) 
                                       || (1U == (IData)(vlSelfRef.funct3_i))) 
                                      || (2U == (IData)(vlSelfRef.funct3_i)))))) {
                            vlSelfRef.illegal_instr_o = 1U;
                        }
                    } else {
                        vlSelfRef.illegal_instr_o = 1U;
                    }
                } else {
                    vlSelfRef.illegal_instr_o = 1U;
                }
            }
        } else if ((0x10U & (IData)(vlSelfRef.opcode_i))) {
            if ((1U & (~ ((IData)(vlSelfRef.opcode_i) 
                          >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.opcode_i))) {
                    if ((2U & (IData)(vlSelfRef.opcode_i))) {
                        if ((1U & (IData)(vlSelfRef.opcode_i))) {
                            vlSelfRef.rf_wen_o = 1U;
                            vlSelfRef.imm_type_o = 3U;
                            vlSelfRef.alu_src2_sel_o = 2U;
                        }
                    }
                } else if ((2U & (IData)(vlSelfRef.opcode_i))) {
                    if ((1U & (IData)(vlSelfRef.opcode_i))) {
                        vlSelfRef.rf_wen_o = 1U;
                        vlSelfRef.imm_type_o = 0U;
                        vlSelfRef.alu_src2_sel_o = 1U;
                    }
                }
            }
            if ((8U & (IData)(vlSelfRef.opcode_i))) {
                vlSelfRef.illegal_instr_o = 1U;
            } else if ((4U & (IData)(vlSelfRef.opcode_i))) {
                if ((2U & (IData)(vlSelfRef.opcode_i))) {
                    if ((1U & (~ (IData)(vlSelfRef.opcode_i)))) {
                        vlSelfRef.illegal_instr_o = 1U;
                    }
                } else {
                    vlSelfRef.illegal_instr_o = 1U;
                }
            } else if ((2U & (IData)(vlSelfRef.opcode_i))) {
                if ((1U & (~ (IData)(vlSelfRef.opcode_i)))) {
                    vlSelfRef.illegal_instr_o = 1U;
                }
            } else {
                vlSelfRef.illegal_instr_o = 1U;
            }
        } else {
            if ((1U & (~ ((IData)(vlSelfRef.opcode_i) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.opcode_i) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlSelfRef.opcode_i))) {
                        if ((1U & (IData)(vlSelfRef.opcode_i))) {
                            vlSelfRef.rf_wen_o = 1U;
                            vlSelfRef.imm_type_o = 0U;
                            vlSelfRef.alu_src2_sel_o = 1U;
                        }
                    }
                }
            }
            if ((8U & (IData)(vlSelfRef.opcode_i))) {
                vlSelfRef.illegal_instr_o = 1U;
            } else if ((4U & (IData)(vlSelfRef.opcode_i))) {
                vlSelfRef.illegal_instr_o = 1U;
            } else if ((2U & (IData)(vlSelfRef.opcode_i))) {
                if ((1U & (IData)(vlSelfRef.opcode_i))) {
                    if ((4U & (IData)(vlSelfRef.funct3_i))) {
                        if ((2U & (IData)(vlSelfRef.funct3_i))) {
                            vlSelfRef.illegal_instr_o = 1U;
                        }
                    } else if ((2U & (IData)(vlSelfRef.funct3_i))) {
                        if ((1U & (IData)(vlSelfRef.funct3_i))) {
                            vlSelfRef.illegal_instr_o = 1U;
                        }
                    }
                } else {
                    vlSelfRef.illegal_instr_o = 1U;
                }
            } else {
                vlSelfRef.illegal_instr_o = 1U;
            }
        }
        if ((1U & (~ ((IData)(vlSelfRef.opcode_i) >> 5U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.opcode_i) 
                          >> 4U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.opcode_i) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.opcode_i) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelfRef.opcode_i))) {
                            if ((1U & (IData)(vlSelfRef.opcode_i))) {
                                vlSelfRef.rf_wdata_sel_o = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
}

void Vcontroller___024root___eval_triggers__ico(Vcontroller___024root* vlSelf);

bool Vcontroller___024root___eval_phase__ico(Vcontroller___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcontroller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller___024root___eval_phase__ico\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vcontroller___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vcontroller___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vcontroller___024root___eval_act(Vcontroller___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcontroller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller___024root___eval_act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

void Vcontroller___024root___eval_nba(Vcontroller___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcontroller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller___024root___eval_nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

void Vcontroller___024root___eval_triggers__act(Vcontroller___024root* vlSelf);

bool Vcontroller___024root___eval_phase__act(Vcontroller___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcontroller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller___024root___eval_phase__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<0> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vcontroller___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vcontroller___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vcontroller___024root___eval_phase__nba(Vcontroller___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcontroller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller___024root___eval_phase__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vcontroller___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcontroller___024root___dump_triggers__ico(Vcontroller___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vcontroller___024root___dump_triggers__nba(Vcontroller___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vcontroller___024root___dump_triggers__act(Vcontroller___024root* vlSelf);
#endif  // VL_DEBUG

void Vcontroller___024root___eval(Vcontroller___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcontroller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller___024root___eval\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vcontroller___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/Users/michaelli/Documents/GitHub/iac-riscv-cw-24/RISC-V_RV32I_Project/rtl/controller.sv", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vcontroller___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vcontroller___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/Users/michaelli/Documents/GitHub/iac-riscv-cw-24/RISC-V_RV32I_Project/rtl/controller.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vcontroller___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/Users/michaelli/Documents/GitHub/iac-riscv-cw-24/RISC-V_RV32I_Project/rtl/controller.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vcontroller___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vcontroller___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vcontroller___024root___eval_debug_assertions(Vcontroller___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcontroller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller___024root___eval_debug_assertions\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.clk_i & 0xfeU))) {
        Verilated::overWidthError("clk_i");}
    if (VL_UNLIKELY((vlSelfRef.rst_ni & 0xfeU))) {
        Verilated::overWidthError("rst_ni");}
    if (VL_UNLIKELY((vlSelfRef.opcode_i & 0x80U))) {
        Verilated::overWidthError("opcode_i");}
    if (VL_UNLIKELY((vlSelfRef.funct3_i & 0xf8U))) {
        Verilated::overWidthError("funct3_i");}
    if (VL_UNLIKELY((vlSelfRef.funct7_i & 0x80U))) {
        Verilated::overWidthError("funct7_i");}
    if (VL_UNLIKELY((vlSelfRef.branch_eq_i & 0xfeU))) {
        Verilated::overWidthError("branch_eq_i");}
    if (VL_UNLIKELY((vlSelfRef.branch_lt_i & 0xfeU))) {
        Verilated::overWidthError("branch_lt_i");}
    if (VL_UNLIKELY((vlSelfRef.branch_ltu_i & 0xfeU))) {
        Verilated::overWidthError("branch_ltu_i");}
}
#endif  // VL_DEBUG
