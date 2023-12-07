set terminal png
set output "Assignment5.png"
set title "Congestion control and retransmission"
set xlabel "Time"
set ylabel "Packets"
plot "seventh.cwnd" using 1:2 with lines title "Old Congestion Window" lw 2, "seventh.cwnd" using 1:3 with lines title "New Congestion Window" lw 2
