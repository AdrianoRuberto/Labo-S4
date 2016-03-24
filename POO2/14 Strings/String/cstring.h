/*
 * File:   CString.h
 * Author: matthieu.villard
 *
 * Created on 10. mars 2016, 11:37
 */

#ifndef CSTRING_H
#define CSTRING_H

#include <iostream>
#include <math.h>

using namespace std;

class CString {
    friend ostream &operator<<(ostream &os, const CString &str);

    bool operator==(const CString &a) const;

    bool operator==(const char *const cstr) const;

    void operator+=(const char *const cstr);

public: // Constructeurs
    CString();

    CString(const char *const cstr);

    CString(const CString &str);

    CString(const char chr);

    CString(const int n);

    CString(const double d);

    CString(const bool b);

    ~CString();

public: // Fonctions

    /*
     *  @return la taille de la chaine de caractère sans '\0'
     */
    const size_t size() const;

    char &getChar(size_t index);

    bool equal(const char *const cstr) const;

    bool equal(const CString &str) const;

    CString append(const char c) const;

    CString append(const char *const cstr) const;

    CString append(const CString &str) const;

    void impappend(const char c);

    void impappend(const char *const cstr);

    void impappend(const CString &str);

    char *getChars(const size_t a,const size_t b);

    const char *toString() const;


private:
    char *c_str;
    // La taille de la chaine sans le '\0'
    size_t length;
};

#endif	/* CSTRING_H */

