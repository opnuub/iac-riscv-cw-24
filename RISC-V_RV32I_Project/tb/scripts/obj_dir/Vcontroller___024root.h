// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vcontroller.h for the primary calling header

#ifndef VERILATED_VCONTROLLER___024ROOT_H_
#define VERILATED_VCONTROLLER___024ROOT_H_  // guard

#include "verilated.h"

class Vcontroller__Syms;

class Vcontroller___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk_i,0,0);
    VL_IN8(rst_ni,0,0);
    VL_IN8(opcode_i,6,0);
    VL_IN8(funct3_i,2,0);
    VL_IN8(funct7_i,6,0);
    VL_IN8(branch_eq_i,0,0);
    VL_IN8(branch_lt_i,0,0);
    VL_IN8(branch_ltu_i,0,0);
    VL_OUT8(rf_wen_o,0,0);
    VL_OUT8(rf_wdata_sel_o,1,0);
    VL_OUT8(alu_op_o,3,0);
    VL_OUT8(alu_src1_sel_o,1,0);
    VL_OUT8(alu_src2_sel_o,1,0);
    VL_OUT8(mem_wen_o,0,0);
    VL_OUT8(mem_size_o,2,0);
    VL_OUT8(mem_signed_o,0,0);
    VL_OUT8(imm_type_o,2,0);
    VL_OUT8(next_pc_sel_o,2,0);
    VL_OUT8(illegal_instr_o,0,0);

    // INTERNAL VARIABLES
    Vcontroller__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vcontroller___024root(Vcontroller__Syms* symsp, const char* name);
    ~Vcontroller___024root();
    VL_UNCOPYABLE(Vcontroller___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
