/********************************************************************* 
*
* bBinariaIterativa.cpp
*
* Dada uma chave de busca, retorna se valor está na base de dados.
* 
*********************************************************************/

#include <iostream>
#include "bBinariaIterativa.h"

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
int bBinariaIterativa( int *V, int n, int x ){
	
    int inf = 0;   // limite inferior
    int sup = n-1; // limite superior
    int indice;    // indice do meio

    while ( inf <= sup ) {
        
        indice = ( inf + sup ) / 2; 
        
        if ( x == V[indice] ) {
            return 1;
        } else if ( x < V[indice] ) {
            sup = indice-1;
        } else {
            inf = indice+1;
        }

    }
    
    return 0; // valor não encontrado

}