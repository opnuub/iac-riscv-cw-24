// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VPCTOP__SYMS_H_
#define VERILATED_VPCTOP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VPCtop.h"

// INCLUDE MODULE CLASSES
#include "VPCtop___024root.h"

// SYMS CLASS (contains all model state)
class VPCtop__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VPCtop* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VPCtop___024root               TOP;

    // CONSTRUCTORS
    VPCtop__Syms(VerilatedContext* contextp, const char* namep, VPCtop* modelp);
    ~VPCtop__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
