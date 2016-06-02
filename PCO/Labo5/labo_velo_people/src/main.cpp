/******************************************************************************
  \file main.cpp
  \author Yann Thoma
  \date 05.05.2011

  Ce fichier propose un squelette pour l'application de gestion des vélos.
  Il est évident qu'il doit être grandement modifié pour respecter la donnée,
  mais vous y trouvez des exemples d'appels de fonctions de l'interface.

  \groupe Adriano Ruberto et Matthieu Villard

  Nous avons remplacé les parties nécessaires pour qu'il fonctionne comme voulu
  dans le cahier des charges.

  Nous avons en plus rajouté une classe "Site", qui représente les différents
  sites de la ville. C'est cette classe qui s'occupe des attentes passives.
  ****************************************************************************/

#include <QApplication>
#include "bikinginterface.h"


// Pour utiliser cout, cin
#include <iostream>
#include <cstdlib>
using namespace std;


/**
 Inteface pour l'envoi de commandes à l'interface graphique.
 Elle peut sans problème être partagée entre les différents threads.
 */
BikingInterface *gui_interface;

#include <QThread>
#include <QMutex>
#include <QWaitCondition>


/**
 * @brief Fait la gestion d'un site, offre les fonctions put et take qui
 * permettent respectivement de rajouter un vélo ou de prendre un vélo du site.
 *
 * Ces 2 fonctions utilisent des moniteurs pour leurs attentes.
 */
class Site {
private:
    const size_t ID;

    size_t _nbBikes;
    QMutex mutex;
    QWaitCondition availableBike;
    QWaitCondition availableBorne;
public:

    const size_t NB_BORNES;

    Site(size_t id, size_t initBikes, size_t nbBornes)
        : ID(id), _nbBikes(initBikes), NB_BORNES(nbBornes){
        gui_interface->setInitBikes(id, initBikes);
    }

    /**
     * @brief getter pour le nombre de vélo sur le site
     * @return le nombre de vélo
     */
    size_t getBikes(){
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
 * @brief La classe habitant représente les différentes personnes de
 * l'application.
 * l'id 0 est le van, le reste les personnes
 */
class Habitant: public QThread
{

private:
    /**
     * @brief Donne le prochain temps aléatoire en ms
     * @return le prochain temps, bornes : [1000, 4000[
     */
    int nextTime(){
        return 1000 + qrand() % 3000;
    }

public:    
    Habitant(unsigned int id, QVector<Site*>& sites) : id(id), _sites(&sites) {
        if(id != 0)
            gui_interface->setInitPerson(0, id);
    }

void run() Q_DECL_OVERRIDE {
    const size_t MAX_BIKES = 4;
    const size_t NBSITES = _sites->size() - 1;
    qsrand(id);
    size_t curSite= 0;
    size_t nextSite = 0;
    while(true) {
        if (id==0) { // Déplacement de la camionnette
            gui_interface->consoleAppendText(id,"Je commence ma tournée");
            Site* site = _sites->at(NBSITES);
            size_t a = min(2, (int)site->getBikes());

            // Prends le vélo pour le début de sa tournée
            for(size_t i = 0; i < a; ++i)
                site->take();

            // Déplace le van
            gui_interface->vanTravel(NBSITES, 0, nextTime());

            for(size_t i = 0; i < NBSITES; ++i){
                Site* site = _sites->at(i);
                int vi = site->getBikes();
                int minimum = site->NB_BORNES - 2;

                if(vi > minimum){
                    size_t c = std::min(vi - minimum, (int) (MAX_BIKES - a));
                    for(size_t i = 0; i < c; ++i)
                        site->take();
                    a += c;
                } else {
                    size_t c = std::min(minimum - vi, (int)a);
                    for(size_t i = 0; i < c; ++i)
                        site->put();
                    a -= c;
                }
                gui_interface->vanTravel(i, i + 1, nextTime());
            }


            gui_interface->consoleAppendText(id,"j'ai finis !");

            for(size_t i = 0; i < a; ++i) // Dépose les vélos en plus
                site->put();

            QThread::usleep(1000000); // Fait une pause
        }
        else { // Déplacement d'une personne

            gui_interface->consoleAppendText(id,"J'attends pour un vélo...");
            _sites->at(curSite)->take();
            do{
                nextSite = rand() % NBSITES;
            }while(nextSite == curSite);
            // Déplacement d'un vélo
            gui_interface->travel(id, curSite, nextSite, nextTime());
            curSite = nextSite;
            _sites->at(curSite)->put();

            QThread::usleep(nextTime() * 1000); // Fait son activitée
        }
    }
}

private:
    unsigned int id;

    QVector<Site*>* _sites;
};

/**
 * @brief La classe CMDInput est utilisé pour faire la saisie utilisateur.
 * les touches sont :
 *  p : rajoute un vélo au dépot s'il n'est pas plein
 *  t[s] : prends un vélo sur le site s'il y'en a un disponible
 *
 * exemple :
 * > p
 * >>> Put !
 * > t5
 * >>> Taken !
 *
 * Nous avons fait en sorte que la fenêtre soit bloquante en ne checkant pas
 * avant si on peut ajouter/supprimer un vélo pour montre la bonne gestion de
 * la concurence.
 *
 * C'est à dire que cette classe ce comporte comme une personne supplémentaire.
 */
class CMDInput : public QThread {
private:
    QVector<Site*>* _sites;
public:
    CMDInput( QVector<Site*>& sites) : _sites(&sites){}

    void run() Q_DECL_OVERRIDE {
        char c;
        int n;
        while(true){
            cout << "> ";
            cin >> c;
            switch(c){
            case 'p':
                _sites->at(_sites->length() - 1)->put();
                cout << "Put a bike !" << endl;
                break;
            case 't':
                cin >> n;
                if(n >= 0 && n < _sites->length() - 1){
                    _sites->at(n)->take();
                    cout << "Taken !" << endl;
                    break;
                }
            }
            cin.clear();
        }
    }
};

/**
 * @brief main l'application principal, créer les threads et les démarres.
 *
 * @param argc Le nombre d'argument, il est nécessaire d'en avoir exactement
 *             1 + 4 (1 le nom, 4 les arguments décris ci-dessous)
 * @param argv Les arguments sont :
 *             - argv[0] - Le nom
 *             - argv[1] - Le nombre de sites
 *             - argv[2] - Le nombre d'habitants
 *             - argv[3] - Le nombre de bornes
 *             - argv[4] - Le nombre de vélo
 * @return EXIT_FAILURE si argc != 5 ou si les arguments ne respectent pas
 *         l'énoncé du labo.
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Récupération des arguments en lignes de commande
    if(argc != 5)
        return EXIT_FAILURE;

    int nbSites= atoi(argv[1]);
    int nbHabitants = atoi(argv[2]);
    int nbBornes = atoi(argv[3]);
    int nbBikes = atoi(argv[4]);

    if(nbSites < 2 || nbBornes < 4 || nbBikes < nbSites *(nbBornes - 2) + 3)
        return EXIT_FAILURE;

    // Initialisation de la partie graphique de l'application
    BikingInterface::initialize(nbHabitants,nbSites);
    // Création de l'interface pour les commandes à la partie graphique
    gui_interface=new BikingInterface();

    // Création de threads
    QVector<Site*> sites;
    for(int i = 0; i <= nbSites; ++i){
        if(i == nbSites){  // Dépot
            sites.push_back(new Site(i, nbBikes - (nbBornes - 2) * nbSites,
                                     INT_MAX));
        } else { // Site normal
            sites.push_back(new Site(i, nbBornes - 2, nbBornes));
        }
    }

    // Création de la gestion de la saisie utilisateur.
    CMDInput cmdinput(sites);
    cmdinput.start();

    // Création des habitants
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


