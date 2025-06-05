#include <iostream>
#include "includes/armas.h"
#include "includes/personajes.h"

using namespace std;

void menu(int &a);
void jcj1(personaje &pj1, personaje &pj2);
void jcj2v2(personaje &pj1a, personaje &pj1b, personaje &pj2a, personaje &pj2b);
personaje& elegir_pj(guerrero &caballero, otros &duende, otros &ogro, mago &hypnos, mago &medico, mago &necromago);

arma espada("Espada",20,"Espada de hierro comun",false,false);
arma mazo("Mazo",25,"Mazo de ogro, contundente y pesado",true,false);
arma daga("Daga envenenada",10,"Daga envenenada, quita vida de manera gradual",false,true);
baston confuso(0,0,"Baston de la confusion",20,"Ataca a sus compañeros(enemigo)",false,false);
baston curador(1,0,"Baston de la curacion",20,"Cura a un personaje aliado",false,false);
baston revivir(2,0,"Baston necromago",20,"Revive un compañero muerto",false,false);

guerrero caballero(100,"Tristan el grande",true,0,true,"Un caballero noble, dispuesto a pelear",30,espada);
otros duende(90,"Duende",true,0,true,"Duendes, seres tan bajos que no merecen nombre, poseen una daga venenosa. Cuidado!",daga);
otros ogro(140,"Orcus el ogro",true,0,true,"Orcus, un ogro malvado con un mazo gigante",mazo);
mago hypnos(80,"Hypnos",true,0,true,"El hipnotista: puede hipnotizar a los enemigos para que se ataquen entre si",confuso,15,true);
mago medico(80,"Vita",true,0,true,"La curandera: cura a sus aliados",curador,15,true);
mago necromago(80,"Mors",true,0,true,"El desterrado: Lo desterraron por sus experimentos, podia revivir muertos durante un tiempo (1 turno)",revivir,15,true);

int main (){
    int a;
    do {
        menu(a);
        switch (a) {
            case 1:
                cout << "Has elegido jugar 1v1" << endl;
                cout << "Jugador 1: ";
                personaje &pj1 = elegir_pj(caballero, duende, ogro, hypnos, medico, necromago);
                cout << "Jugador 2: ";
                personaje &pj2 = elegir_pj(caballero, duende, ogro, hypnos, medico, necromago);
                jcj1(pj1, pj2);
                break;
            case 2:
                cout << "Has elegido jugar 2v2" << endl;
                cout << "Jugador 1 - Personaje 1: ";
                personaje &pj1a = elegir_pj(caballero, duende, ogro, hypnos, medico, necromago);
                cout << "Jugador 1 - Personaje 2: ";
                personaje &pj1b = elegir_pj(caballero, duende, ogro, hypnos, medico, necromago);
                cout << "Jugador 2 - Personaje 1: ";
                personaje &pj2a = elegir_pj(caballero, duende, ogro, hypnos, medico, necromago);
                cout << "Jugador 2 - Personaje 2: ";
                personaje &pj2b = elegir_pj(caballero, duende, ogro, hypnos, medico, necromago);
                jcj2v2(pj1a, pj1b, pj2a, pj2b);
                break;
        }
    } while (a != 0);
    return 0;
}

void menu(int &a){
    cout << "#####MENU#####"<<endl;
    cout << "Seleccione una accion"<<endl;
    cout << "1: Jugar 1v1"<<endl;
    cout << "2: Jugar 2v2"<<endl;
    cout << "0: Salir"<<endl;
    cin >> a;
}

personaje& elegir_pj(guerrero &caballero, otros &duende, otros &ogro, mago &hypnos, mago &medico, mago &necromago){
    int pj;
    cout << "Elige un personaje: ";
    cout << "1: Tristan el grande"<<endl;
    cout << "2: Duende"<<endl;
    cout << "3: Orcus el ogro"<<endl;
    cout << "4: Hypnos el hipnotista"<<endl;
    cout << "5: Vita la curandera"<<endl;
    cout << "6: Mors el necromago"<<endl;
    cin >> pj;
    switch (pj){
        case 1: cout<<"Has elegido a Tristan el grande"<<endl; return caballero;
        case 2: cout<<"Has elegido al Duende"<<endl; return duende;
        case 3: cout<<"Has elegido a Orcus el ogro"<<endl; return ogro;
        case 4: cout<<"Has elegido a Hypnos el hipnotista"<<endl; return hypnos;
        case 5: cout<<"Has elegido a Vita la curandera"<<endl; return medico;
        case 6: cout<<"Has elegido a Mors el necromago"<<endl; return necromago;
        default: cout<<"Opcion invalida, elige de nuevo"<<endl; return elegir_pj(caballero, duende, ogro, hypnos, medico, necromago);
    }
}

void jcj1(personaje& pj1, personaje& pj2){
    int turno=0;
    while(pj1.get_vivo() && pj2.get_vivo()){
        turno++;
        cout << "Turno " << turno << endl;
        cout << "Jugador 1 (" << pj1.get_nombrepj() << "):" << endl;
        pj1.aplicar_veneno();
        cout << "Vida: " << pj1.get_vida() << endl;
        cout << "1: Atacar\n2: Usar habilidad especial\n";
        int accion;
        cin >> accion;
        if(accion==1){
            pj1.atacar_a(pj2);
        } else if (accion==2 && dynamic_cast<mago*>(&pj1)) {
            mago *m = dynamic_cast<mago*>(&pj1);
            m->especial(m->get_arma(), pj1, pj2);
        }
        if(!pj2.get_vivo()) break;

        cout << "Jugador 2 (" << pj2.get_nombrepj() << "):" << endl;
        pj2.aplicar_veneno();
        cout << "Vida: " << pj2.get_vida() << endl;
        cout << "1: Atacar\n2: Usar habilidad especial\n";
        cin >> accion;
        if(accion==1){
            pj2.atacar_a(pj1);
        } else if (accion==2 && dynamic_cast<mago*>(&pj2)) {
            mago *m = dynamic_cast<mago*>(&pj2);
            m->especial(m->get_arma(), pj2, pj1);
        }
    }
    cout << (pj1.get_vivo() ? pj1.get_nombrepj() : pj2.get_nombrepj()) << " ha ganado!" << endl;
}

void jcj2v2(personaje& pj1a, personaje& pj1b, personaje& pj2a, personaje& pj2b){
    int turno=0;
    while((pj1a.get_vivo()||pj1b.get_vivo()) && (pj2a.get_vivo()||pj2b.get_vivo())){
        turno++;
        cout << "Turno " << turno << endl;
        if(pj1a.get_vivo()) {
            cout << "Jugador 1a (" << pj1a.get_nombrepj() << "):" << endl;
            pj1a.aplicar_veneno();
            cout << "1: Atacar\n2: Usar habilidad especial\n";
            int accion;
            cin >> accion;
            if(accion==1){
                cout << "1: " << pj2a.get_nombrepj() << "\n2: " << pj2b.get_nombrepj() << endl;
                int objetivo; cin >> objetivo;
                if(objetivo==1) pj1a.atacar_a(pj2a);
                else pj1a.atacar_a(pj2b);
            } else if (accion==2 && dynamic_cast<mago*>(&pj1a)) {
                mago *m = dynamic_cast<mago*>(&pj1a);
                m->especial(m->get_arma(), pj1a, pj2a);
            }
        }
        if(!(pj2a.get_vivo()||pj2b.get_vivo())) { cout<<"Equipo 1 gana!\n"; break; }
        if(!(pj1a.get_vivo()||pj1b.get_vivo())) { cout<<"Equipo 2 gana!\n"; break; }
    }
}
