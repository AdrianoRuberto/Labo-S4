/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_14
 Fichier     : cstring.h
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 05.04.2106

 But         :  Cette classe définis une classe String en utilisant une approche
                orienté objet.

 ----------------------------------------------------------------------------------
 */

#ifndef CSTRING_H
#define CSTRING_H

#include <iostream>

using namespace std;

class String {
	friend ostream& operator<<(ostream& os, const String& str);
	friend istream& operator>>(istream& is, const String& str);

private:
	char* data;

public: // Constructeurs
	String();

	String(const char* const cstr);

	String(const String& str);

	String(const char chr);

	String(const int n);

	String(const double d);

	String(const bool b);

	~String();

public: // Surcharge des opérateurs
	bool operator==(const String& a) const;

	bool operator==(const char* const cstr) const;

	String operator+=(const String& str);

	String operator+=(const char* const cstr);

	String operator+(const String& str);

	String operator+(const char* const cstr);

	operator const char*();

	char* operator[](const size_t i);

	String operator=(const String& str);

	String operator=(const char* const cstr);

public: // Fonctions

	/**
	 *  @return la taille de la chaine de caractère sans '\0'
	 */
	const size_t size() const;

	/**
	 * Retourne l'adresse du caractère à l'indice donnée
	 * @param index l'index
	 * @return le caractère
	 */
	char* getChar(size_t index);

	/**
	 * Détermine si son état est égal à celui d’une autre chaîne de caractères
	 * @param cstr La chaîne de caractère
	 * @return true si l'état est égal, sinon false
	 */
	bool equal(const char* const cstr) const;

	/**
	 * Détermine si son état est égal à celui d’une autre instance de String
	 * @param cstr La chaîne de caractère
	 * @return true si l'état est égal, sinon false
	 */
	bool equal(const String& str) const;

	/**
	 *
	 */
	String append(const char c) const;

	String append(const char* const cstr) const;

	String append(const String& str) const;

	String impappend(const char c);

	String impappend(const char* const cstr);

	String impappend(const String& str);

	/**
	 * Retourne la sous-chaîne du string entre a et b, bornes incluses.
	 *
	 * Les indices d'une chaîne commence par 0.
	 *
	 * Si la borne supérieur est plus grande que la taille de la String, throw out_of_range
	 *
	 * @param a La borne inférieur
	 * @param b La borne supérieur
	 * @return la sous-chaîne
	 */
	char* getChars(const size_t a, const size_t b);

};

#endif	/* CSTRING_H */

