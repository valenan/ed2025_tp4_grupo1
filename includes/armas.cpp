#include "armas.h"

arma::arma(string nombre, int dano, string descripcion, bool contundente, bool veneno) {
    this->nombre = nombre;
    this->dano = dano;
    this->descripcion = descripcion;
    this->contundente = contundente;
    this->veneno = veneno;
}

void arma::mostrar_arma() {
    cout << "Nombre: " << nombre << "\nDano: " << dano << "\nDescripcion: " << descripcion << endl;
    cout << (contundente ? "Contundente\n" : "No contundente\n");
    cout << (veneno ? "Tiene veneno\n" : "No tiene veneno\n");
}

int arma::get_dano() { return dano; }
bool arma::get_veneno() { return veneno; }
bool arma::get_contundente() { return contundente; }

// -----------------------------

baston::baston(int especial, int cooldown, string nombre, int dano, string descripcion, bool contundente, bool veneno)
: arma(nombre, dano, descripcion, contundente, veneno) {
    this->especial = especial;
    this->cooldown = cooldown;
}

void baston::mostrar_arma() {
    arma::mostrar_arma();
    cout << "Especial: " << especial << " | Cooldown: " << cooldown << endl;
}

int baston::get_especial() { return especial; }
int baston::get_cooldown() { return cooldown; }
