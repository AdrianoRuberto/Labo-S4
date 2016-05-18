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

string Container::toString() const {
	return name() + ": " + containsToString();
}

void Container::move(const Person& p, Container& source, Container& dest) {
	if (!source.contain(p))
		throw runtime_error("La personne " + p.name() + " n'est pas dans " + source.toString());

	dest.load(p);
	source._contains.remove(&p);
}

void Container::move(Container& source, Container& dest) {
	dest.load(source._contains);
	source._contains.clear();
}

bool Container::contain(const Person& p) const {
	return find(_contains.begin(), _contains.end(), &p) != _contains.end();
}

string Container::containsToString() const {
	string res = "";
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
	for(const Person* p : _contains){
		p->validation(*this);
	}
}

void Container::accept(Dispatcher& dispatcher){
	for(const Person* p : _contains){
		p->accept(dispatcher);
	}

}