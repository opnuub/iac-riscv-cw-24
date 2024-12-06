// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VDATAMEMORY__SYMS_H_
#define VERILATED_VDATAMEMORY__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VDataMemory.h"

// INCLUDE MODULE CLASSES
#include "VDataMemory___024root.h"

// SYMS CLASS (contains all model state)
class VDataMemory__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VDataMemory* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VDataMemory___024root          TOP;

    // CONSTRUCTORS
    VDataMemory__Syms(VerilatedContext* contextp, const char* namep, VDataMemory* modelp);
    ~VDataMemory__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
