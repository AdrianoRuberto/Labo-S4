#include "mythread.h"

long unsigned int MyThread::compteur;


MyThread::MyThread(long unsigned int paramNbIterations, QObject *parent) :
    QThread(parent)
{
    nbIterations = paramNbIterations;
}

void MyThread::run()
{
    long unsigned int i = 0;

    while (i < nbIterations)
    {
        compteur++;
        i++;

        QThread::yieldCurrentThread();
    }
}
