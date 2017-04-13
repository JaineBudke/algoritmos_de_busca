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
*@brief Função principal que contém o tempo de execução dos algoritmos de busca.
*/
int main(){

	std::srand(std::time(0)); // semente do rand

	int nBases = 5; // Quantidade de bases de busca
	int tamN[] = { 50, 100, 1000, 10000, 100000 }; // Tamanhos das bases de busca


	for ( int i = 0 ; i < nBases ; ++i ) { // Fazendo várias buscas, com bases aleatórias de diferentes tamanhos
		
		int tamBase = tamN[i]; // Tamanho da base de busca
		int base[ tamBase ];   // Vetor com os valores da base

		generateRandomBase( base, tamBase ); // Gera base de busca aleatória e ordenada


		int qntKeys = 3;
		/* CHAVES DE BUSCA:
		 * Melhor caso sequencial -> primeiro elemento = base[0].
		 * Pior caso sequencial   -> elemento não existe = base[ tamBase-1 ]+1.
		 * Melhor caso binária    -> elemento do meio = base[ tamBase/2 ].
		 * Pior caso binária      -> elemento não existe = base[ tamBase-1 ]+1.
		 */
		int chavesDeBusca[] = { base[0], base[ tamBase-1 ]+1, base[ tamBase/2 ] };


		/* FORMATAÇÃO SAÍDA */
		for( int i=1; i<=6; i++ ){
			cout << "+" << std::setw (14) << std::setfill ('-');
		}
		cout << std::endl;
		

		cout << endl << "TAMANHO BASE DE BUSCA = " << tamBase << endl;
		/* MEDIÇÃO DO TEMPO DE CADA IMPLEMENTAÇÃO DE BUSCA E COM CHAVES DE BUSCA DIFERENTES */
		for ( int j = 0; j < qntKeys ; ++j ) {
			tempoExecucao( base, tamBase, chavesDeBusca[j] );	
		}

	}

	
	
	return 0;

}

/**
 * @brief Realiza a medição do tempo da execução de cada algoritmo de busca.
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


/**
 * @brief Realiza a comparação entre dois valores.
 * @param a Primeiro valor para comparação.
 * @param b Segundo valor para comparação.
 * @return Se a é menor, maior ou igual a b.
 */
int compare( const void * a, const void * b ) {
 
    const int *intA = static_cast <const int*> ( a );
    const int *intB = static_cast <const int*> ( b );
 
    if ( *intA == *intB ) {
        return 0;
    } else if ( *intA < *intB ) {
        return -1;
    } else if ( *intA > *intB ) {
        return 1;
    } 
 
}


/**
 * @brief Gera a base de busca aleatória.
 * @details Função implementada fazendo uso das bibliotecas ctime e cstdlib.
 * @param base Vetor com a base de busca.
 * @param tamBase Tamanho da base de busca.
 */
void generateRandomBase( int *base, int tamBase ){

	for ( int i = 0; i < tamBase; ++i ) { // gerando base de busca
		int num_aleatorio = std::rand() % 200000; // número aleatório entre 0 e 2000
	   	base[i] = num_aleatorio; // Add valor à base
	}

	// Ordena base de busca
	qsort( base, tamBase, sizeof( int ), compare );
	

}