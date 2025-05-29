#ifndef PERSONAJES_H
#define PERSONAJES_H

#include <iostream>
#include <armas.h>
using namespace std;

class personaje{
    private:
    int vida;
    string nombre;
    arma& weapon;

    public:
    personaje(int vida,string nombre,arma& weapon);
    void mostrar_pj();

};
#endif