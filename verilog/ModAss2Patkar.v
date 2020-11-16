`timescale 1ns/1ns

/*testing for 74hc138 ic*/

/*
module test74hc138();
	reg [2:0] NumberIn;
	reg [2:0] EnInputs;
	wire [7:0] CatchOutput;//ouput received from the ic
	
	initial begin
		EnInputs=3'b100;//enable inputs
		NumberIn=3'b101;//number to be decoded
	end

	//module instantiation
	ic74hc138 m0(.EnableB0(EnInputs[0]),.EnableB1(EnInputs[1]),.Enable2(EnInputs[2]),.NumberBit0(NumberIn[0]),.NumberBit1(NumberIn[1]),.NumberBit2(NumberIn[2]),.DecodedOut(CatchOutput));

	always@(*)begin
		$display ("%8b",CatchOutput);//active low output
	end

endmodule
*/

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


module TestBench();	
	reg clock;

	//Registers for led matrix
	wire [7:0] Column0;
	wire [7:0] Column1;
	wire [7:0] Column2;
	wire [7:0] Column3;
	wire [7:0] Column4;
	wire [7:0] Column5;
	wire [7:0] Column6;
	wire [7:0] Column7;

	//for storing the extended bits of 1st IC
	wire [7:0] Extend0;
	wire [7:0] Extend1;
	wire [7:0] Extend2;
	wire [7:0] Extend3;
	wire [7:0] Extend4;
	wire [7:0] Extend5;
	wire [7:0] Extend6;
	wire [7:0] Extend7;

	//outputs for 1st ic
	wire [7:0] TestOutputs0;

	//outputs for 2nd ic
	wire [7:0] TestOutputs1;

	//outputs for counter 0
	wire [2:0] TestCounterOut0;

	//outputs for counter 1
	wire [2:0] TestCounterOut1;

	//enable for 1st ic
	reg EnableIc0B0;
	reg EnableIc0B1;
	reg EnableIc02;

	//enable for 2nd ic
	reg EnableIc1B0;
	reg EnableIc1B1;
	reg EnableIc12;

	initial begin
		//intialising 1st IC
		EnableIc0B0=0;
		EnableIc0B1=0;
		EnableIc02=1;

		//initialising 2nd IC
		EnableIc1B0=0;
		EnableIc1B1=0;
		EnableIc12=1;//this has to be 0 to get proper output
		/*
		//initialising counter
		TestCounterOut0=3'b000;
		TestCounterOut1=3'b000;

		//initialising outputs
		TestOutputs0=8'b11111111;
		TestOutputs1=8'b11111111;
		*/
		//initialising clock
		clock=1'b0;

		//dumping variables for gtk wave
		$dumpfile("./gtkfile.vcd");
		$dumpvars(0);//only dumping variables in this module
		#1000 $finish;
	end

	//instantiating the bit extender for the eight bits required for led array
	BitExtend b0(.OneBit(TestOutputs0[0]),.EightBits(Extend0));
	BitExtend b1(.OneBit(TestOutputs0[1]),.EightBits(Extend1));
	BitExtend b2(.OneBit(TestOutputs0[2]),.EightBits(Extend2));
	BitExtend b3(.OneBit(TestOutputs0[3]),.EightBits(Extend3));
	BitExtend b4(.OneBit(TestOutputs0[4]),.EightBits(Extend4));
	BitExtend b5(.OneBit(TestOutputs0[5]),.EightBits(Extend5));
	BitExtend b6(.OneBit(TestOutputs0[6]),.EightBits(Extend6));
	BitExtend b7(.OneBit(TestOutputs0[7]),.EightBits(Extend7));

	//instantiating 1st counter
	mod8counter c0(.clk(clock),.count(TestCounterOut0));
	//instatiating 2nd counter
	mod8counter c1(.clk(TestCounterOut0[2]),.count(TestCounterOut1));

	//instantiating 1st IC
	ic74hc138 m0(.NumberBit0(TestCounterOut0[0]),.NumberBit1(TestCounterOut0[1]),.NumberBit2(TestCounterOut0[2]),.DecodedOut(TestOutputs0),.EnableB0(EnableIc0B0),.EnableB1(EnableIc0B1),.Enable2(EnableIc02));
	//instatiating 2nd IC
	ic74hc138 m1(.NumberBit0(TestCounterOut1[0]),.NumberBit1(TestCounterOut1[1]),.NumberBit2(TestCounterOut1[2]),.DecodedOut(TestOutputs1),.EnableB0(EnableIc1B0),.EnableB1(EnableIc1B1),.Enable2(EnableIc12));

	//assigning the led values
	assign Column0=(TestOutputs1)&(~Extend0);//logi similar to diode logic
	assign Column1=(TestOutputs1)&(~Extend1);
	assign Column2=(TestOutputs1)&(~Extend2);
	assign Column3=(TestOutputs1)&(~Extend3);	
	assign Column4=(TestOutputs1)&(~Extend4);
	assign Column5=(TestOutputs1)&(~Extend5);	
	assign Column6=(TestOutputs1)&(~Extend6);
	assign Column7=(TestOutputs1)&(~Extend7);

	//generating clock wave	
	always
	 #10 clock=!clock;

endmodule

/*
error:
was getting the error :./ModAss2Patkar.v:13: warning: Port 4 (DecodedOut) of ic74hc138 expects 8 bits, got 1.
./ModAss2Patkar.v:13:        : Padding 7 high bits of the port.
Solution:seems name of a variable(CatchOutput) declared was wrong as (CathOutput)
*/
