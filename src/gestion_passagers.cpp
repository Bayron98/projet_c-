#include "../include/gestion_passagers.h"

int find(Passager**&passagers, int &nbr_passagers, int identifiant){
    for(int i = 0; i < nbr_passagers; i++){
        if(passagers[i]->identifiant() == identifiant){
            return i;
        }
    }
    return -1;
}

bool add(Passager **&passagers,int &nbr_passagers, Passager*&passager){
    if(if_exist(passagers, nbr_passagers, passager)){
        return false;
    }else{
        nbr_passagers++;
        if(passager == NULL){
            passagers = (Passager **)malloc(sizeof(Passager *));
        }else{
            passagers = (Passager **)realloc(passagers, nbr_passagers*sizeof(Passager *));
        }
        passagers[nbr_passagers-1] = passager;
        return true;
    }
}

bool if_exist(Passager **&passagers,int &nbr_passagers, Passager*&passager){
     for(int i = 0; i < nbr_passagers; i++){
        if(passagers[i]->identifiant() == passager->identifiant()){
            return true;
        }
    }
    return false;
}


void details(Passager **&passager,int &nbr_passager){
    for(int i = 0; i < nbr_passager; i++){
        cout << "##########################################################" << endl;
        cout << "Passager "<<i+1<<": "<<endl;
        passager[i]->details();
        cout << "##########################################################" << endl;
    }
}