#ifndef _BUSCA_BINARIA_ITERATIVA_
#define _BUSCA_BINARIA_ITERATIVA_


/**!
 * Essa função realiza uma busca binária em uma base de dados, passada por 
 * parametro por meio de um vetor, de tamanho n.
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
int bBinariaIterativa( int *V, int n, int x );


#endif