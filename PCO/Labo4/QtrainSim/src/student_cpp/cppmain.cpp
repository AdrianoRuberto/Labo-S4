#include "ctrain_handler.h"
#include "locomotive.h"

#include <QList>

//Creation d'une locomotive
static Locomotive rose;
static Locomotive jaune;

//Arret d'urgence
void emergency_stop()
{
    rose.arreter();
    jaune.arreter();
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
    parcours << 23 << 23;

    //Initialisation des aiguillages
    diriger_aiguillage(1,  TOUT_DROIT,  0);
    diriger_aiguillage(5,  TOUT_DROIT,  0);
    diriger_aiguillage(7,  TOUT_DROIT,  0);
    diriger_aiguillage(10, TOUT_DROIT,  0);
    diriger_aiguillage(11, TOUT_DROIT,  0);
    diriger_aiguillage(13, TOUT_DROIT,  0);
    diriger_aiguillage(16, TOUT_DROIT,  0);
    diriger_aiguillage(17, TOUT_DROIT,  0);
    diriger_aiguillage(22, TOUT_DROIT,  0);
    diriger_aiguillage(23, TOUT_DROIT,  0);

    //Initialisation de la locomotive
    rose.fixerNumero(1);
    rose.fixerVitesse(12);
    rose.fixerPosition(16, 23);
    rose.allumerPhares();
    rose.demarrer();
    rose.afficherMessage("Ready!");

    while(true){
        //Attente du passage de la locomotive sur chacun des contacts du parcours
        for(int tour = 1; tour <= 2; ++tour){
             rose.afficherMessage(QString("Tour %1").arg(tour));
            for (int cpt = 1; cpt < parcours.length(); cpt++) {
                attendre_contact(parcours[cpt]);
                rose.afficherMessage(QString("J'ai atteint le contact %1").arg(cpt));
            }
        }
        rose.inverserSens();

    }

    //Arreter la locomotive
    rose.arreter();
    rose.afficherMessage("Yeah, piece of cake!");

    //Fin de la simulation
    mettre_maquette_hors_service();

    //Exemple de commande
    afficher_message("Enter a command in the input field at the top of the window.");
    QString commande = getCommand();
    afficher_message(qPrintable(QString("Your command is: ") + commande));

    return EXIT_SUCCESS;
}
