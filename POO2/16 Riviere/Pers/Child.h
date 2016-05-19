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
#include <stdexcept>
#include "../Cont/Container.h"

class Child : public Person {
protected:
	const Father* _father;
	const Mother* _mother;

	Child(const string& name, const Father& father, const Mother& mother)
			: Person(name), _father(&father), _mother(&mother) { }

public:
	bool canDrive() const { return false; }
};

class Girl : public Child {
public:
	Girl(const string& name, const Father& father, const Mother& mother) : Child(name, father, mother) { }

	/**
	 * Valide uniquement si elles ne sont pas seules avec leur père et que leur mère n’est pas présente
	 */
	void validation(const Container& container) const {
		if (container.contain(*_father) && !container.contain(*_mother))
			throw runtime_error(
					"La fille " + name() + " ne peut pas rester seule avec son pere car sa mere n'est pas la");
	}

};

class Boy : public Child {
public:
	Boy(const string& name, const Father& father, const Mother& mother) : Child(name, father, mother) { }

	/**
	 * Valide uniquement s'ils ne sont pas seuls avec leur mère et que leur père n’est pas présent
	 */
	void validation(const Container& container) const {
		if (container.contain(*_mother) && !container.contain(*_father))
			throw runtime_error(
					"Le garcon " + name() + " ne peut pas rester seul avec sa mere car son pere n'est pas la");
	}
};


#endif //INC_16_RIVIERE_ENFANTS_H
