module HazardUnit #(
) ( 
    input logic [4:0]       Rs1E,            // Source register 1 in Execute stage
    input logic [4:0]       Rs2E,            // Source register 2 in Execute stage
    input logic [4:0]       Rs1D,            // Source register 1 in Decode stage
    input logic [4:0]       Rs2D,            // Source register 2 in Decode stage
    input logic [4:0]       RdE,             // Destination register in Execute stage
    input logic [4:0]       destReg_m,       // Destination register in Memory stage
    input logic [4:0]       destReg_w,       // Destination register in Writeback stage
    input logic            memoryRead_e,     // Memory read enable in Execute stage
    input logic            RegWriteM,        // Register write enable in Memory stage
    input logic            RegWriteW,        // Register write enable in Writeback stage
    input logic            zero_hazard,      // Branch condition for zero hazard
    input logic            jump_hazard,      // Hazard due to jump instructions
    input logic            mem_stall,        // New: Memory stall signal from cache
    output logic [1:0]     ForwardAE,       // Forwarding control for Source A
    output logic [1:0]     ForwardBE,       // Forwarding control for Source B
    output logic           stall,           // Pipeline stall signal
    output logic           FlushD,          // Flush Decode stage
    output logic           FlushE           // Flush Execute stage
);

    // Reset hazard outputs
    always_comb begin
        // Data hazard forwarding logic
        if (RegWriteM && (destReg_m != 0) && (destReg_m == Rs1E)) begin
            ForwardAE = 2'b10;  // Forward from Memory stage
        end 
        else if (RegWriteW && (destReg_w != 0) && (destReg_w == Rs1E)) begin
            ForwardAE = 2'b01;  // Forward from Writeback stage
        end 
        else begin
            ForwardAE = 2'b00;  // No forwarding
        end

        // Forwarding for Source B
        if (RegWriteM && (destReg_m != 0) && (destReg_m == Rs2E)) begin
            ForwardBE = 2'b10;  // Forward from Memory stage
        end 
        else if (RegWriteW && (destReg_w != 0) && (destReg_w == Rs2E)) begin
            ForwardBE = 2'b01;  // Forward from Writeback stage
        end 
        else begin
            ForwardBE = 2'b00;  // No forwarding
        end

        // Stall logic
        if ((memoryRead_e && ((RdE == Rs1D) || (RdE == Rs2D))) || mem_stall) begin
            stall = 1'b1;
        end 
        else begin
            stall = 1'b0;
        end

        // Control hazard handling
        if (zero_hazard || jump_hazard) begin
            FlushD = 1'b1;
            FlushE = 1'b1;
        end
        else if (stall) begin
            FlushE = 1'b1;
            FlushD = 1'b0;
        end
        else begin
            FlushD = 1'b0;
            FlushE = 1'b0;
        end
    end

endmodule