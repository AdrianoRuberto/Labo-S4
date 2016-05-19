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
#include "Pers/Parent.h"
#include "Pers/Child.h"
#include "Pers/Cop.h"
#include "Pers/Thief.h"


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
				return;
			case 'm': // deplacer bateau
				try {
					_boat.move(_boat.current() == &_left ? _right : _left);
				} catch (const runtime_error& e) {
					cout << e.what() << endl;
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
				break;
		}
	} else if (input.length() > 2 && input[1] == ' ') {
		string name = input.substr(2);
		const Person* person = Person::find(_persons, name); // Récupère la personne
		if (person == nullptr) { // La personne n'a pas été trouvée
			cout << "### La personne " + name + " n'existe pas" << endl;
			return;
		} else {
			switch (input[0]) {
				case 'e': // embarquer <nom>
					load(*person);
					return;
				case 'd': // debarquer <nom>
					unload(*person);
					return;
				default:
					break;
			}
		}
	}

	cout << "### La commande " + input + " n'existe pas" << endl;
}

bool Controller::isFinished() {
	return _left.isEmpty() && _boat.isEmpty();
}

void Controller::reset() {
	// Déplace tout sur la rive de gauche
	turn = 0;
	_boat.move(_left);
	Container::load(_boat, _left);
	Container::load(_right, _left);
}

Controller::Controller() : _left("Gauche"), _right("Droite"), _boat("Bateau", _left) {
	Father* father = new Father();
	Mother* mother = new Mother();
	_persons.push_back(father);
	_persons.push_back(mother);
	_persons.push_back(new Boy("paul", *father, *mother));
	_persons.push_back(new Boy("pierre", *father, *mother));
	_persons.push_back(new Girl("julie", *father, *mother));
	_persons.push_back(new Girl("jeanne", *father, *mother));

	Cop* cop = new Cop();
	_persons.push_back(cop);
	_persons.push_back(new Thief(*cop));

	_left.load(_persons);
}

Controller::~Controller() {
	for (const Person* p : _persons)
		delete p;
}

void Controller::load(const Person& p) {
	try {
		Container::load(p, *_boat.current(), _boat);
		validation(p, *_boat.current(), _boat);
	} catch (const runtime_error& e) {
		cout << e.what() << endl;
	}

}

void Controller::unload(const Person& p) {
	try {
		Container::load(p, _boat, *_boat.current());
		validation(p, _boat, *_boat.current());
	} catch (const runtime_error& e) {
		cout << e.what() << endl;
	}
}

void Controller::validation(const Person& p, Container& source, Container& dest) {
	try{
		source.validation();
		dest.validation();
	}catch(const runtime_error& e){
		// Annule le mouvement en cas de non validation
		cout << e.what() << endl;
		Container::load(p, dest, source);
	}
}