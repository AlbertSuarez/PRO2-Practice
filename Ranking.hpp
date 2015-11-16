/** @file Ranking.hpp
    @brief Especificación de la clase Ranking
*/

#ifndef _RANKING_HPP_
#define _RANKING_HPP_

#include "utils.PRO2"
#include<vector>
#include<list>



/** @class Ranking
    @brief Representa un ranking de todos los organismos del experiment
*/

class Ranking
{
private:
  /** @brief Sequencia de listas de familias del ranking */
  vector<list<pair<int,int> > > rank;
  /** @brief Sequencia de las posiciones dels organismes */
  vector<int> posicions;

public:
  // Constructoras

  /** @brief Creadora con valor predeterminado.

      \pre N > 1, N < M
      \post El resultado es un ranking con tamaño inicial N y tamaño maximo M
  */
  Ranking(int N, int M);

  /** @brief Actualizadora del ranking.

      \pre a i b identificadores de los padres del identificador de su respectivo hijo c
      \post El p.i. se ha actualizado
  */
  void actualizar_ranking(int a, int b, int c);

  // Escritura de ranking

  /** @brief Operación de escritura.

      \pre cierto
      \post Se han escrito los atributos del parámetro implícito en el canal
      standard de salida.
  */
  void escribir_ranking() const;

};

#endif
