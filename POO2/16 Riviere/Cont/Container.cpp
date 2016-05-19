/**
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_16
 Fichier     : Container.cpp
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 18.05.2016
 ----------------------------------------------------------------------------------
 */

#include <algorithm>
#include "Container.h"
#include "../Pers/Person.h"

string Container::toString() const {
	return name() + ": " + containsToString();
}

bool Container::contain(const Person& p) const {
	return std::find(_contains.begin(), _contains.end(), &p) != _contains.end();
}

string Container::containsToString() const {
	string res = " ";
	for (const Person* p : _contains) res += p->name() + " ";
	return res;
}

bool Container::isEmpty() const {
	return _contains.empty();
}

string Container::name() const {
	return _name;
}

void Container::load(const list<const Person*>& persons) {
	for (const Person* p : persons)
		load(*p);
}

void Container::load(const Person& p) {
	_contains.push_back(&p);
}

void Container::validation() const {
	for (const Person* p : _contains) {
		p->validation(*this);
	}
}

Container::Container(const string& name) : _name(name) { }

size_t Container::size() const {
	return _contains.size();
}

void Container::unload(const Person& p) {
	_contains.remove(&p);
}

void Container::load(Container& dest) {
	if (this != &dest) {
		dest.load(_contains);
		_contains.clear();
	}
}

const Person* Container::find(const string& name) const {
	for (const Person* p : _contains) {
		if (p->name() == name)
			return p;
	}
	return nullptr;
}