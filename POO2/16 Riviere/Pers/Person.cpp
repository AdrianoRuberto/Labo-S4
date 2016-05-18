//
// Created by Nykros on 12.05.2016.
//

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