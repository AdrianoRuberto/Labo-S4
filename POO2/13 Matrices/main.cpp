/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_13
 Fichier     : main.h
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 09.03.2106

 But         : Ce programme a pour but de mettre en oeuvre et tester des
 *             fonctionnalités relatives à la manipulation de matrices binaires
 *             carrées.

 ----------------------------------------------------------------------------------
 */
#include "Test.h"

int main() {
    Test test(5);
    test.testVor();
    test.testPor();
    test.testIor();
    test.testVand();
    test.testPand();
    test.testIand();
    test.testVxor();
    test.testIand();
    test.testVxor();
    test.testPxor();
    test.testIxor();
    
    return 0;
}