/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_3
 Fichier     : bmmanager.cpp
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 07.04.2106

 But         : Ce programme a pour but d'implémenter un bandit manchot semblable aux
               machines que l'on peut trouver dans un casino

 ----------------------------------------------------------------------------------
 */

#ifndef BMMANAGER_H_
#define BMMANAGER_H_

#include <QObject>
class BmManager
{
private:
    int current = -1;
    int jackpot = 50; // valeur initiale du jackpot

public:
    /**
    * \brief Cette fonction est appelée une seule fois, au lancement de
    *        l'application.
    */
    void start();

    /**
    * \brief Cette fonction est appelée une seule fois, à la terminaison
    *        de l'application.
    */
    void end();

    /**
    * \brief Cette fonction est appelée lorsqu'une pièce a été insérée.
    */
    void pieceIntroduite();

    /**
    * \brief Cette fonction est appelée lorsque le bouton stop est enfoncé.
    */
    void boutonStop();

    /**
     * @brief getCurrent pour obtenir le rouleau actuellement en jeu, le prochain à être stoppé
     */
    int getCurrent() const;
};

#endif /*BMMANAGER_H_*/
