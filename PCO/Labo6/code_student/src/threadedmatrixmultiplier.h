/**
 * Groupe : Adriano Ruberto & Matthieu Villard
 * PCO - Labo6
 *
 * Il nous a été demandé d'implémenter une multiplication matricielle pour une
 * architecture multi-coeur.
 *
 * Pour cela, nous avons structurer notre code de la façon suivante :
 * - Une classe WorkerTask qui est une subdivision de la matrice résultante et
 *   qu'il faut sommer avec les 2 autres matrices. Elle représente donc une
 *   tâche à faire.
 * - Une classe MatrixWorker qui permet de faire les tâches
 * - Une classe ThreadedMatrixMultiplier qui permet de faire la multiplication
 *   entre 2 matrices.
 *
 * Deux condition sont dans le ThreadedMatrixMultiplier
 * - newTask qui modélise l'arrivée d'une nouvelle tâche
 * - allTaskDone qui permet de savoir si toutes les tâches on été faites.
 *
 * newTask est utilisée dans la fonction get de ThreadedMatrixMultiplier et
 * permet de faire une attente passive si les MatrixWorker ont finis toutes
 * les tâches qui étaient disponible.
 *
 * allTaskDone est quant à elle utilisée pour signaler la fin d'une série de
 * WorkerTask.
 */

#ifndef THREADEDMATRIXMULTIPLIER_H
#define THREADEDMATRIXMULTIPLIER_H

#include <QThread>
#include <QSemaphore>
#include <QVector>
#include <QMutex>
#include <QQueue>

#include "hoaremonitor.h"
#include "matrix.h"
#include "abstractmatrixmultiplier.h"

/**
 * A multi-threaded multiplicator.
 */
template <class T>
class ThreadedMatrixMultiplier
        : public AbstractMatrixMultiplier<T>, public HoareMonitor
{
private:

    /**
     * @brief The WorkerTask class is the task for the MatrixWorkers.
     * It contains all the information (ie: begin/end of col/row, the 3 matrix)
     * needed to subdivise the multiplication.
     */
    class WorkerTask {
    public:
        SquareMatrix<T>* A;
        SquareMatrix<T>* B;
        SquareMatrix<T>* C;
        int beginRow;
        int endRow;
        int beginCol;
        int endCol;
        int* nbTasks;

        WorkerTask( SquareMatrix<T> &A,  SquareMatrix<T> &B, SquareMatrix<T> *C, int size, int col, int row, int nbTasks)
            : A(&A), B(&B), C(C), nbTasks(&nbTasks) {
            beginCol = size * col;
            endCol = size * (col + 1);
            beginRow = size * row;
            endRow = size * (row + 1);
        }
    };

    /**
     * @brief The MatrixWorker class is a worker who will try to get a
     * WorkerTask and to do it.
     */
    class MatrixWorker : public QThread {
    private:
        ThreadedMatrixMultiplier* manager;
    public:
        MatrixWorker(ThreadedMatrixMultiplier* manager)
            : manager(manager) {
        }

        /**
         * @brief Try to get a task and do it.
         */
        void run() {
            while(true){
                try{
                    WorkerTask task = manager->get();
                    for(int i = task.beginCol; i < task.endCol; ++i) {
                        for(int j = task.beginRow; j < task.endRow; ++j) {
                            for(int k = 0 ; k < task.A->size(); k++) {
                                task.C->setElement(i, j, task.C->element(i, j) + task.A->element(k, j) * task.B->element(i, k));
                            }
                        }
                    }
                    manager->finish(task);
                } catch(...) {
                    // Signal it will be dead
                    manager->monitorIn();
                    manager->signal(manager->workerDeath);
                    manager->monitorOut();
                    break;
                }
            };
        }
    };

    QQueue<WorkerTask> tasks;
    QList<MatrixWorker*> workers;

    Condition newTask;
    Condition allTasksDone;
    Condition workerDeath;

    int waitingWorker = 0;

    bool running = true;

    /**
     * @brief Gets a task, if no task to be done, will wait till the newTask
     *        condition is triggered.
     * @return a task
     */
    WorkerTask get() {
        monitorIn();

        ++waitingWorker;
        while(tasks.isEmpty() && running) {
            wait(newTask);
        }
        --waitingWorker;

        if(!running) { // Throw an error for the worker to stop.
            monitorOut();
            throw std::runtime_error("Stop you");
        }

        WorkerTask task = tasks.dequeue();
        monitorOut();
        return task;
    }

    /**
     * @brief finish a task, if all the task are done, will signal allTasksDone
     * @param task the finished task
     */
    void finish(WorkerTask task) {
        monitorIn();
        (*task.nbTasks)--;
        if(*task.nbTasks <= 0) {
            signal(allTasksDone);
        }
        monitorOut();
    }




public:

    /**
     * @brief ThreadedMatrixMultiplier is the constructor of this class,
     *        he creates all the worker and start them.
     * @param nbThreads the number of threaded worker
     * @param nbBlocksPerRow the number of blocks per row
     */
    ThreadedMatrixMultiplier(int nbThreads, int nbBlocksPerRow = 0)
        : nbThreads(nbThreads), nbBlocksPerRow(nbBlocksPerRow) {
        monitorIn();
        for(int i = 0; i < nbThreads; ++i) {
            workers << new MatrixWorker(this);
            workers.back()->start();
        }
        monitorOut();
    }

    ~ThreadedMatrixMultiplier() {
        monitorIn();
        running = false;

        // Kill the remaining waiting workers
        while(waitingWorker > 0) {
            signal(newTask);
            wait(workerDeath);
        }

        monitorOut();

        for(MatrixWorker* w : workers) {
            w->wait();
            delete w;
        }
    }

    /**
     * @brief multiply 2 square matrix in one result matrix
     * @param A the first matrix
     * @param B the second matrix
     * @param C the result of A x B
     */
    void multiply( SquareMatrix<T> &A,  SquareMatrix<T> &B, SquareMatrix<T> *C) {
        multiply(A, B, C, nbBlocksPerRow);
    }

    /**
     * @brief multiply 2 square matrix in one result matrix, but with a number
     * of blocks
     * @param A the first matrix
     * @param B the second matrix
     * @param C the result of A x B
     * @param nbBlocks the number of blocks
     */
    void multiply( SquareMatrix<T> &A,  SquareMatrix<T> &B, SquareMatrix<T> *C, int nbBlocks) {
        monitorIn();
        int size = A.size() / nbBlocks;
        int nbTasks = 0;
        for (int i = 0; i < nbBlocks; ++i) {
            for (int j = 0; j < nbBlocks; ++j) {
                WorkerTask task(A, B, C, size, i, j, ++nbTasks);
                tasks.enqueue(task);
                signal(newTask);
            }
        }

        wait(allTasksDone);
        monitorOut();
    }

protected:
    int nbThreads;
    int nbBlocksPerRow;
};



#endif // THREADEDMATRIXMULTIPLIER_H
