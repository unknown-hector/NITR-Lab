`include "SR.v"

module RAM(output out, input in, select, read, CLK); 
    wire w1,w2,w3,nin,nread;

    not (nread,read),(nin,in);

    and (w1,select,nin,nread), (w2,select,in,nread);

    SR Instance(w3,w2,w1,CLK);

    assign out = select & read & w3;

endmodule