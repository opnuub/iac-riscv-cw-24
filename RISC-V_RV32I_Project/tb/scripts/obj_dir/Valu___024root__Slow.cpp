// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Valu.h for the primary calling header

<<<<<<< HEAD
#include "verilated.h"

=======
#include "Valu__pch.h"
>>>>>>> e196d578041264977e0c3743a08c2822d1681fa1
#include "Valu__Syms.h"
#include "Valu___024root.h"

void Valu___024root___ctor_var_reset(Valu___024root* vlSelf);

Valu___024root::Valu___024root(Valu__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Valu___024root___ctor_var_reset(this);
}

void Valu___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Valu___024root::~Valu___024root() {
}
