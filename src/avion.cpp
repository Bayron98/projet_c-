#include "../include/avion.h"


Avion::Avion(){}

// saisi
void Avion::fill(){
    cout << "Entrez le code: "; cin >>_code;
    cout << "Entrez le nom du pilote: "; cin >>_nom_pilote;
    cout << "Entrez le modèle: "; cin >>_modele;
    cout << "Entrez la capacité: "; cin >>_capacite;
    cout << "Entrez la date de fabrication (YYYY-MM-DD): ";
    string date;
    while(true){
        cin >> date;
        if (!check_date(date)){cout << "Date invalide"<<endl;continue;}
        _date_fabrication = from_string(date);
        break;
    }

    cout << "Entrez le nombre de vols assurés: "; cin >>_nbr_vols;

}
// affichage
void Avion::details(){
    cout << "Code: "<<_code<<endl;
    cout << "Nom du pilote: "<<_nom_pilote<<endl;
    cout << "Modèle: "<<_modele<<endl;
    cout << "Capacité: "<<_capacite<<endl;
    cout << "Date de fabrication: "<<_date_fabrication<<endl;
    cout << "Le nombre de vols assurés: "<<_nbr_vols<<endl;

}

// getters
string Avion::code(){return _code;}
string Avion::nom_pilote(){return _nom_pilote;}
string Avion::modele(){return _modele;}
int Avion::capacite(){return _capacite;}
date Avion::date_fabrication(){return _date_fabrication;}
int Avion::nbr_vols(){return _nbr_vols;}

// setters
void Avion::code(string code){ _code = code;}
void Avion::nom_pilote(string nom_pilote){ _nom_pilote = nom_pilote;}
void Avion::modele(string modele){ _modele = modele;}
void Avion::capacite(int capacite){_capacite = capacite;}
void Avion::date_fabrication(date date_fabrication){ _date_fabrication = date_fabrication;}
void Avion::nbr_vols(int nbr_vols){_nbr_vols = nbr_vols;}