#Instruções para plotar sen(x)
reset
set grid
set title "Busca Sequencial Iterativa"
set key above
set ylabel "Tempo de Execucao"
set xlabel "Tamanho Base de Busca"
set size 1,1
set term post eps enhanced color
set out 'grafSI.eps'
plot 'dadosSI1.txt' title '1o valor base de dados' with lines, 'dadosSI2.txt' title 'valor inexistente' with lines, 'dadosSI3.txt' title 'elemento do meio' with lines
#Fim