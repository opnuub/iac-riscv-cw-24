// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VPREGDECODE__SYMS_H_
#define VERILATED_VPREGDECODE__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VPRegDecode.h"

// INCLUDE MODULE CLASSES
#include "VPRegDecode___024root.h"

// SYMS CLASS (contains all model state)
class VPRegDecode__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VPRegDecode* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VPRegDecode___024root          TOP;

    // CONSTRUCTORS
    VPRegDecode__Syms(VerilatedContext* contextp, const char* namep, VPRegDecode* modelp);
    ~VPRegDecode__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
