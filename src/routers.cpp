#include "../include/routers.h"

void avions_router(Avion **avions, int &nbr_avions)
{
    char input;
    do
    {
        cout << "Options avion: " << endl;
        cout << "a: pour ajouter" << endl;
        cout << "s: pour chercher" << endl;
        cout << "d: pour afficher les détails" << endl;
        cout << "q: pour quitter" << endl;
        cin >> input;
        switch (input)
        {
        case 'a':
        {
           Avion *a = new Avion();
           cout << "Veuillez saisir les infos de l'avion: "<<endl;
           a->fill();
           if(!add(avions, nbr_avions, a)){
            cout << "Avion existe déja !"<<endl;
           }
           break;
        }        
        default:
            cout << "Commande non reconnue"<<endl;
            break;
        }
    } while (input != 'q');
}
void passagers_router();
void vols_router();