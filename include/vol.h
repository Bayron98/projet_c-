#include <iostream>
#include "../include/avion.h"
#include "../include/passager.h"
#include "../include/validator.h"
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace std;
using namespace boost::posix_time;
using namespace boost::gregorian;

class Vol
{
private:
    int _code;
    Avion *_avion;
    int _nbr_passagers;
    Passager **_passagers;
    ptime _date_depart;
    ptime _date_arrivee;

public:
    Vol();
    Vol(int, Avion*, ptime, ptime);

    // saisie
    void fill();

    // affichage
    void details();

    // getters
    int code();
    Avion* avion();
    int nbr_passagers();
    Passager **passagers();
    ptime date_depart();
    ptime date_arrivee();

    // setters
    void code(int);
    void avion(Avion*);
    void nbr_passagers(int);
    bool date_depart(ptime);
    bool date_arrivee(ptime);

    //methods
    bool if_exist(Passager*);
    bool add(Passager*);
    void show_less10();
    bool remove(Passager*);
    int find(Passager*);
};