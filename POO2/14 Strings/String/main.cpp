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
#include "cstring.h"

using namespace std;

int main() {
	cout << "========================\n";
	{
		String strs[] = {123, -987};
		for (String s : strs) {
			cout << s << endl;
		}
	}
	cout << "========================\n";
	{

		String strs[] = {123.4, 123.45, -123.4, -123.45, 987.12341234};
		for (String s : strs) {
			cout << s << endl;
		}
	}

	cout << "========================\n";
	{
		String str('a');
		cout << str << endl;
	}
	cout << "========================\n";
	{
		String tru(true);
		String fal(false);
		cout << tru << endl;
		cout << fal << endl;
	}
	cout << "========================\n";
	{
		String a("abc");
		String b("def");
		cout << a << endl << b << endl;
		cout << a.append(b) << endl;
		cout << a << endl;
		cout << a.impappend(b) << endl;
		cout << a << endl;
		a.impappend("xyz123");
		cout << a << endl;
		cout << a.append('c') << endl;
		cout << a.impappend('d') << endl;
		cout << a << endl;
	}
	cout << "========================\n";
	{
		String str("abcdef");
		try {
			cout << str.getChars(3, 8) << endl;
		} catch (const out_of_range& oor) {
			cout << oor.what() << endl;
		}
		try {
			cout << str.getChars(8, 8) << endl;
		} catch (const out_of_range& orr) {
			cout << orr.what() << endl;
		}
		cout << str.getChars(1, 5) << endl;
		cout << str.getChars(5, 1) << endl;
		cout << str.getChars(1, 1) << endl;
	}

	cout << "========================\n";
	{
		String str(12345);
		cout << str << endl;
		cout << str.getChar(3) << endl;
		char* c = str.getChar(4);
		*c = 'b';
		cout << str << endl;
	}
	return EXIT_SUCCESS;
}