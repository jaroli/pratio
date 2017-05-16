set term postscript enhanced color
set output "pratio.eps"

set size 0.6,0.6

set xrange [-12:2.5]
set xlabel "Energy (eV)"


set ylabel "Participation ratio"
set yrange [0:1]
set ytics nomirror

set y2label "Density of states (a.u.)" tc rgb "red"
set y2tics 

unset key

Ef=5.6653
plot "pratio.out" u ($1-Ef):2 axes x1y1 w points pt 7 ps 0.5 lc rgb "black",\
     "doscar" u ($1-Ef):2 axes x1y2 w lines lt 1 lw 2 lc rgb "red"
