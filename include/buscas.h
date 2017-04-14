/**
 * @file	buscas.h
 * @brief	Arquivo cabeçalho com a implementacao de funcoes que
 			realizam uma busca em uma base de dados, passada por
 			parametro por meio de um vetor, de tamanho n.
 * @author	Bianca Santiago (bianca.santiago72@gmail.com)
 * @author	Jaine Budke (jainebudke@hotmail.com)
 * @since	25/03/2017
 * @date	16/04/2017
 */

#ifndef BUSCAS_H
#define BUSCAS_H

#include <iostream> 
using std::cout;
using std::endl;

#include <iomanip>
#include <time.h>

#include <ctime>
#include <cstdlib>

#include <fstream>
#include <string>


/**
 * @brief Realiza a medição do tempo da execuçaõ de cada algoritmo de busca.
 * @details Função implementada fazendo uso das bibliotecas iomanip e time.h.
 * @param arqsaida Arquivo de saída dos dados.
 * @param V Vetor com a base de busca.
 * @param n Tamanho do vetor.
 * @param x Chave de busca.
 * @return O tempo de execução dos algoritmos de busca.
 */
int tempoExecucao( std::ofstream & arqsaida, int *V, int n, int x );


/**
 * @brief Realiza a comparação entre dois valores.
 * @param a Primeiro valor para comparação.
 * @param b Segundo valor para comparação.
 * @return Se a é menor, maior ou igual a b.
 */
int compare( const void * a, const void * b );


/**
 * @brief Gera a base de busca aleatória.
 * @details Função implementada fazendo uso das bibliotecas ctime e cstdlib.
 * @param base Vetor com a base de busca.
 * @param tamBase Tamanho da base de busca.
 */
void generateRandomBase( int *base, int tamBase );


/**
 * @brief Realiza uma busca binária em uma base de dados, passada por 
          parametro por meio de um vetor, de tamanho n.
 * @details Algoritmo de busca implementado de maneira iterativa.
 * @param V Vetor com a base de busca.
 * @param n Tamanho do vetor.
 * @param x Chave de busca.
 * @return Se elemento foi encontrado ("1" se encontrado ou "0" se não encontrado).
 */
int bBinariaIterativa( int *V, int n, int x );

/**
 * @brief Realiza uma busca binária em uma base de dados, passada por 
          parametro por meio de um vetor, de tamanho n.
 * @details Algoritmo de busca implementado de maneira recursiva.
 * @param V Vetor com a base de busca.
 * @param n Tamanho do vetor.
 * @param x Chave de busca.
 * @return Se elemento foi encontrado ("1" se encontrado ou "0" se não encontrado).
 */
int bBinariaRecursiva( int *V, int n, int x );

/**
 * @brief Realiza uma busca sequencial em uma base de dados, passada por 
          parametro por meio de um vetor, de tamanho n.
 * @details Algoritmo de busca implementado de maneira iterativa.
 * @param V Vetor com a base de busca.
 * @param n Tamanho do vetor.
 * @param x Chave de busca.
 * @return Se elemento foi encontrado ("1" se encontrado ou "0" se não encontrado).
 */
int bSequencialIterativa( int *V, int n, int x );

/**
 * @brief Realiza uma busca sequencial em uma base de dados, passada por 
          parametro por meio de um vetor, de tamanho n.
 * @details Algoritmo de busca implementado de maneira recursiva.
 * @param V Vetor com a base de busca.
 * @param n Tamanho do vetor.
 * @param x Chave de busca.
 * @return Se elemento foi encontrado ("1" se encontrado ou "0" se não encontrado).
 */
int bSequencialRecursiva( int *V, int n, int x );

#endif