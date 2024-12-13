// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VPCUNIT__SYMS_H_
#define VERILATED_VPCUNIT__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vpcunit.h"

// INCLUDE MODULE CLASSES
#include "Vpcunit___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vpcunit__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vpcunit* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vpcunit___024root              TOP;

    // CONSTRUCTORS
    Vpcunit__Syms(VerilatedContext* contextp, const char* namep, Vpcunit* modelp);
    ~Vpcunit__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
