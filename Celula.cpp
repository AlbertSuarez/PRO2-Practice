/** @file Celula.cpp
    @brief Código de la clase Celula
*/

#include "Celula.hpp"

// Constructoras

Celula::Celula(){}

Celula::Celula(int iden, bool activ)
{
    id = iden;
    activa = activ;
}

// Modificadoras

void Celula::modificar_id(int iden)
{
    id = iden;
}

void Celula::modificar_activa(bool activ)
{
    activa = activ;
}

// Consultoras;

int Celula::consultar_id() const
{
    return id;
}

bool Celula::consultar_activa() const
{
    return activa;
}

// Lectura

void Celula::leer_celula()
{
    id = readint();
    if (id != 0) activa = readbool();
}

// Escritura

void Celula::escribir_celula() const
{
    cout << id << " ";
    if (activa) cout << "1 ";
    else cout << "-1 ";
}
