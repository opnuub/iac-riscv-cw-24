// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VbranchUnit.h for the primary calling header

#include "VbranchUnit__pch.h"
#include "VbranchUnit__Syms.h"
#include "VbranchUnit___024root.h"

void VbranchUnit___024root___ctor_var_reset(VbranchUnit___024root* vlSelf);

VbranchUnit___024root::VbranchUnit___024root(VbranchUnit__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VbranchUnit___024root___ctor_var_reset(this);
}

void VbranchUnit___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VbranchUnit___024root::~VbranchUnit___024root() {
}
