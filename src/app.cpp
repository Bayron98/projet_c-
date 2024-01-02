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
        else{
            vols_router();
            break;
        }
    case '2':
        avions_router(avions, nbr_avions);
        break;
    case '3':
        passagers_router();
        break;
        // case 'a':{
        //    Avion *a = new Avion();
        //    cout << "Veuillez saisir les infos de l'avion: "<<endl;
        //    a->fill();
        //    if(!add(avions, nbr_avions, a)){
        //     cout << "Avion existe déja !"<<endl;
        //    }
        //    return true;
        // }
        // case 'p':{
        //    Passager *p = new Passager();
        //    cout << "Veuillez saisir les infos du passager: "<<endl;
        //    p->fill();
        //    if(!add(passagers, nbr_passagers, p)){
        //     cout << "Passager existe déja !"<<endl;
        //    }
        //    return true;
        // }
        // case 'd':{
        //     cout << "Voici la liste des vols disponibles: "<<endl;
        //     details(vols,nbr_vols);
        //     return true;
        // }
        // case 'v':{
        //    if(nbr_passagers == 0 && nbr_avions == 0){
        //       cout << "Nombre insuffisant de passagers et d'avions pour créer un vol"<<endl;
        //       break;
        //    }else{
        //     Vol *v = new Vol();
        //     v->fill();
        //     cout << "Ajoutez l'avion souhaitez: "<<endl;
        //     cout << " Voici la liste des avions disponibles: "<<endl;
        //     details(avions, nbr_avions);
        //     string code;
        //     cin >> code;
        //     int index = find(avions, nbr_avions, code);
        //     while (index == -1){
        //         cout << "Aucune avion ne correspond au code entré"<<endl;
        //         cin >> code;
        //         index = find(avions, nbr_avions, code);
        //     }
        //     v->avion(avions[index]);
        //     cout << "Ajoutez les passagers: (Cliquez sur 'q' pour arretez la saisie)"<<endl;
        //     cout << "Voici la liste des passagers disponibles: "<<endl;
        //     details(passagers, nbr_passagers);
        //     string input;
        //     while(true){
        //         cin >> input;
        //         if(input == "q"){
        //             break;
        //         }else{
        //             index = find(passagers, nbr_passagers, stoi(input));
        //             if(index == -1){
        //             cout << "Aucun passager ne correspond au identifiant entré"<<endl;
        //             }else if(!v->add(passagers[index])){
        //                 cout << "Ajout échoué"<<endl;
        //             }
        //         }
        //     }
        //     if(!add(vols, nbr_vols, v)){
        //        cout << "Vol existe déja !"<<endl;
        //     }
        // }
        //  return true;
        // }
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
