//
// Created by Nykros on 12.05.2016.
//

#ifndef INC_16_RIVIERE_CONTROLLER_H
#define INC_16_RIVIERE_CONTROLLER_H

#include "Pers/Person.h"
#include "Bank.h"
#include "Boat.h"
#include "Pers/Parent.h"
#include "Pers/Child.h"
#include "Pers/Cop.h"
#include "Pers/Thief.h"
#include <list>

class Controller {
private:
	int turn = 0;
	Bank _left;
	Bank _right;
	Boat _boat;
	list<const Person*> _persons;

	void cmdNotFound();
public:
	Controller() : _left("Gauche"), _right("Droite"), _boat("Bateau", _left) {
		_persons.push_back(new Father("pere"));
		_persons.push_back(new Mother("mere"));
		_persons.push_back(new Boy("paul"));
		_persons.push_back(new Boy("pierre"));
		_persons.push_back(new Girl("julie"));
		_persons.push_back(new Girl("jeanne"));
		_persons.push_back(new Cop("policier"));
		_persons.push_back(new Thief("voleur"));

		_left = Bank("Gauche", _persons);
		_right = Bank("Droite");

		_boat = Boat("Bateau", _left);

	}

	~Controller() {
		for(const Person* p : _persons)
			delete p;
	}

	void showMenu() const;

	void display() const;

	void nextTurn();

	bool isFinished();
};


#endif //INC_16_RIVIÈRE_CONTROLLER_H
