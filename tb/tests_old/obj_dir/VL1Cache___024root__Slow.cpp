// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VL1Cache.h for the primary calling header

#include "VL1Cache__pch.h"
#include "VL1Cache__Syms.h"
#include "VL1Cache___024root.h"

void VL1Cache___024root___ctor_var_reset(VL1Cache___024root* vlSelf);

VL1Cache___024root::VL1Cache___024root(VL1Cache__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VL1Cache___024root___ctor_var_reset(this);
}

void VL1Cache___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VL1Cache___024root::~VL1Cache___024root() {
}
