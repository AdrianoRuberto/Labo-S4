#include "ctrain_handler.h"
#include "locomotive.h"

#include <QList>
#include <QThread>
#include <QSemaphore>

typedef int SensAiguillage;
typedef int NoAiguillage;
typedef int NoCapteur;
typedef std::map<std::pair<NoCapteur, NoCapteur>,std::pair<NoAiguillage, SensAiguillage> > ChangementsAiguillage;

bool isOccuped = false;

QSemaphore mutex(1);
QSemaphore troncon(1);

void inverse(QList<int>& list){
    for(int k = 0; k < (list.size()/2); k++)
        list.swap(k,list.size()-(1+k));
}

// Changement d'aiguillage si nécessaire
void changement(int current, int next, ChangementsAiguillage& ca){
    mutex.acquire();
    auto it = ca.find({current, next});
    if( it != ca.end()){
        diriger_aiguillage(it->second.first, it->second.second, 0);
    }
    mutex.release();
}

// Tronçon commun 5-34
class StopableLoco : public QThread{
private:
    Locomotive _loco;
    QList<NoCapteur> _parcours;
    ChangementsAiguillage _aiguillage = {
                {{14,  5}, {3,  DEVIE}},
                {{5,  14}, {3,  DEVIE}},
                {{34, 32}, {20, DEVIE}},
                {{32, 34}, {20, DEVIE}}
    };

public:

    StopableLoco(Locomotive& loco)
        : _loco(loco){
        _parcours << 23 << 16 << 14 << 5 << 34 << 32 << 23;
    }

    void run() {
        int nbTour = 0;
        while(true){
            //Attente du passage de la locomotive sur chacun des contacts du parcours
            for(int tour = 1; tour <= 2; ++tour){
                 _loco.afficherMessage(QString("Tour %1").arg(++nbTour));
                for (int cpt = 1; cpt < _parcours.length(); cpt++) {
                    NoCapteur current = _parcours[cpt];
                    NoCapteur next = _parcours[cpt + 1 < _parcours.length() ? cpt + 1 : 0];

                    attendre_contact(current);
                    _loco.afficherMessage(QString("J'ai atteint le contact %1").arg(current));

                    // Essaie de rentrer ou de sortir de la partie en commun
                    if(current == 14 || current == 32){
                        mutex.acquire();
                        if((current == 14 && next == 5) || (current == 32 && next == 34)){ // Essaie de rentrer
                            if(isOccuped) {
                                _loco.arreter();
                                mutex.release();
                                _loco.afficherMessage("Je dois attendre ...");
                                troncon.acquire(); // Attente pour redémarrer
                                isOccuped = true;
                                _loco.afficherMessage("Et c'est reparti !");
                                _loco.demarrer();
                            } else {
                                troncon.acquire();
                                isOccuped = true;
                            }
                        } else { // Sortie
                            _loco.afficherMessage("Je suis sorti !");
                            isOccuped = false;
                            troncon.release();
                        }
                        mutex.release();
                    }


                    // Changement d'aiguillage si nécessaire
                    changement(current, next, _aiguillage);
                }
            }
            inverse(_parcours);
            _loco.inverserSens();
        }
    }
};

class UnstopableLoco : public QThread {
private:
    Locomotive _loco;
    QList<NoCapteur> _principal;
    QList<NoCapteur> _secondaire;
    ChangementsAiguillage _aiguillage = {
        {{5,  10}, {3,  TOUT_DROIT  }},
        {{10, 5},  {4,  DEVIE       }},
        {{10, 2},  {4,  TOUT_DROIT  }},
        {{34, 28}, {20, TOUT_DROIT  }},
        {{28, 34}, {19, DEVIE       }},
        {{28, 30}, {19, TOUT_DROIT  }}
    };
public:

    UnstopableLoco(Locomotive& loco)
        : _loco(loco){
        _principal << 20 << 12 << 10 << 5 << 34 << 28 << 20;
        _secondaire << 10 << 2 << 30 << 28;
    }

    void run() {
        int nbTour = 0;
        while(true){
            //Attente du passage de la locomotive sur chacun des contacts du parcours
            for(int tour = 1; tour <= 2; ++tour){
                 _loco.afficherMessage(QString("Tour %1").arg(++nbTour));
                for (int cpt = 1; cpt < _principal.length(); cpt++) {
                    NoCapteur current = _principal[cpt];
                    NoCapteur next = _principal[cpt + 1 < _principal.length() ? cpt + 1 : 0];

                    attendre_contact(current);
                    _loco.afficherMessage(QString("J'ai atteint le contact %1").arg(current));

                    // Essaie de rentrer ou de sortir de la partie en commun
                    if(current == 10 || current == 28){
                        if((current == 10 && next == 5) || (current == 28 && next == 34)){ // Essaie d'entrer
                            mutex.acquire();
                            if(isOccuped){  // On passe par l'autre voie
                                mutex.release();
                                _loco.afficherMessage("Deja occupe :( je prends la secondaire");
                                for(int cptAux = 1; cptAux < _secondaire.length(); ++cpt, ++cptAux){
                                    NoCapteur current = _secondaire[cptAux - 1];
                                    NoCapteur next = _secondaire[cptAux < _secondaire.length() ? cptAux : 0];
                                    changement(current, next, _aiguillage);
                                    attendre_contact(_secondaire[cptAux]);
                                    _loco.afficherMessage(QString("J'ai atteint le contact %1").arg(current));
                                }
                            } else { // On passe par la voie principale
                                _loco.afficherMessage("Yes ! La voie principal !");
                                troncon.acquire();
                                isOccuped = true;
                                mutex.release();
                            }
                        } else { // On sort
                            _loco.afficherMessage("Je suis sorti !");
                            mutex.acquire();
                            isOccuped = false;
                            mutex.release();
                            troncon.release();
                        }
                    }

                    changement(current, next, _aiguillage);
                }
            }
            inverse(_principal);
            inverse(_secondaire);
            _loco.inverserSens();

        }
    }
};

//Creation d'une locomotive

static Locomotive stopable;
static Locomotive unstopable;

UnstopableLoco* ul = nullptr;
StopableLoco* sl = nullptr;

//Arret d'urgence
void emergency_stop()
{
    sl->terminate();
    ul->terminate();
    stopable.arreter();
    unstopable.arreter();
    afficher_message("\nSTOP!");
}

//Fonction principale
int cmain()
{
    afficher_message("Hit play to start the simulation...");

    //Choix de la maquette
    selection_maquette(MAQUETTE_A);

    //Initialisation des aiguillages
    diriger_aiguillage(1,  TOUT_DROIT,  0);
    diriger_aiguillage(2,  DEVIE,       0);
    diriger_aiguillage(5,  TOUT_DROIT,  0);
    diriger_aiguillage(7,  TOUT_DROIT,  0);
    diriger_aiguillage(8,  DEVIE,       0);
    diriger_aiguillage(10, TOUT_DROIT,  0);
    diriger_aiguillage(11, TOUT_DROIT,  0);
    diriger_aiguillage(13, TOUT_DROIT,  0);
    diriger_aiguillage(14, DEVIE,       0);
    diriger_aiguillage(16, TOUT_DROIT,  0);
    diriger_aiguillage(19, TOUT_DROIT,  0);
    diriger_aiguillage(17, TOUT_DROIT,  0);
    diriger_aiguillage(22, TOUT_DROIT,  0);
    diriger_aiguillage(23, TOUT_DROIT,  0);

    //Initialisation de la locomotive rose
    stopable.fixerNumero(1);
    stopable.fixerVitesse(6);
    stopable.fixerPosition(16, 23);
    stopable.allumerPhares();
    stopable.demarrer();
    stopable.afficherMessage("Ready!");


    //Initialisation de la locomotive jaune
    unstopable.fixerNumero(2);
    unstopable.fixerVitesse(10);
    unstopable.fixerPosition(13, 19);
    unstopable.allumerPhares();
    unstopable.demarrer();
    unstopable.afficherMessage("Ready!");


    StopableLoco stopableLoco(stopable);
    UnstopableLoco unstopableLoco(unstopable);

    sl = &stopableLoco;
    ul = &unstopableLoco;

    stopableLoco.start();
    unstopableLoco.start();

    stopableLoco.wait();
    unstopableLoco.wait();

    //Fin de la simulation
    afficher_message("Finis !");
    mettre_maquette_hors_service();

    /*
    //Exemple de commande
    afficher_message("Enter a command in the input field at the top of the window.");
    QString commande = getCommand();
    afficher_message(qPrintable(QString("Your command is: ") + commande));
    */
    return EXIT_SUCCESS;
}
