//
// Created by Nykros on 12.05.2016.
//

#ifndef INC_16_RIVIERE_BOAT_H
#define INC_16_RIVIERE_BOAT_H


#include "Container.h"
#include "Bank.h"

class Boat : public Container {
private:
	const Bank* currentBank;
public:
	Boat(const string& name, const Bank& bank) : Container(name), currentBank(&bank) { }

	const Bank* bank() const;
};


#endif //INC_16_RIVIÈRE_BOAT_H
