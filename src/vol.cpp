#include "../include/vol.h"

Vol::Vol()
{
    _passagers = NULL;
    _nbr_passagers = 0;
}
Vol::Vol(int code, Avion *avion, ptime date_depart, ptime date_arrivee)
    : _code(code), _avion(avion), _nbr_passagers(0), _passagers(NULL), _date_depart(date_depart), _date_arrivee(date_arrivee)
{
}

// saisie
void Vol::fill()
{
    cout << "Entrez le code: ";
    cin >> _code;
    cout << "Entrez la date de départ (YYYY-MM-DD HH:MM): ";
    {
        string date,hour;
        cin >> date>>hour;
        string full_date = date + " " + hour;
        while (true)
        {
            if (!check_date_time(full_date))
            {
                cout << "Date invalide" << endl;
                cin >> date>>hour;
                full_date = date + " " + hour;
            }
            else
            {
                _date_depart = time_from_string(full_date);
                break;
            }
        }
    }
    cout << "Entrez la date d'arrivée (YYYY-MM-DD HH:MM): ";
    {
        string date,hour;
        cin >> date>>hour;
        string full_date = date + " " + hour;
        while (true)
        {
            if (!check_date_time(full_date))
            {
                cout << "Date invalide" << endl;
                cin >> date>>hour;
                full_date = date + " " + hour;
            }
            else
            {
                _date_arrivee = time_from_string(full_date);
                break;
            }
        }
    }
}

// affichage
void Vol::details()
{
    cout << "Code: " << _code << endl;
    cout << "Avion: " << endl;
    _avion->details();
    cout << "Date de départ: " << _date_depart << endl;
    cout << "Date d'arrivée: " << _date_arrivee << endl;
    cout << "Les passagers: " << endl;
    for (int i = 0; i < _nbr_passagers; i++)
    {
        _passagers[i]->details();
        cout <<endl;
    }
}

// getters
int Vol::code() { return _code; }
Avion *Vol::avion() { return _avion; }
int Vol::nbr_passagers() { return _nbr_passagers; }
Passager **Vol::passagers() { return _passagers; }
ptime Vol::date_depart() { return _date_depart; }
ptime Vol::date_arrivee() { return _date_arrivee; }

// setters
void Vol::code(int code) { _code = code; }
void Vol::avion(Avion *avion) { _avion = avion; }
void Vol::nbr_passagers(int nbr_passagers) { _nbr_passagers = nbr_passagers; }

bool Vol::date_depart(ptime date_depart)
{
    ptime now = second_clock::local_time();
    if (date_depart > now)
    {
        _date_depart = date_depart;
        return true;
    }
    else
    {
        return false;
    }
}
bool Vol::date_arrivee(ptime date_arrivee)
{
    ptime now = second_clock::local_time();
    if (date_arrivee > now)
    {
        _date_arrivee = date_arrivee;
        return true;
    }
    else
    {
        return false;
    }
}

// methods
bool Vol::if_exist(Passager *p)
{
    for (int i = 0; i < _nbr_passagers; i++)
    {
        if (_passagers[i]->comparer(p))
        {
            return true;
        }
    }
    return false;
}
bool Vol::add(Passager *p)
{
    if (_avion->capacite() == _nbr_passagers || if_exist(p))
    {
        return false;
    }
    else
    {
        _nbr_passagers++;
        if (_passagers == NULL)
        {
            _passagers = (Passager **)malloc(sizeof(Passager *));
        }
        else
        {
            _passagers = (Passager **)realloc(_passagers, _nbr_passagers * sizeof(Passager *));
        }
        _passagers[_nbr_passagers - 1] = p;
        return true;
    }
}
void Vol::show_less10()
{
    int j = 0;
    for (int i = 0; i < _nbr_passagers; i++)
    {
        if (_passagers[i]->age() < 10)
        {
            _passagers[i]->details();
            cout << "#######################" << endl;
            j++;
        }
    }
    if(j == 0){
        cout << "Aucun"<<endl;
    }
}

int Vol::find(Passager *p)
{
    for (int i = 0; i < _nbr_passagers; i++)
    {
        if (_passagers[i]->comparer(p))
        {
            return i;
        }
    }
    return -1;
}

bool Vol::remove(Passager *p)
{
    if (_passagers == NULL || !if_exist(p))
    {
        return false;
    }
    else
    {
        for (int i = find(p); i < _nbr_passagers - 1; i++)
        {
            _passagers[i] = _passagers[i + 1];
        }
        _nbr_passagers--;
        _passagers = (Passager **)realloc(_passagers, _nbr_passagers * sizeof(Passager *));
        return true;
    }
}