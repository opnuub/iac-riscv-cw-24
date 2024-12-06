// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcontroller.h for the primary calling header

#include "verilated.h"

#include "Vcontroller___024root.h"

VL_INLINE_OPT void Vcontroller___024root___combo__TOP__0(Vcontroller___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontroller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller___024root___combo__TOP__0\n"); );
    // Body
    vlSelf->alu_src2_sel_o = 0U;
    vlSelf->alu_src1_sel_o = 0U;
    vlSelf->rf_wen_o = 0U;
    vlSelf->rf_wdata_sel_o = 0U;
    vlSelf->imm_type_o = 0U;
    vlSelf->mem_wen_o = 0U;
    vlSelf->mem_signed_o = 1U;
    vlSelf->illegal_instr_o = 0U;
    vlSelf->mem_size_o = vlSelf->funct3_i;
    vlSelf->alu_op_o = 0U;
    if ((1U & (~ ((IData)(vlSelf->opcode_i) >> 6U)))) {
        if ((1U & (~ ((IData)(vlSelf->opcode_i) >> 5U)))) {
            if ((0x10U & (IData)(vlSelf->opcode_i))) {
                if ((1U & (~ ((IData)(vlSelf->opcode_i) 
                              >> 3U)))) {
                    if ((4U & (IData)(vlSelf->opcode_i))) {
                        if ((2U & (IData)(vlSelf->opcode_i))) {
                            if ((1U & (IData)(vlSelf->opcode_i))) {
                                vlSelf->alu_src1_sel_o = 1U;
                            }
                        }
                    }
                }
            }
            if ((1U & (~ ((IData)(vlSelf->opcode_i) 
                          >> 4U)))) {
                if ((1U & (~ ((IData)(vlSelf->opcode_i) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelf->opcode_i) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelf->opcode_i))) {
                            if ((1U & (IData)(vlSelf->opcode_i))) {
                                vlSelf->mem_signed_o 
                                    = (1U & (~ ((IData)(vlSelf->funct3_i) 
                                                >> 2U)));
                            }
                        }
                    }
                }
            }
        }
        if ((0x20U & (IData)(vlSelf->opcode_i))) {
            if ((1U & (~ ((IData)(vlSelf->opcode_i) 
                          >> 4U)))) {
                if ((1U & (~ ((IData)(vlSelf->opcode_i) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelf->opcode_i) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelf->opcode_i))) {
                            if ((1U & (IData)(vlSelf->opcode_i))) {
                                vlSelf->mem_wen_o = 1U;
                                if ((((0U == (IData)(vlSelf->funct3_i)) 
                                      | (1U == (IData)(vlSelf->funct3_i))) 
                                     | (2U == (IData)(vlSelf->funct3_i)))) {
                                    vlSelf->mem_size_o 
                                        = vlSelf->funct3_i;
                                }
                            }
                        }
                    }
                }
            }
            if ((0x10U & (IData)(vlSelf->opcode_i))) {
                if ((1U & (~ ((IData)(vlSelf->opcode_i) 
                              >> 3U)))) {
                    if ((4U & (IData)(vlSelf->opcode_i))) {
                        if ((2U & (IData)(vlSelf->opcode_i))) {
                            if ((1U & (IData)(vlSelf->opcode_i))) {
                                vlSelf->alu_op_o = 0xaU;
                            }
                        }
                    } else if ((2U & (IData)(vlSelf->opcode_i))) {
                        if ((1U & (IData)(vlSelf->opcode_i))) {
                            vlSelf->alu_op_o = ((4U 
                                                 & (IData)(vlSelf->funct3_i))
                                                 ? 
                                                ((2U 
                                                  & (IData)(vlSelf->funct3_i))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelf->funct3_i))
                                                   ? 9U
                                                   : 8U)
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelf->funct3_i))
                                                   ? 
                                                  ((0x20U 
                                                    & (IData)(vlSelf->funct7_i))
                                                    ? 7U
                                                    : 6U)
                                                   : 5U))
                                                 : 
                                                ((2U 
                                                  & (IData)(vlSelf->funct3_i))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelf->funct3_i))
                                                   ? 4U
                                                   : 3U)
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelf->funct3_i))
                                                   ? 2U
                                                   : 
                                                  ((0x20U 
                                                    & (IData)(vlSelf->funct7_i))
                                                    ? 1U
                                                    : 0U))));
                        }
                    }
                }
            }
        } else {
            if ((1U & (~ ((IData)(vlSelf->opcode_i) 
                          >> 4U)))) {
                if ((1U & (~ ((IData)(vlSelf->opcode_i) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelf->opcode_i) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelf->opcode_i))) {
                            if ((1U & (IData)(vlSelf->opcode_i))) {
                                if ((4U & (IData)(vlSelf->funct3_i))) {
                                    if ((1U & (~ ((IData)(vlSelf->funct3_i) 
                                                  >> 1U)))) {
                                        vlSelf->mem_size_o 
                                            = vlSelf->funct3_i;
                                    }
                                } else if ((2U & (IData)(vlSelf->funct3_i))) {
                                    if ((1U & (~ (IData)(vlSelf->funct3_i)))) {
                                        vlSelf->mem_size_o 
                                            = vlSelf->funct3_i;
                                    }
                                } else {
                                    vlSelf->mem_size_o 
                                        = vlSelf->funct3_i;
                                }
                            }
                        }
                    }
                }
            }
            if ((0x10U & (IData)(vlSelf->opcode_i))) {
                if ((1U & (~ ((IData)(vlSelf->opcode_i) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelf->opcode_i) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelf->opcode_i))) {
                            if ((1U & (IData)(vlSelf->opcode_i))) {
                                vlSelf->alu_op_o = 
                                    ((4U & (IData)(vlSelf->funct3_i))
                                      ? ((2U & (IData)(vlSelf->funct3_i))
                                          ? ((1U & (IData)(vlSelf->funct3_i))
                                              ? 9U : 8U)
                                          : ((1U & (IData)(vlSelf->funct3_i))
                                              ? ((0x20U 
                                                  & (IData)(vlSelf->funct7_i))
                                                  ? 7U
                                                  : 6U)
                                              : 5U))
                                      : ((2U & (IData)(vlSelf->funct3_i))
                                          ? ((1U & (IData)(vlSelf->funct3_i))
                                              ? 4U : 3U)
                                          : ((1U & (IData)(vlSelf->funct3_i))
                                              ? 2U : 0U)));
                            }
                        }
                    }
                }
            }
        }
    }
    vlSelf->next_pc_sel_o = 0U;
    if ((0x40U & (IData)(vlSelf->opcode_i))) {
        if ((0x20U & (IData)(vlSelf->opcode_i))) {
            if ((1U & (~ ((IData)(vlSelf->opcode_i) 
                          >> 4U)))) {
                if ((1U & (~ ((IData)(vlSelf->opcode_i) 
                              >> 3U)))) {
                    if ((4U & (IData)(vlSelf->opcode_i))) {
                        if ((2U & (IData)(vlSelf->opcode_i))) {
                            if ((1U & (IData)(vlSelf->opcode_i))) {
                                vlSelf->alu_src2_sel_o = 1U;
                            }
                        }
                    }
                }
                if ((8U & (IData)(vlSelf->opcode_i))) {
                    if ((4U & (IData)(vlSelf->opcode_i))) {
                        if ((2U & (IData)(vlSelf->opcode_i))) {
                            if ((1U & (IData)(vlSelf->opcode_i))) {
                                vlSelf->rf_wen_o = 1U;
                                vlSelf->rf_wdata_sel_o = 2U;
                                vlSelf->imm_type_o = 4U;
                                vlSelf->next_pc_sel_o = 2U;
                            }
                        }
                    }
                } else if ((4U & (IData)(vlSelf->opcode_i))) {
                    if ((2U & (IData)(vlSelf->opcode_i))) {
                        if ((1U & (IData)(vlSelf->opcode_i))) {
                            vlSelf->rf_wen_o = 1U;
                            vlSelf->rf_wdata_sel_o = 2U;
                            vlSelf->imm_type_o = 0U;
                            vlSelf->next_pc_sel_o = 3U;
                        }
                    }
                } else if ((2U & (IData)(vlSelf->opcode_i))) {
                    if ((1U & (IData)(vlSelf->opcode_i))) {
                        vlSelf->imm_type_o = 2U;
                        if ((4U & (IData)(vlSelf->funct3_i))) {
                            vlSelf->next_pc_sel_o = 
                                ((2U & (IData)(vlSelf->funct3_i))
                                  ? ((1U & (IData)(vlSelf->funct3_i))
                                      ? ((IData)(vlSelf->branch_ltu_i)
                                          ? 0U : 1U)
                                      : ((IData)(vlSelf->branch_ltu_i)
                                          ? 1U : 0U))
                                  : ((1U & (IData)(vlSelf->funct3_i))
                                      ? ((IData)(vlSelf->branch_lt_i)
                                          ? 0U : 1U)
                                      : ((IData)(vlSelf->branch_lt_i)
                                          ? 1U : 0U)));
                        } else if ((1U & (~ ((IData)(vlSelf->funct3_i) 
                                             >> 1U)))) {
                            vlSelf->next_pc_sel_o = 
                                ((1U & (IData)(vlSelf->funct3_i))
                                  ? ((IData)(vlSelf->branch_eq_i)
                                      ? 0U : 1U) : 
                                 ((IData)(vlSelf->branch_eq_i)
                                   ? 1U : 0U));
                        }
                    }
                }
            }
            if ((0x10U & (IData)(vlSelf->opcode_i))) {
                vlSelf->illegal_instr_o = 1U;
            } else if ((8U & (IData)(vlSelf->opcode_i))) {
                if ((4U & (IData)(vlSelf->opcode_i))) {
                    if ((2U & (IData)(vlSelf->opcode_i))) {
                        if ((1U & (~ (IData)(vlSelf->opcode_i)))) {
                            vlSelf->illegal_instr_o = 1U;
                        }
                    } else {
                        vlSelf->illegal_instr_o = 1U;
                    }
                } else {
                    vlSelf->illegal_instr_o = 1U;
                }
            } else if ((4U & (IData)(vlSelf->opcode_i))) {
                if ((2U & (IData)(vlSelf->opcode_i))) {
                    if ((1U & (~ (IData)(vlSelf->opcode_i)))) {
                        vlSelf->illegal_instr_o = 1U;
                    }
                } else {
                    vlSelf->illegal_instr_o = 1U;
                }
            } else if ((2U & (IData)(vlSelf->opcode_i))) {
                if ((1U & (IData)(vlSelf->opcode_i))) {
                    if ((1U & (~ ((IData)(vlSelf->funct3_i) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelf->funct3_i))) {
                            vlSelf->illegal_instr_o = 1U;
                        }
                    }
                } else {
                    vlSelf->illegal_instr_o = 1U;
                }
            } else {
                vlSelf->illegal_instr_o = 1U;
            }
        } else {
            vlSelf->illegal_instr_o = 1U;
        }
    } else {
        if ((0x20U & (IData)(vlSelf->opcode_i))) {
            if ((0x10U & (IData)(vlSelf->opcode_i))) {
                if ((1U & (~ ((IData)(vlSelf->opcode_i) 
                              >> 3U)))) {
                    if ((4U & (IData)(vlSelf->opcode_i))) {
                        if ((2U & (IData)(vlSelf->opcode_i))) {
                            if ((1U & (IData)(vlSelf->opcode_i))) {
                                vlSelf->alu_src2_sel_o = 2U;
                                vlSelf->rf_wen_o = 1U;
                                vlSelf->imm_type_o = 3U;
                            }
                        }
                    } else if ((2U & (IData)(vlSelf->opcode_i))) {
                        if ((1U & (IData)(vlSelf->opcode_i))) {
                            vlSelf->rf_wen_o = 1U;
                        }
                    }
                }
                if ((8U & (IData)(vlSelf->opcode_i))) {
                    vlSelf->illegal_instr_o = 1U;
                } else if ((4U & (IData)(vlSelf->opcode_i))) {
                    if ((2U & (IData)(vlSelf->opcode_i))) {
                        if ((1U & (~ (IData)(vlSelf->opcode_i)))) {
                            vlSelf->illegal_instr_o = 1U;
                        }
                    } else {
                        vlSelf->illegal_instr_o = 1U;
                    }
                } else if ((2U & (IData)(vlSelf->opcode_i))) {
                    if ((1U & (~ (IData)(vlSelf->opcode_i)))) {
                        vlSelf->illegal_instr_o = 1U;
                    }
                } else {
                    vlSelf->illegal_instr_o = 1U;
                }
            } else {
                if ((1U & (~ ((IData)(vlSelf->opcode_i) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelf->opcode_i) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelf->opcode_i))) {
                            if ((1U & (IData)(vlSelf->opcode_i))) {
                                vlSelf->alu_src2_sel_o = 1U;
                                vlSelf->imm_type_o = 1U;
                            }
                        }
                    }
                }
                if ((8U & (IData)(vlSelf->opcode_i))) {
                    vlSelf->illegal_instr_o = 1U;
                } else if ((4U & (IData)(vlSelf->opcode_i))) {
                    vlSelf->illegal_instr_o = 1U;
                } else if ((2U & (IData)(vlSelf->opcode_i))) {
                    if ((1U & (IData)(vlSelf->opcode_i))) {
                        if ((1U & (~ (((0U == (IData)(vlSelf->funct3_i)) 
                                       | (1U == (IData)(vlSelf->funct3_i))) 
                                      | (2U == (IData)(vlSelf->funct3_i)))))) {
                            vlSelf->illegal_instr_o = 1U;
                        }
                    } else {
                        vlSelf->illegal_instr_o = 1U;
                    }
                } else {
                    vlSelf->illegal_instr_o = 1U;
                }
            }
        } else if ((0x10U & (IData)(vlSelf->opcode_i))) {
            if ((1U & (~ ((IData)(vlSelf->opcode_i) 
                          >> 3U)))) {
                if ((4U & (IData)(vlSelf->opcode_i))) {
                    if ((2U & (IData)(vlSelf->opcode_i))) {
                        if ((1U & (IData)(vlSelf->opcode_i))) {
                            vlSelf->alu_src2_sel_o = 2U;
                            vlSelf->rf_wen_o = 1U;
                            vlSelf->imm_type_o = 3U;
                        }
                    }
                } else if ((2U & (IData)(vlSelf->opcode_i))) {
                    if ((1U & (IData)(vlSelf->opcode_i))) {
                        vlSelf->alu_src2_sel_o = 1U;
                        vlSelf->rf_wen_o = 1U;
                        vlSelf->imm_type_o = 0U;
                    }
                }
            }
            if ((8U & (IData)(vlSelf->opcode_i))) {
                vlSelf->illegal_instr_o = 1U;
            } else if ((4U & (IData)(vlSelf->opcode_i))) {
                if ((2U & (IData)(vlSelf->opcode_i))) {
                    if ((1U & (~ (IData)(vlSelf->opcode_i)))) {
                        vlSelf->illegal_instr_o = 1U;
                    }
                } else {
                    vlSelf->illegal_instr_o = 1U;
                }
            } else if ((2U & (IData)(vlSelf->opcode_i))) {
                if ((1U & (~ (IData)(vlSelf->opcode_i)))) {
                    vlSelf->illegal_instr_o = 1U;
                }
            } else {
                vlSelf->illegal_instr_o = 1U;
            }
        } else {
            if ((1U & (~ ((IData)(vlSelf->opcode_i) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelf->opcode_i) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlSelf->opcode_i))) {
                        if ((1U & (IData)(vlSelf->opcode_i))) {
                            vlSelf->alu_src2_sel_o = 1U;
                            vlSelf->rf_wen_o = 1U;
                            vlSelf->imm_type_o = 0U;
                        }
                    }
                }
            }
            if ((8U & (IData)(vlSelf->opcode_i))) {
                vlSelf->illegal_instr_o = 1U;
            } else if ((4U & (IData)(vlSelf->opcode_i))) {
                vlSelf->illegal_instr_o = 1U;
            } else if ((2U & (IData)(vlSelf->opcode_i))) {
                if ((1U & (IData)(vlSelf->opcode_i))) {
                    if ((4U & (IData)(vlSelf->funct3_i))) {
                        if ((2U & (IData)(vlSelf->funct3_i))) {
                            vlSelf->illegal_instr_o = 1U;
                        }
                    } else if ((2U & (IData)(vlSelf->funct3_i))) {
                        if ((1U & (IData)(vlSelf->funct3_i))) {
                            vlSelf->illegal_instr_o = 1U;
                        }
                    }
                } else {
                    vlSelf->illegal_instr_o = 1U;
                }
            } else {
                vlSelf->illegal_instr_o = 1U;
            }
        }
        if ((1U & (~ ((IData)(vlSelf->opcode_i) >> 5U)))) {
            if ((1U & (~ ((IData)(vlSelf->opcode_i) 
                          >> 4U)))) {
                if ((1U & (~ ((IData)(vlSelf->opcode_i) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelf->opcode_i) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelf->opcode_i))) {
                            if ((1U & (IData)(vlSelf->opcode_i))) {
                                vlSelf->rf_wdata_sel_o = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
}

void Vcontroller___024root___eval(Vcontroller___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontroller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller___024root___eval\n"); );
    // Body
    Vcontroller___024root___combo__TOP__0(vlSelf);
}

#ifdef VL_DEBUG
void Vcontroller___024root___eval_debug_assertions(Vcontroller___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontroller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk_i & 0xfeU))) {
        Verilated::overWidthError("clk_i");}
    if (VL_UNLIKELY((vlSelf->rst_ni & 0xfeU))) {
        Verilated::overWidthError("rst_ni");}
    if (VL_UNLIKELY((vlSelf->opcode_i & 0x80U))) {
        Verilated::overWidthError("opcode_i");}
    if (VL_UNLIKELY((vlSelf->funct3_i & 0xf8U))) {
        Verilated::overWidthError("funct3_i");}
    if (VL_UNLIKELY((vlSelf->funct7_i & 0x80U))) {
        Verilated::overWidthError("funct7_i");}
    if (VL_UNLIKELY((vlSelf->branch_eq_i & 0xfeU))) {
        Verilated::overWidthError("branch_eq_i");}
    if (VL_UNLIKELY((vlSelf->branch_lt_i & 0xfeU))) {
        Verilated::overWidthError("branch_lt_i");}
    if (VL_UNLIKELY((vlSelf->branch_ltu_i & 0xfeU))) {
        Verilated::overWidthError("branch_ltu_i");}
}
#endif  // VL_DEBUG
