// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VPIPTOP__SYMS_H_
#define VERILATED_VPIPTOP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vpiptop.h"

// INCLUDE MODULE CLASSES
#include "Vpiptop___024root.h"

// SYMS CLASS (contains all model state)
class Vpiptop__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vpiptop* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vpiptop___024root              TOP;

    // CONSTRUCTORS
    Vpiptop__Syms(VerilatedContext* contextp, const char* namep, Vpiptop* modelp);
    ~Vpiptop__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
