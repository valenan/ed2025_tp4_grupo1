#ifndef ARMAS_H
#define ARMAS_H

#include <iostream>
using namespace std;

class arma {
private:
    string nombre;
    int dano;
    string descripcion;
    bool contundente;
    bool veneno;
public:
    arma(string nombre, int dano, string descripcion, bool contundente, bool veneno);
    void mostrar_arma();
    int get_dano();
    bool get_veneno();
    bool get_contundente();
};

class baston : public arma {
private:
    int especial;
    int cooldown;
public:
    baston(int especial, int cooldown, string nombre, int dano, string descripcion, bool contundente, bool veneno);
    /*
    0 = Confusión: el enemigo ataca a su equipo
    1 = Curación: cura a un aliado
    2 = Necromancia: revive un aliado 1 turno
    */
    void mostrar_arma();
    int get_especial();
    int get_cooldown();
};

#endif
