/**
 * Labo2 - Etape 1
 * @author Adriano Ruberto
 *
 *
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

using namespace std;

// Various prime numbers:
// 433494437
// 2971215073
// 68720001023
// 4398050705407
// 70368760954879
// 18014398241046527
// 99194853094755497


/**
 * @brief isPrime permet de savoir si un nombre est premier ou non
 * @param x le nombre à tester
 * @return true si x est un chiffre premier, sinon false
 */
bool isPrime(const uint64_t x){

    const uint64_t MAX = ceill(sqrt(x));

    for(uint64_t i = 2; i <= MAX; ++i){
        if(x % i == 0 && i != x) // Test si c'est un chiffre premier
            return false;
    }

    return true;
}

int main(int argc, char *argv[]) {

    if(argc != 2) // Pour savoir si on a bien que le nombre à tester
       return EXIT_FAILURE;

    // Récupère le nombre passé en argument
    uint64_t x = strtoull(argv[1], NULL, 0);

    cout << (isPrime(x) ? "" :"NOT a ") << "prime number!" << endl;

    //Quit the program
    return EXIT_SUCCESS;
}

