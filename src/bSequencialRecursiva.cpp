/********************************************************************* 
*
* bSequencialRecursiva.cpp
*
* Dada uma chave de busca, retorna se valor está na base de dados.
* 
*********************************************************************/


#include <iostream>
#include "bSequencialRecursiva.h"


/**!
 * Essa função realiza uma busca sequencial em uma base de dados, passada por 
 * parametro por meio de um vetor de tamanho n.
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
int bSequencialRecursiva( int *V, int n, int x ){

	if ( n == 0 ) { // vetor vazio, elemento não encontrado
		return 0;
	} else if ( V[n] == x ) {  // encontrou elemento
		return 1;
	} else {
		return bSequencialRecursiva( V , n-1 , x );
	}

}