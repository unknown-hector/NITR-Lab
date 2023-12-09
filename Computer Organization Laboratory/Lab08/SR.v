module SR(output reg Q, input S,R,CLK);

always @(negedge CLK) begin

if(S==0 && R==0) 
    Q <= Q; 
else if(S==0 && R==1)
    Q <= 1'b0; 
else if(S==1 && R==0)
    Q <= 1'b1;
else
    Q <= 1'bx;

end

endmodule