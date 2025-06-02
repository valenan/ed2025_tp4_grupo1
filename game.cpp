#include <iostream>
#include "includes/armas.h"
#include "includes/personajes.h"

using namespace std;
void menu(int a);
void jcj1();
personaje& elegir_pj(guerrero caballero, otros duende, otros ogro, mago hypnos, mago medico, mago necromago);
void jcj1(personaje& pj1,personaje& pj2);

int main (){
    int a,turno=0;
    //definicion de armas
    arma espada("Espada",20,"Espada de hierro comun",false,false);
    arma mazo("Mazo",25,"Mazo de ogro, contundente y pesado",true,false);
    arma daga("Daga envenenada",10,"Daga envenenada, quita vida de manera gradual",false,true);
    baston confuso(0,0,"Baston de la confusion",20,"Ataca a sus compañeros(enemigo)",false,false);
    baston curador(1,0,"Baston de la cuarcion",20,"Cura a un personaje aliado",false,false);
    baston revivir(2,0,"Baston necromago",20,"Revive un compañero muerto",false,false);
    //definicion de personajes
    guerrero caballero(100,"Tristan el grande",true,0,true,"Un caballero noble, dispuesto a pelear",30,espada);
    otros duende(90,"Duende",true,0,true,"Duendes, seres tan bajos que no merecen nombre, poseen una daga venenosa. Cuidado!",daga);
    otros ogro(140,"Orcus el ogro",true,0,true,"Orcus, un ogro malvado con un mazo gigante",mazo);
    mago hypnos(80,"Hypnos",true,0,true,"El hipnotista: puede hipnotizar a los enemigos para que se ataquen entre si",confuso,15,true);
    mago medico(80,"Vita",true,0,true,"La curandera: cura a sus aliados",curador,15,true);
    mago necromago(80,"Mors",true,0,true,"El desterrado: Lo desterraron por sus experimentos, podia revivir muertos durante un tiempo (1 turno)",revivir,15,true);

    do{
    menu(a);
    switch (a){
        case 1:
        cout<<"Has elegido jugar 1v1"<<endl;
        cout<<"Jugador 1: ";
        personaje& pj1=elegir_pj(caballero,duende,ogro,hypnos,medico,necromago);
        cout<<"Jugador 2: ";
        personaje& pj2=elegir_pj(caballero,duende,ogro,hypnos,medico,necromago);
        jcj1(pj1,pj2);
        break;

    }

    }while(a!=0);
    return 0;}
void menu(int a){
cout<<"#####MENU#####"<<endl;
cout<<"Seleccione una accion"<<endl;
cout<<"1: Jugar 1v1"<<endl;
cout<<"2: Jugar 2v2"<<endl;
cout<<"3: Jugar 3v3"<<endl;
cout<<"4: Mostrar personajes"<<endl;
cout<<"5: Mostrar armas"<<endl;
cout<<"0: Salir"<<endl;
cin>>a;
};
personaje& elegir_pj(guerrero caballero, otros duende, otros ogro, mago hypnos, mago medico, mago necromago){
    int pj;
        cout<<"Elige un personaje: ";
        cout<<"1: Tristan el grande"<<endl;
        cout<<"2: Duende"<<endl;
        cout<<"3: Orcus el ogro"<<endl;
        cout<<"4: Hypnos el hipnotista"<<endl;
        cout<<"5: Vita la curandera"<<endl;
        cout<<"6: Mors el necromago"<<endl;
        cin>>pj;
        switch (pj){
            case 1:
                cout<<"Has elegido a Tristan el grande"<<endl;
                return caballero;
                break;
            case 2:
                cout<<"Has elegido al Duende"<<endl;
                return duende;
                break;
            case 3:
                cout<<"Has elegido a Orcus el ogro"<<endl;
                return ogro;
                break;
            case 4:
                cout<<"Has elegido a Hypnos el hipnotista"<<endl;
                return hypnos;
                break;
            case 5:
                cout<<"Has elegido a Vita la curandera"<<endl;
                return medico;
                break;
            case 6:
                cout<<"Has elegido a Mors el necromago"<<endl;
                return necromago;
                break;
            default:
                cout<<"Opcion invalida, elige de nuevo"<<endl;
        }
    
};

void jcj1(personaje& pj1, personaje& pj2){
    int turno1=0,turno2=0,dano;
    while(pj1.get_vivo()&&pj2.get_vivo()){
turno1++;
cout<<"Turno del jugador 1: "<<endl;
if(pj1.get_activo()){
    cout<<pj1.get_nombrepj()<<" es el jugador activo."<<endl;
} else {
    cout<<pj1.get_nombrepj()<<" no esta activo, turno perdido."<<endl;
    turno1--;
    continue; // Si el jugador no esta activo, se salta su turno
}
if (pj1.get_veneno()>0){
            pj1.recibirveneno(true);
            cout<<pj1.get_nombrepj()<<" ha recibido veneno, pierde 10 de vida."<<endl;
        }
        cout<<"Vida de "<<pj1.get_nombrepj()<<": "<<pj1.get_vida()<<endl;
        cout<<"Vida de "<<pj2.get_nombrepj()<<": "<<pj2.get_vida()<<endl;
        cout<<"Elige una accion: "<<endl;
        cout<<"1: Atacar"<<endl;
        cout<<"2: Usar habilidad especial"<<endl;
        int accion1;
        cin>>accion1;

        if(accion1==1){
            dano=pj1.atacar(pj2.get_arma());
            pj2.recibirdano(dano);
            if(pj1.get_arma().get_veneno()){
                pj2.recibirveneno(true);
            }
            if(!pj2.get_vivo()){
                cout<<pj2.get_nombrepj()<<" ha sido derrotado!"<<endl;
                break;
            }
        } else if (accion1 == 2) {
        if(pj1.get_arma().get_contundente()){
            cout<<"El arma es contundente, el enemigo no podra atacar en su proximo turno."<<endl;
            pj2.set_activo(false); // El enemigo no podra atacar en su proximo turno
        } else {
            cout << "Accion invalida, turno perdido." << endl;
        }



    };
};