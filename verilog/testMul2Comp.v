module testMul2Comp();
	reg [3:0] in1=4'b10;
	reg [3:0] in2=4'b10;
	reg [3:0] in3=4'b10;
	reg [3:0] in4=4'b10;
	reg [3:0] out1;
	reg [3:0] out2;
	Mul2Comp(.Ar(in1),.Ai(in2),.Br(in3),.Bi(in4),.Yr(out1),.Yi(out2));
	$display("Multiplication of %d+i%d and %d+i%d yields %d+i%d",in1,in2,in3,in4,out1,out2); 
endmodule
