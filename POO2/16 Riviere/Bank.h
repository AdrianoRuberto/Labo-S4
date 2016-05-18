//
// Created by Nykros on 12.05.2016.
//

#ifndef INC_16_RIVIERE_BANK_H
#define INC_16_RIVIERE_BANK_H


#include "Container.h"

class Bank : public Container {

public:
	Bank(const string& name, const list<const Person*>& contains = list<const Person*>()) : Container(name, contains)
	{ }
};


#endif //INC_16_RIVIERE_BANK_H
