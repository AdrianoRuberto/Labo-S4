#ifndef PRIMETHREAD_H
#define PRIMETHREAD_H

#include <qthread.h>

class PrimeThread : public QThread
{

public:
    static bool isPrime;
private:
    uint64_t x, min, max;

public:
    void run() Q_DECL_OVERRIDE{

        for(uint64_t i = min; !isPrime && i <= max; ++i){
            if(x % i == 0 && i != x) // Test si c'est un chiffre premier
                isPrime = false;
        }
        isPrime = true;
    }
    PrimeThread(const uint64_t x, const uint64_t min, const uint64_t max) : x(x), min(min), max(max){}
};


bool PrimeThread::isPrime = false;

#endif // THREAD_H
