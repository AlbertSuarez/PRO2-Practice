/** @file Experiment.hpp
    @brief Especificación de la clase Experiment
*/

#ifndef _EXPERIMENT_HPP_
#define _EXPERIMENT_HPP_

#include "Ranking.hpp"
#include "Organisme.hpp"
#include "Celula.hpp"
#include<vector>

/** @class Experiment
    @brief Representa un experiment como un conjunto de organismes
*/

class Experiment
{
private:
  /** @brief Indica los maximos organismos posibles del experiment */
  int MAXORGANISMES;            // MAXORGANISMES numero natural
  /** @brief Indica los organismos vivos y muertos del experiment */
  int mida;                   // tamano numero natural
  /** @brief Indica los organismos vivos del experiment */
  int vius;                     // vius numero natural
  /** @brief Sequencia de todos los organismes del experiment */
  vector<Organisme> EXP;
  /** @brief Matriu que indica si dos organismos se han reproducido (true) o no (false) */
  vector<vector<bool> > emparellats;
  
public:
  // Constructoras
  
  /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar un experiment.
      \pre cierto
      \post El resultado es un experiment vacio
  */  
  Experiment();
  
  /** @brief Creadora con tamaño predeterminado.

      Permite declarar un experiment nuevo con tamaño maximo especificado.
      \pre m > 2
      \post El resultado es un experiment de tamano maximo m
  */  
  Experiment(int m);
  
  // Modificadoras

  /** @brief Ronda de reproducción de organismes
    
      \pre cierto
      \post El resultado es el numero de hijos producidos en la ronda de reproduccion y además
            el parametro implicito se modifica despues de la ronda de reproduccion y R actualizado
  */
  int reproduccion(Ranking &R);

  /** @brief Crecimiento de un organismo

      \pre 1 <= x <= M y organisme x pot creixer
      \post El elemento xessimo del p.i. ha sufrido un estiron
  */
  void estiron(int x);

  /** @brief Decrecimiento de un organismo

      \pre 1 <= x <= M y organisme x vivo
      \post El elemento xessimo del p.i. ha sufrido un recorte
  */
  void recorte(int x);
  
  // Consultoras
  
  /** @brief Consultora de tamaño
   
      \pre cierto
      \post El resultado es el numero de organismes del parametro implicito
  */
  int tamano() const;
  
  /** @brief Consultora de tamaño máximo
   
      \pre cierto
      \post El resultado es el maximo numero de organismes del parametro implicito
  */
  int tamano_maximo() const;

  /** @brief Consultora de organismos vivos

      \pre cierto
      \post El resultado es el numero de organismes vivos del parametro implicito
  */
  int consultar_vius() const;
  
  /** @brief Consultora de muerte de todos los organismos

      \pre cierto
      \post El resultado es si todos los organismos estan muertos
  */
  bool muerto() const;

  // Lectura de Experiment
  
  /** @brief Operación de lectura.

      \pre marca < tamaño maximo
      \post Se han leido los atributos del parámetro implícito en el canal
      standard de entrada. 
  */
  void leer_experiment(int marca);

  // Escritura

  /** @brief Operación de escritura de un organisme del experiment

      \pre 1 <= x <= M
      \post Se han escrito los atributos del elemento xessimo del p.i. en el canal standard de salida.
  */
  void escribir_organisme(int x);

  /** @brief Operación de escritura de los ultimos hijos de la ronda

      \pre 1 <= x <= M
      \post Se han escrito los atributos del los ultimos x organismes del p.i. en la ultima ronda de reproduccion en el canal standard de salida.
  */
  void escribir_ultims(int x);
  
};

#endif
