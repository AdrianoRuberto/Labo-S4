/*
 * File:   CString.cpp
 * Author: Matthieu Villard
 * Author: Adriano Ruberto
 *
 * Created on 10. mars 2016, 11:37
 */

#include <stdlib.h>
#include <stdexcept>
#include <cstring>

#include "cstring.h"

typedef unsigned long long ullong;

ostream &operator<<(ostream &os, const CString &str) {
    os << str.c_str;
    return os;
}

CString::CString() {
    c_str = new char[1];
    c_str[0] = '\0';
    length = 1;
}

CString::CString(const char *cstr) {
    length = strlen(cstr);
    this->c_str = new char[length + 1];
    strcpy(c_str, cstr);
}

CString::CString(const CString &str) {
    c_str = new char[str.length + 1];
    length = str.length;
    strcpy(c_str, str.c_str);
}

CString::CString(const char chr) {
    c_str = new char[2];
    c_str[0] = chr;
    c_str[1] = '\0';
    length = 1;
}

CString::CString(const int n) {
    size_t size;
    if (n < 0)
        size = 3 + log(-n) / log(10);
    else
        size = 2 + log(n) / log(10);
    c_str = new char[size];
    c_str[size - 1] = '\0';

    const char FIRST_DIGIT = '0';
    int pos = size - 2;
    int rest = abs(n);
    do {
        const int mod = rest % 10;
        c_str[pos--] = FIRST_DIGIT + mod;
        rest /= 10;
    } while (rest != 0);
    if (n < 0)
        c_str[pos] = '-';
}

CString::CString(const double n) {
    throw runtime_error("Not implemented");
}

CString::CString(const bool b) {
    throw runtime_error("Not implemented");
}

CString::~CString() {
    delete c_str;
}

const size_t CString::size() const {
    return strlen(c_str);
}

const char *CString::toString() const {
    return c_str;
}

char &CString::getChar(size_t index) {
    if (index > size())
        throw out_of_range("Index is out of range");

    return c_str[index];
}

bool CString::equal(const char *const cstr) const {
    for (int i = 0; true; ++i) {
        if (cstr == '\0' || c_str == '\0') {
            if (cstr == '\0' && c_str == '\0')
                return true;
            else return false;
        }
        if (cstr[i] != c_str[i])
            return false;
    }
}

bool CString::equal(const CString &str) const {
    return equal(str.c_str);
}

bool CString::operator==(const CString &a) const {
    return equal(a);
}

bool CString::operator==(const char *const cstr) const {
    return equal(cstr);
}

void CString::operator+=(const char *const cstr) {
    throw runtime_error("Not implemented");
}

CString CString::append(const char c) const {
    throw runtime_error("Not implemented");
}

CString CString::append(const char *const cstr) const {
    throw runtime_error("Not implemented");
}

CString CString::append(const CString &str) const {
    throw runtime_error("Not implemented");
}

void CString::impappend(const char *const cstr) {
    const char *tmp = c_str;
    c_str = new char[size() + strlen(cstr) + 1];
    strcpy(c_str, tmp);
    strcat(c_str, cstr);
    delete tmp;
}

void CString::impappend(const char c) {
    impappend(&c);
}

void CString::impappend(const CString &str) {
    impappend(str.c_str);
}

char *CString::getChars(const size_t a, const size_t b) {
    if (a > b)
        return nullptr;
    const size_t chunk = b - a + 1;
    char *res = new char[chunk + 1];
    strncpy(res, c_str + a, chunk);
    res[chunk] = '\0';

    return res;
}