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
        while(true){
            //Attente du passage de la locomotive sur chacun des contacts du parcours
            for(int tour = 1; tour <= 2; ++tour){
                 _loco.afficherMessage(QString("Tour %1").arg(tour));
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
                                int vitesse = _loco.vitesse();
                                _loco.fixerVitesse(0);
                                mutex.release();

                                // Attente pour redémarer
                                while(true){
                                    sleep(1);
                                    mutex.acquire();
                                    if(!isOccuped)
                                        break;
                                    mutex.release();
                                }
                                _loco.fixerVitesse(vitesse);
                            }
                            isOccuped = true;
                        } else { // Sortie
                            isOccuped = false;
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
        {{10, 5},  {4,  DEVIE       }},
        {{5,  10}, {3,  DEVIE       }},
        {{10, 2},  {4,  TOUT_DROIT  }},
        {{2,  10}, {4,  TOUT_DROIT  }},
        {{34, 28}, {20, TOUT_DROIT  }},
        {{28, 34}, {19, TOUT_DROIT  }},
    };
public:

    UnstopableLoco(Locomotive& loco)
        : _loco(loco){
        _principal << 20 << 12 << 10 << 5 << 34 << 28 << 20;
        _secondaire << 10 << 2 << 30 << 28;
    }

    void run() {
        while(true){
            //Attente du passage de la locomotive sur chacun des contacts du parcours
            for(int tour = 1; tour <= 2; ++tour){
                 _loco.afficherMessage(QString("Tour %1").arg(tour));
                for (int cpt = 1; cpt < _principal.length(); cpt++) {
                    NoCapteur current = _principal[cpt];
                    NoCapteur next = _principal[cpt + 1 < _principal.length() ? cpt + 1 : 0];

                    attendre_contact(current);
                    _loco.afficherMessage(QString("J'ai atteint le contact %1").arg(current));

                    // Essaie de rentrer ou de sortir de la partie en commun
                    if(current == 10 || current == 28){
                        if((current == 10 && next == 5) || (current == 28 && next == 34)){ // Essaie d'entrer
                            mutex.acquire();
                            if(isOccuped){
                                mutex.release();
                                // On passe par l'autre voie
                                for(int cptAux = 1; cptAux < _secondaire.length(); ++cpt, ++cptAux){
                                    NoCapteur current = _secondaire[cptAux - 1];
                                    NoCapteur next = _secondaire[cptAux < _secondaire.length() ? cptAux : 0];
                                    changement(current, next, _aiguillage);
                                    attendre_contact(_secondaire[cptAux]);
                                    _loco.afficherMessage(QString("J'ai atteint le contact %1").arg(current));

                                }
                            } else {
                                isOccuped = true;
                                mutex.release();
                            }
                        } else {
                            mutex.acquire();
                            isOccuped = false;
                            mutex.release();
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
    rose.fixerNumero(1);
    rose.fixerVitesse(8);
    rose.fixerPosition(16, 23);
    rose.allumerPhares();
    rose.demarrer();
    rose.afficherMessage("Ready!");

    StopableLoco stopableLoco(rose);
    stopableLoco.start();

    //Initialisation de la locomotive jaune
    jaune.fixerNumero(2);
    jaune.fixerVitesse(10);
    jaune.fixerPosition(13, 19);
    jaune.allumerPhares();
    jaune.demarrer();
    jaune.afficherMessage("Ready!");


    UnstopableLoco unstopableLoco(jaune);
    unstopableLoco.start();

    stopableLoco.wait();
    unstopableLoco.wait();


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
