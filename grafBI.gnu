#Instruções para plotar sen(x)
reset
set grid
set title "Busca Binaria Iterativa"
set key above
set ylabel "Tempo de Execucao"
set xlabel "Tamanho Base de Busca"
set size 1,1
set term post eps enhanced color
set out 'grafBI.eps'
plot 'dadosBI1.txt' title '1o valor base de dados' with lines, 'dadosBI2.txt' title 'valor inexistente' with lines, 'dadosBI3.txt' title 'elemento do meio' with lines
#Fim