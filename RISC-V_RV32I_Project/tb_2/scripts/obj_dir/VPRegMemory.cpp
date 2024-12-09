// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VPRegMemory.h"
#include "VPRegMemory__Syms.h"

//============================================================
// Constructors

VPRegMemory::VPRegMemory(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VPRegMemory__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , RdM{vlSymsp->TOP.RdM}
    , RdW{vlSymsp->TOP.RdW}
    , RegWriteM{vlSymsp->TOP.RegWriteM}
    , ResultSrcM{vlSymsp->TOP.ResultSrcM}
    , RegWriteW{vlSymsp->TOP.RegWriteW}
    , ResultSrcW{vlSymsp->TOP.ResultSrcW}
    , ALUResultM{vlSymsp->TOP.ALUResultM}
    , DMRd{vlSymsp->TOP.DMRd}
    , PCPlus4M{vlSymsp->TOP.PCPlus4M}
    , ALUResultW{vlSymsp->TOP.ALUResultW}
    , WriteDataW{vlSymsp->TOP.WriteDataW}
    , PCPlus4W{vlSymsp->TOP.PCPlus4W}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VPRegMemory::VPRegMemory(const char* _vcname__)
    : VPRegMemory(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VPRegMemory::~VPRegMemory() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void VPRegMemory___024root___eval_initial(VPRegMemory___024root* vlSelf);
void VPRegMemory___024root___eval_settle(VPRegMemory___024root* vlSelf);
void VPRegMemory___024root___eval(VPRegMemory___024root* vlSelf);
#ifdef VL_DEBUG
void VPRegMemory___024root___eval_debug_assertions(VPRegMemory___024root* vlSelf);
#endif  // VL_DEBUG
void VPRegMemory___024root___final(VPRegMemory___024root* vlSelf);

static void _eval_initial_loop(VPRegMemory__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    VPRegMemory___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        VPRegMemory___024root___eval_settle(&(vlSymsp->TOP));
        VPRegMemory___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void VPRegMemory::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VPRegMemory::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VPRegMemory___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        VPRegMemory___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* VPRegMemory::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void VPRegMemory::final() {
    VPRegMemory___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VPRegMemory::hierName() const { return vlSymsp->name(); }
const char* VPRegMemory::modelName() const { return "VPRegMemory"; }
unsigned VPRegMemory::threads() const { return 1; }
