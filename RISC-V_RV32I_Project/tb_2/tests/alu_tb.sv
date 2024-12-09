module alu_tb;

    parameter DATA_WIDTH = 32;

    // Testbench signals
    logic [DATA_WIDTH-1:0] srcA;
    logic [DATA_WIDTH-1:0] srcB;
    logic [2:0] aluControl;
    logic [DATA_WIDTH-1:0] aluResult;

    // Instantiate the ALU
    alu #(.DATA_WIDTH(DATA_WIDTH)) uut (
        .srcA(srcA),
        .srcB(srcB),
        .aluControl(aluControl),
        .aluResult(aluResult)
    );

    // Test sequence
    initial begin
        // Test ADD operation
        srcA = 32'd15;
        srcB = 32'd10;
        aluControl = 3'b000;
        #10;
        $display("ADD: srcA=%0d, srcB=%0d, aluResult=%0d", srcA, srcB, aluResult);
        assert(aluResult == srcA + srcB) else $error("ADD failed");

        // Test SUB operation
        srcA = 32'd20;
        srcB = 32'd5;
        aluControl = 3'b001;
        #10;
        $display("SUB: srcA=%0d, srcB=%0d, aluResult=%0d", srcA, srcB, aluResult);
        assert(aluResult == srcA - srcB) else $error("SUB failed");

        // Test AND operation
        srcA = 32'hA5A5A5A5;
        srcB = 32'h5A5A5A5A;
        aluControl = 3'b010;
        #10;
        $display("AND: srcA=%h, srcB=%h, aluResult=%h", srcA, srcB, aluResult);
        assert(aluResult == (srcA & srcB)) else $error("AND failed");

        // Test OR operation
        srcA = 32'hA5A5A5A5;
        srcB = 32'h5A5A5A5A;
        aluControl = 3'b011;
        #10;
        $display("OR: srcA=%h, srcB=%h, aluResult=%h", srcA, srcB, aluResult);
        assert(aluResult == (srcA | srcB)) else $error("OR failed");

        // Test LUI operation
        srcA = 32'h12345678;
        srcB = 32'h87654321;
        aluControl = 3'b100;
        #10;
        $display("LUI: srcA=%h, srcB=%h, aluResult=%h", srcA, srcB, aluResult);
        assert(aluResult == srcB) else $error("LUI failed");

        // Test SLT operation
        srcA = -32'sd5;
        srcB = 32'sd10;
        aluControl = 3'b101;
        #10;
        $display("SLT: srcA=%0d, srcB=%0d, aluResult=%0d", srcA, srcB, aluResult);
        assert(aluResult == 32'b1) else $error("SLT failed");

        // Test SLL operation
        srcA = 32'd1;
        srcB = 32'd4;
        aluControl = 3'b110;
        #10;
        $display("SLL: srcA=%0d, srcB=%0d, aluResult=%0d", srcA, srcB, aluResult);
        assert(aluResult == (srcA << srcB[4:0])) else $error("SLL failed");

        // Test SRL operation
        srcA = 32'd16;
        srcB = 32'd2;
        aluControl = 3'b111;
        #10;
        $display("SRL: srcA=%0d, srcB=%0d, aluResult=%0d", srcA, srcB, aluResult);
        assert(aluResult == (srcA >> srcB[4:0])) else $error("SRL failed");

        $display("All tests passed!");
        $finish;
    end

endmodule
