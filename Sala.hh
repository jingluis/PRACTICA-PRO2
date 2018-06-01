/** @file Sala.hh
    @brief Especificación de la clase Sala
*/

#ifndef _SALA_
#define _SALA_
#ifndef NO_DIAGRAM
#include "Inventario.hh"
#include <vector>
#include <map>
#endif


typedef vector <vector <string> > Matriz;

/*
 * Clase Sala
 */

/** @class Sala
    @brief Representa el contenido de una Sala

    Ofrece operaciones consultoras y modificadoras de la Sala y operación de escritura.
*/
class Sala{
private:

  /** @brief Lugar donde se guarda los productos del parámetro implícito */
  Matriz estanteria;
  /** @brief información sobre cada producto y su cantidad del parámetro implícito */
  map<string,int> prod_existente;
  /** @brief la cantidad total de productos en el parámetro implícito */
  int cantidad;
  /** @brief información sobre el número de filas en el parámetro implícito */
  int row;
  /** @brief información sobre el número de columnas en el parámetro implícito */
  int column;
  /** @brief indica si hay que compactar el parámetro implícito o no para evitar compactaciones inecesarias*/
  bool compactado;

  /** @brief Consultora que devuelve la primera posición no nula del parámetro implícito a partir de la posición i,j
      @pre i,j >= 0
      @post i = la fila del primer elemento no nulo, j = la columna del primer elemento no nulo.
  */
  void first_pos_no_null(int& i, int& j) const;

  /** @brief Consultora que devuelve la primera posición nula del parámetro implícito a partir de la posición i,j
      @pre i,j >= 0
      @post i = la fila del primer elemento nulo, j = la columna del primer elemento nulo.
  */
  void first_pos_null(int& i, int& j) const;

  /** @brief Modificadora que compacta el parámetro implícito
      @pre Cierto.
      @post El resultado devuelve el parámetro implícito compactado.
  */
  void compactar_sala();

  /** @brief Modificadora que reorganiza el parámetro implícito
      @pre Cierto.
      @post El resultado devuelve el parámetro implícito reorganizado.
  */
  void reorganizar_sala();



public:

  /** @brief Creadora por defecto.
      @pre cierto.
      @post El resultado es el parámetro implícito vacío.
  */
  Sala();

  /** @brief Creadora de Sala con fila i y columna j.
      @pre Cierto.
      @post El resultado es el parámetro implícito con fila i y columna j.
  */
  Sala(const int& i, const int& j);

  /** @brief Modificadora que coloca el maximo número de producto con identificador p en el parámetro implícito y consulta el número de productos no cabidos.
      \pre El producto existe en el Inventario.
      \post  El resultado es el número de productos con identifcador p no cabidos en el parámetro implícito. El parámetro implícito tiene los productos anteriores más tantas unidades de producto con iden p cabidos.
  */
  int poner_items(const string& p, int c);

  /** @brief Modificadora que extrae el maximo número de producto con identificador p en  el parámetro implícito y consulta el número de productos no extraídos.
      \pre El producto existe en el Inventario.
      \post  El resultado es el número de productos con identifcador p no extraídos en el parámetro implícito. El parámetro implícito tiene los productos anteriores menos tantas unidades de producto con iden p quitados.
  */
  int quitar_items(const string& p, int c);

  /** @brief Modificadora que compacta la sala.
      @pre Cierto.
      @post El parámetro implícito queda compactada con el orden de productos antes de compactar.
  */
  void compactar();

  /** @brief Modificadora que compacta el parámetro implícito con identificador n.
      \pre Cierto.
      \post  El parámetro implícito queda reorganizada.
  */
  void reorganizar();

  /** @brief Modificadora que redimensiona el parámetro implícito.
      \pre Los productos de la sala del parámetro implícito caben en las nuevas dimensiones.
      \post  El parámetro implícito queda redimensionada.
  */
  void redimensionar(const int& fila, const int& columna);

  /** @brief Consultora del número total de productos del parámetro implícito.
      \pre Cierto.
      \post Devuelve el número total de productos del parámetro implícito.
  */
  int consultar_total() const;

  /** @brief Consultora del producto que está en el parámetro implícito en la fila i y columna j.
      \pre Cierto.
      \post  El resultado es el producto de la fila i y columna j del parámetro implícito, si no hay producto se devuelve "NULL".
  */
  string consultar_pos(const int& fila, const int& columna) const;

  /** @brief Operacion de escritura
      \pre Cierto
      \post Se ha escrito el contenido de la estanteria, la cantidad total de productos y los productos con su cantidad alfabéticamente del parámetro implícito.
  */
  void escribir() const;

};
#endif
