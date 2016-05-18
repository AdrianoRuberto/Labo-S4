//
// Created by Nykros on 12.05.2016.
//

#ifndef INC_16_RIVIERE_CONTAINER_H
#define INC_16_RIVIERE_CONTAINER_H

#include <string>
#include <list>
#include "Pers/Person.h"

using namespace std;

class Container {
private:
	string _name;
	list<Person*> _contains;
public:
	Container(const string& name) : _name(name) { }
	string toString() const;

};


#endif //INC_16_RIVIERE_CONTAINER_H
