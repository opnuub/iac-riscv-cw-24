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
    output  logic [DATA_WIDTH-1:0]  a0
);

    // Declare all internal signals
    // Fetch Stage
    logic [DATA_WIDTH-1:0] PCPlus4F, instr, pc, PCTargetE, nextPC;

    // Decode Stage
    logic [DATA_WIDTH-1:0] PCd, PCPlus4D, rd1, rd2, ImmExtD, instrD;
    logic RegWriteD, MemWriteD, JumpD, BranchD, ALUSrcD;
    logic [2:0] ALUControlD, sizeSrcD;
    logic [1:0] ResultSrcD, immSrcD;

    // Execute Stage
    logic [DATA_WIDTH-1:0] PCe, PCPlus4E, ImmExtE, rd1E, rd2E, srcB, aluResult;
    logic [4:0] RdE;
    logic RegWriteE, MemWriteE, JumpE, BranchE, ALUSrcE;
    logic [2:0] ALUControlE, sizeSrcE;
    logic [1:0] ResultSrcE;

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

    //Hazard Unit
    logic Flush;

    // Additional Signals
    logic jalrSrc, pcSrc, zero;


    always_ff @(posedge clk) begin
    $display(" ");

    // Debug Fetch Stage
    // $display("Fetch Stage:");
    $display("NEW Instruction: %h, Opcode: %b", instr, instr[6:0]); 
    $display("pc_F: %h, instr_F: %h", pc, instr);
    // $display("pc_Plus4_F: %h, pc_next_F: %h", pc_Plus4_F, pc_next_F);

    // $display("PCSrce_E: %b", PCSrc_E);

    // // Debug Decode Stage
    // $display("Decode Stage:");
    // $display("signextend opcode: %b, Sign extended value: %h", immSrc_D, ImmExt_D);    
    // $display("regwrite_D: %b", regWrite_D);
    // $display("regwrite_E: %b", regWrite_E);
    // $display("regwrite_M: %b", regWrite_M);
    // $display("regFileOut1_D: %h, regFileOut2_D: %h, ImmExt_D: %h", regFileOut1_D, regFileOut2_D, ImmExt_D);
    // $display("Instruction Decode: rd: %0d, rs1: %0d, rs2: %0d", instr_D[11:7], instr_D[19:15], instr_D[24:20]);
    // // $display("resultSrc_D: %b", resultSrc_D);

    // // Debug Execute Stage
    // $display("Execute Stage:");
    // $display("Jump_E: %b, zero_E %b", jump_E, zero_E);
    // $display("ALUout_E: %h, ALU_in2_E: %h, mux4SrcA_OUT: %h", ALUout_E, ALU_in2_E, mux4SrcA_OUT);
    // $display("regFileOut1_E: %h, regFileOut2_E: %h", regFileOut1_E, regFileOut2_E);
    // $display("ALU Control: %b, ALU Src: %b", ALUcontrol_E, ALUsrc_E);
    // $display("memread_E %b", MemRead_E);
    // $display("resultSrc_E: %b", resultSrc_E);

    // // Debug Memory Stage
    // $display("Memory Stage:");
    // $display("ALUout_M: %h, WriteData_M: %h, ReadMem_out_M: %h", ALUout_M, WriteData_M, ReadMem_out_M);
    // $display("resultSrc_M: %b", resultSrc_M);
    // // $display("memread_M %b, Memory Control: %b", MemRead_M, MemCtrl_M);
    // if (memWrite_M) begin
    //     $display("Memory Write Enabled: Writing to memory: %h, Data: %h", ALUout_M, WriteData_M);
    // end

    // // Debug Writeback Stage
    // $display("Writeback Stage:");
    // $display("ALUout_W: %h, ReadMem_out_W: %h, pc_Plus4_W: %h", ALUout_W, ReadMem_out_W, pc_Plus4_W);
    // $display("resultSrc_W: %b (0: ALUout_W, 1: ReadMem_out_W, 2: pc_Plus4_W)", resultSrc_W);
    // $display("regwrite: %b", regWrite_W);

    // if (regWrite_W) begin
    //     $display("Register Write Enabled: Writing to Register: %0d, Data: %h", destinationReg_W, Result_W);
    // //     $display("This is a0:  ", a0);
    // end
    // if (memWrite_M) begin
    //     $display("Memory Write Enabled: Writing to Memory: %0d, Data: %h", ALUout_M[17:0], WriteData_M);
    // //     $display("This is a0:  ", a0);
    // end


    // // Debug Hazard Unit
     $display("Hazard Unit:");
     $display(", flush: %b",/* stall,*/Flush);//stall: %b
    // $display("ForwardA_e: %b, ForwardB_e: %b", forwardA_e, forwardB_e);
end


    HazardUnit #(
    ) HazardUnit (
    .zero(zero),
    .Flush(Flush)
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
        .instr(instr),
        .Flush(Flush),
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
        .a0(a0)
    );

    PRegDecode #(
        .DATA_WIDTH(DATA_WIDTH)
    ) PRegDecode (
        .Flush(Flush),
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
        .ALUSrcE(ALUSrcE)
    );

    aluMux #(
        .DATA_WIDTH(DATA_WIDTH)
    ) aluMux (
        .immOp(ImmExtE),
        .regOp2(rd2E),
        .aluSrc(ALUSrcE),
        .srcB(srcB)
    );

    alu #(
        .DATA_WIDTH(DATA_WIDTH)
    ) alu (
        .srcA(rd1E),
        .srcB(srcB),
        .aluControl(ALUControlE),
        .aluResult(aluResult)
    );

    branchUnit #(
        .DATA_WIDTH(DATA_WIDTH)
    ) branchUnit_inst (
        .srcA(rd1E),
        .srcB(srcB),
        .aluControl(ALUControlE),
        .zero(zero)
    );

    extendPC #(   
    .DATA_WIDTH(DATA_WIDTH),
    .ADDR_WIDTH(ADDR_WIDTH)
    ) extendPC (
    .pc(PCe),
    .immOp(ImmExtE),
    .result(ResultW),
    .jalrSrc(jalrSrc),
    .PCTargetE(PCTargetE)
    );

    PRegExecute #(
        .DATA_WIDTH(DATA_WIDTH)
    ) PRegExecute (
        .sizeSrcE(sizeSrcE),
        .sizeSrcM(sizeSrcM),
        .rst(rst),
        .ALUout(aluResult),
        .WriteData(rd2E),
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
        .ReadData(ReadData)
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
