/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_2
 Fichier     : etape1.cpp
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 17.03.2106

 But         : Ce programme a pour but d'implémenter le calcul de validation d'un 
 *             nombre premier à l'aide d'une simple fonction sans utilisation de 
 *             thread

 ----------------------------------------------------------------------------------
 */

#include "etape1.h"
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


