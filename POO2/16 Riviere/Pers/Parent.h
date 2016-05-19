/**
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_16
 Fichier     : Parent.cpp
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 18.05.2016
 But         : Cette classe représente un parent abstrait ainsi qu'un père et une mère
 ----------------------------------------------------------------------------------
 */

#ifndef INC_16_RIVIERE_PARENT_H
#define INC_16_RIVIERE_PARENT_H

#include "FamilyMember.h"

class Parent : public FamilyMember {
protected:
	Parent(const string& name) : FamilyMember(name) { }

public:
	bool canDrive() const;

	void accept(Dispatcher& dispatcher) const;
};

class Father : public Parent {
public:
	Father(const string& name) : Parent(name) { }

	void accept(Dispatcher& dispatcher) const;
};

class Mother : public Parent {
public:
	Mother(const string& name) : Parent(name) { }

	void accept(Dispatcher& dispatcher) const;
};


#endif //INC_16_RIVIERE_PARENT_H
