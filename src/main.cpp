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
	int tamN[] = { 100, 1000, 10000, 50000, 100000 }; // Tamanhos das bases de busca

	///////////////////////////////////////////////////////////////////////////
	// GRAVANDO DADOS EM ARQUIVOS dadosBI1.txt, dadosBI2.txt, dadosBI3.txt
	///////////////////////////////////////////////////////////////////////////
	// Gravando em dadosBI1.txt
	std::ofstream arqsaidaBI1;
	arqsaidaBI1.open( "dadosBI1.txt", std::ios::out );
	if( !arqsaidaBI1.is_open() ){
		return 0;
	}

	std::cout << "Gerando dados BI..." << std::endl;
	
	// Grava o cabeçalho
	arqsaidaBI1 << "#Dados para o script geraGrafico.gnu da Busca Binária Iterativa" << std::endl;
	/*
	 * X - Tamanho da base de busca
	 * Y - Tempo de execução
	 * W - Chave de busca						 
	*/
	arqsaidaBI1 << "#X" << std::setw(10) << "#Y" << std::endl;

	// Gravando em dadosBI2.txt
	std::ofstream arqsaidaBI2;
	arqsaidaBI2.open( "dadosBI2.txt", std::ios::out );
	if( !arqsaidaBI2.is_open() ){
		return 0;
	}

	std::cout << "Gerando dados BI..." << std::endl;

	// Grava o cabeçalho
	arqsaidaBI2 << "#Dados para o script geraGrafico.gnu da Busca Binária Iterativa" << std::endl;
	/*
	 * X - Tamanho da base de busca
	 * Y - Tempo de execução
	 * W - Chave de busca						 
	*/
	arqsaidaBI2 << "#X" << std::setw(10) << "#Y" << std::endl;

	// Gravando em dadosBI3.txt
	std::ofstream arqsaidaBI3;
	arqsaidaBI3.open( "dadosBI3.txt", std::ios::out );
	if( !arqsaidaBI3.is_open() ){
		return 0;
	}

	std::cout << "Gerando dados BI..." << std::endl;

	// Grava o cabeçalho
	arqsaidaBI3 << "#Dados para o script geraGrafico.gnu da Busca Binária Iterativa" << std::endl;
	/*
	 * X - Tamanho da base de busca
	 * Y - Tempo de execução
	 * W - Chave de busca						 
	*/
	arqsaidaBI3 << "#X" << std::setw(10) << "#Y" << std::endl;


	///////////////////////////////////////////////////////////////////////////
	// GRAVANDO DADOS EM ARQUIVOS dadosBR1.txt, dadosBR2.txt, dadosBR3.txt
	///////////////////////////////////////////////////////////////////////////
	// Gravando dadosBR1.txt
	std::ofstream arqsaidaBR1;
	arqsaidaBR1.open( "dadosBR1.txt", std::ios::out );
	if( !arqsaidaBR1.is_open() ){
		return 0;
	}

	std::cout << "Gerando dados BR..." << std::endl;

	// Grava o cabeçalho
	arqsaidaBR1 << "#Dados para o script geraGrafico.gnu da Busca Binária Recursiva" << std::endl;
	/*
	 * X - Tamanho da base de busca
	 * Y - Tempo de execução
	 * W - Chave de busca						 
	*/
	arqsaidaBR1 << "#X" << std::setw(10) << "#Y" << std::endl;

	// Gravando dadosBR2.txt
	std::ofstream arqsaidaBR2;
	arqsaidaBR2.open( "dadosBR2.txt", std::ios::out );
	if( !arqsaidaBR2.is_open() ){
		return 0;
	}

	std::cout << "Gerando dados BR..." << std::endl;

	// Grava o cabeçalho
	arqsaidaBR2 << "#Dados para o script geraGrafico.gnu da Busca Binária Recursiva" << std::endl;
	/*
	 * X - Tamanho da base de busca
	 * Y - Tempo de execução
	 * W - Chave de busca						 
	*/
	arqsaidaBR2 << "#X" << std::setw(10) << "#Y" << std::endl;

	// Gravando dadosBR3.txt
	std::ofstream arqsaidaBR3;
	arqsaidaBR3.open( "dadosBR3.txt", std::ios::out );
	if( !arqsaidaBR3.is_open() ){
		return 0;
	}

	std::cout << "Gerando dados BR..." << std::endl;

	// Grava o cabeçalho
	arqsaidaBR3 << "#Dados para o script geraGrafico.gnu da Busca Binária Recursiva" << std::endl;
	/*
	 * X - Tamanho da base de busca
	 * Y - Tempo de execução
	 * W - Chave de busca						 
	*/
	arqsaidaBR3 << "#X" << std::setw(10) << "#Y" << std::endl;


	///////////////////////////////////////////////////////////////////////////
	// GRAVANDO DADOS EM ARQUIVOS dadosSI1.txt, dadosSI2.txt, dadosSI3.txt
	///////////////////////////////////////////////////////////////////////////
	// Gravando dadosSI1.txt
	std::ofstream arqsaidaSI1;
	arqsaidaSI1.open( "dadosSI1.txt", std::ios::out );
	if( !arqsaidaSI1.is_open() ){
		return 0;
	}

	std::cout << "Gerando dados SI..." << std::endl;

	// Grava o cabeçalho
	arqsaidaSI1 << "#Dados para o script geraGrafico.gnu  da Busca Sequencial Iterativa" << std::endl;
	/*
	 * X - Tamanho da base de busca
	 * Y - Tempo de execução
	 * W - Chave de busca						 
	*/
	arqsaidaSI1 << "#X" << std::setw(10) << "#Y" << std::endl;

	// Gravando dadosSI2.txt
	std::ofstream arqsaidaSI2;
	arqsaidaSI2.open( "dadosSI2.txt", std::ios::out );
	if( !arqsaidaSI2.is_open() ){
		return 0;
	}

	std::cout << "Gerando dados SI..." << std::endl;

	// Grava o cabeçalho
	arqsaidaSI2 << "#Dados para o script geraGrafico.gnu  da Busca Sequencial Iterativa" << std::endl;
	/*
	 * X - Tamanho da base de busca
	 * Y - Tempo de execução
	 * W - Chave de busca						 
	*/
	arqsaidaSI2 << "#X" << std::setw(10) << "#Y" << std::endl;

	// Gravando dadosSI3.txt
	std::ofstream arqsaidaSI3;
	arqsaidaSI3.open( "dadosSI3.txt", std::ios::out );
	if( !arqsaidaSI3.is_open() ){
		return 0;
	}

	std::cout << "Gerando dados SI..." << std::endl;

	// Grava o cabeçalho
	arqsaidaSI3 << "#Dados para o script geraGrafico.gnu  da Busca Sequencial Iterativa" << std::endl;
	/*
	 * X - Tamanho da base de busca
	 * Y - Tempo de execução
	 * W - Chave de busca						 
	*/
	arqsaidaSI3 << "#X" << std::setw(10) << "#Y" << std::endl;



	///////////////////////////////////////////////////////////////////////////
	// GRAVANDO DADOS EM ARQUIVOS dadosSR1.txt, dadosSR2.txt, dadosSR3.txt
	///////////////////////////////////////////////////////////////////////////
	// Gravando dadosSR1.txt
	std::ofstream arqsaidaSR1;
	arqsaidaSR1.open( "dadosSR1.txt", std::ios::out );
	if( !arqsaidaSR1.is_open() ){
		return 0;
	}

	std::cout << "Gerando dados SR..." << std::endl;

	// Grava o cabeçalho
	arqsaidaSR1 << "#Dados para o script geraGrafico.gnu da Busca Sequencial Recursiva" << std::endl;
	/*
	 * X - Tamanho da base de busca
	 * Y - Tempo de execução
	 * W - Chave de busca						 
	*/
	arqsaidaSR1 << "#X" << std::setw(10) << "#Y" << std::endl;

	// Gravando dadosSR2.txt
	std::ofstream arqsaidaSR2;
	arqsaidaSR2.open( "dadosSR2.txt", std::ios::out );
	if( !arqsaidaSR2.is_open() ){
		return 0;
	}

	std::cout << "Gerando dados SR..." << std::endl;

	// Grava o cabeçalho
	arqsaidaSR2 << "#Dados para o script geraGrafico.gnu da Busca Sequencial Recursiva" << std::endl;
	/*
	 * X - Tamanho da base de busca
	 * Y - Tempo de execução
	 * W - Chave de busca						 
	*/
	arqsaidaSR2 << "#X" << std::setw(10) << "#Y" << std::endl;

	// Gravando dadosSR3.txt
	std::ofstream arqsaidaSR3;
	arqsaidaSR3.open( "dadosSR3.txt", std::ios::out );
	if( !arqsaidaSR3.is_open() ){
		return 0;
	}

	std::cout << "Gerando dados SR..." << std::endl;

	// Grava o cabeçalho
	arqsaidaSR3 << "#Dados para o script geraGrafico.gnu da Busca Sequencial Recursiva" << std::endl;
	/*
	 * X - Tamanho da base de busca
	 * Y - Tempo de execução
	 * W - Chave de busca						 
	*/
	arqsaidaSR3 << "#X" << std::setw(10) << "#Y" << std::endl;





	for ( int i = 0 ; i < nBases ; ++i ) { // Fazendo várias buscas, com bases aleatórias de diferentes tamanhos
		
		int tamBase = tamN[i]; // Tamanho da base de busca
		int base[ tamBase ];   // Vetor com os valores da base

		generateRandomBase( base, tamBase ); // Gera base de busca aleatória e ordenada


		/* CHAVES DE BUSCA:
		 * Melhor caso sequencial -> primeiro elemento = base[0].
		 * Pior caso sequencial   -> elemento não existe = base[ tamBase-1 ]+1.
		 * Melhor caso binária    -> elemento do meio = base[ tamBase/2 ].
		 * Pior caso binária      -> elemento não existe = base[ tamBase-1 ]+1.
		*/

		/* MEDIÇÃO DO TEMPO DE CADA IMPLEMENTAÇÃO DE BUSCA E COM CHAVES DE BUSCA DIFERENTES */
		tempoExecucaoBI( arqsaidaBI1, base, tamBase, base[0] );	
		tempoExecucaoBI( arqsaidaBI2, base, tamBase, base[ tamBase-1 ]+1 );	
		tempoExecucaoBI( arqsaidaBI3, base, tamBase, base[ tamBase/2 ] );	

		tempoExecucaoBR( arqsaidaBR1, base, tamBase, base[0] );	
		tempoExecucaoBR( arqsaidaBR2, base, tamBase, base[ tamBase-1 ]+1 );	
		tempoExecucaoBR( arqsaidaBR3, base, tamBase, base[ tamBase/2 ] );	

		tempoExecucaoSI( arqsaidaSI1, base, tamBase, base[0] );	
		tempoExecucaoSI( arqsaidaSI2, base, tamBase, base[ tamBase-1 ]+1 );	
		tempoExecucaoSI( arqsaidaSI3, base, tamBase, base[ tamBase/2 ] );	

		tempoExecucaoSR( arqsaidaSR1, base, tamBase, base[0] );	
		tempoExecucaoSR( arqsaidaSR2, base, tamBase, base[ tamBase-1 ]+1 );	
		tempoExecucaoSR( arqsaidaSR3, base, tamBase, base[ tamBase/2 ] );	
		
	}

	// FECHANDO ARQUIVO COM DADOS BI
	std::cout << "Fechando o arquivo dadosBI.txt..." << std::endl;
	arqsaidaBI1.close();
	arqsaidaBI2.close();
	arqsaidaBI3.close();

	// FECHANDO ARQUIVO COM DADOS BR
	std::cout << "Fechando o arquivo dadosBR.txt..." << std::endl;
	arqsaidaBR1.close();
	arqsaidaBR2.close();
	arqsaidaBR3.close();

	// FECHANDO ARQUIVO COM DADOS SI
	std::cout << "Fechando o arquivo dadosSI.txt..." << std::endl;
	arqsaidaSI1.close();
	arqsaidaSI2.close();
	arqsaidaSI3.close();

	// FECHANDO ARQUIVO COM DADOS SR
	std::cout << "Fechando o arquivo dadosSR.txt..." << std::endl;
	arqsaidaSR1.close();
	arqsaidaSR2.close();
	arqsaidaSR3.close();

	
	return 0;

}

/**
 * @brief Realiza a medição do tempo da execução do algoritmo de busca binária iterartiva.
 * @details Função implementada fazendo uso das bibliotecas iomanip e time.h.
 * @param arqsaida Arquivo de saída dos dados.
 * @param V Vetor com a base de busca.
 * @param n Tamanho da base de busca.
 * @param x Chave de busca.
 * @return O tempo de execução do algoritmo de busca binária iterartiva.
 */
int tempoExecucaoBI( std::ofstream & arqsaidaBI, int *V, int n, int x ){


	clock_t Ticks[8];

    Ticks[0] = clock();
	bBinariaIterativa( V, n, x );
	Ticks[1] = clock();
	double tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;

	// Gravando os registros numéricos
	arqsaidaBI << n << std::setw(10) << tempo << x << std::endl;

	// Tratamento de erro de leitura de arquivo
	if( arqsaidaBI.fail() ) {
		std::cout << "Erro fatal!" << std::endl;
		exit(1); // Aborta programa
	}

	return 0;

}

/**
 * @brief Realiza a medição do tempo da execução do algoritmo de busca binária recursiva.
 * @details Função implementada fazendo uso das bibliotecas iomanip e time.h.
 * @param arqsaida Arquivo de saída dos dados.
 * @param V Vetor com a base de busca.
 * @param n Tamanho da base de busca.
 * @param x Chave de busca.
 * @return O tempo de execução do algoritmo de busca binária recursiva.
 */
int tempoExecucaoBR( std::ofstream & arqsaidaBR, int *V, int n, int x ){


	clock_t Ticks[8];

	Ticks[2] = clock();
	bBinariaRecursiva( V, n, x );
	Ticks[3] = clock();
	double tempoBR = (Ticks[3] - Ticks[2]) * 1000.0 / CLOCKS_PER_SEC;

	// Gravando os registros numéricos
	arqsaidaBR << n << std::setw(10) << tempoBR << std::endl;

	// Tratamento de erro de leitura de arquivo
	if( arqsaidaBR.fail() ) {
		std::cout << "Erro fatal!" << std::endl;
		exit(1); // Aborta programa
	}

	return 0;

}

/**
 * @brief Realiza a medição do tempo da execução do algoritmo de busca sequencial iterartiva.
 * @details Função implementada fazendo uso das bibliotecas iomanip e time.h.
 * @param arqsaida Arquivo de saída dos dados.
 * @param V Vetor com a base de busca.
 * @param n Tamanho da base de busca.
 * @param x Chave de busca.
 * @return O tempo de execução do algoritmo de busca sequencial iterartiva.
 */
int tempoExecucaoSI( std::ofstream & arqsaidaSI, int *V, int n, int x ){


	clock_t Ticks[8];

	Ticks[4] = clock();
	bSequencialIterativa( V, n, x );
	Ticks[5] = clock();
	double tempoSI = (Ticks[5] - Ticks[4]) * 1000.0 / CLOCKS_PER_SEC;

	// Gravando os registros numéricos
	arqsaidaSI << n << std::setw(10) << tempoSI << std::endl;

	// Tratamento de erro de leitura de arquivo
	if( arqsaidaSI.fail() ) {
		std::cout << "Erro fatal!" << std::endl;
		exit(1); // Aborta programa
	}

	return 0;

}

/**
 * @brief Realiza a medição do tempo da execução do algoritmo de busca sequencial recursiva.
 * @details Função implementada fazendo uso das bibliotecas iomanip e time.h.
 * @param arqsaida Arquivo de saída dos dados.
 * @param V Vetor com a base de busca.
 * @param n Tamanho da base de busca.
 * @param x Chave de busca.
 * @return O tempo de execução do algoritmo de busca sequencial recursiva.
 */
int tempoExecucaoSR( std::ofstream & arqsaidaSR, int *V, int n, int x ){

	clock_t Ticks[8];

	Ticks[6] = clock();
	bSequencialRecursiva( V, n, x );
	Ticks[7] = clock();
	double tempoSR = (Ticks[7] - Ticks[6]) * 1000.0 / CLOCKS_PER_SEC;

	// Gravando os registros numéricos
	arqsaidaSR << n << std::setw(10) << tempoSR << std::endl;

	// Tratamento de erro de leitura de arquivo
	if( arqsaidaSR.fail() ) {
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

    return 0;
 
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