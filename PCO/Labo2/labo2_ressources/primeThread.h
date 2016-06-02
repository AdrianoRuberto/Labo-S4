/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_2
 Fichier     : primeThread.h
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 17.03.2106

 But         : Ce programme a pour but de déterminer si un nombre est premier
 *             en utilisant plusieurs threads
 ----------------------------------------------------------------------------------
 */
#ifndef PRIMETHREAD_H
#define PRIMETHREAD_H

#include <QThread>
#include <vector>

using namespace std;

class PrimeThreadManager {

private:
    uint64_t x;
    bool prime;

public:
    /**
     * @brief PrimeThreadManager
     * @param x le nombre à check
     */
    PrimeThreadManager(const uint64_t x) : x(x){}

    /**
     * @brief run pour savoir si x est un nombre premier
     * @param maxThread le nombre de thread max à allouer
     * @return
     */
   /*
   ----------------------------------------------------------------------------------
   Description  : Déterminer si un nombre est premier

   Paramètre(s) : - maxThread : le nombre de threads à utiliser

   ----------------------------------------------------------------------------------
    */
    bool run(const size_t maxThread) {

        // calcule le nombre effectif de threads qu'il est possible d'utiliser
        const uint64_t TRANCHE = ceill(ceill(sqrt(x) - 1) / maxThread);

        vector<PrimeThread*> threads;

        for(size_t i = 0; i < maxThread; ++i)
            threads.push_back(new PrimeThread(this, x, 2 + i * TRANCHE, (i + 1) * TRANCHE + 2));

        for(PrimeThread* pt : threads)
            pt->start();

        for(PrimeThread* pt : threads)
            pt->wait(); // Attent que tous les thredas aient terminé

        for(PrimeThread* pt : threads)
            delete pt;

        return prime;
    }

    void setPrime(bool b){
        prime = b;
    }

    bool getPrime(){
        return prime;
    }

    class PrimeThread : public QThread
    {
    private:
        uint64_t x, min, max;
        PrimeThreadManager* ptm;

    public:
        void run() Q_DECL_OVERRIDE{
            for(uint64_t i = min; ptm->getPrime() && i <= max; ++i){
                if(x % i == 0 && i != x) // Test si c'est un chiffre premier
                    ptm->setPrime(false);
            }
        }

        PrimeThread(PrimeThreadManager* ptm, const uint64_t x, const uint64_t min, const uint64_t max)
            : ptm(ptm), x(x), min(min), max(max){}
    };
};

#endif // THREAD_H
