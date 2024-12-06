// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VPREGMEMORY__SYMS_H_
#define VERILATED_VPREGMEMORY__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VPRegMemory.h"

// INCLUDE MODULE CLASSES
#include "VPRegMemory___024root.h"

// SYMS CLASS (contains all model state)
class VPRegMemory__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VPRegMemory* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VPRegMemory___024root          TOP;

    // CONSTRUCTORS
    VPRegMemory__Syms(VerilatedContext* contextp, const char* namep, VPRegMemory* modelp);
    ~VPRegMemory__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
