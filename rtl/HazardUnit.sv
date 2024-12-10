module HazardUnit #(
) ( // notes say to check if source register in execute stage matches destination register in memory or writeback stage         
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
    output logic [1:0]      ForwardAE,
    output logic [1:0]      ForwardBE,  
    output logic            stall,          
    output logic            Flush
);

// if the destination register is the same as the read address in memory or writeback, and write is enabled then forward

// forwardA_E = 2'b01 means resultW gets used as the aluInput1
// forwardB_E = 2'b01 means resultW gets used in the srcBe mux 0

// forwardA_E = 2'b10 means resultM gets used as the aluInput1
// forwardB_E = 2'b10 means resultM gets used in the srcBe mux 0
    
    // assign stall = (regWrite_m && (rs1_e == destReg_m || rs2_e == destReg_m)); maybe we can seperate these 2 
    // assign stall = (regWrite_m && (rs1_e == destReg_m || rs2_e == destReg_m || rs1_e == destReg_w || rs2_e == destReg_w));
    

//  logic [1:0] stall_counter;   IDEA

always_comb begin

    stall = 1'b0;
    Flush = 1'b0;
    ForwardAE = 2'b00;
    ForwardBE = 2'b00;

                                    // FORWARDING
    // for forward A_E
    if (RegWriteM && (destReg_m != 0) && (destReg_m == Rs1E)) begin
        ForwardAE = 2'b10;
    end 
    else if (RegWriteW && (destReg_w != 0) && (destReg_w == Rs1E)) begin
        ForwardAE = 2'b01;
    end 
    else begin
        ForwardAE = 2'b00;
    end

    // for forward B_E
    if (RegWriteM && (destReg_m != 0) && (destReg_m == Rs2E)) begin
        ForwardBE = 2'b10;
    end
    else if (RegWriteW && (destReg_w != 0) && (destReg_w == Rs2E)) begin
        ForwardBE = 2'b01;
    end
    else begin
        ForwardBE = 2'b00;
    end

                                // STALL
    if (memoryRead_e && ((RdE == Rs1D) || (RdE == Rs2D))) begin  //   memoryRead_e
        stall = 1'b1;
    end 
    else begin
        stall = 1'b0;
    end

                                // FLUSH
    assign Flush = (zero_hazard || jump_hazard);    

end

endmodule