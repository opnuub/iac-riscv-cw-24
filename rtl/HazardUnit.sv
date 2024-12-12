module HazardUnit #(
) ( 
    input logic [4:0]       Rs1E,
    input logic [4:0]       Rs2E,
    input logic [4:0]       Rs1D,
    input logic [4:0]       Rs2D,
    input logic [4:0]       RdE,
    input logic [4:0]       destReg_m,
    input logic [4:0]       destReg_w,
    input logic             memoryRead_e,
    input logic             RegWriteM,
    input logic             RegWriteW,
    input logic             zero_hazard,
    input logic             jump_hazard,
    input logic             mem_stall,       // From MemoryController
    input logic             l1_miss,         // New: L1 cache miss signal
    input logic             l2_miss,         // New: L2 cache miss signal
    input logic             cache_busy,      // New: Cache busy signal
    output logic [1:0]      ForwardAE,
    output logic [1:0]      ForwardBE,
    output logic            stall,
    output logic            FlushD,
    output logic            FlushE
);

    logic load_use_hazard;
    logic control_hazard;
    logic memory_hazard;   

    always_comb begin
        ForwardAE = 2'b00;
        ForwardBE = 2'b00;
        stall = 1'b0;
        FlushD = 1'b0;
        FlushE = 1'b0;
        
        //Data forwarding logic for Source A
        if (RegWriteM && (destReg_m != 5'b0) && (destReg_m == Rs1E))
            ForwardAE = 2'b10;  
        else if (RegWriteW && (destReg_w != 5'b0) && (destReg_w == Rs1E) && 
                !(RegWriteM && destReg_m != 5'b0 && destReg_m == Rs1E))
            ForwardAE = 2'b01; 
        else 
            ForwardAE = 2'b00;

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
        control_hazard = zero_hazard || jump_hazard;

        // Memory hazard detection (enhanced)
        memory_hazard = l1_miss || l2_miss || cache_busy;


        
        // Combined stall and flush logic



        if (load_use_hazard) begin
            stall = 1'b1;
            // FlushE = 1'b1;
            // FlushD = 1'b0;
        end else if (control_hazard) begin
            stall = 1'b0;
            FlushD = 1'b1;
            FlushE = 1'b1;
        end else if ((l1_miss || l2_miss || cache_busy)&mem_stall) begin
            stall = 1'b1;  
            FlushD = 1'b0;
            FlushE = 1'b0;
        end else if (mem_stall) begin
            stall = 1'b1;   
            FlushD = 1'b1;   
            FlushE = 1'b1; 
        end


        // if (load_use_hazard) begin
        //     stall = 1'b1;
        //     FlushE = 1'b1;
        //     FlushD = 1'b0;
        // end else if (control_hazard) begin
        //     stall = 1'b0;
        //     FlushD = 1'b1;
        //     FlushE = 1'b1;
        // end else if ((l1_miss || l2_miss || cache_busy)&mem_stall) begin
        //     stall = 1'b1;  
        //     FlushD = 1'b0;
        //     FlushE = 1'b0;
        // end else if (mem_stall) begin
        //     stall = 1'b1;   
        //     FlushE = 1'b1;   
        //     FlushD = 1'b0; 
        // end
end
endmodule