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
	string name;

public:
	virtual bool canDrive() const = 0;
	virtual bool canBeWith(const list<Person*> persons) const = 0;
};


#endif //INC_16_RIVIÈRE_PERSON_H
