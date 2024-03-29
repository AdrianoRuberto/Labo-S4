/**
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_16
 Fichier     : Cop.cpp
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 18.05.2016
 But         : Cette classe représente un policier
 ----------------------------------------------------------------------------------
 */

#ifndef INC_16_RIVIERE_COP_H
#define INC_16_RIVIERE_COP_H


#include "Person.h"

class Cop : public Person {

public:
	Cop(const string& name = "policier") : Person(name) { }

	bool canDrive() const { return true; }
};


#endif //INC_16_RIVIÈRE_COP_H
