// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vbranch.h"
#include "Vbranch__Syms.h"

//============================================================
// Constructors

Vbranch::Vbranch(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vbranch__Syms(contextp(), _vcname__, this)}
    , funct3_i{vlSymsp->TOP.funct3_i}
    , branch_taken_o{vlSymsp->TOP.branch_taken_o}
    , branch_eq_o{vlSymsp->TOP.branch_eq_o}
    , branch_lt_o{vlSymsp->TOP.branch_lt_o}
    , branch_ltu_o{vlSymsp->TOP.branch_ltu_o}
    , rs1_data_i{vlSymsp->TOP.rs1_data_i}
    , rs2_data_i{vlSymsp->TOP.rs2_data_i}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vbranch::Vbranch(const char* _vcname__)
    : Vbranch(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vbranch::~Vbranch() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vbranch___024root___eval_initial(Vbranch___024root* vlSelf);
void Vbranch___024root___eval_settle(Vbranch___024root* vlSelf);
void Vbranch___024root___eval(Vbranch___024root* vlSelf);
#ifdef VL_DEBUG
void Vbranch___024root___eval_debug_assertions(Vbranch___024root* vlSelf);
#endif  // VL_DEBUG
void Vbranch___024root___final(Vbranch___024root* vlSelf);

static void _eval_initial_loop(Vbranch__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vbranch___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vbranch___024root___eval_settle(&(vlSymsp->TOP));
        Vbranch___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vbranch::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vbranch::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vbranch___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vbranch___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vbranch::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vbranch::final() {
    Vbranch___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vbranch::hierName() const { return vlSymsp->name(); }
const char* Vbranch::modelName() const { return "Vbranch"; }
unsigned Vbranch::threads() const { return 1; }
