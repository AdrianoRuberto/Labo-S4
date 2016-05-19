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

class Container;

using namespace std;

class Person {
private:
	string _name;

public:
	Person(const string& name) : _name(name){};

	/**
	 * @return true si la personne peut conduire
	 */
	virtual bool canDrive() const = 0;

	/**
	 *@return le nom de la personne
	 */
	string name() const { return _name;}

	/**
	 * Valide le container par rapport à la personne concernée, à redéfinir dans les sous-classes si nécessaire
	 * @param container le container
	 * @throw runtime_error en cas de non validation
	 */
	virtual void validation(const Container& container) const { }
};


#endif //INC_16_RIVIÈRE_PERSON_H