// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vregfile.h"
#include "Vregfile__Syms.h"

//============================================================
// Constructors

Vregfile::Vregfile(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vregfile__Syms(contextp(), _vcname__, this)}
    , clk_i{vlSymsp->TOP.clk_i}
    , rst_ni{vlSymsp->TOP.rst_ni}
    , wen_i{vlSymsp->TOP.wen_i}
    , waddr_i{vlSymsp->TOP.waddr_i}
    , raddr1_i{vlSymsp->TOP.raddr1_i}
    , raddr2_i{vlSymsp->TOP.raddr2_i}
    , wdata_i{vlSymsp->TOP.wdata_i}
    , rdata1_o{vlSymsp->TOP.rdata1_o}
    , rdata2_o{vlSymsp->TOP.rdata2_o}
    , a0_o{vlSymsp->TOP.a0_o}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vregfile::Vregfile(const char* _vcname__)
    : Vregfile(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vregfile::~Vregfile() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vregfile___024root___eval_initial(Vregfile___024root* vlSelf);
void Vregfile___024root___eval_settle(Vregfile___024root* vlSelf);
void Vregfile___024root___eval(Vregfile___024root* vlSelf);
#ifdef VL_DEBUG
void Vregfile___024root___eval_debug_assertions(Vregfile___024root* vlSelf);
#endif  // VL_DEBUG
void Vregfile___024root___final(Vregfile___024root* vlSelf);

static void _eval_initial_loop(Vregfile__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vregfile___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vregfile___024root___eval_settle(&(vlSymsp->TOP));
        Vregfile___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vregfile::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vregfile::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vregfile___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vregfile___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vregfile::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vregfile::final() {
    Vregfile___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vregfile::hierName() const { return vlSymsp->name(); }
const char* Vregfile::modelName() const { return "Vregfile"; }
unsigned Vregfile::threads() const { return 1; }
