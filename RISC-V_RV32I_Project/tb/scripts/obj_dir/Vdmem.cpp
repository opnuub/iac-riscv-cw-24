// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vdmem__pch.h"

//============================================================
// Constructors

Vdmem::Vdmem(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vdmem__Syms(contextp(), _vcname__, this)}
    , clk_i{vlSymsp->TOP.clk_i}
    , rst_ni{vlSymsp->TOP.rst_ni}
    , wen_i{vlSymsp->TOP.wen_i}
    , size_i{vlSymsp->TOP.size_i}
    , signed_i{vlSymsp->TOP.signed_i}
    , addr_i{vlSymsp->TOP.addr_i}
    , wdata_i{vlSymsp->TOP.wdata_i}
    , rdata_o{vlSymsp->TOP.rdata_o}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vdmem::Vdmem(const char* _vcname__)
    : Vdmem(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vdmem::~Vdmem() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vdmem___024root___eval_debug_assertions(Vdmem___024root* vlSelf);
#endif  // VL_DEBUG
void Vdmem___024root___eval_static(Vdmem___024root* vlSelf);
void Vdmem___024root___eval_initial(Vdmem___024root* vlSelf);
void Vdmem___024root___eval_settle(Vdmem___024root* vlSelf);
void Vdmem___024root___eval(Vdmem___024root* vlSelf);

void Vdmem::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vdmem::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vdmem___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vdmem___024root___eval_static(&(vlSymsp->TOP));
        Vdmem___024root___eval_initial(&(vlSymsp->TOP));
        Vdmem___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vdmem___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vdmem::eventsPending() { return false; }

uint64_t Vdmem::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vdmem::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vdmem___024root___eval_final(Vdmem___024root* vlSelf);

VL_ATTR_COLD void Vdmem::final() {
    Vdmem___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vdmem::hierName() const { return vlSymsp->name(); }
const char* Vdmem::modelName() const { return "Vdmem"; }
unsigned Vdmem::threads() const { return 1; }
void Vdmem::prepareClone() const { contextp()->prepareClone(); }
void Vdmem::atClone() const {
    contextp()->threadPoolpOnClone();
}
