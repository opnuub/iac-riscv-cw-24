// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VbranchUnit__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VbranchUnit::VbranchUnit(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VbranchUnit__Syms(contextp(), _vcname__, this)}
    , aluControl{vlSymsp->TOP.aluControl}
    , zero{vlSymsp->TOP.zero}
    , srcA{vlSymsp->TOP.srcA}
    , srcB{vlSymsp->TOP.srcB}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

VbranchUnit::VbranchUnit(const char* _vcname__)
    : VbranchUnit(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VbranchUnit::~VbranchUnit() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VbranchUnit___024root___eval_debug_assertions(VbranchUnit___024root* vlSelf);
#endif  // VL_DEBUG
void VbranchUnit___024root___eval_static(VbranchUnit___024root* vlSelf);
void VbranchUnit___024root___eval_initial(VbranchUnit___024root* vlSelf);
void VbranchUnit___024root___eval_settle(VbranchUnit___024root* vlSelf);
void VbranchUnit___024root___eval(VbranchUnit___024root* vlSelf);

void VbranchUnit::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VbranchUnit::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VbranchUnit___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VbranchUnit___024root___eval_static(&(vlSymsp->TOP));
        VbranchUnit___024root___eval_initial(&(vlSymsp->TOP));
        VbranchUnit___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VbranchUnit___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VbranchUnit::eventsPending() { return false; }

uint64_t VbranchUnit::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VbranchUnit::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VbranchUnit___024root___eval_final(VbranchUnit___024root* vlSelf);

VL_ATTR_COLD void VbranchUnit::final() {
    VbranchUnit___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VbranchUnit::hierName() const { return vlSymsp->name(); }
const char* VbranchUnit::modelName() const { return "VbranchUnit"; }
unsigned VbranchUnit::threads() const { return 1; }
void VbranchUnit::prepareClone() const { contextp()->prepareClone(); }
void VbranchUnit::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> VbranchUnit::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VbranchUnit___024root__trace_decl_types(VerilatedVcd* tracep);

void VbranchUnit___024root__trace_init_top(VbranchUnit___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VbranchUnit___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VbranchUnit___024root*>(voidSelf);
    VbranchUnit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    if (strlen(vlSymsp->name())) tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    VbranchUnit___024root__trace_decl_types(tracep);
    VbranchUnit___024root__trace_init_top(vlSelf, tracep);
    if (strlen(vlSymsp->name())) tracep->popPrefix();
}

VL_ATTR_COLD void VbranchUnit___024root__trace_register(VbranchUnit___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VbranchUnit::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VbranchUnit::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VbranchUnit___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
