//
// Created by Nykros on 12.05.2016.
//

#include <algorithm>
#include "Container.h"

string Container::toString() const {
	return name() + ": " + containsToString();
}

void Container::move(const Person& p, Container& source, Container& dest) {
	if (!source.contain(p))
		throw runtime_error("The person " + p.name() + " is not in " + source.toString());

	source._contains.remove(&p);
	dest._contains.push_back(&p);
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

void Container::moveAll(Container& dest) {
	for (const Person* p : _contains) {
		dest._contains.push_back(p);
	}
	_contains.clear();
}

void Container::load(const list<const Person*> persons) {
	for(const Person* p : persons)
		_contains.push_back(p);
}