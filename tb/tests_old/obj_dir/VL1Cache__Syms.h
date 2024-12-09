// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VL1CACHE__SYMS_H_
#define VERILATED_VL1CACHE__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VL1Cache.h"

// INCLUDE MODULE CLASSES
#include "VL1Cache___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)VL1Cache__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VL1Cache* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VL1Cache___024root             TOP;

    // CONSTRUCTORS
    VL1Cache__Syms(VerilatedContext* contextp, const char* namep, VL1Cache* modelp);
    ~VL1Cache__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
