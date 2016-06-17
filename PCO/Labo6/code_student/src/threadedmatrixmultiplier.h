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
 * A multi-threaded multiplicator to be implemented.
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

        WorkerTask( SquareMatrix<T> &A,  SquareMatrix<T> &B, SquareMatrix<T> *C, int size, int col, int row)
            : A(&A), B(&B), C(C) {
            beginCol = size * col;
            endCol = size * (col + 1);
            beginRow = size * row;
            endRow = size * (row + 1);

        }
    };

    class MatrixWorker : public QThread {
    private:
        ThreadedMatrixMultiplier* creator;
    public:
        MatrixWorker(ThreadedMatrixMultiplier* creator)
            : creator(creator) {
        }

        /**
         * @brief Try to get a task and do it.
         */
        void run() {
            while(true) {
                WorkerTask task = creator->get();
                for(int i = task.beginCol; i < task.endCol; ++i) {
                    for(int j = task.beginRow; j < task.endRow; ++j) {
                        for(int k = 0 ; k < task.A->size(); k++) {
                            task.C->setElement(i, j, task.C->element(i, j) + task.A->element(k, j) * task.B->element(i, k));
                        }
                    }
                }

                creator->signal(creator->taskDone);
            }
        }

    };


    QQueue<WorkerTask> tasks;
    QList<MatrixWorker*> workers;

    Condition newTask;
    Condition taskDone;

    /**
     * @brief Adds a task to the queue of tasks, will trigger the newTask
     * condition.
     * @param task the task to add
     */
    void add(WorkerTask& task) {
        monitorIn();
        tasks.enqueue(task);
        signal(newTask);
        monitorOut();
    }

    /**
     * @brief Gets a task, if no task to be done, will wait till the newTask
     *        condition is triggered.
     * @return a task
     */
    WorkerTask get() {
        monitorIn();
        while(tasks.isEmpty()) {
            wait(newTask);
        }

        WorkerTask task = tasks.dequeue();
        monitorOut();
        return task;
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
        for(MatrixWorker* w : workers) {
            w->terminate();
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
        int size = A.size() / nbBlocks;
        int nbTasks = 0;
        for (int i = 0; i < nbBlocks; ++i) {
            for (int j = 0; j < nbBlocks; ++j) {
                WorkerTask task(A, B, C, size, i, j);
                add(task);
                ++nbTasks;
            }
        }

        for(int i = 0; i != nbTasks; ++i) {
            wait(taskDone);
        }
    }

protected:
    int nbThreads;
    int nbBlocksPerRow;
};



#endif // THREADEDMATRIXMULTIPLIER_H
