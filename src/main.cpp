/**
 * @file	main.cpp
 * @brief	Código fonte do prgrama com medição de tempo de execução dos algoritmos de busca
 * @author	Bianca Santiago (bianca.santiago72@gmail.com)
 * @author	Jaine Budke (jainebudke@hotmail.com)
 * @since	25/03/2017
 * @date	16/04/2017
 */

#include "buscas.h"

/**
*@brief Função principal ue contém o tempo de execução dos algoritmos ded busca.
*/
int main(){


	int n = 33;
	int V[] = {  1,  3,  5,  7,   8,  13,  15, 18, 19, 22, 24, 27, 29,
					33, 35, 43, 54,  55,  58,  59, 60, 71, 73, 78, 79, 80, 
					83, 84, 85,	99, 101, 111, 112 };

	int chavesDeBusca[] = { 1, 15, 27, 59, 77, 112 };

	/* FORMATAÇÃO SAÍDA */
	for( int i=1; i<=6; i++ ){
		cout << "+" << std::setw (14) << std::setfill ('-');
	}
	cout << std::endl;

	for ( int j = 0; j <= 5 ; ++j ) {
		tempoExecucao( V, n, chavesDeBusca[j] );	
	}
	
	return 0;

}

/**
 * @brief Realiza a medição do tempo da execuçaõ de cada algoritmo de busca.
 * @details Função implementada fazendo uso das bibliotecas iomanip e time.h.
 * @param V Vetor com a base de busca.
 * @param n Tamanho do vetor.
 * @param x Chave de busca.
 * @return O tempo de execução dos algoritmos de busca.
 */
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
	cout << endl << "CHAVE DE BUSCA = " << x << endl;
	
	cout << "TEMPO DE BUSCA: ";
	cout << "BINÁRIA ITERATIVA = " << tempoBI << endl;
	cout << "BINÁRIA RECURSIVA = " << tempoBR << endl;
	cout << "SEQUENCIAL ITERATIVA = " << tempoSI << endl;
	cout << "SEQUENCIAL RECURSIVA = " << tempoSR << endl;
	cout << endl;

	for( int i=1; i<=6; i++ ){
		cout << "+" << std::setw (14) << std::setfill ('-');
	}
	cout << endl;


	return 0;

}