#ifndef PASSAGER_H
#define PASSAGER_H

#include <iostream>

using namespace std;

class Passager
{
private:
    int _identifiant;
    string _nom;
    string _prenom;
    int _age;
    int _telephone;
    string _adresse;

public:
    Passager();

    // saisie
    void fill();

    // affichage
    void details();

    // getters
    int identifiant();
    string nom();
    string prenom();
    int age();
    int telephone();
    string adresse();

    // setters
    void identifiant(int);
    void nom(string);
    void prenom(string);
    void age(int);
    void telephone(int);
    void adresse(string);

    // comparer
    bool comparer(Passager *);
};

#endif