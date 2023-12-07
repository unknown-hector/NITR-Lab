set terminal pdf
set output "Atish.pdf"
set title "TCP Analysis"
set xrange [1500:9000]
set yrange [52:59]
set xlabel "Payload"
set ylabel "Average throughput"
plot "Lab6.txt" using 1:2 with lines title "TcpNewReno" lw 2,\
	 "Lab6.txt" using 1:3 with lines title "TcpHtcp" lw 2,\
	 "Lab6.txt" using 1:4 with lines title "TcpYeah" lw 2,\
	 "Lab6.txt" using 1:5 with lines title "TcpBic" lw 2,\
	 "Lab6.txt" using 1:6 with lines title "TcpScalable" lw 2
