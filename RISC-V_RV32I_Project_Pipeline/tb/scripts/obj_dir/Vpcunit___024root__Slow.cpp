// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpcunit.h for the primary calling header

#include "verilated.h"

#include "Vpcunit__Syms.h"
#include "Vpcunit___024root.h"

void Vpcunit___024root___ctor_var_reset(Vpcunit___024root* vlSelf);

Vpcunit___024root::Vpcunit___024root(Vpcunit__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vpcunit___024root___ctor_var_reset(this);
}

void Vpcunit___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vpcunit___024root::~Vpcunit___024root() {
}
