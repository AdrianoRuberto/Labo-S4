/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_15
 Fichier     : main.cpp
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 20.04.2016
 But         : Cette classe permet de tester la classe contenu dans le fichier List.h
 ----------------------------------------------------------------------------------
 */

#include <cstdlib>
#include <iostream>
#include "List.h"

using namespace std;

class Personne {
public:
	virtual string whatIAm() { return "Personne"; }
};

class Etudiant : public Personne {
public:
	string whatIAm() { return "Etudiant"; }
};

int main() {
	const string sep = "=========================================";
	cout << "attendu | calcule" << endl;
	List<string> vide;
	List<string> oneTwoThree;
	oneTwoThree.append("un").append("deux").append("trois");

	cout << sep << endl;
	cout << "Constructeur sans parametres" << endl;
	cout << "[] | [" << vide << "]" << endl;

	cout << sep << endl;
	cout << "Constructeur de copie" << endl;
	List<string> s2(oneTwoThree);
	cout << oneTwoThree << " | " << s2 << endl;

	cout << sep << endl;
	cout << "Surcharge de l'operateur =" << endl;
	List<string> tmp;
	tmp = oneTwoThree;
	cout << oneTwoThree << " | " << tmp << endl;

	cout << sep << endl;
	cout << "Surcharge de l'operateur []" << endl;
	cout << "un | " << oneTwoThree[0] << endl;
	cout << "deux | " << oneTwoThree[1] << endl;
	cout << "trois | " << oneTwoThree[2] << endl;
	oneTwoThree[0] = "zero";
	cout << "zero | " << oneTwoThree[0] << endl;
	oneTwoThree[0] = "un";
	try {
		cout << "index is out of range | ";
		oneTwoThree[3];
	} catch (const out_of_range& oor) {
		cout << oor.what() << endl;
	}

	cout << sep << endl;
	cout << "Methode size()" << endl;
	cout << "0 | " << vide.size() << endl;
	cout << "3 | " << oneTwoThree.size() << endl;

	cout << sep << endl;
	cout << "Methode remove(int index)" << endl;
	cout << "un trois | " << tmp.remove(1) << endl;
	cout << "un | " << tmp.remove(1) << endl;
	cout << "[] | [" << tmp.remove(0) << "]" << endl;


	cout << sep << endl;
	cout << "Methode remove(T o)" << endl;
	tmp = oneTwoThree;
	string s("deux");
	cout << "un trois | " << tmp.remove(s) << endl;
	s = "Pas la";
	cout << "un trois | " << tmp.remove(s) << endl;
	s = "trois";
	cout << "un | " << tmp.remove(s) << endl;
	s = "un";
	cout << "[] | [" << tmp.remove(s) << "]" << endl;

	cout << sep << endl;
	cout << "Methode find(T o)" << endl;
	cout << "deux | " << *oneTwoThree.find("deux") << endl;
	cout << boolalpha << "true | " << (oneTwoThree.find("abcdef") == oneTwoThree.end()) << endl;

	cout << sep << endl;
	cout << "Liaison dynamique" << endl;
	List<Personne*> ps;
	ps.append(new Personne()).append(new Etudiant()).append(nullptr).append(new Personne());
	cout << "Personne Etudiant Personne | ";
	for (auto it = ps.begin(); it != ps.end(); ++it){
		if(*it != nullptr)
			cout << (*it)->whatIAm() << " ";

	}
	cout << endl;
	return 0;
}