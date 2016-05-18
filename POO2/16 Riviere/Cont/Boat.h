//
// Created by Nykros on 12.05.2016.
//

#ifndef INC_16_RIVIERE_BOAT_H
#define INC_16_RIVIERE_BOAT_H


#include "Container.h"
#include "Bank.h"

class Boat : public Container {
private:
	const size_t MAX_LOAD = 2;
	Bank* _current;
public:
	Boat(const string& name, Bank& bank) : Container(name), _current(&bank) { }

	Bank* current() const;

	string containsToString() const;

	void move(Bank& other);

	bool canMove() const;

	void load(const Person& p);
};


#endif //INC_16_RIVIÈRE_BOAT_H
