module srlatch(s,r,q,q_b,clock);
	input s,r,clock;
	output q,q_b;
	wire s,r,q,q_b;
	always@(posedge clock)
		begin
		assign q<=s~&q_b;
		assign q_b=r~&q;
		end
endmodule
