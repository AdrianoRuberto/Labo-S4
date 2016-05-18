/**
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_16
 Fichier     : Boat.h
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 18.05.2016
 But         : Cette classe définit un bateau, avec une capacité maximum
 ----------------------------------------------------------------------------------
 */

#ifndef INC_16_RIVIERE_BOAT_H
#define INC_16_RIVIERE_BOAT_H


#include "Container.h"
#include "Bank.h"

class Boat : public Container {
private:
	const size_t MAX_LOAD = 2;
	Bank* _current;
public:
	Boat(const string& name, Bank& bank) : Container(name), _current(&bank) { }

	/**
	 * @return la rive courante
	 */
	Bank* current() const;

	/**
	 * @return appel le parent mais rajoute < > au tour
	 */
	string containsToString() const;

	/**
	 * Déplace le bateau sur l'autre rive
	 * @param other l'autre rive
	 */
	void move(Bank& other);

	/**
	 * appel le parent s'il y'a assez de place sur le bateau
	 * @param p la personne à embarquer
	 */
	void load(const Person& p);
};


#endif //INC_16_RIVIÈRE_BOAT_H
