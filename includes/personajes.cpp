#include <iostream>
#include <armas.h>
#include<personajes.h>
using namespace std;



personaje::personaje(int vida,string nombre,arma& weapon): weapon(weapon){
    this->vida=vida;
    this->nombre=nombre;
};

