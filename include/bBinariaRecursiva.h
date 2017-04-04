#ifndef _BUSCA_BINARIA_RECURSIVA_
#define _BUSCA_BINARIA_RECURSIVA_


/**!
 * Essa função realiza uma busca binária em uma base de dados, passada por 
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
int bBinariaRecursiva( int *V, int n, int x );


#endif