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

ostream& operator<<(ostream& os, const String& str) { return os << str.data; }

istream& operator>>(istream& is, const String& str) {
	// is.get();

	return is;
}
// Surcharge des opérateurs
bool String::operator==(const String& a) const { return equal(a); }

bool String::operator==(const char* const cstr) const { return equal(cstr); }

String String::operator+=(const String& str) { return impappend(str); }

String String::operator+=(const char* const cstr) { return impappend(cstr); }

String String::operator+(const String& str) { return append(str); }

String String::operator+(const char* const cstr) { return append(cstr); }

String::operator const char*() { return data; }

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
	data = new char[1];
	data[0] = '\0';
}

String::String(const char* const cstr) {
	this->data = new char[strlen(cstr) + 1];
	strcpy(data, cstr);
}

String::String(const String& str) {
	data = new char[str.size() + 1];
	strcpy(data, str.data);
}

String::String(const char chr) {
	data = new char[2];
	data[0] = chr;
	data[1] = '\0';
}

String::String(const int n) {
	const size_t size = (size_t) log10((n > 0 ? n : -n)) + 2 + (n < 0);
	data = new char[size];
	sprintf(data, "%d", n);
}

String::String(const double n) {
	char* tmp = new char[24];
	int nb = sprintf(tmp, "%.14g", n);
	data = new char[nb + 1];
	sprintf(data, "%.14g", n);
	delete[] tmp;
}

String::String(const bool b) { data = (char*) (b ? "true" : "false"); }

String::~String() { delete data; }

// Fonctions
const size_t String::size() const { return strlen(data); }

char* String::getChar(size_t index) {
	if (index > size())
		throw out_of_range("Index is out of range");
	return &data[index];
}

bool String::equal(const char* const cstr) const { return !strcmp(data, cstr); }

bool String::equal(const String& str) const { return equal(str.data); }

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

String String::impappend(const char* const cstr) {
	const char* tmp = data;
	// Alloue la nouvelle taille
	data = new char[size() + strlen(cstr) + 1];
	strcpy(data, tmp);
	strcat(data, cstr);
	delete tmp;
	return data;
}

String String::impappend(const char c) { return impappend(String(c).data); }

String String::impappend(const String& str) { return impappend(str.data); }

char* String::getChars(const size_t a, const size_t b) {
	if (a > b)
		return getChars(b, a);
	if (b > size())
		throw out_of_range("Index is out of range");

	const size_t chunk = b - a + 1;
	char* res = new char[chunk + 1];

	strncpy(res, data + a, chunk);
	res[chunk] = '\0';

	return res;
}


