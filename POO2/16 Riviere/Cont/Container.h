//
// Created by Nykros on 12.05.2016.
//

#ifndef INC_16_RIVIERE_CONTAINER_H
#define INC_16_RIVIERE_CONTAINER_H

#include <string>
#include <list>
#include "../Pers/Person.h"

using namespace std;

class Container {
private:
	string _name;
protected:
	list<const Person*> _contains;

	Container(const string& name) : _name(name) { }

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
	 * Déplace toutes les personnes contenues par le container vers la destination
	 *
	 * @param dest la destination
	 */
	void moveAll(Container& dest);

	/**
	 * Embarque toutes les personnes dans le containers
	 *
	 * @param persons les personnes à embarquer
	 */
	void load(const list<const Person*> persons);

	bool contain(const Person& p) const;

	bool isEmpty() const;

	virtual string toString() const;

	virtual string name() const;

	virtual string containsToString() const;

	virtual bool canLoad() const = 0;

};


#endif //INC_16_RIVIERE_CONTAINER_H
