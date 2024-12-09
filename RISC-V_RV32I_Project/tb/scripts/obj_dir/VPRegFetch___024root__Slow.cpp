// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPRegFetch.h for the primary calling header

#include "VPRegFetch__pch.h"
#include "VPRegFetch__Syms.h"
#include "VPRegFetch___024root.h"

void VPRegFetch___024root___ctor_var_reset(VPRegFetch___024root* vlSelf);

VPRegFetch___024root::VPRegFetch___024root(VPRegFetch__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VPRegFetch___024root___ctor_var_reset(this);
}

void VPRegFetch___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VPRegFetch___024root::~VPRegFetch___024root() {
}
