#ifndef PERSONAJES_H
#define PERSONAJES_H

#include <iostream>
#include <armas.h>
using namespace std;

class personaje{
    private:
    int vida;
    string nombrepj;
    bool activo;
    int veneno;
    bool vivo;
    string descripcion;

    public:
    personaje(int vida,string nombrepj,bool activo,int veneno,bool vivo,string descripcion);
    void mostrar_pj();
    int atacar(arma dano);
    void recibirdano(int recibido);
    void recibirveneno(int recibido);
};
class guerrero: public personaje{
    /*
    Guerrero: No puede usar baston de mago, tiene un escudo,
    tiene 100 de vida.
    */
    private:
    arma& ARMA;
    int escudo;//30 hp, si se rompe el guerrero no recibe daño
    public:
    guerrero(int vida,string nombrepj, bool activo, int veneno, bool vivo,string descripcion,int escudo,arma& weapon);
    void recibirescudo(int recibido,int escudo);
};
class mago: public personaje {
private:
baston BASTON;
int proteccion; //funciona como 1 escudo, con menos vida y se puede usar solo 1 turno
bool prot_si;
public:
mago(int vida,string nombrepj,bool activo,int veneno,bool vivo,string descripcion,baston BASTON,int proteccion,bool prot_si);
};
class otros: public personaje{
    //Personajes "normales".
    private:
    arma& ARMA;
    public:
    otros(int vida,string nombrepj,bool activo,int veneno,bool vivo,string descripcion,arma& ARMA);
};



#endif