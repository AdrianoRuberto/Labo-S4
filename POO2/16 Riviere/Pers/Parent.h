//
// Created by Nykros on 17.05.2016.
//

#ifndef INC_16_RIVIERE_PARENT_H
#define INC_16_RIVIERE_PARENT_H


#include "Person.h"

class Parent : public Person {
protected:
	Parent(const string& name) : Person(name) { }

public:
	bool canDrive() const;

};

class Father : public Parent {
public:
	Father(const string& name) : Parent(name) { }

};

class Mother : public Parent {
public:
	Mother(const string& name) : Parent(name) { }

};


#endif //INC_16_RIVIERE_PARENT_H
