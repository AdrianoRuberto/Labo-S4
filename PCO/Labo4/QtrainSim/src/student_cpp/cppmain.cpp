#include "ctrain_handler.h"
#include "locomotive.h"

#include <QList>
#include <QThread>

typedef int SensAiguillage;
typedef int NoAiguillage;
typedef int NoCapteur;
typedef std::map<std::pair<NoCapteur, NoCapteur>,std::pair<NoAiguillage, SensAiguillage> > ChangementsAiguillage;

void inverse(QList<int>& list){
    for(int k = 0; k < (list.size()/2); k++)
        list.swap(k,list.size()-(1+k));
}

class StopableLoco : public QThread{
private:
    Locomotive _loco;
    QList<NoCapteur> _parcours;
    ChangementsAiguillage _aiguillage; // Les changements à appliquer pour 1 passage
public:

    StopableLoco(Locomotive& loco, QList<NoCapteur>& parcours, ChangementsAiguillage& aiguillage)
        : _loco(loco), _parcours(parcours), _aiguillage(aiguillage){

    }

    void run() {
        while(true){
            //Attente du passage de la locomotive sur chacun des contacts du parcours
            for(int tour = 1; tour <= 2; ++tour){
                 _loco.afficherMessage(QString("Tour %1").arg(tour));
                for (int cpt = 1; cpt < _parcours.length(); cpt++) {
                    attendre_contact(_parcours[cpt]);
                    _loco.afficherMessage(QString("J'ai atteint le contact %1").arg(_parcours[cpt]));
                }
            }
            inverse(_parcours);
            _loco.inverserSens();
        }
    }
};

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
    QList<int> parcoursRose;
    parcoursRose << 23 << 16 << 14 << 5 << 34 << 32 << 23;
    QList<int> parcoursJaunePrincipal;
    parcoursJaunePrincipal << 20 << 12 << 10 << 6 << 5 << 34 << 33 << 28 << 20;

    //Initialisation des aiguillages
    diriger_aiguillage(8,  DEVIE,       0);
    diriger_aiguillage(2,  DEVIE,       0);
    diriger_aiguillage(20, DEVIE,       0);
    diriger_aiguillage(14, DEVIE,       0);
    diriger_aiguillage(11, TOUT_DROIT,  0);
    diriger_aiguillage(17, TOUT_DROIT,  0);
    diriger_aiguillage(23, TOUT_DROIT,  0);

    //Initialisation de la locomotive rose
    rose.fixerNumero(1);
    rose.fixerVitesse(8);
    rose.fixerPosition(16, 23);
    rose.allumerPhares();
    rose.demarrer();
    rose.afficherMessage("Ready!");

    ChangementsAiguillage roseChangement = {
                {{4,6}, {5,TOUT_DROIT}}
        // TODO complete
    };

    StopableLoco stopableLoco(rose, parcoursRose, roseChangement);

    stopableLoco.start();

    //Initialisation de la locomotive jaune
    jaune.fixerNumero(2);
    jaune.fixerVitesse(0);
    jaune.fixerPosition(13, 19);
    jaune.allumerPhares();
    jaune.demarrer();
    jaune.afficherMessage("Ready!");

    stopableLoco.wait();



    /*
    //Arreter la locomotive
    loco1.arreter();
    loco1.afficherMessage("Yeah, piece of cake!");

    //Fin de la simulation
    mettre_maquette_hors_service();

    //Exemple de commande
    afficher_message("Enter a command in the input field at the top of the window.");
    QString commande = getCommand();
    afficher_message(qPrintable(QString("Your command is: ") + commande));
*/
    return EXIT_SUCCESS;
}
