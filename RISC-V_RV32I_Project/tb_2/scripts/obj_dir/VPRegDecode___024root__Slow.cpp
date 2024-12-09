// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPRegDecode.h for the primary calling header

#include "verilated.h"

#include "VPRegDecode__Syms.h"
#include "VPRegDecode___024root.h"

void VPRegDecode___024root___ctor_var_reset(VPRegDecode___024root* vlSelf);

VPRegDecode___024root::VPRegDecode___024root(VPRegDecode__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VPRegDecode___024root___ctor_var_reset(this);
}

void VPRegDecode___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

VPRegDecode___024root::~VPRegDecode___024root() {
}
