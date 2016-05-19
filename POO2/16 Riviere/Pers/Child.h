/**
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_16
 Fichier     : Child.h
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 18.05.2016
 But         : Ce fichier implémente 3 classes représentant chacun :
               - un enfant abstrait
               - un garçon
               - une fille
 ----------------------------------------------------------------------------------
 */

#ifndef INC_16_RIVIERE_ENFANTS_H
#define INC_16_RIVIERE_ENFANTS_H


#include "Person.h"
#include "Parent.h"

class Child : public Person {
protected:
	const Parent* _father;
	const Parent* _mother;
	Child(const string& name, const Parent& father, const Parent& mother)
			: Person(name), _father(&father), _mother(&mother) { }

public:
	bool canDrive() const;
};

class Girl : public Child {
public:
	Girl(const string& name, const Parent& father, const Parent& mother) : Child(name, father, mother) { }

	/**
	 * Valide uniquement s'elles ne sont pas seules avec leur père et que leur mère n’est pas présente
	 */
	void validation(const Container& container) const;

};

class Boy : public Child {
public:
	Boy(const string& name, const Parent& father, const Parent& mother) : Child(name, father, mother) { }

	/**
	 * Valide uniquement s'ils ne sont pas seuls avec leur mère et que leur père n’est pas présent
	 */
	void validation(const Container& container) const;
};


#endif //INC_16_RIVIERE_ENFANTS_H
