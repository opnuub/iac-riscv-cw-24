// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VBRANCH__SYMS_H_
#define VERILATED_VBRANCH__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vbranch.h"

// INCLUDE MODULE CLASSES
#include "Vbranch___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vbranch__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vbranch* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vbranch___024root              TOP;

    // CONSTRUCTORS
    Vbranch__Syms(VerilatedContext* contextp, const char* namep, Vbranch* modelp);
    ~Vbranch__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
