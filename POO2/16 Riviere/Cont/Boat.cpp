//
// Created by Nykros on 12.05.2016.
//

#include "Boat.h"

const Bank* Boat::bank() const {
	return _current;
}

string Boat::containsToString() const {
	return "< " + Container::containsToString() + " >";
}

void Boat::move(const Bank& other) {
	_current = &other;
}

const Bank* Boat::current() const {
	return _current;
}

bool Boat::canMove() const {
	for(const Person* p : _contains){
		if(p->canDrive()) return true;
	}
	return false;
}