//
// Created by Nykros on 12.05.2016.
//

#include "Container.h"

string Container::toString() const {
	string res = _name + ": ";
	for (Person* p : _contains) {
		res += p->name() + " ";
	}
	return res;
}