/**
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_16
 Fichier     : Cop.h
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 18.05.2016
 ----------------------------------------------------------------------------------
 */

#include "Cop.h"
#include "../Dispatcher.h"

bool Cop::canDrive() const {
	return true;
}

void Cop::accept(Dispatcher& dispatcher) const {
	dispatcher.dispatch(*this);
}