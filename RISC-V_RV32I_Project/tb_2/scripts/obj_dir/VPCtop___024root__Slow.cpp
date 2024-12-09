// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPCtop.h for the primary calling header

#include "verilated.h"

#include "VPCtop__Syms.h"
#include "VPCtop___024root.h"

void VPCtop___024root___ctor_var_reset(VPCtop___024root* vlSelf);

VPCtop___024root::VPCtop___024root(VPCtop__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VPCtop___024root___ctor_var_reset(this);
}

void VPCtop___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

VPCtop___024root::~VPCtop___024root() {
}
