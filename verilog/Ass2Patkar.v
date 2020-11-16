module testic74hc138();
	reg [2:0] NumberIn;
	reg [2:0] EnInputs;
	reg [7:0] CathOutput;
	
	initial begin
		EnInputs=3'b100;
		NumberIn=3'b101;
		$display ("%8b",CatchOutput);
	end

	/*module instantiation*/
	ic74hc138 m0(.EnableB0(EnInputs[0]),.EnableB1(EnableInputs[1]),.Enable2(EnableInputs[2]),.NumberBit0(NumberIn[0]),.NumberBit1(NumberIn[1]),.NumberBit2(NumberIn[2]),.DecodedOut(CatchOutput));
endmodule

module ic74hc138(NumberBit0,NumberBit1,NumberBit2,DecodedOut,EnableB0,EnableB1,Enable2);
	
	input EnableB0,EnableB1,Enable2,NumberBit0,NumberBit1,NumberBit2;
	
	output [7:0] DecodedOut;
	wire [7:0] DecodedOut;
	wire [2:0] inputConcatenated;

	assign inputConcatenated={NumberBit2,NumberBit1,NumberBit0};
	assign DecodedOut=(EnableB0|EnableB1|(~Enable2)) ? 8'b11111111 : 8'b00000001<<inputConcatenated ;

endmodule
