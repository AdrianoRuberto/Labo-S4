//
// Created by Nykros on 12.05.2016.
//

#ifndef INC_16_RIVIERE_CONTROLLER_H
#define INC_16_RIVIERE_CONTROLLER_H

#include "Pers/Person.h"
#include "Bank.h"
#include "Boat.h"
#include <list>

class Controller {
private:
	int turn;
	Container* _left = new Container("Gauche");
	Container* _right = new Container("Droite");
	Container* _boat = new Container("Boat");
	list<Person*> _persons;
public:
    Controller(const list<Person*>& persons) {

    }

	void showMenu() const;
	void display() const;
	void nextTurn() const;
};


#endif //INC_16_RIVIÈRE_CONTROLLER_H
