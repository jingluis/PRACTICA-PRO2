/** @file SalaBinTree.hh
    @brief Especificación de la distribución de Salas
*/

#include "Almacen.hh"
#ifndef _SALABINTREE_
#define _SALABINTREE_
#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include "BinTreeIOint.hh"
#endif

/*
 * Clase SalaBinTree
 */

/** @class SalaBinTree
    @brief Representa la relación que hay entre las salas del almacen.

    Ofrece operacion modificadoras y consultora de distribución.

    Dado que vamos a necesitar leer arbol de enteros, se emplea una "marca" para indicar la lectura de un arbol vacío.
*/
class SalaBinTree{
private:

  /** @brief Muestra información sobre la organización de la Sala */
  BinTree <int> distribucion;
  /** @brief operación de imersión en el cual se hace la distribución de los elementos
      \pre A = dis, almacen = a, p es un identificador válido y existe en el sistema.
      \post El resultado la cantidad del producto p que quedan para distribuir. Los productos se han distribuido en las salas correspondientes.
  */
  static int i_distribuir_sala(const BinTree<int>& dis, Almacen& a, const string& p, int c);

public:

    /** @brief Creadora por defecto.
        @pre Cierto.
        @post El resultado es un arbol de entero vacío.
    */
  SalaBinTree();

  /** @brief Operacion de lectura
      \pre El arbol es vacío; el canal estandar d'entrada contiene el recorrido en preorden de un arbol binario A de enteros.
      \post El resultado es un arbol leído en preorden.
  */
  void leer_distribucion();

  /** @brief Modificadora y consultora de elementos restantes que quedan para distribuir.
      \pre p es un identificador válido y existe en el sistema.
      \post el resultado la cantidad del producto p que quedan para distribuir. Los productos se han distribuido en las salas correspondientes.
  */
  int distribuir(Almacen& a, const string& p, int c);


};
#endif
