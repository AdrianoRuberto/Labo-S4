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
#include "../Dispatcher.h"

bool Thief::canDrive() const {
	return false;
}

void Thief::validation(const Container& container) const {
	ThiefDispatcher tf;
	container.accept(tf);

	if(!tf._cop && tf._fm)
		throw runtime_error("Le voleur ne peut pas rester en contact avec un membre de la famille si le policier "
				                    "n'est pas present.");

}