// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vcontroller__pch.h"

//============================================================
// Constructors

Vcontroller::Vcontroller(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vcontroller__Syms(contextp(), _vcname__, this)}
    , clk_i{vlSymsp->TOP.clk_i}
    , rst_ni{vlSymsp->TOP.rst_ni}
    , opcode_i{vlSymsp->TOP.opcode_i}
    , funct3_i{vlSymsp->TOP.funct3_i}
    , funct7_i{vlSymsp->TOP.funct7_i}
    , branch_eq_i{vlSymsp->TOP.branch_eq_i}
    , branch_lt_i{vlSymsp->TOP.branch_lt_i}
    , branch_ltu_i{vlSymsp->TOP.branch_ltu_i}
    , rf_wen_o{vlSymsp->TOP.rf_wen_o}
    , rf_wdata_sel_o{vlSymsp->TOP.rf_wdata_sel_o}
    , alu_op_o{vlSymsp->TOP.alu_op_o}
    , alu_src1_sel_o{vlSymsp->TOP.alu_src1_sel_o}
    , alu_src2_sel_o{vlSymsp->TOP.alu_src2_sel_o}
    , mem_wen_o{vlSymsp->TOP.mem_wen_o}
    , mem_size_o{vlSymsp->TOP.mem_size_o}
    , mem_signed_o{vlSymsp->TOP.mem_signed_o}
    , imm_type_o{vlSymsp->TOP.imm_type_o}
    , next_pc_sel_o{vlSymsp->TOP.next_pc_sel_o}
    , illegal_instr_o{vlSymsp->TOP.illegal_instr_o}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vcontroller::Vcontroller(const char* _vcname__)
    : Vcontroller(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vcontroller::~Vcontroller() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vcontroller___024root___eval_debug_assertions(Vcontroller___024root* vlSelf);
#endif  // VL_DEBUG
void Vcontroller___024root___eval_static(Vcontroller___024root* vlSelf);
void Vcontroller___024root___eval_initial(Vcontroller___024root* vlSelf);
void Vcontroller___024root___eval_settle(Vcontroller___024root* vlSelf);
void Vcontroller___024root___eval(Vcontroller___024root* vlSelf);

void Vcontroller::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vcontroller::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vcontroller___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vcontroller___024root___eval_static(&(vlSymsp->TOP));
        Vcontroller___024root___eval_initial(&(vlSymsp->TOP));
        Vcontroller___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vcontroller___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vcontroller::eventsPending() { return false; }

uint64_t Vcontroller::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vcontroller::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vcontroller___024root___eval_final(Vcontroller___024root* vlSelf);

VL_ATTR_COLD void Vcontroller::final() {
    Vcontroller___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vcontroller::hierName() const { return vlSymsp->name(); }
const char* Vcontroller::modelName() const { return "Vcontroller"; }
unsigned Vcontroller::threads() const { return 1; }
void Vcontroller::prepareClone() const { contextp()->prepareClone(); }
void Vcontroller::atClone() const {
    contextp()->threadPoolpOnClone();
}
