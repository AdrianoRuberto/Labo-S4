/**
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_16
 Fichier     : Container.h
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 18.05.2016
 But         : Cette classe définit un container abstrait
 ----------------------------------------------------------------------------------
 */

#ifndef INC_16_RIVIERE_CONTAINER_H
#define INC_16_RIVIERE_CONTAINER_H

#include <string>
#include <list>
#include "../Pers/Person.h"

class Dispatcher;
class Person;

using namespace std;

class Container {
private:
	string _name;
protected:
	list<const Person*> _contains;

	Container(const string& name) : _name(name) { }

	/**
	 * @return le nom du container
	 */
	virtual string name() const;

	/**
	 * @return les personnes contenues sous formes de string
	 */
	virtual string containsToString() const;

public:

	/**
	 * Déplace la personne du container source au container destination
	 *
	 * @param p       la personne
	 * @param source  La source
	 * @param dest    La destination
	 * @throw
	 */
	static void move(const Person& p, Container& source, Container& dest);

	/**
	 * Déplace toutes les personnes de source à destination
	 *
	 * @param source    la source
	 * @param dest      la destination
	 */
	static void move(Container& source, Container& dest);

	/**
	 * Embarque toutes les personnes dans le container
	 *
	 * @param persons les personnes à embarquer
	 */
	void load(const list<const Person*>& persons);

	/**
	 * Embarque une personne dans le container
	 *
	 * @param p la personne
	 */
	virtual void load(const Person& p);

	/**
	 * @param p la personne
	 * @return true si le container à la personne à charge
	 */
	bool contain(const Person& p) const;

	/**
	 * @return true si le container ne gère personne
	 */
	bool isEmpty() const;

	/**
	 * @return une représentation textuelle du container
	 */
	virtual string toString() const;

	/**
	 * Valide l'état actuel du container
	 * @throw runtime_error si ce n'est pas valide
	 */
	void validation() const;

	void accept(Dispatcher& dispatcher) const;

};


#endif //INC_16_RIVIERE_CONTAINER_H
