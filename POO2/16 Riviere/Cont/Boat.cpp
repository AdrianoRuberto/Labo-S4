//
// Created by Nykros on 12.05.2016.
//

#include "Boat.h"

const Bank* Boat::current() const {
	return _current;
}

string Boat::containsToString() const {
	return "< " + Container::containsToString() + " >";
}

void Boat::move(const Bank& other) {
	_current = &other;
}

bool Boat::canMove() const {
	for (const Person* p : _contains) {
		if (p->canDrive()) return true;
	}
	return false;
}

bool Boat::canLoad() const {
	return _contains.size() < MAX_LOAD;
}