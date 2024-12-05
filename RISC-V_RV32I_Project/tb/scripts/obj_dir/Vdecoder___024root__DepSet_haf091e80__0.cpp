// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdecoder.h for the primary calling header

#include "Vdecoder__pch.h"
#include "Vdecoder___024root.h"

void Vdecoder___024root___ico_sequent__TOP__0(Vdecoder___024root* vlSelf);

void Vdecoder___024root___eval_ico(Vdecoder___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdecoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecoder___024root___eval_ico\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vdecoder___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vdecoder___024root___ico_sequent__TOP__0(Vdecoder___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdecoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecoder___024root___ico_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.funct3_o = (7U & (vlSelfRef.instr_i >> 0xcU));
    vlSelfRef.funct7_o = (vlSelfRef.instr_i >> 0x19U);
    vlSelfRef.rd_addr_o = (0x1fU & (vlSelfRef.instr_i 
                                    >> 7U));
    vlSelfRef.rs1_addr_o = (0x1fU & (vlSelfRef.instr_i 
                                     >> 0xfU));
    vlSelfRef.rs2_addr_o = (0x1fU & (vlSelfRef.instr_i 
                                     >> 0x14U));
    vlSelfRef.opcode_o = (0x7fU & vlSelfRef.instr_i);
    vlSelfRef.imm_o = ((0x40U & (IData)(vlSelfRef.opcode_o))
                        ? ((0x20U & (IData)(vlSelfRef.opcode_o))
                            ? ((0x10U & (IData)(vlSelfRef.opcode_o))
                                ? 0U : ((8U & (IData)(vlSelfRef.opcode_o))
                                         ? ((4U & (IData)(vlSelfRef.opcode_o))
                                             ? ((2U 
                                                 & (IData)(vlSelfRef.opcode_o))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlSelfRef.opcode_o))
                                                  ? 
                                                 (((- (IData)(
                                                              (vlSelfRef.instr_i 
                                                               >> 0x1fU))) 
                                                   << 0x15U) 
                                                  | ((0x100000U 
                                                      & (vlSelfRef.instr_i 
                                                         >> 0xbU)) 
                                                     | ((0xff000U 
                                                         & vlSelfRef.instr_i) 
                                                        | ((0x800U 
                                                            & (vlSelfRef.instr_i 
                                                               >> 9U)) 
                                                           | (0x7feU 
                                                              & (vlSelfRef.instr_i 
                                                                 >> 0x14U))))))
                                                  : 0U)
                                                 : 0U)
                                             : 0U) : 
                                        ((4U & (IData)(vlSelfRef.opcode_o))
                                          ? ((2U & (IData)(vlSelfRef.opcode_o))
                                              ? ((1U 
                                                  & (IData)(vlSelfRef.opcode_o))
                                                  ? 
                                                 (((- (IData)(
                                                              (vlSelfRef.instr_i 
                                                               >> 0x1fU))) 
                                                   << 0xcU) 
                                                  | (vlSelfRef.instr_i 
                                                     >> 0x14U))
                                                  : 0U)
                                              : 0U)
                                          : ((2U & (IData)(vlSelfRef.opcode_o))
                                              ? ((1U 
                                                  & (IData)(vlSelfRef.opcode_o))
                                                  ? 
                                                 (((- (IData)(
                                                              (vlSelfRef.instr_i 
                                                               >> 0x1fU))) 
                                                   << 0xdU) 
                                                  | ((0x1000U 
                                                      & (vlSelfRef.instr_i 
                                                         >> 0x13U)) 
                                                     | ((0x800U 
                                                         & (vlSelfRef.instr_i 
                                                            << 4U)) 
                                                        | ((0x7e0U 
                                                            & (vlSelfRef.instr_i 
                                                               >> 0x14U)) 
                                                           | (0x1eU 
                                                              & (vlSelfRef.instr_i 
                                                                 >> 7U))))))
                                                  : 0U)
                                              : 0U))))
                            : 0U) : ((0x20U & (IData)(vlSelfRef.opcode_o))
                                      ? ((0x10U & (IData)(vlSelfRef.opcode_o))
                                          ? ((8U & (IData)(vlSelfRef.opcode_o))
                                              ? 0U : 
                                             ((4U & (IData)(vlSelfRef.opcode_o))
                                               ? ((2U 
                                                   & (IData)(vlSelfRef.opcode_o))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.opcode_o))
                                                    ? 
                                                   (0xfffff000U 
                                                    & vlSelfRef.instr_i)
                                                    : 0U)
                                                   : 0U)
                                               : 0U))
                                          : ((8U & (IData)(vlSelfRef.opcode_o))
                                              ? 0U : 
                                             ((4U & (IData)(vlSelfRef.opcode_o))
                                               ? 0U
                                               : ((2U 
                                                   & (IData)(vlSelfRef.opcode_o))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.opcode_o))
                                                    ? 
                                                   (((- (IData)(
                                                                (vlSelfRef.instr_i 
                                                                 >> 0x1fU))) 
                                                     << 0xcU) 
                                                    | ((0xfe0U 
                                                        & (vlSelfRef.instr_i 
                                                           >> 0x14U)) 
                                                       | (0x1fU 
                                                          & (vlSelfRef.instr_i 
                                                             >> 7U))))
                                                    : 0U)
                                                   : 0U))))
                                      : ((0x10U & (IData)(vlSelfRef.opcode_o))
                                          ? ((8U & (IData)(vlSelfRef.opcode_o))
                                              ? 0U : 
                                             ((4U & (IData)(vlSelfRef.opcode_o))
                                               ? ((2U 
                                                   & (IData)(vlSelfRef.opcode_o))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.opcode_o))
                                                    ? 
                                                   (0xfffff000U 
                                                    & vlSelfRef.instr_i)
                                                    : 0U)
                                                   : 0U)
                                               : ((2U 
                                                   & (IData)(vlSelfRef.opcode_o))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.opcode_o))
                                                    ? 
                                                   (((- (IData)(
                                                                (vlSelfRef.instr_i 
                                                                 >> 0x1fU))) 
                                                     << 0xcU) 
                                                    | (vlSelfRef.instr_i 
                                                       >> 0x14U))
                                                    : 0U)
                                                   : 0U)))
                                          : ((8U & (IData)(vlSelfRef.opcode_o))
                                              ? 0U : 
                                             ((4U & (IData)(vlSelfRef.opcode_o))
                                               ? 0U
                                               : ((2U 
                                                   & (IData)(vlSelfRef.opcode_o))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.opcode_o))
                                                    ? 
                                                   (((- (IData)(
                                                                (vlSelfRef.instr_i 
                                                                 >> 0x1fU))) 
                                                     << 0xcU) 
                                                    | (vlSelfRef.instr_i 
                                                       >> 0x14U))
                                                    : 0U)
                                                   : 0U))))));
    VL_WRITEF_NX("instr_i: %b\nopcode_o: %b\nrd_addr_o: %b, rs1_addr_o: %b, rs2_addr_o: %b\nfunct3_o: %b, funct7_o: %b\nimm_debug: %b, imm_sign_extended: %11d\n",0,
                 32,vlSelfRef.instr_i,7,(IData)(vlSelfRef.opcode_o),
                 5,vlSelfRef.rd_addr_o,5,(IData)(vlSelfRef.rs1_addr_o),
                 5,vlSelfRef.rs2_addr_o,3,(IData)(vlSelfRef.funct3_o),
                 7,vlSelfRef.funct7_o,32,vlSelfRef.imm_o,
                 32,vlSelfRef.imm_o);
}

void Vdecoder___024root___eval_triggers__ico(Vdecoder___024root* vlSelf);

bool Vdecoder___024root___eval_phase__ico(Vdecoder___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdecoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecoder___024root___eval_phase__ico\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vdecoder___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vdecoder___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vdecoder___024root___eval_act(Vdecoder___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdecoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecoder___024root___eval_act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

void Vdecoder___024root___eval_nba(Vdecoder___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdecoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecoder___024root___eval_nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

void Vdecoder___024root___eval_triggers__act(Vdecoder___024root* vlSelf);

bool Vdecoder___024root___eval_phase__act(Vdecoder___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdecoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecoder___024root___eval_phase__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<0> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vdecoder___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vdecoder___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vdecoder___024root___eval_phase__nba(Vdecoder___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdecoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecoder___024root___eval_phase__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vdecoder___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdecoder___024root___dump_triggers__ico(Vdecoder___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vdecoder___024root___dump_triggers__nba(Vdecoder___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vdecoder___024root___dump_triggers__act(Vdecoder___024root* vlSelf);
#endif  // VL_DEBUG

void Vdecoder___024root___eval(Vdecoder___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdecoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecoder___024root___eval\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vdecoder___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/Users/michaelli/Documents/GitHub/iac-riscv-cw-24/RISC-V_RV32I_Project/rtl/decoder.sv", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vdecoder___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vdecoder___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/Users/michaelli/Documents/GitHub/iac-riscv-cw-24/RISC-V_RV32I_Project/rtl/decoder.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vdecoder___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/Users/michaelli/Documents/GitHub/iac-riscv-cw-24/RISC-V_RV32I_Project/rtl/decoder.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vdecoder___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vdecoder___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vdecoder___024root___eval_debug_assertions(Vdecoder___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdecoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecoder___024root___eval_debug_assertions\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
