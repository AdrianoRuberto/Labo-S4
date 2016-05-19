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

void Parent::accept(Dispatcher& dispatcher) const {
	dispatcher.dispatch(*this);
	FamilyMember::accept(dispatcher);
}

void Mother::accept(Dispatcher& dispatcher) const {
	dispatcher.dispatch(*this);
	Parent::accept(dispatcher);
}

void Father::accept(Dispatcher& dispatcher) const {
	dispatcher.dispatch(*this);
	Parent::accept(dispatcher);
}