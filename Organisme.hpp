/** @file Organisme.hpp
    @brief Especificación de la clase Organisme
*/

#ifndef _ORGANISME_HPP_
#define _ORGANISME_HPP_

#include "Celula.hpp"
#include "Arbre.hpp"

/** @class Organisme
    @brief Representa un organisme como arbol de celulas, el máximo identificador y si puede crecer o no
*/

class Organisme
{
private:
  /** @brief Arbre de totes les celules del organisme */
  Arbre<Celula> Organ;
  /** @brief Indica si puede crecer (true) o no (false) */
  bool potcreixer;
  /** @brief Identificador del organisme */
  int id;                   // id número natural
  /** @brief Identificador máximo de un organisme */
  int maxid;                // maxid número natural
  /** @brief Indica el tamaño del organisme */
  int tamano;
  /** @brief Tamaño de la interseccion entre dos organismes
      \pre a = A, b = B
      \post El resultado es el tamaño de la intersección entre A y B
  */
  int interseccion(Arbre<Celula>& a, Arbre<Celula>& b);
  /** @brief Compatibilidad entre dos organismes
      \pre a = A, b = B
      \post El resultado es si A y B son compatibles (true) o no (false)
  */
  bool compatibles(Organisme& a, Organisme& b);
  /** @brief Immersion de estiron
      \pre a = A
      \post A ha sufrido un estiron
  */
  void crece(Arbre<Celula>& a);
  /** @brief Immersion de recorte
      \pre a = A
      \post A ha sufrido un recorte y canviamax indica si la maxid de A ha cambiado
  */
  void decrece(Arbre<Celula>& a, bool& canviamax);
  /** @brief Immersion de lectura del organisme
      \pre cierto
      \post Se han leido los atributos del parámetro implícito en el canal
      standard de entrada.
  */
  void i_leer_organisme(Arbre<Celula>& a, int marca);
  /** @brief Immersion de escritura del organisme
      \pre cierto
      \post Se han escrito los atributos del parámetro implícito en el canal
      standard de salida
  */
  void i_escribir_organisme(Arbre<Celula>& a);
  /** @brief Tamaño de la interseccion entre dos organismes
      \pre a = A
      \post El resultado es si A tiene alguna celula activa (true) o no (false)
  */
  bool te_activa(Arbre<Celula>& a);
  /** @brief Immersion de la reproduccion
      \pre maximid es el identificador maximo de m y h es el hijo de la reproduccion de entre m y n
           y m y n son compatibles
      \post h contiene el organisme hijo resultante de la reproduccion entre m y n
  */
  void i_reproduccion(Arbre<Celula>& m, Arbre<Celula>& n, Arbre<Celula>& h, int& maximid, int& tamanofill, bool& casraro);
  /** @brief Busqueda del id maximo
      \pre a = A, max = 0
      \post max indica el maxim id del arbre A
  */
  void buscar_maxid(Arbre<Celula>& a, int& max);
  
public:
  // Constructoras 

  /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar un organisme.
      \pre cierto
      \post El resultado es un organisme vacio
  */  
  Organisme();
  
  /** @brief Creadora copiadora. 

      Permite declarar un organisme nuevo como copia de otro ya existente.
      \pre cierto
      \post El resultado es un organisme igual que o
  */  
  Organisme(const Organisme& o);
  
  // Modificadoras
  
  /** @brief Crecimiento de un organisme
   
      \pre potcreixer = true
      \post El parametro implícito sufre un estirón
  */
  void estiron();
  
  /** @brief Decrecimiento de un organisme
   
      \pre El parametro implícito esta vivo
      \post El parametro implícito sufre un recorte
  */
  void recorte();
  
  /** @brief Reproducción de organismes
    
      \pre cierto
      \post El p.i. (hijo) es el organsime resultante de la reproduccion de m y n si m y n son compatibles,
            altramente no hace nada.
  */
  void reproduccion(Organisme& m, Organisme& n);
  
  // Consultoras
  
  /** @brief Consultora de vida de un organisme
    
      \pre cierto
      \post El resultado es si el parametro implícito esta vivo o no
  */
  bool esta_vivo() const;
  
  /** @brief Consultora de tamaño del organisme
    
      \pre cierto
      \post El resultado es el tamaño del organisme
  */
  int consultar_tamano() const;

  /** @brief Consultora de maximo identificador

      \pre cierto
      \post El resultado es el identificador del p.i.
  */
  int consultar_id() const;

  /** @brief Consultora de maximo identificador

      \pre cierto
      \post El resultado es el maximo identificador del p.i.
  */
  int consultar_maxid() const;

  /** @brief Consultora de posibilidad de crecer

      \pre cierto
      \post El resultado es si puede crecer el organismo o no
  */
  bool consultar_potcreixer() const;
  
  // Lectura de Organisme
  
  /** @brief Operación de lectura.

      \pre num = identificador del organisme a llegir
      \post Se han leido los atributos del parámetro implícito en el canal
      standard de entrada. 
  */
  void leer_organisme(int& num);
    
  // Escritura de Organisme
  
  /** @brief Operación de escritura.

      \pre cierto
      \post Se han escrito los atributos del parámetro implícito en el canal
      standard de salida. 
  */
  void escribir_organisme();
  
};

#endif
