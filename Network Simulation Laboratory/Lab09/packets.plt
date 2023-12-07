set terminal pdf
set output "PacketsReceivedComparison.pdf"

set title "AODV Packets Received  ,  DSDV rPackets Received  over time"
set xlabel "Simulation Time (seconds)"
set ylabel "Packets Received "

plot "AODV.txt" using 1:3 with lines title "AODV Packets Received " lw 2 ,"DSDV.txt" using 1:3 with lines title "DSDV Packets Received " lw 2
