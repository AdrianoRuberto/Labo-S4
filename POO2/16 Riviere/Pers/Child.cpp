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
#include "../Cont/Container.h"

bool Child::canDrive() const {
	return false;
}

void Boy::validation(const Container& container) const {
	if(container.contain(*_mother) && !container.contain(*_father))
		throw runtime_error("Le garcon " + name() + " ne peut pas rester seul avec sa mere car son pere n'est pas la");
}

void Girl::validation(const Container& container) const {
	if(container.contain(*_father) && !container.contain(*_mother))
		throw runtime_error("La fille " + name() + " ne peut pas rester seule avec son pere car sa mere n'est pas la");
}