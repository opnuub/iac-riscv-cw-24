// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpiptop.h for the primary calling header

#include "verilated.h"

#include "Vpiptop__Syms.h"
#include "Vpiptop___024root.h"

void Vpiptop___024root___ctor_var_reset(Vpiptop___024root* vlSelf);

Vpiptop___024root::Vpiptop___024root(Vpiptop__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vpiptop___024root___ctor_var_reset(this);
}

void Vpiptop___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vpiptop___024root::~Vpiptop___024root() {
}
