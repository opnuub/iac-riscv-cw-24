// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpcunit.h for the primary calling header

#include "Vpcunit__pch.h"
#include "Vpcunit__Syms.h"
#include "Vpcunit___024root.h"

void Vpcunit___024root___ctor_var_reset(Vpcunit___024root* vlSelf);

Vpcunit___024root::Vpcunit___024root(Vpcunit__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vpcunit___024root___ctor_var_reset(this);
}

void Vpcunit___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vpcunit___024root::~Vpcunit___024root() {
}
