/**
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_16
 Fichier     : Boat.cpp
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 18.05.2016
 ----------------------------------------------------------------------------------
 */

#include <stdexcept>
#include "Boat.h"
#include "../Pers/Person.h"

Bank* Boat::current() const {
	return _current;
}

string Boat::containsToString() const {
	return "<" + Container::containsToString() + ">";
}

void Boat::move(Bank& other) {
	for (const Person* p : _contains) {
		if (p->canDrive()) {
			_current = &other;
			return;
		}
	}

	throw runtime_error("Personne peut conduire le bateau");
}

void Boat::load(const Person& p) {
	if (_contains.size() < MAX_LOAD)
		Container::load(p);
	else throw runtime_error("Deja trop de personnes sur " + name());
}