// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vpcunit__pch.h"

//============================================================
// Constructors

Vpcunit::Vpcunit(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vpcunit__Syms(contextp(), _vcname__, this)}
    , clk_i{vlSymsp->TOP.clk_i}
    , rst_ni{vlSymsp->TOP.rst_ni}
    , next_pc_sel_i{vlSymsp->TOP.next_pc_sel_i}
    , alu_result_i{vlSymsp->TOP.alu_result_i}
    , imm_i{vlSymsp->TOP.imm_i}
    , pc_o{vlSymsp->TOP.pc_o}
    , next_pc_o{vlSymsp->TOP.next_pc_o}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vpcunit::Vpcunit(const char* _vcname__)
    : Vpcunit(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vpcunit::~Vpcunit() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vpcunit___024root___eval_debug_assertions(Vpcunit___024root* vlSelf);
#endif  // VL_DEBUG
void Vpcunit___024root___eval_static(Vpcunit___024root* vlSelf);
void Vpcunit___024root___eval_initial(Vpcunit___024root* vlSelf);
void Vpcunit___024root___eval_settle(Vpcunit___024root* vlSelf);
void Vpcunit___024root___eval(Vpcunit___024root* vlSelf);

void Vpcunit::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vpcunit::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vpcunit___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vpcunit___024root___eval_static(&(vlSymsp->TOP));
        Vpcunit___024root___eval_initial(&(vlSymsp->TOP));
        Vpcunit___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vpcunit___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vpcunit::eventsPending() { return false; }

uint64_t Vpcunit::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vpcunit::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vpcunit___024root___eval_final(Vpcunit___024root* vlSelf);

VL_ATTR_COLD void Vpcunit::final() {
    Vpcunit___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vpcunit::hierName() const { return vlSymsp->name(); }
const char* Vpcunit::modelName() const { return "Vpcunit"; }
unsigned Vpcunit::threads() const { return 1; }
void Vpcunit::prepareClone() const { contextp()->prepareClone(); }
void Vpcunit::atClone() const {
    contextp()->threadPoolpOnClone();
}
