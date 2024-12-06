// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VDataMemory.h for the primary calling header

#include "verilated.h"

#include "VDataMemory__Syms.h"
#include "VDataMemory___024root.h"

void VDataMemory___024root___ctor_var_reset(VDataMemory___024root* vlSelf);

VDataMemory___024root::VDataMemory___024root(VDataMemory__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VDataMemory___024root___ctor_var_reset(this);
}

void VDataMemory___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

VDataMemory___024root::~VDataMemory___024root() {
}
