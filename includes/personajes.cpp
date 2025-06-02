#include <iostream>
#include <armas.h>
#include<personajes.h>
using namespace std;



personaje::personaje(int vida,string nombrepj,bool activo,int veneno,bool vivo,string descripcion){
    this->vida=vida;
    this->nombrepj=nombrepj;
    this->activo=activo;
    this->veneno=veneno;
    this->vivo=vivo;
    this->descripcion=descripcion;
};
void personaje::mostrar_pj(){
cout<<"Nombre: "<<nombrepj<<endl<<"Descripcion: "<<descripcion<<endl;
};
int atacar(arma dano){
    cout<<"Atacas con "<<dano.get_dano()<<" de dano."<<endl;
    return dano.get_dano();
};
void personaje::recibirdano(int recibido){
    vida-=recibido;
    if (vida<=0){
        vida=0;
        vivo=false;
    }
};
void personaje::recibirveneno(bool recibido){
    if (recibido){
        veneno=3; //3 turnos de veneno
        cout<<"El personaje ha sido envenenado, perdera 10 de vida por turno."<<endl;
    } else {
        veneno=0; //no hay veneno
    }
};
void personaje::recibircuracion(int recibido){
    vida+=recibido;
    if (vida>100) vida=100; //maximo 100 de vida
    cout<<"El personaje ha sido curado, ahora tiene "<<vida<<" de vida."<<endl;
};
//getters
int personaje::get_vida(){ return vida; }
string personaje::get_nombrepj(){ return nombrepj; }
bool personaje::get_activo(){ return activo; }
int personaje::get_veneno(){ return veneno; }
bool personaje::get_vivo(){ return vivo; }
string personaje::get_descripcion(){ return descripcion; }
//setters
void personaje::set_vida(int vida) { this->vida = vida; }
void personaje::set_nombrepj(const string& nombrepj) { this->nombrepj = nombrepj; }
void personaje::set_activo(bool activo) { this->activo = activo; }
void personaje::set_veneno(int veneno) { this->veneno = veneno; }
void personaje::set_vivo(bool vivo) { this->vivo = vivo; }
void personaje::set_descripcion(const string& descripcion) { this->descripcion = descripcion; }
// Guerrero class
guerrero::guerrero(int vida,string nombrepj, bool activo, int veneno, bool vivo,string descripcion,int escudo,arma& ARMA)
    : personaje(vida,nombrepj,activo,veneno,vivo,descripcion), ARMA(ARMA), escudo(escudo) {
        this->escudo = escudo;
    // Constructor de guerrero
};
void guerrero::recibirescudo(int recibido,int escudo){
    if (escudo>0){
        escudo-=recibido;
        if (escudo<0) escudo=0; //no puede ser negativo
        cout<<"El escudo ha absorbido "<<recibido<<" de dano, ahora tiene "<<escudo<<" de vida."<<endl;
    } else {
        recibirdano(recibido); //si no hay escudo, recibe el dano
    }
};
arma& guerrero::get_arma() {
    return ARMA; // Retorna la arma del guerrero
};
// Mago class
mago::mago(int vida,string nombrepj,bool activo,int veneno,bool vivo,string descripcion,baston BASTON,int proteccion,bool prot_si)
    : personaje(vida,nombrepj,activo,veneno,vivo,descripcion), BASTON(BASTON), proteccion(proteccion), prot_si(prot_si) {
    this->proteccion = proteccion;
    this->prot_si = prot_si;
        // Constructor de mago
};
int mago::especial(baston& BASTON,personaje& pj1,personaje& pj2) {
    switch (BASTON.get_especial())  // Especial del baston
    {
    case 0:
        pj2.set_activo(false); // Confusion: el enemigo ataca a un compañero
        cout << pj2.get_nombrepj() << " ha sido confundido y no puede atacar este turno." << endl;
        break;
    case 1:
        pj1.recibircuracion(20); // Curacion: cura a un aliado
        cout << pj1.get_nombrepj() << " ha sido curado por " << 20 << " puntos de vida." << endl;
        break;
    case 2:
        pj2.set_vivo(true);
        pj2.set_vida(999);// vida=999 para indicar que ha sido revivido, no puede ser atacado
        cout << pj2.get_nombrepj() << " ha sido revivido por " << 1 << " turno" << endl;
        break;
    
    default:
        break;
    }
};
arma& mago::get_arma() {
    return BASTON; // Retorna el baston del mago
};
// Otros class
otros::otros(int vida,string nombrepj,bool activo,int veneno,bool vivo,string descripcion,arma& ARMA)
    : personaje(vida,nombrepj,activo,veneno,vivo,descripcion), ARMA(ARMA) {
        // Constructor de otros
};
arma& otros::get_arma() {
    return ARMA; // Retorna la arma del personaje normal
};