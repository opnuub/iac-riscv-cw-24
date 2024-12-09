// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VPRegFetch__pch.h"

//============================================================
// Constructors

VPRegFetch::VPRegFetch(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VPRegFetch__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , FlushF{vlSymsp->TOP.FlushF}
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
// Evaluation function

#ifdef VL_DEBUG
void VPRegFetch___024root___eval_debug_assertions(VPRegFetch___024root* vlSelf);
#endif  // VL_DEBUG
void VPRegFetch___024root___eval_static(VPRegFetch___024root* vlSelf);
void VPRegFetch___024root___eval_initial(VPRegFetch___024root* vlSelf);
void VPRegFetch___024root___eval_settle(VPRegFetch___024root* vlSelf);
void VPRegFetch___024root___eval(VPRegFetch___024root* vlSelf);

void VPRegFetch::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VPRegFetch::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VPRegFetch___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VPRegFetch___024root___eval_static(&(vlSymsp->TOP));
        VPRegFetch___024root___eval_initial(&(vlSymsp->TOP));
        VPRegFetch___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VPRegFetch___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VPRegFetch::eventsPending() { return false; }

uint64_t VPRegFetch::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VPRegFetch::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VPRegFetch___024root___eval_final(VPRegFetch___024root* vlSelf);

VL_ATTR_COLD void VPRegFetch::final() {
    VPRegFetch___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VPRegFetch::hierName() const { return vlSymsp->name(); }
const char* VPRegFetch::modelName() const { return "VPRegFetch"; }
unsigned VPRegFetch::threads() const { return 1; }
void VPRegFetch::prepareClone() const { contextp()->prepareClone(); }
void VPRegFetch::atClone() const {
    contextp()->threadPoolpOnClone();
}
