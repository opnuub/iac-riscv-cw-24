// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VL2Cache.h for the primary calling header

#include "VL2Cache__pch.h"
#include "VL2Cache__Syms.h"
#include "VL2Cache___024root.h"

void VL2Cache___024root___ctor_var_reset(VL2Cache___024root* vlSelf);

VL2Cache___024root::VL2Cache___024root(VL2Cache__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VL2Cache___024root___ctor_var_reset(this);
}

void VL2Cache___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VL2Cache___024root::~VL2Cache___024root() {
}
