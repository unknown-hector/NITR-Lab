set terminal pdf
set output "receive_rate_comparison.pdf"

set title "AODV Receive rate  ,  DSDV receive rate over time"
set xlabel "Simulation Time (seconds)"
set ylabel "Receive Rate"

plot "AODV.txt" using 1:2 with lines title "AODV Receive Rate" lw 2 ,"DSDV.txt" using 1:2 with lines title "DSDV Receive Rate" lw 2
