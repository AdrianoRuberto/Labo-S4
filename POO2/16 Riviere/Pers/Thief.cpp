/**
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_16
 Fichier     : Thief.cpp
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 18.05.2016
 ----------------------------------------------------------------------------------
 */
#include <stdexcept>
#include "Thief.h"
#include "../Cont/Container.h"

bool Thief::canDrive() const {
	return false;
}

void Thief::validation(const Container& container) const {
	if (!container.contain(*_cop) && container.size() >= 2) {
		throw runtime_error("Le voleur ne peut pas rester en contact avec un membre de la famille si le policier "
				                    "n'est pas present.");
	}
}