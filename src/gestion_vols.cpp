#include "../include/gestion_vols.h"

bool if_exist(Vol **&vols, int &nbr_vols, Vol *&vol)
{
    for (int i = 0; i < nbr_vols; i++)
    {
        if (vols[i]->code() == vol->code())
        {
            return true;
        }
    }
    return false;
}

bool add(Vol **&vols, int &nbr_vols, Vol *&vol)
{
    if (if_exist(vols, nbr_vols, vol))
    {
        return false;
    }
    else
    {
        nbr_vols++;
        if (vols == NULL)
        {
            vols = (Vol **)malloc(sizeof(Vol *));
        }
        else
        {
            vols = (Vol **)realloc(vols, nbr_vols * sizeof(Vol *));
        }
        vols[nbr_vols - 1] = vol;
        return true;
    }
}

int find(Vol **&vols, int &nbr_vols, Vol *&vol)
{
    for (int i = 0; i < nbr_vols; i++)
    {
        if (vols[i]->code() == vol->code())
        {
            return i;
        }
    }
    return -1;
}

int find(Vol **&vols, int &nbr_vols, int code)
{
    for (int i = 0; i < nbr_vols; i++)
    {
        if (vols[i]->code() == code)
        {
            return i;
        }
    }
    return -1;
}

bool remove(Vol **&vols, int &nbr_vols, Vol *&vol)
{
    if (vols == NULL || !if_exist(vols, nbr_vols, vol))
    {
        return false;
    }
    else
    {
        for (int i = find(vols, nbr_vols, vol); i < nbr_vols - 1; i++)
        {
            vols[i] = vols[i + 1];
        }
        nbr_vols--;
        vols = (Vol **)realloc(vols, nbr_vols * sizeof(Vol *));
        return true;
    }
}
void modify_pilote(Vol *&vol, string nom_pilote)
{
    vol->avion()->nom_pilote(nom_pilote);
}
void details(Vol **&vols, int &nbr_vols)
{
    if (nbr_vols == 0)
    {
        cout << "aucun vol";
    }
    else
    {
        for (int i = 0; i < nbr_vols; i++)
        {
            cout << "##########################################################" << endl;
            cout << "Vol " << i + 1 << ": " << endl;
            vols[i]->details();
            cout << "##########################################################" << endl;
        }
    }
}
bool show(Vol **&vols, int &nbr_vols, Passager *&p)
{
    int j = 0;
    for (int i = 0; i < nbr_vols; i++)
    {
        if (vols[i]->if_exist(p))
        {
            j++;
            vols[i]->details();
            cout << "##################################" << endl;
        }
    }
    if (j == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool modify_date(Vol *&vol, ptime date_depart, ptime date_arrivee)
{
    if (vol->date_depart(date_depart) && vol->date_arrivee(date_arrivee))
    {
        return true;
    }
    else
    {
        return false;
    }
}
void tomorrow(Vol **&vols, int &nbr_vols)
{
    date current;
    date tomorrow = day_clock::local_day() + days(1);
    for (int i = 0; i < nbr_vols; i++)
    {
        current = vols[i]->date_depart().date();
        if (current == tomorrow)
        {
            vols[i]->details();
            cout << "##################################" << endl;
        }
    }
}