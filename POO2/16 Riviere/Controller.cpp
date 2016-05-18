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
	string sep = "";
	string river = "";
	for (int i = 0; i < 60; ++i) {
		sep += "-";
		river += "=";
	}

	cout << sep << endl;
	cout << _left.toString() << endl;
	cout << sep << endl;
	if (_boat.bank() == &_left) cout << _boat.toString() << endl << river << endl;
	else cout << river << endl << _boat.toString() << endl;

	cout << sep << endl;
	cout << _right.toString() << endl;
	cout << sep << endl;
}

void Controller::nextTurn() {
	cout << turn++ << "> ";
	string input;
	getline(cin, input);
	cout << input << endl;
}

bool Controller::isFinished() {
	return _left.isEmpty() && _boat.isEmpty();
}