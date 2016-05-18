//
// Created by Nykros on 12.05.2016.
//

#include <iostream>
#include "Controller.h"


void Controller::showMenu() const {
	cout << "p\t: afficher" << endl;
	cout << "e <nom>\t: embarquer <nom>" << endl;
	cout << "d <nom>\t: debarquer <nom>" << endl;
	cout << "m \t: deplacer bateau" << endl;
	cout << "r \t: reinitialiser" << endl;
	cout << "q \t: quitter" << endl;
	cout << "h \t: menu" << endl;

}

void Controller::display() const {
	string sep = "-----";
	string river = "======";
	cout << sep << endl;
	cout << _left->toString() << endl;
	cout << sep << endl; // TODO add boat

	cout << river << endl;

	cout << sep << endl;
	cout << _right->toString() << endl;
	cout << sep << endl;
}

void Controller::nextTurn() const {

}