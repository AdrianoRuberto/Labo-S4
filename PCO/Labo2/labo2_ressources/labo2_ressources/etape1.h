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

#ifndef ETAPE1_H
#define	ETAPE1_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>
#include <limits.h>
#include <iostream>
#include <cmath>
#include <cstdint>


/*
----------------------------------------------------------------------------------
Description  : Déterminer si un nombre est premier

Paramètre(s) : - x : le nombre à tester

----------------------------------------------------------------------------------
 */
bool isPrime(const uint64_t x);


#endif	/* ETAPE1_H */

