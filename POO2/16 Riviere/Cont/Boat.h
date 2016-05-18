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
	const Bank* _current;
public:
	Boat(const string& name, const Bank& bank) : Container(name), _current(&bank) { }

	const Bank* current() const;

	string containsToString() const;

	void move(const Bank& other);

	bool canMove() const;

	bool canLoad() const;
};


#endif //INC_16_RIVIÈRE_BOAT_H
