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

bool App::router(){
    char input;
    cin >> input;
    switch(input){
        case 'q':
           return false;
        case 'a':{
           Avion *a = new Avion();
           cout << "Veuillez saisir les infos de l'avion: "<<endl;
           a->fill();
           add(avions, nbr_avions, a);
           return true;
        }
        case 'p':{
           Passager *p = new Passager();
           cout << "Veuillez saisir les infos du passager: "<<endl;
           p->fill();
           add(passagers, nbr_passagers, p);
           return true;
        }
        case 'd':{
            cout << "Voici la liste des vols disponibles: "<<endl;
            details(vols,nbr_vols);
            return true;
        }
        case 'v':{
           if(nbr_passagers == 0 && nbr_avions == 0){
              cout << "Nombre insuffisant de passagers et d'avions pour créer un vol"<<endl;
              break;
           }else{
            Vol *v = new Vol();
            v->fill();
            cout << "Ajoutez l'avion souhaitez: "<<endl;
            cout << " Voici la liste des avions disponibles: "<<endl;
            details(avions, nbr_avions);
            string code;
            cin >> code;
            int index = find(avions, nbr_avions, code);
            while (index == -1){
                cout << "Aucune avion ne correspond au code entré"<<endl;
                cin >> code;
                index = find(avions, nbr_avions, code);
            }
            v->avion(avions[index]);
            cout << "Ajoutez les passagers: (Cliquez sur 'q' pour arretez la saisie)"<<endl;
            cout << "Voici la liste des passagers disponibles: "<<endl;
            details(passagers, nbr_passagers);
            string input;
            while(true){
                cin >> input;
                if(input == "q"){
                    break;
                }else{
                    index = find(passagers, nbr_passagers, stoi(input));
                    if(index == -1){
                    cout << "Aucun passager ne correspond au identifiant entré"<<endl;
                    }else if(!v->add(passagers[index])){
                        cout << "Ajout échoué"<<endl;
                    }
                }
            }
            add(vols, nbr_vols, v);
        }
         return true;
        }
        default:
           cout << "Commande non reconnue"<<endl;
           return true;
    }
    return true;

}

void App::run()
{
    do{
        cout << "##########################################################" << endl;
        cout << "Application de gestion de vols (pour quitter cliquez sur q)" << endl;
        cout << "##########################################################" << endl;
        cout << "##########################################################" << endl;
        cout << "Nombre de vols: " << nbr_vols;
        if (nbr_avions == 0 || nbr_passagers == 0)
        {
            cout << " (pour ajouter des vols il faut d'abord avoir des avions et des passagers disponibles)" << endl;
        }
        else
        {
            cout << " (pour ajouter cliquez sur v)| d: afficher details vols" << endl;
        }
        cout << "Nombre d'avions: " << nbr_avions
             << " (pour ajouter cliquez sur a)" << endl;
        cout << "Nombre de passagers: " << nbr_passagers
             << " (pour ajouter cliquez sur p)" << endl;
        cout << "##########################################################" << endl;
        cout << "##########################################################" << endl;
    }while(router());
}







