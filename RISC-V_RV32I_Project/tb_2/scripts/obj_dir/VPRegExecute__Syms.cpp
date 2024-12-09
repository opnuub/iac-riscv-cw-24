// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VPRegExecute__Syms.h"
#include "VPRegExecute.h"
#include "VPRegExecute___024root.h"

// FUNCTIONS
VPRegExecute__Syms::~VPRegExecute__Syms()
{
}

VPRegExecute__Syms::VPRegExecute__Syms(VerilatedContext* contextp, const char* namep, VPRegExecute* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
