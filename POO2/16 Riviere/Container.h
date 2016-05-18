//
// Created by Nykros on 12.05.2016.
//

#ifndef INC_16_RIVIERE_CONTAINER_H
#define INC_16_RIVIERE_CONTAINER_H

#include <string>
#include <list>
#include "Pers/Person.h"

using namespace std;

class Container {
private:
	string _name;
	list<const Person*> _contains;
protected:
	Container(const string& name, const list<const Person*>& contains = list<const Person*>()) : _name(name),
	                                                                                 _contains(contains) { }

public:

	/**
	 * Déplace la personne du container source au container destination
	 * @param Person    p       la personne
	 * @param Container source  La source
	 * @param Container dest    La destination
	 * @throw
	 */
	static void move(const Person& p, Container& source, Container& dest);
	bool contain(const Person& p) const;
	bool isEmpty() const;
	virtual string toString() const;
	virtual string containsToString() const;

};


#endif //INC_16_RIVIERE_CONTAINER_H
