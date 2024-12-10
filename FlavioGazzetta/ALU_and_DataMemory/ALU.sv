module ALU #(
    parameter DATA_WIDTH = 32
) (
    input   logic [DATA_WIDTH-1:0]  SrcA,
    input   logic [DATA_WIDTH-1:0]  SrcB,
    input   logic [2:0]             ALUControl,
    output  logic [DATA_WIDTH-1:0]  ALUResult,
    output  logic                   zero,
    output  logic                   signedsmaller,
    output  logic                   unsignedsmaller
);

    logic [DATA_WIDTH-1:0] add, sub, Opand, Opor, Opxor, slt, sltu, shift_left, shift_right, shift_arith;

    always_comb begin
        zero = 0;
        signedsmaller = 0;
        unsignedsmaller = 0;

        add = SrcA + SrcB;
        sub = SrcA - SrcB;
        Opand = SrcA & SrcB;
        Opor = SrcA | SrcB;
        //Opxor = SrcA ^ SrcB; kick if need more space
        slt = (SrcA < SrcB) ? {{(DATA_WIDTH-1){1'b0}}, 1'b1} : {DATA_WIDTH{1'b0}};
        sltu = ($unsigned(SrcA) < $unsigned(SrcB)) ? {{(DATA_WIDTH-1){1'b0}}, 1'b1} : {DATA_WIDTH{1'b0}};//remove
        shift_left = SrcA << SrcB[4:0];
        shift_right = SrcA >> SrcB[4:0];
        //shift_arith = $signed(SrcA) >>> SrcB[4:0];

        signedsmaller = ($signed(SrcA) < $signed(SrcB));
        unsignedsmaller = ($unsigned(SrcA) < $unsigned(SrcB));

        case (ALUControl)
            3'b000: ALUResult = add;
            3'b001: ALUResult = sub;
            3'b010: ALUResult = Opand;
            3'b011: ALUResult = Opor;
            3'b100: ALUResult = Opxor;
            3'b101: ALUResult = slt;
            //3'b0111: ALUResult = sltu;//remove
            3'b110: ALUResult = shift_left;
            3'b111: ALUResult = shift_right;
            //3'b1100: ALUResult = shift_arith;//remove
            //3'b1101: ALUResult = SrcB;
            default: ALUResult = {DATA_WIDTH{1'b0}};
        endcase

        zero = (ALUResult == {DATA_WIDTH{1'b0}});
    end

endmodule
