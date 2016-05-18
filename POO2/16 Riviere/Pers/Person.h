/**
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_16
 Fichier     : Person.h
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 18.05.2016
 But         : Cette classe définit une personne abstraite
 ----------------------------------------------------------------------------------
 */


#ifndef INC_16_RIVIERE_PERSON_H
#define INC_16_RIVIERE_PERSON_H

#include <string>
#include <list>

using namespace std;

class Person {
private:
	string _name;

public:
	Person(const string& name) : _name(name) { }

	/**
	 * @return true si la personne peut conduire
	 */
	virtual bool canDrive() const = 0;

	// virtual bool canBeWith(const list<Person*> persons) const = 0;

	/**
	 *@return le nom de la personne
	 */
	string name() const;

	/**
	 * @param persons   La liste de personne dans laquelle chercher
	 * @param name      Le nom de la personne à chercher
	 * @return la personne si elle est trouvée, sinon retourn nullptr
	 */
	static const Person* find(const list<const Person*>& persons, const string name);
};


#endif //INC_16_RIVIÈRE_PERSON_H
