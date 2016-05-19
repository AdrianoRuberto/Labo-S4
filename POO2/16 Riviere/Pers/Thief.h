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
#include "Cop.h"

class Thief : public Person {
private:
	const Cop* _cop;

	bool canDrive() const;

public:
	Thief(const string& name, const Cop& cop) : Person(name), _cop(&cop) { }

	void validation(const Container& container) const;

};


#endif //INC_16_RIVIERE_VOLEUR_H
