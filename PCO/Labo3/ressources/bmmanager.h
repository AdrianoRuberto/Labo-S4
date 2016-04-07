/** \file bm_manager.h
* \brief Définition des fonctions que le développeur doit implémenter. 
*        Ces fonctions sont appelées par l'interface graphique.
* \author Yann Thoma
* \date 03.03.2016
*/

#ifndef BMMANAGER_H_
#define BMMANAGER_H_

#include <QObject>
class BmManager
{
private:
    int current = -1;
    int jackpot = 50;

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

    int getCurrent() const;
};

#endif /*BMMANAGER_H_*/
