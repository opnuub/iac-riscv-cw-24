// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcontroller.h for the primary calling header

#include "verilated.h"

#include "Vcontroller___024root.h"

VL_ATTR_COLD void Vcontroller___024root___eval_initial(Vcontroller___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontroller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller___024root___eval_initial\n"); );
}

void Vcontroller___024root___combo__TOP__0(Vcontroller___024root* vlSelf);

VL_ATTR_COLD void Vcontroller___024root___eval_settle(Vcontroller___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontroller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller___024root___eval_settle\n"); );
    // Body
    Vcontroller___024root___combo__TOP__0(vlSelf);
}

VL_ATTR_COLD void Vcontroller___024root___final(Vcontroller___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontroller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller___024root___final\n"); );
}

VL_ATTR_COLD void Vcontroller___024root___ctor_var_reset(Vcontroller___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontroller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk_i = VL_RAND_RESET_I(1);
    vlSelf->rst_ni = VL_RAND_RESET_I(1);
    vlSelf->opcode_i = VL_RAND_RESET_I(7);
    vlSelf->funct3_i = VL_RAND_RESET_I(3);
    vlSelf->funct7_i = VL_RAND_RESET_I(7);
    vlSelf->branch_eq_i = VL_RAND_RESET_I(1);
    vlSelf->branch_lt_i = VL_RAND_RESET_I(1);
    vlSelf->branch_ltu_i = VL_RAND_RESET_I(1);
    vlSelf->rf_wen_o = VL_RAND_RESET_I(1);
    vlSelf->rf_wdata_sel_o = VL_RAND_RESET_I(2);
    vlSelf->alu_op_o = VL_RAND_RESET_I(4);
    vlSelf->alu_src1_sel_o = VL_RAND_RESET_I(2);
    vlSelf->alu_src2_sel_o = VL_RAND_RESET_I(2);
    vlSelf->mem_wen_o = VL_RAND_RESET_I(1);
    vlSelf->mem_size_o = VL_RAND_RESET_I(3);
    vlSelf->mem_signed_o = VL_RAND_RESET_I(1);
    vlSelf->imm_type_o = VL_RAND_RESET_I(3);
    vlSelf->next_pc_sel_o = VL_RAND_RESET_I(3);
    vlSelf->illegal_instr_o = VL_RAND_RESET_I(1);
}
