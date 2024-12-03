// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vdecoder__pch.h"

//============================================================
// Constructors

Vdecoder::Vdecoder(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vdecoder__Syms(contextp(), _vcname__, this)}
    , opcode_o{vlSymsp->TOP.opcode_o}
    , funct3_o{vlSymsp->TOP.funct3_o}
    , funct7_o{vlSymsp->TOP.funct7_o}
    , rd_addr_o{vlSymsp->TOP.rd_addr_o}
    , rs1_addr_o{vlSymsp->TOP.rs1_addr_o}
    , rs2_addr_o{vlSymsp->TOP.rs2_addr_o}
    , instr_i{vlSymsp->TOP.instr_i}
    , imm_o{vlSymsp->TOP.imm_o}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vdecoder::Vdecoder(const char* _vcname__)
    : Vdecoder(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vdecoder::~Vdecoder() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vdecoder___024root___eval_debug_assertions(Vdecoder___024root* vlSelf);
#endif  // VL_DEBUG
void Vdecoder___024root___eval_static(Vdecoder___024root* vlSelf);
void Vdecoder___024root___eval_initial(Vdecoder___024root* vlSelf);
void Vdecoder___024root___eval_settle(Vdecoder___024root* vlSelf);
void Vdecoder___024root___eval(Vdecoder___024root* vlSelf);

void Vdecoder::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vdecoder::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vdecoder___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vdecoder___024root___eval_static(&(vlSymsp->TOP));
        Vdecoder___024root___eval_initial(&(vlSymsp->TOP));
        Vdecoder___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vdecoder___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vdecoder::eventsPending() { return false; }

uint64_t Vdecoder::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vdecoder::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vdecoder___024root___eval_final(Vdecoder___024root* vlSelf);

VL_ATTR_COLD void Vdecoder::final() {
    Vdecoder___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vdecoder::hierName() const { return vlSymsp->name(); }
const char* Vdecoder::modelName() const { return "Vdecoder"; }
unsigned Vdecoder::threads() const { return 1; }
void Vdecoder::prepareClone() const { contextp()->prepareClone(); }
void Vdecoder::atClone() const {
    contextp()->threadPoolpOnClone();
}
