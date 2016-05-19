/**
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_16
 Fichier     : Parent.cpp
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 18.05.2016
 But         : Cette classe représente un parent
 ----------------------------------------------------------------------------------
 */

#ifndef INC_16_RIVIERE_PARENT_H
#define INC_16_RIVIERE_PARENT_H

#include "Person.h"

class Parent : public Person {
protected:
	Parent(const string& name) : Person(name) { }

public:
	bool canDrive() const { return true; }
};

class Father : public Parent {
public:
	Father(const string& name = "pere") : Parent(name) { }
};

class Mother : public Parent {
public:
	Mother(const string& name = "mere") : Parent(name) { }
};


#endif //INC_16_RIVIERE_PARENT_H
