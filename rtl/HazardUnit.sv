module HazardUnit #(
) ( 
    input logic [4:0]       Rs1E,            // Source register 1 in Execute stage
    input logic [4:0]       Rs2E,            // Source register 2 in Execute stage
    input logic [4:0]       Rs1D,            // Source register 1 in Decode stage
    input logic [4:0]       Rs2D,            // Source register 2 in Decode stage
    input logic [4:0]       RdE,             // Destination register in Execute stage
    input logic [4:0]       destReg_m,       // Destination register in Memory stage
    input logic [4:0]       destReg_w,       // Destination register in Writeback stage
    input logic             memoryRead_e,    // Memory read enable in Execute stage
    input logic             RegWriteM,       // Register write enable in Memory stage
    input logic             RegWriteW,       // Register write enable in Writeback stage
    input logic             zero_hazard,     // Branch condition for zero hazard
    input logic             jump_hazard,     // Hazard due to jump instructions
    output logic [1:0]      ForwardAE,       // Forwarding control for Source A
    output logic [1:0]      ForwardBE,       // Forwarding control for Source B
    output logic            stall,           // Pipeline stall signal
    output logic            FlushD,          // Flush Decode stage
    output logic            FlushE           // Flush Execute stage
);

    // Reset hazard outputs
    always_comb begin
        stall = 1'b0;
        FlushD = 1'b0;
        FlushE = 1'b0;
        ForwardAE = 2'b00;
        ForwardBE = 2'b00;

        // ==========================================================
        //                     Forwarding Logic
        // ==========================================================

        // Forwarding for Source A in Execute stage
        if (RegWriteM && (destReg_m != 0) && (destReg_m == Rs1E)) begin
            ForwardAE = 2'b10;  // Forward from ALU result in Memory stage
        end 
        else if (RegWriteW && (destReg_w != 0) && (destReg_w == Rs1E)) begin
            ForwardAE = 2'b01;  // Forward from Writeback stage
        end 
        else begin
            ForwardAE = 2'b00;  // No forwarding
        end

        // Forwarding for Source B in Execute stage
        if (RegWriteM && (destReg_m != 0) && (destReg_m == Rs2E)) begin
            ForwardBE = 2'b10;  // Forward from ALU result in Memory stage
        end 
        else if (RegWriteW && (destReg_w != 0) && (destReg_w == Rs2E)) begin
            ForwardBE = 2'b01;  // Forward from Writeback stage
        end 
        else begin
            ForwardBE = 2'b00;  // No forwarding
        end

        // ==========================================================
        //                       Stalling Logic
        // ==========================================================
        // Stall the pipeline when:
        // - Memory read in Execute stage (load instruction)
        // - Destination register in Execute matches source registers in Decode
        if (memoryRead_e && ((RdE == Rs1D) || (RdE == Rs2D))) begin
            stall = 1'b1;
        end 
        else begin
            stall = 1'b0;
        end

        // ==========================================================
        //                       Flushing Logic
        // ==========================================================
        // Flush Decode and Execute stages for hazards:
        // - Branch taken (zero hazard)
        // - Jump instruction hazard
        // - Stall due to data hazards
        if (zero_hazard || jump_hazard) begin
            FlushD = 1'b1;
            FlushE = 1'b1;
        end
        else if (stall) begin
            FlushE = 1'b1;  // Flush Execute only during stalls
        end
        else begin
            FlushD = 1'b0;
            FlushE = 1'b0;
        end
    end

endmodule
