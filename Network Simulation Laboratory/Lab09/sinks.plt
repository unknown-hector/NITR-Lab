set terminal pdf
set output "NumberOfSinks.pdf"

set title "AODV sinks ,  DSDV sinks  over time"
set xlabel "Simulation Time (seconds)"
set ylabel "Number of sinks "

plot "AODV.txt" using 1:4 with lines title "AODV  sinks " lw 2 ,"DSDV.txt" using 1:4 with lines title "DSDV sinks  " lw 2
