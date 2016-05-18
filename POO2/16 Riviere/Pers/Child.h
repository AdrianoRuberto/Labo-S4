//
// Created by Nykros on 17.05.2016.
//

#ifndef INC_16_RIVIERE_ENFANTS_H
#define INC_16_RIVIERE_ENFANTS_H


#include "Person.h"
#include "Parent.h"

class Child : public Person {

public:
	Child(const string& name) : Person(name) { }

	bool canDrive() const;
};

class Girl : public Child {
public:
	Girl(const string& name) : Child(name) { }
};

class Boy : public Child {

public:
	Boy(const string& name) : Child(name) { }
};


#endif //INC_16_RIVIERE_ENFANTS_H
