#include "../include/app.h"

App::App()
{
    nbr_passagers = 0;
    passagers = NULL;
    nbr_avions = 0;
    avions = NULL;
    nbr_vols = 0;
    vols = NULL;
}

bool App::router()
{
    char input;
    cin >> input;
    switch (input)
    {
    case 'q':
        return false;
    case '1':
        if (nbr_passagers == 0 && nbr_avions == 0)
        {
            cout << "Action non autorisée" << endl;
            break;
        }
        else
        {
            vols_router(vols, nbr_vols, avions, nbr_avions, passagers, nbr_passagers);
            break;
        }
    case '2':
        avions_router(avions, nbr_avions);
        break;
    case '3':
        passagers_router(passagers, nbr_passagers, vols, nbr_vols);
        break;

    default:
        cout << "Commande non reconnue" << endl;
        return true;
    }
    return true;
}

void App::run()
{
    do
    {
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "##########################################################" << endl;
        cout << "Application de gestion de vols (pour quitter cliquez sur q)" << endl;
        cout << "##########################################################" << endl;
        cout << "##########################################################" << endl;
        cout << "Nombre de vols: " << nbr_vols;
        if (nbr_avions == 0 || nbr_passagers == 0)
        {
            cout << " (Indisponible) " << endl;
        }
        else
        {
            cout << " (1: afficher plus d'options) " << endl;
        }
        cout << "Nombre d'avions: " << nbr_avions
             << " (2: afficher plus d'options) " << endl;
        cout << "Nombre de passagers: " << nbr_passagers
             << " (3: afficher plus d'options) " << endl;
        cout << "##########################################################" << endl;
        cout << "##########################################################" << endl;
    } while (router());
}
