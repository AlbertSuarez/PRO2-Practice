/** @file Celula.hpp
    @brief Especificación de la clase Celula
*/

#ifndef _CELULA_HPP_
#define _CELULA_HPP_

#include "utils.PRO2"

/** @class Celula
    @brief Representa una celula con atributos identificador y actividad
*/

class Celula
{
private:
  /** @brief Identificador de la celula */
  int id;               // id número natural
  /** @brief Indica si es activa (true) o pasiva (false) */
  bool activa;          // activa = true    pasiva = false
  
public:
  // Constructoras
  
  /** @brief Creadora por defecto.
      
      Se ejecuta automáticamente al declarar una celula
      \pre cierto
      \post El resultado es una celula sin valores determinados para sus atributos
  */
  Celula();
  
  /** @brief Creadora con valores concretos.
      
      \pre iden > 0
      \post El resultado es una celula con identificador "iden" y actividad "activ"
  */
  Celula(int iden, bool activ);
  
  // Modificadoras

  /** @brief Modificadora del identificador.

      \pre iden > 0
      \post El parámetro implícito pasa a tener identificador "iden"
  */
  void modificar_id(int iden);

  /** @brief Modificadora de la actividad.

      \pre cierto
      \post El parámetro implícito pasa a tener actividad "activ"
  */
  void modificar_activa(bool activ);

  // Consultoras

  /** @brief Consultora del identificador.

      \pre cierto
      \post El resultado es el identificador del parámetro implícito
  */
  int consultar_id() const;
 
  /** @brief Consultora de la actividad.

      \pre cierto
      \post El resultado es la actividad del parámetro implícito
  */
  bool consultar_activa() const;

  // Lectura de celula
  
  /** @brief Operación de lectura.

      \pre cierto
      \post Se han leido los atributos del parámetro implícito en el canal
      standard de entrada. 
  */
  void leer_celula();
  
  // Escritura de celula

  /** @brief Operación de escritura.

      \pre cierto
      \post Se han escrito los atributos del parámetro implícito en el canal
      standard de salida. 
  */
  void escribir_celula() const;
  
};

#endif
