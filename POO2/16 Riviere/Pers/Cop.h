//
// Created by Nykros on 18.05.2016.
//

#ifndef INC_16_RIVIERE_COP_H
#define INC_16_RIVIERE_COP_H


#include "Person.h"

class Cop : public Person {

public:
	Cop(const string& name) : Person(name) { }

	bool canDrive() const;
};


#endif //INC_16_RIVIÈRE_COP_H
