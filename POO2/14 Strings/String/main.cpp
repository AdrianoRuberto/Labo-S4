/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_14
 Fichier     : main.h
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 05.04.2106

 But         : Ce programme a pour but de mettre en oeuvre et tester toutes les
 *             fonctionnalitées relatives à la classe String

 ----------------------------------------------------------------------------------
 */
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include "cstring.h"

using namespace std;

int main() {

	cout << "Les tests se lisent comme suit :\nexpected | test" << endl;

	cout << "==============================" << endl;
	cout << "Constr. Chaine vide" << endl;
	String s;
	cout << setw(15) << "''" << " | '" << s << "'" << endl;

	cout << "==============================" << endl;
	cout << "Constr. Chaine de caracteres" << endl;
	const char* chars[] = {"123", "salut", "", "1", "It works !"};
	for (const char* cstr : chars)
		cout << setw(15) << cstr << " | " << String(cstr) << endl;

	cout << "==============================" << endl;
	cout << "Constr. instance String" << endl;
	String ss[] = {"123", "salut", "", "1", "It works !"};
	for (String& str : ss)
		cout << setw(15) << str << " | " << String(str) << endl;

	cout << "==============================" << endl;
	cout << "Constr. caractere" << endl;
	cout << setw(15) << 'c' << " | " << String('c') << endl;

	cout << "==============================" << endl;
	cout << "Constr. entier" << endl;
	int is[] = {123, -5, +5, 987654321};
	for (int i : is)
		cout << setw(15) << i << " | " << String(i) << endl;

	cout << "==============================" << endl;
	cout << "Constr. reel" << endl;
	double ds[] = {123.4, 123.45, -123.4, -123.45, 987.12341234, 123456789.123456789};
	for (double d : ds)
		cout << setw(15) << d << " | " << String(d) << endl;

	cout << "==============================" << endl;
	cout << "Constr. booleen" << endl;
	bool bs[] = {true, false};
	for (bool b : bs)
		cout << setw(15) << boolalpha << b << " | " << String(b) << endl;

	cout << "==============================" << endl;
	cout << "Fct. longueur" << endl;
	for (const char* cstr : chars)
		cout << setw(15) << strlen(cstr) << " | " << String(cstr).size() << endl;

	cout << "==============================" << endl;
	cout << "Repr. sous la forme const char*" << endl;
	cout << "Teste avec la fonction printf" << endl;
	for (const char* cstr : chars) {
		cout << setw(15) << cstr << " | ";
		printf(String(cstr));
		cout << endl;
	}

	cout << "==============================" << endl;
	cout << "Recuperation d'un char" << endl;
	String s2(1234);
	cout << setw(15) << 2 << " | " << *s2.getChar(1) << endl;
	char* c = s2.getChar(0);
	*c = 'a';
	cout << setw(15) << "a234" << " | " << s2 << endl;
	cout << setw(15) << "3" << " | " << *s2[2] << endl;

	cout << "==============================" << endl;
	cout << "Egaliter" << endl;
	String s3(1234);
	String s4("1234");
	String s5(1234.5);
	cout << setw(15) << true << " | " << s3.equal(s4) << endl;
	cout << setw(15) << true << " | " << (s3 == s4) << endl;
	cout << setw(15) << false << " | " << (s3 == s5) << endl;
	cout << setw(15) << false << " | " << (s3 != s4) << endl;
	cout << setw(15) << true << " | " << (s3 != s5) << endl;

	cout << "==============================" << endl;
	cout << "Affectation" << endl;
	s3 = s5;
	cout << setw(15) << s5 << " | " << s3 << endl;
	s3.ipappend('c');
	cout << setw(15) << s5 << " != " << s3 << endl;
	s4 = "abcd";
	cout << setw(15) << "abcd" << " | " << s4 << endl;

	cout << "==============================" << endl;
	cout << "Concatenation" << endl;
	String a("abc");
	String b("def");
	cout << "Avec une autre string" << endl;
	cout << setw(15) << "abcdef" << " | " << a.append(b) << endl;
	cout << setw(15) << "abc" << " | " << a << endl;
	cout << setw(15) << "abcdef" << " | " << a.ipappend(b) << endl;
	cout << setw(15) << "abcdef" << " | " << a << endl;
	cout << "Avec une chaine de caracteres" << endl;
	cout << setw(15) << "abcdefxyz123" << " | " << a.ipappend("xyz123") << endl;
	cout << setw(15) << "abcdefxyz123" << " | " << a << endl;
	cout << "Avec un caractere" << endl;
	cout << setw(15) << "abcdefxyz123c" << " | " << a.append('c') << endl;
	cout << setw(15) << "abcdefxyz123" << " | " << a << endl;
	cout << setw(15) << "abcdefxyz123d" << " | " << a.ipappend('d') << endl;
	cout << setw(15) << "abcdefxyz123d" << " | " << a << endl;

	cout << "========================" << endl;
	cout << "Extraction" << endl;
	String str("abcdef");
	cout << setw(15) << "Index is out of range | ";
	try {
		cout << str.getChars(3, 8) << endl;
	} catch (const out_of_range& oor) {
		cout << oor.what() << endl;
	}
	cout << setw(15) << "Index is out of range | ";
	try {
		cout << str.getChars(8, 8) << endl;
	} catch (const out_of_range& orr) {
		cout << orr.what() << endl;
	}
	cout << setw(15) << "bcdef" << " | " << str.getChars(1, 5) << endl;
	cout << setw(15) << "bcdef" << " | " << str.getChars(5, 1) << endl;
	cout << setw(15) << "a" << " | " << str.getChars(0, 0) << endl;

	cout << "========================" << endl;
	cout << "(Facultatif) lecture clavier" << endl;
	cout << "> ";
	String strIn;
	cin >> strIn;
	cout << "Vous avez ecris : " << strIn << endl;
	return EXIT_SUCCESS;
}