/*
 * File:   CString.h
 * Author: matthieu.villard
 *
 * Created on 10. mars 2016, 11:37
 */

#ifndef CSTRING_H
#define CSTRING_H

#include <iostream>

using namespace std;

class String {
    friend ostream& operator<<(ostream& os, const String& str);

private:
    char* data;

public: // Surcharge des opérateurs
    bool operator==(const String& a) const;

    bool operator==(const char* const cstr) const;

    String operator+=(const String& a);

    String operator+=(const char* const cstr);

    operator const char*() const;

public: // Constructeurs
    String();

    String(const char* const cstr);

    String(const String& str);

    String(const char chr);

    String(const int n);

    String(const double d);

    String(const bool b);

    ~String();

public: // Fonctions

    /*
     *  @return la taille de la chaine de caractère sans '\0'
     */
    const size_t size() const;

    char& getChar(size_t index);

    bool equal(const char* const cstr) const;

    bool equal(const String& str) const;

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

