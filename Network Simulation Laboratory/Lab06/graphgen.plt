set terminal pdf
set output "Lab4.pdf"
set title "Plot"
set xlabel "device(node)"
set ylabel "throughtput and Goodput"
plot "processed.txt" using 1:2 with lines title " device(node) vs Throughput" lw 2, "processed.txt" using 1:3 with lines title "device(node) vs Goodput" lw 2
