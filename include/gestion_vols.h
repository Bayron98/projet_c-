#ifndef GESTION_VOLS_H
#define GESTION_VOLS_H


#include <iostream>
#include "../include/vol.h"

#include <boost/date_time/posix_time/posix_time.hpp>

using namespace std;
using namespace boost::posix_time;

bool if_exist(Vol **&,int&, Vol*&);
bool add(Vol **&,int&, Vol*&);
int find(Vol**&, int&, int);
int find(Vol **&, int&, Vol*&);
bool remove(Vol **&,int&, Vol*&);
void modify_pilote(Vol*&, string);
void details(Vol **&,int&);
bool show(Vol **&,int&, Passager *&);
bool modify_date(Vol *&, ptime, ptime);
void tomorrow(Vol **&,int&);

#endif
