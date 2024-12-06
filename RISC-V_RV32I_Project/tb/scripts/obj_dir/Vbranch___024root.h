// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vbranch.h for the primary calling header

#ifndef VERILATED_VBRANCH___024ROOT_H_
#define VERILATED_VBRANCH___024ROOT_H_  // guard

#include "verilated.h"

class Vbranch__Syms;

class Vbranch___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(funct3_i,2,0);
    VL_OUT8(branch_taken_o,0,0);
    VL_OUT8(branch_eq_o,0,0);
    VL_OUT8(branch_lt_o,0,0);
    VL_OUT8(branch_ltu_o,0,0);
    VL_IN(rs1_data_i,31,0);
    VL_IN(rs2_data_i,31,0);

    // INTERNAL VARIABLES
    Vbranch__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vbranch___024root(Vbranch__Syms* symsp, const char* name);
    ~Vbranch___024root();
    VL_UNCOPYABLE(Vbranch___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
