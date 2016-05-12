//
// Created by Nykros on 12.05.2016.
//

#ifndef INC_16_RIVIERE_PERSON_H
#define INC_16_RIVIERE_PERSON_H

#include <string>

using namespace std;

class Person {
private:
	string name;

public:
	virtual bool canDrive();
};


#endif //INC_16_RIVIÈRE_PERSON_H
