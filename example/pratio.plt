set term postscript enhanced
set output "pratio.eps"

set size 0.6,0.6

set xlabel "Energy (eV)"
set ylabel "Participation ratio"

set xrange [-6:8]
set yrange [0:1]
unset key
plot "prat" w points pt 7 ps 0.5 lc rgb "black"
