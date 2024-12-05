// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VIMEM__SYMS_H_
#define VERILATED_VIMEM__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vimem.h"

// INCLUDE MODULE CLASSES
#include "Vimem___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vimem__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vimem* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vimem___024root                TOP;

    // CONSTRUCTORS
    Vimem__Syms(VerilatedContext* contextp, const char* namep, Vimem* modelp);
    ~Vimem__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
