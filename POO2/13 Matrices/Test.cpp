/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_13
 Fichier     : Test.h
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 09.03.2106
 -----------------------------------------------------------------------------------
 */

#include "Test.h"

Test::Test(size_t size) {
   cout << "********** Lancement d'une nouvelle phase de tests **********\n\n";
   
   // Permet de garantir que chaque phase de test aura des valeur différente
   srand(time(0)); 
   one = new BinaryMatrice(size);
   two = new BinaryMatrice(size);
   
   cout << "1) Etats initiaux des matrices generees aleatoirement\n\n";
   display();
   
   stepNo = 2;
}

Test::~Test() {
}

void Test::testVor(){
   cout << stepNo++ << ") Test de l'operation \"one or two\" par valeur\n\n";
   cout << "one vor two\n";
   one->vor(*two).print();
   cout << "\n";
   display();
}

void Test::testPor(){
   cout << stepNo++ << ") Test de l'operation \"one or two\" par pointeur\n\n";
   cout << "one por two\n";
   one->por(*two)->print();
   cout << "\n";
   display();
}

void Test::testIor(){
   cout << stepNo++ << ") Test de l'operation \"one or two\" par modification\n\n";
   cout << "one ior two\n";
   one->ior(*two);
   cout << "\n";
   display();
}

void Test::testVand(){
   cout << stepNo++ << ") Test de l'operation \"one and two\" par valeur\n\n";
   cout << "one vand two\n";
   one->vand(*two).print();
   cout << "\n";
   display();
}

void Test::testPand(){
   cout << stepNo++ << ") Test de l'operation \"one and two\" par pointeur\n\n";
   cout << "one pand two\n";
   one->pand(*two)->print();
   cout << "\n";
   display();
}

void Test::testIand(){
   cout << stepNo++ << ") Test de l'operation \"one and two\" par modification\n\n";
   cout << "one iand two\n";
   one->iand(*two);
   cout << "\n";
   display();
}

void Test::testVxor(){
   cout << stepNo++ << ") Test de l'operation \"one xor two\" par valeur\n\n";
   cout << "one vxor two\n";
   one->vxor(*two).print();
   cout << "\n";
   display();
}

void Test::testPxor(){
   cout << stepNo++ << ") Test de l'operation \"one xor two\" par pointeur\n\n";
   cout << "one pxor two\n";
   one->pxor(*two)->print();
   cout << "\n";
   display();
}

void Test::testIxor(){
   cout << stepNo++ << ") Test de l'operation \"one xor two\" par modification\n\n";
   cout << "one ixor two\n";
   one->ixor(*two);
   cout << "\n";
   display();
}

void Test::display(){
   // Affichage de l'état des deux matrices
   cout << "one:\n";
   one->print();
   cout << "\n";
   cout << "two:\n";
   two->print();
   cout << "\n";
}



