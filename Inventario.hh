/** @file Inventario.hh
    @brief Especificación de la clase Inventario
*/

#ifndef _INVENTARIO_
#define _INVENTARIO_
#ifndef NO_DIAGRAM
#include <iostream>
using namespace std;
#include <map>
#include "PRO2Excepcio.hh"
#endif


/*
 * Clase Inventario
 */

/** @class Inventario
    @brief Representa el Inventario que controla los productos y su cantidad en el almacen.

    Ofrece operaciones para modificar cierto producto un producto de un producto específico y escritura todos los productos del Inventario.
*/
class Inventario{

private:
/** @brief diccionario de los productos y su cantidad en el almacen.

    Ordenada crecientemente por el id de sus componentes */
  map <string,int> inventario;

public:

/** @brief Creadora por defecto.
    @pre cierto.
    @post El resultado es un Inventario vacío
*/
  Inventario();


/** @brief Modificadora que registra un producto con identificador s con 0 unidad en el Inventario.
    @pre El producto con identificador s no se encuentra en el parámetro implícito.
    @post Se ha registrado el producto con identificador s con 0 unidad en el parámetro implícito.
*/
  void poner_prod(const string& s);



/** @brief Modificadora que elimina el producto con identificador s con 0 unidad en el Inventario.
    @pre El producto con identificador s se encuentra en el parámetro implícito con 0 unidad.
    @post Se ha eliminado el producto con identificador s del parámetro implícito.
*/
  void quitar_prod(const string& s);



/** @brief Modificadora que incrementa n unidades al producto con identificador s.
    @pre El producto con identificador s se encuentra en el parámetro implícito.
    @post El producto con identificador s se le ha aumentado n unidades en el parámetro implícito.
*/
  void aumentar_unidad(const string& s, int n);




/** @brief Modificadora que decrementa n unidad al producto con identificador s.
    @pre El producto con identificador s se encuentra en el parámetro implícito y su cantidad es mayor o igual que n.
    @post El producto con identificador s se le ha decrementado n unidades en el parámetro implícito.
*/
  void disminuir_unidad(const string& s, int n);



/** @brief Consultora del producto con identificador s en el parámetro implícito.
    @pre cierto.
    @post El resultado indica si existe el producto con identificador s en el parámetro implícito.
*/
  bool existir_prod(const string& s) const;



/** @brief Consultora de la cantidad del producto con identificador s del parámetro implícito.
    @pre El producto con identificador s se encuentra en el parámetro implícito.
    @post El resultado indica la cantidad del producto con identificador s del parámetro implícito.
*/
  int consultar_prod(const string& s) const;



/** @brief Operación de escritura de los productos del Inventario.
    \pre  cierto.
    \post Se ha escrito por el canal de salida todos los productos con su cantidad del parámetro implícito.

*/
  void escribir() const;

};
#endif
