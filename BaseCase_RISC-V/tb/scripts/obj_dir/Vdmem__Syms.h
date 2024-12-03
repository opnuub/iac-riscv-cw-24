// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VDMEM__SYMS_H_
#define VERILATED_VDMEM__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vdmem.h"

// INCLUDE MODULE CLASSES
#include "Vdmem___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vdmem__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vdmem* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vdmem___024root                TOP;

    // CONSTRUCTORS
    Vdmem__Syms(VerilatedContext* contextp, const char* namep, Vdmem* modelp);
    ~Vdmem__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
