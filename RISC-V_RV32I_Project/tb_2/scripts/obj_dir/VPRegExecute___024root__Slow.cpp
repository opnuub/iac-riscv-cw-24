// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPRegExecute.h for the primary calling header

#include "verilated.h"

#include "VPRegExecute__Syms.h"
#include "VPRegExecute___024root.h"

void VPRegExecute___024root___ctor_var_reset(VPRegExecute___024root* vlSelf);

VPRegExecute___024root::VPRegExecute___024root(VPRegExecute__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VPRegExecute___024root___ctor_var_reset(this);
}

void VPRegExecute___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

VPRegExecute___024root::~VPRegExecute___024root() {
}
