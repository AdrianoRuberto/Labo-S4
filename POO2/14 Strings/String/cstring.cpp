/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_14
 Fichier     : cstring.cpp
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 05.04.2106
 -----------------------------------------------------------------------------------
 */
#include <string.h>
#include <stdio.h>
#include <stdexcept>
#include <math.h>

#include "cstring.h"

ostream& operator<<(ostream& os, const String& str) { return str.print(os); }

// Surcharge des opérateurs
bool String::operator==(const String& a) const { return equal(a); }

bool String::operator==(const char* const cstr) const { return equal(cstr); }

String String::operator+=(const String& str) { return ipappend(str); }

String String::operator+=(const char* const cstr) { return ipappend(cstr); }

String String::operator+(const String& str) const { return append(str); }

String String::operator+(const char* const cstr) const { return append(cstr); }

String::operator const char*() { return toCharArray(); }

char* String::operator[](const size_t i) { return getChar(i); }

String String::operator=(const String& str) {
	if (this == &str) // Affectation à lui même
		return *this;

	data = new char[str.size() + 1];
	strcpy(data, str.data);
	return *this;
}

String String::operator=(const char* const cstr) {
	data = new char[strlen(cstr) + 1];
	strcpy(data, cstr);
	return *this;
}

// Constructeurs
String::String() {
	data = '\0';
}

String::String(const char* const cstr) {
	data = new char[strlen(cstr) + 1];
	strcpy(data, cstr);
}

String::String(const String& str) {
	data = new char[str.size() + 1];
	strcpy(data, str.data);
}

String::String(const char chr) {
	data = new char[2];
	sprintf(data, "%c", chr);
}

String::String(const int n) {
	data = new char[(size_t) log10((n > 0 ? n : -n)) + 2 + (n < 0)];
	sprintf(data, "%d", n);
}

String::String(const double d) {
	// Le nombre de caractères maximum que peut prendre un double avec le formatage %g est de 12
	data = new char[13];
	sprintf(data, "%g", d);
}

String::String(const bool b) {
	data = (char*) (b ? "true" : "false");
}

String::~String() { delete data; }

// Fonctions
const size_t String::size() const { return strlen(data); }

const char* String::toCharArray() const { return getChars(0, size()); }

char* String::getChar(size_t index) {
	if (index > size()) throw out_of_range("Index is out of range");
	return &data[index];
}

bool String::equal(const char* const cstr) const { return !strcmp(data, cstr); }

bool String::equal(const String& str) const {
	if (&str == this) return true;
	return equal(str.data);
}

String String::append(const char* const cstr) const {
	char* tmp = new char[size() + strlen(cstr) + 1];
	strcpy(tmp, data);
	strcat(tmp, cstr);
	String res(tmp);
	delete tmp;
	return res;
}

String String::append(const char c) const { return append(String(c)); }

String String::append(const String& str) const { return append(str.data); }

String String::ipappend(const char* const cstr) {
	const char* tmp = data;
	data = new char[size() + strlen(cstr) + 1];
	strcpy(data, tmp);
	strcat(data, cstr);
	delete tmp;
	return data;
}

String String::ipappend(const char c) { return ipappend(String(c).data); }

String String::ipappend(const String& str) { return ipappend(str.data); }

const char* String::getChars(const size_t a, const size_t b) const {
	if (a > b) return getChars(b, a);
	if (b > size())	throw out_of_range("Index is out of range");

	const size_t chunk = b - a + 1;
	char* res = new char[chunk + 1];

	strncpy(res, data + a, chunk);
	res[chunk] = '\0';

	return res;
}

ostream& String::print(ostream& os) const {
	return os << data;
}