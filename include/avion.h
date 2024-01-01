#include <iostream>
#include "../include/validator.h"
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace std;
using namespace boost::gregorian;

class Avion{
    private:
    string _code;
    string _nom_pilote;
    string _modele;
    int _capacite;
    date _date_fabrication;
    int _nbr_vols;
    public:
    Avion();

    // saisie
    void fill();

    // affichage
    void details();

    // getters
    string code();
    string nom_pilote();
    string modele();
    int capacite();
    date date_fabrication();
    int nbr_vols();

    // setters
    void code(string);
    void nom_pilote(string);
    void modele(string);
    void capacite(int);
    void date_fabrication(date);
    void nbr_vols(int);


};