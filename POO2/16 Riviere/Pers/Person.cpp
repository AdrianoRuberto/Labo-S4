/**
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_16
 Fichier     : Person.cpp
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 18.05.2016
 ----------------------------------------------------------------------------------
 */

#include "Person.h"


string Person::name() const {
	return _name;
}

const Person* Person::find(const list<const Person*>& persons, const string name) {
	for(const Person* p : persons){
		if(p->_name == name)
			return p;
	}
	return nullptr;
}

Person::Person(const string& name) : _name(name) { }