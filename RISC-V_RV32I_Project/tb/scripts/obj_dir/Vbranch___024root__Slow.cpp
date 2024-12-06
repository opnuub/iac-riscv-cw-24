// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbranch.h for the primary calling header

#include "verilated.h"

#include "Vbranch__Syms.h"
#include "Vbranch___024root.h"

void Vbranch___024root___ctor_var_reset(Vbranch___024root* vlSelf);

Vbranch___024root::Vbranch___024root(Vbranch__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vbranch___024root___ctor_var_reset(this);
}

void Vbranch___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vbranch___024root::~Vbranch___024root() {
}
