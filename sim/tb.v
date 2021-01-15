module tb();
    reg clk, reset;

    // Control data
    reg[3:0] s;
    reg ci, M;

    // Operands
    reg[3:0] a, b, yexpected;
    wire [3:0] y;

    reg[31:0] vectornum, errors;
    reg[18:0] testvectors[0:15000];

    // instantiate device under test
    alu74181 dut(s, ci, M, a, b, y);

    // generate clock
    always
    begin
        clk = 1;
        #5;
        clk = 0;
        #5;
    end

    // at start of test, load vectors
    // and pulse reset
    initial
        begin
        $readmemb("74181.tv", testvectors);
        vectornum = 0;
        errors = 0;
        reset = 1;
        #27;
        reset = 0;
        end

    // apply test vectors on rising edge of clk
    always @ (posedge clk)
        begin
        #1; {s, M, ci, a, b, yexpected} = testvectors[vectornum];
        end

    // check results on falling edge of clk
    always @ (negedge clk)
        if(~reset) begin // skip during reset
            if(y !== yexpected) begin
                $display("Error: inputs = %b, %b", a, b);
                $display("Error: flags = %b, %b", M, ci);
                $display("Error: selection = %b", s);
                $display(" outputs = %b (%b expected)", y, yexpected);
                errors = errors + 1;
            end
            vectornum = vectornum + 1;
            if(testvectors[vectornum] === 4'bx) begin
                $display("%d tests completed with %d errors", vectornum, errors);
                $finish;
            end
        end
endmodule
