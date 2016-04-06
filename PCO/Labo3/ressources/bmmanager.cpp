#include <QString>
#include <QThread>


#include "bmmanager.h"
#include "banditmanchot_interface.h"

// En microsecondes
#define DelaiLocal  4000000

class RouleauThread : public QThread
{
private:
    static int nb;
    int pos = nb++;
public:

    void run() Q_DECL_OVERRIDE {
        int valeur;
        valeur = 0;
        setValeurRouleau(pos,valeur);
        for(;;){
            usleep(10000);
            valeur = (valeur + 1) % 10;
            setValeurRouleau(pos,valeur);
        }
    }
};

RouleauThread rouleaux[3];
int current = 0;
int jackpot = 0;

void BmManager::start()
{
}

void BmManager::end()
{
    for(RouleauThread& rt : rouleaux)
        rt.terminate();
}

void BmManager::pieceIntroduite()
{
    setJackpot(++jackpot);
    for(RouleauThread& rt : rouleaux)
        rt.start();
}

void BmManager::boutonStop()
{
    rouleaux[current++].terminate();
    if(current == 2){ // Les 3 sont stoppés

    }
}

int RouleauThread::nb = 0;
