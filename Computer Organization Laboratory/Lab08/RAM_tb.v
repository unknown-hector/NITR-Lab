`include "RAM.v" 

module RAM_tb;

reg IN,SEL, READ, CLK;

wire OUT;

RAM Instance (OUT, IN, SEL, READ, CLK);

initial begin

SEL = 1'b1; IN = 1'b1; READ = 1'b0;

$monitor("T=%0t Select = %b, CLK = %b Input = %b, Read = %b | Output = %b",$time,SEL,CLK, IN, READ, OUT);

$dumpfile("RAM.vcd");
$dumpvars();

end

initial begin

CLK = 0;

#5 CLK = 1;

#5 CLK = 0;

#5 CLK = 1; READ = 1;

#5 CLK = 0;

#5 CLK = 1;

#5 CLK = 0;

#5 CLK = 1; SEL = 0;

#5 CLK = 0;

#5 CLK = 1; SEL = 1; IN = 0;

#5 CLK = 0;

#5;

end

endmodule