#ifndef PERSONAJES_H
#define PERSONAJES_H

#include <iostream>
#include <armas.h>
using namespace std;

class personaje{
    private:
    int vida;
    string nombre;
    bool activo;
    int veneno;
    bool vivo;

    public:
    personaje(int vida,string nombre,bool activo,int veneno,bool vivo);
    void mostrar_pj();
    void atacar(arma dano);
    void atacarveneno(bool veneno);
    void recibirdano(int recibido);
    void recibirveneno(int recibido);
};
class guerrero: public personaje{
    /*
    Guerrero: No puede usar baston de mago, tiene un escudo,
    tiene 100 de vida.
    */
    private:
    arma& weapon;
    int escudo;//30 hp, si se rompe el guerrero no recibe daño
    public:
    guerrero(int vida,string nombre, bool activo, int veneno, bool vivo,int escudo,arma& weapon);
    void recibirescudo(int recibido,int escudo);
};
class mago: public personaje {
private:
baston magia;


};




#endif