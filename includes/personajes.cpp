#include "personajes.h"

personaje::personaje(int vida, string nombrepj, bool activo, int veneno, bool vivo, string descripcion) {
    this->vida = vida;
    this->nombrepj = nombrepj;
    this->activo = activo;
    this->veneno = veneno;
    this->vivo = vivo;
    this->descripcion = descripcion;
}

void personaje::mostrar_pj() {
    cout << "Nombre: " << nombrepj << endl << "Descripcion: " << descripcion << endl;
}

int personaje::atacar(arma& dano) {
    cout << "Atacas con " << dano.get_dano() << " de dano." << endl;
    return dano.get_dano();
}

void personaje::recibirdano(int recibido) {
    vida -= recibido;
    if (vida <= 0) {
        vida = 0;
        vivo = false;
    }
}

void personaje::recibirveneno(bool recibido) {
    if (recibido) {
        veneno = 3;
        cout << "El personaje ha sido envenenado, perdera 10 de vida por turno." << endl;
    } else {
        veneno = 0;
    }
}

void personaje::recibircuracion(int recibido) {
    vida += recibido;
    if (vida > 100) vida = 100;
    cout << "El personaje ha sido curado, ahora tiene " << vida << " de vida." << endl;
}

int personaje::get_vida() { return vida; }
string personaje::get_nombrepj() { return nombrepj; }
bool personaje::get_activo() { return activo; }
int personaje::get_veneno() { return veneno; }
bool personaje::get_vivo() { return vivo; }
string personaje::get_descripcion() { return descripcion; }

void personaje::set_vida(int vida) { this->vida = vida; }
void personaje::set_nombrepj(const string& nombrepj) { this->nombrepj = nombrepj; }
void personaje::set_activo(bool activo) { this->activo = activo; }
void personaje::set_veneno(int veneno) { this->veneno = veneno; }
void personaje::set_vivo(bool vivo) { this->vivo = vivo; }
void personaje::set_descripcion(const string& descripcion) { this->descripcion = descripcion; }

// -----------------------------

guerrero::guerrero(int vida, string nombrepj, bool activo, int veneno, bool vivo, string descripcion, int escudo, arma& ARMA)
    : personaje(vida, nombrepj, activo, veneno, vivo, descripcion), ARMA(ARMA), escudo(escudo) {}

void guerrero::recibirescudo(int recibido, int escudo) {
    if (escudo > 0) {
        escudo -= recibido;
        if (escudo < 0) escudo = 0;
        cout << "El escudo ha absorbido " << recibido << " de dano, ahora tiene " << escudo << " de vida." << endl;
    } else {
        recibirdano(recibido);
    }
}

arma& guerrero::get_arma() {
    return ARMA;
}

// -----------------------------

mago::mago(int vida, string nombrepj, bool activo, int veneno, bool vivo, string descripcion, baston BASTON, int proteccion, bool prot_si)
    : personaje(vida, nombrepj, activo, veneno, vivo, descripcion), BASTON(BASTON), proteccion(proteccion), prot_si(prot_si) {}

int mago::especial(baston& BASTON, personaje& pj1, personaje& pj2) {
    switch (BASTON.get_especial()) {
    case 0:
        pj2.set_activo(false);
        cout << pj2.get_nombrepj() << " ha sido confundido y no puede atacar este turno." << endl;
        break;
    case 1:
        pj1.recibircuracion(20);
        cout << pj1.get_nombrepj() << " ha sido curado por " << 20 << " puntos de vida." << endl;
        break;
    case 2:
        pj2.set_vivo(true);
        pj2.set_vida(999);
        cout << pj2.get_nombrepj() << " ha sido revivido por 1 turno." << endl;
        break;
    default:
        break;
    }
    return 0;
}

arma& mago::get_arma() {
    return BASTON;
}

// -----------------------------

otros::otros(int vida, string nombrepj, bool activo, int veneno, bool vivo, string descripcion, arma& ARMA)
    : personaje(vida, nombrepj, activo, veneno, vivo, descripcion), ARMA(ARMA) {}

arma& otros::get_arma() {
    return ARMA;
}
