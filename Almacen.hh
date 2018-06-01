/** @file Almacen.hh
    @brief Especificación de la clase Almacen
*/
#ifndef _ALMACEN_
#define _ALMACEN_

#include "Sala.hh"
#ifndef NO_DIAGRAM
#include <vector>
#endif

/*
 * Clase Almacen
 */

/** @class Almacen
    @brief Representa la organización de las salas

    Ofrece operaciones para modificar ciertos productos en una sala determinada y operaciones de lectura/escritura.
*/

class Almacen{

private:
  /** @brief vector donde se almacena las salas */
  vector <Sala> almacen;

public:
  /** @brief Creadora por defecto.
      @pre cierto.
      @post El resultado es un Almacen vacío.
  */
  Almacen();

  /** @brief Creadora de Almacen con n salas.
      @pre n >= 1.
      @post El resultado es un Almacen con n salas vacías.
  */
  Almacen(int n);

  /** @brief Modificadora que coloca un máximo número de cantidad <=c de productos con iden p en la sala n.
      \pre El producto está registrado en el inventario.
      \post se devuelve un entero que indica cuantas unidades con iden p no cabidos en la sala n. Sala n tiene los productos anteriores más tantas unidades de producto con iden p cabidos.
  */
  int poner_items_sala(int n, const string& p, int c);

  /** @brief Modificadora que extrae un máximo número de cantidad <=c de productos con iden p en la sala n.
      \pre   El producto existe en el sistema.
      \post  se devuelve un entero que indica cuantas unidades con iden p no quitados de la sala n. Sala n tiene los productos anteriores menos tantas unidades de producto con iden p quitados.
  */
  int quitar_items_sala(int n, const string& p, int c);
    /** @brief Modificadora que compacta la sala con identificador n.
        @pre Cierto.
        @post La sala con identificador n del parámetro implícito queda compactada.
    */
  void compactar_sala_iden(int n);

  /** @brief Modificadora que compacta la sala con identificador n.
      \pre Cierto.
      \post La sala con identificador n del parámetro implícito queda reorganizada.
  */
  void reorganizar_sala_iden(int n);

  /** @brief Modificadora que redimensiona la sala con identificador n.
      \pre Los productos de la sala con identificador n caben en las nuevas dimensiones.
      \post La sala con identificador n del parámetro implícito queda redimensionada.
  */
  void redimensionar_sala_iden(int n, int i, int j);


  /** @brief Consultora que determina la cantidad de productos en la sala con identifcador n.
      \pre Cierto
      \post  El resultado es el numero de productos en la sala n.
  */
  int consultar_sala_prod(int n) const;

  /** @brief Consultora del producto que está en la sala n en la fila i y columna j.
      \pre Cierto.
      \post  El resultado es el producto de la fila i y columna j de sala n, si no hay producto se devuelve "NULL".
  */
  string consultar_sala_pos_prod(int n, int i, int j) const;

  /** @brief Operacion de lectura
      \pre N>0, el canal de entrada estandar contiene un entero;
      \post en el parametro implicito se ha leído las filas y columnas de cada sala.
  */
  void leer_sala(int n);

  /** @brief Operacion de escritura
      \pre N>0, el canal de entrada estandar contiene un entero;
      \post se ha escrito el contenido de la estanteria, la cantidad total de productos y los productos con su cantidad alfabéticamente de la sala n.
  */
  void escribir_sala(int n) const;
};
#endif
