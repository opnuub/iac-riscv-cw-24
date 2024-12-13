// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vimem.h for the primary calling header

#include "Vimem__pch.h"
#include "Vimem__Syms.h"
#include "Vimem___024root.h"

void Vimem___024root___ctor_var_reset(Vimem___024root* vlSelf);

Vimem___024root::Vimem___024root(Vimem__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vimem___024root___ctor_var_reset(this);
}

void Vimem___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vimem___024root::~Vimem___024root() {
}
