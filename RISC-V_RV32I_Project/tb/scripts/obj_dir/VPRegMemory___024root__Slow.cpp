// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPRegMemory.h for the primary calling header

#include "verilated.h"

#include "VPRegMemory__Syms.h"
#include "VPRegMemory___024root.h"

void VPRegMemory___024root___ctor_var_reset(VPRegMemory___024root* vlSelf);

VPRegMemory___024root::VPRegMemory___024root(VPRegMemory__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VPRegMemory___024root___ctor_var_reset(this);
}

void VPRegMemory___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

VPRegMemory___024root::~VPRegMemory___024root() {
}
