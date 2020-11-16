module Mul2Comp(Ar,Ai,Br,Bi,Yr,Yi)
	input wire [3:0] Ar;
	input wire [3:0] Ai; 
	input wire [3:0] Br;
	input wire[3:0] Bi;
	output wire [3:0] Yr;
	output wire [3:0] Yi;
	initial begin//testing 
	Ar=4'b0100;
	Ai=4'b0100;
	Br=4'b0100;
	Bi=4'b0100;
	end
	assign Yr=(Ar*Br)-(Ai*Bi);
	assign Yi=(Ar*Bi)+(Ai*Br);
	$display("Multiplication of %d+i%d and %d+i%d is %d+i%d\n",Ar,Ai,Br,Bi,Yr,Yi);
endmodule 
