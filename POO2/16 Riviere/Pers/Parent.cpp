/**
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_16
 Fichier     : Parent.h
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 18.05.2016
 ----------------------------------------------------------------------------------
 */

#include "Parent.h"
#include "../Dispatcher.h"

bool Parent::canDrive() const {
	return true;
}

void Mother::accept(Dispatcher& dispatcher) const {
	dispatcher.dispatch(*this);
}

void Father::accept(Dispatcher& dispatcher) const {
	dispatcher.dispatch(*this);
}