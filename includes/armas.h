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
    int get_dano();
    bool get_veneno();
    bool get_contundente();

};
class baston: public arma{
private:
    int especial;
    int cooldown;               
public:
baston(int especial, int cooldown,string nombre, int dano, string descripcion,bool contundente,bool veneno);
/*los bastones de mago tienen habilidades especiales:
0=Confusion: Produce que el personaje atacado ataque a sus compañeros
1=Curacion: Cura tus personajes
2=Necromacia: Trae un personaje de la muerte durante el siguiente turno
todos los especiales consumen un turno
*/
void mostrar_arma();
int get_especial();
int get_cooldown();
};

#endif