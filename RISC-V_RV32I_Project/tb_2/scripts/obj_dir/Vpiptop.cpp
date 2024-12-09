// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vpiptop.h"
#include "Vpiptop__Syms.h"

//============================================================
// Constructors

Vpiptop::Vpiptop(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vpiptop__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , trigger{vlSymsp->TOP.trigger}
    , a0{vlSymsp->TOP.a0}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vpiptop::Vpiptop(const char* _vcname__)
    : Vpiptop(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vpiptop::~Vpiptop() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vpiptop___024root___eval_initial(Vpiptop___024root* vlSelf);
void Vpiptop___024root___eval_settle(Vpiptop___024root* vlSelf);
void Vpiptop___024root___eval(Vpiptop___024root* vlSelf);
#ifdef VL_DEBUG
void Vpiptop___024root___eval_debug_assertions(Vpiptop___024root* vlSelf);
#endif  // VL_DEBUG
void Vpiptop___024root___final(Vpiptop___024root* vlSelf);

static void _eval_initial_loop(Vpiptop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vpiptop___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vpiptop___024root___eval_settle(&(vlSymsp->TOP));
        Vpiptop___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vpiptop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vpiptop::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vpiptop___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vpiptop___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vpiptop::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vpiptop::final() {
    Vpiptop___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vpiptop::hierName() const { return vlSymsp->name(); }
const char* Vpiptop::modelName() const { return "Vpiptop"; }
unsigned Vpiptop::threads() const { return 1; }
