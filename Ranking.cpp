/** @file Ranking.cpp
    @brief Código de la clase Ranking
*/

#include "Ranking.hpp"

// Constructoras

Ranking::Ranking(int N, int M)
{
    rank = vector<list<pair<int,int> > >(M);
    posicions = vector<int>(M,0);
    for (int i = 0; i < N; ++i) posicions[i] = i+1;
}

void Ranking::actualizar_ranking(int a, int b, int c)
{
    posicions[c-1] = c;
    list<pair<int,int> >::iterator it = rank[a].end();
    pair<int,int> aux;
    aux.first = b+1;
    aux.second = c;
    rank[a].insert(it,aux);                             // Insertem en la posició del pare el identificador
                                                        // de la mare i del fill
    list<pair<int,int> >::iterator it2 = rank[b].end();
    pair<int,int> aux2;
    aux2.first = a+1;
    aux2.second = c;
    rank[b].insert(it2,aux2);                           // Insertem en la posició de la mare el identificador
                                                        // del pare i del fill

    for (int i = 0; i < 2; ++i) {
        int aux;
        if (i == 0) aux = a+1;                          // Cas en el que es tracte el pare (a)
        else if (i == 1) aux = b+1;                     // Cas en el que es tracte la mare (b)
        int j = 0;
        while (posicions[j] != aux) ++j;
        --j;
        while (j >= 0 and (rank[posicions[j]-1]).size() < (rank[aux-1]).size()) {
            int x = posicions[j];
            posicions[j] = aux;
            posicions[j+1] = x;
            --j;
        }
        while (j >= 0 and (rank[posicions[j]-1]).size() == (rank[aux-1]).size()) {
            if (posicions[j] > posicions[j+1]) {
                int x = posicions[j];
                posicions[j] = aux;
                posicions[j+1] = x;
                --j;
            }
            else {
                j = -1;
            }
        }
    }
}

// Escritura

void Ranking::escribir_ranking() const
{
    int i = 0;
    while (i < posicions.size() and posicions[i] != 0) {
        cout << posicions[i] << " :";
        list<pair<int,int> >::const_iterator it = rank[posicions[i]-1].begin();
        while (it != rank[posicions[i]-1].end()) {
            cout << " " << (*it).first << " " << (*it).second;
            ++it;
        }
        cout << endl;
        ++i;
    }
}
