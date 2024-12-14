// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VL2Cache__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VL2Cache::VL2Cache(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VL2Cache__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst_n{vlSymsp->TOP.rst_n}
    , load{vlSymsp->TOP.load}
    , store{vlSymsp->TOP.store}
    , mem_ready{vlSymsp->TOP.mem_ready}
    , hit{vlSymsp->TOP.hit}
    , miss{vlSymsp->TOP.miss}
    , mem_write{vlSymsp->TOP.mem_write}
    , mem_read{vlSymsp->TOP.mem_read}
    , busy{vlSymsp->TOP.busy}
    , address{vlSymsp->TOP.address}
    , data_in{vlSymsp->TOP.data_in}
    , mem_data{vlSymsp->TOP.mem_data}
    , data_out{vlSymsp->TOP.data_out}
    , mem_write_data{vlSymsp->TOP.mem_write_data}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

VL2Cache::VL2Cache(const char* _vcname__)
    : VL2Cache(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VL2Cache::~VL2Cache() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VL2Cache___024root___eval_debug_assertions(VL2Cache___024root* vlSelf);
#endif  // VL_DEBUG
void VL2Cache___024root___eval_static(VL2Cache___024root* vlSelf);
void VL2Cache___024root___eval_initial(VL2Cache___024root* vlSelf);
void VL2Cache___024root___eval_settle(VL2Cache___024root* vlSelf);
void VL2Cache___024root___eval(VL2Cache___024root* vlSelf);

void VL2Cache::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VL2Cache::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VL2Cache___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VL2Cache___024root___eval_static(&(vlSymsp->TOP));
        VL2Cache___024root___eval_initial(&(vlSymsp->TOP));
        VL2Cache___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VL2Cache___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VL2Cache::eventsPending() { return false; }

uint64_t VL2Cache::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VL2Cache::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VL2Cache___024root___eval_final(VL2Cache___024root* vlSelf);

VL_ATTR_COLD void VL2Cache::final() {
    VL2Cache___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VL2Cache::hierName() const { return vlSymsp->name(); }
const char* VL2Cache::modelName() const { return "VL2Cache"; }
unsigned VL2Cache::threads() const { return 1; }
void VL2Cache::prepareClone() const { contextp()->prepareClone(); }
void VL2Cache::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> VL2Cache::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VL2Cache___024root__trace_decl_types(VerilatedVcd* tracep);

void VL2Cache___024root__trace_init_top(VL2Cache___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VL2Cache___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VL2Cache___024root*>(voidSelf);
    VL2Cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    if (strlen(vlSymsp->name())) tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    VL2Cache___024root__trace_decl_types(tracep);
    VL2Cache___024root__trace_init_top(vlSelf, tracep);
    if (strlen(vlSymsp->name())) tracep->popPrefix();
}

VL_ATTR_COLD void VL2Cache___024root__trace_register(VL2Cache___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VL2Cache::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VL2Cache::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VL2Cache___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
