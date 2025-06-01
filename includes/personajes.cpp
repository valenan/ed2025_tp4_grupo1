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
void personaje::atacar(arma dano,bool veneno,bool contundente){


};
