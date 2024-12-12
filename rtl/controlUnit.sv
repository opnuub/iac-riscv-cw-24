module controlUnit(
    input   logic [6:0] op,
    input   logic [2:0] funct3,
    input   logic       funct7,
    output  logic       Branch,
    output  logic       jumpSrc,
    output  logic       jalrSrc,
    output  logic [1:0] resultSrc,
    output  logic       memWrite,
    output  logic [3:0] aluControl,
    output  logic       aluSrc,
    output  logic [1:0] immSrc,
    output  logic       regWrite,
    output  logic [2:0] sizeSrc,
    // New outputs for virtual memory support
    output  logic [1:0] privilege_mode,
    output  logic       exception_handled,
    input   logic       exception_raised,
    input   logic [2:0] exception_cause
);

logic [1:0] aluOp;
    
    // Add privilege mode control
    always_comb begin
        if (exception_raised) begin
            privilege_mode = 2'b11; // Switch to Machine mode
            exception_handled = 1'b1;
        end else begin
            privilege_mode = 2'b00; // User mode
            exception_handled = 1'b0;
        end
    end

    mainDecoder mainDecoder (
        .funct3(funct3),
        .op(op),
        .Branch(Branch),
        .jumpSrc(jumpSrc),
        .jalrSrc(jalrSrc),
        .resultSrc(resultSrc),
        .memWrite(memWrite),
        .aluSrc(aluSrc),
        .immSrc(immSrc),
        .regWrite(regWrite),
        .aluOp(aluOp)
        .sizeSrc(sizeSrc),
        .privilege_mode(privilege_mode),
        .exception_raised(exception_raised)
    );

    aluDecoder aluDecoder (
        .op(op[5]),
        .aluOp(aluOp),
        .funct3(funct3),
        .funct7(funct7),
        .aluControl(aluControl)
    );
    
endmodule
