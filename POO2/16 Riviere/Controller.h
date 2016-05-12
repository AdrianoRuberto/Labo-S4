//
// Created by Nykros on 12.05.2016.
//

#ifndef INC_16_RIVIERE_CONTROLLER_H
#define INC_16_RIVIERE_CONTROLLER_H

#include "Person.h"
#include "Bank.h"
#include "Boat.h"
#include <list>

class Controller : Person {
private:
	int turn;
	Bank* bankOne;
	Bank* bankTwo;
	Boat* boat;
	list<Person*> persons;
public:
	void showMenu() const;
	void display() const;
	void nextTurn() const;
};


#endif //INC_16_RIVIÈRE_CONTROLLER_H
