// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vimem.h"
#include "Vimem__Syms.h"

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
// Evaluation loop

void Vimem___024root___eval_initial(Vimem___024root* vlSelf);
void Vimem___024root___eval_settle(Vimem___024root* vlSelf);
void Vimem___024root___eval(Vimem___024root* vlSelf);
#ifdef VL_DEBUG
void Vimem___024root___eval_debug_assertions(Vimem___024root* vlSelf);
#endif  // VL_DEBUG
void Vimem___024root___final(Vimem___024root* vlSelf);

static void _eval_initial_loop(Vimem__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vimem___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vimem___024root___eval_settle(&(vlSymsp->TOP));
        Vimem___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vimem::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vimem::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vimem___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vimem___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vimem::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vimem::final() {
    Vimem___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vimem::hierName() const { return vlSymsp->name(); }
const char* Vimem::modelName() const { return "Vimem"; }
unsigned Vimem::threads() const { return 1; }
