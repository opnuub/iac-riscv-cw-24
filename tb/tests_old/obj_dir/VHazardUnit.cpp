// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VHazardUnit__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VHazardUnit::VHazardUnit(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VHazardUnit__Syms(contextp(), _vcname__, this)}
    , Rs1E{vlSymsp->TOP.Rs1E}
    , Rs2E{vlSymsp->TOP.Rs2E}
    , Rs1D{vlSymsp->TOP.Rs1D}
    , Rs2D{vlSymsp->TOP.Rs2D}
    , RdE{vlSymsp->TOP.RdE}
    , destReg_m{vlSymsp->TOP.destReg_m}
    , destReg_w{vlSymsp->TOP.destReg_w}
    , memoryRead_e{vlSymsp->TOP.memoryRead_e}
    , RegWriteM{vlSymsp->TOP.RegWriteM}
    , RegWriteW{vlSymsp->TOP.RegWriteW}
    , zero_hazard{vlSymsp->TOP.zero_hazard}
    , jump_hazard{vlSymsp->TOP.jump_hazard}
    , ForwardAE{vlSymsp->TOP.ForwardAE}
    , ForwardBE{vlSymsp->TOP.ForwardBE}
    , stall{vlSymsp->TOP.stall}
    , Flush{vlSymsp->TOP.Flush}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

VHazardUnit::VHazardUnit(const char* _vcname__)
    : VHazardUnit(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VHazardUnit::~VHazardUnit() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VHazardUnit___024root___eval_debug_assertions(VHazardUnit___024root* vlSelf);
#endif  // VL_DEBUG
void VHazardUnit___024root___eval_static(VHazardUnit___024root* vlSelf);
void VHazardUnit___024root___eval_initial(VHazardUnit___024root* vlSelf);
void VHazardUnit___024root___eval_settle(VHazardUnit___024root* vlSelf);
void VHazardUnit___024root___eval(VHazardUnit___024root* vlSelf);

void VHazardUnit::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VHazardUnit::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VHazardUnit___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VHazardUnit___024root___eval_static(&(vlSymsp->TOP));
        VHazardUnit___024root___eval_initial(&(vlSymsp->TOP));
        VHazardUnit___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VHazardUnit___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VHazardUnit::eventsPending() { return false; }

uint64_t VHazardUnit::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VHazardUnit::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VHazardUnit___024root___eval_final(VHazardUnit___024root* vlSelf);

VL_ATTR_COLD void VHazardUnit::final() {
    VHazardUnit___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VHazardUnit::hierName() const { return vlSymsp->name(); }
const char* VHazardUnit::modelName() const { return "VHazardUnit"; }
unsigned VHazardUnit::threads() const { return 1; }
void VHazardUnit::prepareClone() const { contextp()->prepareClone(); }
void VHazardUnit::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> VHazardUnit::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VHazardUnit___024root__trace_decl_types(VerilatedVcd* tracep);

void VHazardUnit___024root__trace_init_top(VHazardUnit___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VHazardUnit___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VHazardUnit___024root*>(voidSelf);
    VHazardUnit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    if (strlen(vlSymsp->name())) tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    VHazardUnit___024root__trace_decl_types(tracep);
    VHazardUnit___024root__trace_init_top(vlSelf, tracep);
    if (strlen(vlSymsp->name())) tracep->popPrefix();
}

VL_ATTR_COLD void VHazardUnit___024root__trace_register(VHazardUnit___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VHazardUnit::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VHazardUnit::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VHazardUnit___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
