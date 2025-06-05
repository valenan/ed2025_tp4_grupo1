#ifndef PERSONAJES_H
#define PERSONAJES_H

#include <iostream>
#include "armas.h"
using namespace std;

class personaje {
private:
    int vida;
    string nombrepj;
    bool activo;
    int veneno;
    bool vivo;
    string descripcion;

public:
    personaje(int vida, string nombrepj, bool activo, int veneno, bool vivo, string descripcion);
    void mostrar_pj();
    int atacar(arma& dano);  // Corregido: es método, no función libre
    void recibirdano(int recibido);
    void recibirveneno(bool recibido);
    void recibircuracion(int recibido);
    virtual arma& get_arma() = 0;

    int get_vida();
    string get_nombrepj();
    bool get_activo();
    int get_veneno();
    bool get_vivo();
    string get_descripcion();

    void set_vida(int vida);
    void set_nombrepj(const string& nombrepj);
    void set_activo(bool activo);
    void set_veneno(int veneno);
    void set_vivo(bool vivo);
    void set_descripcion(const string& descripcion);
};

class guerrero : public personaje {
private:
    arma& ARMA;
    int escudo;
public:
    guerrero(int vida, string nombrepj, bool activo, int veneno, bool vivo, string descripcion, int escudo, arma& ARMA);
    void recibirescudo(int recibido, int escudo);
    arma& get_arma() override;
};

class mago : public personaje {
private:
    baston BASTON;
    int proteccion;
    bool prot_si;
public:
    mago(int vida, string nombrepj, bool activo, int veneno, bool vivo, string descripcion, baston BASTON, int proteccion, bool prot_si);
    int especial(baston& BASTON, personaje& pj1, personaje& pj2);
    arma& get_arma() override;
};

class otros : public personaje {
private:
    arma& ARMA;
public:
    otros(int vida, string nombrepj, bool activo, int veneno, bool vivo, string descripcion, arma& ARMA);
    arma& get_arma() override;
};

#endif
