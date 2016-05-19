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
#include "../Cont/Container.h"
#include <stdexcept>

class Thief : public Person {
private:
	const Cop* _cop;

	bool canDrive() const { return false; }

public:
	Thief(const Cop& cop, const string& name = "voleur") : _cop(&cop), Person(name) { }

	/**
	 * Valide uniquement si il y'a un policier ou s'il est seul
	 */
	void validation(const Container& container) const {
		if (!container.contain(*_cop) && container.size() >= 2) {
			throw runtime_error("Le voleur ne peut pas rester en contact avec un membre de la famille si le policier "
					                    "n'est pas present.");
		}
	}

};


#endif //INC_16_RIVIERE_VOLEUR_H
