// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VL1Cache.h for the primary calling header

#ifndef VERILATED_VL1CACHE___024ROOT_H_
#define VERILATED_VL1CACHE___024ROOT_H_  // guard

#include "verilated.h"
#include "VL1Cache___024root.h"


class VL1Cache__Syms;
struct VL1Cache_L1Cache__DOT__CacheLine__struct__0 {
    IData/*19:0*/ __PVT__tag;
    VlWide<4>/*127:0*/ __PVT__data;
    CData/*0:0*/ __PVT__valid;

    bool operator==(const VL1Cache_L1Cache__DOT__CacheLine__struct__0& rhs) const {
        return __PVT__tag == rhs.__PVT__tag
            && __PVT__data == rhs.__PVT__data
            && __PVT__valid == rhs.__PVT__valid;
    }
    bool operator!=(const VL1Cache_L1Cache__DOT__CacheLine__struct__0& rhs) const {
        return !(*this == rhs);
    }
};

class alignas(VL_CACHE_LINE_BYTES) VL1Cache___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(writeEnable,0,0);
    VL_OUT8(hit,0,0);
    CData/*7:0*/ L1Cache__DOT__index;
    CData/*1:0*/ L1Cache__DOT__offset;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__reset__0;
    CData/*0:0*/ __VactContinue;
    VL_IN(address,31,0);
    VL_IN(writeData,31,0);
    VL_OUT(readData,31,0);
    IData/*31:0*/ L1Cache__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;
    VlUnpacked<VL1Cache_L1Cache__DOT__CacheLine__struct__0, 256> L1Cache__DOT__cache;

    // INTERNAL VARIABLES
    VL1Cache__Syms* const vlSymsp;

    // CONSTRUCTORS
    VL1Cache___024root(VL1Cache__Syms* symsp, const char* v__name);
    ~VL1Cache___024root();
    VL_UNCOPYABLE(VL1Cache___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const VL1Cache_L1Cache__DOT__CacheLine__struct__0& obj);

#endif  // guard
