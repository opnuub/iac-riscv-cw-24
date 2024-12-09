// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VPREGFETCH__SYMS_H_
#define VERILATED_VPREGFETCH__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VPRegFetch.h"

// INCLUDE MODULE CLASSES
#include "VPRegFetch___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)VPRegFetch__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VPRegFetch* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VPRegFetch___024root           TOP;

    // CONSTRUCTORS
    VPRegFetch__Syms(VerilatedContext* contextp, const char* namep, VPRegFetch* modelp);
    ~VPRegFetch__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
