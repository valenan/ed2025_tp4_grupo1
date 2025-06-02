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
    //Constructor
    personaje(int vida,string nombrepj,bool activo,int veneno,bool vivo,string descripcion);
    //Metodos
    void mostrar_pj();
    int atacar(arma dano);
    void recibirdano(int recibido);
    void recibirveneno(bool recibido);
    void recibircuracion(int recibido);

    //getters
    int get_vida();
    string get_nombrepj();
    bool get_activo();
    int get_veneno();
    bool get_vivo();
    string get_descripcion();
    //setters
    void set_vida(int vida);
    void set_nombrepj(const string& nombrepj);
    void set_activo(bool activo);
    void set_veneno(int veneno);
    void set_vivo(bool vivo);
    void set_descripcion(const string& descripcion);
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
    guerrero(int vida,string nombrepj, bool activo, int veneno, bool vivo,string descripcion,int escudo,arma& ARMA);
    void recibirescudo(int recibido,int escudo);
};
class mago: public personaje {
private:
baston BASTON;
int proteccion; //funciona como 1 escudo, con menos vida y se puede usar solo 1 turno
bool prot_si;
public:
mago(int vida,string nombrepj,bool activo,int veneno,bool vivo,string descripcion,baston BASTON,int proteccion,bool prot_si);
int especial(baston& BASTON,personaje& pj1,personaje& pj2); 

};
class otros: public personaje{
    //Personajes "normales".
    private:
    arma& ARMA;
    public:
otros(int vida,string nombrepj,bool activo,int veneno,bool vivo,string descripcion,arma& ARMA);
};



#endif