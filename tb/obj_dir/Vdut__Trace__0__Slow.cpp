// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdut__Syms.h"


VL_ATTR_COLD void Vdut___024root__trace_init_sub__TOP__0(Vdut___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+105,"clk", false,-1);
    tracep->declBit(c+106,"rst", false,-1);
    tracep->declBus(c+107,"a0", false,-1, 31,0);
    tracep->pushNamePrefix("top ");
    tracep->declBus(c+110,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+110,"INSTR_WIDTH", false,-1, 31,0);
    tracep->declBus(c+110,"ADDR_WIDTH", false,-1, 31,0);
    tracep->declBus(c+111,"MEM_ADDR_WIDTH", false,-1, 31,0);
    tracep->declBus(c+112,"REG_DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+113,"OFFSET", false,-1, 31,0);
    tracep->declBit(c+105,"clk", false,-1);
    tracep->declBit(c+106,"rst", false,-1);
    tracep->declBus(c+107,"a0", false,-1, 31,0);
    tracep->declBus(c+7,"PCPlus4F", false,-1, 31,0);
    tracep->declBus(c+8,"instr", false,-1, 31,0);
    tracep->declBus(c+9,"pc", false,-1, 31,0);
    tracep->declBus(c+10,"PCTargetE", false,-1, 31,0);
    tracep->declBus(c+11,"nextPC", false,-1, 31,0);
    tracep->declBus(c+12,"PCd", false,-1, 31,0);
    tracep->declBus(c+13,"PCPlus4D", false,-1, 31,0);
    tracep->declBus(c+108,"rd1", false,-1, 31,0);
    tracep->declBus(c+109,"rd2", false,-1, 31,0);
    tracep->declBus(c+14,"ImmExtD", false,-1, 31,0);
    tracep->declBus(c+15,"instrD", false,-1, 31,0);
    tracep->declBit(c+16,"RegWriteD", false,-1);
    tracep->declBit(c+17,"MemWriteD", false,-1);
    tracep->declBit(c+18,"JumpD", false,-1);
    tracep->declBit(c+19,"BranchD", false,-1);
    tracep->declBit(c+20,"ALUSrcD", false,-1);
    tracep->declBus(c+21,"sizeSrcD", false,-1, 2,0);
    tracep->declBus(c+22,"ResultSrcD", false,-1, 1,0);
    tracep->declBus(c+23,"immSrcD", false,-1, 1,0);
    tracep->declBus(c+24,"ALUControlD", false,-1, 3,0);
    tracep->declBus(c+25,"PCe", false,-1, 31,0);
    tracep->declBus(c+26,"PCPlus4E", false,-1, 31,0);
    tracep->declBus(c+27,"ImmExtE", false,-1, 31,0);
    tracep->declBus(c+1,"rd1E", false,-1, 31,0);
    tracep->declBus(c+28,"rd2E", false,-1, 31,0);
    tracep->declBus(c+29,"srcB", false,-1, 31,0);
    tracep->declBus(c+30,"aluResult", false,-1, 31,0);
    tracep->declBus(c+31,"RdE", false,-1, 4,0);
    tracep->declBit(c+32,"RegWriteE", false,-1);
    tracep->declBit(c+33,"MemWriteE", false,-1);
    tracep->declBit(c+34,"JumpE", false,-1);
    tracep->declBit(c+35,"BranchE", false,-1);
    tracep->declBit(c+2,"ALUSrcE", false,-1);
    tracep->declBus(c+36,"sizeSrcE", false,-1, 2,0);
    tracep->declBus(c+37,"ResultSrcE", false,-1, 1,0);
    tracep->declBus(c+38,"ALUControlE", false,-1, 3,0);
    tracep->declBus(c+39,"ALUResultM", false,-1, 31,0);
    tracep->declBus(c+40,"WriteDataM", false,-1, 31,0);
    tracep->declBus(c+41,"ReadData", false,-1, 31,0);
    tracep->declBus(c+42,"PCPlus4M", false,-1, 31,0);
    tracep->declBus(c+43,"RdM", false,-1, 4,0);
    tracep->declBit(c+44,"RegWriteM", false,-1);
    tracep->declBit(c+45,"MemWriteM", false,-1);
    tracep->declBus(c+46,"sizeSrcM", false,-1, 2,0);
    tracep->declBus(c+47,"ResultSrcM", false,-1, 1,0);
    tracep->declBus(c+48,"ALUResultW", false,-1, 31,0);
    tracep->declBus(c+3,"ReadDataW", false,-1, 31,0);
    tracep->declBus(c+49,"PCPlus4W", false,-1, 31,0);
    tracep->declBus(c+50,"ResultW", false,-1, 31,0);
    tracep->declBus(c+51,"RdW", false,-1, 4,0);
    tracep->declBit(c+52,"RegWriteW", false,-1);
    tracep->declBus(c+4,"ResultSrcW", false,-1, 1,0);
    tracep->declBit(c+53,"Flush", false,-1);
    tracep->declBit(c+54,"stall", false,-1);
    tracep->declBit(c+55,"memoryRead", false,-1);
    tracep->declBus(c+56,"ForwardAE", false,-1, 1,0);
    tracep->declBus(c+57,"ForwardBE", false,-1, 1,0);
    tracep->declBus(c+58,"SrcAE", false,-1, 31,0);
    tracep->declBus(c+59,"WriteDataE", false,-1, 31,0);
    tracep->declBus(c+5,"Rs1E", false,-1, 4,0);
    tracep->declBus(c+6,"Rs2E", false,-1, 4,0);
    tracep->declBit(c+60,"jalrSrc", false,-1);
    tracep->declBit(c+61,"pcSrc", false,-1);
    tracep->declBit(c+62,"zero", false,-1);
    tracep->pushNamePrefix("DataMemory ");
    tracep->declBus(c+110,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+111,"ADDR_WIDTH", false,-1, 31,0);
    tracep->declBit(c+105,"clk", false,-1);
    tracep->declBus(c+46,"SizeCtr", false,-1, 2,0);
    tracep->declBus(c+63,"ALUResult", false,-1, 16,0);
    tracep->declBus(c+40,"WriteData", false,-1, 31,0);
    tracep->declBit(c+45,"MemWrite", false,-1);
    tracep->declBus(c+41,"ReadData", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("HazardMux1 ");
    tracep->declBus(c+110,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+1,"rdE", false,-1, 31,0);
    tracep->declBus(c+50,"ResultW", false,-1, 31,0);
    tracep->declBus(c+39,"ALUResultM", false,-1, 31,0);
    tracep->declBus(c+56,"Forward", false,-1, 1,0);
    tracep->declBus(c+58,"Out", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("HazardMux2 ");
    tracep->declBus(c+110,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+28,"rdE", false,-1, 31,0);
    tracep->declBus(c+50,"ResultW", false,-1, 31,0);
    tracep->declBus(c+39,"ALUResultM", false,-1, 31,0);
    tracep->declBus(c+57,"Forward", false,-1, 1,0);
    tracep->declBus(c+59,"Out", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("HazardUnit ");
    tracep->declBus(c+5,"Rs1E", false,-1, 4,0);
    tracep->declBus(c+6,"Rs2E", false,-1, 4,0);
    tracep->declBus(c+64,"Rs1D", false,-1, 4,0);
    tracep->declBus(c+65,"Rs2D", false,-1, 4,0);
    tracep->declBus(c+31,"RdE", false,-1, 4,0);
    tracep->declBus(c+43,"destReg_m", false,-1, 4,0);
    tracep->declBus(c+51,"destReg_w", false,-1, 4,0);
    tracep->declBit(c+55,"memoryRead_e", false,-1);
    tracep->declBit(c+44,"RegWriteM", false,-1);
    tracep->declBit(c+52,"RegWriteW", false,-1);
    tracep->declBit(c+62,"zero_hazard", false,-1);
    tracep->declBit(c+34,"jump_hazard", false,-1);
    tracep->declBus(c+56,"ForwardAE", false,-1, 1,0);
    tracep->declBus(c+57,"ForwardBE", false,-1, 1,0);
    tracep->declBit(c+54,"stall", false,-1);
    tracep->declBit(c+53,"Flush", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("PCMuxSelect ");
    tracep->declBit(c+34,"JumpE", false,-1);
    tracep->declBit(c+35,"BranchE", false,-1);
    tracep->declBit(c+62,"zero", false,-1);
    tracep->declBit(c+61,"pcSrcE", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("PRegDecode ");
    tracep->declBus(c+110,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+108,"rd1", false,-1, 31,0);
    tracep->declBus(c+109,"rd2", false,-1, 31,0);
    tracep->declBus(c+12,"PCd", false,-1, 31,0);
    tracep->declBus(c+14,"ImmExtD", false,-1, 31,0);
    tracep->declBit(c+105,"clk", false,-1);
    tracep->declBit(c+106,"rst", false,-1);
    tracep->declBit(c+53,"Flush", false,-1);
    tracep->declBus(c+66,"RdD", false,-1, 4,0);
    tracep->declBus(c+13,"PCPlus4D", false,-1, 31,0);
    tracep->declBus(c+1,"rd1E", false,-1, 31,0);
    tracep->declBus(c+28,"rd2E", false,-1, 31,0);
    tracep->declBus(c+25,"PCe", false,-1, 31,0);
    tracep->declBus(c+31,"RdE", false,-1, 4,0);
    tracep->declBus(c+27,"ImmExtE", false,-1, 31,0);
    tracep->declBus(c+26,"PcPlus4E", false,-1, 31,0);
    tracep->declBit(c+16,"RegWriteD", false,-1);
    tracep->declBus(c+22,"ResultSrcD", false,-1, 1,0);
    tracep->declBit(c+17,"MemWriteD", false,-1);
    tracep->declBit(c+18,"JumpD", false,-1);
    tracep->declBit(c+19,"BranchD", false,-1);
    tracep->declBus(c+24,"ALUControl", false,-1, 3,0);
    tracep->declBit(c+20,"ALUSrcD", false,-1);
    tracep->declBit(c+32,"RegWriteE", false,-1);
    tracep->declBus(c+37,"ResultSrcE", false,-1, 1,0);
    tracep->declBit(c+33,"MemWriteE", false,-1);
    tracep->declBit(c+34,"JumpE", false,-1);
    tracep->declBit(c+35,"BranchE", false,-1);
    tracep->declBus(c+38,"ALUControlE", false,-1, 3,0);
    tracep->declBit(c+2,"ALUSrcE", false,-1);
    tracep->declBus(c+21,"sizeSrcD", false,-1, 2,0);
    tracep->declBus(c+36,"sizeSrcE", false,-1, 2,0);
    tracep->declBus(c+64,"Rs1D", false,-1, 4,0);
    tracep->declBus(c+65,"Rs2D", false,-1, 4,0);
    tracep->declBus(c+5,"Rs1E", false,-1, 4,0);
    tracep->declBus(c+6,"Rs2E", false,-1, 4,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("PRegExecute ");
    tracep->declBus(c+110,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+30,"ALUout", false,-1, 31,0);
    tracep->declBus(c+28,"WriteData", false,-1, 31,0);
    tracep->declBus(c+26,"PCPlus4E", false,-1, 31,0);
    tracep->declBit(c+105,"clk", false,-1);
    tracep->declBit(c+106,"rst", false,-1);
    tracep->declBus(c+31,"RdE", false,-1, 4,0);
    tracep->declBus(c+39,"ALUResultM", false,-1, 31,0);
    tracep->declBus(c+40,"WriteDataM", false,-1, 31,0);
    tracep->declBus(c+43,"RdM", false,-1, 4,0);
    tracep->declBus(c+42,"PCPlus4M", false,-1, 31,0);
    tracep->declBit(c+32,"RegWriteE", false,-1);
    tracep->declBus(c+37,"ResultSrcE", false,-1, 1,0);
    tracep->declBit(c+33,"MemWriteE", false,-1);
    tracep->declBit(c+44,"RegWriteM", false,-1);
    tracep->declBus(c+47,"ResultSrcM", false,-1, 1,0);
    tracep->declBit(c+45,"MemWriteM", false,-1);
    tracep->declBus(c+36,"sizeSrcE", false,-1, 2,0);
    tracep->declBus(c+46,"sizeSrcM", false,-1, 2,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("PRegFetch ");
    tracep->declBus(c+110,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+8,"instr", false,-1, 31,0);
    tracep->declBus(c+9,"PCf", false,-1, 31,0);
    tracep->declBus(c+7,"PCPlus4F", false,-1, 31,0);
    tracep->declBit(c+105,"clk", false,-1);
    tracep->declBit(c+53,"Flush", false,-1);
    tracep->declBit(c+106,"rst", false,-1);
    tracep->declBit(c+54,"stall", false,-1);
    tracep->declBus(c+13,"PCPlus4D", false,-1, 31,0);
    tracep->declBus(c+12,"PCd", false,-1, 31,0);
    tracep->declBus(c+15,"InstrD", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("PRegMemory ");
    tracep->declBus(c+110,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+39,"ALUResultM", false,-1, 31,0);
    tracep->declBus(c+41,"DMRd", false,-1, 31,0);
    tracep->declBus(c+43,"RdM", false,-1, 4,0);
    tracep->declBus(c+42,"PCPlus4M", false,-1, 31,0);
    tracep->declBit(c+105,"clk", false,-1);
    tracep->declBit(c+106,"rst", false,-1);
    tracep->declBus(c+51,"RdW", false,-1, 4,0);
    tracep->declBus(c+48,"ALUResultW", false,-1, 31,0);
    tracep->declBus(c+3,"ReadDataW", false,-1, 31,0);
    tracep->declBus(c+49,"PCPlus4W", false,-1, 31,0);
    tracep->declBit(c+44,"RegWriteM", false,-1);
    tracep->declBus(c+47,"ResultSrcM", false,-1, 1,0);
    tracep->declBit(c+52,"RegWriteW", false,-1);
    tracep->declBus(c+4,"ResultSrcW", false,-1, 1,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("alu ");
    tracep->declBus(c+110,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+58,"srcA", false,-1, 31,0);
    tracep->declBus(c+29,"srcB", false,-1, 31,0);
    tracep->declBus(c+38,"aluControl", false,-1, 3,0);
    tracep->declBus(c+30,"aluResult", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("aluMux ");
    tracep->declBus(c+110,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+27,"immOp", false,-1, 31,0);
    tracep->declBus(c+59,"regOp2", false,-1, 31,0);
    tracep->declBit(c+2,"aluSrc", false,-1);
    tracep->declBus(c+29,"srcB", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("branchUnit_inst ");
    tracep->declBus(c+110,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+58,"srcA", false,-1, 31,0);
    tracep->declBus(c+29,"srcB", false,-1, 31,0);
    tracep->declBus(c+38,"aluControl", false,-1, 3,0);
    tracep->declBit(c+62,"zero", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("controlUnit ");
    tracep->declBus(c+67,"op", false,-1, 6,0);
    tracep->declBus(c+68,"funct3", false,-1, 2,0);
    tracep->declBit(c+69,"funct7", false,-1);
    tracep->declBit(c+19,"Branch", false,-1);
    tracep->declBit(c+18,"jumpSrc", false,-1);
    tracep->declBit(c+60,"jalrSrc", false,-1);
    tracep->declBus(c+22,"resultSrc", false,-1, 1,0);
    tracep->declBit(c+17,"memWrite", false,-1);
    tracep->declBus(c+24,"aluControl", false,-1, 3,0);
    tracep->declBit(c+20,"aluSrc", false,-1);
    tracep->declBus(c+23,"immSrc", false,-1, 1,0);
    tracep->declBit(c+16,"regWrite", false,-1);
    tracep->declBus(c+21,"sizeSrc", false,-1, 2,0);
    tracep->declBus(c+70,"aluOp", false,-1, 1,0);
    tracep->pushNamePrefix("aluDecoder ");
    tracep->declBit(c+71,"op", false,-1);
    tracep->declBus(c+70,"aluOp", false,-1, 1,0);
    tracep->declBus(c+68,"funct3", false,-1, 2,0);
    tracep->declBit(c+69,"funct7", false,-1);
    tracep->declBus(c+24,"aluControl", false,-1, 3,0);
    tracep->declBus(c+72,"opfunct7", false,-1, 1,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("mainDecoder ");
    tracep->declBus(c+67,"op", false,-1, 6,0);
    tracep->declBus(c+68,"funct3", false,-1, 2,0);
    tracep->declBit(c+19,"Branch", false,-1);
    tracep->declBit(c+18,"jumpSrc", false,-1);
    tracep->declBit(c+60,"jalrSrc", false,-1);
    tracep->declBus(c+22,"resultSrc", false,-1, 1,0);
    tracep->declBit(c+17,"memWrite", false,-1);
    tracep->declBit(c+20,"aluSrc", false,-1);
    tracep->declBus(c+23,"immSrc", false,-1, 1,0);
    tracep->declBit(c+16,"regWrite", false,-1);
    tracep->declBus(c+70,"aluOp", false,-1, 1,0);
    tracep->declBus(c+21,"sizeSrc", false,-1, 2,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("extend ");
    tracep->declBus(c+110,"INSTR_WIDTH", false,-1, 31,0);
    tracep->declBus(c+110,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+15,"instruction", false,-1, 31,0);
    tracep->declBus(c+23,"immSrc", false,-1, 1,0);
    tracep->declBit(c+18,"jumpSrc", false,-1);
    tracep->declBus(c+14,"immExt", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("extendPC ");
    tracep->declBus(c+110,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+110,"ADDR_WIDTH", false,-1, 31,0);
    tracep->declBus(c+25,"pc", false,-1, 31,0);
    tracep->declBus(c+27,"immOp", false,-1, 31,0);
    tracep->declBus(c+50,"result", false,-1, 31,0);
    tracep->declBit(c+60,"jalrSrc", false,-1);
    tracep->declBus(c+10,"PCTargetE", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("instrMemory ");
    tracep->declBus(c+110,"ADDR_WIDTH", false,-1, 31,0);
    tracep->declBus(c+110,"INSTR_WIDTH", false,-1, 31,0);
    tracep->declBus(c+9,"pc", false,-1, 31,0);
    tracep->declBus(c+8,"instr", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pcMux ");
    tracep->declBus(c+110,"ADDR_WIDTH", false,-1, 31,0);
    tracep->declBus(c+10,"branchPC", false,-1, 31,0);
    tracep->declBus(c+7,"PCPlus4F", false,-1, 31,0);
    tracep->declBit(c+61,"PCsrc", false,-1);
    tracep->declBus(c+11,"nextPC", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pcReg ");
    tracep->declBus(c+113,"OFFSET", false,-1, 31,0);
    tracep->declBus(c+110,"ADDR_WIDTH", false,-1, 31,0);
    tracep->declBus(c+11,"nextPC", false,-1, 31,0);
    tracep->declBit(c+105,"clk", false,-1);
    tracep->declBit(c+106,"rst", false,-1);
    tracep->declBit(c+54,"stall", false,-1);
    tracep->declBus(c+7,"PCPlus4F", false,-1, 31,0);
    tracep->declBus(c+9,"pc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("regfile ");
    tracep->declBus(c+110,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+112,"REG_DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+105,"clk", false,-1);
    tracep->declBus(c+64,"rs1", false,-1, 4,0);
    tracep->declBus(c+65,"rs2", false,-1, 4,0);
    tracep->declBus(c+51,"rd", false,-1, 4,0);
    tracep->declBit(c+52,"RegWrite", false,-1);
    tracep->declBus(c+50,"ResultW", false,-1, 31,0);
    tracep->declBus(c+108,"ALUop1", false,-1, 31,0);
    tracep->declBus(c+109,"regOp2", false,-1, 31,0);
    tracep->declBus(c+107,"a0", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+73+i*1,"rom_array", true,(i+0), 31,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("resultMux ");
    tracep->declBus(c+110,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+3,"ReadDataW", false,-1, 31,0);
    tracep->declBus(c+48,"ALUResult", false,-1, 31,0);
    tracep->declBus(c+49,"PCPlus4", false,-1, 31,0);
    tracep->declBus(c+4,"ResultSrc", false,-1, 1,0);
    tracep->declBus(c+50,"Result", false,-1, 31,0);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vdut___024root__trace_init_top(Vdut___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_init_top\n"); );
    // Body
    Vdut___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vdut___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vdut___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vdut___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vdut___024root__trace_register(Vdut___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vdut___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vdut___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vdut___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vdut___024root__trace_full_sub_0(Vdut___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vdut___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_full_top_0\n"); );
    // Init
    Vdut___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdut___024root*>(voidSelf);
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vdut___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vdut___024root__trace_full_sub_0(Vdut___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->top__DOT__rd1E),32);
    bufp->fullBit(oldp+2,(vlSelf->top__DOT__ALUSrcE));
    bufp->fullIData(oldp+3,(vlSelf->top__DOT__ReadDataW),32);
    bufp->fullCData(oldp+4,(vlSelf->top__DOT__ResultSrcW),2);
    bufp->fullCData(oldp+5,(vlSelf->top__DOT__Rs1E),5);
    bufp->fullCData(oldp+6,(vlSelf->top__DOT__Rs2E),5);
    bufp->fullIData(oldp+7,(((IData)(4U) + vlSelf->top__DOT__pc)),32);
    bufp->fullIData(oldp+8,(((vlSelf->top__DOT__instrMemory__DOT__rom
                              [(0xfffU & ((IData)(3U) 
                                          + vlSelf->top__DOT__pc))] 
                              << 0x18U) | ((vlSelf->top__DOT__instrMemory__DOT__rom
                                            [(0xfffU 
                                              & ((IData)(2U) 
                                                 + vlSelf->top__DOT__pc))] 
                                            << 0x10U) 
                                           | ((vlSelf->top__DOT__instrMemory__DOT__rom
                                               [(0xfffU 
                                                 & ((IData)(1U) 
                                                    + vlSelf->top__DOT__pc))] 
                                               << 8U) 
                                              | vlSelf->top__DOT__instrMemory__DOT__rom
                                              [(0xfffU 
                                                & vlSelf->top__DOT__pc)])))),32);
    bufp->fullIData(oldp+9,(vlSelf->top__DOT__pc),32);
    bufp->fullIData(oldp+10,(((IData)(vlSelf->top__DOT__jalrSrc)
                               ? vlSelf->top__DOT__ResultW
                               : (vlSelf->top__DOT__PCe 
                                  + vlSelf->top__DOT__ImmExtE))),32);
    bufp->fullIData(oldp+11,((((IData)(vlSelf->top__DOT__JumpE) 
                               | ((IData)(vlSelf->top__DOT__BranchE) 
                                  & (IData)(vlSelf->top__DOT__zero)))
                               ? ((IData)(vlSelf->top__DOT__jalrSrc)
                                   ? vlSelf->top__DOT__ResultW
                                   : (vlSelf->top__DOT__PCe 
                                      + vlSelf->top__DOT__ImmExtE))
                               : ((IData)(4U) + vlSelf->top__DOT__pc))),32);
    bufp->fullIData(oldp+12,(vlSelf->top__DOT__PCd),32);
    bufp->fullIData(oldp+13,(vlSelf->top__DOT__PCPlus4D),32);
    bufp->fullIData(oldp+14,(vlSelf->top__DOT__ImmExtD),32);
    bufp->fullIData(oldp+15,(vlSelf->top__DOT__instrD),32);
    bufp->fullBit(oldp+16,(vlSelf->top__DOT__RegWriteD));
    bufp->fullBit(oldp+17,(vlSelf->top__DOT__MemWriteD));
    bufp->fullBit(oldp+18,(vlSelf->top__DOT__JumpD));
    bufp->fullBit(oldp+19,(vlSelf->top__DOT__BranchD));
    bufp->fullBit(oldp+20,(vlSelf->top__DOT__ALUSrcD));
    bufp->fullCData(oldp+21,(vlSelf->top__DOT__sizeSrcD),3);
    bufp->fullCData(oldp+22,(vlSelf->top__DOT__ResultSrcD),2);
    bufp->fullCData(oldp+23,(vlSelf->top__DOT__immSrcD),2);
    bufp->fullCData(oldp+24,(vlSelf->top__DOT__ALUControlD),4);
    bufp->fullIData(oldp+25,(vlSelf->top__DOT__PCe),32);
    bufp->fullIData(oldp+26,(vlSelf->top__DOT__PCPlus4E),32);
    bufp->fullIData(oldp+27,(vlSelf->top__DOT__ImmExtE),32);
    bufp->fullIData(oldp+28,(vlSelf->top__DOT__rd2E),32);
    bufp->fullIData(oldp+29,(vlSelf->top__DOT__srcB),32);
    bufp->fullIData(oldp+30,(vlSelf->top__DOT__aluResult),32);
    bufp->fullCData(oldp+31,(vlSelf->top__DOT__RdE),5);
    bufp->fullBit(oldp+32,(vlSelf->top__DOT__RegWriteE));
    bufp->fullBit(oldp+33,(vlSelf->top__DOT__MemWriteE));
    bufp->fullBit(oldp+34,(vlSelf->top__DOT__JumpE));
    bufp->fullBit(oldp+35,(vlSelf->top__DOT__BranchE));
    bufp->fullCData(oldp+36,(vlSelf->top__DOT__sizeSrcE),3);
    bufp->fullCData(oldp+37,(vlSelf->top__DOT__ResultSrcE),2);
    bufp->fullCData(oldp+38,(vlSelf->top__DOT__ALUControlE),4);
    bufp->fullIData(oldp+39,(vlSelf->top__DOT__ALUResultM),32);
    bufp->fullIData(oldp+40,(vlSelf->top__DOT__WriteDataM),32);
    bufp->fullIData(oldp+41,(vlSelf->top__DOT__ReadData),32);
    bufp->fullIData(oldp+42,(vlSelf->top__DOT__PCPlus4M),32);
    bufp->fullCData(oldp+43,(vlSelf->top__DOT__RdM),5);
    bufp->fullBit(oldp+44,(vlSelf->top__DOT__RegWriteM));
    bufp->fullBit(oldp+45,(vlSelf->top__DOT__MemWriteM));
    bufp->fullCData(oldp+46,(vlSelf->top__DOT__sizeSrcM),3);
    bufp->fullCData(oldp+47,(vlSelf->top__DOT__ResultSrcM),2);
    bufp->fullIData(oldp+48,(vlSelf->top__DOT__ALUResultW),32);
    bufp->fullIData(oldp+49,(vlSelf->top__DOT__PCPlus4W),32);
    bufp->fullIData(oldp+50,(vlSelf->top__DOT__ResultW),32);
    bufp->fullCData(oldp+51,(vlSelf->top__DOT__RdW),5);
    bufp->fullBit(oldp+52,(vlSelf->top__DOT__RegWriteW));
    bufp->fullBit(oldp+53,(vlSelf->top__DOT__Flush));
    bufp->fullBit(oldp+54,(vlSelf->top__DOT__stall));
    bufp->fullBit(oldp+55,((1U == (IData)(vlSelf->top__DOT__ResultSrcE))));
    bufp->fullCData(oldp+56,(vlSelf->top__DOT__ForwardAE),2);
    bufp->fullCData(oldp+57,(vlSelf->top__DOT__ForwardBE),2);
    bufp->fullIData(oldp+58,(vlSelf->top__DOT__SrcAE),32);
    bufp->fullIData(oldp+59,(vlSelf->top__DOT__WriteDataE),32);
    bufp->fullBit(oldp+60,(vlSelf->top__DOT__jalrSrc));
    bufp->fullBit(oldp+61,(((IData)(vlSelf->top__DOT__JumpE) 
                            | ((IData)(vlSelf->top__DOT__BranchE) 
                               & (IData)(vlSelf->top__DOT__zero)))));
    bufp->fullBit(oldp+62,(vlSelf->top__DOT__zero));
    bufp->fullIData(oldp+63,((0x1ffffU & vlSelf->top__DOT__ALUResultM)),17);
    bufp->fullCData(oldp+64,((0x1fU & (vlSelf->top__DOT__instrD 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+65,((0x1fU & (vlSelf->top__DOT__instrD 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+66,((0x1fU & (vlSelf->top__DOT__instrD 
                                       >> 7U))),5);
    bufp->fullCData(oldp+67,((0x7fU & vlSelf->top__DOT__instrD)),7);
    bufp->fullCData(oldp+68,((7U & (vlSelf->top__DOT__instrD 
                                    >> 0xcU))),3);
    bufp->fullBit(oldp+69,((1U & (vlSelf->top__DOT__instrD 
                                  >> 0x1eU))));
    bufp->fullCData(oldp+70,(vlSelf->top__DOT__controlUnit__DOT__aluOp),2);
    bufp->fullBit(oldp+71,((1U & (vlSelf->top__DOT__instrD 
                                  >> 5U))));
    bufp->fullCData(oldp+72,(((2U & (vlSelf->top__DOT__instrD 
                                     >> 4U)) | (1U 
                                                & (vlSelf->top__DOT__instrD 
                                                   >> 0x1eU)))),2);
    bufp->fullIData(oldp+73,(vlSelf->top__DOT__regfile__DOT__rom_array[0]),32);
    bufp->fullIData(oldp+74,(vlSelf->top__DOT__regfile__DOT__rom_array[1]),32);
    bufp->fullIData(oldp+75,(vlSelf->top__DOT__regfile__DOT__rom_array[2]),32);
    bufp->fullIData(oldp+76,(vlSelf->top__DOT__regfile__DOT__rom_array[3]),32);
    bufp->fullIData(oldp+77,(vlSelf->top__DOT__regfile__DOT__rom_array[4]),32);
    bufp->fullIData(oldp+78,(vlSelf->top__DOT__regfile__DOT__rom_array[5]),32);
    bufp->fullIData(oldp+79,(vlSelf->top__DOT__regfile__DOT__rom_array[6]),32);
    bufp->fullIData(oldp+80,(vlSelf->top__DOT__regfile__DOT__rom_array[7]),32);
    bufp->fullIData(oldp+81,(vlSelf->top__DOT__regfile__DOT__rom_array[8]),32);
    bufp->fullIData(oldp+82,(vlSelf->top__DOT__regfile__DOT__rom_array[9]),32);
    bufp->fullIData(oldp+83,(vlSelf->top__DOT__regfile__DOT__rom_array[10]),32);
    bufp->fullIData(oldp+84,(vlSelf->top__DOT__regfile__DOT__rom_array[11]),32);
    bufp->fullIData(oldp+85,(vlSelf->top__DOT__regfile__DOT__rom_array[12]),32);
    bufp->fullIData(oldp+86,(vlSelf->top__DOT__regfile__DOT__rom_array[13]),32);
    bufp->fullIData(oldp+87,(vlSelf->top__DOT__regfile__DOT__rom_array[14]),32);
    bufp->fullIData(oldp+88,(vlSelf->top__DOT__regfile__DOT__rom_array[15]),32);
    bufp->fullIData(oldp+89,(vlSelf->top__DOT__regfile__DOT__rom_array[16]),32);
    bufp->fullIData(oldp+90,(vlSelf->top__DOT__regfile__DOT__rom_array[17]),32);
    bufp->fullIData(oldp+91,(vlSelf->top__DOT__regfile__DOT__rom_array[18]),32);
    bufp->fullIData(oldp+92,(vlSelf->top__DOT__regfile__DOT__rom_array[19]),32);
    bufp->fullIData(oldp+93,(vlSelf->top__DOT__regfile__DOT__rom_array[20]),32);
    bufp->fullIData(oldp+94,(vlSelf->top__DOT__regfile__DOT__rom_array[21]),32);
    bufp->fullIData(oldp+95,(vlSelf->top__DOT__regfile__DOT__rom_array[22]),32);
    bufp->fullIData(oldp+96,(vlSelf->top__DOT__regfile__DOT__rom_array[23]),32);
    bufp->fullIData(oldp+97,(vlSelf->top__DOT__regfile__DOT__rom_array[24]),32);
    bufp->fullIData(oldp+98,(vlSelf->top__DOT__regfile__DOT__rom_array[25]),32);
    bufp->fullIData(oldp+99,(vlSelf->top__DOT__regfile__DOT__rom_array[26]),32);
    bufp->fullIData(oldp+100,(vlSelf->top__DOT__regfile__DOT__rom_array[27]),32);
    bufp->fullIData(oldp+101,(vlSelf->top__DOT__regfile__DOT__rom_array[28]),32);
    bufp->fullIData(oldp+102,(vlSelf->top__DOT__regfile__DOT__rom_array[29]),32);
    bufp->fullIData(oldp+103,(vlSelf->top__DOT__regfile__DOT__rom_array[30]),32);
    bufp->fullIData(oldp+104,(vlSelf->top__DOT__regfile__DOT__rom_array[31]),32);
    bufp->fullBit(oldp+105,(vlSelf->clk));
    bufp->fullBit(oldp+106,(vlSelf->rst));
    bufp->fullIData(oldp+107,(vlSelf->a0),32);
    bufp->fullIData(oldp+108,(vlSelf->top__DOT__regfile__DOT__rom_array
                              [(0x1fU & (vlSelf->top__DOT__instrD 
                                         >> 0xfU))]),32);
    bufp->fullIData(oldp+109,(vlSelf->top__DOT__regfile__DOT__rom_array
                              [(0x1fU & (vlSelf->top__DOT__instrD 
                                         >> 0x14U))]),32);
    bufp->fullIData(oldp+110,(0x20U),32);
    bufp->fullIData(oldp+111,(0x11U),32);
    bufp->fullIData(oldp+112,(5U),32);
    bufp->fullIData(oldp+113,(4U),32);
}
