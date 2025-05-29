#include <armas.h>


using namespace std;

    arma::arma(string nombre, int dano, string descripcion,bool contundente,bool veneno){
        this->nombre=nombre;
        this->dano=dano;
        this->descripcion=descripcion;
        this->contundente=contundente;
        this->veneno=veneno;
    }
    void arma::mostrar_arma(){
    cout<<"Nombre: "<<nombre<<endl<<"Descripcion: "<<descripcion<<endl;
    if (veneno)
        cout<<"Veneno: Drena la vida del enemigo durante 3 turnos (-10 hp/turno)"<<endl;
    if (contundente)
        cout<<"Contundente: Deja inutilizable al personaje del enemigo 1 turno"<<endl;
    };

baston::baston(int especial, int cooldown,string nombre, int dano, string descripcion,bool contundente,bool veneno):arma(nombre,dano,descripcion,contundente,veneno){
    this->especial=especial;
    this->cooldown=cooldown;
};
void baston::mostrar_arma(){
    arma::mostrar_arma();
    cout<<"Especial:"<<endl;
    switch (especial){
    case 0:
    cout<<"Confusion: Provoca que el enemigo atacado ataque a un compañero suyo."<<endl<<cooldown<<endl;
    break;
    case 1:
    cout<<"Curacion: Cura uno de tus aliados."<<endl<<"Cooldown: "<<cooldown<<endl;
    break;
    case 2:
    cout<<"Necromacia: Revive un aliado en el proximo turno."<<endl<<cooldown<<endl;
    break;
};
};