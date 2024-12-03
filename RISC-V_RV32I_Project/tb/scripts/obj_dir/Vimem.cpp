// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vimem__pch.h"

//============================================================
// Constructors

Vimem::Vimem(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vimem__Syms(contextp(), _vcname__, this)}
    , clk_i{vlSymsp->TOP.clk_i}
    , addr_i{vlSymsp->TOP.addr_i}
    , rdata_o{vlSymsp->TOP.rdata_o}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vimem::Vimem(const char* _vcname__)
    : Vimem(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vimem::~Vimem() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vimem___024root___eval_debug_assertions(Vimem___024root* vlSelf);
#endif  // VL_DEBUG
void Vimem___024root___eval_static(Vimem___024root* vlSelf);
void Vimem___024root___eval_initial(Vimem___024root* vlSelf);
void Vimem___024root___eval_settle(Vimem___024root* vlSelf);
void Vimem___024root___eval(Vimem___024root* vlSelf);

void Vimem::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vimem::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vimem___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vimem___024root___eval_static(&(vlSymsp->TOP));
        Vimem___024root___eval_initial(&(vlSymsp->TOP));
        Vimem___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vimem___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vimem::eventsPending() { return false; }

uint64_t Vimem::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vimem::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vimem___024root___eval_final(Vimem___024root* vlSelf);

VL_ATTR_COLD void Vimem::final() {
    Vimem___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vimem::hierName() const { return vlSymsp->name(); }
const char* Vimem::modelName() const { return "Vimem"; }
unsigned Vimem::threads() const { return 1; }
void Vimem::prepareClone() const { contextp()->prepareClone(); }
void Vimem::atClone() const {
    contextp()->threadPoolpOnClone();
}
