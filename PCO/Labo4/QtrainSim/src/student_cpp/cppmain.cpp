/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_4
 Fichier     : cppmain.cpp
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 05.05.2106

 But         : Ce programme a pour but de faire rouler 2 trains avec un troncon commun
               La maquette choisie est la A et le troncon commun est défini par les capteurs
               5-34.

               Pour ce fait, nous avons créer 2 threads, 1 pour le train pouvant s'arrêter,
               un autre pour celui avec un chemin secondaire.

               Pour gérer l'inertie, nous avons décidé de faire le check si le troncon
               est occupé 2 capteurs avant, de telle sorte que les trains aient le
               temps de freiner.

 ----------------------------------------------------------------------------------
 */

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

// Inverse une liste
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

// La loco qui peut s'arrêter
class StopableLoco : public QThread{
private:
    Locomotive _loco;
    QList<NoCapteur> _parcours;
    ChangementsAiguillage _aiguillage = {
                {{14,  5}, {3,  DEVIE}},
                {{5,  14}, {3,  DEVIE}},
                {{34, 25}, {20, DEVIE}},
                {{25, 34}, {20, DEVIE}}
    };
public:

    StopableLoco(){
        _parcours << 23 << 16 << 14 << 5 << 34 << 25 << 23;
        _loco.fixerNumero(1);
        _loco.fixerVitesse(8);
        _loco.fixerPosition(16, 23);
        _loco.allumerPhares();
        _loco.afficherMessage("Ready!");
    }

    void stop() {
        _loco.arreter();
    }

    void run() {
        _loco.demarrer();
        int nbTour = 0;
        while(true){
            // Fait les 2 tours
            for(int tour = 1; tour <= 2; ++tour){
                 _loco.afficherMessage(QString("Tour %1").arg(++nbTour));
                 //Attente du passage de la locomotive sur chacun des contacts du parcours
                for (NoCapteur cpt = 1; cpt < _parcours.length(); cpt++) {
                    NoCapteur current = _parcours[cpt];
                    NoCapteur next = _parcours[cpt + 1 < _parcours.length() ? cpt + 1 : 0];

                    attendre_contact(current);
                    _loco.afficherMessage(QString("J'ai atteint le contact %1").arg(current));

                    // Essaie de rentrer ou de sortir de la partie en commun
                    if(current == 14 || current == 25){
                        if((current == 14 && next == 5) || (current == 25 && next == 34)){ // Essaie de rentrer
                            mutex.acquire();
                            if(isOccuped) {
                                _loco.arreter();
                                mutex.release();
                                _loco.afficherMessage("Je dois attendre ...");
                                troncon.acquire(); // Attente pour redémarrer
                                mutex.acquire();
                                isOccuped = true;
                                _loco.afficherMessage("Et c'est reparti !");
                                _loco.demarrer();
                            } else {
                                troncon.acquire();
                                isOccuped = true;
                            }
                            mutex.release();
                        } else { // Sortie
                            mutex.acquire();
                            _loco.afficherMessage("Je suis sorti !");
                            isOccuped = false;
                            troncon.release();
                            mutex.release();
                        }
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

// La loco qui ne peut pas s'arrêter
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

    UnstopableLoco(){
        _principal << 20 << 12 << 10 << 5 << 34 << 28 << 20;
        _secondaire << 10 << 2 << 30 << 28;

        _loco.fixerNumero(14);
        _loco.fixerVitesse(12);
        _loco.fixerPosition(13, 19);
        _loco.allumerPhares();
        _loco.afficherMessage("Ready!");
    }

    void stop() {
        _loco.arreter();
    }

    void run() {
        _loco.demarrer();
        int nbTour = 0;
        while(true){
            // Fait les 2 tours
            for(int tour = 1; tour <= 2; ++tour){
                 _loco.afficherMessage(QString("Tour %1").arg(++nbTour));
                 //Attente du passage de la locomotive sur chacun des contacts du parcours
                for (NoCapteur cpt = 1; cpt < _principal.length(); cpt++) {
                    NoCapteur current = _principal[cpt];
                    NoCapteur next = _principal[cpt + 1 < _principal.length() ? cpt + 1 : 0];

                    attendre_contact(current);
                    _loco.afficherMessage(QString("J'ai atteint le contact %1").arg(current));

                    // Essaie de rentrer ou de sortir de la partie en commun
                    if(current == 10 || current == 28){
                        mutex.acquire();
                        if((current == 10 && next == 5) || (current == 28 && next == 34)){ // Essaie d'entrer
                            if(isOccuped){  // On passe par l'autre voie
                                mutex.release();
                                _loco.afficherMessage("Deja occupe :( je prends la secondaire");
                                for(NoCapteur cptAux = 1; cptAux < _secondaire.length(); ++cpt, ++cptAux){
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
                            isOccuped = false;
                            mutex.release();
                            troncon.release();
                        }
                    }

                    // Changement d'aiguillage si nécessaire
                    changement(current, next, _aiguillage);
                }
            }
            inverse(_principal);
            inverse(_secondaire);
            _loco.inverserSens();
        }
    }
};

// Utilisé pour l'emergency_stop
static StopableLoco* stopable;
static UnstopableLoco* unstopable;

//Arret d'urgence
void emergency_stop()
{
    // On arrête brutalement les 2 loco.
    stopable->stop();
    stopable->terminate();

    unstopable->stop();
    unstopable->terminate();

    afficher_message("\nSTOP!");
}

//Fonction principale
int cmain()
{
    afficher_message("Hit play to start the simulation...");

    //Choix de la maquette
    selection_maquette(MAQUETTE_A);

    // A décommenter sur maquette réelle
    //init_maquette();

    //Initialisation des aiguillages
    diriger_aiguillage(1,  TOUT_DROIT,  0);
    diriger_aiguillage(2,  DEVIE,       0);
    diriger_aiguillage(5,  TOUT_DROIT,  0);
    diriger_aiguillage(7,  TOUT_DROIT,  0);
    diriger_aiguillage(8,  DEVIE,       0);
    diriger_aiguillage(9,  DEVIE,       0);
    diriger_aiguillage(10, TOUT_DROIT,  0);
    diriger_aiguillage(11, TOUT_DROIT,  0);
    diriger_aiguillage(13, TOUT_DROIT,  0);
    diriger_aiguillage(14, DEVIE,       0);
    diriger_aiguillage(15, DEVIE,       0);
    diriger_aiguillage(16, TOUT_DROIT,  0);
    diriger_aiguillage(17, TOUT_DROIT,  0);
    diriger_aiguillage(19, TOUT_DROIT,  0);
    diriger_aiguillage(22, TOUT_DROIT,  0);
    diriger_aiguillage(23, TOUT_DROIT,  0);

    StopableLoco stopableLoco;
    UnstopableLoco unstopableLoco;

    stopable = &stopableLoco;
    unstopable = &unstopableLoco;

    // Démarre les loco
    stopableLoco.start();
    unstopableLoco.start();

    // Attends que les locos finissent
    stopableLoco.wait();
    unstopableLoco.wait();

    //Fin de la simulation
    afficher_message("Finis !");
    mettre_maquette_hors_service();

    return EXIT_SUCCESS;
}
