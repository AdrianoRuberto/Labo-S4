/**
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_16
 Fichier     : Controller.cpp
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 18.05.2016
 ----------------------------------------------------------------------------------
 */

#include <iostream>
#include <cstdlib>
#include <stdexcept>
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
	if (_boat.current() == &_left) cout << _boat.toString() << endl << river << endl;
	else cout << river << endl << _boat.toString() << endl;

	cout << sep << endl;
	cout << _right.toString() << endl;
	cout << sep << endl;
}

void Controller::nextTurn() {
	cout << turn++ << "> ";
	string input;
	getline(cin, input);
	if (input.length() == 1) {
		switch (input[0]) {
			case 'p': // afficher
				display();
				nextTurn();
				return;
			case 'm': // deplacer bateau
				try {
					_boat.move(_boat.current() == &_left ? _right : _left);
				} catch (const runtime_error& e) {
					cout << e.what() << endl;
					nextTurn();
				}
				return;
			case 'r': // reinitialiser
				reset();
				return;
			case 'q':
				exit(EXIT_SUCCESS);
			case 'h': // menu
				showMenu();
				return;
			default:
				cmdNotFound();
				return;
		}
	} else if (input.length() > 2 && input[1] == ' ') {
		string name = input.substr(2);
		const Person* person = Person::find(_persons, name); // Récupère la personne
		if (person == nullptr) { // La personne n'a pas été trouvée
			cout << "La personne " + name + " n'existe pas" << endl;
			nextTurn();
		} else {
			switch (input[0]) {
				case 'e': // embarquer <nom>
					Container::move(*person, *_boat.current(), _boat);
					return;
				case 'd': // debarquer <nom>
					Container::move(*person, _boat, *_boat.current());
					return;
				default:
					cmdNotFound();
					return;
			}
		}
	} else {
		cmdNotFound();
	}
}

bool Controller::isFinished() {
	return _left.isEmpty() && _boat.isEmpty();
}

void Controller::cmdNotFound() {
	cout << "# La commande n'existe pas" << endl;
	nextTurn();
}

void Controller::reset() {
	// Déplace tout sur la rive de gauche
	Container::move(_boat, _left);
	Container::move(_right, _left);
}

Controller::Controller() : _left("Gauche"), _right("Droite"), _boat("Bateau", _left) {
	_persons.push_back(new Father("pere"));
	_persons.push_back(new Mother("mere"));
	_persons.push_back(new Boy("paul"));
	_persons.push_back(new Boy("pierre"));
	_persons.push_back(new Girl("julie"));
	_persons.push_back(new Girl("jeanne"));
	_persons.push_back(new Cop("policier"));
	_persons.push_back(new Thief("voleur"));
	_left.load(_persons);
}

Controller::~Controller() {
	for(const Person* p : _persons)
		delete p;
}