#include "../include/gestion_avions.h"

int find(Avion **&avions, int &nbr_avions, string code)
{
    for (int i = 0; i < nbr_avions; i++)
    {
        if (avions[i]->code() == code)
        {
            return i;
        }
    }
    return -1;
}

bool add(Avion **&avions, int &nbr_avions, Avion *&avion)
{
    if (if_exist(avions, nbr_avions, avion))
    {
        return false;
    }
    else
    {
        nbr_avions++;
        if (avions == NULL)
        {
            avions = (Avion **)malloc(sizeof(Avion *));
        }
        else
        {
            avions = (Avion **)realloc(avions, nbr_avions * sizeof(Avion *));
        }
        avions[nbr_avions - 1] = avion;
        return true;
    }
}

bool if_exist(Avion **&avions, int &nbr_avions, Avion *&avion)
{
    for (int i = 0; i < nbr_avions; i++)
    {
        if (avions[i]->code() == avion->code())
        {
            return true;
        }
    }
    return false;
}

void details(Avion **&avions, int &nbr_avions)
{
    if (nbr_avions == 0)
    {
        cout << "aucun avion" << endl;
    }
    else
    {
        for (int i = 0; i < nbr_avions; i++)
        {
            cout << "##########################################################" << endl;
            cout << "Avion " << i + 1 << ": " << endl;
            avions[i]->details();
            cout << "##########################################################" << endl;
        }
    }
}