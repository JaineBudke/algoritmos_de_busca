/********************************************************************* 
 *
 * Main program, com medição de tempo de execução dos algoritmos de busca
 *
 * @author Bianca Santiago
 * @author Jaine Budke
 *
 * @date 16/04/2017
*********************************************************************/


#include <iostream>
#include <iomanip>
#include <time.h>

#include "bBinariaIterativa.h"
#include "bBinariaRecursiva.h"
#include "bSequencialIterativa.h"
#include "bSequencialRecursiva.h"

int tempoExecucao( int *V, int n, int x );

int main(){


	int n = 33;
	int V[] = {  1,  3,  5,  7,   8,  13,  15, 18, 19, 22, 24, 27, 29,
					33, 35, 43, 54,  55,  58,  59, 60, 71, 73, 78, 79, 80, 
					83, 84, 85,	99, 101, 111, 112 };
	int chavesDeBusca[] = { 1, 15, 27, 59, 77, 112 };

	/* FORMATAÇÃO SAÍDA */
	for( int i=1; i<=6; i++ ){
		std::cout << "+" << std::setw (14) << std::setfill ('-');
	}
	std::cout << std::endl;

	for ( int j = 0; j <= 5 ; ++j ) {
		tempoExecucao( V, n, chavesDeBusca[j] );	
	}
	


	return 0;

}

int tempoExecucao( int *V, int n, int x ){

	clock_t Ticks[8];

    Ticks[0] = clock();
	bBinariaIterativa( V, n, x );
	Ticks[1] = clock();
	double tempoBI = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;

	Ticks[2] = clock();
	bBinariaRecursiva( V, n, x );
	Ticks[3] = clock();
	double tempoBR = (Ticks[3] - Ticks[2]) * 1000.0 / CLOCKS_PER_SEC;

	Ticks[4] = clock();
	bSequencialIterativa( V, n, x );
	Ticks[5] = clock();
	double tempoSI = (Ticks[5] - Ticks[4]) * 1000.0 / CLOCKS_PER_SEC;

	Ticks[6] = clock();
	bSequencialRecursiva( V, n, x );
	Ticks[7] = clock();
	double tempoSR = (Ticks[7] - Ticks[6]) * 1000.0 / CLOCKS_PER_SEC;


	/* FORMATAÇÃO SAÍDA */
	std::cout << std::endl << "CHAVE DE BUSCA = " << x << std::endl;
	
	std::cout << "TEMPO DE BUSCA: ";
	std::cout << "BINÁRIA ITERATIVA = " << tempoBI << std::endl;
	std::cout << "BINÁRIA RECURSIVA = " << tempoBR << std::endl;
	std::cout << "SEQUENCIAL ITERATIVA = " << tempoSI << std::endl;
	std::cout << "SEQUENCIAL RECURSIVA = " << tempoSR << std::endl;
	std::cout << std::endl;

	for( int i=1; i<=6; i++ ){
		std::cout << "+" << std::setw (14) << std::setfill ('-');
	}
	std::cout << std::endl;


	return 0;

}


// PARA EXECUTAR
// g++ src/main.cpp src/bBinariaIterativa.cpp src/bBinariaRecursiva.cpp src/bSequencialIterativa.cpp src/bSequencialRecursiva.cpp -std=c++11 -I include -o main