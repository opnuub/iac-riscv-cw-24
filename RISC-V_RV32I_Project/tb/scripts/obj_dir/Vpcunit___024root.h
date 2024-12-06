// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vpcunit.h for the primary calling header

#ifndef VERILATED_VPCUNIT___024ROOT_H_
#define VERILATED_VPCUNIT___024ROOT_H_  // guard

#include "verilated.h"

class Vpcunit__Syms;

class Vpcunit___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk_i,0,0);
    VL_IN8(rst_ni,0,0);
    VL_IN8(next_pc_sel_i,2,0);
    CData/*0:0*/ __Vclklast__TOP__clk_i;
    CData/*0:0*/ __Vclklast__TOP__rst_ni;
    VL_IN(alu_result_i,31,0);
    VL_IN(imm_i,31,0);
    VL_OUT(pc_o,31,0);
    VL_OUT(next_pc_o,31,0);
    IData/*31:0*/ pcunit__DOT__pc_q;

    // INTERNAL VARIABLES
    Vpcunit__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vpcunit___024root(Vpcunit__Syms* symsp, const char* name);
    ~Vpcunit___024root();
    VL_UNCOPYABLE(Vpcunit___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
