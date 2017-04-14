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

	
	// GRAVANDO DADOS EM ARQUIVO
	std::ofstream arqsaida;
	arqsaida.open( "dados.txt", std::ios::out );
	if( !arqsaida.is_open() ){
		return 0;
	}

	std::cout << "Gerando dados..." << std::endl;

	// Grava o cabeçalho
	arqsaida << "#Dados para o script geraGrafico.gnu" << std::endl;
	/*
	 * X - Tamanho da base de busca
	 * Y - Tempo de execução
	 * Z - Tipo da busca = { 1 - binária iterativa
	 						 2 - binária recursiva
	 						 3 - sequencial iterativa
	 						 4 - sequencial recursiva }
	 * W - Chave de busca						 
	*/
	arqsaida << "#X" << std::setw(10) << "#Y" << std::setw(10) << "#Z" << std::setw(10) << "#W" << std::endl;


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


		/* MEDIÇÃO DO TEMPO DE CADA IMPLEMENTAÇÃO DE BUSCA E COM CHAVES DE BUSCA DIFERENTES */
		for ( int j = 0; j < qntKeys ; ++j ) {
			tempoExecucao( arqsaida, base, tamBase, chavesDeBusca[j] );	
		}

	}

	// FECHANDO ARQUIVO COM DADOS
	std::cout << "Fechando o arquivo..." << std::endl;
	arqsaida.close();
	
	return 0;

}

/**
 * @brief Realiza a medição do tempo da execução de cada algoritmo de busca.
 * @details Função implementada fazendo uso das bibliotecas iomanip e time.h.
 * @param arqsaida Arquivo de saída dos dados.
 * @param V Vetor com a base de busca.
 * @param n Tamanho da base de busca.
 * @param x Chave de busca.
 * @return O tempo de execução dos algoritmos de busca.
 */
int tempoExecucao( std::ofstream & arqsaida, int *V, int n, int x ){


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
	


	// Gravando os registros numéricos
	arqsaida << n << std::setw(10) << tempoBI << std::setw(10) << 1 << std::setw(10) << x << std::endl;
	arqsaida << n << std::setw(10) << tempoBR << std::setw(10) << 2 << std::setw(10) << x << std::endl;
	arqsaida << n << std::setw(10) << tempoSI << std::setw(10) << 3 << std::setw(10) << x << std::endl;
	arqsaida << n << std::setw(10) << tempoSR << std::setw(10) << 4 << std::setw(10) << x << std::endl;

	// Tratamento de erro de leitura de arquivo
	if( arqsaida.fail() ) {
		std::cout << "Erro fatal!" << std::endl;
		exit(1); // Aborta programa
	}


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