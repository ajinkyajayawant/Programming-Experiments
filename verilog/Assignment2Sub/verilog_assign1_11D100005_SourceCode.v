/*code for the decoder ic*/
module ic74hc138(NumberBit0,NumberBit1,NumberBit2,DecodedOut,EnableB0,EnableB1,Enable2);
	
	input EnableB0,EnableB1,Enable2,NumberBit0,NumberBit1,NumberBit2;
	
	output [7:0] DecodedOut;//decoded Output from the ic
	wire [7:0] DecodedOut;
	wire [2:0] inputConcatenated;//input as a single variable
	wire [7:0] shiftedOutput;
	
	/*shifting the number 00000001 by number of bits equal to the input number*/
	assign shiftedOutput=(8'b00000001 << inputConcatenated);
	/*combining 3 bits of input into single number*/
	assign inputConcatenated={NumberBit2,NumberBit1,NumberBit0};
	/*generating the output according to value of 3 enable bits*/
	assign DecodedOut=((EnableB0==1)||(EnableB1==1)||(Enable2==0)) ? 8'b00000000 :~shiftedOutput ;

endmodule

module mod8counter(clk,count);
	input clk;
	output [2:0] count;
	reg [2:0] count;
	
	initial begin
		count=3'b000;
	end

	always@(posedge clk)begin
		count<=count+3'b1;
	end
endmodule

module BitExtend(OneBit,EightBits);
	input OneBit;
	wire OneBit;
	output [7:0] EightBits;
	wire [7:0] EightBits;

	assign EightBits={OneBit,OneBit,OneBit,OneBit,OneBit,OneBit,OneBit,OneBit};

endmodule
