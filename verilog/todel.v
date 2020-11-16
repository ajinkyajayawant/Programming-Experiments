/*to see how binary numbers are represented in verilog*/

module todel(A);
input [4:0] A ;
wire signed [4:0] A = 5'b00110;//the binary number given by us is mod of the number we want
wire signed [4:0] B = -5'd2;
initial begin
$display("%b %d",A*B,A*B);
end
endmodule
