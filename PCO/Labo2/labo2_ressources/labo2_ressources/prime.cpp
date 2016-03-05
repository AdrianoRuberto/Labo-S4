/**
 * Labo2 - Etape 2
 * @author Adriano Ruberto
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>
#include <limits.h>
#include <iostream>
#include <cmath>
#include <cstdint>
#include "PrimeThread.h"

using namespace std;

// Various prime numbers:
// 433494437
// 2971215073
// 68720001023
// 4398050705407
// 70368760954879
// 18014398241046527
// 99194853094755497


int main(int argc, char *argv[]) {

    if(argc != 2) // Pour savoir si on a bien que le nombre à tester
       return EXIT_FAILURE;

    //const uint64_t MAX = ceill(sqrt(x));

    // Récupère le nombre passé en argument
    uint64_t x = strtoull(argv[1], NULL, 0);

    const int MAX_THREAD = atoi(argv[2]);

    vector<PrimeThread> threads;
    for(int i = 0; i < MAX_THREAD; ++i){
        threads.push_back();
    }

    //Quit the program
    return EXIT_SUCCESS;
}

