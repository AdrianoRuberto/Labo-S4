/**
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_16
 Fichier     : Container.h
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 18.05.2016
 But         : Ce fichier définit une classe container abstraite ainsi qu'une rive
 ----------------------------------------------------------------------------------
 */

#ifndef INC_16_RIVIERE_CONTAINER_H
#define INC_16_RIVIERE_CONTAINER_H

#include <string>
#include <list>

class Person;

using namespace std;

class Container {
private:
	string _name;

protected:
	list<const Person*> _contains;

	Container(const string& name);

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

	/*
	 * Débarque la personne du container
	 *
	 * @param p La personne
	 */
	virtual void unload(const Person& p);

	/**
	 * Embarque toutes les personnes vers la destination
	 * @param dest Le container de destination
	 */
	virtual void load(Container& dest);

	/**
	 * @param p la personne
	 * @return true si le container à la personne à charge
	 */
	bool contain(const Person& p) const;

	/**
	 * Cherche une personne dans le container
	 * @param name Le nom de la personne à chercher
	 * @return la personne si elle est trouvée, sinon retourn nullptr
	 */
	const Person* find(const string& name) const;

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

	/**
	 * @return le nombre de personne géré par le container
	 */
	size_t size() const;
	
};

class Bank : public Container {
public:
	Bank(const string& name) : Container(name) { };
};

#endif //INC_16_RIVIERE_CONTAINER_H