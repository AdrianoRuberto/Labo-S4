/******************************************************************************
  \file main.cpp
  \author Yann Thoma
  \date 05.05.2011

  Ce fichier propose un squelette pour l'application de gestion des vélos.
  Il est évident qu'il doit être grandement modifié pour respecter la donnée,
  mais vous y trouvez des exemples d'appels de fonctions de l'interface.
  ****************************************************************************/

#include <QApplication>
#include "bikinginterface.h"


// Pour utiliser cout, cin
#include <iostream>
using namespace std;

#define NBSITES 8
#define NBHABITANTS 10


/**
 Inteface pour l'envoi de commandes à l'interface graphique.
 Elle peut sans problème être partagée entre les différents threads.
 */
BikingInterface *gui_interface;

#include <QThread>
#include <QMutex>
#include <QWaitCondition>


class Site {
private:
    const int ID;

    int _nbBikes;
    QMutex mutex;
    QWaitCondition availableBike;
    QWaitCondition availableBorne;
public:

    const int NB_BORNES;

    Site(int id, int initBikes, int nbBornes)
        : ID(id), _nbBikes(initBikes), NB_BORNES(nbBornes){
        gui_interface->setInitBikes(id, initBikes);
    }

    /**
     * @brief getBikes getter for the number of bike
     * @return the number of bike
     */
    int getBikes(){
        return _nbBikes;
    }

    /**
     * @brief enlève un vélo du site, si aucun vélo n'est disponible, attends
     *        que quelqu'un en dépose un
     */
    void take() {
        mutex.lock();
        while(_nbBikes <= 0){
            availableBike.wait(&mutex);
        }
        --_nbBikes;
        availableBorne.wakeOne();
        gui_interface->setBikes(ID, _nbBikes);
        mutex.unlock();
    }

    /**
     * @brief rajoute un vélo sur le site, si auncune borne n'est disponnible
     *        attends qu'une borne se libère
     */
    void put(){
        mutex.lock();
        while(_nbBikes >= NB_BORNES){
            availableBorne.wait(&mutex);
        }
        ++_nbBikes;
        availableBike.wakeOne();
        gui_interface->setBikes(ID, _nbBikes);
        mutex.unlock();
    }
};

/**
  Tâche illustrant les différents appels pouvant être faits à l'interface
  graphique.
  */
class Habitant: public QThread
{
public:    
    Habitant(unsigned int id, QVector<Site*>& sites) : id(id), _sites(&sites) {
        if(id != 0)
            gui_interface->setInitPerson(0, id);
    }

void run() Q_DECL_OVERRIDE {
    const size_t MAX_BIKES = 4;
    unsigned int t = id;
    unsigned int curSite= 0;
    qsrand(t);
    size_t a = 0;

    while(1) {
        // Affichage d'un message
        gui_interface->consoleAppendText(t,"Salut");

        if (t==0) { // Déplacement de la camionnette
            Site* site = _sites->at(NBSITES);

            a = min(2, site->getBikes());
            if(a > MAX_BIKES)
                a = MAX_BIKES;

            for(size_t i = 0; i < a; ++i)
                site->take();

            gui_interface->vanTravel(NBSITES, 0, 2000);

            for(int i = 0; i < NBSITES; ++i){
                Site* site = _sites->at(i);
                int n = site->getBikes();
                int minimum = site->NB_BORNES - 2;

                if(n > minimum){
                    size_t c = std::min(n - minimum, (int) (4 - a));

                    for(size_t i = 0; i < c; ++i)
                        site->take();

                    a += c;
                } else {
                    size_t c = std::min(minimum - n, (int)a);

                    for(size_t i = 0; i < c; ++i)
                        site->put();
                    a -= c;
                }
                gui_interface->vanTravel(i, i + 1, 2000);
            }

            for(size_t i = 0; i < a; ++i) // Dépose les vélos en plus
                site->put();
        }
        else {
            _sites->at(curSite)->take();
            size_t nextSite;
            do{
                nextSite = rand() % NBSITES;
            }while(nextSite == curSite);
            // Déplacement d'un vélo
            gui_interface->travel(t,             // ID de la personne
                                  curSite,       // Site de départ
                                  nextSite,      // site d'arrivée
                                  (t+1)*1000);   // Temps en millisecondes
            curSite = nextSite;
            _sites->at(curSite)->put();
        }

        QThread::usleep(1000000);
    }
}

private:
    unsigned int id;

    QVector<Site*>* _sites;
};


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    int nbHabitants=NBHABITANTS;
    int nbSites=NBSITES;
    int nbBornes = 4;

    // Initialisation de la partie graphique de l'application
    BikingInterface::initialize(nbHabitants,nbSites);
    // Création de l'interface pour les commandes à la partie graphique
    gui_interface=new BikingInterface();

    // Création de threads
    QVector<Site*> sites;
    for(int i = 0; i <= nbSites; ++i){
        sites.push_back(new Site(i, nbBornes - 2, nbBornes));
        gui_interface->setBikes(i, nbBornes - 2);
    }


    int NBTHREADS=nbHabitants;
    Habitant* threads[NBTHREADS];
    int t;
    for(t=0; t<NBTHREADS; t++){
        cout << "Création du thread "<< t << endl;
        threads[t] = new Habitant(t, sites);
        threads[t]->start();
    }


    // Attention, il est obligatoire d'exécuter l'instruction suivante.
    // C'est elle qui permet la gestion de la boucle des évévements de
    // l'application graphique.
    return a.exec();
}


