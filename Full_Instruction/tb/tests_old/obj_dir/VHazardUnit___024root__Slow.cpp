// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VHazardUnit.h for the primary calling header

#include "VHazardUnit__pch.h"
#include "VHazardUnit__Syms.h"
#include "VHazardUnit___024root.h"

void VHazardUnit___024root___ctor_var_reset(VHazardUnit___024root* vlSelf);

VHazardUnit___024root::VHazardUnit___024root(VHazardUnit__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VHazardUnit___024root___ctor_var_reset(this);
}

void VHazardUnit___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VHazardUnit___024root::~VHazardUnit___024root() {
}
