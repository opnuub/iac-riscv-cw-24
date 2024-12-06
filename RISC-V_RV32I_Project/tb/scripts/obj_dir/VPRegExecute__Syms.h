// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VPREGEXECUTE__SYMS_H_
#define VERILATED_VPREGEXECUTE__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VPRegExecute.h"

// INCLUDE MODULE CLASSES
#include "VPRegExecute___024root.h"

// SYMS CLASS (contains all model state)
class VPRegExecute__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VPRegExecute* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VPRegExecute___024root         TOP;

    // CONSTRUCTORS
    VPRegExecute__Syms(VerilatedContext* contextp, const char* namep, VPRegExecute* modelp);
    ~VPRegExecute__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
