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
    int valeur;
public:
    RouleauThread(size_t pos) : pos(pos){}
    void run() Q_DECL_OVERRIDE {
        valeur = 0;
        setValeurRouleau(pos,valeur);
        while(!isInterruptionRequested()){
            valeur = rand() % 10;
            setValeurRouleau(pos,valeur);
            usleep(10000);
        }
    }

    int getValue(){return valeur;}
};

class DelaiThread : public QThread
{
private:
    int timeToWait;
    BmManager* bm;
public:
    DelaiThread(size_t timeToWait, BmManager* bm) : timeToWait(timeToWait), bm(bm){}

    void run() Q_DECL_OVERRIDE {
        bool stop;
        while(timeToWait > 0 && (stop = !isInterruptionRequested())){
            QString s = QString("Temps restant : %1").arg(timeToWait / 100000);
            setMessage(s);
            timeToWait -= 1000;
            usleep(1000);

         }

        if(stop){
            for(int i = bm->getCurrent(); i < NbrDeRouleaux; ++i){
                bm->boutonStop();
            }
        }
    }
};


RouleauThread* rouleaux[NbrDeRouleaux];
DelaiThread* delai;

void BmManager::start()
{
    setMessage("Veuillez introduire une pièce");
    setJackpot(jackpot);
}

void BmManager::end()
{
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

        delai = new DelaiThread(DelaiLocal, this);
        delai->start();
        current = 0;

    }

}

void BmManager::boutonStop()
{
    if(current != -1){ // La partie a commencé

        // On arrête
        rouleaux[current++]->requestInterruption();

        if(current == NbrDeRouleaux){ // Les 3 sont stoppés

            // On attends que les threads se termine
            for(RouleauThread* rt : rouleaux)
                rt->wait();

            delai->requestInterruption();

            delai->wait();

            int a = rouleaux[0]->getValue();
            int b = rouleaux[1]->getValue();
            int c = rouleaux[2]->getValue();

            int gain = -1;
            if(a == b && a == c){ // Jackpot 1/2
                gain = ceil(jackpot / 2.0);
            }
            else if(a == b || a == c || b == c){
                gain = ceil(jackpot / 4.0);
            }
            if(gain != -1){
                setMessage("Jackpot ! Vous avez gagné !");
                jackpot -= gain;
                setJackpot(jackpot);
            } else{
                setMessage("Dommage, retentez le coup :)");
            }

            // Suppression des rouleaux;
            for(int i = 0; i < NbrDeRouleaux; ++i)
                delete rouleaux[i];

            // Suppression des délai
            delete delai;

            current = -1;
        }
    }
}

int BmManager::getCurrent() const{
    return current;
}
