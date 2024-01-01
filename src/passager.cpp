#include <iostream>
#include "../include/passager.h"
using namespace std;

Passager::Passager(){

}

// saisie
void Passager::fill(){
    cout << "Entrez l'identifiant: "; cin >> _identifiant;
    cout << "Entrez le nom: "; cin >> _nom;
    cout << "Entrez le prenom: "; cin >> _prenom;
    cout << "Entrez l'age: "; cin >> _age;
    cout << "Entrez le telephone: "; cin >> _telephone;
    cout << "Entrez l'adresse: "; cin >> _adresse;
}
// affichage
void Passager::details(){
    cout << "Identifiant: "<<_identifiant<<endl;
    cout << "Nom: "<<_nom<<endl;
    cout << "Prenom: "<<_prenom<<endl;
    cout << "Age: "<<_age<<endl;
    cout << "Telephone: "<<_telephone<<endl;
    cout << "Adresse: "<<_adresse<<endl;
}

// getters
int Passager::identifiant(){return _identifiant;}
string Passager::nom(){ return _nom;}
string Passager::prenom(){ return _prenom;}
int Passager::age(){return _age;}
int Passager::telephone(){return _telephone;}
string Passager::adresse(){return _adresse;}

// setters
void Passager::identifiant(int identifiant){_identifiant = identifiant;}
void Passager::nom(string nom){_nom = nom;}
void Passager::prenom(string prenom){_prenom = prenom;}
void Passager::age(int age){_age = age;}
void Passager::telephone(int telephone){_telephone = telephone;}
void Passager::adresse(string adresse){_adresse = adresse;}

// comparer
bool Passager::comparer(Passager *passager){
    if (this->_identifiant == passager->identifiant()){
        return true;
    }else{
        return false;
    }
}