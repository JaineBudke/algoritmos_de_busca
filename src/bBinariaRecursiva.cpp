/********************************************************************* 
*
* bBinariaRecursiva.cpp
*
* Dada uma chave de busca, retorna se valor está na base de dados.
* 
*********************************************************************/

#include <iostream>
#include "bBinariaRecursiva.h"

/**!
 * Essa função realiza uma busca binária em uma base de dados, passada por 
 * parametro por meio de um vetor, de tamanho n.
 * Este algoritmo de busca foi implementado de maneira recursiva.
 *
 * @param V Vetor com a base de busca.
 * @param n Tamanho do vetor.
 * @param x Chave de busca.
 *
 * @return Se elemento foi encontrado.
 * 		   { 0 - elemento não encontrado
 *		   	 1 - elemento encontrado   }
 */
int bBinariaRecursiva( int *V, int n, int x ){
	
	if ( n == 0 )	// vetor vazio, não encontrou elemento
		return -1;
	
	int indice = n/2;	// indice elemento do meio
	
	int valorMemoria = V[indice]; // valor elemento do meio
	
	if ( valorMemoria == x ) // encontrou elemento
		return indice;
	
	else if ( valorMemoria > x ) { // realiza busca na primeira metade
		return( bBinariaRecursiva( V, indice, x ) );
	}

	else if( valorMemoria < x ) { // realiza busca na segunda metade
		return( bBinariaRecursiva(&V[indice+1], n-indice-1, x) );
	}

}