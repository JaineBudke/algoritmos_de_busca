/********************************************************************* 
*
* bSequencialIterativa.cpp
*
* Dada uma chave de busca, retorna se valor está na base de dados.
* 
*********************************************************************/


#include <iostream>
#include "bSequencialIterativa.h"


/**!
 * Essa função realiza uma busca sequencial em uma base de dados, passada por 
 * parametro por meio de um vetor de tamanho n.
 * Este algoritmo de busca foi implementado de maneira iterativa.
 *
 * @param V Vetor com a base de busca.
 * @param n Tamanho do vetor.
 * @param x Chave de busca.
 *
 * @return Se elemento foi encontrado.
 * 		   { 0 - elemento não encontrado
 *		   	 1 - elemento encontrado   }
 */
int bSequencialIterativa( int *V, int n, int x ){

	for (int i = 0 ; i < n ; ++i) {
		if ( V[i] == x ) {
			return 1;
			break;
		}
	}

	return 0;

}