#include <QString>
#include <QThread>


#include "bmmanager.h"
#include "banditmanchot_interface.h"

// En microsecondes
#define DelaiLocal  4000000

#define NbrDeRouleaux 3
class RouleauThread : public QThread
{
private:
    size_t pos;
public:

    RouleauThread(size_t pos) : pos(pos){}
    int valeur;
    void run() Q_DECL_OVERRIDE {
        valeur = 0;
        setValeurRouleau(pos,valeur);
        while(!isInterruptionRequested()){
            usleep(10000);
            valeur = (valeur + 1) % 10;
            setValeurRouleau(pos,valeur);
        }
    }
};

class DelaiThread : public QThread
{
public:
    void run() Q_DECL_OVERRIDE {
        while(true){

        }
    }
};

RouleauThread* rouleaux[NbrDeRouleaux];
int current = 0;
int jackpot = 0;

void BmManager::start()
{

}

void BmManager::end()
{
    for(RouleauThread* rt : rouleaux)
        rt->terminate();
}

void BmManager::pieceIntroduite()
{
    setJackpot(++jackpot);

    for(int i = 0; i < NbrDeRouleaux; ++i){
        rouleaux[i] = new RouleauThread(i);
        rouleaux[i]->start();
    }
}

void BmManager::boutonStop()
{
    rouleaux[current++]->requestInterruption();
    if(current == NbrDeRouleaux){ // Les 3 sont stoppés

        if((rouleaux[0]->valeur == rouleaux[1]->valeur) == rouleaux[2]->valeur){ // Jackpot

        }

        for(int i = 0; i < NbrDeRouleaux; ++i){
            rouleaux[i]->wait();
            delete rouleaux[i];
        }
        current = 0;

    }
}
