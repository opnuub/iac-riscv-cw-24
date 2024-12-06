// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vpcunit.h"
#include "Vpcunit__Syms.h"

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
// Evaluation loop

void Vpcunit___024root___eval_initial(Vpcunit___024root* vlSelf);
void Vpcunit___024root___eval_settle(Vpcunit___024root* vlSelf);
void Vpcunit___024root___eval(Vpcunit___024root* vlSelf);
#ifdef VL_DEBUG
void Vpcunit___024root___eval_debug_assertions(Vpcunit___024root* vlSelf);
#endif  // VL_DEBUG
void Vpcunit___024root___final(Vpcunit___024root* vlSelf);

static void _eval_initial_loop(Vpcunit__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vpcunit___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vpcunit___024root___eval_settle(&(vlSymsp->TOP));
        Vpcunit___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vpcunit::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vpcunit::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vpcunit___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vpcunit___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vpcunit::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vpcunit::final() {
    Vpcunit___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vpcunit::hierName() const { return vlSymsp->name(); }
const char* Vpcunit::modelName() const { return "Vpcunit"; }
unsigned Vpcunit::threads() const { return 1; }
