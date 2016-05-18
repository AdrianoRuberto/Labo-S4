/**
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_16
 Fichier     : Thief.h
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 18.05.2016
 But         : Cette classe représente un voleur
 ----------------------------------------------------------------------------------
 */

#ifndef INC_16_RIVIERE_VOLEUR_H
#define INC_16_RIVIERE_VOLEUR_H


#include "Person.h"

class Thief : public Person {

public:
	Thief(const string& name) : Person(name) { }

private:
	bool canDrive() const;
};


#endif //INC_16_RIVIERE_VOLEUR_H
