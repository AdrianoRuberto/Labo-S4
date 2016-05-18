//
// Created by Nykros on 12.05.2016.
//

#include "Boat.h"

const Bank* Boat::bank() const {
	return currentBank;
}

string Boat::containsToString() const {
	return "< " + Container::containsToString() + " >";
}