/**
 * @file    buscas.cpp
 * @brief   Código fonte com a implementacao de funcoes que
            realizam uma busca em uma base de dados, passada por
            parametro por meio de um vetor, de tamanho n.
 * @author  Bianca Santiago (bianca.santiago72@gmail.com)
 * @author  Jaine Budke (jainebudke@hotmail.com)
 * @since   25/03/2017
 * @date    16/04/2017
 */

#include "buscas.h"

/**
 * @brief Realiza uma busca binária em uma base de dados, passada por 
          parametro por meio de um vetor, de tamanho n.
 * @details Algoritmo de busca implementado de maneira iterativa.
 * @param V Vetor com a base de busca.
 * @param n Tamanho do vetor.
 * @param x Chave de busca.
 * @return Se elemento foi encontrado ("1" se encontrado ou "0" se não encontrado).
 */
int bBinariaIterativa( int *V, int n, int x ){
	
    int inf = 0;   // limite inferior
    int sup = n-1; // limite superior
    int indice;    // indice do meio

    while ( inf <= sup ) {
        
        indice = ( inf + sup ) / 2; 
        int valorMemoria = V[indice];
        
        if ( x == valorMemoria ) {
            return 1;
        } else if ( valorMemoria > x ) {
            sup = indice-1;
        } else if( valorMemoria < x ) {
            inf = indice+1;
        }

    }

    return 0; // valor não encontrado

}

/**
 * @brief Realiza uma busca binária em uma base de dados, passada por 
          parametro por meio de um vetor, de tamanho n.
 * @details Algoritmo de busca implementado de maneira recursiva.
 * @param V Vetor com a base de busca.
 * @param n Tamanho do vetor.
 * @param x Chave de busca.
 * @return Se elemento foi encontrado ("1" se encontrado ou "0" se não encontrado).
 */
int bBinariaRecursiva( int *V, int n, int x ){
    
    if ( n == 0 )   // vetor vazio, não encontrou elemento
        return -1;
    
    int indice = n/2;   // indice elemento do meio
    
    int valorMemoria = V[indice]; // valor elemento do meio
    
    if ( valorMemoria == x ) // encontrou elemento
        return 1;
    
    else if ( valorMemoria > x ) { // realiza busca na primeira metade
        return( bBinariaRecursiva( V, indice, x ) );
    }

    else if( valorMemoria < x ) { // realiza busca na segunda metade
        return( bBinariaRecursiva(&V[indice+1], n-indice-1, x) );
    }
    return 0;

}

/**
 * @brief Realiza uma busca sequencial em uma base de dados, passada por 
          parametro por meio de um vetor, de tamanho n.
 * @details Algoritmo de busca implementado de maneira iterativa.
 * @param V Vetor com a base de busca.
 * @param n Tamanho do vetor.
 * @param x Chave de busca.
 * @return Se elemento foi encontrado ("1" se encontrado ou "0" se não encontrado).
 */
int bSequencialIterativa( int *V, int n, int x ){

    for ( int i = 0 ; i < n ; ++i ) {
        if( V[i] == x ){
            return 1;
        }
        else if( V[i] > x ){
            return 0;
        }
    }

    return 0;

}

/**
 * @brief Realiza uma busca sequencial em uma base de dados, passada por 
          parametro por meio de um vetor, de tamanho n.
 * @details Algoritmo de busca implementado de maneira recursiva.
 * @param V Vetor com a base de busca.
 * @param n Tamanho do vetor.
 * @param x Chave de busca.
 * @return Se elemento foi encontrado ("1" se encontrado ou "0" se não encontrado).
 */
int bSequencialRecursiva( int *V, int indice, int n, int x ){

    if( indice == n ){
        return 0;
    } else if( V[indice] > x ){
        return 0;
    } else if( x == V[indice] ){
        return 1;
    } else {
        return bSequencialRecursiva( V, indice+1, n, x );
    }

}