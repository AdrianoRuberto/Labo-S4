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

class Child : public Person {
protected:
	const Father* _father;
	const Mother* _mother;
public:
	Child(const string& name, const Father& father, const Mother& mother)
			: Person(name), _father(&father), _mother(&mother) { }

	bool canDrive() const;
};

class Girl : public Child {
public:

	Girl(const string& name, const Father& father, const Mother& mother) : Child(name, father, mother) { }

	void validation(const Container& container) const;

};

class Boy : public Child {
public:

	Boy(const string& name, const Father& father, const Mother& mother) : Child(name, father, mother) { }

	void validation(const Container& container) const;
};


#endif //INC_16_RIVIERE_ENFANTS_H
