/**
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_16
 Fichier     : FamilyMember.h
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 18.05.2016
 ----------------------------------------------------------------------------------
 */

#include "FamilyMember.h"
#include "../Dispatcher.h"

FamilyMember::FamilyMember(const string& name) : Person(name) { }

void FamilyMember::accept(Dispatcher& dispatcher) const {
	dispatcher.dispatch(*this);
}