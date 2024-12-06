module PC_top #(
    parameter DATA_WIDTH = 32
) (
    input   logic                  clk,
    input   logic                  rst,
    input   logic                  PCsrcE,
    input   logic [DATA_WIDTH-1:0] PCTargetE,
    output  logic [DATA_WIDTH-1:0] InstrD,
    output  logic [DATA_WIDTH-1:0] PCd,
    output  logic [DATA_WIDTH-1:0] PCPlus4D

);

    logic [DATA_WIDTH-1:0] PCFp;
    logic [DATA_WIDTH-1:0] PCf;
    logic [DATA_WIDTH-1:0] PCPlus4F;
    logic [DATA_WIDTH-1:0] Rd;

    PCReg PCReg (
        .clk (clk),      
        .rst (rst),    
        .PCFp (PCFp),       
        .PCf (PCf)     	
    );

    mux mux (
        .PCTargetE (PCTargetE),          
        .PCsrcE (PCsrcE),
        .PCPlus4F (PCPlus4F),       
        .PCFp (PCFp)     	
    );

    imem imem (
        .PCf (PCf),          
        .Rd (Rd)  	
    );

    adder adder (
        .PCf (PCf),          
        .PCPlus4F (PCPlus4F)  	
    );

    PRegFetch PRegFetch (
        .clk (clk),
        .Rd (Rd),     
        .PCf (PCf),      
        .PCPlus4F (PCPlus4F),       
        .InstrD (InstrD),
        .PCd (PCd),  
        .PCPlus4D (PCPlus4D)	
    );

endmodule
