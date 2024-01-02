#ifndef APP_H
#define APP_H
#include <iostream>
#include "../include/passager.h"
#include "../include/avion.h"
#include "../include/vol.h"
#include "../include/gestion_vols.h"
#include "../include/gestion_avions.h"
#include "../include/gestion_passagers.h"
#include "../include/validator.h"
#include "../include/routers.h"

using namespace std;

class App
{
private:
    int nbr_passagers;
    Passager **passagers;
    int nbr_avions;
    Avion **avions;
    int nbr_vols;
    Vol **vols;

public:
    App();
    void run();
    bool router();
    int friend find(Avion **, int &, string);
    bool friend add(Avion **, int &, Avion *);
    bool friend if_exist(Avion **, int &, Avion *);

    bool friend if_exist(Passager **, int &, Passager *);
    bool friend add(Passager **, int &, Passager *);
    int friend find(Passager **, int &, int);

    void friend avions_router();
    void friend passagers_router();
    void friend vols_router();
};

#endif
