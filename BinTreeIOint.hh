#ifndef BINIOINT_HPP
#define BINIOINT_HPP
#ifndef NO_DIAGRAM
#include <iostream>
#include "BinTree.hh"
#endif

/**
    @brief Lectura de un arbol binario de enteros.  Els elements se introducen en preorden: primero la raíz, después el subarbol
    izquierdo y por último el derecho. Los árboles vacíos se representan con una marca.
*/

/**
    @brief Lectura de un árbol binario de enteros.
    \pre a es vacío; el canal estandar de entrada contiene el recorrido en preorden
    de un arbol binario A de enteros
    \post a = A
*/
void read_bintree_int(BinTree<int>& a, int marca);




#endif
