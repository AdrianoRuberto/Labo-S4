//
// Created by Nykros on 17.05.2016.
//

#ifndef INC_16_RIVIERE_ENFANTS_H
#define INC_16_RIVIERE_ENFANTS_H


#include "Person.h"
#include "Parent.h"

class Child : Person {

public:
	bool canDrive() const;
};

class Girl : Person {
public:
	bool canBeWith(const list<Person*> persons) const {
		return false;
	}

};

class Boy : Person {

};


#endif //INC_16_RIVIERE_ENFANTS_H
