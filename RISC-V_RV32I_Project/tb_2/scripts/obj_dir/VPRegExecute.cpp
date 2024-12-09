// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VPRegExecute.h"
#include "VPRegExecute__Syms.h"

//============================================================
// Constructors

VPRegExecute::VPRegExecute(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VPRegExecute__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , RdE{vlSymsp->TOP.RdE}
    , RdM{vlSymsp->TOP.RdM}
    , RegWriteE{vlSymsp->TOP.RegWriteE}
    , ResultSrcE{vlSymsp->TOP.ResultSrcE}
    , MemWriteE{vlSymsp->TOP.MemWriteE}
    , RegWriteM{vlSymsp->TOP.RegWriteM}
    , ResultSrcM{vlSymsp->TOP.ResultSrcM}
    , MemWriteM{vlSymsp->TOP.MemWriteM}
    , ALUout{vlSymsp->TOP.ALUout}
    , WriteData{vlSymsp->TOP.WriteData}
    , PCPlus4E{vlSymsp->TOP.PCPlus4E}
    , ALUResultM{vlSymsp->TOP.ALUResultM}
    , WriteDataM{vlSymsp->TOP.WriteDataM}
    , PCPlus4M{vlSymsp->TOP.PCPlus4M}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VPRegExecute::VPRegExecute(const char* _vcname__)
    : VPRegExecute(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VPRegExecute::~VPRegExecute() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void VPRegExecute___024root___eval_initial(VPRegExecute___024root* vlSelf);
void VPRegExecute___024root___eval_settle(VPRegExecute___024root* vlSelf);
void VPRegExecute___024root___eval(VPRegExecute___024root* vlSelf);
#ifdef VL_DEBUG
void VPRegExecute___024root___eval_debug_assertions(VPRegExecute___024root* vlSelf);
#endif  // VL_DEBUG
void VPRegExecute___024root___final(VPRegExecute___024root* vlSelf);

static void _eval_initial_loop(VPRegExecute__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    VPRegExecute___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        VPRegExecute___024root___eval_settle(&(vlSymsp->TOP));
        VPRegExecute___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void VPRegExecute::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VPRegExecute::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VPRegExecute___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        VPRegExecute___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* VPRegExecute::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void VPRegExecute::final() {
    VPRegExecute___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VPRegExecute::hierName() const { return vlSymsp->name(); }
const char* VPRegExecute::modelName() const { return "VPRegExecute"; }
unsigned VPRegExecute::threads() const { return 1; }
