#include "ctrain_handler.h"
#include "locomotive.h"

#include <QList>

//Creation d'une locomotive
static Locomotive loco1;
static Locomotive loco2;
//Arret d'urgence
void emergency_stop()
{
    loco1.arreter();
    loco2.arreter();
    afficher_message("\nSTOP!");
}

//Fonction principale
int cmain()
{
    afficher_message("Hit play to start the simulation...");

    //Choix de la maquette
    selection_maquette(MAQUETTE_A);

    //Initialisation d'un parcours
    QList<int> parcours;
    parcours << 7 << 15 << 14 << 7 << 6 << 5 << 34 << 33 << 32 << 25 << 24;

    //Initialisation des aiguillages
    diriger_aiguillage(8,  DEVIE,       0);
    diriger_aiguillage(2,  DEVIE,       0);
    diriger_aiguillage(20, DEVIE,       0);
    diriger_aiguillage(14, DEVIE,       0);
    diriger_aiguillage(11, TOUT_DROIT,  0);
    diriger_aiguillage(17, TOUT_DROIT,  0);
    diriger_aiguillage(23, TOUT_DROIT,  0);

    //Initialisation de la locomotive
    loco1.fixerNumero(1);
    loco1.fixerVitesse(12);
    loco1.fixerPosition(16, 23);
    loco1.allumerPhares();
    loco1.demarrer();
    loco1.afficherMessage("Ready!");

    loco2.fixerNumero(2);
    loco2.fixerVitesse(20);
    loco2.fixerPosition(1, 2);
    loco2.allumerPhares();
    loco2.demarrer();
    loco2.afficherMessage("Ready!");

    for(int k = 0; k < 2; ++k){
        //Attente du passage sur les contacts
        for (int i = 1; i < parcours.size(); i++) {
            attendre_contact(parcours.at(i));
            afficher_message(qPrintable(QString("The engine no. %1 has reached contact no. %2.")
                                        .arg(loco1.numero()).arg(parcours.at(i))));
            loco1.afficherMessage(QString("I've reached contact no. %1.").arg(parcours.at(i)));
        }
    }

    //Arreter la locomotive
    loco1.arreter();
    loco1.afficherMessage("Yeah, piece of cake!");

    //Fin de la simulation
    mettre_maquette_hors_service();

    //Exemple de commande
    afficher_message("Enter a command in the input field at the top of the window.");
    QString commande = getCommand();
    afficher_message(qPrintable(QString("Your command is: ") + commande));

    return EXIT_SUCCESS;
}
