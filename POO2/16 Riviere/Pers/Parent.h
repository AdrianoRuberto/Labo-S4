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
public:
	Parent(const string& name) : Person(name) { }

	bool canDrive() const;
};


#endif //INC_16_RIVIERE_PARENT_H
