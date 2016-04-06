/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_14
 Fichier     : cstring.h
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 05.04.2106

 But         :  Cette classe définis une classe String en utilisant une approche
                orienté objet.
                La String est implémentée en utilisant un pointeur sur un tableau de
                char contenant les données de la String. Ce tableau a toujours le
                termine toujours pas le code nul ('\0')

 ----------------------------------------------------------------------------------
 */

#ifndef CSTRING_H
#define CSTRING_H

#include <iostream>

using namespace std;

class String {
	friend ostream& operator<<(ostream&, const String&);

	friend istream& operator>>(istream&, String&);

private:
	char* data;

public: // Constructeurs
	String();

	String(const char* cstr);

	String(const String& str);

	String(const char chr);

	String(const int n);

	// Va formater en utilisant le specifier %g
	String(const double d);

	String(const bool b);

	~String();

public: // Surcharge des opérateurs

	bool operator==(const char* const) const;

	bool operator!=(const char* const) const;

	String& operator+=(const char* const);

	String& operator+=(const char);

	String operator+(const char* const) const;

	String operator+(const char) const;

	operator const char*() const;

	char* operator[](const int);

	String operator=(const char* const);

	String operator=(const String&);

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
	 * @param cstr La chaîne de caractères
	 * @return true si l'état est égal, sinon false
	 */
	bool equal(const String& str) const;

	/**
	 * Affecte la chaîne de caractères à la string courrante
	 * @param cstr la chaîne de caractères
	 * @return la string
	 */
	String set(const char* const cstr);

	/**
	 * Affecte les données de la string à la string courrante.
	 * @param str La string avec les données a copié
	 * @return la string
	 */
	String set(const String& str);

	/**
	 * Créer une nouvelle string qui est le résutlat de la concaténation des données de la string actuel avec un
	 * caractère
	 * @param c Le caractère
	 * @return La nouvelle string concaténée
	 */
	String append(const char c) const;

	/**
	 * Créer une nouvelle string qui est le résultat de la concaténation des données de la string actuel avec une
	 * chaîne de caractères
	 * @param cstr La chaîne de caractère
	 * @return La nouvelle string concaténée
	 */
	String append(const char* const cstr) const;

	/**
	 * Créer une nouvelle string qui est le résultat de la concaténation des données de la string actuel avec la
	 * string passée en paramètre
	 * @param str L'autre string
	 * @return La nouvelle string concaténée
	 */
	String append(const String& str) const;

	/**
	 * Concatène avec un caractère
	 * @param c Le caractère
	 * @return La string concaténée
	 */
	String& ipappend(const char c);

	/**
	 * Concatène avec une chaine de caractères
	 * @param cstr La chaîne de caractères
	 * @return La string concaténée
	 */
	String& ipappend(const char* const cstr);

	/**
	 * Concatène avec la string passée en paramètre
	 * @param str la string
	 * @return La string concaténée
	 */
	String& ipappend(const String& str);

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
	const char* getChars(const size_t a, const size_t b) const;

	/**
	 * Écris la string sur le flux donné
	 * @return le flux
	 */
	ostream& print(ostream& os) const;

	/**
	 * Consume et écris les donnés du flux
	 * @return le flux
	 */
	istream& read(istream& is);
};

#endif	/* CSTRING_H */