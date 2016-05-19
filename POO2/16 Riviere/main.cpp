/**
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_16
 Fichier     : main.cpp
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 18.05.2016
 But         : Permet d'avoir une boucle de jeu pour le jeu de la rivière
 ----------------------------------------------------------------------------------
 */
#include <cstdlib>
#include <iostream>
#include "Controller.h"

int main() {
	Controller controller;
	controller.showMenu();
	controller.display();
	while(!controller.isFinished()){
		controller.nextTurn();
	}

	cout << "Felicitation !" << endl;
	return EXIT_SUCCESS;
}