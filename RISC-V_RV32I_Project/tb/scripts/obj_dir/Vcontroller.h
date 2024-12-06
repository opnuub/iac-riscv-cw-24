// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VCONTROLLER_H_
#define VERILATED_VCONTROLLER_H_  // guard

#include "verilated.h"

class Vcontroller__Syms;
class Vcontroller___024root;

// This class is the main interface to the Verilated model
class Vcontroller VL_NOT_FINAL : public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    Vcontroller__Syms* const vlSymsp;

  public:

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(&clk_i,0,0);
    VL_IN8(&rst_ni,0,0);
    VL_IN8(&opcode_i,6,0);
    VL_IN8(&funct3_i,2,0);
    VL_IN8(&funct7_i,6,0);
    VL_IN8(&branch_eq_i,0,0);
    VL_IN8(&branch_lt_i,0,0);
    VL_IN8(&branch_ltu_i,0,0);
    VL_OUT8(&rf_wen_o,0,0);
    VL_OUT8(&rf_wdata_sel_o,1,0);
    VL_OUT8(&alu_op_o,3,0);
    VL_OUT8(&alu_src1_sel_o,1,0);
    VL_OUT8(&alu_src2_sel_o,1,0);
    VL_OUT8(&mem_wen_o,0,0);
    VL_OUT8(&mem_size_o,2,0);
    VL_OUT8(&mem_signed_o,0,0);
    VL_OUT8(&imm_type_o,2,0);
    VL_OUT8(&next_pc_sel_o,2,0);
    VL_OUT8(&illegal_instr_o,0,0);

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    Vcontroller___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit Vcontroller(VerilatedContext* contextp, const char* name = "TOP");
    explicit Vcontroller(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~Vcontroller();
  private:
    VL_UNCOPYABLE(Vcontroller);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    /// Retrieve name of this model instance (as passed to constructor).
    const char* name() const;

    // Abstract methods from VerilatedModel
    const char* hierName() const override final;
    const char* modelName() const override final;
    unsigned threads() const override final;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
