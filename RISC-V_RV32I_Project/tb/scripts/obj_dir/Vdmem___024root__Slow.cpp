// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdmem.h for the primary calling header

#include "Vdmem__pch.h"
#include "Vdmem__Syms.h"
#include "Vdmem___024root.h"

void Vdmem___024root___ctor_var_reset(Vdmem___024root* vlSelf);

Vdmem___024root::Vdmem___024root(Vdmem__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vdmem___024root___ctor_var_reset(this);
}

void Vdmem___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vdmem___024root::~Vdmem___024root() {
}
