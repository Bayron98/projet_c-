#ifndef ROUTERS_H
#define ROUTERS_H
#include <iostream>
#include "../include/passager.h"
#include "../include/avion.h"
#include "../include/vol.h"
#include "../include/gestion_vols.h"
#include "../include/gestion_avions.h"
#include "../include/gestion_passagers.h"
#include "../include/validator.h"

using namespace std;

void avions_router(Avion **&, int &);
void passagers_router(Passager **&, int &, Vol **&, int &);
void vols_router(Vol **&, int &, Avion **&, int &, Passager **&, int &);

#endif
