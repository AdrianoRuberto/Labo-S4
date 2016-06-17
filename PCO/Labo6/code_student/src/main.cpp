#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

#define ITEMTYPE int

#include "multipliertester.h"
#include "multiplierthreadedtester.h"


int main (int argc, char* argv[])
{
    if(argc != 4) {
        std::cout << "Need 0 argument or should be [matrix size] [nb blocks] [nb threads]" << std::endl;
        return EXIT_FAILURE;
    }

    bool testReentrant = true;
    bool testSimple   = true;

    int matrixSize = std::atoi(argv[1]);
    int nbBlock = std::atoi(argv[2]);
    int nbThread = std::atoi(argv[3]);


    if (testReentrant) {
        MultiplierThreadedTester<ITEMTYPE> tester(nbThread);

        tester.test(matrixSize, nbBlock);
    } if (testSimple) {
        MultiplierTester<ITEMTYPE> tester;

        tester.test(matrixSize,nbThread,nbBlock);
    }


    return EXIT_SUCCESS;
}
