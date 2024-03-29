/**
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_16
 Fichier     : Controller.h
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 18.05.2016
 But         : Cette classe définit un controller pour le jeu : Traverser la rivière
               Le but du jeu est de déplacer toutes les personnes de la rive gauche
               sur la rive droite en respectant les règles suivantes :
				• Il ne peut y avoir que 2 personnes au maximum sur le bateau.
				• Les enfants et le voleur ne peuvent piloter le bateau (mais peuvent
				  y monter lorsqu’il est à quai).
				• Le voleur ne peut pas rester en contact avec un membre de la famille
				  si le policier n'est pas présent.
				• Les fils ne peuvent pas rester seuls avec leur mère si le père n’est
				  pas présent.
				• Les filles ne peuvent pas rester seules avec leur père si la mère
				  n’est pas présente.
 ----------------------------------------------------------------------------------
 */

#ifndef INC_16_RIVIERE_CONTROLLER_H
#define INC_16_RIVIERE_CONTROLLER_H

#include <list>
#include "Pers/Person.h"
#include "Cont/Boat.h"

class Controller {
private:
	int turn = 0;
	Bank _left;
	Bank _right;
	Boat _boat;
	list<const Person*> _persons;

	/**
	 * Réinitialise le jeu
	 */
	void reset();

	/**
	 * Permet de valider un déplacement, si le déplacement n'est pas valide, remet la personne dans la destination
	 *
	 * @param p         La personne
	 * @param source    La source
	 * @param dest      La destination
	 */
	void validation(const Person& p, Container& source, Container& dest);

	/*
	 * Déplace si trouvé dans source la personne dans la destination
	 * @param name      Le nom de la personne
	 * @param source    la source
	 * @param dest      la destination
	 */
	void load(const string& name, Container& source, Container& dest);

public:
	/*
	 * Créer les personnes et les rajoutes à la rive de gauche
	 */
	Controller();

	/*
	 * Détruit les personnes
	 */
	~Controller();

	/*
	 * Montre le menu
	 */
	void showMenu() const;

	/**
	 * Montre l'état actuel du jeu
	 */
	void display() const;

	/**
	 * Lis l'entrée utilisateur et fait la commande associée
	 */
	void nextTurn();

	/**
	 * Permet de savoir si le jeu est terminé. Le jeu est terminé quand la rive gauche ainsi que le bateau sont vide
	 */
	bool isFinished();

};


#endif //INC_16_RIVIÈRE_CONTROLLER_H
