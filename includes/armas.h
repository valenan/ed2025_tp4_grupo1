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

    arma(string nombre, int dano, string descripcion,bool contundente,bool veneno);
    void mostrar_arma();

};
class baston: public arma{
private:
    int especial;
    int cooldown;               
public:
baston(int especial, int cooldown,string nombre, int dano, string descripcion,bool contundente,bool veneno);
void mostrar_arma();
};

#endif