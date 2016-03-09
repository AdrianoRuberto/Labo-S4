/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_13
 Fichier     : test.h
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 09.03.2106

 But         : Cette classe a pour but d'initialiser et de mettre en oeuvre les 
 *             opérateurs logiques offerts par la classe BinaryMatrice et de ainsi
 *             de tester leur comportement. Pour ce faire, nous avons utiliser deux
 *             instances de la classe BinaryMatrice que nous utilisons pour effectuer
 *             les opérations logiques et que nous affichons après pour vérification 
 *             de leur état.

 ----------------------------------------------------------------------------------
 */

#ifndef TEST_H
#define	TEST_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "BinaryMatrice.h"

using namespace std;

class Test {
public:
   Test(size_t);
   ~Test();
   void testVor();
   void testPor();
   void testIor();
   void testVand();
   void testPand();
   void testIand();
   void testVxor();
   void testPxor();
   void testIxor();
private:
   BinaryMatrice* one;
   BinaryMatrice* two;
   int stepNo;
   void display();

};

#endif	/* TEST_H */

