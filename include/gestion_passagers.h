#ifndef GESTION_PASSAGERS_H
#define GESTION_PASSAGERS_H


#include <iostream>
#include "../include/passager.h"


using namespace std;

bool if_exist(Passager **&,int&, Passager*&);
bool add(Passager **&,int&, Passager*&);
int find(Passager**&, int&, int);
void details(Passager **&,int&);


#endif
