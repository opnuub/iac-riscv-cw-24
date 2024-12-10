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
    input logic             mem_stall,     // New signal for memory stalls
    output logic [1:0]      ForwardAE,
    output logic [1:0]      ForwardBE,  
    output logic            stall,          
    output logic            Flush
);

    always_comb begin
        stall = 1'b0;
        Flush = 1'b0;
        ForwardAE = 2'b00;
        ForwardBE = 2'b00;

        // Forwarding logic
        if (RegWriteM && (destReg_m != 0) && (destReg_m == Rs1E)) begin
            ForwardAE = 2'b10;
        end 
        else if (RegWriteW && (destReg_w != 0) && (destReg_w == Rs1E)) begin
            ForwardAE = 2'b01;
        end 

        if (RegWriteM && (destReg_m != 0) && (destReg_m == Rs2E)) begin
            ForwardBE = 2'b10;
        end
        else if (RegWriteW && (destReg_w != 0) && (destReg_w == Rs2E)) begin
            ForwardBE = 2'b01;
        end

        // Stall logic, which includes memory stalls
        if ((memoryRead_e && ((RdE == Rs1D) || (RdE == Rs2D))) || mem_stall) begin
            stall = 1'b1;
        end

        // Flush logic
        Flush = (zero_hazard || jump_hazard);
    end

endmodule
