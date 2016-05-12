//
// Created by Nykros on 12.05.2016.
//

#ifndef INC_16_RIVIÈRE_CONTROLLER_H
#define INC_16_RIVIÈRE_CONTROLLER_H


#include "Person.h"

class Controller : Person {
private:
	int turn;
public:
	void showMenu();
	void display();
	void nextTurn();
};


#endif //INC_16_RIVIÈRE_CONTROLLER_H
