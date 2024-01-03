#include "../include/routers.h"

void avions_router(Avion **&avions, int &nbr_avions)
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
            cout << "Veuillez saisir les infos de l'avion: " << endl;
            a->fill();
            if (!add(avions, nbr_avions, a))
            {
                cout << "Avion existe déja !" << endl;
            }
            break;
        }
        case 'd':
        {
            cout << "Les avions disponibles: " << endl;
            details(avions, nbr_avions);
            break;
        }
        case 's':
        {
            cout << "Entrez le code de l'avion: ";
            string code;
            cin >> code;
            int i = find(avions, nbr_avions, code);
            if (i == -1)
            {
                cout << "Avion introuvable" << endl;
            }
            else
            {
                avions[i]->details();
            }
            break;
        }
        default:
            cout << "Commande non reconnue" << endl;
            break;
        }
    } while (input != 'q');
}
void passagers_router(Passager **&passagers, int &nbr_passagers, Vol **&vols, int &nbr_vols)
{
    char input;
    do
    {
        cout << "Options passager: " << endl;
        cout << "a: pour ajouter" << endl;
        cout << "s: pour chercher" << endl;
        cout << "d: pour afficher les détails" << endl;
        cout << "v: pour afficher les vols" << endl;
        cout << "q: pour quitter" << endl;
        cin >> input;
        switch (input)
        {
        case 'a':
        {
            Passager *p = new Passager();
            cout << "Veuillez saisir les infos du passager: " << endl;
            p->fill();
            if (!add(passagers, nbr_passagers, p))
            {
                cout << "Passager existe déja !" << endl;
            }
            break;
        }
        case 'd':
        {
            cout << "Les passagers disponibles: " << endl;
            details(passagers, nbr_passagers);
            break;
        }
        case 's':
        {
            cout << "Entrez l'identifiant du passager: ";
            string code;
            cin >> code;
            int i = find(passagers, nbr_passagers, stoi(code));
            if (i == -1)
            {
                cout << "Passager introuvable" << endl;
            }
            else
            {
                passagers[i]->details();
            }
            break;
        }
        case 'v':
        {
            string code;
            cout << "Entrez l'identifiant du passager: ";
            cin >> code;
            int index = find(passagers, nbr_passagers, stoi(code));
            if (index == -1)
            {
                cout << "Passager introuvable" << endl;
            }
            else
            {
                cout << "Liste des vols du passager " << code << ": " << endl;
                int j = 0;
                for (int i = 0; i < nbr_vols; i++)
                {
                    if (vols[i]->find(passagers[index]) != -1)
                    {
                        vols[i]->details();
                        j++;
                    }
                }
                if (j == 0)
                {
                    cout << "Aucun vol" << endl;
                }
            }
            break;
        }
        default:
            cout << "Commande non reconnue" << endl;
            break;
        }
    } while (input != 'q');
}
void vols_router(Vol **&vols, int &nbr_vols, Avion **&avions, int &nbr_avions, Passager **&passagers, int &nbr_passagers)
{
    char input;
    do
    {
        cout << "Options vol: " << endl;
        cout << "1: pour ajouter" << endl;
        cout << "2: pour chercher" << endl;
        cout << "3: pour supprimer" << endl;
        cout << "4: pour modifier pilote d'un vol" << endl;
        cout << "5: pour modifier date d'un vol" << endl;
        cout << "6: pour afficher les vols de lendemain" << endl;
        cout << "7: pour afficher les passagers moins de 10 ans d'un vol" << endl;
        cout << "8: pour ajouter des passagers à un vol" << endl;
        cout << "9: pour supprimer un passager d'un vol" << endl;
        cout << "0: pour afficher les détails" << endl;
        cout << "q: pour quitter" << endl;
        cin >> input;
        switch (input)
        {
        case '1':
        {
            if (nbr_passagers == 0 && nbr_avions == 0)
            {
                cout << "Nombre insuffisant de passagers et d'avions pour créer un vol" << endl;
                break;
            }
            else
            {
                Vol *v = new Vol();
                v->fill();
                cout << "Ajoutez l'avion souhaitez: " << endl;
                cout << "Voici la liste des avions disponibles: " << endl;
                details(avions, nbr_avions);
                string code;
                int index;
                while (true)
                {
                    try
                    {
                        cin >> code;
                        index = find(avions, nbr_avions, code);
                        if (index == -1)
                        {
                            cout << "Aucune avion ne correspond au code entré" << endl;
                        }
                        else
                        {
                            v->avion(avions[index]);
                            break;
                        }
                    }
                    catch (const exception &e)
                    {
                        cout << "Commande non reconnue" << endl;
                    }
                }

                cout << "Ajoutez les passagers: (Cliquez sur 'q' pour arretez la saisie)" << endl;
                cout << "Voici la liste des passagers disponibles: " << endl;
                details(passagers, nbr_passagers);
                string input;
                while (true)
                {
                    cin >> input;
                    if (input == "q")
                    {
                        break;
                    }
                    else
                    {
                        try
                        {
                            index = find(passagers, nbr_passagers, stoi(input));
                            if (index == -1)
                            {
                                cout << "Aucun passager ne correspond au identifiant entré" << endl;
                            }
                            else if (!v->add(passagers[index]))
                            {
                                cout << "Ajout échoué" << endl;
                            }
                        }
                        catch (const exception &e)
                        {
                            cout << "Commande non reconnue" << endl;
                        }
                    }
                }
                if (!add(vols, nbr_vols, v))
                {
                    cout << "Vol existe déja !" << endl;
                }
            }
            break;
        }
        case '2':
        {
            cout << "Entrez le code du vol: ";
            string code;
            cin >> code;
            int i = find(vols, nbr_vols, stoi(code));
            if (i == -1)
            {
                cout << "Vol introuvable" << endl;
            }
            else
            {
                vols[i]->details();
            }
            break;
        }
        case '3':
        {
            cout << "Entrez le code du vol: ";
            string code;
            cin >> code;
            int i = find(vols, nbr_vols, stoi(code));
            if (i == -1)
            {
                cout << "Vol introuvable" << endl;
            }
            else
            {
                remove(vols, nbr_vols, vols[i]);
            }
            break;
        }
        case '4':
        {
            cout << "Entrez le code du vol: ";
            string code;
            cin >> code;
            int i = find(vols, nbr_vols, stoi(code));
            if (i == -1)
            {
                cout << "Vol introuvable" << endl;
            }
            else
            {
                string nom;
                cout << "Entrez nouveau nom du pilote: ";
                cin >> nom;
                vols[i]->avion()->nom_pilote(nom);
            }
            break;
        }
        case '5':
        {
            cout << "Entrez le code du vol: ";
            string code;
            cin >> code;
            int i = find(vols, nbr_vols, stoi(code));
            if (i == -1)
            {
                cout << "Vol introuvable" << endl;
            }
            else
            {
                ptime f_full_date;
                cout << "Entrez la nouvelle date de départ (YYYY-MM-DD HH:MM): ";
                string date, hour;
                cin >> date >> hour;
                string full_date = date + " " + hour;
                while (true)
                {
                    if (!check_date_time(full_date))
                    {
                        cout << "Date invalide" << endl;
                        cin >> date >> hour;
                        full_date = date + " " + hour;
                    }
                    else
                    {
                        f_full_date = time_from_string(full_date);
                        break;
                    }
                }
                ptime f_full_date2;
                cout << "Entrez la nouvelle date d'arrivée (YYYY-MM-DD HH:MM): ";
                string date2, hour2;
                cin >> date2 >> hour2;
                string full_date2 = date2 + " " + hour2;
                while (true)
                {
                    if (!check_date_time(full_date2))
                    {
                        cout << "Date invalide" << endl;
                        cin >> date2 >> hour2;
                        full_date2 = date2 + " " + hour2;
                    }
                    else
                    {
                        f_full_date2 = time_from_string(full_date2);
                        break;
                    }
                }
                if (modify_date(vols[i], f_full_date, f_full_date2))
                {
                    cout << "Modification réussie" << endl;
                }
                else
                {
                    cout << "Echec" << endl;
                }
            }
            break;
        }
        case '6':
        {
            cout << "Voici la liste des vols de lendemain: " << endl;
            tomorrow(vols, nbr_vols);
            break;
        }
        case '7':
        {
            cout << "Entrez le code du vol: ";
            string code;
            cin >> code;
            int i = find(vols, nbr_vols, stoi(code));
            if (i == -1)
            {
                cout << "Vol introuvable" << endl;
            }
            else
            {
                cout << "Voici la liste des passager moins de 10 ans dans le vol " << code << " : " << endl;
                vols[i]->show_less10();
            }
            break;
        }
        case '8':
        {
            cout << "Entrez le code du vol: ";
            string code;
            cin >> code;
            int i = find(vols, nbr_vols, stoi(code));
            if (i == -1)
            {
                cout << "Vol introuvable" << endl;
            }
            else
            {
                int index;
                cout << "Ajoutez les passagers: (Cliquez sur 'q' pour arretez la saisie)" << endl;
                cout << "Voici la liste des passagers disponibles: " << endl;
                details(passagers, nbr_passagers);
                string input;
                while (true)
                {
                    cin >> input;
                    if (input == "q")
                    {
                        break;
                    }
                    else
                    {
                        try
                        {
                            index = find(passagers, nbr_passagers, stoi(input));
                            if (index == -1)
                            {
                                cout << "Aucun passager ne correspond au identifiant entré" << endl;
                            }
                            else if (!vols[i]->add(passagers[index]))
                            {
                                cout << "Ajout échoué" << endl;
                            }
                        }
                        catch (const exception &e)
                        {
                            cout << "Commande non reconnue" << endl;
                        }
                    }
                }
            }
            break;
        }
        case '9':
        {
            cout << "Entrez le code du vol: ";
            string code;
            cin >> code;
            int i = find(vols, nbr_vols, stoi(code));
            if (i == -1)
            {
                cout << "Vol introuvable" << endl;
            }
            else
            {
                cout << "Entrez le passager à supprimer: ";
                string id;
                cin >> id;
                int j = find(passagers, nbr_passagers, stoi(id));
                if (j == -1)
                {
                    cout << "Passager introuvable" << endl;
                }
                else
                {
                    if (vols[i]->find(passagers[j]) == -1)
                    {
                        cout << "Passager introuvable dans le vol" << endl;
                    }
                    else
                    {
                        vols[i]->remove(passagers[j]);
                        cout << "Passager supprimé" << endl;
                    }
                }
                break;
            }
            break;
        }

        case '0':
        {
            cout << "Voici la liste des vols disponibles: " << endl;
            details(vols, nbr_vols);
            break;
        }
        default:
            cout << "Commande non reconnue" << endl;
            break;
        }
    } while (input != 'q');
}