/**
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_16
 Fichier     : Child.h
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 18.05.2016
 But         : Cette classe représente un enfant, ainsi qu'un garçon et une fille
 ----------------------------------------------------------------------------------
 */

#ifndef INC_16_RIVIERE_ENFANTS_H
#define INC_16_RIVIERE_ENFANTS_H


#include "Person.h"
#include "Parent.h"

class Child : public FamilyMember {

public:
	Child(const string& name) : FamilyMember(name) { }

	bool canDrive() const;
};

class Girl : public Child {
public:
	Girl(const string& name) : Child(name) { }
};

class Boy : public Child {

public:
	Boy(const string& name) : Child(name) { }
};


#endif //INC_16_RIVIERE_ENFANTS_H
