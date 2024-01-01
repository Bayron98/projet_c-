#ifndef GESTION_AVIONS_H
#define GESTION_AVIONS_H


#include <iostream>
#include "../include/avion.h"


using namespace std;

int find(Avion**&, int&, string);
bool add(Avion **&,int&, Avion*&);
bool if_exist(Avion **&,int&, Avion*&);
void details(Avion **&,int&);
#endif
