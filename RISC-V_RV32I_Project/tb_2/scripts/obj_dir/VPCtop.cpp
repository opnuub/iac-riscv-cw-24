// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VPCtop.h"
#include "VPCtop__Syms.h"

//============================================================
// Constructors

VPCtop::VPCtop(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VPCtop__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , PCsrcE{vlSymsp->TOP.PCsrcE}
    , PCTargetE{vlSymsp->TOP.PCTargetE}
    , InstrD{vlSymsp->TOP.InstrD}
    , PCd{vlSymsp->TOP.PCd}
    , PCPlus4D{vlSymsp->TOP.PCPlus4D}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VPCtop::VPCtop(const char* _vcname__)
    : VPCtop(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VPCtop::~VPCtop() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void VPCtop___024root___eval_initial(VPCtop___024root* vlSelf);
void VPCtop___024root___eval_settle(VPCtop___024root* vlSelf);
void VPCtop___024root___eval(VPCtop___024root* vlSelf);
#ifdef VL_DEBUG
void VPCtop___024root___eval_debug_assertions(VPCtop___024root* vlSelf);
#endif  // VL_DEBUG
void VPCtop___024root___final(VPCtop___024root* vlSelf);

static void _eval_initial_loop(VPCtop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    VPCtop___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        VPCtop___024root___eval_settle(&(vlSymsp->TOP));
        VPCtop___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void VPCtop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VPCtop::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VPCtop___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        VPCtop___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* VPCtop::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void VPCtop::final() {
    VPCtop___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VPCtop::hierName() const { return vlSymsp->name(); }
const char* VPCtop::modelName() const { return "VPCtop"; }
unsigned VPCtop::threads() const { return 1; }
