module top #(
    parameter DATA_WIDTH = 32,
    parameter INSTR_WIDTH = 32,
    parameter ADDR_WIDTH = 32,
    parameter MEM_ADDR_WIDTH = 17,
    parameter REG_DATA_WIDTH = 5,
    parameter OFFSET = 4,
    
    // Cache-related parameters
    parameter L1_SET_WIDTH = 5,
    parameter L2_SET_WIDTH = 6,
    parameter L3_SET_WIDTH = 8
) (
    input   logic                   clk,
    input   logic                   rst,
    output  logic [DATA_WIDTH-1:0]  a0
);

    // Internal signals
    // Fetch Stage
    logic [DATA_WIDTH-1:0] PCPlus4F, instr, pc, PCTargetE, nextPC;

    // Decode Stage
    logic [DATA_WIDTH-1:0] PCd, PCPlus4D, rd1, rd2, ImmExtD, instrD;
    logic RegWriteD, MemWriteD, JumpD, BranchD, ALUSrcD;
    logic [2:0] sizeSrcD;
    logic [1:0] ResultSrcD, immSrcD;
    logic [3:0] ALUControlD;

    // Execute Stage
    logic [DATA_WIDTH-1:0] PCe, PCEn, PCPlus4E, ImmExtE, rd1E, rd2E, srcB, aluResult;
    logic [4:0] RdE;
    logic RegWriteE, MemWriteE, JumpE, BranchE, ALUSrcE;
    logic [2:0] sizeSrcE;
    logic [1:0] ResultSrcE;
    logic [3:0] ALUControlE;

    // Memory Stage
    logic [DATA_WIDTH-1:0] ALUResultM, WriteDataM, ReadData, PCPlus4M;
    logic [4:0] RdM;
    logic RegWriteM, MemWriteM;
    logic [2:0] sizeSrcM;
    logic [1:0] ResultSrcM;

    // Write-Back Stage
    logic [DATA_WIDTH-1:0] ALUResultW, ReadDataW, PCPlus4W, ResultW;
    logic [4:0] RdW;
    logic RegWriteW;
    logic [1:0] ResultSrcW;

    // Hazard Unit
    logic FlushD, FlushE, stall, memoryRead;
    logic [1:0] ForwardAE, ForwardBE;
    logic [DATA_WIDTH-1:0] SrcAE, WriteDataE;
    logic [4:0] Rs1E, Rs2E;

    // Additional Signals
    logic jalrSrc, pcSrc, zero, JalrE;
    
    // Memory System Signals
    logic MemReady;

    always_comb begin
        memoryRead = (ResultSrcE == 2'b01);
    end
    MMU #(
        .ADDR_WIDTH(ADDR_WIDTH)
    ) mmu (
        .clk(clk),
        .rst_n(!rst),
        .virtual_addr(ALUResultM),
        .read_enable(ResultSrcE == 2'b01),
        .write_enable(MemWriteM),
        .physical_addr(physical_addr),
        .access_fault(mmu_access_fault),
        .page_fault(mmu_page_fault),
        .busy(mmu_busy),
        .privilege_mode(privilege_mode),
        .mem_read(mmu_mem_read),
        .mem_write(mmu_mem_write),
        .mem_addr(mmu_mem_addr),
        .mem_rdata(ReadData),
        .mem_ready(MemReady)
    );
    ExceptionHandler #(
        .ADDR_WIDTH(ADDR_WIDTH)
    ) exception_handler (
        .clk(clk),
        .rst_n(!rst),
        .exception_raised(mmu_access_fault || mmu_page_fault),
        .exception_cause({1'b0, mmu_page_fault, mmu_access_fault}),
        .exception_pc(pc),
        .handler_pc(exception_handler_pc),
        .exception_handled(exception_handled),
        .new_privilege_mode(new_privilege_mode)
    );
    MemoryProtectionUnit #(
        .ADDR_WIDTH(ADDR_WIDTH)
    ) mpu (
        .address(ALUResultM),
        .privilege_mode(privilege_mode),
        .read_access(ResultSrcE == 2'b01),
        .write_access(MemWriteM),
        .protection_fault(mpu_fault)
    );

    // Hazard detection and forwarding
    assign mem_stall = mmu_busy || !MemReady;

    HazardUnit hazard_unit (
        .Rs1E(Rs1E),
        .Rs2E(Rs2E),
        .Rs1D(instrD[19:15]),
        .Rs2D(instrD[24:20]),
        .RdE(RdE),
        .destReg_m(RdM),
        .destReg_w(RdW),
        .memoryRead_e(memoryRead),
        .RegWriteM(RegWriteM),
        .RegWriteW(RegWriteW),
        .zero_hazard(zero),
        .jump_hazard(JumpE),
        .mem_stall(mem_stall),  // Modified to include MMU stalls
        .ForwardAE(ForwardAE),
        .ForwardBE(ForwardBE),
        .stall(stall),
        .FlushD(FlushD),
        .FlushE(FlushE)
    );

    // Forwarding muxes
    HazardMux #(
        .DATA_WIDTH(DATA_WIDTH)
    ) HazardMux1 (
        .rdE(rd1E),
        .ResultW(ResultW),
        .ALUResultM(ALUResultM),
        .Forward(ForwardAE),
        .Out(SrcAE)
    );

    HazardMux #(
        .DATA_WIDTH(DATA_WIDTH)
    ) HazardMux2 (
        .rdE(rd2E),
        .ResultW(ResultW),
        .ALUResultM(ALUResultM),
        .Forward(ForwardBE),
        .Out(WriteDataE)
    );

    // PC control
    pcMux #(
        .ADDR_WIDTH(ADDR_WIDTH)
    ) pcMux (
        .branchPC(PCTargetE),
        .PCPlus4F(PCPlus4F),
        .PCsrc(pcSrc),
        .nextPC(nextPC)
    );

    PCMuxSelect PCMuxSelect (
        .zero(zero),
        .JumpE(JumpE),
        .BranchE(BranchE),
        .pcSrcE(pcSrc)
    );

    // Fetch stage
    pcReg #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .OFFSET(OFFSET)
    ) pcReg (
        .stall(stall),
        .clk(clk),
        .rst(rst),
        .nextPC(nextPC),
        .pc(pc),
        .PCPlus4F(PCPlus4F)
    );

    instrMemory #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .INSTR_WIDTH(INSTR_WIDTH)
    ) instrMemory (
        .pc(pc),
        .instr(instr)
    );

    PRegFetch #(
        .DATA_WIDTH(DATA_WIDTH)
    ) PRegFetch (
        .stall(stall),
        .instr(instr),
        .Flush(FlushD),
        .rst(rst),
        .PCf(pc),
        .PCPlus4F(PCPlus4F),
        .clk(clk),
        .PCPlus4D(PCPlus4D),
        .PCd(PCd),
        .InstrD(instrD)
    );

    // Decode stage
    controlUnit controlUnit (
        .op(instrD[6:0]),
        .funct3(instrD[14:12]),
        .funct7(instrD[30]),
        .regWrite(RegWriteD),
        .resultSrc(ResultSrcD),
        .memWrite(MemWriteD),
        .jumpSrc(JumpD),
        .Branch(BranchD),
        .jalrSrc(jalrSrc),
        .aluControl(ALUControlD),
        .aluSrc(ALUSrcD),
        .immSrc(immSrcD),
        .sizeSrc(sizeSrcD)
    );

    extend #(
        .INSTR_WIDTH(INSTR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) extend (
        .instruction(instrD),
        .immSrc(immSrcD),
        .jumpSrc(JumpD),
        .immExt(ImmExtD)
    );

    regfile #(
        .DATA_WIDTH(DATA_WIDTH),
        .REG_DATA_WIDTH(REG_DATA_WIDTH)
    ) regfile (
        .clk(clk),
        .rs1(instrD[19:15]),
        .rs2(instrD[24:20]),
        .rd(RdW),
        .RegWrite(RegWriteW),
        .ResultW(ResultW),
        .ALUop1(rd1),
        .regOp2(rd2),
        .a0(a0)
    );

    PRegDecode #(
        .DATA_WIDTH(DATA_WIDTH)
    ) PRegDecode (
        .Rs1D(instrD[19:15]), 
        .Rs2D(instrD[24:20]),
        .Rs1E(Rs1E),
        .Rs2E(Rs2E),
        .Flush(FlushE),
        .sizeSrcD(sizeSrcD),
        .sizeSrcE(sizeSrcE),
        .rd1(rd1),
        .rd2(rd2),
        .PCd(PCd),
        .ImmExtD(ImmExtD),
        .clk(clk),
        .rst(rst),
        .RdD(instrD[11:7]),
        .PCPlus4D(PCPlus4D),
        .rd1E(rd1E),
        .rd2E(rd2E),
        .PCe(PCe),
        .RdE(RdE),
        .ImmExtE(ImmExtE),
        .PcPlus4E(PCPlus4E),
        .RegWriteD(RegWriteD),
        .ResultSrcD(ResultSrcD),
        .MemWriteD(MemWriteD),
        .JumpD(JumpD),
        .BranchD(BranchD),
        .ALUControl(ALUControlD),
        .ALUSrcD(ALUSrcD),
        .RegWriteE(RegWriteE),
        .ResultSrcE(ResultSrcE),
        .MemWriteE(MemWriteE),
        .JumpE(JumpE),
        .BranchE(BranchE),
        .ALUControlE(ALUControlE),
        .ALUSrcE(ALUSrcE),
        .jalrSrc(jalrSrc),
        .JalrE(JalrE)
    );

    // Execute stage
    aluMux #(
        .DATA_WIDTH(DATA_WIDTH)
    ) aluMux (
        .immOp(ImmExtE),
        .regOp2(WriteDataE),
        .aluSrc(ALUSrcE),
        .srcB(srcB)
    );

    alu #(
        .DATA_WIDTH(DATA_WIDTH)
    ) alu (
        .srcA(SrcAE),
        .srcB(srcB),
        .aluControl(ALUControlE),
        .aluResult(aluResult)
    );

    branchUnit #(
        .DATA_WIDTH(DATA_WIDTH)
    ) branchUnit_inst (
        .srcA(SrcAE),
        .srcB(srcB),
        .aluControl(ALUControlE),
        .zero(zero)
    );

    JalrMux #(
        .ADDR_WIDTH(ADDR_WIDTH)
    ) JalrMux1 (
        .Rd1E(rd1E),
        .PcE(PCe),
        .JalrE(JalrE),
        .PCEn(PCEn)
    );

    extendPC #(   
        .DATA_WIDTH(DATA_WIDTH),
        .ADDR_WIDTH(ADDR_WIDTH)
    ) extendPC (
        .PCEn(PCEn),
        .immOp(ImmExtE),
        .PCTargetE(PCTargetE)
    );

    PRegExecute #(
        .DATA_WIDTH(DATA_WIDTH)
    ) PRegExecute (
        .sizeSrcE(sizeSrcE),
        .sizeSrcM(sizeSrcM),
        .rst(rst),
        .ALUout(aluResult),
        .WriteData(WriteDataE),
        .PCPlus4E(PCPlus4E),
        .clk(clk),
        .RdE(RdE),
        .ALUResultM(ALUResultM),
        .WriteDataM(WriteDataM),
        .RdM(RdM),
        .PCPlus4M(PCPlus4M),
        .RegWriteE(RegWriteE),
        .ResultSrcE(ResultSrcE),
        .MemWriteE(MemWriteE),
        .RegWriteM(RegWriteM),
        .ResultSrcM(ResultSrcM),
        .MemWriteM(MemWriteM)
    );

    // Memory stage
    PRegMemory #(
        .DATA_WIDTH(DATA_WIDTH)
    ) PRegMemory (
        .ALUResultM(ALUResultM),
        .DMRd(ReadData),
        .RdM(RdM),
        .PCPlus4M(PCPlus4M),
        .clk(clk),
        .rst(rst),
        .RdW(RdW),
        .ALUResultW(ALUResultW),
        .ReadDataW(ReadDataW),
        .PCPlus4W(PCPlus4W),
        .RegWriteM(RegWriteM),
        .ResultSrcM(ResultSrcM),
        .RegWriteW(RegWriteW),
        .ResultSrcW(ResultSrcW)
    );

    MemoryController #(
        .DATA_WIDTH(DATA_WIDTH),
        .ADDR_WIDTH(MEM_ADDR_WIDTH)
    ) memory_controller (
        .clk(clk),
        .rst_n(!rst),
        .MemWrite(mmu_mem_write && !mmu_busy),
        .SizeCtr(sizeSrcM),
        .addr(physical_addr[MEM_ADDR_WIDTH-1:0]),
        .WriteData(WriteDataM),
        .ReadData(ReadData),
        .MemReady(MemReady),
        .regs0(),
        .s0()
    );

    // Writeback stage
    resultMux #(
        .DATA_WIDTH(DATA_WIDTH)
    ) resultMux (
        .ReadDataW(ReadDataW),
        .ALUResult(ALUResultW),
        .PCPlus4(PCPlus4W),
        .ResultSrc(ResultSrcW),
        .Result(ResultW)
    );

endmodule