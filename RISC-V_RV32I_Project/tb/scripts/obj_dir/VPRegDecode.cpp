// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VPRegDecode.h"
#include "VPRegDecode__Syms.h"

//============================================================
// Constructors

VPRegDecode::VPRegDecode(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VPRegDecode__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , RdD{vlSymsp->TOP.RdD}
    , RdE{vlSymsp->TOP.RdE}
    , RegWriteD{vlSymsp->TOP.RegWriteD}
    , ResultSrcD{vlSymsp->TOP.ResultSrcD}
    , MemWriteD{vlSymsp->TOP.MemWriteD}
    , JumpD{vlSymsp->TOP.JumpD}
    , BranchD{vlSymsp->TOP.BranchD}
    , ALUControl{vlSymsp->TOP.ALUControl}
    , ALUSrcD{vlSymsp->TOP.ALUSrcD}
    , RegWriteE{vlSymsp->TOP.RegWriteE}
    , ResultSrcE{vlSymsp->TOP.ResultSrcE}
    , MemWriteE{vlSymsp->TOP.MemWriteE}
    , JumpE{vlSymsp->TOP.JumpE}
    , BranchE{vlSymsp->TOP.BranchE}
    , ALUControlE{vlSymsp->TOP.ALUControlE}
    , ALUSrcE{vlSymsp->TOP.ALUSrcE}
    , rd1{vlSymsp->TOP.rd1}
    , rd2{vlSymsp->TOP.rd2}
    , PCd{vlSymsp->TOP.PCd}
    , ImmExtD{vlSymsp->TOP.ImmExtD}
    , PCPlus4D{vlSymsp->TOP.PCPlus4D}
    , rd1E{vlSymsp->TOP.rd1E}
    , rd2E{vlSymsp->TOP.rd2E}
    , PCe{vlSymsp->TOP.PCe}
    , ImmExtE{vlSymsp->TOP.ImmExtE}
    , PcPlus4E{vlSymsp->TOP.PcPlus4E}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VPRegDecode::VPRegDecode(const char* _vcname__)
    : VPRegDecode(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VPRegDecode::~VPRegDecode() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void VPRegDecode___024root___eval_initial(VPRegDecode___024root* vlSelf);
void VPRegDecode___024root___eval_settle(VPRegDecode___024root* vlSelf);
void VPRegDecode___024root___eval(VPRegDecode___024root* vlSelf);
#ifdef VL_DEBUG
void VPRegDecode___024root___eval_debug_assertions(VPRegDecode___024root* vlSelf);
#endif  // VL_DEBUG
void VPRegDecode___024root___final(VPRegDecode___024root* vlSelf);

static void _eval_initial_loop(VPRegDecode__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    VPRegDecode___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        VPRegDecode___024root___eval_settle(&(vlSymsp->TOP));
        VPRegDecode___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void VPRegDecode::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VPRegDecode::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VPRegDecode___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        VPRegDecode___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* VPRegDecode::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void VPRegDecode::final() {
    VPRegDecode___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VPRegDecode::hierName() const { return vlSymsp->name(); }
const char* VPRegDecode::modelName() const { return "VPRegDecode"; }
unsigned VPRegDecode::threads() const { return 1; }
