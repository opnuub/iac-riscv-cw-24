module top #( //!!!!!!this file is still filled with errors, I am not finished yet
    parameter DATA_WIDTH = 32,
    parameter INSTR_WIDTH = 32,
    parameter ADDR_WIDTH = 32,
    parameter MEM_ADDR_WIDTH = 17,
    parameter REG_DATA_WIDTH = 5,
    parameter OFFSET = 4
) (
    input   logic                   clk,
    input   logic                   rst,
    //input   logic                 trigger,
    output  logic [DATA_WIDTH-1:0]  a0,
    output  logic [DATA_WIDTH-1:0]  a1,
    output  logic [DATA_WIDTH-1:0]  a2,
    output  logic [DATA_WIDTH-1:0]  a3,
    output  logic [DATA_WIDTH-1:0]  a4,
    output  logic [DATA_WIDTH-1:0]  a5,
    output  logic [DATA_WIDTH-1:0]  a6,
    output  logic [DATA_WIDTH-1:0]  s1,
    output  logic [DATA_WIDTH-1:0]  t1,
    output  logic [DATA_WIDTH-1:0]  t0,
    // output  logic [DATA_WIDTH-1:0]  rega5,
    // output  logic [DATA_WIDTH-1:0]  rega6,

output logic [DATA_WIDTH-1:0] PCPlus4F, instr, pc, PCTargetE, nextPC, PCd, PCPlus4D, rd1, rd2, ImmExtD, instrD, PCe, PCEn, PCPlus4E, ImmExtE, rd1E, rd2E, srcB, aluResult, ALUResultM, WriteDataM, ReadData, PCPlus4M, ALUResultW, ReadDataW, PCPlus4W, ResultW, SrcAE, WriteDataE,
output logic [4:0] RdE, RdM, RdW, Rs1E, Rs2E,
output logic RegWriteD, MemWriteD, JumpD, BranchD, ALUSrcD, RegWriteE, MemWriteE, JumpE, BranchE, ALUSrcE, RegWriteM, MemWriteM, RegWriteW, FlushD, FlushE, stall, memoryRead, jalrSrc, pcSrc, zero, JalrE,
output logic [2:0] sizeSrcD, sizeSrcE, sizeSrcM,
output logic [1:0] ResultSrcD, immSrcD, ResultSrcE, ResultSrcM, ResultSrcW, ForwardAE, ForwardBE,
output logic [3:0] ALUControlD, ALUControlE


);

    // Declare all internal signals
    // Fetch Stage

    // logic [DATA_WIDTH-1:0] PCPlus4F, instr, pc, PCTargetE, nextPC;

    // // Decode Stage
    // logic [DATA_WIDTH-1:0] PCd, PCPlus4D, rd1, rd2, ImmExtD, instrD;
    // logic RegWriteD, MemWriteD, JumpD, BranchD, ALUSrcD;
    // logic [2:0] sizeSrcD;
    // logic [1:0] ResultSrcD, immSrcD;
    // logic [3:0] ALUControlD;

    // // Execute Stage
    // logic [DATA_WIDTH-1:0] PCe, PCEn, PCPlus4E, ImmExtE, rd1E, rd2E, srcB, aluResult;
    // logic [4:0] RdE;
    // logic RegWriteE, MemWriteE, JumpE, BranchE, ALUSrcE;
    // logic [2:0] sizeSrcE;
    // logic [1:0] ResultSrcE;
    // logic [3:0] ALUControlE;

    // // Memory Stage
    // logic [DATA_WIDTH-1:0] ALUResultM, WriteDataM, ReadData, PCPlus4M;
    // logic [4:0] RdM;
    // logic RegWriteM, MemWriteM;
    // logic [2:0] sizeSrcM;
    // logic [1:0] ResultSrcM;

    // // Write-Back Stage
    // logic [DATA_WIDTH-1:0] ALUResultW, ReadDataW, PCPlus4W, ResultW;
    // logic [4:0] RdW;
    // logic RegWriteW;
    // logic [1:0] ResultSrcW;

    // //Hazard Unit
    // logic FlushD, FlushE, stall, memoryRead;
    // logic [1:0] ForwardAE, ForwardBE;
    // logic [DATA_WIDTH-1:0] SrcAE, WriteDataE;
    // logic [4:0] Rs1E, Rs2E;

    // // Additional Signals
    // logic jalrSrc, pcSrc, zero, JalrE;

    
//     always_ff @(posedge clk) begin
//     $display(" "); // Blank line for readability
//     $display("********** Pipeline Debug **********");

//     // Fetch Stage
//     $display("Fetch Stage:");
//     $display("Current PC: %h, Fetched Instruction: %h", pc, instr);
//     $display("Next PC: %h, PC+4: %h", nextPC, PCPlus4F);

//     // Decode Stage
//     $display("Decode Stage:");
//     $display("Instruction Decode: rd: %0d, rs1: %0d, rs2: %0d", instrD[11:7], instrD[19:15], instrD[24:20]);
//     $display("Decoded Immediate: %h, Branch: %b, Jump: %b, ALU Src: %b, ALU Control D: %b", ImmExtD, BranchD, JumpD, ALUSrcD, ALUControlD);
//     $display("Control Signals: RegWrite: %b, MemWrite: %b, ResultSrc: %b", RegWriteD, MemWriteD, ResultSrcD);

//     // Execute Stage
//     $display("Execute Stage:");
//     $display("ALU Inputs: SrcA: %d, SrcB: %d, ALU Control: %b", SrcAE, srcB, ALUControlE);
//     $display("ALU Output: %d, Zero: %b, PC Target: %h", aluResult, zero, PCTargetE);
//     $display("Control Signals: Branch: %b, Jump: %b, RegWrite: %b", BranchE, JumpE, RegWriteE);
//     $display("Forwarding: ForwardAE: %b, ForwardBE: %b", ForwardAE, ForwardBE); // Forwarding signals

//     // Memory Stage
//     $display("Memory Stage:");
//     $display("Memory Address: %h, Write Data: %h, Read Data: %h", ALUResultM, WriteDataM, ReadData);
//     $display("Control Signals: MemWrite: %b, RegWrite: %b, ResultSrc: %b", MemWriteM, RegWriteM, ResultSrcM);

//     // Write-Back Stage
//     $display("Write-Back Stage:");
//     $display("Write Back Data: %h, ALU Result: %h, PC+4: %h", ResultW, ALUResultW, PCPlus4W);
//     $display("Destination Register: %0d, RegWrite: %b", RdW, RegWriteW);

//     // Hazard Unit
//     $display("Hazard Unit:");
//     $display("Flush Signal: %b, Stall Signal: %b", Flush, stall); // Flush and stall signals
//     $display("Forwarding: ForwardAE: %b, ForwardBE: %b", ForwardAE, ForwardBE); // Forwarding signals

//     $display("************************************");
// end

// always_ff @ (posedge clk)begin
// $display("sizeSrcD: %d, sizeSrcE: %d, sizeSrcM: %d", sizeSrcD, sizeSrcE, sizeSrcM);
// end

// always_ff @(posedge clk) begin
//     if (MemWriteM) begin
//         $display("[WRITE] At clk=%0d, ALUResultM: %h, WriteDataM: %h, SizeCtr (sizeSrcM): %b", $time, ALUResultM, WriteDataM, sizeSrcM);
//     end
//     $display("a0: %h", a0);
// end


// always_comb begin
//     $display("ALUResultM: %h, ReadData: %h, ReadDataW: %h, ResultSrcW %b, ResultW %d", ALUResultM, ReadData, ReadDataW, ResultSrcW, ResultW);
//     $display("RdW: %d", RdW);
//     $display("Fetch Stage:");
//     $display("Current PC: %h, Fetched Instruction: %h", pc, instr);
//     $display("Next PC: %h, PC+4: %h", nextPC, PCPlus4F);
// end


    always_comb begin
    memoryRead = (ResultSrcE == 1); // Set memoryRead if ResultSrcE indicates a memory operation.
    end

    HazardUnit #(
    ) HazardUnit (
    .Rs1E(Rs1E), 
    .Rs2E(Rs2E),  
    .Rs1D(instrD[19:15]), 
    .Rs2D(instrD[24:20]),     
    .RdE(RdE),
    .destReg_m(RdM),  
    .destReg_w(RdW),
    .memoryRead_e(memoryRead),//when you are doing load -> loading data from memory //
    .RegWriteM(RegWriteM),     
    .RegWriteW(RegWriteW),   
    .zero_hazard(zero),   
    .jump_hazard(JumpE),
    .ForwardAE(ForwardAE),
    .ForwardBE(ForwardBE),  
    .stall(stall),          
    .FlushD(FlushD),
    .FlushE(FlushE)
    );

    HazardMux #(
    .DATA_WIDTH(DATA_WIDTH)
    ) HazardMux1 (
    .rdE(rd1E),
    .ResultW(ResultW),
    .ALUResultM(ALUResultM),
    .Forward(ForwardAE),
    .Out(SrcAE)
    );

    HazardMux2 #(
    .DATA_WIDTH(DATA_WIDTH)
    ) HazardMux2 (
    .rdE(rd2E),
    .ResultW(ResultW),
    .ALUResultM(ALUResultM),
    .Forward(ForwardBE),
    .Out(WriteDataE)
    );

    pcMux #(
    .ADDR_WIDTH(ADDR_WIDTH)
    ) pcMux (
    .branchPC(PCTargetE),
    .PCPlus4F(PCPlus4F),
    .PCsrc(pcSrc),
    .nextPC(nextPC)
    );

    PCMuxSelect #(
    ) PCMuxSelect (
    .zero(zero),
    .JumpE(JumpE),
    .BranchE(BranchE),
    .pcSrcE(pcSrc)
    );

    // Fetch Stage
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

    // Decode Stage
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
        .a0(a0),
        //for Testing:
        .a1(a1),
        .a2(a2),
        .a3(a3),
        .a4(a4),
        .a5(a5),
        .a6(a6),
        .t1(t1),
        .s1(s1),
        .t0(t0)
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

    PRegMemory # (
        .DATA_WIDTH(DATA_WIDTH)
    ) PRegMemory (
    .ALUResultM(ALUResultM),
    .DMRd(ReadData),
    .RdM(RdM),
    .PCPlus4M(PCPlus4M),
    .clk(clk),
    .rst(rst),         // Reset signal
    .RdW(RdW),
    .ALUResultW(ALUResultW),
    .ReadDataW(ReadDataW),
    .PCPlus4W(PCPlus4W),
    .RegWriteM(RegWriteM),
    .ResultSrcM(ResultSrcM),
    .RegWriteW(RegWriteW),
    .ResultSrcW(ResultSrcW)
    );

    DataMemory #(
        .DATA_WIDTH(DATA_WIDTH),
        .ADDR_WIDTH(MEM_ADDR_WIDTH)
    ) DataMemory (
        .clk(clk),
        .SizeCtr(sizeSrcM),
        .ALUResult(ALUResultM[MEM_ADDR_WIDTH-1:0]),
        .WriteData(WriteDataM),
        .MemWrite(MemWriteM),
        .ReadData(ReadData),
        // .rega5(rega5),
        // .rega6(rega6),
        .a5(a5),
        .a6(a6)
    );

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
