/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_3
 Fichier     : bmmanager.cpp
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 07.04.2106

 But         : Ce programme a pour but d'implémenter un bandit manchot semblable aux
               machines que l'on peut trouver dans un casino

 Remarque    : Pour le calcul de la valeur du rouleau, nous avons utilisé une simple
               incrémentation cyclique. De ce fait, si le joueur attend la fin du délai,
               le jeu se bloque et le joueur a de fortes chances de gagner. Nous avons
               utilisé cette méthode car c'est celle qui selon nous se rapprochait le
               plus de celle utilisée dans les casinos. Un autre méthode pourrait être
               de générer des valeurs aléatoires pour éviter que le joueur gagne
               lorsqu'il attend la fin du délai.
 ----------------------------------------------------------------------------------
 */


#include <QString>
#include <QThread>

#include "bmmanager.h"
#include "banditmanchot_interface.h"

// En microsecondes
#define DelaiLocal  4000000 // Temps à disposition du joueur

#define NbrDeRouleaux 3

class RouleauThread : public QThread
{
private:
    size_t pos;
    int valeur;
public:
    /**
     * @brief RouleauThread
     * @param pos l'indice du rouleau
     */
    RouleauThread(size_t pos) : pos(pos){}

    /**
     * @brief run pour afficher la valeur du rouleau
     * @return
     */
    void run() Q_DECL_OVERRIDE {
        valeur = 0; // valeur initiale
        setValeurRouleau(pos,valeur); // affiche la veleur du rouleau
        while(!isInterruptionRequested()){
            /* Incrémentation de la valeur du rouleau
               A noter qu'avec cette methode pour determiner la valeur, si le temps est écoulé,
               il y a de grande chances pour que le joueur gagne.
             */
            valeur = ++valeur % 10;
            setValeurRouleau(pos,valeur); // affiche la valeur du rouleau
            usleep(10000); // Temps d'attente entre chaque affichage
        }
    }

    /**
     * @brief getValue pour obtenir la valeur du rouleau
     * @return
     */
    int getValue(){return valeur;}
};

RouleauThread* rouleaux[NbrDeRouleaux]; // rouleaux disponibles

class DelaiThread : public QThread
{
private:
    int timeToWait;
    BmManager* bm;
public:
    /**
     * @brief DelaiThread
     * @param timeToWait le delai en millisecondes, bm le BmManager appelant
     */
    DelaiThread(size_t timeToWait, BmManager* bm) : timeToWait(timeToWait), bm(bm){}

    /**
     * @brief run pour afficher un compte à rebours du temps restant
     * @return
     */
    void run() Q_DECL_OVERRIDE {
        bool stop;
        // Affichage du temps restant
        while(timeToWait > 0 && (stop = !isInterruptionRequested())){
            QString s = QString("Temps restant : %1").arg(timeToWait / 100000);
            setMessage(s);  // Affichage du temps restant
            timeToWait -= 1000; // Décrémentation du temps restant
            usleep(1000); // Affiche le temps restant toutes les secondes
        }

        // Si le joueur n'a pas fini de jouer, bloque les rouleaux et affiche le résultat
        if(stop){
            for(int i = bm->getCurrent(); i < NbrDeRouleaux; ++i){
                bm->boutonStop();
            }
        }
    }
};



DelaiThread* delai;

void BmManager::start()
{
    setMessage("Veuillez introduire une pièce");
    setJackpot(jackpot); // Affiche la Valeur initiale du jackpot
}

void BmManager::end()
{
    // Arrête les threads

    for(RouleauThread* rt : rouleaux)
        rt->terminate();

    delai->terminate();
}

void BmManager::pieceIntroduite()
{
    if(current == -1){ // La partie n'as pas encore commencé
        setJackpot(++jackpot);
        // Initialisation des rouleaux et début de ces derniers
        for(int i = 0; i < NbrDeRouleaux; ++i){
            rouleaux[i] = new RouleauThread(i);
            rouleaux[i]->start();
        }

        // Initialisation et début du compte à rebours
        delai = new DelaiThread(DelaiLocal, this);
        delai->start();

        current = 0; // le premier rouleaux est le prochain à être stoppé
    }

}

void BmManager::boutonStop()
{
    if(current != -1){ // La partie a commencé

        // On arrête le rouleau
        rouleaux[current++]->requestInterruption();

        if(current == NbrDeRouleaux){ // Les 3 sont stoppés
            // on attend que le compte à rebours soient arrêté
            delai->requestInterruption();
            delai->wait();
            // Suppression des délai
            delete delai;

            // On attends que les threads se termine
            for(int i = 0; i < NbrDeRouleaux; ++i)
                rouleaux[i]->wait();

            // Récupération des valeurs des rouleaux
            int a = rouleaux[0]->getValue();
            int b = rouleaux[1]->getValue();
            int c = rouleaux[2]->getValue();

            // Suppression des rouleaux;
            for(int i = 0; i < NbrDeRouleaux; ++i)
                delete rouleaux[i];


            // Calcul des gains
            int gain = -1;
            if(a == b && a == c){ // Jackpot 1/2
                gain = ceil(jackpot / 2.0);
            }
            else if(a == b || a == c || b == c){    // 2 valeurs identiques, 1/4 du jackpot
                gain = ceil(jackpot / 4.0);
            }
            if(gain != -1){
                setMessage("Jackpot ! Vous avez gagné ! Total des gains : " + QString::number(gain));
                jackpot -= gain;
                setJackpot(jackpot);    // affichage de la nouvelle valeur du jackpot
            } else{
                setMessage("Dommage, retentez le coup :)");
            }

            current = -1; // fin de la partie
        }
    }
}

int BmManager::getCurrent() const{
    return current;
}
