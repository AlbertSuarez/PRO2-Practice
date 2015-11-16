/** @file Experiment.cpp
    @brief Código de la clase Experiment
*/

#include "Experiment.hpp"

// Constructoras

Experiment::Experiment()
{
    MAXORGANISMES = 0;
    mida = 0;
    vius = 0;
}

Experiment::Experiment(int m)
{
    MAXORGANISMES = m;
    EXP = vector<Organisme>(m);
    emparellats = vector<vector<bool> >(m,vector<bool>(m,false));
}

// Modificadoras

int Experiment::reproduccion(Ranking &R)
{
    int fills = 0;
    int final = mida;
    int i = 0;
    int j = 1;
    vector<bool> aparicions(final,false);
    while (j < final and mida != MAXORGANISMES) {
        while (i < final - 1 and (aparicions[i] or not EXP[i].esta_vivo())) ++i;
        j = i + 1;
        while (j < final and (aparicions[j] or emparellats[i][j] or not EXP[j].esta_vivo())) ++j;
        if (j < final and i < final - 1) {
            Organisme h;
            h.reproduccion(EXP[i],EXP[j]);
            aparicions[i] = true;
            aparicions[j] = true;
            emparellats[i][j] = true;
            emparellats[j][i] = true;
            if (h.esta_vivo()) {
                EXP[mida] = h;
                ++mida;
                R.actualizar_ranking(i,j,mida);
                ++fills;
                ++vius;
            }
        }
        else if (i < final - 1) {
            ++i;
            j = i + 1;
        }
    }
    return fills;
}

void Experiment::estiron(int x)
{
    if (EXP[x-1].consultar_potcreixer()) {
        EXP[x-1].estiron();
    }
}

void Experiment::recorte(int x)
{
    if (EXP[x-1].esta_vivo()) {
        EXP[x-1].recorte();
        if (not EXP[x-1].esta_vivo()) --vius;
    }
}

// Consultoras

int Experiment::tamano() const
{
    return mida;
}

int Experiment::tamano_maximo() const
{
    return MAXORGANISMES;
}

int Experiment::consultar_vius() const
{
    return vius;
}

bool Experiment::muerto() const
{
    return (vius == 0);
}

// Lectura

void Experiment::leer_experiment(int marca)
{
    int num = 0;
    for (int i = 0; i < marca; ++i) {
        ++num;
        EXP[i].leer_organisme(num);
    }
    vius = marca;
    mida = marca;
}

// Escritura

void Experiment::escribir_organisme(int x)
{    
    if (x <= mida) {
        cout << x << " : ";
        EXP[x-1].escribir_organisme();
        cout << endl;
    }
}

void Experiment::escribir_ultims(int x)
{
    for (int i = mida - x; i < mida; ++i) {
        cout << i + 1 << " : ";
        EXP[i].escribir_organisme();
        cout << endl;
    }

}
