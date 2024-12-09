// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VL2Cache__pch.h"
#include "VL2Cache.h"
#include "VL2Cache___024root.h"

// FUNCTIONS
VL2Cache__Syms::~VL2Cache__Syms()
{
}

VL2Cache__Syms::VL2Cache__Syms(VerilatedContext* contextp, const char* namep, VL2Cache* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(87);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
