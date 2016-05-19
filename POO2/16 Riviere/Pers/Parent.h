/**
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_16
 Fichier     : Parent.cpp
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 18.05.2016
 But         : Ce fichier implémente 3 classes, chacun représentant:
               - Un parent abstrait
               - Un père
               - Une mère
 ----------------------------------------------------------------------------------
 */

#ifndef INC_16_RIVIERE_PARENT_H
#define INC_16_RIVIERE_PARENT_H

#include "Person.h"

class Parent : public Person {
protected:
	Parent(const string& name) : Person(name) { }

public:
	bool canDrive() const;
};

class Father : public Parent {
public:
	Father(const string& name) : Parent(name) { }
};

class Mother : public Parent {
public:
	Mother(const string& name) : Parent(name) { }
};


#endif //INC_16_RIVIERE_PARENT_H
