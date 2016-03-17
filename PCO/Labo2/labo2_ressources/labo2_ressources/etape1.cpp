/**
 * Labo2 - Etape 1
 * @author Adriano Ruberto
 *
 *
 */

#include "etape1.h"

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


