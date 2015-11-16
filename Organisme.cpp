/** @file Organisme.cpp
    @brief Código de la clase Organisme
*/

#include "Organisme.hpp"

// Privades

int Organisme::interseccion(Arbre<Celula>& a, Arbre<Celula>& b)
{
    if (a.es_buit() or b.es_buit()) {
        return 0;
    }
    else {
        Arbre<Celula> a1,a2,b1,b2;
        Celula c1 = a.arrel();
        Celula c2 = b.arrel();
        a.fills(a1,a2);
        b.fills(b1,b2);
        int x = interseccion(a1,b1);
        int y = interseccion(a2,b2);
        a.plantar(c1,a1,a2);
        b.plantar(c2,b1,b2);
        return x + y + 1;
    }


}

bool Organisme::compatibles(Organisme& a, Organisme& b)
{
    int mida = interseccion(a.Organ,b.Organ);
    return (mida >= int((a.consultar_tamano() + b.consultar_tamano())/4));
}

void Organisme::crece(Arbre<Celula> &a)
{
    if (not a.es_buit()) {
        Arbre<Celula> a1, a2;
        Celula c;
        c = a.arrel();
        a.fills(a1,a2);
        if (a1.es_buit() and a2.es_buit()) {
            Celula c1(c);
            Celula c2(c);
            ++maxid;
            c1.modificar_id(maxid);
            ++maxid;
            c2.modificar_id(maxid);
            tamano += 2;
            Arbre<Celula> aux1 = a1;
            Arbre<Celula> aux2 = a2;
            a1.plantar(c1,aux1,aux2);
            a2.plantar(c2,aux1,aux2);
            a.plantar(c,a1,a2);
        }
        else if (a1.es_buit()) {
            crece(a2);
            a.plantar(c,a1,a2);
        }
        else if (a2.es_buit()) {
            crece(a1);
            a.plantar(c,a1,a2);
        }
        else {
            crece(a1);
            crece(a2);
            a.plantar(c,a1,a2);
        }
    }
}

void Organisme::decrece(Arbre<Celula> &a, bool& canviamax)
{
    if (not a.es_buit()) {
        Arbre<Celula> a1, a2;
        Celula c = a.arrel();
        a.fills(a1,a2);
        if (a1.es_buit() and a2.es_buit()) {
            --tamano;
            if (c.consultar_id() == maxid) canviamax = true;
        }
        else {
            if (a1.es_buit()) {
            decrece(a2,canviamax);
            a.plantar(c,a1,a2);
            }
            else if (a2.es_buit()) {
            decrece(a1,canviamax);
            a.plantar(c,a1,a2);
            }
            else {
            decrece(a1,canviamax);
            decrece(a2,canviamax);
            a.plantar(c,a1,a2);
            }
        }
    }
}

void Organisme::i_leer_organisme(Arbre<Celula>& a, int marca)
{
    Arbre<Celula> a1, a2;
    Celula c;
    c.leer_celula();
    if (c.consultar_id() != marca) {
        ++tamano;
        if (c.consultar_id() > maxid) maxid = c.consultar_id();
        i_leer_organisme(a1,marca);
        i_leer_organisme(a2,marca);
        a.plantar(c,a1,a2);
    }
}

void Organisme::i_escribir_organisme(Arbre<Celula>& a)
{
    if (a.es_buit()) {
        cout << "0 ";
    }
    else {
        Arbre<Celula> a1, a2;
        Celula c = a.arrel();
        a.fills(a1,a2);
        i_escribir_organisme(a1);
        c.escribir_celula();
        i_escribir_organisme(a2);
        a.plantar(c,a1,a2);
    }
}

bool Organisme::te_activa(Arbre<Celula>& a)
{
    if (a.es_buit()) return false;
    else {
        Celula c = a.arrel();
        if (c.consultar_activa()) return true;
        else {
            Arbre<Celula> a1, a2;
            a.fills(a1,a2);
            bool trobat = (te_activa(a1) or te_activa(a2));
            a.plantar(c,a1,a2);
            return trobat;
        }
    }

}

void Organisme::i_reproduccion(Arbre<Celula> &m, Arbre<Celula> &n, Arbre<Celula> &h, int& maximid, int& tamanofill, bool& casoraro)
{
    if (not m.es_buit() and not n.es_buit()) {
        Arbre<Celula> m1,m2,n1,n2,h1,h2;
        Celula c1 = m.arrel();
        Celula c2 = n.arrel();
        Celula aux(c1);
        if (not c1.consultar_activa() and not c2.consultar_activa()) {
            h.plantar(aux,m1,m2);
            ++tamanofill;
        }
        else {
            aux.modificar_activa(true);
            h.plantar(aux,m1,m2);
            ++tamanofill;
        }
        m.fills(m1,m2);
        n.fills(n1,n2);
        h.fills(h1,h2);
        i_reproduccion(m1,n1,h1,maximid,tamanofill,casoraro);
        i_reproduccion(m2,n2,h2,maximid,tamanofill,casoraro);
        m.plantar(c1,m1,m2);
        n.plantar(c2,n1,n2);
        h.plantar(aux,h1,h2);
    }
    else if (not m.es_buit() and n.es_buit()) {
        if (te_activa(m)) {
            Arbre<Celula> m1,m2,h1,h2;
            Celula c1 = m.arrel();
            h.plantar(c1,m1,m2);
            ++tamanofill;
            m.fills(m1,m2);
            h.fills(h1,h2);
            i_reproduccion(m1,n,h1,maximid,tamanofill,casoraro);
            i_reproduccion(m2,n,h2,maximid,tamanofill,casoraro);
            m.plantar(c1,m1,m2);
            h.plantar(c1,h1,h2);
        }
    }
    else if (m.es_buit() and not n.es_buit()) {
        if (te_activa(n)) {
            casoraro = true;
            Arbre<Celula> n1,n2,h1,h2;
            Celula c1 = n.arrel();
            Celula aux(c1);
            ++maximid;
            aux.modificar_id(maximid);
            h.plantar(aux,n1,n2);
            ++tamanofill;
            n.fills(n1,n2);
            h.fills(h1,h2);
            i_reproduccion(m,n1,h1,maximid,tamanofill,casoraro);
            i_reproduccion(m,n2,h2,maximid,tamanofill,casoraro);
            n.plantar(c1,n1,n2);
            h.plantar(aux,h1,h2);
        }
    }
}

void Organisme::buscar_maxid(Arbre<Celula>& a, int& max)
{
    if (not a.es_buit()) {
        Arbre<Celula> a1,a2;
        Celula c = a.arrel();
        a.fills(a1,a2);
        if (c.consultar_id() > max) max = c.consultar_id();
        if (not a1.es_buit() and a2.es_buit()) {
            buscar_maxid(a1,max);
            a.plantar(c,a1,a2);
        }
        else if (a1.es_buit() and not a2.es_buit()) {
            buscar_maxid(a2,max);
            a.plantar(c,a1,a2);
        }
        else if (not a1.es_buit() and not a2.es_buit()) {
            int max2 = 0;
            buscar_maxid(a1,max);
            buscar_maxid(a2,max2);
            if (max2 > max) max = max2;
            a.plantar(c,a1,a2);
        }
        else a.plantar(c,a1,a2);
    }
}

// Constructoras

Organisme::Organisme()
{
    tamano = 0;
    id = 0;
    maxid = 0;
    potcreixer = true;
}

Organisme::Organisme(const Organisme& o)
{
    Organ = o.Organ;
    potcreixer = o.potcreixer;
    id = o.id;
    maxid = o.maxid;
}

// Modificadoras

void Organisme::estiron()
{
    crece(Organ);
}

void Organisme::recorte()
{
    bool canviamax = false;
    decrece(Organ,canviamax);
    potcreixer = false;
    if (canviamax) {
        int max = 0;
        buscar_maxid(Organ,max);
        maxid = max;
    }
}

void Organisme::reproduccion(Organisme &m, Organisme &n)
{
    if ((m.esta_vivo() and n.esta_vivo()) and compatibles(m,n)) {
        bool casoraro = false;
        int maximid = m.consultar_maxid();
        i_reproduccion(m.Organ,n.Organ,Organ,maximid,tamano,casoraro);
        if (not casoraro) {
            maximid = 0;
            buscar_maxid(Organ,maximid);
        }
        maxid = maximid;
    }
}

// Consultoras

bool Organisme::esta_vivo() const
{
    if (Organ.es_buit()) return false;
    else return true;
}

int Organisme::consultar_tamano() const
{
    return tamano;
}

int Organisme::consultar_id() const
{
    return id;
}

int Organisme::consultar_maxid() const
{
    return maxid;
}

bool Organisme::consultar_potcreixer() const
{
    return potcreixer;
}

// Lectura

void Organisme::leer_organisme(int& num)
{
    id = num;
    tamano = 0;
    maxid = 0;
    potcreixer = true;
    i_leer_organisme(Organ,0);
}

// Escritura

void Organisme::escribir_organisme()
{
    i_escribir_organisme(Organ);
}
