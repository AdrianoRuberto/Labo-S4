/**
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_16
 Fichier     : Child.cpp
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 18.05.2016
 ----------------------------------------------------------------------------------
 */

#include <stdexcept>
#include "Child.h"
#include "../Dispatcher.h"

bool Child::canDrive() const {
	return false;
}

void Boy::validation(const Container& container) const {
	BoyDispatcher dispatcher;
	container.accept(dispatcher);
	if(dispatcher._mother && !dispatcher._father)
		throw runtime_error("Le garcon " + name() + " ne peut pas rester seuls avec sa mere car son pere n'est pas la");
}