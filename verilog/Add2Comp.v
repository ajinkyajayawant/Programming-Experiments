module Add2Comp(Ar,Ai,Br,Bi,Yr,Yi);
	input [3:0] Ar;
	input [3:0] Ai; 
	input [3:0] Br;
	input [3:0] Bi;
	output [3:0] Yr;
	output [3:0] Yi;
	
	wire [3:0] Yr;
	wire [3:0] Yi;

	assign Yr=Ar+Br;
	assign Yi=Ai+Bi;
endmodule:
