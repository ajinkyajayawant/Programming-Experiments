module BinToBcd(BinNumber , BcdNumber);
	input wire [6:0] BinNumber;
	output 	reg [7:0] BcdNumber;
	reg [3:0] tempTens;reg [3:0] units;reg [3:0] tens;//since intput can max be 128
	parameter dec=4'b1010;

always@(*)begin
	units[3:0]=BinNumber%dec;
	tempTens[3:0]=(BinNumber-units)/dec;
	tens[3:0]=tempTens%dec;
	BcdNumber[3:0]=units;//is this valid?
	BcdNumber[7:4]=tens;
end
endmodule
