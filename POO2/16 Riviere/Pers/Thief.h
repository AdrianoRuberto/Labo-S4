//
// Created by Nykros on 17.05.2016.
//

#ifndef INC_16_RIVIERE_VOLEUR_H
#define INC_16_RIVIERE_VOLEUR_H


#include "Person.h"

class Thief : public Person {

public:
	Thief(const string& name) : Person(name) { }

private:
	bool canDrive() const;
};


#endif //INC_16_RIVIERE_VOLEUR_H
