// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VPRegFetch.h"
#include "VPRegFetch__Syms.h"

//============================================================
// Constructors

VPRegFetch::VPRegFetch(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VPRegFetch__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , instr{vlSymsp->TOP.instr}
    , PCf{vlSymsp->TOP.PCf}
    , PCPlus4F{vlSymsp->TOP.PCPlus4F}
    , PCPlus4D{vlSymsp->TOP.PCPlus4D}
    , PCd{vlSymsp->TOP.PCd}
    , InstrD{vlSymsp->TOP.InstrD}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VPRegFetch::VPRegFetch(const char* _vcname__)
    : VPRegFetch(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VPRegFetch::~VPRegFetch() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void VPRegFetch___024root___eval_initial(VPRegFetch___024root* vlSelf);
void VPRegFetch___024root___eval_settle(VPRegFetch___024root* vlSelf);
void VPRegFetch___024root___eval(VPRegFetch___024root* vlSelf);
#ifdef VL_DEBUG
void VPRegFetch___024root___eval_debug_assertions(VPRegFetch___024root* vlSelf);
#endif  // VL_DEBUG
void VPRegFetch___024root___final(VPRegFetch___024root* vlSelf);

static void _eval_initial_loop(VPRegFetch__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    VPRegFetch___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        VPRegFetch___024root___eval_settle(&(vlSymsp->TOP));
        VPRegFetch___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void VPRegFetch::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VPRegFetch::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VPRegFetch___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        VPRegFetch___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* VPRegFetch::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void VPRegFetch::final() {
    VPRegFetch___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VPRegFetch::hierName() const { return vlSymsp->name(); }
const char* VPRegFetch::modelName() const { return "VPRegFetch"; }
unsigned VPRegFetch::threads() const { return 1; }
