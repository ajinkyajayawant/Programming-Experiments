module ic74hc138(NumberBit0,NumberBit1,NumberBit2,DecodedOut,EnableB0,EnableB1,Enable2);
	
	input EnableB0,EnableB1,Enable2,NumberBit0,NumberBit1,NumberBit2;
	
	output [7:0] DecodedOut;
	wire [7:0] DecodedOut;
	wire [2:0] inputConcatenated;
	wire [7:0] shiftedOutput;
	
	assign shiftedOutput=(8'b11111110 << inputConcatenated);
	assign inputConcatenated={NumberBit2,NumberBit1,NumberBit0};

	assign DecodedOut=((EnableB0==0)||(EnableB1==0)||(Enable2==1)) ? 8'b11111111 :shiftedOutput ;

	/*assign DecodedOut[0]=(EnableB0|EnableB1|(~Enable2)) ? 1'b1 :shiftedOutput[0] ;
	assign DecodedOut[1]=(EnableB0|EnableB1|(~Enable2)) ? 1'b1 :shiftedOutput[1] ;
	assign DecodedOut[2]=(EnableB0|EnableB1|(~Enable2)) ? 1'b1 :shiftedOutput[2] ;
	assign DecodedOut[3]=(EnableB0|EnableB1|(~Enable2)) ? 1'b1 :shiftedOutput[3] ;
	assign DecodedOut[4]=(EnableB0|EnableB1|(~Enable2)) ? 1'b1 :shiftedOutput[4] ;
	assign DecodedOut[5]=(EnableB0|EnableB1|(~Enable2)) ? 1'b1 :shiftedOutput[5] ;
	assign DecodedOut[6]=(EnableB0|EnableB1|(~Enable2)) ? 1'b1 :shiftedOutput[6] ;
	assign DecodedOut[7]=(EnableB0|EnableB1|(~Enable2)) ? 1'b1 :shiftedOutput[7] ;*/


endmodule
