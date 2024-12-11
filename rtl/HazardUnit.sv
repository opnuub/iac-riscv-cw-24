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
    input logic            zero_hazard,      // Branch taken signal
    input logic            jump_hazard,      // Jump instruction in Execute stage
    input logic            mem_stall,        // Memory/Cache stall signal
    output logic [1:0]     ForwardAE,       // Forwarding control for Source A
    output logic [1:0]     ForwardBE,       // Forwarding control for Source B
    output logic           stall,           // Pipeline stall signal
    output logic           FlushD,          // Flush Decode stage
    output logic           FlushE           // Flush Execute stage
);

    // Default assignments
    logic load_use_hazard;
    logic control_hazard;
    
always_comb begin
    // Initialize outputs
    ForwardAE = 2'b00;
    ForwardBE = 2'b00;
    stall = 1'b0;
    FlushD = 1'b0;
    FlushE = 1'b0;

    // Data forwarding logic for Source A
    if (RegWriteM && (destReg_m != 5'b0) && (destReg_m == Rs1E)) begin
        ForwardAE = 2'b10;  // Forward from Memory stage
    end else if (RegWriteW && (destReg_w != 5'b0) && (destReg_w == Rs1E)) begin
        ForwardAE = 2'b01;  // Forward from Writeback stage
    end

    // Data forwarding logic for Source B
    if (RegWriteM && (destReg_m != 5'b0) && (destReg_m == Rs2E)) begin
        ForwardBE = 2'b10;  // Forward from Memory stage
    end else if (RegWriteW && (destReg_w != 5'b0) && (destReg_w == Rs2E)) begin
        ForwardBE = 2'b01;  // Forward from Writeback stage
    end

    // Load-use hazard detection
    assign load_use_hazard = memoryRead_e && 
                      ((RdE == Rs1D && Rs1D != 5'b0) || (RdE == Rs2D && Rs2D != 5'b0));
    
    // Control hazard detection
    assign control_hazard = zero_hazard || jump_hazard;

    // Stall and flush logic
    if (load_use_hazard) begin // memstall might required!!!
        stall = 1'b1;   // Pipeline stall due to load-use or memory stall
        FlushE = 1'b1;  // Flush Execute stage to avoid incorrect execution
        FlushD = 1'b0;  // Decode stage is retained to prevent instruction loss
    end else if (control_hazard) begin
        stall = 1'b0;   // No stall for control hazards
        FlushD = 1'b1;  // Flush Decode stage
        FlushE = 1'b1;  // Flush Execute stage
    end else if (mem_stall) begin
        stall = 1'b1;   // Pipeline stall due to memory stall
        FlushE = 1'b1;  // Flush Execute stage to avoid incorrect execution
        FlushD = 1'b0;  // Decode stage is retained to prevent instruction loss
    end else begin
        stall = 1'b0;  
        FlushD = 1'b0;
        FlushE = 1'b0;
    end
end
endmodule