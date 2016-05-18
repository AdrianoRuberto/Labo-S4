//
// Created by Nykros on 12.05.2016.
//

#ifndef INC_16_RIVIERE_PERSON_H
#define INC_16_RIVIERE_PERSON_H

#include <string>
#include <list>

using namespace std;

class Person {
private:
	string _name;

public:
	Person(const string& name) : _name(name) { }

	virtual bool canDrive() const = 0;

	// virtual bool canBeWith(const list<Person*> persons) const = 0;
	string name() const;

	static const Person* find(const list<const Person*>& persons, const string name);
};


#endif //INC_16_RIVIÈRE_PERSON_H
