/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_2
 Fichier     : prime.cpp
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 17.03.2106

 But         : Ce programme a pour but d'implémenter le calcul de validation d'un nombre
 *             premier et de comparer son efficacité lorsque l'implémentation est 
 *             multithread ou non en variant le nombre de thread pour avoir un aperçu
 *             du gain de temps en fonction du nombre de threads

 ----------------------------------------------------------------------------------
 */

/*
----------------------------------------------------------------------------------
Réponses au questions  : 

Question 1 : Mesurez le gain de temps produit par votre version multi-threadée en 
faisant varier le nombre de threads. Que remarquez-vous ?
 * On teste avec le nombre 18014398241046527:
 *    Sans multithread : 1197,
 *    Pour 1 thread : 1457ms,
 *    Pour 2 threads : 

----------------------------------------------------------------------------------
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
#include <ctime>
#include <chrono>
#include "PrimeThread.h"
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



typedef chrono::high_resolution_clock Clock;
typedef chrono::milliseconds milliseconds;

/*
----------------------------------------------------------------------------------
Description  : main du programme. Prends en arguments le nombre à tester et le nombre 
 *             de threads à utiliser

----------------------------------------------------------------------------------
 */
int main(int argc, char *argv[]) {

    if(argc != 3) // Pour savoir si on a bien que le nombre à tester
       return EXIT_FAILURE;

    // Récupère le nombre passé en argument
    uint64_t x = strtoull(argv[1], NULL, 0);

    const size_t MAX_THREAD = atoi(argv[2]);
    
    Clock::time_point start = Clock::now(); // récupère le temps actuel

    // Appel du test du nombre en mode multithread
    PrimeThreadManager ptm = PrimeThreadManager(x);
    bool prime = ptm.run(MAX_THREAD);
    
    Clock::time_point end = Clock::now(); // récupère le temps actuel
    milliseconds duration = chrono::duration_cast<milliseconds>(end - start); // Calcule la durée
    
    cout << "With threads(" << duration.count() << "ms) : " << (prime ? "" :"NOT a ") << "prime number!" << endl;
    
    start = Clock::now(); // récupère le temps actuel
    
    // Appel du test du nombre sans mode multithread
    prime = isPrime(x);
    
    end = Clock::now(); // récupère le temps actuel
    duration = duration = chrono::duration_cast<milliseconds>(end - start); // Calcule la durée
    
    cout << "Without threads(" << duration.count() << "ms) : " << (prime ? "" :"NOT a ") << "prime number!" << endl;

    //Quit the program
    return EXIT_SUCCESS;
}


