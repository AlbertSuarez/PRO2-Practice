/**
 * @mainpage PRACTICA de PRO2.
 
PRIMAVERA 2014.

Los científicos de un laboratorio de investigación biológica desean llevar a
cabo una serie de experimentos para estudiar el ciclo de vida de una especie de
organismos celulares sencillos.

Los científicos del laboratorio jugaran con organismos de células estructurados
en forma de árbol. Cada célula del organismo contiene dos atributos: el identificador
(un número natural mayor que zero) y la actividad, ya que una célula puede ser o bien
activa (true) o pasiva (false).

Por cada experimento que realizen recibiran al inicio unos N organismos iniciales, con
un M maximo organismos por el experimento, dónde M siempre será mas grande estrictamente
que N.

Entonces a partir de estos N organismos iniciales dispondran de cinco opciones para
poder trabajar con ellos:

Opción 1. Aplicar un estirón a un subconjunto de organismos.

Opción 2. Aplicar un recorte a un subconjunto de organismos.

Opción 3. Aplicar una ronda de reproducción en el experimento.

Opción 4. Obtener el ranking de reproducción de todos los organismos existentes.

Opción 5. Consultar el estado de un subconjunto de organismos.

Después de todo ello, el experimento finalizará cuando o bien lo finalizen manualmente,
o todos los organismos hayan muerto o se haya alcanzado el máximo permitido.

*/

/** @file pro2.cpp
    @brief Programa principal para la PRACTICA de PRO2.
*/

#include "utils.PRO2"
#include "Ranking.hpp"
#include "Experiment.hpp"
#include "Organisme.hpp"

/** @brief Programa principal para la PRACTICA de PRO2.
*/

int main()
{
  // leer los valores enteros N (población inicial del experimento, mayor que 1)
  int N = readint();
  
  // leer M (máximo permitido de población histórica, mayor que N).
  int M = readint();

  // leer los N organismos iniciales. Cada organismo ha de tener al 
  // menos una célula (es decir, ha de estar vivo).
  Experiment exp(M);
  Ranking R(N,M);
  int fills_ronda;
  exp.leer_experiment(N);
  
  int op = readint();
  while (op != -6 and exp.tamano() < exp.tamano_maximo() and not exp.muerto()) {
    if (op == -1) {
      // Aplicar un estirón a un subconjunto de organismos. Se proporciona una
      // secuencia de enteros no repetidos entre 1 y M.  Los organismos que estén
      // vivos (y no hayan empezado a sufrir recortes) en el momento de realizar la
      // tarea, cuyos identificadores estén en la secuencia, sufrirán el
      // correspondiente estirón.
      int x = readint();
      for (int i = 0; i < x; ++i) {
        int y = readint();
        exp.estiron(y);
      }
    }
    
    else if (op == -2) {
      // Aplicar un recorte a un subconjunto de organismos. Se proporciona una
      // secuencia de enteros no repetidos entre 1 y M.  Los organismos que estén
      // vivos en el momento de realizar la tarea, cuyos identificadores estén en la
      // secuencia, sufrirán el correspondiente recorte.
      int x = readint();
      for (int i = 0; i < x; ++i) {
        int y = readint();
        exp.recorte(y);
      }
    }
    
    else if (op == -3) {
      // Aplicar una ronda de reproducción a todos los organismos. Actualizar el
      // ranking consecuentemente. Escribir el número de hijos nacidos en la ronda.
      cout << "RONDA DE EMPAREJAMIENTOS" << endl;
      fills_ronda = exp.reproduccion(R);
      cout << "Nuevos organismos : " << fills_ronda << endl;
      cout << endl;
    }
    
    else if (op == -4) {
      // Obtener el ranking de reproducción de los organismos. Para cada organismo,
      // vivo o muerto, que haya existido hasta el momento de la consulta se ha de
      // obtener un listado de sus emparejamientos que hayan producido hijos.  Cada
      // emparejamiento estará representado por el identificador de su compañero y el
      // del hijo. El listado vendrá ordenado por el identificador de los hijos.
      cout << "RANKING" << endl;
      R.escribir_ranking();
      cout << endl;
    }
    
    else if (op == -5) {
      // Consultar el estado de un subconjunto de organismos. Se proporciona una
      // secuencia de enteros no repetidos entre 1 y M.  Se escribirá la estructura
      // celular de los organismos existentes (vivos o muertos) en el momento de
      // realizar la tarea cuyos identificadores estén en la secuencia.
      int x = readint();
      cout << "ORGANISMOS" << endl;
      for (int i = 0; i < x; ++i) {
        int y = readint();
        exp.escribir_organisme(y);
      }
      cout << endl;
    }
    
    if (exp.tamano() < exp.tamano_maximo() or not exp.muerto()) op = readint();
  }

  cout << "FIN" << endl;
  cout << endl;
  
  // Tras el fin del proceso, se ha de indicar la causa. 
  // Si ha sido porque la población ha llegado a M organismos (máximo
  // permitido), se han de realizar dos consultas adicionales:
  // Obtener el ranking
  // Consultar el estado de los organismos nacidos en la última ronda de
  // reproducción (atención: ésta ha podido ser incompleta)
  
  cout << "Organismos en total : " << exp.tamano() << endl;
  cout << "Organismos vivos : " << exp.consultar_vius() << endl;
  cout << endl;

  if (exp.tamano() == exp.tamano_maximo()) {
    cout << "ORGANISMOS" << endl;
    exp.escribir_ultims(fills_ronda);
    cout << endl;
    cout << "RANKING" << endl;
    R.escribir_ranking();
  }
}
